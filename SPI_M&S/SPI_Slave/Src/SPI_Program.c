/*
 * SPI_Program.c
 *
 *  Created on: Aug 31, 2024
 *      Author: Abdalrahman
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/SPI/SPI_Interface.h"
#include "../Include/MCAL/SPI/SPI_Private.h"
#include "../Include/MCAL/SPI/SPI_Cfg.h"

void MSPI_voidInit(void)
{
	// Data Order = MSB First
	CLR_BIT(SPCR , 5);
	// Choose CPOL and CPHA  => Falling / Raising , Setup , Sample
	SET_BIT(SPCR , 3);
	SET_BIT(SPCR , 2);
	#if(SPI_MODE == SPI_MASTER_MODE)
	{
		// Select Master Mode
		SET_BIT(SPCR,4);
		// Select Clk  = Fosc 24
		CLR_BIT(SPCR , 0);
		SET_BIT(SPCR , 1);
	}

	#elif(SPI_MODE == SPI_SLAVE_MODE)
	{
		// Select Slave Mode
		CLR_BIT(SPCR,4);
	}
#endif
	// Enable SPI
	SET_BIT(SPCR , 6);
}

u8 MSPI_u8TransReceive(u8 A_u8Data)
{
	// Set Data to be sent into data register
	SPDR = A_u8Data;

	// wait until data transmission end
	while(GET_BIT(SPSR,7) == 0);

	// return data received

	return SPDR;

}
