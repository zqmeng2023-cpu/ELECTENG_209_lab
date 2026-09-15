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

uint16_t adc_read(uint8_t chan){
	uint8_t low;
	uint8_t high;
	uint16_t result;
	
	// Clear old channel selection bits and select the requested ADC channel
	ADMUX = (ADMUX & 0xF0) | (chan & 0x0F);
	
	// Start ADC conversion
	ADCSRA |= (1 << ADSC);
	
	while(ADCSRA & (1 << ADSC)){
		
	}
	low = ADCL;
	high = ADCH;
	
	result  = ((uint16_t)high << 8) | low;
	return result;
	
}

uint16_t adc_convert_mv(uint16_t value){
	uint32_t voltage_mv;
	voltage_mv = (uint32_t)value * 5000UL;
	voltage_mv = voltage_mv / 1023UL;
	
	return(uint16_t)voltage_mv;
}