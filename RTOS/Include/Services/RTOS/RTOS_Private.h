/*
 * RTOS_Private.h
 *
 *  Created on: Sep 4, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_
#define INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_

typedef struct
{
	u16 FirstDelay;
	u16 Periodicity;
	void (*pf)(void);

}RTOS_TCB;


#endif /* INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_ */
