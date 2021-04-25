/*****************************************************************************/
/* File name: MSPI_private.h                                                 */
/* Author: MOHAMMED MANSOUR													     */
/* Description: This file contains the private information of SPI Module     */
/*****************************************************************************/

/*Header file guard*/
#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

/************************************************************************/
/*                            SPI registers                             */
/************************************************************************/

#define MSPI_SPCR  (*(volatile u8_t*)(0x2D))
#define MSPI_SPSR  (*(volatile u8_t*)(0x2E))
#define MSPI_SPDR  (*(volatile u8_t*)(0x2F))


#endif /* MSPI_PRIVATE_H_ */