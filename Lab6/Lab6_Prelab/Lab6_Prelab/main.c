/*
 * Lab6_Prelab.c
 *
 * Created: 30/09/2026 11:01:58 am
 * Author : zmen433
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>


const uint8_t seg_pattern[10] = {
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x07,
	0x7F,
	0x6F
};

void display_digit(uint8_t number){
	uint8_t pattern = seg_pattern[number];
	
	PORTC = (PORTC & 0xC0)|(pattern & 0x3F);
	
	if ((pattern & 0x40) != 0)
	{
		PORTB |= (1 << PB4);
	} 
	else
	{
		PORTB &= ~(1 << PB4);
	}
}

int main(void)
{
    /* Replace with your application code */
	
	uint8_t counter = 0;
	// PC0-PC5 :a-f output
	 DDRC |= 0x3F;
	 DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB4);
	 
	 //PB7 - push button input
	 DDRB &= ~(1 << PB7);
	 
	 PORTB |= (1 << PB7);
	 
	 PORTB |= (1 << PB0);
	 PORTB &= ~(1 << PB1);
	 
	 
	 
	uint8_t i;
    while (1) 
    {
		display_digit(counter);
		
		for (i = 0; i < 10; i++){
			_delay_ms (100);
			
			if ((PINB & (1 << PB7)) == 0){
				counter = 0;
				display_digit( counter);
				break;
			}
		}
		
		if (i == 10)
		{
			counter ++;
			if (counter > 9){
				counter = 0;
			}
		}
	}
	
}

