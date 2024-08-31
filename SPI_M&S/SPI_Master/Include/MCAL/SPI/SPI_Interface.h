/*
 * SPI_Interface.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_SPI_SPI_INTERFACE_H_
#define INCLUDE_MCAL_SPI_SPI_INTERFACE_H_


void MSPI_voidInit(void);
u8 MSPI_u8TransReceive(u8 A_u8Data);

#define SPI_MASTER_MODE 0
 #define SPI_SLAVE_MODE  1


#endif /* INCLUDE_MCAL_SPI_SPI_INTERFACE_H_ */
