/******************************************************************************/
/* File name: MUART_interface.h                                               */
/* Author: MOHAMMED MANSOUR  												      */
/* Description: This file contains the interfacing information of UART Module */
/******************************************************************************/

/*Header file guard*/
#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/*Baud rate register values at 16MHz*/
#define MUART_BAUDRATE_2400    (416)
#define MUART_BAUDRATE_4800    (207)
#define MUART_BAUDRATE_9600    (103)
#define MUART_BAUDRATE_19200   (51)
#define MUART_BAUDRATE_115200  (8)

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/*This function is responsible for initializing the UART module with specific baud rate*/
void muart_init(u16_t au16_baudRate);

/*This function is responsible for sending one byte of data over UART peripheral*/
void muart_sendByte(u8_t au8_dataByte);

/*This function is responsible for sending multiple bytes of data with defined size over UART peripheral*/
void muart_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize);

/*This function is responsible for receiving one byte of data from UART peripheral*/
void muart_recvByte(u8_t* pu8_dataByte);

#endif /* MUART_INTERFACE_H_ */