//--------------------------------------------------------
// Electronic candle for Padauk PFS154C and SDASPDK (SDCC toolchain)
// LED is connected to PA4, PWM0 is used to drive LED
// Implements algorithm from:
// https://github.com/cpldcpu/CandleLEDhack/blob/master/Emulator/CandeflickerLED.c
//
// cpldcpu - Feb 7 2019
// Sep 21, 2019 cpldcpu - update to newer toolchain
//--------------------------------------------------------

#include <stdint.h>
#include <pdk/io_pfs154.h>

#define LEDPIN PA4

volatile unsigned int rnd_lfsr;

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV16 | CLKMD_ENABLE_IHRC; // 1 Mhz main clock
	EASY_PDK_CALIBRATE_IHRC(F_CPU, 5000);		 // tune SYSCLK to 1.0MHz @ 5.00V
	return 0;
}

void lfsr_step()
{
	if (rnd_lfsr & 1)
	{
		rnd_lfsr = (rnd_lfsr >> 1) ^ 0x822B;
	}
	else
	{
		rnd_lfsr = (rnd_lfsr >> 1);
	}
}

void candle_init()
{
	PWMG1C = 0x87; // Enable PWMG1, set to PA4, src=IHR
	PWMG1S = 0x20; // prescaler=4, divider=1, no interrupt

	PWMG1CUBL = 0xff; // set PWM counter upper bound to 0xffff
	PWMG1CUBH = 0xff;

	rnd_lfsr = 0x55ce;
}

void candle_do()
{
	if (rnd_lfsr & 0x100)
	{
		PWMG1DTH = 255;
	}
	else
	{
		PWMG1DTH = (uint8_t)(rnd_lfsr & 255);
	}

	for (char i = 0; i < 7; i++)
	{
		lfsr_step();
		if ((rnd_lfsr & 0xff) > 128)
			return;
	}
}

void main(void)
{
	candle_init();

	T16M = T16_CLK_DIV16 | T16_CLK_SYSCLK | T16_INTSRC_11BIT; // 1 MHZ / 16 / (2^11) = 30 Hz
	INTEN |= INTEN_T16;
	INTRQ = 0; 

	__asm__("engint"); // enable interrupts
	
	for (;;)
	{
	}
}

void handler(void) __interrupt(0)
{
	if (INTRQ & INTRQ_T16)
	{
		candle_do();
		intrq &= ~INTRQ_T16;
	}
}
