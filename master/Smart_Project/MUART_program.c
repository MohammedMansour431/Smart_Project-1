/*****************************************************************************/
/* File name: MUART_program.c                                                */
/* Author: MOHAMMED MANSOUR  												     */
/* Description: This file contains the logical operations of UART Module     */
/*****************************************************************************/

/************************************************************************/
/*                             Includes                                 */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MUART_private.h"
#include "MUART_interface.h"

#define  F_CPU  16000000UL
#include "util/delay.h"

/************************************************************************/
/*                             Important macros                         */
/************************************************************************/

#define TIMEOUT_DELAY  (10)

/************************************************************************/
/*                          Functions' definitions                      */
/************************************************************************/

void muart_init(u16_t au16_baudRate)
{
	/*Enable Tx and Rx Pins with no interrupts*/
	MUART_UCSRB = 0x18;
	
	/*Enable asynchronous mode, no parity bit, 1 stop bit and 1 byte of data operation*/
	MUART_UCSRC = 0x86;
	
	/*Setting the low baud rate register*/
	MUART_UBRRL = (u8_t)au16_baudRate;

	/*Setting the high baud rate register*/
	MUART_UBRRH = (u8_t)(au16_baudRate >> 8);
	
	/*Return from this function*/
	return;
}

void muart_sendByte(u8_t au8_dataByte)
{
	/*A variable used in timing out operations*/
	u8_t au8_timeOut = 0;
	
	/*Checking if the UDR register is empty or not*/
	if(GET_BIT(MUART_UCSRA, 5))
	{
		/*Transmitting data over UART*/
		MUART_UDR = au8_dataByte;
		
		/*Waiting until the transmission is complete*/
		while( (GET_BIT(MUART_UCSRA, 6) == 0) && (au8_timeOut < TIMEOUT_DELAY) )
		{
			/*Increase the timing out variable*/
			au8_timeOut++;
			
			/*Delay for 1ms*/
			_delay_ms(1);
		}
		
		/*Clear the TXC flag*/
		SET_BIT(MUART_UCSRA, 6);
	}
	else
	{
		/*Do nothing*/
	}
	
	/*Return from this function*/
	return;
}

void muart_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize)
{
	/*A variable used in looping operations*/
	u8_t au8_loopingVar = 0;
	
	/*Wait until sending all the data bytes*/
	while(au8_dataSize--)
	{
		/*Send data byte*/
		muart_sendByte(pu8_dataStream[au8_loopingVar]);
		
		/*Increase the looping variable*/
		au8_loopingVar++;
	}
	
	/*Return from this function*/
	return;
}

void muart_recvByte(u8_t* pu8_dataByte)
{
	/*Checking if there's any data received in UDR register*/
	if(GET_BIT(MUART_UCSRA, 7))
	{
		/*Get the data*/
		*pu8_dataByte = MUART_UDR;	
	}
	else
	{
		/*Do nothing*/
	}
	
	/*Return from this function*/
	return;
}