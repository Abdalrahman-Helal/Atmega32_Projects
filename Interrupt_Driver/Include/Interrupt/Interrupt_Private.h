/*
 * Interrupt_Private.h
 *
 *  Created on: Aug 17, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_INTERRUPT_INTERRUPT_PRIVATE_H_
#define INCLUDE_INTERRUPT_INTERRUPT_PRIVATE_H_

#define INT_GICR   (*((volatile u8 * )0x5B)
#define INT_GIFR   (*((volatile u8 * )0x5A)
#define INT_MCUCR  (*((volatile u8 * )0x55)
#define INT_MCUCSR (*((volatile u8 * )0x54)



#endif /* INCLUDE_INTERRUPT_INTERRUPT_PRIVATE_H_ */
