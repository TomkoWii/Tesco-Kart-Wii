TARGET := TomkoWii
DEVKITPPC := /opt/devkitpro/devkitPPC

include $(DEVKITPPC)/wii_rules

CFLAGS := -g -O2 -mrvl -Wall
CXXFLAGS := $(CFLAGS)

# DÔLEŽITÉ: Povedz kompilátoru, kde presne hľadať grrlib a portlibs
INCLUDES := -Iinclude -I$(DEVKITPRO)/libogc/include -I$(PORTLIBS)/include

# Správne a kritické poradie knižníc podľa oficiálnej GRRLIB dokumentácie
LIBDIRS := $(PORTLIBS)
LIBS := -lgrrlib -lpngu -lfat -lwiiuse -lbte -logc -lm -lpng -ljpeg -lfreetype -lz

all: $(TARGET).dol

$(TARGET).elf: src/main.o
	$(CC) $(CFLAGS) $^ -L$(DEVKITPRO)/libogc/lib/wii -L$(PORTLIBS)/lib -o $@ $(LIBS)

$(TARGET).dol: $(TARGET).elf
	elf2dol $< $@

clean:
	rm -f src/*.o *.elf *.dol
