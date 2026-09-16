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

volatile uint16_t adc_raw;
volatile uint16_t adc_mv;


int main(void)
{
    /* Replace with your application code */
	adc_init();
	
    while (1) 
    {
		adc_raw = adc_read(2);
		adc_mv = adc_convert_mv(adc_raw);
		
		// Convert number to ASCII and transmit
		usart_transmit_uint16(adc_mv);
		
		// Send unit
		usart_transmit_string("mV\r\n");
		
		// Slow down output so it is easier to read
		_delay_ms(100);
		
    }
	return 0;
}

