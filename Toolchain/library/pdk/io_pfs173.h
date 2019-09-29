// I/O include file for Padauk PFS173
// Version: 0.11a
// Automatically generated on 2019-09-29 16:10:55.829285

#ifndef __PDK_IO_PFS173_H
#define __PDK_IO_PFS173_H

#include <pdk/io_common.h>

#define __PDK_RAMEND 255
#define __PDK_IOEND 127
#define __PDK_FLASHEND 3071

#define PDK_USE_FACTORY_TRIMMING() {__asm__ (".word (0x7bed)\nmov _ihrcr,a\n.word (0x7bee)\nmov _bgtr,a\n");}

#define T16C    	t16c // __sfr16 __at(0x00) T16C
__sfr16	t16c;

#define FLAG    	flag // __sfr __at(0x00) FLAG
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M
#define EOSCR   	eoscr // __sfr __at(0x0a) EOSCR
#define IHRCR   	ihrcr // __sfr __at(0x0b) IHRCR
#define INTEGS  	integs // __sfr __at(0x0c) INTEGS
#define PADIER  	padier // __sfr __at(0x0d) PADIER
#define PBDIER  	pbdier // __sfr __at(0x0e) PBDIER
#define PA      	pa // __sfr __at(0x10) PA
#define PAC     	pac // __sfr __at(0x11) PAC
#define PAPH    	paph // __sfr __at(0x12) PAPH
#define PB      	pb // __sfr __at(0x13) PB
#define PBC     	pbc // __sfr __at(0x14) PBC
#define PBPH    	pbph // __sfr __at(0x15) PBPH
#define PC      	pc // __sfr __at(0x16) PC
#define PCC     	pcc // __sfr __at(0x17) PCC
#define PCPH    	pcph // __sfr __at(0x18) PCPH
#define PBPL    	pbpl // __sfr __at(0x19) PBPL
#define PCPL    	pcpl // __sfr __at(0x1a) PCPL
#define ADCC    	adcc // __sfr __at(0x20) ADCC
#define ADCM    	adcm // __sfr __at(0x21) ADCM
#define ADCR    	adcr // __sfr __at(0x22) ADCR
#define ADCRGC  	adcrgc // __sfr __at(0x24) ADCRGC
#define MISC    	misc // __sfr __at(0x26) MISC
#define MISC2   	misc2 // __sfr __at(0x27) MISC2
#define MISC_LVR	misc_lvr // __sfr __at(0x28) MISC_LVR
#define GPCC    	gpcc // __sfr __at(0x2b) GPCC
#define GPCS    	gpcs // __sfr __at(0x2c) GPCS
#define TM2C    	tm2c // __sfr __at(0x30) TM2C
#define TM2CT   	tm2ct // __sfr __at(0x31) TM2CT
#define TM2S    	tm2s // __sfr __at(0x32) TM2S
#define TM2B    	tm2b // __sfr __at(0x33) TM2B
#define TM3C    	tm3c // __sfr __at(0x34) TM3C
#define TM3S    	tm3s // __sfr __at(0x35) TM3S
#define TM3CT   	tm3ct // __sfr __at(0x36) TM3CT
#define TM3B    	tm3b // __sfr __at(0x37) TM3B
#define PWMG0C  	pwmg0c // __sfr __at(0x40) PWMG0C
#define PWMGCLK 	pwmgclk // __sfr __at(0x41) PWMGCLK
#define PWMG0DTH	pwmg0dth // __sfr __at(0x42) PWMG0DTH
#define PWMG0DTL	pwmg0dtl // __sfr __at(0x43) PWMG0DTL
#define PWMG0CUBH	pwmg0cubh // __sfr __at(0x44) PWMG0CUBH
#define PWMG0CUBL	pwmg0cubl // __sfr __at(0x45) PWMG0CUBL
#define PWMG1C  	pwmg1c // __sfr __at(0x46) PWMG1C
#define PWMG1DTH	pwmg1dth // __sfr __at(0x48) PWMG1DTH
#define PWMG1DTL	pwmg1dtl // __sfr __at(0x49) PWMG1DTL
#define PWMG2C  	pwmg2c // __sfr __at(0x4c) PWMG2C
#define PWMG2DTH	pwmg2dth // __sfr __at(0x4e) PWMG2DTH
#define PWMG2DTL	pwmg2dtl // __sfr __at(0x4f) PWMG2DTL
#define ILRCR   	ilrcr // __sfr __at(0x62) ILRCR
#define BGTR    	bgtr // __sfr __at(0x63) BGTR
#define ROP     	rop // __sfr __at(0x67) ROP

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
