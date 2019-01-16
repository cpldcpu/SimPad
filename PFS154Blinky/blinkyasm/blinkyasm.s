;--------------------------------------------------------
; Blinky for Padauk PFS154C
; Based on asm code generated from blinky.c by SDCC
;
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.6 #10883 (Linux)
;--------------------------------------------------------
; Equivalent C-code in comment below
;--------------------------------------------------------
;
; volatile int counter;
;
; __sfr __at(0x03) clkmd;
; __sfr __at(0x10) pa;
; __sfr __at(0x11) pac;
;
; void main(void)
; {
; 	clkmd = 0x78; // Disable ILRC, watchdog, clock= IHRC/64
; 	pac = 0x01;	// PA.0=output
;	
; 	for (;;) {
; 		counter=30000;
; 		while (--counter);
; 		pa=0x00;
;
; 		counter=30000;
; 		while (--counter);
; 		pa=0x01;
; 	}
; }
;--------------------------------------------------------

	.module blinky
	.optsdcc -mpdk14
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _tm2b
	.globl _tm2s
	.globl _tm2c
	.globl _pac
	.globl _pa
	.globl _intrq
	.globl _inten
	.globl _clkmd
	.globl _counter
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG (ABS)
	.org 0x0000
_clkmd	=	0x0003
_inten	=	0x0004
_intrq	=	0x0005
_pa	=	0x0010
_pac	=	0x0011
_tm2c	=	0x001c
_tm2s	=	0x0017
_tm2b	=	0x0009
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
_counter::
	.ds 2
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
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME
__interrupt_vect:
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
	.area	PREG (ABS)
;	.area CODE
.org 0x00
__sdcc_program_startup:
	goto	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
.org 0x10	
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	mov	a, #0x78
	mov	_clkmd, a
	mov	a, #0x01
	mov	_pac, a
00108$:
	mov	a, #0x30
	mov	_counter+0, a
	mov	a, #0x75
	mov	_counter+1, a
;	blinky.c: 35: while (--counter);
00101$:
	dec	_counter+0
	subc	_counter+1
	mov	a, _counter+0
	or	a, _counter+1
	ceqsn	a, #0x00
	goto	00101$
;	blinky.c: 36: pa=0x00;
	mov	a, #0x00
	mov	_pa, a
;	blinky.c: 38: counter=30000;
	mov	a, #0x30
	mov	_counter+0, a
	mov	a, #0x75
	mov	_counter+1, a
;	blinky.c: 39: while (--counter);
00104$:
	dec	_counter+0
	subc	_counter+1
	mov	a, _counter+0
	or	a, _counter+1
	ceqsn	a, #0x00
	goto	00104$
;	blinky.c: 40: pa=0x01;
	mov	a, #0x01
	mov	_pa, a
	goto	00108$
00110$:
;	blinky.c: 42: }
	ret

