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

uint8_t state;  // S0=forward  S1= Receive

#define	S_forward	0
#define S_receive 	1
#define	Endmarker	0x00	// CR  -> Code should not be 0xff to avoid glitches causing updates

uint8_t datareg;
uint8_t forwardreg;
uint8_t loopctr;

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

// The table is organized in a way, where it will decode both ascii directly and hex digits with an offset of 0x30.
//					  SPC/@ A	 B 	  C	   D    E	 F    G    H    I    J    K    L    M    N    O     P/0  1    2    3    4    5    6	   7	8    9    A	   B 	C	 D    E	   F
const char segdec[] ={0x00,0x77,0x7c,0x58,0x5e,0x79,0x71,0x00,0x76,0x30,0x0e,0x00,0x38,0x00,0x54,0x5c, 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV2 | CLKMD_ENABLE_IHRC; // 8 Mhz main clock
	// PDK_USE_FACTORY_TRIMMING();			 	// It appears that the factory trimming is sometimes slightly off - possibly not done at 5V
	EASY_PDK_CALIBRATE_IHRC(F_CPU,5000);
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
	PB=0x7f^0x40;  // Display hyphen '-' after reset

	PAC|=_BV(Dout);
	forwardreg=255;
	state = S_receive;
	for (;;)
	{
		if ((forwardreg==Endmarker)&&(state==S_forward)) {	// received end marker while in forwarding mode -> update condition met
			uint8_t datain=datareg;
			switch (datain) {
				// case 0x20: PB=0x7f^0x00; break; // space
				case '-':  PB=0x7f^0x40; break; // hyphen
				default:   PB=0x7f^segdec[datain&31]; break;
			}

			state=S_receive;
			forwardreg=255;
			#ifdef debug 
				PDK_sendchar('U');
				PDK_sendchar(datain);
			#endif			
		}
	}
}

void handler(void) __interrupt(0)
{
	// Falling edge on PA0 detected = being of UART frame
	// One UART frame last 138.89 cycles at 57600 BAUD and 8 Mhz clock
	// Entering interrupt handler takes approx 3+2+2=7 cycles

__asm 
	mov		a,#(S_receive)
	cneqsn	a,_state
	goto	h_receive

	// Delay to start condition half bit
	// 139/2-7-3 ~ 59.5 cycles

	// forward
h_forward:
	mov		a,#20	// 19*3+2=59 cycles
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

	// Delay to start condition half bit
	// 139/2-7-4 ~ 58.5 cycles

	mov		a,#20	// 19*3+2=59 cycles
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
// overhead is 2+3=5 cycles

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

	mov 	a,#(Endmarker)
	ceqsn 	a,_datareg		// Check if end-marker was received instead of data. If yes, stay in receive mode.
	clear 	_state			// switch to forward
h_glitch:
h_exit:
__endasm;

	INTRQ=0;  // only using one interrupt
}
