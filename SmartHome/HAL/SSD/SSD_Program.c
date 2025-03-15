/*
 * SSD_Program.c
 *
 *  Created on: Mar 2, 2025
 *      Author: Abdalrahman
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../SSD/SSD_Interface.h"
#include "../SSD/SSD_Private.h"
#include "../SSD/SSD_Cfg.h"

#include <util/delay.h>




void HSSD_vInit(DIO_PORT_e A_PortID)
{
	if((A_PortID <= DIO_PORTD))
	{
		switch(A_PortID)
		{
		case DIO_PORTA:
			MDIO_vSetPortDir(A_PortID , 0xFF);
			MDIO_vSetPortVal(A_PortID , 0xFF);
			break;
		case DIO_PORTB:
			MDIO_vSetPortDir(A_PortID , 0xFF);
			MDIO_vSetPortVal(A_PortID , 0xFF);
			break;
		case DIO_PORTC:
			MDIO_vSetPortDir(A_PortID , 0xFF);
			MDIO_vSetPortVal(A_PortID , 0xFF);
			break;
		case DIO_PORTD:
			MDIO_vSetPortDir(A_PortID , 0xFF);
			MDIO_vSetPortVal(A_PortID , 0xFF);
			break;
		}
	}
}

void HSSD_vDisplayNumber(DIO_PORT_e A_PortID, u8 A_u8NumberValue)
{
	if(A_PortID <= DIO_PORTD)
	{
		switch(A_PortID)
		{
		case DIO_PORTA:
			MDIO_vSetPortVal(A_PortID , A_u8NumberValue);
			break;
		case DIO_PORTB:
			MDIO_vSetPortVal(A_PortID, A_u8NumberValue);
			break;
		case DIO_PORTC:
			MDIO_vSetPortVal(A_PortID, A_u8NumberValue);
			break;
		case DIO_PORTD:
			MDIO_vSetPortVal(A_PortID, A_u8NumberValue);
			break;
		}
	}
}
void HSSD_vDisplayNumberAscending(DIO_PORT_e A_PortID , u16 A_u16TimetoWait)
{
	u8 SSD_u8ArrOfNumbers [10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	if(A_PortID <= DIO_PORTD)
	{
		switch(A_PortID)
		{
		case DIO_PORTA:
			for(u8 i =0 ; i <= 9; i++)
			{
				HSSD_vDisplayNumber(DIO_PORTA, SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);

			}
			break;

		case DIO_PORTB:
			for(u8 i =0 ; i <= 9; i++)
			{
				HSSD_vDisplayNumber(DIO_PORTB, SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			};
			break;

		case DIO_PORTC:
			for(u8 i =0 ; i <= 9; i++)
			{
				HSSD_vDisplayNumber(DIO_PORTC, SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;

		case DIO_PORTD:
			for(u8 i =0 ; i <= 9; i++)
			{
				HSSD_vDisplayNumber(DIO_PORTD, SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;
		}
	}
}


void HSSD_vCountDown(DIO_PORT_e A_PortID ,s8 A_u8Time , u16 A_u16TimetoWait)
{
	u8 SSD_u8ArrOfNumbers [10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

	if(A_PortID <= DIO_PORTD)
	{
		switch(A_PortID)
		{
		case DIO_PORTA:
			for(s8 i=A_u8Time; i >= 0; i--)
			{
				HSSD_vDisplayNumber(DIO_PORTA, SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;

		case DIO_PORTB:
			for(s8 i=A_u8Time ; i >= 0; i--)
			{
				HSSD_vDisplayNumber(DIO_PORTB, SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;

		case DIO_PORTC:
			for(s8 i =A_u8Time  ; i >= 0; i--)
			{
				HSSD_vDisplayNumber(DIO_PORTC, SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;

		case DIO_PORTD:
			for(s8 i=A_u8Time ; i >= 0; i--)
			{
				HSSD_vDisplayNumber(DIO_PORTD, SSD_u8ArrOfNumbers[i]);
				_delay_ms(A_u16TimetoWait);
			}
			break;
		}
		MDIO_vSetPortVal(A_PortID , 0xFF);
	}
}



//------------------------------------

