/*****************************************************************************/
/* File name: MSPI_interface.h                                               */
/* Author: MOHAMMED MANSOUR												     */
/* Description: This file contains the interfacing information of SPI Module */
/*****************************************************************************/

/*Header file guard*/
#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/*SPI modes*/
#define MSPI_MASTER_MODE (1)
#define MSPI_SLAVE_MODE  (0)

/*Data out order*/
#define MSPI_LSB_FIRST   (1)
#define MSPI_MSB_FIRST   (0)

/*SPI clock modes*/
#define MSPI_SAMPLE_R_SETUP_F (0)
#define MSPI_SETUP_R_SAMPLE_F (1)
#define MSPI_SAMPLE_F_SETUP_R (2)
#define MSPI_SETUP_F_SAMPLE_R (3)

/*SPI speed*/
#define MSPI_CLK_BY_2         (0)
#define MSPI_CLK_BY_4         (1)
#define MSPI_CLK_BY_8         (2)
#define MSPI_CLK_BY_16        (3)
#define MSPI_CLK_BY_32        (4)
#define MSPI_CLK_BY_64        (5)
#define MSPI_CLK_BY_128       (7)

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/*This function is used to initialize the SPI module*/
void mspi_init(u8_t au8_spiMode, u8_t au8_dataOutMode, u8_t au8_clockMode, u8_t au8_spiSpeed);

/*This function is used to send and receive one byte in master mode*/
void mspi_masterSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData);

/*This function is used to send and receive one byte in slave mode*/
void mspi_slaveSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData);

#endif /* MSPI_INTERFACE_H_ */