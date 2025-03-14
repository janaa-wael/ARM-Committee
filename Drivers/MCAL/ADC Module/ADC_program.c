/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 13 February 2025                                                  */
/*********************************************************************************/

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "stm32f103xx.h"
#include "STD_TYPES.h"

void ADC_Init(void)
{
    RCC->APB2ENR |= (1 << 9);                    // ADC1 clock
    RCC->CFGR    |= (ADC_PRESCALER << 14);       //Bit 14,15  01 for /4

    /* ADC Configuration */
    ADC1->CR2   |= (1 << 0);                                      // Enable ADC
    ADC1->CR2   |= (1<<23);                                       //Enable Temp sensor
    ADC1->SMPR1 |= (ADC_SAMPLE_TIME << ((ADC_CHANNEL- 10 )* 3));  // Sample time
    ADC1->SQR1  |= ((Number_Of_Conversion - 1) << 20);      	  // 1 conversion
    ADC1->SQR3  |= (ADC_CHANNEL << 0);                            // Channel selection
}

u16 ADC_GetValue()
{
	ADC1->CR2   |= (1 << 22); // Start ADC conversion
    while (!(ADC1->SR & (1 << 1))); // Wait for conversion
    u16 readingValue = ADC1->DR;    //read data
    ADC1->SR &= ~(1 << 1);          //clear flag of EOC

    return readingValue;
}
void ADC_DeInit(void)
{
    // Disable ADC
    ADC1->CR2 &= ~(1 << 0);  // Disable ADC (ADON)

    // Disable ADC1 clock
    RCC->APB2ENR &= ~(1 << 9);  // Disable ADC1 clock
}
