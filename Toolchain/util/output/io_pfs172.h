// I/O include file for Padauk PFS172
// Version: 0.1a
// Automatically generated on 2019-09-01 20:55:50.724373

#ifndef __PDK_IO_PFS172_H
#define __PDK_IO_PFS172_H

#include <pdk/io_common.h>

#define __PDK_IOEND 63



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
