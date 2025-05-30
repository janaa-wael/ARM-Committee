/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 12 March 2025                                                     */
/*********************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define MSP1_STATUS          MSPI_ENABLE

#define MSPI1_CLOCK_MODE     MSPI_MODE3

#define MSPI1_MASTER_SLAVE   MSPI_MASTER

#define MSPI1_PRESCALLER     MSPI_FPCLK_DIVIDED_BY_4

#define MSPI1_DATA_ORDER     MSPI_MSB_FIRST

#define MSPI1_SS_MANAGE      HW_SLAVE_MANAGEMENT

#define MSPI1_DATA_SIZE      MSPI_16BIT_DATA

#define MSPI1_INT_STATUS     MSPI_INT_DISABLE

#endif /* SPI_CONFIG_H_ */
