/*
 * spi.h
 *
 * Created: 2015-06-17 20:47:46
 *  Author: Macikow
 */ 


#ifndef SPI_H_
#define SPI_H_

void spiInit(void);
void spiTransmit(unsigned char data);
unsigned char spiRead(void);
void SPI_CSNHigh(void);
void SPI_CSNLow(void);


#endif /* SPI_H_ */