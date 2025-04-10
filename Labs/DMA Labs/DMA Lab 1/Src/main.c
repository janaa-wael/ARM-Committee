/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 12 March 2025                                                     */
/*********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_INTERFACE.h"
#include "DIO_interface.h"
#include "NVIC_INTERFACE.h"
#include "DMA_INTERFACE.h"

u32 SOURCE[1000]={0};
u32 DESTINATION[1000];

u32 SOURCE2[1000]={0};
u32 DESTINATION2[1000];

u16 i = 0;

void DMA_CallBack(void){

	MDMA_VidClearFlag(CHANNEL1, DMA_TCIF);
	for(int i = 0 ; i < 8000 ; i++);
	MGPIO_VidTogglePinValue(GPIOA, PIN1);
}

int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB , 0);
	RCC_voidEnableClock(RCC_APB2 , 2);

	DMA_Configurations DMA_Config = {CHANNEL1, MEM_TO_MEM, DMA_ENABLE_CIRCULAR, PERIPHERAL_INCREMENT_ENABLE,
			MEM_INCREMENT_ENABLE , WORD , WORD , DMA_VERY_HIGH };
	MGPIO_VidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_10MHZ_PP);

	MNVIC_VidSetPriority(DMA_ID, 1, NO_SUB_PRIORITY, GROUP3);
	MNVIC_VidEnablePeripheral(DMA_ID);

	MDMA_VidSetCallBackChannel1(DMA_CallBack);

	MDMA_VidSetConfiguration (&DMA_Config);
	//MGPIO_VidSetPinValue(GPIOA, PIN2, HIGH);
	MDMA_VidSetAddress(CHANNEL1, SOURCE, DESTINATION, 1000);
	MDMA_VidInerruptEnable(CHANNEL1, DMA_TCIE);
	MDMA_VidDMAEnable(CHANNEL1);

	//For Processor

	for( i = 0 ; i < 1000 ;i++ )
	{
		DESTINATION2[i]=SOURCE2[i];
	}
	MGPIO_VidSetPinValue(GPIOA, PIN2, HIGH);


	return 0;
}
