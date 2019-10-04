/* ---------------------------------------------------------------
adc.c

Example using the ADC in the PFS173.
Analog input is on PB2

Oct  04, 2019 cpldcpu - first release
------------------------------------------------------------------ */
  
#include <stdint.h>
#include <pdk/io_pfs173.h>
#include <pdk/delay.h>
#include <pdk/softuart.h>

// UART configuration 
#define TXPORT pa
#define TXPORTC pac
#define TXPIN 7
#define BAUDRATE 115200

#include "delay.c"			// include delay implementation. 
#include "PDK_softuart.c"	// include softuart implementation

#define LEDPIN PA0

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	PDK_USE_FACTORY_TRIMMING();
	return 0; 
}

void main(void)
{
	uint16_t cnt=0;

	PDK_autobaud();			// Adjust baudrate on easypdkprogrammer

 	// PAC |= _BV(LEDPIN);	    // Enable LED output

	PBC&=~_BV(PB2);	// Disable PGIO on analog input pin
	PBPH&=~_BV(PB2);
	PBDIER&=~_BV(PB2);

	ADCM=ADCM_CLK_SYSCLK_DIV16; // 500 kHz ADC clock
	ADCC=ADCC_ADC_ENABLE | ADCC_CH_AD2_PB2; // Enable ADC
	ADCRGC=ADCRG_ADC_REF_VDD; 

 	for (;;) {
		ADCC|=_BV(6); // Start conversion

		do {} while ((ADCC&_BV(6))==0);

		uint8_t adcout=ADCR;

		PDK_senduint16(adcout);
		PDK_sendstring('\n');
		delay_ms(200);

 	}
}