
.module     SOFTUART
.globl      _putchar
.globl      _putchar_PARM_1

_pa=         0x10
_pac=        0x11

TXPIN=  7

BAUDRATE = 38400
F_CPU = 8000000

.area DATA

_uart_cntr:
	.ds 1
_putchar_PARM_1:
	.ds 1
.area       CODE

_putchar:
	set0	_pa, #TXPIN
	set1	_pac, #TXPIN

	call	uartdelay

	mov	    a, #0x08
	mov	    _uart_cntr, a
sendloop:
	sr	    _putchar_PARM_1
	swapc	_pa,#TXPIN
	call	uartdelay

    dzsn	_uart_cntr
	goto	sendloop

	set1	_pa, #TXPIN

uartdelay:
	mov	    a,#(F_CPU/4)/BAUDRATE
0$:
	sub     a,#1
	t1sn	f,z
	goto	0$
	ret
	
