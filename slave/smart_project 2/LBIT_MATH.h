//***********************************************************************   */
/* FILE NAME :LBIT_MATH.h                                                   */
/* Author:MOHAMMED MANSOUR                                                  */
/* Description :This header file contains C created data types              */
/* **********************************************************************   */

/*Header file guard*/
#ifndef _LBIT_MATH_H_
#define _LBIT_MATH_H_

/*Setting the required bit to 1*/
#define SET_BIT(REG,BIT)      REG |= (1<<BIT)

/*Setting the required bit to 0*/
#define CLEAR_BIT(REG,BIT)    REG &= ~(1<<BIT)

/*Get the required bit value*/
#define GET_BIT(REG,BIT)      ((REG >> BIT)&1)

/*Toggle the required bit value*/
#define TOGGLE_BIT(REG,BIT)   REG ^= (1<<BIT)

#endif /*_LBIT_MATH_H_*/
