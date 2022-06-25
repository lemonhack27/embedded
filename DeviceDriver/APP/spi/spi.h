/*
 * spi.h
 *
 *  Created on: 2018-2-3
 *      Author: Administrator
 */

#ifndef SPI_H_
#define SPI_H_

//====================================================
#include "AVP33x_Project.h"

//========º¯ÊýÉùÃ÷ =====================================
interrupt void spiTxFifoIsr(void);
interrupt void spiRxFifoIsr(void);
void spiInit(void);
void error(void);

#endif /* SPI_H_ */
