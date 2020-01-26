//--------------------------------------------------------
// Chainable 7 Segment display
//
// External pins:
// PB0..PB6 Sa...Sg 
// PB7		Sdp
// PA6		Dout
// PA0		Din
//
//--------------------------------------------------------
// Jan 22, 2020 cpldcpu - first 
//--------------------------------------------------------

#include <stdint.h>
#include <pdk/io_pfs154.h>
#include <pdk/delay.h>

#include "delay.c"	// include delay implementation. Needs to be cleaned up later.

uint8_t datareg;
uint8_t forwardreg;
uint8_t loopctr;
uint8_t state=1;  // S0=forward  S1= Receive

#define	Din	PA0
#define Dout PA6

// #define debug

#ifdef debug 
// UART configuration 
#define TXPORT pa
#define TXPORTC pac
#define TXPIN 7
#define BAUDRATE 57600

#include "PDK_softuart.c"	// include softuart implementation

#endif

//                     0   1    2    3    4    5    6	 7	  8    9	A	 B 	  C	   D    E	 F
const char numbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV2 | CLKMD_ENABLE_IHRC; // 8 Mhz main clock
	PDK_USE_FACTORY_TRIMMING();
#ifdef debug 
	PDK_autobaud();
#endif
	return 0;
}

void main(void)
{

	// T16M = T16_CLK_DIV16 | T16_CLK_SYSCLK | T16_INTSRC_11BIT; // 1 MHZ / 16 / (2^11) = 30 Hz
	INTEN  =INTEN_PA0;
	INTEGS =INTEGS_PA0_FALLING;
	PADIER|=PADIE_PA0_WAKEUP_ENABLE;	
	INTRQ = 0; 

	__asm__("engint"); // enable interrupts

	PBC=0x7F;		
	PAC|=_BV(Dout);
	forwardreg=255;

	for (;;)
	{
		if ((forwardreg==0)&&(state==0)) {	// reset condition met
			PB=0x7f^numbers[datareg&15];
			state=1;
			forwardreg=255;
		}
	}
}

void handler(void) __interrupt(0)
{
	// Falling edge on PA0 detected = being of UART frame
	// One UART frame last 138.89 cycles at 57600 BAUD and 8 Mhz clock
	// Entering interrupt handler takes approx 3+2+2=7 cycles

	// Delay to start condition half bit
	// 139/2-7 ~ 62 cycles
__asm 
	t0sn	_state,#0
	goto	h_receive

	// forward
h_forward:
	mov		a,#21	// 20*3+2=62 cycles
h_0$:				
	dzsn	a		// 3 cycles per loop, 2 for last
	goto	h_0$

	t0sn	s(PA), #(Din)	// Test if start condition is still valid
	goto	h_glitch	
	set0	s(PA), #(Dout) // start on output 

	// delay to next bit=139 cycles

	mov		a,#45	// 44*3+2=134 cycles
h_1$:				
	dzsn	a		// 3 cycles per loop, 2 for last
	goto	h_1$

	mov		a,#8
	mov		_loopctr,a

// receive loop
// overhead is 5+3=8 cycles

h_bitloop:
	swapc	s(PA), #(Din)  // sample input 
	pushaf
	swapc	s(PA), #(Dout)
	popaf
	src     _forwardreg

	mov		a,#44	// 43*3+2=131=139-8
h_2$:
	dzsn	a		// 3 cycles per loop, 2 for last
	goto	h_2$

	dzsn	_loopctr
	goto	h_bitloop

	set1 	s(PA), #(Dout)	// complete last bit, stop bit is omitted.
	goto	h_exit
h_receive:

	mov		a,#21	// 20*3+2=62 cycles
h_3$:				
	dzsn	a		// 3 cycles per loop, 2 for last
	goto	h_3$

	t0sn	s(PA), #(Din)	// Test if start condition is still valid
	goto	h_glitch	
	nop

	// delay to next bit=139 cycles

	mov		a,#45	// 44*3+2=134 cycles
h_4$:				
	dzsn	a		// 3 cycles per loop, 2 for last
	goto	h_4$

	mov		a,#8
	mov		_loopctr,a

// receive loop
// overhead is 5+3=8 cycles

h_bitloop2:
	swapc	s(PA), #(Din)  // sample input 
	src     _datareg

	mov		a,#45	// 44*3+2=134=139-5
h_5$:
	dzsn	a		// 3 cycles per loop, 2 for last
	goto	h_5$

	dzsn	_loopctr
	goto	h_bitloop2

	set1 	s(PA), #(Dout)	// complete last bit, stop bit is omitted.

	clear 	_state			// switch to forward
h_glitch:
h_exit:
__endasm;

	INTRQ=0;  // only using one interrupt
}
