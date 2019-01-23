;--------------------------------------------------------
; Blinky for Padauk PMS150C and SDASPDK (SDCC toolchain)
; LED on PA0
; cpldcpu Jan 2019
;--------------------------------------------------------
	.module blinky
	.optsdcc -mpdk14
	
;--------------------------------------------------------
; resgisters
;--------------------------------------------------------

_flag	=	0x0002
_clkmd	=	0x0003
_pa		=	0x0010
_pac	=	0x0011

;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
d_begin:
_counter:
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
	.org 0x00

_main:
	mov		a,#(d_end-d_begin+1)&254	; initialize stack pointer to end of data area
	mov		sp,a

	mov		a, #0x78			; Initialized clk to IHRC/32 = 0.5MHz
	mov		_clkmd, a

	mov		a, #0x01
	mov		_pac, a

.mloop:
	set1	_pa,#0
	call	wait

	set0	_pa,#0
	call	wait
	goto	.mloop

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


