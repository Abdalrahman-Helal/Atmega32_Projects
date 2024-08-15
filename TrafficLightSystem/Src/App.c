/*
 * App.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include <util/delay.h>


#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/SSD/SSD_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"



int main(void)
{
	// Configure PORTA as Output for SSD1
	MDIO_voidSetPortDirection(DIO_PORTA,0xFF);

	// Configure PORTB as Output for SSD2
	MDIO_voidSetPortDirection(DIO_PORTB,0xFF);

//	//Configure PORTC as Output for LEDs(Green,Yellow ,Red)
	MDIO_voidSetPortDirection(DIO_PORTC,0x07);

	u8 SSD_Arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	u8 LED_Arr[3]={GREEN,YELLOW ,RED};
	u8 i=3;
	u8 j=0;
	while(1)
	{
		for(j=0; j<3;j++)
		{
			HLED_voidTurnLEDOn(DIO_PORTC,LED_Arr[j]);

			if(j==0 || j==2)
			{
				HSSD_voidDisplayNumber(DIO_PORTB,SSD_Arr[1]); // 1
				HSSD_voidDisplayNumber(DIO_PORTA,SSD_Arr[0]); //0
				_delay_ms(1000);

				HSSD_voidDisplayNumber(DIO_PORTB,SSD_Arr[0]); // 0
				HSSD_voidDisplayNumberDescending(DIO_PORTA,1000);
			}

			else
			{
				for(i=3; i>0;i--)
				{
					MDIO_voidSetPortValue(DIO_PORTA,(SSD_Arr[i]));
					_delay_ms(1000);
				}
			}
			HLED_voidTurnLEDOff(DIO_PORTC,LED_Arr[j]);

		}
	}
}


/****************************/







