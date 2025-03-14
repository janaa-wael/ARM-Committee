/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 13 February 2025                                                  */
/*********************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"

/* Function Prototypes */
void ADC_Init(void);
u16 ADC_GetValue(void);
void ADC_DeInit(void);
#endif /* ADC_INTERFACE_H_ */
