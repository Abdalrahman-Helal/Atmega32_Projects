/*
 * RTOS_Interface.h
 *
 *  Created on: Sep 4, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_
#define INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_

void SRTOS_voidInit(void);
void SRTOS_voidInitArrayFunctions(void);
void SRTOS_voidCreateTask (u8 A_u8priority, u16 A_u16Periodicity, u16 A_u16FirstDelay, void (*pf)(void));
void SRTOS_voidScheduler (void);

#endif /* INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_ */
