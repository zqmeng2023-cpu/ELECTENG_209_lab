/*
 * adc.c
 *
 * Created: 15/09/2026 1:15:39 PM
 *  Author: zmen433
 */ 

#include<avr/io.h>

#include "common.h"
#include "adc.h"

void adc_init(void) {
	// AVCC reference
	// Right adjusted result
	// Select ADC2
	ADMUX = (1 << REFS0) | (1 << MUX1);
	
	// Enable ADC
	// Prescaler = 16
	ADCSRA = (1 << ADEN) | (1 << ADPS2);
	
	ADCSRB = 0x00;
}