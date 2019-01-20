;--------------------------------------------------------
; SPI-Master for PFS154
; cpldcpu Jan 2019
;
; LED is connected to PA0, PWM0 is used to drive LED
;
; SPI:
;		CLK		PA3
;		DATA	PA6
;

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
_spi_data:
	.ds 1
_tmp1:
	.ds 1
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

	mov		a, #0x87			;  Enable PWMG0, set to PA0, src=IHR
	mov		_pwmg0c,a

	mov		a, #0x20			;  prescaler=4, divider=1, no interrupt
	mov		_pwmg0s,a

	mov		a, #0xff
	mov		_pwmg0cubl,a
	mov		_pwmg0cubh,a
	
	mov		a, #1
	mov		_random,a 			; random seed

;	mov		a, #0x01
;	mov		_pac, a

.mloop:
	call	wait
	mov		a,_random
	mov		_spi_data,a
	mov		_pwmg0dth,a	
	add		a,#32
	mov		_random,a

	call 	spi_sendbyte
	goto	.mloop

; Wait loop

wait:
	mov		a, #0xff
	mov		_counter+0, a
	mov		_counter+1, a
.waitloop:
	dzsn	_counter+0
	goto	.waitloop
	dzsn	_counter+1
	goto	.waitloop
	ret

;--------------------------------------------------------
; SPI sendbyte
;		CLK		PA3
;		DATA	PA6
;
; Sends out one byte that is saved to _spi_data
;--------------------------------------------------------

spi_sendbyte:
	mov		a, #8
	mov		_tmp1,a

	mov		a, #0x48
	mov		_pac,a
	set0	_pa, #3

.sendloop:
	sl 		_spi_data
	swapc	_pa, #6

	call	spi_delay
	set1	_pa, #3

	call	spi_delay
	set0	_pa, #3

	dzsn	_tmp1
	goto	.sendloop
	ret

spi_delay:
	mov		a, #5		; 20 cyles
.loop:
	sub		a, #1		; 4 clockcycles per loop
	ceqsn   a, #0
	goto 	.loop
	ret


