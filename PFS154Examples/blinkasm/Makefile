# Makefile for SDCC with PDK14 target assembler project
# Jan 13, 2019 TB
#
# Inspired from here:
# https://github.com/lujji/stm8-bare-min/blob/master/stm8s/examples/Makefile.include


SDCC=sdcc
SDLD=sdld
SDAS=sdaspdk
OBJCOPY=sdobjcopy
TARGET=main.ihx
ASFLAGS=-lo
LDFLAGS=-mpdk14 -lpdk14 --out-fmt-ihx
CFLAGS=-lpdk14 -mpdk14
SPCONV= python3 ../simpad_conv.py
SPDISAS= python3 ../simpad_disasm.py

SRCS    := $(wildcard *.c $(LIBDIR)/*.c)
ASRCS   := $(wildcard *.s $(LIBDIR)/*.s)

OBJS     = $(SRCS:.c=.rel)
OBJS 	+= $(ASRCS:.s=.rel)

all: $(TARGET) cinclude disasm

$(TARGET): $(OBJS)
	$(SDCC) $(LDFLAGS) $(OBJS) -o $@

%.rel: %.s
	$(SDAS) $(ASFLAGS) $<

%.rel: %.c
	$(SDCC) $(CFLAGS) $(INCLUDE) -c $< -o $@

size:
	$(OBJCOPY) -I ihex -O binary $(TARGET) $(TARGET).bin
	@echo "Image size:"
	@stat -L -c %s $(TARGET).bin
cinclude: 
	$(SPCONV) >$(TARGET).h_txt
disasm:
	$(SPDISAS)
clean:
	rm -f $(OBJECTS) *.map *.asm *.rel *.ihx *.o *.sym *.lk *.lst *.rst *.cdb *.bin *.h_txt

.PHONY: all clean flash
