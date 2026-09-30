/*
 * Lab6_Part2.c
 *
 * Created: 30/09/2026 1:18:39 pm
 * Author : zmen433
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "display.h"


volatile uint16_t counter = 0;

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

ISR(TIMER0_COMPA_vect){
	send_next_character_to_display();
}

int main(void){
	init_display();
	timer0_init();
	seperate_and_load_characters(counter, 255);
	sei();
	
	while(1){
		_delay_ms(400);
		counter++;
		if(counter > 9999){
			counter = 0;
			
		}
		seperate_and_load_characters(counter, 255);
		
	}
	return 0;
}