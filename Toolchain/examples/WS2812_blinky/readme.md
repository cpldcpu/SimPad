# Example using the PDK_WS2812 support for RGB LEDs.

A small bitbanging routines to support writing to WS2812 and similar RGB-LEDS with integrated controller. Only 4 MHz and 8 MHz CPU clock is allowed.

The following calls are supported:

  - ```void PDK_WS2812_writebyte(uint8_t)    ``` Sends a single byte to the WS2812 string. Eache LED either needs 3 (RGB) or 4 (RGBW) bytes.
  - ```void PDK_WS_writeRGB(r,g,b)   ``` Send a RGB triple to the WS2812 string.
  - ```void PDK_WS_writeRGBW(r,g,b,w)   ``` Send a RGBW quadruple to the WS2812 string.

Please note that the WS2812 will automatically update their RGB value after the bus has been idle for >50µs. Make sure that a wait time is included after writing all date to the string to ensure proper updating.

The implementation can be found [here](../../library/PDK_WS2812.c).

In cases of issues, please take a look at the readme of the WS2812_light library [here](https://github.com/cpldcpu/light_ws2812).
