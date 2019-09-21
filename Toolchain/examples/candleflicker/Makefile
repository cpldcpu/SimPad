# ----------------------------------------------------------------
# Generic makefile for the Padauk open source toolchain
# 
# Usage:
#
# make					- build project
# make flash			- flash binary to microcontroller
# make start			- start program on microcontroller	
# make clean			- clean
# make compileandrun	- compile, flash and start
#
# Requires the SDCC compiler and the easypdkprog programmer
#
# ----------------------------------------------------------------
# History:
#
# Sep 1th, 2019/cpldcpu		First version
# ----------------------------------------------------------------

# Define your processor settings here

MCU		= pfs154
ARCH	= pdk14
F_CPU	= 1000000
TARGET	= main.ihx

# Toolchain settings. Usually does not need to be changed

LIBRARY = ../../library
SDCC	= sdcc
SDLD	= sdld
SDAS	= sdaspdk14
OBJCOPY	= sdobjcopy
PROGRAMMER	= easypdkprog

# Compiler flags

ASFLAGS	= -lo
LDFLAGS	= -m$(ARCH) -l$(ARCH) --out-fmt-ihx 
CFLAGS 	= -m$(ARCH) -p$(MCU) -DF_CPU=$(F_CPU)
CFLAGS += -I. -I$(LIBRARY) 

SRCS    := $(wildcard *.c) # $(LIBRARY)/*.c)
ASRCS   := $(wildcard *.s) # $(LIBRARY)/*.s)

OBJS     = $(SRCS:.c=.rel)
OBJS 	+= $(ASRCS:.s=.rel)

all: $(TARGET) size 

$(TARGET): $(OBJS)
	$(SDCC) $(LDFLAGS) $(OBJS) -o $@

%.rel: %.s
	$(SDAS) $(ASFLAGS) $<

%.rel: %.c
	$(SDCC) $(CFLAGS) -c $< -o $@

flash:
	$(PROGRAMMER) -n $(MCU) write $(TARGET)

start: 
	$(PROGRAMMER) -n $(MCU) start

compileandrun: all flash start

size:
	$(OBJCOPY) -I ihex -O binary $(TARGET) $(TARGET).bin
	@echo ===============
	@echo Size of binary:
	@stat -L -c %s $(TARGET).bin
	@echo  bytes 
	@echo ===============

disasm:
	python3 simpad_disasm.py

clean:
	rm -f $(OBJECTS) *.map *.asm *.rel *.ihx *.sym *.lk *.lst *.rst *.cdb *.bin 

.PHONY: all clean flash
