/* ---------------------------------------------------
	Blinky on PA4 for PFS154

	Sep 1 , 2019 cpldcpu - First version
	Sep 21, 2019 cpldcpu - Updated sfr to upper case
  ---------------------------------------------------- */
  
#include <stdint.h>
#include <pdk/io_pfs154.h>
#include <pdk/delay.h>

#include "delay.c"	// include delay implementation. Needs to be cleaned up later.

#define LEDPIN PA4

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	PDK_USE_FACTORY_TRIMMING();

	return 0; // perform normal initialization
}

 
void main(void)
{
 	PAC |= _BV(LEDPIN);	    // This syntex will infer set0/set1

 	for (;;) {
 		PA ^= _BV(LEDPIN);	// Toggle LED
		delay_ms(500);
 	}
}

