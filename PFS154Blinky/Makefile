# Makefile for SDCC with PDK14 target assembler project
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
PYTHON=python

SRCS    := $(wildcard *.c $(LIBDIR)/*.c)
ASRCS   := $(wildcard *.s $(LIBDIR)/*.s)

OBJS     = $(SRCS:.c=.rel)
OBJS 	+= $(ASRCS:.s=.rel)

all: $(TARGET) cinclude

$(TARGET): $(OBJS)
	$(SDCC) $(LDFLAGS) $(OBJS) -o $@

%.rel: %.s
	$(SDAS) $(ASFLAGS) $<

%.rel: %.c
	$(SDCC) $(CFLAGS) $(INCLUDE) -c $< -o $@

cinclude: 
	$(PYTHON) simpad.py >$(TARGET).h_txt

clean:
	rm -f $(OBJECTS) *.map *.asm *.rel *.ihx *.o *.sym *.lk *.lst *.rst *.cdb *.bin *.h_txt

.PHONY: all clean flash
