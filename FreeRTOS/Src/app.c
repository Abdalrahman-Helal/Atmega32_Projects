/*
 * app.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Abdalrahman
 */


#include <util/delay.h>
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include"../OS/FreeRTOS.h"
#include"../OS/task.h"
#include"../OS/semphr.h"

xSemaphoreHandle LCD_Semaphore;

void LED_Toggle1 (void * pv);
void LED_Toggle2 (void * pv);
void LED_Toggle3 (void * pv);

void LCDTask1 (void *pv);
void LCDTask2 (void *pv);

int main()
{
	MDIO_voidInit();
	MGI_voidEnable();
	HLCD_voidInit();

	// Create 3 Tasks for Toggle LEDs
	xTaskCreate(LED_Toggle1,NULL,200,NULL,4,NULL);
	xTaskCreate(LED_Toggle2,NULL,200,NULL,3,NULL);
	xTaskCreate(LED_Toggle3,NULL,200,NULL,2,NULL);

	//Create 2 Tasks for LCD
	xTaskCreate(LCDTask1,NULL,200,NULL,2,NULL);
	xTaskCreate(LCDTask2,NULL,200,NULL,2,NULL);

	// Create Binary Semaphore
	vSemaphoreCreateBinary(LCD_Semaphore);

	// Start FreeRTOS Scheduler
	vTaskStartScheduler();
}

void LCDTask1 (void *pv)
{
	while(1)
	{
		if(xSemaphoreTake(LCD_Semaphore,portMAX_DELAY) == pdTRUE)
		{
			HLCD_voidDisplayString(" T1 ");
			xSemaphoreGive(LCD_Semaphore);
		}
		vTaskDelay(1000);
	}
}

void LCDTask2 (void *pv)
{
	while(1)
	{
		if(xSemaphoreTake(LCD_Semaphore,portMAX_DELAY) == pdTRUE)
		{
			HLCD_voidDisplayString(" T2 ");
			xSemaphoreGive(LCD_Semaphore);
		}
		vTaskDelay(1000);
	}
}

void LED_Toggle1 (void * pv)
{

	while(1)
	{
		HLED_voidToggleLED(DIO_PORTA, PIN0);
		vTaskDelay(1000);
	}
}

void LED_Toggle2 (void * pv)
{

	while(1)
	{
		HLED_voidToggleLED(DIO_PORTA, PIN1);
		vTaskDelay(2000);
	}
}

void LED_Toggle3 (void * pv)
{

	while(1)
	{
		HLED_voidToggleLED(DIO_PORTA, PIN2);
		vTaskDelay(5000);
	}
}



