
/************************************************************************/
/* FILE NAME :Project smart home 1                                                */
/* Author:MOHAMMED MANSOUR                                                     */
/* Description : This file contains the interfacing information of Bluetooth module and spi module to receive data from Bluetooth device to avr atmega32(master) ,
and master send data to another avr (slave    */
/************************************************************************/

#include "LSTD_TYPES.H"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "MUART_interface.h"
#include "BLUE_interface.h"

#define F_CPU  16000000UL
#include "util/delay.h"

	int main(void)
	{
		 u8_t motor1=0;
		u8_t recvdata =0;
		
	/* spi input output port*/
		mdio_setPinStatus(PORTB,(PIN4|PIN5|PIN7),OUTPUT);
		mdio_setPinStatus(PORTB,PIN6,INPUT_FLOAT);
	
	 /*UART tx and rx pins  */
		mdio_setPinStatus(PORTD,PIN0,INPUT_FLOAT);
		mdio_setPinStatus(PORTD,PIN1,OUTPUT);
		mdio_setPinStatus(PORTA,PIN1,OUTPUT);

		/*define bluetooth Baudrate speed*/
		// muart_init(MUART_BAUDRATE_9600 );
	     bluetooth_init_module();
	  	/*initialization  Fun  SPI  */
	     mspi_init(MSPI_MASTER_MODE,MSPI_MSB_FIRST,MSPI_SAMPLE_R_SETUP_F,MSPI_CLK_BY_16);
   
  
    /* Replace with your application code */
   
    while (1) 
    {
		// bluetooth_init_module(MUART_BAUDRATE_9600,motor1); 
		bluetooth_recvByte(&motor1);
		// bluetooth_recvByte( motor1); 
		
	     if(motor1)
		 {
			mdio_setPinValue(PORTB,PIN4,LOW);
			mspi_masterSendRecvByte(motor1,(void *)0);
			mdio_setPinValue(PORTB,PIN4,HIGH);
			motor1 = 0;
	     }		
	}
	
}
		


