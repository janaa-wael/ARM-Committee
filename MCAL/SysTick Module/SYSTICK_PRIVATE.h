/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                                        */
/* Version   : V01                                                               */
/* Date      : 6 February 2025                                                    */
/*********************************************************************************/

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

typedef struct{

	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL  ;
	volatile u32 CALIB;

}SYSTICK;

/* SysTick Control and Status Register Bits */
#define ENABLE_BIT			0
#define TICK_INT_BIT		1
#define CLK_SOURCE_BIT		2
#define COUNT_FLAG_BIT		16



#define MSTK ((volatile SYSTICK*)0xE000E010)

#endif /* SYSTICK_REG_H_ */
