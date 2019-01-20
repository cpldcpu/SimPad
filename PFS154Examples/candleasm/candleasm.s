;--------------------------------------------------------
; Electronic candle for Padauk PFS154C and SDASPDK (SDCC toolchain)
; LED is connected to PA0, PWM0 is used to drive LED
; Implements algorithm from:  
; https://github.com/cpldcpu/CandleLEDhack/blob/master/Emulator/CandeflickerLED.c
;
; cpldcpu Jan 2019
;--------------------------------------------------------
	.module blinky
	.optsdcc -mpdk14
	
;--------------------------------------------------------
; resgisters
;--------------------------------------------------------

_flag		=	0x00

_clkmd		=	0x03
_pa			=	0x10
_pac		=	0x11

_pwmg0c 	=	0x20
_pwmg0s 	=	0x21
_pwmg0dth 	=	0x22	;PWM duty value high 
_pwmg0dtl 	=	0x23	;PWM duty value low 
_pwmg0cubh 	=	0x24	;PWM counter upper bound high
_pwmg0cubl 	=	0x25	;PWM counter upper bound low

;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
d_begin:
_counter:
	.ds 2
_random:
	.ds 2
d_end:

;--------------------------------------------------------
; overlayable items in ram 
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area HOME
	.area PREG (ABS)
	.org 0x000

_main:
	mov		a,#(d_end-d_begin+1)&254	; initialize stack pointer to end of data area
	mov		sp,a

	mov		a, #0x38			; Initialize clk to IHRC/8 = 2 MHz
	mov		_clkmd, a

	call	candle_init

	set1	_pac,#4				; PA.4=output   
	set0	_pa,#4				; PA.4=GND

.mloop:
	call	wait
	call	candle_do
	goto	.mloop

;--------------------------------------------------------
; Delay loop
;--------------------------------------------------------
wait:
	mov		a, #0x5f
	mov		_counter+0, a
	mov		_counter+1, a
.waitloop:
	dzsn	_counter+0
	goto	.waitloop
	dzsn	_counter+1
	goto	.waitloop
	ret

;--------------------------------------------------------
; Flicker candle algorithm for PFS154
; Implements algorithm from:  
; https://github.com/cpldcpu/CandleLEDhack/blob/master/Emulator/CandeflickerLED.c
; LED anode is connected to PA0, PWM0 is used to drive LED
;--------------------------------------------------------

candle_init:
	mov		a, #0x87			;  Enable PWMG0, set to PA0, src=IHR
	mov		_pwmg0c,a

	mov		a, #0x20			;  prescaler=4, divider=1, no interrupt
	mov		_pwmg0s,a

	mov		a, #0xff
	mov		_pwmg0cubl,a
	mov		_pwmg0cubh,a
	
	mov		a, #1
	mov		_random,a 			; random seed
	ret

candle_do:
	mov		a, _random
	t0sn	_random+1,#0	 ; 50% chance for full brightness
	or		a,#255
	mov		_pwmg0dth,a	

; Reduces the propability of brightness values below a threshold to occur.
; This will reduce the frequency of "strong flicker" events.

	mov		a,3
	mov		_counter,a
.repeatrnd:
	call	lfsr_step
	mov		a, _random
	sub     a, #128			;	Changing this to lower value will increase flicker
	t1sn	f,c	  
	ret
	dzsn	_counter
	goto	.repeatrnd

;   Random number generator
;   16 bit lfsr 

;   https://users.ece.cmu.edu/~koopman/lfsr/index.html

;   if (i & 1)  { i = (i >> 1) ^ feed; }
;   else        { i = (i >> 1);       }

;   Maximum length feedback terms that only use bits 15-8:
;   0x9c00
;   0xb400
;   0xbd00
;   0xca00
;   0xeb00
;   0xfc00

lfsr_step:
	mov		a, #0xca		; Load feedback term into accu. 
	sr		_random+1	  	; shift random value right, bit0 goes into carry
	src		_random
	t0sn	f,c				; Skip next instrcution if carry is clear
	xor		_random+1,a	   	; xor with feedback term
	ret