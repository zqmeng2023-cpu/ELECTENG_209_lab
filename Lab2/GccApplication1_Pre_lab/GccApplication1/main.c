/*
 * GccApplication1.c
 *
 * Created: 7/08/2026 4:07:39 PM
 * Author : zmen433
 */ 

#include <avr/io.h>
#include <stdint.h>

#define PRIME_COUNT 62

uint8_t is_prime(uint16_t number)
{
	uint16_t divisor;
	if(number < 2)
	{
		return 0;
	}
	for (divisor = 2; divisor * divisor <= number; divisor++)
	{
		if (number % divisor == 0)
		{
			return 0;
		}
	}
	return 1;
}


int main(void)
{
    /* Replace with your application code */
	uint16_t primes[PRIME_COUNT];
	uint8_t prime_index = 0;
	uint16_t number;
	for (number = 2; number <=300; number++)
	{
		if(is_prime(number)){
			primes[prime_index] = number;
			prime_index++;
		}
	}
    while (1)
    {
    }
}

