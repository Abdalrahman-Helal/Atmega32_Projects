/*
 * App.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include <util/delay.h>



#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/LCD/LCD_interface.h"
#include "../Include/HAL/Keypad/Keypad_Interface.h"
#include "../Include/HAL/SSD/SSD_Interface.h"



u8 g_u8ArrofKeyValues[3][3]={
								{'7','8','9'},
								{'4','5','6'},
								{'1','2','3'}

							  };

u8 S_arr[3][3]={

				{SEVEN,EIGHT,NINE},
				{FOUR,FIVE,SIX},
				{ONE,TWO,THREE}

				};

#define F_CPU 8000000UL

int main(void)
{


	MDIO_voidSetPortDirection(DIO_PORTA, 0x0F);
	MDIO_voidSetPortValue(DIO_PORTA, 0xFF);
	MDIO_voidSetPortDirection(DIO_PORTB, 0xFF);
	MDIO_voidSetPortValue(DIO_PORTB , 0xFF);


	u8 local_u8KeyPadValue;


	while(1)
	{
		local_u8KeyPadValue = HKEYPAD_u8GetPressedKey();
		if(local_u8KeyPadValue == '0')
		{
			HSSD_voidDisplayNumber(DIO_PORTB , ZERO);
		}
		else
		{
			for(u8 i =0; i < 3 ; i++ )
			{
				for (u8 j=0; j < 3; j++ )
				{
					if(local_u8KeyPadValue == g_u8ArrofKeyValues[i][j])
					{
						HSSD_voidDisplayNumber(DIO_PORTB ,S_arr[i][j]);
					}
				}
			}
		}

	}
}

