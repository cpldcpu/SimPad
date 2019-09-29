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
	CLKMD = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 16/2=8 Mhz main clock

//  Uncomment this line to use the automatic IHRC trimming function included in the EASYPDKPROG software.
//	Trimming will only be activated when the program is started for the first time and the resulting
//  values will be written to flash. This call is required on MCUS without factory calibration, for example the PMS150C.
//  In addition, it is possible to trim the IHRC to value different from 16MHz. Also when the operating voltage deviates
//  significantly from 5V it may be sensible to use additional trimming.

//	EASY_PDK_CALIBRATE_IHRC(F_CPU, 5000);		 // tune SYSCLK to 8.0MHz @ 5.00V

//  Uncomment this line to use the preprogrammed trimming values for IHR and Bandgap provided in 
//  the flash of PFS154/PFS174. This does not require additional trimming after programming and improves turnaround times.
//  The accuracy should be sufficient if you want to use IHRC=16 MHz default at 5.00V

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

