/* ---------------------------------------------------------------
ligthsensor.c

LED is connected to PA0 (anode) and PA4 (cathode). 

Sep 21, 2019 cpldcpu - first release
Sep 29, 2019 cpldcpu - last iteration after many tries. It appears the PFS154
is too noisy for this to work.
------------------------------------------------------------------ */
  
#include <stdint.h>
#include <pdk/io_pfs154.h>
#include <pdk/delay.h>
#include <pdk/softuart.h>

// UART configuration 
#define TXPORT pa
#define TXPORTC pac
#define TXPIN 7
#define BAUDRATE 38400

#include "delay.c"			// include delay implementation. 
#include "PDK_softuart.c"	// include softuart implementation

uint16_t senselight_delay(void);

volatile uint32_t brightness;
volatile uint16_t counter;
volatile uint8_t vref=8;

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	PDK_USE_FACTORY_TRIMMING();
	PDK_autobaud();			// Adjust baudrate on easypdkprogrammer
	return 0; 
}

void main(void)
{
	uint32_t cnt=0;

	PDK_sendchar('\n');

 	for (;;) {
		cnt=senselight_delay();
		PDK_senduint16(cnt);
		PDK_sendchar('\n');
 	}
}

// Thesis on LED as light sensor https://digi.lib.ttu.ee/i/file.php?DLID=9345&t=1

uint16_t senselight_delay(void) {
	
__asm
	set1	_pac,#0				; PA.0=output
	set0	_padier,#0			; PA.0=Disable input
	set0	_pa,#0				; PA.0=GND

	set1	_pa,#4				; PA.4=VDD
	set1	_pac,#4				; PA.4=output   -  Discharge LED
	set0	_padier,#4			; PA.4 Disable input
	set0	_paph,#4			; PA.4 pull up off.

	mov 	a,#(GPCC_COMP_MINUS_VINT_R | GPCC_COMP_PLUS_PA4 | GPCC_COMP_INVERSE | GPCC_COMP_ENABLE )
	mov		_gpcc,a

	mov 	a, s(vref)
	// or      a, #GPCS_COMP_OUTPUT_PA0   // enable comparator output on PA0
	mov		_gpcs,a				;

 	clear	_brightness+0
  	mov		a,#130		// max output value of timer expires
	mov 	_brightness+1,a

	mov     a, #INTEN_T16
	mov     s(INTEN),a
	mov 	a, #(T16_CLK_DIV16 | T16_CLK_IHRC | T16_INTSRC_15BIT)
	mov    	s(T16M),a		; enable timer at 1 MHz, interrupt after 32768 cycles => 32.7ms
	mov     a, #0
	mov     s(INTRQ),a 

	clear 	_t16c+0
	clear 	_t16c+1

	stt16   _t16c			; initialize timer with 0
	set0	_pac,#4				; PA.4=input 

 .senseloop4$:
	t0sn	s(INTRQ), #2		; check for timer interrupt
	goto 	senseloopout4
 	t1sn	s(GPCC),#6
	goto 	.senseloop4$

	ldt16 	_t16c				; load timer value

	mov 	a, _t16c+0
	mov  	_brightness+0,a
	mov 	a, _t16c+1
 	mov		_brightness+1,a

senseloopout4:
	t1sn	s(INTRQ), #2		; check for timer interrupt
	goto 	senseloopout4
__endasm;

	return brightness;
}

