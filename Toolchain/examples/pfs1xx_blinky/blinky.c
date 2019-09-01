/* ---------------------------------------------
	Blinky on PA4 for PFS154
	v1.0 - Sep 1st, 2019
  --------------------------------------------- */
  
#include <stdint.h>
#include <pdk/io_pfs154.h>
#include <pdk/delay.h>

#define LEDPIN PA4

unsigned char _sdcc_external_startup(void)
{
	clkmd = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	return 0; // perform normal initialization
}

void main(void)
{
 	pac |= _BV(LEDPIN);	    // Use this exact syntax to infer set0/set1
 	for (;;) {
 		pa ^= _BV(LEDPIN);	// Toggle LED
		delay_ms(500);
 	}
}

