// I/O include file for Padauk PMS150C
// Version: 0.11a
// Automatically generated on 2019-09-29 16:10:55.796255

#ifndef __PDK_IO_PMS150C_H
#define __PDK_IO_PMS150C_H

#include <pdk/io_common.h>

#define __PDK_RAMEND 63
#define __PDK_IOEND 31
#define __PDK_FLASHEND 1023

#define PDK_USE_FACTORY_TRIMMING() {#error 'this device does not support factory trimming'}

#define T16C    	t16c // __sfr16 __at(0x00) T16C
__sfr16	t16c;

#define FLAG    	flag // __sfr __at(0x00) FLAG
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M
#define TM2B    	tm2b // __sfr __at(0x09) TM2B
#define EOSCR   	eoscr // __sfr __at(0x0a) EOSCR
#define IHRCR   	ihrcr // __sfr __at(0x0b) IHRCR
#define INTEGS  	integs // __sfr __at(0x0c) INTEGS
#define PADIER  	padier // __sfr __at(0x0d) PADIER
#define PA      	pa // __sfr __at(0x10) PA
#define PAC     	pac // __sfr __at(0x11) PAC
#define PAPH    	paph // __sfr __at(0x12) PAPH
#define TM2S    	tm2s // __sfr __at(0x17) TM2S
#define BGTR    	bgtr // __sfr __at(0x19) BGTR
#define GPCC    	gpcc // __sfr __at(0x1a) GPCC
#define MISC    	misc // __sfr __at(0x1b) MISC
#define TM2C    	tm2c // __sfr __at(0x1c) TM2C
#define TM2CT   	tm2ct // __sfr __at(0x1d) TM2CT
#define GPCS    	gpcs // __sfr __at(0x1e) GPCS
#define ILRCR   	ilrcr // __sfr __at(0x1f) ILRCR

__sfr __at(0x00)	flag;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;

__sfr __at(0x09)	tm2b;
__sfr __at(0x0a)	eoscr;
__sfr __at(0x0b)	ihrcr;
__sfr __at(0x0c)	integs;
__sfr __at(0x0d)	padier;

__sfr __at(0x10)	pa;
__sfr __at(0x11)	pac;
__sfr __at(0x12)	paph;
__sfr __at(0x17)	tm2s;

__sfr __at(0x19)	bgtr;
__sfr __at(0x1a)	gpcc;
__sfr __at(0x1b)	misc;
__sfr __at(0x1c)	tm2c;
__sfr __at(0x1d)	tm2ct;
__sfr __at(0x1e)	gpcs;
__sfr __at(0x1f)	ilrcr;

#endif
