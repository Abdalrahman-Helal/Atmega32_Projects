#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

#define BIT_SET(REG,POS)	REG |= (1<<POS) 
#define BIT_CLR(REG,POS) 	REG &= ~(1<<POS)
#define BIT_FLIP(REG,POS)   REG ^= (1<<POS)

void timerInit(void);

int main(void)
{
    timerInit();
    DDRB =0x11;
    PORTB=0x00;
    while(1)
    {

    }
    
}

void timerInit(void)
{
    TCCR1A=0x00;
    TCNT1=65047;

     // Set Prescaller to 1024
    TCCR1B |=(1<<CS12);
    TCCR1B |=(1<<CS10);
    
    TIMSK |= (1<<TOIE1); // Overflow Interrupt Enable 


    sei(); // Set Global Interrupt Enable
}

ISR(TIMER1_OVF_vect){
    TCNT1=65047;
	BIT_FLIP(PORTB,0);
}




