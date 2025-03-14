/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 12 March 2025                                                     */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SPI_INTERFACE.h"

int main(void) {
    // Initialize System Clock
    RCC_voidInitSysClock();

    // Enable Clock for GPIOA and SPI1
    RCC_voidEnableClock(RCC_APB2, 2);  // GPIOA
    RCC_voidEnableClock(RCC_APB2, 12); // SPI1

    // Configure SPI1 Pins
    MGPIO_VidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_10MHZ_AFPP); // MOSI
    MGPIO_VidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_AFPP); // SCK
    MGPIO_VidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);   // CS (Chip Select)
    MGPIO_VidSetPinDirection(GPIOA, PIN6, INPUT_PULLUP_PULLDOWN);          // MISO (Fixed!)

    // Initialize SPI
    MSPI_VidInit();

    while (1) {
        // Activate SPI Communication (Pull CS Low)
        MGPIO_VidSetPinValue(GPIOA, PIN4, LOW);

        for (int i = 0; i < 800000; i++); // Delay

        // Send Data
        MSPI1_VidSendDataU16(0xAABB);

        MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);

        for (int i = 0; i < 800000; i++); // Delay

        MGPIO_VidSetPinValue(GPIOA, PIN4, LOW);

        MSPI1_VidSendDataU16(0xBBAA);

        // Deactivate SPI Communication (Pull CS High)
        MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
    }

    return 0;
}
