// I/O include file for Padauk PMS164
// Version: 0.1a
// Automatically generated on 2019-09-21 11:25:32.753601

#ifndef __PDK_IO_PMS164_H
#define __PDK_IO_PMS164_H

#include <pdk/io_common.h>

#define __PDK_IOEND 63


#define FLAG    	flag // __sfr __at(0x00) FLAG
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M

#define MISC    	misc // __sfr __at(0x08) MISC
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
#define RSTST   	rstst // __sfr __at(0x1b) RSTST
#define TM2C    	tm2c // __sfr __at(0x1c) TM2C
#define TM2CT   	tm2ct // __sfr __at(0x1d) TM2CT
#define MISC3   	misc3 // __sfr __at(0x1e) MISC3


#define MISC_LVR	misc_lvr // __sfr __at(0x2d) MISC_LVR

#define TM3C    	tm3c // __sfr __at(0x32) TM3C
#define TM3CT   	tm3ct // __sfr __at(0x33) TM3CT
#define TM3S    	tm3s // __sfr __at(0x34) TM3S
#define TM3B    	tm3b // __sfr __at(0x35) TM3B

#define ILRCR   	ilrcr // __sfr __at(0x39) ILRCR
#define ROP     	rop // __sfr __at(0x3a) ROP

__sfr __at(0x00)	flag;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;

__sfr __at(0x08)	misc;
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
__sfr __at(0x1b)	rstst;
__sfr __at(0x1c)	tm2c;
__sfr __at(0x1d)	tm2ct;
__sfr __at(0x1e)	misc3;


__sfr __at(0x2d)	misc_lvr;

__sfr __at(0x32)	tm3c;
__sfr __at(0x33)	tm3ct;
__sfr __at(0x34)	tm3s;
__sfr __at(0x35)	tm3b;

__sfr __at(0x39)	ilrcr;
__sfr __at(0x3a)	rop;

#endif
