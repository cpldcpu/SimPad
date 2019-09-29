// simple brainfuck interpreter for Paudak PFS154
//
//    Sep 12th, 2019 cdldcpu    - initial
//    Sep 20th, 2019 cdldcpu    - adjusted to new library structure
// 
//
// Based on sbi.c by Daniel B. Cristofani 
// http://www.brainfuck.org/ 

#include <stdlib.h>
#include <stdint.h>
#include <pdk/io_pfs154.h>
#include <pdk/delay.h>

// UART configuration 
#define TXPORT pa
#define TXPORTC pac
#define TXPIN 7
#define BAUDRATE 38400

#include "delay.c"			// include delay implementation. 
#include "PDK_softuart.c"	// include softuart implementation

#define ARRAYSIZE 64
#define MAXCODESIZE 512

// ----------------------------------------------------------------------------
// Brainfuck code is defined directly in code array. Uncomment examples below
// ----------------------------------------------------------------------------

// print square numbers
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

uint16_t findloopbegin(uint16_t);
uint16_t findloopend(uint16_t);
volatile uint8_t array[ARRAYSIZE]; // memory array

unsigned char _sdcc_external_startup(void)
{
	CLKMD = CLKMD_IHRC_DIV2|CLKMD_ENABLE_IHRC;  // 8 Mhz main clock
	PDK_USE_FACTORY_TRIMMING();

    PDK_autobaud();  // send synchronisation character for autobaud
    
    return 0; 
}

uint16_t findloopend(uint16_t codep) {
    uint16_t depth=0;
    for (int16_t i=(int16_t)codep+1; i<MAXCODESIZE; i++) {
        switch (code[i]) {
            case '[': depth++; break;
            case ']': if (!depth--) return i; break;
        }        
    }
    PDK_sendstring("Umatched [\n");
    return 0;
}

uint16_t findloopbegin(uint16_t codep) {
    uint16_t depth=0;
    for (int16_t i=(int16_t)codep-1; i>=0 ; i--) {
        switch (code[i]) {
            case '[': if (!depth--) return i; break;
            case ']': depth++; break;
        }        
    }
    PDK_sendstring("Umatched ]\n");
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
            case ',': PDK_sendstring("Entry command ',' not supported\n");break;
            case '.': PDK_sendchar(array[memp]==10?'\n':array[memp]); break;
            case '[': if(!array[memp]) codep=findloopend(codep); break;
            case ']': if(array[memp]) codep=findloopbegin(codep); break;
        }
    }
}
