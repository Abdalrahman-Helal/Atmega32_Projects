MAKE := make
clean:
	rm -fd Blink.elf
	rm -fd Blink.elf
	
all: Blink.elf

blink.elf: Blink.elf
	avr-gcc -mmcu=atmega32 -Os -o Blink.elf Blink.o
	
Blink.o: Blink.c
	avr-gcc -mmcu=atmega32 -Os -c Blink.c -o Blink.o