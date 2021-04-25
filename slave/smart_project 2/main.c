/***********************************************************************   */
/* FILE NAME :Slave Main Program .                                         */
/* Author:MOHAMMED MANSOUR                                                 */
/* Description : This file contains the interfacing information of spi
   module and two actuator work when master module send data from bluetooth */
/***********************************************************************   */

#include "LSTD_TYPES.H"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#define F_CPU  16000000UL
#include "util/delay.h"

int main(void)
{
	    u8_t sendata ;
		u8_t recvdata ;

	/* spi slave input output port*/
		mdio_setPinStatus(PORTB,(PIN4|PIN5|PIN7),INPUT_FLOAT);
		mdio_setPinStatus(PORTB,PIN6,OUTPUT);
		
	/* output pin actuator_1 and actuator_2 */
		mdio_setPinStatus(PORTD,PIN3,OUTPUT);
		mdio_setPinStatus(PORTD,PIN2,OUTPUT);
		
    /* his function is used to initialize the SPI module*/
		mspi_init(MSPI_SLAVE_MODE,MSPI_MSB_FIRST,MSPI_SAMPLE_R_SETUP_F,MSPI_CLK_BY_16);
	

	/* Replace with your application code */
		while (1) 
   { 
	/*This function is used to send and receive one byte in slave mode*/
		mspi_slaveSendRecvByte(sendata, &recvdata);

		switch(recvdata)
	   {
		   
	/*In case of Led1  ON*/
			case 'a':
			
		mdio_setPinValue(PORTD,PIN3,HIGH);
			break;
			
	/*In case of Led2  ON*/		
		    case 'b':
		
		mdio_setPinValue(PORTD,PIN2,HIGH);
	 	    break;
			 
	/*In case of Led1  OFF*/	
		case 'A':
		
		mdio_setPinValue(PORTD,PIN3,LOW);
			break;
			
	/*In case of Led1  OFF*/
		case 'B':
		
		mdio_setPinValue(PORTD,PIN2,LOW);
			break;
		
		}
   }
}

