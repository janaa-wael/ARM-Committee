/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 1 April 2025                                                      */
/*********************************************************************************/


#include"TYPES.h"
#include"MACROS.h"

#include"GPIO_INTERFACE.h"
#include"GPIO_REG.h"


void MGPIO_VidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode ){

	switch(Copy_u8Port){
	case GPIOA:

		if(Copy_u8Pin <= 7 ){//low

			MGPIOA->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			MGPIOA->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOA->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			MGPIOA->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 ){//low

			MGPIOB->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			MGPIOB->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOB->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			MGPIOB->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}

		break;
	case GPIOC:

		if(Copy_u8Pin <= 7 ){//low

			MGPIOC->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			MGPIOC->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOC->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			MGPIOC->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}

		break;
	default :break;
	}

}

void MGPIO_VidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value ){

	switch(Copy_u8Port){
	case GPIOA:

		if( u8Copy_u8Value == HIGH ){

			SET_BIT( MGPIOA->ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT( MGPIOA->ODR , Copy_u8Pin );
		}

		break;
	case GPIOB:

		if( u8Copy_u8Value == HIGH ){

			SET_BIT( MGPIOB->ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT( MGPIOB->ODR , Copy_u8Pin );
		}

		break;
	case GPIOC:

		if( u8Copy_u8Value == HIGH ){

			SET_BIT( MGPIOC->ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT( MGPIOC->ODR , Copy_u8Pin );
		}

		break;

	}

}

u8   MGPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port){
	case GPIOA:

		LOC_u8Result = GET_BIT( MGPIOA->IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( MGPIOB->IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( MGPIOB->IDR , Copy_u8Pin );

		break;

	}

	return LOC_u8Result;

}

void MGPIO_VidSetPortDirection( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode ){

	switch( Copy_u8Port ){

	case GPIOA:

		if      ( Copy_u8Position == LOW  ) { MGPIOA->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == HIGH ) { MGPIOA->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case GPIOB:

		if      ( Copy_u8Position == LOW  ) { MGPIOB->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == HIGH ) { MGPIOB->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case GPIOC:

		if      ( Copy_u8Position == LOW  ) { MGPIOC->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == HIGH ) { MGPIOC->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;

	}

}

void MGPIO_VidSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value ){

	switch( Copy_u8Port ){

	case GPIOA:

		if      ( Copy_u8Position == LOW  ){ MGPIOA->ODR = (MGPIOA->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == HIGH ){ MGPIOA->ODR = (MGPIOA->ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	case GPIOB:

		if      ( Copy_u8Position == LOW  ){ MGPIOB->ODR = (MGPIOB->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == HIGH ){ MGPIOB->ODR = (MGPIOB->ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	case GPIOC:

		if      ( Copy_u8Position == LOW  ){ MGPIOC->ODR = (MGPIOC->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == HIGH ){ MGPIOC->ODR = (MGPIOC->ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;

	}

}

u16 MGPIO_u16GetPortValue( u8 Copy_u8Port , u8 Copy_u8Position ){

	u16 LOC_u16Result = 0;

	switch( Copy_u8Port ){

	case GPIOA:

		LOC_u16Result = MGPIOA->IDR;
		if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	case GPIOB:

		LOC_u16Result = MGPIOB->IDR;
		if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	case GPIOC:

		LOC_u16Result = MGPIOC->IDR;
		if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;

	}

	return LOC_u16Result ;

}
