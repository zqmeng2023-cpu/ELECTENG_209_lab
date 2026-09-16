/*
 * 
 *
 * Created: 14/09/2026 1:39:55 PM
 * Author : zmen433
 */ 
#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB |= (1 << DDB5);
	DDRB &= ~(1 << DDB7);
	DDRC = 0x00;
	DDRD = 0x00;
	
	
	
	PORTB &= ~(1 << PORTB5);
	
    while (1) 
    {
		if ((PINB & (1 << PINB7)) == 0)
		{
			PORTB |= (1<< PORTB5);
		} 
		else
		{
			PORTB &= ~(1<< PORTB5);
		}
		
    }
	return 0;
}

