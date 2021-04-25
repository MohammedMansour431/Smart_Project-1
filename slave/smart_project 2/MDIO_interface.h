/************************************************************************/
/* FILE NAME :MDIO_NTERFACE.h                                                  */                                                                       
/* Author:MOHAMMED MANSOUR                                                     */
/* Description : This file contains the interfacing information of DIo module  */
/************************************************************************/
/*Header file guard*/

#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_
/************************************************************************/
/*  inter facing marco                                                                     */
/************************************************************************/
/* gpio ports*/
#define PORTA (0)
#define PORTB (1)
#define PORTC (2)
#define PORTD (3)
/*GPIO pins*/
#define PIN0 (0b00000001)
#define PIN1 (0b00000010)
#define PIN2 (0b00000100)
#define PIN3 (0b00001000)
#define PIN4 (0b00010000)
#define PIN5 (0b00100000)
#define PIN6 (0b01000000)
#define PIN7 (0b10000000)

/*GPIO pins_status*/
#define INPUT_FLOAT   (0)
#define INPUT_PULLUP  (1)
#define OUTPUT        (2)

/*GPIO pins value*/
#define LOW   (0)
#define HIGH  (1)
/************************************************************************/
/*                       function prototype                             */
/************************************************************************/
/*this function responsibly for certain status to a certain port pin   (used in GPIO pins_status to choose any pins of three pin )  */
void mdio_setPinStatus( u8_t  au8_port , u8_t au8_pin , u8_t au8_pinStatus);
/*this function responsible for setting certain value to a certain port pin    (used in GPIO pins value when used output low(0) or High (1)  )   */
void mdio_setPinValue( u8_t  au8_port , u8_t  au8_pin , u8_t  au8_pinStatus);

/*This function is responsible for toggling the current value of a certain port pin*/
void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin);

/*This function is responsible for getting the current value of a certain port pin*/
u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin);

#endif /* MDIO_INTERF ACE_H_ */