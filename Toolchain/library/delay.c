// delay_c for easy pdk toolchain

#include <pdk/delay.h>
#include <stdint.h>

void delay_ms(uint16_t ms) {
	while (ms--) {
		for (uint8_t i=0; i<(F_CPU/1000/200); i++) __asm__("mov a,#50\n0$: sub a,#1\nt1sn f,z\ngoto 0$\n");  // each loop is 50*4=200 cycles.
	}
}

