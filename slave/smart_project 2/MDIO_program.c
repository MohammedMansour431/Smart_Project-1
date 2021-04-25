/***********************************************************************   */
/* FILE NAME :MDIO_program.c                                              */
/* Author:MOHAMMED MANSOUR                                                 */
/* Description : This file contains the logical operation of DIo module    */
/* **********************************************************************   */
/************************************************************************/
/*                     Include                                             */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
/************************************************************************/
/*  function definitions                                                                     */
/************************************************************************/

void mdio_setPinStatus( u8_t  au8_port , u8_t au8_pin , u8_t au8_pinStatus)
{
	/*Switching over the ports*/
	switch(au8_port)
	{/*In case portA */
	case PORTA:
	
	/* switching over pin  status*/
	switch(au8_pinStatus)	
		{
		/*In case of input float*/
		case INPUT_FLOAT:
			
			/*Clearing the corresponding bits in DDR register*/
			MDIO_DDRA &= ~au8_pin;
				break;
			
		/*In case of input pullup*/
		case INPUT_PULLUP:
			
			/*Clearing the corresponding bits in DDR register*/
			MDIO_DDRA  &= ~au8_pin;		
			/*Setting the corresponding bits in PORT register*/
			MDIO_PORTA |= au8_pin;
				break;
			
		/*In case of output*/
		case OUTPUT:

			/*Setting the corresponding bits in DDR register*/
			MDIO_DDRA |= au8_pin;
				break;
			
		/*In case of default case*/
		default:
				break;
		}
		
		break;
	/*In case of PORTB*/
		case PORTB:
			
			/*Switching over pin status*/
			switch(au8_pinStatus)
			{
				/*In case of input float*/
				case INPUT_FLOAT:
					
					/*Clearing the corresponding bits in DDR register*/
					MDIO_DDRB &= ~au8_pin; 
					break;
				
				/*In case of input pullup*/				
				case INPUT_PULLUP:
					
					/*Clearing the corresponding bits in DDR register*/					
					MDIO_DDRB  &= ~au8_pin;
					
					/*Setting the corresponding bits in PORT register*/
					MDIO_PORTB |= au8_pin;
					break;
				
				/*In case of output*/
				case OUTPUT:

					/*Setting the corresponding bits in DDR register*/
					MDIO_DDRB |= au8_pin;
					break;
				
				/*In case of default case*/
				default:
					break;
			}
			break;
	
	/*In case of PORTD*/
		case PORTD:
			
			/*Switching over pin status*/
			switch(au8_pinStatus)
			{
				/*In case of input float*/
				case INPUT_FLOAT:
					
					/*Clearing the corresponding bits in DDR register*/
					MDIO_DDRD &= ~au8_pin; 
					break;
				
				/*In case of input pullup*/				
				case INPUT_PULLUP:
					
					/*Clearing the corresponding bits in DDR register*/					
					MDIO_DDRD  &= ~au8_pin;
					
					/*Setting the corresponding bits in PORT register*/
					MDIO_PORTD |= au8_pin;
					break;
				
				/*In case of output*/
				case OUTPUT:

					/*Setting the corresponding bits in DDR register*/
					MDIO_DDRD |= au8_pin;
					break;
				
				/*In case of default case*/
				default:
					break;
			}
			break;
		
		/*In case of default case*/	
		default:
			break;

	}
	
	/*REturn from function */
	return;
}


