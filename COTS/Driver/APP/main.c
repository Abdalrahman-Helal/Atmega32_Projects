/*
 * main.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Abdalrahman
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>
//#include <avr/io.h>

#include "../MCAL/DIO/DIO_Int.h"
#include "../HAL/SSD/SSD_Int.h"
#include "../HAL/KEYPAD/KEYPAD_Int.h"



#define F_CPU 8000000UL

int main(void)
{


	SSD_t s1, s2;
	s1.SSD_ID = 1;
	s1.SSD_PORT=DIO_PORTA;

	s2.SSD_ID = 2;
	s2.SSD_PORT=DIO_PORTC;

	HSSD_vInit(s1);
	HSSD_vInit(s2);

	HSSD_vDisplayNum(s1 , 6);
	HSSD_vDisplayNum(s2 , 4);

	HSSD_vDisplayNum(s1, 0);
	KPD_Init();

	u8 L_u8PinVal=0;

	while(1)
	{
		L_u8PinVal = KPD_u8GetPressedkey();
		if(L_u8PinVal < 10)
		{
			HSSD_vDisplayNum(s2, L_u8PinVal);
		}
		else if ( (L_u8PinVal >= 10) && (L_u8PinVal <= 15))
		{
			switch (L_u8PinVal) {

			case 10:
				HSSD_vDisplayNum(s1 , 1);
				HSSD_vDisplayNum(s2 , 0);
				break;

			case 11:
				HSSD_vDisplayNum(s1 , 1);
				HSSD_vDisplayNum(s2 , 1);
				break;

			case 12:
				HSSD_vDisplayNum(s1 , 1);
				HSSD_vDisplayNum(s2 , 2);
				break;

			case 13:
				HSSD_vDisplayNum(s1 , 1);
				HSSD_vDisplayNum(s2 , 3);
				break;

			case 14:
				HSSD_vDisplayNum(s1 , 1);
				HSSD_vDisplayNum(s2 , 4);
				break;

			case 15:
				HSSD_vDisplayNum(s1 , 1);
				HSSD_vDisplayNum(s2 , 5);
				break;
			}
		}
	}





}
