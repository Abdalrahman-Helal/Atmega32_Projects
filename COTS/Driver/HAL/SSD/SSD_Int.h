/*
 * SSD_Int.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Abdalrahman
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_


#define ZERO 	0b01000000
#define ONE 	0b01111001
#define TWO 	0b00100100
#define THREE 	0b00110000
#define FOUR 	0b00011001
#define FIVE 	0b00010010
#define SIX 	0b00000010
#define SEVEN 	0b01111000
#define EIGHT 	0b00000000
#define NINE 	0b00010000

#define COM_CATHODE   1
#define COM_ANODE     0

//#define SSD_PORT DIO_PORTA

#define SSD_TYPE 	 COM_ANODE

typedef struct
{
	 u8 SSD_PORT;
	 u8 SSD_ID

}SSD_t;


void SSD_vInit(SSD_t SSD);
void SSD_vDisplayNum(SSD_t SSD , u8 A_u8Num);
void SSD_vTurnOff(SSD_t SSD);

#endif /* HAL_SSD_SSD_INT_H_ */