void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_pinValue)
{
	/*Switching over the DIO ports*/
	switch(au8_port)
	{
		/*In case of PORTA*/
		case PORTA:
			
			/*Switching over pin value*/
			switch(au8_pinValue)
			{
			/*In case of low*/
			case LOW:
					
					/*Clearing the corresponding bits in PORT register*/
					MDIO_PORTA &= ~au8_pin; 
					break;
				
			/*In case of high*/				
			case HIGH:
					
					/*Setting the corresponding bits in PORT register*/
					MDIO_PORTA |= au8_pin;
					break;
				
				/*In case of default case*/
				default:
					break;
			}
			break;

		/*In case of PORTB*/
		case PORTB:
			
			/*Switching over pin value*/
			switch(au8_pinValue)
			{
				/*In case of low*/
				case LOW:
					
					/*Clearing the corresponding bits in PORT register*/
					MDIO_PORTB &= ~au8_pin; 
					break;
				
				/*In case of high*/				
				case HIGH:
					
					/*Setting the corresponding bits in PORT register*/
					MDIO_PORTB |= au8_pin;
					break;
				
				/*In case of default case*/
				default:
					break;
			}
			break;

		/*In case of PORTC*/
		case PORTC:
			
			/*Switching over pin value*/
			switch(au8_pinValue)
			{
				/*In case of low*/
				case LOW:
					
					/*Clearing the corresponding bits in PORT register*/
					MDIO_PORTC &= ~au8_pin; 
					break;
				
				/*In case of high*/				
				case HIGH:
					
					/*Setting the corresponding bits in PORT register*/
					MDIO_PORTC |= au8_pin;
					break;
				
				/*In case of default case*/
				default:
					break;
			}
			break;

		/*In case of PORTD*/
		case PORTD:
			
			/*Switching over pin value*/
			switch(au8_pinValue)
			{
				/*In case of low*/
				case LOW:
					
					/*Clearing the corresponding bits in PORT register*/
					MDIO_PORTD &= ~au8_pin; 
					break;
				
				/*In case of high*/				
				case HIGH:
					
					/*Setting the corresponding bits in PORT register*/
					MDIO_PORTD |= au8_pin;
					break;
				
				/*In case of default case*/
				default:
					break;
			}
			break;
			
			/*In case of default*/
			default:
				break;
	}
	
	/*Return from this function*/
	return;
}

void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin)
{
	/*Switching over the DIO ports*/
	switch(au8_port)
	{
		/*In case of PORTA*/
		case PORTA:

			/*Toggling the corresponding bits in PORT register*/
			MDIO_PORTA ^= au8_pin;
			break;			

		/*In case of PORTB*/
		case PORTB:

			/*Toggling the corresponding bits in PORT register*/
			MDIO_PORTB ^= au8_pin;
			break;			

		/*In case of PORTC*/
		case PORTC:

			/*Toggling the corresponding bits in PORT register*/
			MDIO_PORTC ^= au8_pin;
			break;			

		/*In case of PORTD*/
		case PORTD:

			/*Toggling the corresponding bits in PORT register*/
			MDIO_PORTD ^= au8_pin;
			break;			

		/*In case of default*/
		default:
			break;
	}
		
	/*Return from this function*/
	return;
}

u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin)
{
	/*This variable is used to get the corresponding pin value*/
	u8_t au8_pinValue = 0;
	
	/*Switching over the DIO ports*/
	switch(au8_port)
	{
		/*In case of PORTA*/
		case PORTA:
			
			/*Checking the pin value is HIGH or LOW*/
			if( MDIO_PINA & au8_pin )
			{
				/*The pin value is HIGH*/
				au8_pinValue = HIGH;	
			}
			else
			{
				/*The pin value is LOW*/
				au8_pinValue = LOW;
			}
			break;

		/*In case of PORTB*/
		case PORTB:
			
			/*Checking the pin value is HIGH or LOW*/
			if( MDIO_PINB & au8_pin )
			{
				/*The pin value is HIGH*/
				au8_pinValue = HIGH;	
			}
			else
			{
				/*The pin value is LOW*/
				au8_pinValue = LOW;
			}
			break;

		/*In case of PORTC*/
		case PORTC:
			
			/*Checking the pin value is HIGH or LOW*/
			if( MDIO_PINC & au8_pin )
			{
				/*The pin value is HIGH*/
				au8_pinValue = HIGH;	
			}
			else
			{
				/*The pin value is LOW*/
				au8_pinValue = LOW;
			}
			break;

		/*In case of PORTD*/
		case PORTD:
			
			/*Checking the pin value is HIGH or LOW*/
			if( MDIO_PIND & au8_pin )
			{
				/*The pin value is HIGH*/
				au8_pinValue = HIGH;	
			}
			else
			{
				/*The pin value is LOW*/
				au8_pinValue = LOW;
			}
			break;
		
		/*In case of default*/
		default:
			break;
	}

	/*Return the pin value*/
	return au8_pinValue;
}
