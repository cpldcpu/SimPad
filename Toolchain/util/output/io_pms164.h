// I/O include file for Padauk PMS164
// Version: 0.1a
// Automatically generated on 2019-09-01 20:55:50.723372

#ifndef __PDK_IO_PMS164_H
#define __PDK_IO_PMS164_H

#include <pdk/io_common.h>

#define __PDK_IOEND 63



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
