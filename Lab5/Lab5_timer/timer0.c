/*
 * timer0.c
 *
 * Created: 23/09/2026 11:20:49 AM
 *  Author: zmen433
 */ 
#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void timer0_init(){
	TCCR0A = (1 << WGM01); //CTC mode
	
	TCNT0 = 0; //start timer0 from 0;
	OCR0A = 77;
	TIFR0 = (1 << OCF0A);
	
	TCCR0B = (1 << CS02);
	
	
}

uint8_t timer0_check_clear_compare(){
	if (TIFR0 & (1 << OCF0A))
	{
		TIFR0 = (1 << OCF0A);
		return 1;
	}
	return 0;
}