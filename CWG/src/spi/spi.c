/*
 * spi.c
 *
 * Created: 2015-06-17 20:47:36
 *  Author: Macikow
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#define DD_MOSI 3
#define DD_MISO 4
#define DD_SCK 5
#define DD_CSN 0
#define PIN_CSN 0
#define CSN_HIGH (PORTB |= (1<<PIN_CSN)) 	
#define CSN_LOW	 (PORTB &= ~(1<<PIN_CSN))
#define LED_TOGGLE ((PORTD) ^= (1<<3))

/************************************************************************/
/* inicjacja SPI 
	Wyjœcia SS nie u¿ywam
	jako wyjœcia enable u¿ywam CSN na PB0                                                              */
/************************************************************************/

void spiTransmit(unsigned char data);
unsigned char spiRead(void);
void SPI_CSNHigh(void);
void SPI_CSNLow(void);
void spiInit(void);
	
	
void spiInit(void){
	DDRB |= (1<<DD_MOSI) | (1<<DD_SCK) | (1<<DD_CSN);
	DDRB &= ~(1<<DD_MISO);
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0);
	printf("inicjacja spi SPCR: 0x%x -OK\n",SPCR);
}
void spiTransmit(unsigned char data){
	CSN_LOW;
	SPDR = data;
	//while(!(SPSR & (1<<SPIF)));
	CSN_HIGH;
}
unsigned char spiRead(void){
	return SPDR;
}
void SPI_CSNHigh(void){
//	CSN_HIGH;
}
void SPI_CSNLow(void){
//	CSN_LOW;
}