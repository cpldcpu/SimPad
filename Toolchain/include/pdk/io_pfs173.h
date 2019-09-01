// I/O include file for Padauk PFS173
// Version: 0.1a
// Automatically generated on 2019-09-01 20:30:59.592097

#ifndef __PDK_IO_PFS173_H
#define __PDK_IO_PFS173_H

#include <pdk/io_common.h>

#define __PDK_RAMEND 255
#define __PDK_IOEND 127
#define __PDK_FLASHEND 3071

#define __PDK_IHRCCAL *((const unsigned char*)(35821))

__sfr16	t16c;

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
__sfr __at(0x13)	pb;
__sfr __at(0x14)	pbc;
__sfr __at(0x15)	pbph;
__sfr __at(0x16)	pc;
__sfr __at(0x17)	pcc;

__sfr __at(0x18)	pcph;
__sfr __at(0x19)	pbpl;
__sfr __at(0x1a)	pcpl;

__sfr __at(0x20)	adcc;
__sfr __at(0x21)	adcm;
__sfr __at(0x22)	adcr;
__sfr __at(0x24)	adcrgc;
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


__sfr __at(0x40)	pwmg0c;
__sfr __at(0x41)	pwmgclk;
__sfr __at(0x42)	pwmg0dth;
__sfr __at(0x43)	pwmg0dtl;
__sfr __at(0x44)	pwmg0cubh;
__sfr __at(0x45)	pwmg0cubl;
__sfr __at(0x46)	pwmg1c;

__sfr __at(0x48)	pwmg1dth;
__sfr __at(0x49)	pwmg1dtl;
__sfr __at(0x4c)	pwmg2c;
__sfr __at(0x4e)	pwmg2dth;
__sfr __at(0x4f)	pwmg2dtl;



__sfr __at(0x62)	ilrcr;
__sfr __at(0x63)	bgtr;
__sfr __at(0x67)	rop;




#endif
