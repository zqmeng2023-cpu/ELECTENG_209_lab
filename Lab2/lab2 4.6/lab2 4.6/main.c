/*
 * lab2 4.6.c
 *
 * Created: 12/08/2026 12:54:02 PM
 * Author : zmen433
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>



void usart_init(uint16_t ubrr)
{
	UBRR0H = (uint8_t)(ubrr>>8);
	UBRR0L = (uint8_t)(ubrr);

	UCSR0B = (1 << TXEN0);

	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void usart_transmit(uint8_t data)
{
	while(!(UCSR0A & (1 << UDRE0)))
	{

	}
	UDR0 = data;
}

int main(void)
{
	/* Replace with your application code */
	uint16_t number = 345;
	uint8_t hundreds;
	uint8_t tens;
	uint8_t ones;

	usart_init(12);
	while (1)
	{
		hundreds = number/100;
		tens = (number/10)%10;
		ones = number%10;
		
		usart_transmit(hundreds + '0');
		usart_transmit(tens + '0');
		usart_transmit(ones + '0');
		_delay_ms(500);
	}
}


