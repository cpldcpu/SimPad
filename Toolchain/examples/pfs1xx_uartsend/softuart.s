
.module     SOFTUART
.globl      _transmitchar
.globl      _transmitchar_PARM_1
.globl		_print_uint16
.globl		_print_uint16_PARM_1
.globl		p

_pa=         0x10
_pac=        0x11

TXPIN=  7
TXPORT= _pa
TXPORTC= _pac

BAUDRATE = 38400
F_CPU 	 = 8000000

.area DATA

_uart_cntr:
_loopctr2:
	.ds 1
_loopctr1:
	.ds 1
_transmitchar_PARM_1:
	.ds 2
_print_uint16_PARM_1:
	.ds 2	
_print_tmp:	
	.ds 6

.area       CODE
;------------------------------------------------------
; transmitchar
;------------------------------------------------------

_transmitchar:
	set0	TXPORT, #TXPIN
	set1	TXPORTC, #TXPIN

	call	uartdelay

	mov	    a, #0x08
	mov	    _uart_cntr, a
sendloop:
	sr	    _transmitchar_PARM_1
	swapc	TXPORT,#7
	call	uartdelay

    dzsn	_uart_cntr
	goto	sendloop

	set1	TXPORT, #TXPIN

uartdelay:
	mov	    a,#(F_CPU/4)/BAUDRATE
0$:
	sub     a,#1
	t1sn	f,z
	goto	0$
	ret
	
;-------------------------------------------------------
; print_uint16
; 
; Accepts an uint16 value as parameter and outputs its 
; decimal representation on the UART using "putchar".
; Optimized for size. See C code below for algorithm.
;-------------------------------------------------------
_print_uint16:
	clear 	_print_tmp+0
	clear 	_print_tmp+1
	clear 	_print_tmp+2
	clear 	_print_tmp+3
	clear 	_print_tmp+4
	clear 	_print_tmp+5	;store value >10 here to display leading zeroes

	mov 	a,#16
	mov		_loopctr1,a
	; mov		_print_tmp+5,a
print_uint16_loop$:
	sl  	_print_uint16_PARM_1+0
	slc  	_print_uint16_PARM_1+1
	pushaf			; save carry flag

	mov		a, #(_print_tmp)
	mov		p, a
	clear	p+1

	mov		a, #5
	mov		_loopctr2,a

print_uint16_innerloop$:
	popaf
	idxm	a, p
	slc		a
	idxm	p,a
	add		a, #-10
	t0sn 	f,c
	idxm	p,a
	pushaf							; save carry flag
	
	inc		p
	dzsn 	_loopctr2
	goto 	print_uint16_innerloop$

	popaf

	dzsn 	_loopctr1
	goto 	print_uint16_loop$

	mov 	a,#5					; Iterate also though last element, which is used is a flag. p points to last element
	mov		_loopctr1,a

print_uint16_outloop$:
	idxm	a, p
	ceqsn	a, _print_tmp+5   		; skip leading zeros. Also skip last element in array
	call	digitout

	dec		p

	dzsn	_loopctr1
	goto 	print_uint16_outloop$

	idxm	a, p					; rightmost digit is always printed

digitout:
	add		a, #0x30
	mov		_transmitchar_PARM_1+0, a
	mov		_print_tmp+5,a 			; Don't skip further zeros
	goto	_transmitchar			; Uses ret from transmitchar

;------------------------------------------------------
; C-Version, for reference. 
; Uses two step approach:
; 1) Convert binary to BCD, one digit per byte
; 2) Print array as ASCII.
;------------------------------------------------------

; void printnum(uint16_t num) {
; 	char outbuf[5]={0,0,0,0,0};
; 	uint8_t i,k;

; 	for (i=0; i<16; i++) {
; 		uint8_t carry=0;
; 		if (num&0x8000) carry=1;
; 		num<<=1;
; 		for (k=0; k<5; k++)  {
; 			outbuf[k]<<=1;
; 			outbuf[k]|=carry;
; 			carry=0;
; 			if (outbuf[k]>=10) {outbuf[k]-=10; carry=1;}
; 		}
; 	}

; 	k=4;
; 	do {
; 		putchar(outbuf[k]+'0');
; 	} while (k-->0);
; }