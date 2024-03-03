#define F_CPU 8000000UL
#define __AVR_ATmega32__

#include <util/delay.h>  
#include <avr/io.h>

#define SET_BIT(REG,POS)        REG|= (1<<POS)
#define CLR_BIT(REG,POS)        REG&= ~(1<<POS)

int main(void)
{
    DDRA=0xFF;
    while(1)
    {
        SET_BIT(PORTA,0); // turn on LED 1
        _delay_ms(1000);
        CLR_BIT(PORTA,0);

        SET_BIT(PORTA,1); // turn on LED 1
        _delay_ms(1000);
        CLR_BIT(PORTA,1);

        SET_BIT(PORTA,2); // turn on LED 1
        _delay_ms(1000);
        CLR_BIT(PORTA,2);

        SET_BIT(PORTA,3); // turn on LED 1
        _delay_ms(1000);
        CLR_BIT(PORTA,3);

    }
}