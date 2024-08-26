/*
 * SSD_Program.c

 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"



#include "../Include/HAL/SSD/SSD_Interface.h"

void HSSD_voidDisplayNumber(DIO_PORT_e A_portID, u8 A_u8NumberValue)
{
	// Check Input Validation
	if(A_portID <= DIO_PORTD)
	{
		switch(A_portID)
		{
		case DIO_PORTA:
//			MDIO_voidSetPortDirection(A_portID,~(A_u8NumberValue));
			MDIO_voidSetPortValue(A_portID,(A_u8NumberValue));
			break;
		case DIO_PORTB:
//			MDIO_voidSetPortDirection(A_portID,~(A_u8NumberValue));
			MDIO_voidSetPortValue(A_portID,(A_u8NumberValue));
			break;
		case DIO_PORTC:
//			MDIO_voidSetPortDirection(A_portID,~(A_u8NumberValue));
			MDIO_voidSetPortValue(A_portID,(A_u8NumberValue));
			break;
		case DIO_PORTD:
//			MDIO_voidSetPortDirection(A_portID,~(A_u8NumberValue));
			MDIO_voidSetPortValue(A_portID,(A_u8NumberValue));
			break;
		}
	}
	else
	{
		// Do Nothing
	}
}

void HSSD_voidDisplayNumberAscending(DIO_PORT_e A_portID , u16 A_u16TimeToWait)
{
	u8 SSD_arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	for(u8 i=0; i<=9;i++)
	{
//		MDIO_voidSetPortDirection(A_portID,~(SSD_arr[i]));
		MDIO_voidSetPortValue(A_portID,(SSD_arr[i]));
		_delay_ms(A_u16TimeToWait);
	}
}

void HSSD_voidDisplayNumberDescending (DIO_PORT_e A_portID , u16 A_u16TimeToWait)
{
	u8 SSD_arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	for(u8 i=9; i>=0;i--)
	{
//		MDIO_voidSetPortDirection(A_portID,~(SSD_arr[i]));
		MDIO_voidSetPortValue(A_portID,(SSD_arr[i]));
		_delay_ms(A_u16TimeToWait);
	}
}



