# Code examples PFS154 for SDCC

To be compiled on Philips branch of SDCC for the PDK14 target. See [here](https://www.mikrocontroller.net/topic/461002#5643846). Please note that his branch is work in progress and not yet ready to be released. 

blinky.c still has linker issues, the assembler examples work nicely.

Current workflow: The makefile generates a text file (main.ihx.h_txt) with c-instructions that need to be pasted into programmer main.c. 

