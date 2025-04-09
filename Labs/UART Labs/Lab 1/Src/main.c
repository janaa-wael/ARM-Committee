/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 1 April 2025                                                      */
/*********************************************************************************/


#include "TYPES.h"
#include "MACROS.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "USART_INTERFACE.h"



int main(void)
{

	u8 LOC_u8NewData = 0 ;
	u8 LOC_u8OldData = 0;

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock ( APB2_BUS , GPIOA_RCC ) ;
	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC) ;

	MGPIO_VidSetPinDirection      ( GPIOA , PIN9  , OUTPUT_SPEED_2MHZ_AFPP) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN10 , INPUT_FLOATING) ;

	MGPIO_VidSetPortDirection     ( GPIOA , LOW  , OUTPUT_SPEED_2MHZ_PP) ;

	MUSART_VidInit();

	while(1){

		LOC_u8NewData = MUSART1_u8RecCharSynch();

		if( LOC_u8NewData > '0' && LOC_u8NewData < '9' )
		{
			LOC_u8NewData -= 48 ;
			LOC_u8OldData |= 1 << ( LOC_u8NewData - 1 ) ;
			MGPIO_VidSetPortValue( GPIOA , LOW , LOC_u8OldData );
		}
		if( LOC_u8NewData == 'c' )
		{
			MGPIO_VidSetPortValue( GPIOA , LOW , LOW );
			LOC_u8OldData = 0;

		}

	}

	return 0;
}

