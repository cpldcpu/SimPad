// I/O include file for Padauk PMS15A
// Version: 0.1a
// Automatically generated on 2019-09-01 20:55:50.718368

#ifndef __PDK_IO_PMS15A_H
#define __PDK_IO_PMS15A_H

#include <pdk/io_common.h>

#define __PDK_IOEND 31



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
