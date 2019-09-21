// I/O include file for Padauk PFS172
// Version: 0.1a
// Automatically generated on 2019-09-21 11:25:32.753601

#ifndef __PDK_IO_PFS172_H
#define __PDK_IO_PFS172_H

#include <pdk/io_common.h>

#define __PDK_IOEND 63


#define FLAG    	flag // __sfr __at(0x00) FLAG
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M

#define EOSCR   	eoscr // __sfr __at(0x0a) EOSCR
#define IHRCR   	ihrcr // __sfr __at(0x0b) IHRCR
#define INTEGS  	integs // __sfr __at(0x0c) INTEGS
#define PADIER  	padier // __sfr __at(0x0d) PADIER
#define PBDIER  	pbdier // __sfr __at(0x0e) PBDIER

#define PA      	pa // __sfr __at(0x10) PA
#define PAC     	pac // __sfr __at(0x11) PAC
#define PAPH    	paph // __sfr __at(0x12) PAPH
#define PAPL    	papl // __sfr __at(0x13) PAPL
#define PB      	pb // __sfr __at(0x15) PB
#define PBC     	pbc // __sfr __at(0x16) PBC
#define PBPH    	pbph // __sfr __at(0x17) PBPH

#define PBPL    	pbpl // __sfr __at(0x18) PBPL

#define ADCC    	adcc // __sfr __at(0x20) ADCC
#define ADCM    	adcm // __sfr __at(0x21) ADCM
#define ADCR    	adcr // __sfr __at(0x22) ADCR
#define MISC    	misc // __sfr __at(0x26) MISC
#define MISC2   	misc2 // __sfr __at(0x27) MISC2

#define MISC_LVR	misc_lvr // __sfr __at(0x28) MISC_LVR
#define GPCC    	gpcc // __sfr __at(0x2b) GPCC
#define GPCS    	gpcs // __sfr __at(0x2c) GPCS

#define TM2C    	tm2c // __sfr __at(0x30) TM2C
#define TM2CT   	tm2ct // __sfr __at(0x31) TM2CT
#define TM2S    	tm2s // __sfr __at(0x32) TM2S
#define TM2B    	tm2b // __sfr __at(0x33) TM2B
#define TM3C    	tm3c // __sfr __at(0x34) TM3C
#define TM3S    	tm3s // __sfr __at(0x35) TM3S
#define TM3CT   	tm3ct // __sfr __at(0x36) TM3CT
#define TM3B    	tm3b // __sfr __at(0x37) TM3B

#define ILRCR   	ilrcr // __sfr __at(0x3b) ILRCR
#define BGTR    	bgtr // __sfr __at(0x3c) BGTR
#define ROP     	rop // __sfr __at(0x3d) ROP

__sfr __at(0x00)	flag;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;

__sfr __at(0x0a)	eoscr;
__sfr __at(0x0b)	ihrcr;
__sfr __at(0x0c)	integs;
__sfr __at(0x0d)	padier;
__sfr __at(0x0e)	pbdier;

__sfr __at(0x10)	pa;
__sfr __at(0x11)	pac;
__sfr __at(0x12)	paph;
__sfr __at(0x13)	papl;
__sfr __at(0x15)	pb;
__sfr __at(0x16)	pbc;
__sfr __at(0x17)	pbph;

__sfr __at(0x18)	pbpl;

__sfr __at(0x20)	adcc;
__sfr __at(0x21)	adcm;
__sfr __at(0x22)	adcr;
__sfr __at(0x26)	misc;
__sfr __at(0x27)	misc2;

__sfr __at(0x28)	misc_lvr;
__sfr __at(0x2b)	gpcc;
__sfr __at(0x2c)	gpcs;

__sfr __at(0x30)	tm2c;
__sfr __at(0x31)	tm2ct;
__sfr __at(0x32)	tm2s;
__sfr __at(0x33)	tm2b;
__sfr __at(0x34)	tm3c;
__sfr __at(0x35)	tm3s;
__sfr __at(0x36)	tm3ct;
__sfr __at(0x37)	tm3b;

__sfr __at(0x3b)	ilrcr;
__sfr __at(0x3c)	bgtr;
__sfr __at(0x3d)	rop;

#endif
