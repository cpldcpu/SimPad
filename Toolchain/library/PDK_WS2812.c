
/* ---------------------------------------------------------------
   PDK_WS2812.c

   Support for WS2812 RGB LEDs. Requires either 4 MHz or 8 MHz F_CPU
   clock. Please set F_CPU accordingly.

   The follow #defines need to be present before this source is included:

   WS2812_PORT  - Port regiser (pa,pb,pc)
   WS2812_PORTC - Port controler regiser (pac,pbc,pcc)
   WS2812_PIN   - Pin on port (0-7)
    
   Sep 22, 2019 cpldcpu - first release
------------------------------------------------------------------ */

/*
    Cycle timing: 

	              t0    t1    t2    t3    
	8 Mhz timing:  0    3     7     10
	4 Mhz timing:  1    2     3     6

    See here for details:
    https://cpldcpu.wordpress.com/2014/01/14/light_ws2812-library-v2-0-part-i-understanding-the-ws2812/

*/

#include <pdk/ws2812.h>

void  PDK_WS2812_writebyte(uint8_t in) {

	in;
#if (F_CPU==8000000)
__asm
	set1 	s(WS2812_PORTC),#(WS2812_PIN)
	mov     a,#8
10$:
	set1 	s(WS2812_PORT),#(WS2812_PIN)   ;0
	sl		_PDK_WS2812_writebyte_PARM_1+0     ;1
	nop 								   ;2
	swapc	s(WS2812_PORT),#(WS2812_PIN)   ;3
	nop 								   ;4
	nop 								   ;5
    nop                                    ;6
	set0 	s(WS2812_PORT),#(WS2812_PIN)   ;7	
	dzsn 	a							   ;8
	goto    10$		                       ;10
__endasm;
#elif (F_CPU==4000000)
__asm
	set1 	s(WS2812_PORTC),#(WS2812_PIN)
	mov     a,#8
10$:
	sl		_PDK_WS2812_writebyte_PARM_1+0     ;0
	set1 	s(WS2812_PORT),#(WS2812_PIN)   ;1
	swapc	s(WS2812_PORT),#(WS2812_PIN)   ;2
	set0 	s(WS2812_PORT),#(WS2812_PIN)   ;3	
	dzsn 	a							   ;4
	goto    10$		                       ;6
__endasm;
#else
	#error "Please set F_CPU to 8MHz or 4MHz for the WS2812 functions"
#endif
}
