/*
 * lab2 4.7.c
 *
 * Created: 12/08/2026 1:06:29 PM
 * Author : zmen433
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define PRIME_COUNT 62

void usart_init(uint16_t ubrr)
{
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr;

	UCSR0B = (1 << TXEN0);

	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void usart_transmit(uint8_t data)
{
	while (!(UCSR0A & (1 << UDRE0)))
	{
	}

	UDR0 = data;
}

int main(void)
{
	uint16_t primes[PRIME_COUNT];

	uint16_t number;
	uint16_t divisor;

	uint8_t prime_index = 0;
	uint8_t is_prime;

	uint8_t hundreds;
	uint8_t tens;
	uint8_t ones;

	usart_init(12);

	/* Generate prime numbers */
	for (number = 2; number <= 300; number++)
	{
		is_prime = 1;

		for (divisor = 2; divisor < number; divisor++)
		{
			if (number % divisor == 0)
			{
				is_prime = 0;
				break;
			}
		}

		if (is_prime == 1)
		{
			primes[prime_index] = number;
			prime_index++;
		}
	}

	while (1)
	{
		for (prime_index = 0; prime_index < PRIME_COUNT; prime_index++)
		{
			number = primes[prime_index];

			hundreds = number / 100;
			tens = (number / 10) % 10;
			ones = number % 10;

			usart_transmit(hundreds + '0');
			usart_transmit(tens + '0');
			usart_transmit(ones + '0');

			usart_transmit(',');
			usart_transmit(' ');
		}
	}
}
