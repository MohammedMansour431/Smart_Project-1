/*****************************************************************************/
/* File name: MSPI_program.c                                                 */
/* Author:MOHAMMED MANSOUR  											     */
/* Description: This file contains the logical operations of SPI Module      */
/*****************************************************************************/

/************************************************************************/
/*                             Includes                                 */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

#define F_CPU  16000000UL
#include "util/delay.h"

/************************************************************************/
/*                           Important macros                           */
/************************************************************************/

#define TIMEOUT_DELAY  (100)

/************************************************************************/
/*                          Functions' definitions                      */
/************************************************************************/

void mspi_init(u8_t au8_spiMode, u8_t au8_dataOutMode, u8_t au8_clockMode, u8_t au8_spiSpeed)
{
	/*Clear the control register*/
	MSPI_SPCR = 0;
	
	/*Checking if the SPI speed to enable the SPI2X bit or not*/
	if((au8_spiSpeed % 2) == 0)
	{
		/*Enable the SPI double clock speed*/
		SET_BIT(MSPI_SPSR, 0);
	}
	else
	{
		/*Do nothing*/
	}

	/*Set the SPI control register, (0x40) -> Enable SPI operations*/
	MSPI_SPCR |= (0x40) | (au8_dataOutMode << 5) | (au8_spiMode << 4) | (au8_clockMode << 2) | (au8_spiSpeed / 2);
			
	/*Return from this function*/
	return;
}

void mspi_masterSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData)
{
	/*Variable used in timing out operations*/
	u8_t au8_timeOut = 0;
	
	/*Send data through SPI bus from master to slave*/
	MSPI_SPDR = au8_sendData;
	
	/*Wait until the SPI transmission ends*/
	while((GET_BIT(MSPI_SPSR, 7) == 0) && (au8_timeOut < TIMEOUT_DELAY))
	{
		/*Increasing timeout variable*/
		au8_timeOut++;
		
		/*Wait for 1 microseconds*/
		_delay_us(1);
	}
	
	/*Get the received data from slave*/
	*pu8_recvData = MSPI_SPDR;
	
	/*Return from this function*/
	return;
}

void mspi_slaveSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData)
{	
	/*Checking if there's any new data from master or not*/
	if(GET_BIT(MSPI_SPSR, 7))
	{
		/*Get the received data from master*/
		*pu8_recvData = MSPI_SPDR;
		
		/*Send data through SPI bus from slave to master*/
		MSPI_SPDR = au8_sendData;
	}
	else
	{
		/*Do nothing*/
	}
	
	/*Return from this function*/
	return;
}
