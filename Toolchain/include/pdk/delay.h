
// delay_h for padauk toolchain

#include <stdint.h>

#ifndef F_CPU
#   warning "F_CPU not defined, using 8MHz by default"
#   define F_CPU 8000000UL
#endif

extern void delay_ms(uint16_t delay);