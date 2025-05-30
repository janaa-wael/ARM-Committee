/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STD_TYPES.h"
#include "SYSTICK_INTERFACE.h"
#include "SYSTICK_CONFIG.h"

int main(void)
{
	/* Initialize thE RCC System Clock */
	RCC_voidInitSysClock();

	/*Enable RCC for GPIOC*/
	RCC_voidEnableClock(RCC_APB2 , 4);

	/* Initialize PIN13 in PORT C */
	MGPIO_VidSetPinDirection(GPIOC , PIN13 , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOC , PIN14 , OUTPUT_SPEED_10MHZ_PP);

	MGPIO_VidSetPinValue(GPIOC , PIN13 , LOW);
	MGPIO_VidSetPinValue(GPIOC , PIN14 , HIGH);

	/* Initializing SysTick Timer */
	MSTK_VidInit();
	/* Disabling Interrupts */
	MSTK_VidINTStatus(INTERRUPT_CONFIG);

	/**/
	MSTK_VidStart(8000000);
	while(1)
	{
		while(MSTK_u8ReadFlag() == LOW);
		//MSTK_VidClearCurrentValue();
		MGPIO_VidSetPinValue(GPIOC, PIN13, HIGH);

		while(MSTK_u8ReadFlag() == LOW);
		//MSTK_VidClearCurrentValue();
		MGPIO_VidSetPinValue(GPIOC, PIN13, LOW);
	}




	while(1);




}
