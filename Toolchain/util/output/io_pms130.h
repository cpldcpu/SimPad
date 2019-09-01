// I/O include file for Padauk PMS130
// Version: 0.1a
// Automatically generated on 2019-09-01 20:55:50.720370

#ifndef __PDK_IO_PMS130_H
#define __PDK_IO_PMS130_H

#include <pdk/io_common.h>

#define __PDK_IOEND 63



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
