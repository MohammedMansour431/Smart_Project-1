/************************************************************************/
/* FILE NAME :BLUE_NTERFACE.h                                                  */
/* Author:MOHAMMED MANSOUR                                                     */
/* Description : This file contains the interfacing information of BLUETOOTH module  */
/************************************************************************/


/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/*Header file guard*/

#ifndef BLUE_INTERFACE_H_
#define BLUE_INTERFACE_H_
/************************************************************************/
/*                       function prototype                             */
/************************************************************************/

/*This function is used to initialize the BLUETOOTH module*/
void bluetooth_init_module (void);

/*This function is responsible for sending one byte of data over bluetooth peripheral*/
void bluetooth_recvByte(u8_t* pu8_dataByte);

#endif /* BLUE_INTERFACE_H_ */