/*
 * App.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Abdalrahman
 */
#include <avr/io.h>
#include <util/delay.h>
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#define ZERO 	0b01000000
#define ONE 	0b01111001
#define TWO 	0b00100100
#define THREE 	0b00110000
#define FOUR 	0b00011001
#define FIVE 	0b00010010
#define SIX 	0b00000010
#define SEVEN 	0b01111000
#define EIGHT 	0b00000000
#define NINE 	0b00010000



#define F_CPU 8000000UL

int main(void)
{


	u8 SSD_u8ArrOfNumbers [10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	u8 i;
	u8 j;
	DDRD=0xFF;
	DDRB=0xFF;

	while(1)
	{
		for(j=0; j<10;j++)
		{
			PORTD=SSD_u8ArrOfNumbers[j];

			for(i=0; i<10;i++)
			{
				PORTB=SSD_u8ArrOfNumbers[i];
				_delay_ms(1000);
			}
		}
	}




}


