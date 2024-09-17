/*
 * SSD_Prg.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Int.h"
#include "../../HAL/SSD/SSD_Int.h"


static const u8 CGS_u8SSDNumebrs[10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};



void HSSD_vInit(SSD_t SSD)
{
	MDIO_vSetPortDir(SSD.SSD_PORT , 0xFF);
}


void HSSD_vDisplayNum(SSD_t SSD , u8 A_u8Num)
{
	// Input Validation
	if(A_u8Num < 10)
	{

	#if SSD_TYPE == COM_ANODE
		MDIO_vSetPortVal(SSD.SSD_PORT ,CGS_u8SSDNumebrs[A_u8Num]);


	#elif SSD_TYPE == COM_CATHODE
		MDIO_vSetPortVal(SSD.SSD_PORT  ,~CGS_u8SSDNumebrs[A_u8Num]);

	#endif
	}
}

void HSSD_vTurnOff(SSD_t SSD)
{

	#if SSD_TYPE == COM_ANODE
	MDIO_vSetPortVal(SSD.SSD_PORT , 0xFF);

	#elif SSD_TYPE == COM_CATHODE
	MDIO_vSetPortVal(SSD.SSD_PORT , 0x00);

	#endif

}

