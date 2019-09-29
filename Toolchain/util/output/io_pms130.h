// I/O include file for Padauk PMS130
// Version: 0.11a
// Automatically generated on 2019-09-29 16:10:55.805264

#ifndef __PDK_IO_PMS130_H
#define __PDK_IO_PMS130_H

#include <pdk/io_common.h>

#define __PDK_IOEND 63

#define PDK_USE_FACTORY_TRIMMING() {#error 'this device does not support factory trimming'}

#define FLAG    	flag // __sfr __at(0x00) FLAG
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M
#define MULOP   	mulop // __sfr __at(0x08) MULOP
#define TM2B    	tm2b // __sfr __at(0x09) TM2B
#define EOSCR   	eoscr // __sfr __at(0x0a) EOSCR
#define IHRCR   	ihrcr // __sfr __at(0x0b) IHRCR
#define INTEGS  	integs // __sfr __at(0x0c) INTEGS
#define PADIER  	padier // __sfr __at(0x0d) PADIER
#define PBDIER  	pbdier // __sfr __at(0x0e) PBDIER
#define PA      	pa // __sfr __at(0x10) PA
#define PAC     	pac // __sfr __at(0x11) PAC
#define PAPH    	paph // __sfr __at(0x12) PAPH
#define PB      	pb // __sfr __at(0x14) PB
#define PBC     	pbc // __sfr __at(0x15) PBC
#define PBPH    	pbph // __sfr __at(0x16) PBPH
#define MISC    	misc // __sfr __at(0x1b) MISC
#define ADCRGC  	adcrgc // __sfr __at(0x1c) ADCRGC
#define ADCC    	adcc // __sfr __at(0x20) ADCC
#define ADCM    	adcm // __sfr __at(0x21) ADCM
#define ADCRH   	adcrh // __sfr __at(0x22) ADCRH
#define ADCRL   	adcrl // __sfr __at(0x23) ADCRL
#define RSTST   	rstst // __sfr __at(0x25) RSTST
#define TM3C    	tm3c // __sfr __at(0x2e) TM3C
#define TM3CT   	tm3ct // __sfr __at(0x2f) TM3CT
#define BGTR    	bgtr // __sfr __at(0x36) BGTR
#define TM3S    	tm3s // __sfr __at(0x39) TM3S
#define ROP     	rop // __sfr __at(0x3a) ROP
#define TM2C    	tm2c // __sfr __at(0x3c) TM2C
#define TM2CT   	tm2ct // __sfr __at(0x3d) TM2CT

__sfr __at(0x00)	flag;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;

__sfr __at(0x08)	mulop;
__sfr __at(0x09)	tm2b;
__sfr __at(0x0a)	eoscr;
__sfr __at(0x0b)	ihrcr;
__sfr __at(0x0c)	integs;
__sfr __at(0x0d)	padier;
__sfr __at(0x0e)	pbdier;

__sfr __at(0x10)	pa;
__sfr __at(0x11)	pac;
__sfr __at(0x12)	paph;
__sfr __at(0x14)	pb;
__sfr __at(0x15)	pbc;
__sfr __at(0x16)	pbph;

__sfr __at(0x1b)	misc;
__sfr __at(0x1c)	adcrgc;

__sfr __at(0x20)	adcc;
__sfr __at(0x21)	adcm;
__sfr __at(0x22)	adcrh;
__sfr __at(0x23)	adcrl;
__sfr __at(0x25)	rstst;

__sfr __at(0x2e)	tm3c;
__sfr __at(0x2f)	tm3ct;

__sfr __at(0x36)	bgtr;

__sfr __at(0x39)	tm3s;
__sfr __at(0x3a)	rop;
__sfr __at(0x3c)	tm2c;
__sfr __at(0x3d)	tm2ct;

#endif
