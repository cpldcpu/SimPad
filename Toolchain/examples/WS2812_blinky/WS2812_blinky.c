/* ---------------------------------------------------------------
WS2812_blinky.c

Example showing how to use the PDK_WS2812 functions to write to 
WS2812 RGB LEDs. Will cycle the first two LEDs in a string in RGB and
complementary colours.

Sep 22, 2019 cpldcpu - first release
------------------------------------------------------------------ */
  
#include <stdint.h>
#include <pdk/io_pfs154.h>
#include <pdk/delay.h>
#include <pdk/WS2812.h>

#define WS2812_PIN PB2
#define WS2812_PORT PB
#define WS2812_PORTC PBC

#include "delay.c"				// include delay implementation. 
#include "PDK_WS2812.c"			// include WS2812 implementation.

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	EASY_PDK_CALIBRATE_IHRC(F_CPU,5000);        // tune SYSCLK to 8.0MHz @ 5.00V
	return 0; 
}

void main(void)
{
 	for (;;) {

		PDK_WS2812_writeRGB(0x10,0x00,0x00);  // write RGB triple
		PDK_WS2812_writeRGB(0x00,0x20,0x20);
		delay_ms(200);  // Data written to WS2812 string is automatically activated after the bus was idle for >50µs

		PDK_WS2812_writebyte(0x00);	// write RGB bytes separately
		PDK_WS2812_writebyte(0x10);
		PDK_WS2812_writebyte(0x00);
		PDK_WS2812_writeRGB(0x20,0x00,0x20);
		delay_ms(200);

		PDK_WS2812_writeRGB(0x00,0x00,0x10);
		PDK_WS2812_writeRGB(0x20,0x20,0x00);
		delay_ms(200);
 	}
}