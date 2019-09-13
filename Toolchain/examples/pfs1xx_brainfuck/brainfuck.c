// simple brainfuck interpreter for Paudak PFS154
// cpldcpu Sep 12th, 2019
//
// Based on sbi.c by Daniel B. Cristofani 
// http://www.brainfuck.org/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pdk/io_pfs154.h>
#include <pdk/delay.h>

#define ARRAYSIZE 64
#define MAXCODESIZE 512

// ----------------------------------------------------------------------------
// Brainfuck code is defined directly in code array. Uncomment examples below
// ----------------------------------------------------------------------------

//squares
const char code[]="++++[>+++++<-]>[<+++++>-]+<+[>[>+>+<<-]++>>[<<+>>-]>>>[-]++>[-]+>>>+[[-]++++++>>>]<<<[[<++++++++<++>>-]+<.<[>----<-]<]<<[>>>>>[>>>[-]+++++++++<[>-<-]+++++++++>[-[<->-]+[<<<]]<[>+<-]>]<<-]<<-]";

//tree - does require input
// const char code[]=">>>--------<,[<[>++++++++++<-]>>[<------>>-<+],]++>>++<--[<++[+>]>+<<+++<]<<[>>+[[>>+<<-]<<]>>>>[[<<+>.>-]>>]<.<<<+<<-]>>[<.>--]>.>>.";

// fibonacci - terminates in gibberish
// const char code[]=">++++++++++>+>+[[+++++[>++++++++<-]>.<++++++[>--------<-]+<<<]>.>>[[-]<[>+<-]>>[<<+>+>-]<[>+<-[>+<-[>+<-[>+<-[>+<-[>+<-[>+<-[>+<-[>+<-[>[-]>+>+<<<-[>+<-]]]]]]]]]]]+>>>]<<<]";

// print "brainfuck"
// const char code[]=">++++[>++++++<-]>-[[<+++++>>+<-]>-]<<[<]>>>>--.<<<-.>>>-.<.<.>---.<<+++.>>>++.<<---.[>]<<.";

// print "hello world"
// const char code[]="++++++++[>++++[>++>+++>+++>+<<<<-]>+>->+>>+[<]<-]>>.>>---.+++++++..+++.>.<<-.>.+++.------.--------.>+.>++.";

// output powers of two
// const char code[]=">++++++++++>>+<+[[+++++[>++++++++<-]>.<++++++[>--------<-]+<<]>.>[->[<++>-[<++>-[<++>-[<++>-[<-------->>[-]++<-[<++>-]]]]]]<[>+<-]+>>]<<] ";

// --------------------------------------------------------------------

extern int putchar(int);
uint16_t findloopbegin(uint16_t);
uint16_t findloopend(uint16_t);
volatile uint8_t array[ARRAYSIZE]; // memory array

unsigned char _sdcc_external_startup(void)
{
	clkmd = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	EASY_PDK_CALIBRATE_IHRC(8000000,5000);      //tune SYSCLK to 8.0MHz @ 3.300V
	putchar(0x55);  // send synchronisation character for autobaud
	delay_ms(5);    // wait needed for autobaud
    return 0; // perform normal initialization
}

uint16_t findloopend(uint16_t codep) {
    uint16_t depth=0;
    for (int16_t i=(int16_t)codep+1; i++; i<MAXCODESIZE) {
        switch (code[i]) {
            case '[': depth++; break;
            case ']': if (!depth--) return i; break;
        }        
    }
    printf("Umatched [\n");
    return 0;
}

uint16_t findloopbegin(uint16_t codep) {
    uint16_t depth=0;
    for (int16_t i=(int16_t)codep-1; i--; i>=0) {
        switch (code[i]) {
            case '[': if (!depth--) return i; break;
            case ']': depth++; break;
        }        
    }
    printf("Umatched ]\n");
    return 0;
}

void main(void){
    uint8_t memp;
    uint16_t codep, codelength;

    codelength=sizeof(code);
    memp=0;
    for(codep=0;codep<codelength;codep++){//Everything is okay; we start executing the program.
         switch(code[codep]){
            case '+': array[memp]++; break;
            case '-': array[memp]--; break;
            case '<': memp--; memp&=(ARRAYSIZE-1); break;
            case '>': memp++; memp&=(ARRAYSIZE-1);break;
            case ',': printf("Entry command ',' not supported\n");break;
            case '.': putchar(array[memp]==10?'\n':array[memp]); break;
            case '[': if(!array[memp]) codep=findloopend(codep); break;
            case ']': if(array[memp]) codep=findloopbegin(codep); break;
        }
    }
}
