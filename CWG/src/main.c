/*
 * main.c
 *
 * Created: 2015-07-18 12:48:01
 *  Author: Macikow
 */ 
#define F_CPU 8000000UL
#include<avr/io.h>
#include "debug/debug.h"
#include "spi/spi.h"
#include "measure/measure.h"
#include "nRF/nRF.h"
#include <stdio.h>
#include <util/delay.h>

#define LED_INIT	(DDRD |= (1<<3))
#define LED_TOGGLE ((PORTD) ^= (1<<3))
#define LED_ON (PORTD |= (1<<3))
#define LED_OFF (PORTD|= (1<<3)) 
static int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);
static int uart_putchar(char c, FILE *stream)
{
	if (c == '\n')
	uart_putchar('\r', stream);
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}
#define DD_MOSI 3
#define DD_MISO 4
#define DD_SCK 5
#define DD_CSN 0
void ledInit(void){
	printf("inicjalizacja diody LED\n");
	DDRD|= (1<<3);
}


int main(void){
	stdout = &mystdout;
	
	USART_init();
	ledInit();
	ampInit();
	spiInit();
	
	while(1)
	{
		LED_TOGGLE;
		spiTransmit(0x12);
		_delay_ms(500);
	}
	return 0;
}