// I/O include file for Padauk PMS234
// Version: 0.1a
// Automatically generated on 2019-09-01 20:55:50.727376

#ifndef __PDK_IO_PMS234_H
#define __PDK_IO_PMS234_H

#include <pdk/io_common.h>

#define __PDK_IOEND 127



__sfr __at(0x00)	flag;
__sfr __at(0x01)	fppen;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;
__sfr __at(0x07)	gdio;

__sfr __at(0x0a)	eoscr;
__sfr __at(0x0b)	ihrcr;
__sfr __at(0x0c)	integs;
__sfr __at(0x0d)	padier;
__sfr __at(0x0e)	pbdier;
__sfr __at(0x0f)	(pcdier);

__sfr __at(0x10)	pa;
__sfr __at(0x11)	pac;
__sfr __at(0x12)	paph;
__sfr __at(0x14)	pb;
__sfr __at(0x15)	pbc;
__sfr __at(0x16)	pbph;
__sfr __at(0x17)	pc;

__sfr __at(0x18)	pcc;
__sfr __at(0x19)	pcph;
__sfr __at(0x1a)	pd;
__sfr __at(0x1b)	pdc;
__sfr __at(0x1c)	pdph;

__sfr __at(0x20)	adcc;
__sfr __at(0x21)	adcm;
__sfr __at(0x22)	adcrh ;
__sfr __at(0x23)	adcrl;
__sfr __at(0x25)	rstst;


__sfr __at(0x37)	tm2s;

__sfr __at(0x38)	a_ihrc;
__sfr __at(0x39)	bgtr;
__sfr __at(0x3b)	misc;
__sfr __at(0x3c)	tm2c;
__sfr __at(0x3d)	tm2ct;
__sfr __at(0x3e)	gpcc;









#endif
