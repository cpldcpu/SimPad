/* ---------------------------------------------
	Blinky on PA.0 for PFS154
	Jan 14, 2019 cpldcpu
  --------------------------------------------- */
  
volatile int counter;
__sfr __at(0x03) clkmd;
__sfr __at(0x10) pa;
__sfr __at(0x11) pac;

unsigned char _sdcc_external_startup(void)
{
	clkmd = 0x78; // Disable ILRC, watchdog, clock= IHRC/64
	return 0; // perform normal initialization
}

void main(void)
{
 	pac = 0x01;	// PA.0=output
	
 	for (;;) {
 		counter=30000;
 		while (--counter);
 		pa=0x00;

 		counter=30000;
 		while (--counter);
 		pa=0x01;
 	}
}

