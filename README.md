# SimPad
Various hacks for Padauk MCU, the infamous "0.03USD" microcontroller. This is work in progress, don't expect anything to be functional or useful.

## Folders

### [Hardware](Hardware/)

Programmer for Padauk MCU based on Arduino Nano, currently living on a breadbord. See folder for a description of shortcomings.

### [Firmware](Firmware/)

Firmware, very incomplete work in progress. Is currently able to program PMS150C, PFC154, PMS154C. Right now, no host communication is implemented and the binary needs to be pasted into the source. Debug output is sent to serial output at 115200 baud. Will program a "blinky" into PFS154C in the current configuration. 

### [Protocol](Protocol/)

Information on programming protocol

### [Toolchain](Toolchain/)

Toolchain based on EASYPDKPROG and SDCC. Includes a few examples.

![Image of breadboard](hardware.jpg)
