// I/O include file for Padauk PFS154
// Version: 0.1a
// Automatically generated on 2019-09-01 20:30:59.592097

#ifndef __PDK_IO_PFS154_H
#define __PDK_IO_PFS154_H

#include <pdk/io_common.h>

#define __PDK_RAMEND 127
#define __PDK_IOEND 63
#define __PDK_FLASHEND 2047

#define __PDK_IHRCCAL *((const unsigned char*)(34797))

__sfr16	t16c;

__sfr __at(0x00)	flag;
__sfr __at(0x02)	sp;
__sfr __at(0x03)	clkmd;
__sfr __at(0x04)	inten;
__sfr __at(0x05)	intrq;
__sfr __at(0x06)	t16m;

__sfr __at(0x08)	misc;
__sfr __at(0x09)	tm2b;
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
__sfr __at(0x1b)	misc_lvr;
__sfr __at(0x1c)	tm2c;
__sfr __at(0x1d)	tm2ct;

__sfr __at(0x20)	pwmg0c;
__sfr __at(0x21)	pwmg0s;
__sfr __at(0x22)	pwmg0dth;
__sfr __at(0x23)	pwmg0dtl;
__sfr __at(0x24)	pwmg0cubh;
__sfr __at(0x25)	pwmg0cubl;
__sfr __at(0x26)	pwmg1c;
__sfr __at(0x27)	pwmg1s;

__sfr __at(0x28)	pwmg1dth;
__sfr __at(0x29)	pwmg1dtl;
__sfr __at(0x2a)	pwmg1cubh;
__sfr __at(0x2b)	pwmg1cubl;
__sfr __at(0x2c)	pwmg2c;
__sfr __at(0x2d)	pwmg2s;
__sfr __at(0x2e)	pwmg2dth;
__sfr __at(0x2f)	pwmg2dtl;

__sfr __at(0x30)	pwmg2cubh;
__sfr __at(0x31)	pwmg2cubl;

__sfr __at(0x39)	ilrcr;

#endif
