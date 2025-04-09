/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 1 April 2025                                                      */
/*********************************************************************************/


#ifndef MACROS_H_
#define MACROS_H_


#define SET_BIT(REG , BITNUM) REG |= 1<<BITNUM
#define CLR_BIT(REG , BITNUM) REG &= ~(1<<BITNUM)
#define TOG_BIT(REG , BITNUM) REG ^= 1<<BITNUM
#define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1 )



#endif /* MACROS_H_ */
