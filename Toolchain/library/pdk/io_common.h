// common include for PDK io functions
// based on pms150c.h by JS
// see: https://www.eevblog.com/forum/blog/eevblog-1144-padauk-programmer-reverse-engineering/msg2656752/#msg2656752


#ifndef __PDK_IO_COMMON_H
#define __PDK_IO_COMMON_H

/* Generate code with for calibration. Make sure your programmer supports it.
*/

#define EASY_PDK_CALIBRATE_IHRC(frequency,millivolt) EASY_PDK_CALIBRATE_IHRCx(frequency,millivolt)
#define EASY_PDK_CALIBRATE_IHRCx(frequency,millivolt) \
__asm__(                      \
  "and a, #'H'                \n"\
  "and a, #'8'                \n"\
  "and a, #("#frequency")     \n"\
  "and a, #("#frequency">>8)  \n"\
  "and a, #("#frequency">>16) \n"\
  "and a, #("#frequency">>24) \n"\
  "and a, #("#millivolt")     \n"\
  "and a, #("#millivolt">>8)  \n"\
)

// concatenate underscore for assembler sections

#define sl(x) _ ## x
#define s(y) sl(y)

//Port definitions
#define _BV(x)  (1<<(x))

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

//clkmd definitions
 #define CLKMD_ENABLE_PA5RST          0x01
 #define CLKMD_ENABLE_WATCHDOG        0x02
 #define CLKMD_ENABLE_ILRC            0x04
 #define CLKMD_ENABLE_IHRC            0x10
 #define CLKMD_IHRC_DIV2              0x20
 #define CLKMD_IHRC_DIV4              0x00
 #define CLKMD_IHRC_DIV8              0x28
 #define CLKMD_IHRC_DIV16             0x08
 #define CLKMD_IHRC_DIV32             0x68
 #define CLKMD_IHRC_DIV64             0x88
 #define CLKMD_ILRC                   0xe0
 #define CLKMD_ILRC_DIV4              0xc0

//interrupt enable definitions
 #define INTEN_PA0                    0x01
 #define INTEN_T16                    0x04
 #define INTEN_COMP                   0x10
 #define INTEN_TM2                    0x40

//interrupt request definitions
 #define INTRQ_PA0                    0x01
 #define INTRQ_T16                    0x04
 #define INTRQ_COMP                   0x10
 #define INTRQ_TM2                    0x40

//tm16 definitions
 #define T16_INTSRC_8BIT              0x00
 #define T16_INTSRC_9BIT              0x01
 #define T16_INTSRC_10BIT             0x02
 #define T16_INTSRC_11BIT             0x03
 #define T16_INTSRC_12BIT             0x04
 #define T16_INTSRC_13BIT             0x05
 #define T16_INTSRC_14BIT             0x06
 #define T16_INTSRC_15BIT             0x07
 #define T16_CLK_DIV1                 0x00
 #define T16_CLK_DIV4                 0x08
 #define T16_CLK_DIV16                0x10
 #define T16_CLK_DIV64                0x18
 #define T16_CLK_DISABLE              0x00
 #define T16_CLK_SYSCLK               0x20
 #define T16_CLK_PA4_FALL             0x60
 #define T16_CLK_IHRC                 0x80
 #define T16_CLK_ILRC                 0xC0
 #define T16_CLK_PA0_FALL             0xE0

//eosc definitions
 #define EOSC_LVD_BANDGAP_SHUTDOWN    0x01

//integs definitions
 #define INTEGS_PA0_BOTH              0x00
 #define INTEGS_PA0_RISING            0x01
 #define INTEGS_PA0_FALLING           0x02
 #define INTEGS_T16_RISING            0x00
 #define INTEGS_T16_FALLING           0x04
 #define INTEGS_COMP_BOTH             0x00
 #define INTEGS_COMP_RISING           0x40
 #define INTEGS_COMP_FALLING          0x80

//padie definitions
 #define PADIE_PA0_WAKEUP_ENABLE      0x01
 #define PADIE_PA3_WAKEUP_ENABLE      0x08
 #define PADIE_PA4_WAKEUP_ENABLE      0x10
 #define PADIE_PA5_WAKEUP_ENABLE      0x20
 #define PADIE_PA6_WAKEUP_ENABLE      0x40
 #define PADIE_PA7_WAKEUP_ENABLE      0x80

//misc definitions
 #define MISC_WATCHDOG_8K_ILRC        0x00
 #define MISC_WATCHDOG_16K_ILRC       0x01
 #define MISC_WATCHDOG_64K_ILRC       0x02
 #define MISC_WATCHDOG_256K_ILRC      0x03
 #define MISC_LVR_DISABLE             0x04
 #define MISC_FAST_WAKEUP_ENABLE      0x20

//tm2c definitions
 #define TM2C_CLK_DISABLE             0x00
 #define TM2C_CLK_SYSCLK              0x10
 #define TM2C_CLK_IHRC                0x20
 #define TM2C_CLK_EOSC                0x30
 #define TM2C_CLK_ILRC                0x40
 #define TM2C_CLK_COMPOUT             0x50
 #define TM2C_CLK_PA0_RISE            0x80
 #define TM2C_CLK_PA0_FALL            0x90
 #define TM2C_CLK_PB0_RISE            0xA0
 #define TM2C_CLK_PB0_FALL            0xB0
 #define TM2C_CLK_PA4_RISE            0xC0
 #define TM2C_CLK_PA4_FALL            0xD0
 #define TM2C_OUT_DISABLE             0x00
 #define TM2C_OUT_PB2                 0x04
 #define TM2C_OUT_PA3                 0x08
 #define TM2C_OUT_PB4                 0x0C
 #define TM2C_MODE_PERIOD             0x00
 #define TM2C_MODE_PWM                0x02
 #define TM2C_INVERT_OUT              0x01

//tm2s definitions
 #define TM2S_PWM_RES_8BIT            0x00
 #define TM2S_PWM_RES_6BIT            0x80
 #define TM2S_PRESCALE_NONE           0x00
 #define TM2S_PRESCALE_DIV4           0x20
 #define TM2S_PRESCALE_DIV16          0x40
 #define TM2S_PRESCALE_DIV64          0x60

//gpcc definitions
 #define GPCC_COMP_PLUS_VINT_R        0x00
 #define GPCC_COMP_PLUS_PA4           0x01
 #define GPCC_COMP_MINUS_PA3          0x00
 #define GPCC_COMP_MINUS_PA4          0x02
 #define GPCC_COMP_MINUS_BANDGAP      0x04
 #define GPCC_COMP_MINUS_VINT_R       0x06
 #define GPCC_COMP_ENABLE             0x80
 #define GPCC_COMP_RESULT             0x40
 #define GPCC_COMP_SYNC_TM2           0x20
 #define GPCC_COMP_INVERSE            0x10

#if defined __SDCC_pdk13
 #define GPCC_COMP_MINUS_PA6          0x08
 #define GPCC_COMP_MINUS_PA7          0x0A
#else
 #define GPCC_COMP_MINUS_PB6          0x08
 #define GPCC_COMP_MINUS_PB7          0x0A
#endif

//gpcs definitions
 #define GPCS_COMP_CASE1              0x00
 #define GPCS_COMP_CASE2              0x10
 #define GPCS_COMP_CASE3              0x20
 #define GPCS_COMP_CASE4              0x30
 #define GPCS_COMP_WAKEUP_ENABLE      0x40
 #define GPCS_COMP_OUTPUT_PA0         0x80

 #endif