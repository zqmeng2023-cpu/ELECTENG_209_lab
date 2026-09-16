/*
 * usart.c
 *
 * Created: 16/09/2026 11:34:42 AM
 *  Author: ZMEN433
 */ 
#include <avr/io.h>
#include <stdint.h>
#include "usart.h"

void usart_init(uint16_t ubrr){
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr;
	
	// Enable transmitter
	UCSR0B = (1 << TXEN0);
	
	// 8 bit data
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	
}

void usart_transmit(uint8_t data){
	while (!(UCSR0A & (1 << UDRE0))){
		
	}
	UDR0 = data;
}

void usart_transmit_uint16 (uint16_t value){
	if (value >= 1000)
	{
		usart_transmit((value/1000) + '0');
	}
	
	if (value >= 100)
	{
		usart_transmit(((value / 100) % 10 ) + '0');
	}
	
	if (value >= 10)
	{
		usart_transmit(((value / 10) % 10 ) +'0');
	}
	
	usart_transmit((value % 10) + '0');
}


void usart_transmit_string(const char *text){
	while (*text != '\0'){
		usart_transmit(*text);
		text++;
	}
}