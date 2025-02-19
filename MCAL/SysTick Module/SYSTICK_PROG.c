/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V02                                                               */
/* Date      : 6 February 2025                                                  */
/*********************************************************************************/

/************************* LIBRARY INCLUDES *************************/
#include"BIT_MATH.h"
#include"STD_TYPES.h"

/************************* MCAL MODULES *****************************/
#include "SYSTICK_PRIVATE.h"
#include"SYSTICK_INTERFACE.h"
#include "SYSTICK_CONFIG.h"
#include "STD_TYPES.h"
#include "common_macros.h"
void (*MSTK_CallBack) (void);

void MSTK_VidInit( void ){

	//  Clock = AHB / 8 - Stop Systic
	if(CLK_SRC == MSTK_AHB)
	{
		MSTK->CTRL |= (1 << CLK_SOURCE_BIT);
	}
	else
	{
		MSTK->CTRL &= ~(1 << CLK_SOURCE_BIT);
	}
}


void MSTK_VidStart( u32 Copy_PreloadValue ){

	// AHB = EXT = 8MHZ & CLOCK OF MSTK = AHB / 8 = 8MHZ / 8 = 1MHZ = 1 Micro For Each Count
	//Load Reload Value
	MSTK->LOAD = Copy_PreloadValue - 1;
	//Clear Val Register
	MSTK->VAL  = 0 ;
	//Enable Systick
	SET_BIT( MSTK->CTRL , ENABLE_BIT);

}

void MSTK_VidINTStatus( u8 Copy_u8Status ){

	if(Copy_u8Status == MSTK_INT_EN)
		MSTK->CTRL |=  ( 1 << TICK_INT_BIT);
	else if(Copy_u8Status == MSTK_INT_DIS)
		MSTK->CTRL &= ~( 1 << TICK_INT_BIT);
}

u8 MSTK_u8ReadFlag( void )
{
	return (GET_BIT( MSTK->CTRL , COUNT_FLAG_BIT));
}

void MSTK_VidClearCurrentValue(void)
{
	MSTK->VAL = 0;
}


void SysTick_Handler(void)
{
	MSTK_CallBack();
}

void MSTK_VidSetCallBack( void (*ptr)(void) )
{
	MSTK_CallBack = ptr;
}
