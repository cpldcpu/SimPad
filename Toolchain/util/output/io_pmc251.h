// I/O include file for Padauk PMC251
// Version: 0.11a
// Automatically generated on 2019-09-29 16:10:55.841296

#ifndef __PDK_IO_PMC251_H
#define __PDK_IO_PMC251_H

#include <pdk/io_common.h>

#define __PDK_RAMEND 95
#define __PDK_IOEND 127
#define __PDK_FLASHEND 1023

#define PDK_USE_FACTORY_TRIMMING() {#error 'this device does not support factory trimming'}

#define T16C    	t16c // __sfr16 __at(0x00) T16C
__sfr16	t16c;

#define FLAG    	flag // __sfr __at(0x00) FLAG
#define FPPEN   	fppen // __sfr __at(0x01) FPPEN
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M
#define GDIO    	gdio // __sfr __at(0x07) GDIO
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
#define ADCC    	adcc // __sfr __at(0x20) ADCC
#define ADCM    	adcm // __sfr __at(0x21) ADCM
#define ADCRH   	adcrh // __sfr __at(0x22) ADCRH
#define ADCRL   	adcrl // __sfr __at(0x23) ADCRL
#define RSTST   	rstst // __sfr __at(0x25) RSTST
#define A_IHRC  	a_ihrc // __sfr __at(0x38) A_IHRC
#define (BGTR)  	(bgtr) // __sfr __at(0x39) (BGTR)
#define MISC    	misc // __sfr __at(0x3b) MISC

__sfr __at(0x00)	flag;
__sfr __at(0x01)	fppen;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;
__sfr __at(0x07)	gdio;

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


__sfr __at(0x20)	adcc;
__sfr __at(0x21)	adcm;
__sfr __at(0x22)	adcrh;
__sfr __at(0x23)	adcrl;
__sfr __at(0x25)	rstst;



__sfr __at(0x38)	a_ihrc;
__sfr __at(0x39)	(bgtr);
__sfr __at(0x3b)	misc;









#endif
