// I/O include file for Padauk PMS152
// Version: 0.11a
// Automatically generated on 2019-09-29 16:10:55.812270

#ifndef __PDK_IO_PMS152_H
#define __PDK_IO_PMS152_H

#include <pdk/io_common.h>

#define __PDK_IOEND 63

#define PDK_USE_FACTORY_TRIMMING() {#error 'this device does not support factory trimming'}

#define FLAG    	flag // __sfr __at(0x00) FLAG
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M
#define MISC    	misc // __sfr __at(0x08) MISC
#define TM2B    	tm2b // __sfr __at(0x09) TM2B
#define EOSCR   	eoscr // __sfr __at(0x0a) EOSCR
#define IHRCR   	ihrcr // __sfr __at(0x0b) IHRCR
#define INTEGS  	integs // __sfr __at(0x0c) INTEGS
#define PADIER  	padier // __sfr __at(0x0d) PADIER
#define PBDIER  	pbdier // __sfr __at(0x0e) PBDIER
#define MISC2   	misc2 // __sfr __at(0x0f) MISC2
#define PA      	pa // __sfr __at(0x10) PA
#define PAC     	pac // __sfr __at(0x11) PAC
#define PAPH    	paph // __sfr __at(0x12) PAPH
#define PB      	pb // __sfr __at(0x14) PB
#define PBC     	pbc // __sfr __at(0x15) PBC
#define PBPH    	pbph // __sfr __at(0x16) PBPH
#define TM2S    	tm2s // __sfr __at(0x17) TM2S
#define GPCC    	gpcc // __sfr __at(0x18) GPCC
#define GPCS    	gpcs // __sfr __at(0x19) GPCS
#define BGTR    	bgtr // __sfr __at(0x1a) BGTR
#define MISC_LVR	misc_lvr // __sfr __at(0x1b) MISC_LVR
#define TM2C    	tm2c // __sfr __at(0x1c) TM2C
#define TM2CT   	tm2ct // __sfr __at(0x1d) TM2CT
#define PWMG0C  	pwmg0c // __sfr __at(0x20) PWMG0C
#define PWMGCLK 	pwmgclk // __sfr __at(0x21) PWMGCLK
#define PWMG0DTH	pwmg0dth // __sfr __at(0x22) PWMG0DTH
#define PWMG0DTL	pwmg0dtl // __sfr __at(0x23) PWMG0DTL
#define PWMG0CUBH	pwmg0cubh // __sfr __at(0x24) PWMG0CUBH
#define PWMG0CUBL	pwmg0cubl // __sfr __at(0x25) PWMG0CUBL
#define PWMG1C  	pwmg1c // __sfr __at(0x26) PWMG1C
#define PWMG1DTH	pwmg1dth // __sfr __at(0x28) PWMG1DTH
#define PWMG1DTL	pwmg1dtl // __sfr __at(0x29) PWMG1DTL
#define PWMG2C  	pwmg2c // __sfr __at(0x2c) PWMG2C
#define PWMG2DTH	pwmg2dth // __sfr __at(0x2e) PWMG2DTH
#define PWMG2DTL	pwmg2dtl // __sfr __at(0x2f) PWMG2DTL
#define ILRCR   	ilrcr // __sfr __at(0x39) ILRCR
#define ROP     	rop // __sfr __at(0x3a) ROP

__sfr __at(0x00)	flag;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;

__sfr __at(0x08)	misc;
__sfr __at(0x09)	tm2b;
__sfr __at(0x0a)	eoscr;
__sfr __at(0x0b)	ihrcr;
__sfr __at(0x0c)	integs;
__sfr __at(0x0d)	padier;
__sfr __at(0x0e)	pbdier;
__sfr __at(0x0f)	misc2;

__sfr __at(0x10)	pa;
__sfr __at(0x11)	pac;
__sfr __at(0x12)	paph;
__sfr __at(0x14)	pb;
__sfr __at(0x15)	pbc;
__sfr __at(0x16)	pbph;
__sfr __at(0x17)	tm2s;

__sfr __at(0x18)	gpcc;
__sfr __at(0x19)	gpcs;
__sfr __at(0x1a)	bgtr;
__sfr __at(0x1b)	misc_lvr;
__sfr __at(0x1c)	tm2c;
__sfr __at(0x1d)	tm2ct;

__sfr __at(0x20)	pwmg0c;
__sfr __at(0x21)	pwmgclk;
__sfr __at(0x22)	pwmg0dth;
__sfr __at(0x23)	pwmg0dtl;
__sfr __at(0x24)	pwmg0cubh;
__sfr __at(0x25)	pwmg0cubl;
__sfr __at(0x26)	pwmg1c;

__sfr __at(0x28)	pwmg1dth;
__sfr __at(0x29)	pwmg1dtl;
__sfr __at(0x2c)	pwmg2c;
__sfr __at(0x2e)	pwmg2dth;
__sfr __at(0x2f)	pwmg2dtl;


__sfr __at(0x39)	ilrcr;
__sfr __at(0x3a)	rop;

#endif
