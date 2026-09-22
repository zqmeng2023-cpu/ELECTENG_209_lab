/*
 * Lab5_Prelab.c
 *
 * Created: 23/09/2026 10:17:01 AM
 * Author : zmen433
 */ 

#define F_CPU 2000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0x00;
	
    while (1) 
    {
		PORTB = PORTB | (1 << PB5);
		_delay_ms(375);
		PORTB = PORTB & ~(1<<PB5);
		_delay_ms(125);
    }
}

