/*
 * App.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */
#include <util/delay.h>

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
z
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/Timer/Timer_Interface.h"
#include "../Include/MCAL/WDT/WDT_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"

#define F_CPU 8000000UL

u16 global_u16PeriodTicks;
u16 global_u16OnTicks;

void ICU_SW(void)
{
	static u8 local_u8Counter=0;
	local_u8Counter++;
	if(local_u8Counter == 1)
	{
		// First Rising Edge
		MTIMER1_voidSetTimerValue(0);
	}
	else if(local_u8Counter ==2)
	{
		// Second Rising Edge
		global_u16PeriodTicks=MTIMER1_u16ReadTimer1Value();
		MEXTI_voidConfig(EXTI0, FALLING_EDGE);
	}
	else if(local_u8Counter ==3)
	{
		// First Falling Edge
		global_u16OnTicks=MTIMER1_u16ReadTimer1Value();
		global_u16OnTicks -=global_u16PeriodTicks;
		MEXTI_voidDisbale(EXTI0);
		local_u8Counter=0;
	}
}


void Timer0_OVF()
{
	static u16 Counter =0;
	Counter++;
	if(Counter == 3907)
	{
		MTIMER0_voidSetPreloadValue(192);
		Counter =0;
		HLED_voidToggleLED(DIO_PORTC , PIN0);
		HLED_voidToggleLED(DIO_PORTC , PIN1);
		HLED_voidToggleLED(DIO_PORTC , PIN2);
	}
}

void Timer0_CTC()
{
	static u16 Counter =0;
	Counter++;
	if(Counter == 5000)
	{
		Counter =0;
		HLED_voidToggleLED(DIO_PORTC , PIN0);
		HLED_voidToggleLED(DIO_PORTC , PIN1);
		HLED_voidToggleLED(DIO_PORTC , PIN2);
	}
}
/* Normal Mode */
//int main(void)
//{


	// Timer 0 - > 8 	BIT , Prescaler -- > 8 , F_CPU --> 8 Mhz , 1 Sec
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(Timer0_OVF);
//	MTIMER0_voidInit();
//	MTIMER0_voidSetPreloadValue(192);
//	MGI_voidEnable();
//	while(1)
//	{
//
//	}
//}

	/* CTC Mode */
//int main(void)
//{
////	 Timer 0 - > 8 	BIT , Prescaler -- > 8 , F_CPU --> 8 Mhz , 1 Sec
//		MDIO_voidInit();
//		MTIMER0_voidSetCTCCallback(Timer0_CTC);
//		MTIMER0_voidInit();
//		MGI_voidEnable();
//		while(1)
//		{
//
//		}
//}



	/* Fast PWM Mode */

//int main(void)
//{
//	// Set PB3 as output (FAST-PWM pin)
//	MDIO_voidInit();
//	MDIO_voidSetPinDirection(DIO_PORTB , PIN3 , DIO_OUTPUT);
//	MTIMER0_voidInit();
//	while(1)
//	{
//		for(u16 i=0; i <255; i+=10)
//		{
//			MTIMER0_voidSetOCR0Value(i);
//			_delay_ms(100);
//		}
//	}
//}


		/*Timer 1 , Servo Motor*/
//int main(void)
//{
//	MDIO_voidSetPinDirection(DIO_PORTD ,PIN5 , DIO_OUTPUT);
//	MTIMER1_voidInit();
//	while(1)
//	{
//
//	}
//}


		// Timer1 , ICU SW , didn't work on Proteus
//int main(void)
//{
//	/* Timer0 --> Generate PWM on PB3  --> O/P low
//	 * EXTI 0 --> Read The PWM on PD2 --> I/P Floating
//	 * LCD Data PORT --> PORTC  --> O/P low
//	 * LCD Control Port --> PORTD 3,4,5  --> O/P low
//	 */
//
//	MDIO_voidInit();
//
//
////	MDIO_voidSetPinDirection(DIO_PORTB , PIN3 , DIO_OUTPUT);
////	MDIO_voidSetPintValue(DIO_PORTB , PIN3 , DIO_RESET);
////
////	MDIO_voidSetPinDirection(DIO_PORTD , PIN2 , DIO_INPUT);
////	MDIO_voidSetPintValue(DIO_PORTD , PIN2 , DIO_RESET);
//
////	MDIO_voidSetPortDirection(DIO_PORTC,OxFF);
////	MDIO_voidSetPortValue(DIO_PORTC,0x00);
////
////	MDIO_voidSetPortDirection(DIO_PORTD,0b000111000);
////	MDIO_voidSetPortDirection(DIO_PORTD,0x00);
//
//	MEXTI_voidSetCallBack(EXTI0, ICU_SW);
//	MEXTI_voidConfig(EXTI0 , RISING_EDGE);
//	MEXTI_voidEnable(EXTI0);
//	MGI_voidEnable();
//	MTIMER0_voidInit();
//	MTIMER1_voidICUSWInit();
//
//	while(1)
//	{
//		while((global_u16PeriodTicks == 0) || (global_u16OnTicks ==0))
//		HLCD_voidGoToPos(LCD_ROW1, LCD_COL1);
////		HLCD_voidSendString("---->");
//		HLCD_voidDisplayNumber(global_u16PeriodTicks);
//		HLCD_voidGoToPos(LCD_ROW2, LCD_COL1);
////		HLCD_voidSendString("--->");
//		HLCD_voidDisplayNumber(global_u16OnTicks);
//	}
//}



		/*Watchdog Timer*/

int main()
{
	MDIO_voidSetPinDirection(DIO_PORTA, PIN0 , DIO_OUTPUT);
	MDIO_voidSetPinValue(DIO_PORTA, PIN0 , DIO_RESET);
	_delay_ms(2000);
	HLED_voidTurnLEDOn(DIO_PORTA , PIN0);
	MWDT_voidEnable(WDT_2_1_s);

	while(1)
	{

	}

}











