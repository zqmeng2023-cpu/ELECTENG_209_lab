/*
 * Lab5_timer.c
 *
 * Created: 23/09/2026 11:20:10 AM
 * Author : zmen433
 */ 
#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>



int main(void)
{
    /* Replace with your application code */
	
	DDRB = DDRB | (1 << DDB5);
	timer0_init();
	sei();
	
    while (1) 
    {
    }
}

