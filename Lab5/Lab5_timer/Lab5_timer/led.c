/*
 * led.c
 *
 * Created: 23/09/2026 11:21:08 AM
 *  Author: zmen433
 */ 
#include "led.h"
#include <avr/io.h>

void led_toggle(){
	PORTB ^= (1 << PB5);
}
