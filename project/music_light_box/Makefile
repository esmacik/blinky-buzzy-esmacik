# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: music_light_box.elf 

#additional rules for files
music_light_box.elf: ${COMMON_OBJECTS} assembly.o p2_interrupt_handler.o led.o switches.o main.o wdInterruptHandler.o music.o buzzer.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: music_light_box.elf
	mspdebug rf2500 "prog music_light_box.elf"

clean:
	rm -f *.o *.elf


