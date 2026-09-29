/*
 * Lab6_Prelab.c
 *
 * Created: 30/09/2026 11:01:58 am
 * Author : zmen433
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
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

volatile uint8_t counter = 0;
volatile uint8_t display_flag =0;


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

void timer0_init(void){
	// Timer0 CTC mode
	TCCR0A = (1 << WGM01);
	
	// 2MHz / 256 =7812.5 Hz
	// 10ms = 78 counts
	OCR0A = 77;
	
	// Enable Timer 0 compare match a interrupt
	TIMSK0 = (1 << OCIE0A);
	
	// prescaler = 256
	TCCR0B = (1 << CS02);
	
	
}

ISR(TIMER0_COMPA_vect)
{
	uint8_t digit;
	
	//disable both digits first
	PORTB |= (1 << PB0);
	PORTB |= (1 << PB1);
	
	
	if(display_flag == 0){
		//Ten digit
		digit = counter /10;
		display_digit(digit);
		
		// Enable Ds1
		PORTB &= ~(1 << PB0);
		display_flag = 1;
		
	} else {
		//One digit
		digit = counter % 10;
		display_digit(digit);
		
		//Enable Ds2
		PORTB &= ~(1 << PB1);
		display_flag = 0;
		
	}
}

int main(void)
{
    /* Replace with your application code */
	
	
	// PC0-PC5 :a-f output
	 DDRC |= 0x3F;
	 DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB4);
	 
	 //PB7 - push button input
	 DDRB &= ~(1 << PB7);
	 
	 PORTB |= (1 << PB7);
	 
	 PORTB |= (1 << PB0);
	 PORTB &= ~(1 << PB1);
	 
	 
	 timer0_init();
	 sei();
	 
	 
	 
	 
	uint8_t i;
    while (1) 
    {
		
		
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
			if (counter > 99){
				counter = 0;
			}
		}
	}
	
	return 0;
	
}

