# Example using the PDK_softuart serial monitor

The soft UART TX and print functions founds in ```"library/PDK_softuart.c"``` provide a simple monitor function that can be used for debugging. All functions are programmed in size optimized Assembler and occupy less than 100 instructions. No hardware ressources (IRQ) are used which allows retargeting to any GPIO. Default is PA7, which is also the default pin used by EASYPDKPROG.

Right now the following calls are supported

  - ```void PDK_autobaud(void)      ``` Autobaud for the easypdkprogrammer. This needs to be called before sending anything on the UART
  - ```void PDK_sendchar(uint8_t)   ``` Send a single char on the serial port. So far, no receving is possible.
  - ```void PDK_sendstring(char *)  ``` Sends a zero terminated string that can reside in RAM or ROM
  - ```void PDK_senduint16(uint16_t)``` Prints a decimal representation of a 16 bit unsigned value on the UART.

No serial receive functionality is provided as of now.

The implementation can be found [here](../../library/PDK_softuart.c).
