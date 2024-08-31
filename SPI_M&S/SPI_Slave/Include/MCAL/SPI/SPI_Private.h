/*
 * SPI_Private.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_SPI_SPI_PRIVATE_H_
#define INCLUDE_MCAL_SPI_SPI_PRIVATE_H_

#define SPDR (*(volatile u8 *)0x2F)
#define SPSR (*(volatile u8 *)0x2E)
#define SPCR (*(volatile u8 *)0x2D)

#endif /* INCLUDE_MCAL_SPI_SPI_PRIVATE_H_ */
