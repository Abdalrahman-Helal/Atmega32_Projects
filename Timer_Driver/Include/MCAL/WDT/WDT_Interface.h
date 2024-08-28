/*
 * WDT_Interface.h
 *
 *  Created on: Aug 29, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_WDT_WDT_INTERFACE_H_
#define INCLUDE_MCAL_WDT_WDT_INTERFACE_H_

typedef enum{
	WDT_16_3_ms=0,
	WDT_32_5_ms,
	WDT_65_ms,
	WDT_0_13_s,
	WDT_0_25_s,
	WDT_0_52_s,
	WDT_1_0_s,
	WDT_2_1_s
}WDT_TIME_e;


void MWDT_voidEnable(WDT_TIME_e A_TimeToReset);
void MWDT_voidDisable(void);
#endif /* INCLUDE_MCAL_WDT_WDT_INTERFACE_H_ */
