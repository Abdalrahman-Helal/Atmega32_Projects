/*
 * main.c
 *
 *  Created on: Mar 10, 2025
 *      Author: Abdalrahman
 */

#include <util/delay.h>

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/SSD/SSD_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KEYPAD/KEYPAD_Interface.h"
#include "HAL/DCM/DCM_Interface.h"
#include "HAL/Buzzer/Buzzer_Interface.h"

#include "mainConfg/Cfg.h"


#define LED_OFF 0
#define LED_ON 1

#define DOOR_CLOSE 0
#define DOOR_OPEN  1

u8 DoorStatus = DOOR_CLOSE;
u8 LED_Status = LED_OFF;

#define F_CPU 12000000UL


void SmartHomeWelcome(void)
{
	HLCD_vDisplayString("Hello Helal");
	_delay_ms(200);
	HLCD_vClearDisplay();
}

void SmartHomeLoginPassword()
{
	u16 L_Password;

	HLCD_vDisplayString("Enter password: ");
	HLCD_vGoToPos(LCD_ROW2 , LCD_COL1);



	for(u8 i=0; i <3; i++)
	{
		L_Password= HKEYPAD_u16MultiDigitInput();
		HLCD_vClearDisplay();
		if(PASSWORD == L_Password )
		{

			HLCD_vDisplayString("Welcome Helal");
			_delay_ms(200);
			HLCD_vClearDisplay();
			break;
		}
		else
		{
			if(i < 2)
			{
				HLCD_vDisplayString("Try Again");
				_delay_ms(200);
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Enter password: ");
			}
			else
			{
				HLCD_vDisplayString("Try Later");
				_delay_ms(500);
				HLCD_vClearDisplay();
				// sholud return to any point here
			}
		}
	} // end of FOR (password) loop
}


// ----------------------------------------

void SmartHomeMenu()
{
	// Show Menu
	u8 key = NO_KEY_PRESSED;
	HLCD_vClearDisplay();
	HLCD_vDisplayString("1- Light 3- Door");
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
			if(LED_Status == LED_OFF)
			{
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Lights ON");
				MDIO_vSetPinDir(LED_PORT,LED_PIN,DIO_OUTPUT);
				MDIO_vSetPinVal(LED_PORT,LED_PIN,DIO_HIGH);
				_delay_ms(500);
				LED_Status = LED_ON;
			}
			else
			{
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Already On");
				_delay_ms(1000);
				HLCD_vClearDisplay();
			}
			break;
		case '2':
			if(LED_Status ==  LED_ON)
			{
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Lights OFF");
				MDIO_vSetPinDir(LED_PORT,LED_PIN,DIO_OUTPUT);
				MDIO_vSetPinVal(LED_PORT,LED_PIN,DIO_LOW);
				_delay_ms(500);
				LED_Status = LED_OFF;
			}
			else
			{
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Already Off");
				_delay_ms(1000);
				HLCD_vClearDisplay();
			}

			break;

		case '3':
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Back");
			_delay_ms(200);
			HLCD_vClearDisplay();
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
			HSSD_vCountDown(SSD_PORT , Time , SSD_DELAY);
			HLCD_vClearDisplay();
			HBUZZER_vTurnOn();
			HLCD_vDisplayString("Time Finished");
			_delay_ms(500);
			HBUZZER_vTurnOff();
			HLCD_vClearDisplay();
			break;

		case '2':
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Back");
			_delay_ms(200);
			HLCD_vClearDisplay();
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

	// Door
	case '3':
	{
		u8 Door_Action = NO_KEY_PRESSED;
		HLCD_vClearDisplay();
		HLCD_vDisplayString("1-Open 2-Close");
		HLCD_vGoToPos(LCD_ROW2, LCD_COL1);
		HLCD_vDisplayString("3- Back");
		while(Door_Action == NO_KEY_PRESSED)
		{
			Door_Action = HKEYPAD_u8GetPressedKey();
		}

		switch (Door_Action)
		{

		case '1':
			if(DoorStatus == DOOR_CLOSE)
			{
				HLCD_vClearDisplay();
				HDCM_vRotateCW();
				HLCD_vDisplayString("Door Opening");
				_delay_ms(2000);
				HDCM_vStop();
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Opened");
				_delay_ms(1000);
				DoorStatus = DOOR_OPEN;
			}
			else
			{
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Already Opened");
				_delay_ms(1000);
				HLCD_vClearDisplay();
			}
			break;

		case '2':
			if(DoorStatus == DOOR_OPEN)
			{
				HLCD_vClearDisplay();
				HDCM_vRotateCCW();
				HLCD_vDisplayString("Door Closing");
				_delay_ms(2000);
				HDCM_vStop();
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Closed");
				_delay_ms(1000);
				DoorStatus = DOOR_CLOSE;
			}
			else
			{
				HLCD_vClearDisplay();
				HLCD_vDisplayString("Already Closed");
				_delay_ms(1000);
				HLCD_vClearDisplay();
			}
			break;


		case '3':
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Back");
			_delay_ms(200);
			HLCD_vClearDisplay();
			break;

		default:
			HLCD_vClearDisplay();
			HLCD_vDisplayString("Wrong Input");
			break;
		}
		break; // Case 1 Break
	}

}
}



void main(void)
{
	// Init of KEYPAD , LCD , 7-Segment , DC Motor
	HKEYPAD_vInit();
	HLCD_vInit();
	HSSD_vInit(SSD_PORT);
	HDCM_vInit();
	HBUZZER_vInit();

	SmartHomeWelcome();
	SmartHomeLoginPassword(); // enter password and check it

	while(1)
	{
		SmartHomeMenu();

	} // end of while loop
}


