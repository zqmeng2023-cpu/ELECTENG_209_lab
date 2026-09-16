/*
 * Lab4_ADC.c
 *
 * Created: 15/09/2026 1:12:39 PM
 * Author : zmen433
 */ 

#include "common.h"

#include <avr/io.h>
#include <util/delay.h>

#include "adc.h"
#include "usart.h"

#define NUM_SAMPLES 40

uint16_t adc0_values[NUM_SAMPLES];
uint16_t adc1_values[NUM_SAMPLES];

int main(void)
{
    /* Replace with your application code */
	adc_init();
	usart_init(12);
	uint8_t i;
	
	//Collect 40 examples form ADC0 and ADC1
	for (i = 0; i < NUM_SAMPLES; i++)
	{
		adc0_values[i] = adc_convert_mv(adc_read(0));
		adc1_values[i] = adc_convert_mv(adc_read(1));
	}
	
	//Send all samples through UART after sampling
	for(i = 0; i < NUM_SAMPLES; i++)
	{
		usart_transmit_uint16(adc0_values[i]);
		usart_transmit(',');
		usart_transmit_uint16(adc1_values[i]);
		usart_transmit('\r');
		usart_transmit('\n');
		
	}
	
	
    while (1) 
    {
    }
	return 0;
}

