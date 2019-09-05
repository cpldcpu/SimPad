/* ---------------------------------------------
	soft uart
	
	TX  on PA7
	LED on PA4
  --------------------------------------------- */
  
#include <stdint.h>
#include <pdk/io_pfs154.h>
#include <pdk/delay.h>
#include <stdio.h>

#define LEDPIN PA4
#define TXPIN PA7

// extern void putchar(uint8_t);
extern int putchar(int);

unsigned char _sdcc_external_startup(void)
{
	clkmd = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	EASY_PDK_CALIBRATE_IHRC(8000000,5000);      //tune SYSCLK to 8.0MHz @ 3.300V
	return 0; // perform normal initialization
}

void main(void)
{
 	pac |= _BV(LEDPIN);	    // Use this exact syntax to infer set0/set1
	putchar(0x55);
	delay_ms(5);

 	for (;;) {
 		pa ^= _BV(LEDPIN);	// Toggle LED
		puts("hallo");      // output textstring terminated with a newline. The current printf implementation is too large 
		delay_ms(500);
 	}
}

