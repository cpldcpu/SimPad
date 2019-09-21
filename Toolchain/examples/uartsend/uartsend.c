/* ---------------------------------------------------------------
uartsend.c

Example showing how to use the PDK_softuart routines for printf 
style debugging

Sep 21, 2019 cpldcpu - first release
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

#define LEDPIN PA4

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	EASY_PDK_CALIBRATE_IHRC(8000000,5000);      // tune SYSCLK to 8.0MHz @ 5.00V
	return 0; 
}

void main(void)
{
	uint16_t cnt=0;

	PDK_autobaud();			// Adjust baudrate on easypdkprogrammer

 	PAC |= _BV(LEDPIN);	    // Enable LED output

 	for (;;) {
 		PA ^= _BV(LEDPIN);	// Toggle LED
		PDK_senduint16(cnt++);
		PDK_sendstring(" counts\n");     
		delay_ms(200);
 	}
}