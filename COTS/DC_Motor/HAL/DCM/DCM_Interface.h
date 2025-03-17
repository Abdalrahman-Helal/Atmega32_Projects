/*
 * DCM_Interface.h
 *
 *  Created on: Mar 17, 2025
 *      Author: Abdalrahman
 */

#ifndef DCM_DCM_INTERFACE_H_
#define DCM_DCM_INTERFACE_H_

#define NOSTRUCT 	1
#define STRUCT 		2

#define METHOD 		STRUCT

typedef struct
{
	u8 Port;
	u8 Pin1;
	u8 Pin2;

}DCM_t;


#if METHOD == NOSTRUCT
void HDCM_vInit(void);
void HDCM_vRotateCW(void);
void HDCM_vRotateCCW(void);
void HDCM_vStop(void);
#endif

#if METHOD == STRUCT
DCM_t HDCM_xInit(u8 A_u8Port, u8 A_u8Pin1, u8 A_u8Pin2);
void HDCM_vRotateCW(DCM_t* xMotor);
void HDCM_vRotateCCW(DCM_t* xMotor);
void HDCM_vStop(DCM_t* xMotor);
#endif


#endif /* DCM_DCM_INTERFACE_H_ */
