
// delay_h for padauk toolchain

#include <stdint.h>

#ifndef F_CPU
#   warning "F_CPU not defined, using 8MHz by default"
#   define F_CPU 8000000UL
#endif

extern void delay_ms(uint16_t delay);

#define delay_cycles(CYCLES)  __asm__("mov a,#("#CYCLES"/4)\n0$: sub a,#1\nt1sn f,z\ngoto 0$\n");  // each loop is 4 cycles.


