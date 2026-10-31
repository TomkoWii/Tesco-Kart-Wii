TARGET := TescoKartWii
DEVKITPPC := /opt/devkitpro/devkitPPC

include $(DEVKITPPC)/wii_rules

CFLAGS := -g -O2 -mrvl -Wall
CXXFLAGS := $(CFLAGS)
INCLUDES := -Iinclude
LIBS := -lgrrlib -lwiiuse -lbte -logc -lm

all: $(TARGET).dol

$(TARGET).elf: src/main.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(TARGET).dol: $(TARGET).elf
	elf2dol $< $@

clean:
	rm -f src/*.o *.elf *.dol
