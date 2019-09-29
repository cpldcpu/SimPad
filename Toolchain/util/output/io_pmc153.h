// I/O include file for Padauk PMC153
// Version: 0.11a
// Automatically generated on 2019-09-29 16:10:55.801260

#ifndef __PDK_IO_PMC153_H
#define __PDK_IO_PMC153_H

#include <pdk/io_common.h>

#define __PDK_IOEND 31

#define PDK_USE_FACTORY_TRIMMING() {#error 'this device does not support factory trimming'}

#define FLAG    	flag // __sfr __at(0x00) FLAG
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M
#define -       	- // __sfr __at(0x0a) -
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

__sfr __at(0x00)	flag;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;

__sfr __at(0x0a)	-;
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

#endif
