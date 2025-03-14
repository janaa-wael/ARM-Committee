/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 12 March 2025                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SPI_INTERFACE.h"

void LED_ON()
{
    MGPIO_VidSetPinValue(GPIOA, PIN1, HIGH);
}
void LED_OFF()
{
    MGPIO_VidSetPinValue(GPIOA, PIN1, LOW);
}



int main(void) {
    // Initialize System Clock
    RCC_voidInitSysClock();

    // Enable Clock for GPIOA and SPI1
    RCC_voidEnableClock(RCC_APB2, 2);  // GPIOA
    RCC_voidEnableClock(RCC_APB2, 12); // SPI1

    // Configure SPI1 Pins (Slave Mode)
    MGPIO_VidSetPinDirection(GPIOA, PIN7, INPUT_PULLUP_PULLDOWN);  // MOSI (Master Out, Slave In)
    MGPIO_VidSetPinDirection(GPIOA, PIN5, INPUT_PULLUP_PULLDOWN);  // SCK (Clock)
    MGPIO_VidSetPinDirection(GPIOA, PIN4, INPUT_PULLUP_PULLDOWN);    // CS (Chip Select)
    MGPIO_VidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_AFPP); // MISO (Master In, Slave Out)

    // Configure LED Pin
    MGPIO_VidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_10MHZ_PP);

    // Initialize SPI in Slave Mode
    MSPI_VidInit();

    while (1) {
        // Wait until CS goes LOW (Slave is selected)
        while (MGPIO_u8GetPinValue(GPIOA, PIN4) == HIGH);

        // Receive data from SPI Master
        u16 receivedData = MSPI1_VidSendDataU16(0);

        // Check received data and control LED
        if (receivedData == 0xAABB) {
            LED_ON();
        } else if(receivedData == 0xBBAA){
            LED_OFF();
        }
    }

    return 0;
}
