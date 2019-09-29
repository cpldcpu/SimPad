// I/O include file for Padauk PMS132B
// Version: 0.11a
// Automatically generated on 2019-09-29 16:10:55.810268

#ifndef __PDK_IO_PMS132B_H
#define __PDK_IO_PMS132B_H

#include <pdk/io_common.h>

#define __PDK_IOEND 63

#define PDK_USE_FACTORY_TRIMMING() {#error 'this device does not support factory trimming'}

#define FLAG    	flag // __sfr __at(0x00) FLAG
#define SP      	sp // __sfr __at(0x02) SP
#define CLKMD   	clkmd // __sfr __at(0x03) CLKMD
#define INTEN   	inten // __sfr __at(0x04) INTEN
#define INTRQ   	intrq // __sfr __at(0x05) INTRQ
#define T16M    	t16m // __sfr __at(0x06) T16M
#define MULOP   	mulop // __sfr __at(0x08) MULOP
#define TM2B    	tm2b // __sfr __at(0x09) TM2B
#define EOSCR   	eoscr // __sfr __at(0x0a) EOSCR
#define IHRCR   	ihrcr // __sfr __at(0x0b) IHRCR
#define INTEGS  	integs // __sfr __at(0x0c) INTEGS
#define PADIER  	padier // __sfr __at(0x0d) PADIER
#define PBDIER  	pbdier // __sfr __at(0x0e) PBDIER
#define MISC2   	misc2 // __sfr __at(0x0f) MISC2
#define PA      	pa // __sfr __at(0x10) PA
#define PAC     	pac // __sfr __at(0x11) PAC
#define PAPH    	paph // __sfr __at(0x12) PAPH
#define PB      	pb // __sfr __at(0x14) PB
#define PBC     	pbc // __sfr __at(0x15) PBC
#define PBPH    	pbph // __sfr __at(0x16) PBPH
#define MISC    	misc // __sfr __at(0x17) MISC
#define GPCC    	gpcc // __sfr __at(0x18) GPCC
#define GPCS    	gpcs // __sfr __at(0x19) GPCS
#define BGTR    	bgtr // __sfr __at(0x1a) BGTR
#define RSTST   	rstst // __sfr __at(0x1b) RSTST
#define TM2C    	tm2c // __sfr __at(0x1c) TM2C
#define TM2CT   	tm2ct // __sfr __at(0x1d) TM2CT
#define TM2S    	tm2s // __sfr __at(0x1e) TM2S
#define PWMG0C  	pwmg0c // __sfr __at(0x20) PWMG0C
#define PWMG0S  	pwmg0s // __sfr __at(0x21) PWMG0S
#define PWMG0DTH	pwmg0dth // __sfr __at(0x22) PWMG0DTH
#define PWMG0DTL	pwmg0dtl // __sfr __at(0x23) PWMG0DTL
#define PWMG0CUBH	pwmg0cubh // __sfr __at(0x24) PWMG0CUBH
#define PWMG0CUBL	pwmg0cubl // __sfr __at(0x25) PWMG0CUBL
#define PWMG1C  	pwmg1c // __sfr __at(0x26) PWMG1C
#define PWMG1S  	pwmg1s // __sfr __at(0x27) PWMG1S
#define PWMG1DTH	pwmg1dth // __sfr __at(0x28) PWMG1DTH
#define PWMG1DTL	pwmg1dtl // __sfr __at(0x29) PWMG1DTL
#define PWMG1CUBH	pwmg1cubh // __sfr __at(0x2a) PWMG1CUBH
#define PWMG1CUBL	pwmg1cubl // __sfr __at(0x2b) PWMG1CUBL
#define PWMG2C  	pwmg2c // __sfr __at(0x2c) PWMG2C
#define PWMG2S  	pwmg2s // __sfr __at(0x2d) PWMG2S
#define PWMG2DTH	pwmg2dth // __sfr __at(0x2e) PWMG2DTH
#define PWMG2DTL	pwmg2dtl // __sfr __at(0x2f) PWMG2DTL
#define PWMG2CUBH	pwmg2cubh // __sfr __at(0x30) PWMG2CUBH
#define PWMG2CUBL	pwmg2cubl // __sfr __at(0x31) PWMG2CUBL
#define TM3C    	tm3c // __sfr __at(0x32) TM3C
#define TM3S    	tm3s // __sfr __at(0x33) TM3S
#define TM3CT   	tm3ct // __sfr __at(0x34) TM3CT
#define TM3B    	tm3b // __sfr __at(0x35) TM3B
#define ADC_BGTR	adc_bgtr // __sfr __at(0x36) ADC_BGTR
#define ADC_REFTR	adc_reftr // __sfr __at(0x37) ADC_REFTR
#define ADC_OFSTR	adc_ofstr // __sfr __at(0x38) ADC_OFSTR
#define ILRCR   	ilrcr // __sfr __at(0x39) ILRCR
#define ROP     	rop // __sfr __at(0x3a) ROP
#define ADCC    	adcc // __sfr __at(0x3b) ADCC
#define ADCM    	adcm // __sfr __at(0x3c) ADCM
#define ADCRGC  	adcrgc // __sfr __at(0x3d) ADCRGC
#define ADCR    	adcr // __sfr __at(0x3e) ADCR
#define ADCRL   	adcrl // __sfr __at(0x3f) ADCRL

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
__sfr __at(0x0f)	misc2;

__sfr __at(0x10)	pa;
__sfr __at(0x11)	pac;
__sfr __at(0x12)	paph;
__sfr __at(0x14)	pb;
__sfr __at(0x15)	pbc;
__sfr __at(0x16)	pbph;
__sfr __at(0x17)	misc;

__sfr __at(0x18)	gpcc;
__sfr __at(0x19)	gpcs;
__sfr __at(0x1a)	bgtr;
__sfr __at(0x1b)	rstst;
__sfr __at(0x1c)	tm2c;
__sfr __at(0x1d)	tm2ct;
__sfr __at(0x1e)	tm2s;

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
__sfr __at(0x32)	tm3c;
__sfr __at(0x33)	tm3s;
__sfr __at(0x34)	tm3ct;
__sfr __at(0x35)	tm3b;
__sfr __at(0x36)	adc_bgtr;
__sfr __at(0x37)	adc_reftr;

__sfr __at(0x38)	adc_ofstr;
__sfr __at(0x39)	ilrcr;
__sfr __at(0x3a)	rop;
__sfr __at(0x3b)	adcc;
__sfr __at(0x3c)	adcm;
__sfr __at(0x3d)	adcrgc;
__sfr __at(0x3e)	adcr;
__sfr __at(0x3f)	adcrl;

#endif
