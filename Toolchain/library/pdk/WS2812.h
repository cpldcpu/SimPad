/* ---------------------------------------------------------------
WS2812_.h

Sep 22, 2019 cpldcpu - first release
------------------------------------------------------------------ */

#ifndef __WS2812_h
#define __WS2812_h

// Write RGB to WS2812 string
#define PDK_WS2812_writeRGB(r,g,b) PDK_WS2812_writebyte(r);PDK_WS2812_writebyte(g);PDK_WS2812_writebyte(b);

// Write RGBW  to WS2812 string
#define PDK_WS2812_writeRGBW(r,g,b,w) PDK_WS2812_writebyte(r);PDK_WS2812_writebyte(g);PDK_WS2812_writebyte(b);PDK_WS2812_writebyte(w);


// Write single byte to RGB string
void PDK_WS2812_writebyte(uint8_t);

#endif