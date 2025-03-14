/*
 * main.c
 *
 *  Created on: Mar 10, 2025
 *      Author: Abdalrahman
 */

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/SSD/SSD_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KEYPAD_Interface.h"

#include "../mainConfg/Cfg.h"

#define F_CPU 12000000UL


void SmartHomeLoginPassword()
{
	u16 L_Password;
	u8 PasswordStatus = UnValid;

	HLCD_vDisplayString("Enter password: ");
	HLCD_vGoToPos(LCD_ROW2 , LCD_COL1);



	for(u8 i=0; i <3; i++)
	{
		L_Password= HKEYPAD_u16MultiDigitInput();

		if(L_Password == Password)
		{
			PasswordStatus = Valid;
		}
		if(PasswordStatus == Valid)
		{
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Welcome Helal");
			_delay_ms(200);
			HLCD_vClearDisplay();
			break;
		}
		else
		{
			if(i < 2)
			{
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Try Again");
				_delay_ms(200);
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Enter password: ");
			}
			else
			{
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Try Later");
				_delay_ms(500);
				HLCD_vClearDisplay();
				// sholud return to any point here
			}
		}
	} // end of FOR (password) loop
}


void SmartHomeMenu()
{
	// Show Menu
	u8 key = NO_KEY_PRESSED;
	HLCD_vClearDisplay();
	HLCD_vDisplayString("1- Light");
	HLCD_vGoToPos(LCD_ROW2 , LCD_COL1);
	HLCD_vDisplayString("2- Timer");

	// waiting to enter an input
	while(key == NO_KEY_PRESSED)
	{
		key = HKEYPAD_u8GetPressedKey();
	}

	switch(key)
	{

	// LED
	case '1':
	{ // to remove error of Declaration after label
		u8 LED_Action = NO_KEY_PRESSED;
		HLCD_vClearDisplay();
		HLCD_vDisplayString("1-On 2-OFF");
		HLCD_vGoToPos(LCD_ROW2, LCD_COL1);
		HLCD_vDisplayString("3- Back");
		while(LED_Action == NO_KEY_PRESSED)
		{
			LED_Action = HKEYPAD_u8GetPressedKey();
		}


		switch (LED_Action)
		{
		case '1':
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Lights ON");
			MDIO_vSetPortDir(DIO_PORTC, 0x08);
			MDIO_vSetPortVal(DIO_PORTC , 0x08);

			break;
		case '2':
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Lights OFF");
			MDIO_vSetPortDir(DIO_PORTB , 0x01);
			MDIO_vSetPortVal(DIO_PORTB , 0x00);
			break;

		case '3':
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Back");
			HLCD_vClearDisplay();
			_delay_ms(200);
			SmartHomeMenu();
			break;

		default:
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Wrong Input");
			break;
		}
		break; // Case 1 Break
	}


	// Timer
	case '2':
	{
		u8 Timer_Action = NO_KEY_PRESSED;

		HLCD_vClearDisplay();
		HLCD_vDisplayLongString("1- Set Timer");
		HLCD_vGoToPos(LCD_ROW2, LCD_COL1);
		HLCD_vDisplayString("2- Back");
		while(Timer_Action == NO_KEY_PRESSED)
		{
			Timer_Action = HKEYPAD_u8GetPressedKey();
		}

		switch(Timer_Action)
		{

		case '1':
			HLCD_vClearDisplay();
			HLCD_vDisplayLongString("Set Timer in Sec");
			u8 Time = HKEYPAD_u16MultiDigitInput();
			HLCD_vGoToPos(LCD_ROW2 , LCD_COL1);
			HLCD_vDisplayNumber(Time);
			HSSD_vCountDown(SSD_PORT , Time , 500);
			HLCD_vDisplayString("Time Finished");
			break;

		case '2':
			HLCD_vClearDisplay();
			_delay_ms(200);
			HLCD_vDisplayString("Back");
			HLCD_vClearDisplay();
			SmartHomeMenu();
			break;

		default:
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Wrong Input");
			_delay_ms(500);
			HLCD_vClearDisplay();
			break;
		}
		break;
	}// cause of declaration
	}
}

void main(void)
{
	// Init of KEYPAD , LCD , 7-Segment
	HKEYPAD_vInit();
	HLCD_vInit();
	HSSD_vInit(SSD_PORT);



	while(1)
	{
		HLCD_vDisplayString("Hello Helal");
		_delay_ms(200);
		HLCD_vClearDisplay();

		SmartHomeLoginPassword(); // enter password and check it
		SmartHomeMenu();



	} // end of while loop
}


