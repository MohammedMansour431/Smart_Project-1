//***********************************************************************   */
/* FILE NAME :BLUE_program.c                                              */
/* Author:MOHAMMED MANSOUR                                                 */
/* Description : This file contains the logical operation of BLUETOOTH module    */
/* **********************************************************************   */
/************************************************************************/
/*                     Include                                             */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MUART_interface.h"

/************************************************************************/
/*                    function definitions                              */
/************************************************************************/
void bluetooth_init_module (void)
{
	/*This function is responsible for initializing the UART module with specific baud rate*/
	 muart_init(MUART_BAUDRATE_9600);	
return;	
}


/*This function is responsible for sending one byte of data over bluetooth peripheral*/
void bluetooth_recvByte(u8_t* pu8_dataByte)
{
	
	/*This function is responsible for sending one byte of data over UART peripheral*/
	muart_recvByte (pu8_dataByte);

	return ;
}