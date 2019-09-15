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

extern void transmitchar(uint8_t);
extern void print_uint8(uint8_t);
extern void print_uint16(uint16_t);


void print_string(const char *in)
{
    while (*in) transmitchar(*in++);
}


unsigned char _sdcc_external_startup(void)
{
	clkmd = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	EASY_PDK_CALIBRATE_IHRC(8000000,5000);      //tune SYSCLK to 8.0MHz @ 3.300V
	return 0; // perform normal initialization
}

void main(void)
{
 	pac |= _BV(LEDPIN);	    // Use this exact syntax to infer set0/set1
	transmitchar(0x55);
	delay_ms(5);

	uint16_t cnt=0;
 	for (;;) {
 		pa ^= _BV(LEDPIN);	// Toggle LED
		print_uint16(cnt++);
		print_string(" counts\n");     
		delay_ms(200);
 	}
}