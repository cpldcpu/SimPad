;--------------------------------------------------------
; Electronic candle for Padauk PMS150C and SDASPDK (SDCC toolchain)
; LED is connected to PA4, Timer2 is used to drive LED
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

_tm2c		=	0x1c	; Timer2 Control Register
_tm2ct		=	0x1d	; Timer2 Counter Register
_tm2b		=	0x09	; Timer2 Bound Register
_tm2s		=	0x17	; Timer2 Scaler Register

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
	.org 0xc0

_main:
	mov		a,#(d_end-d_begin+1)&254	; initialize stack pointer to end of data area
	mov		sp,a

	mov		a, #0x18			; Initialize clk to IHRC/16 = 1 MHz
	mov		_clkmd, a

	call	candle_init

.mloop:
	call	wait
	call	candle_do
	goto	.mloop

;--------------------------------------------------------
; Delay loop
;--------------------------------------------------------
wait:
	mov		a, #0x5f
	mov		_counter+1, a
.waitloop:
	dzsn	_counter+0
	goto	.waitloop
	dzsn	_counter+1
	goto	.waitloop
	ret

;--------------------------------------------------------
; Implements algorithm from:  
; https://github.com/cpldcpu/CandleLEDhack/blob/master/Emulator/CandeflickerLED.c
; LED anode is connected to PA4, timer2-pwm is used to drive LED
;--------------------------------------------------------

candle_init:
	mov		a, #0x2e			;  clk=IHRC, output=PA4, PWM mode
	mov		_tm2c,a

	mov		a, #0x41			;  prescaler=16, divider=2, PWM-Frequency ~ 2kHz
	mov		_tm2s,a			
	
	mov		_random,a 			; random seed (needs to be != 0)
	ret

candle_do:
	mov		a, _random
	t0sn	_random+1,#0	 ; 50% chance for full brightness
	or		a,#255
	mov		_tm2b,a	

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