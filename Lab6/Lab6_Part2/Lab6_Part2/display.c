/*
 * display.c
 *
 * Created: 30/09/2026 2:12:17 pm
 *  Author: zmen433
 */ 
#include "display.h"
#include <avr/io.h>

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

static volatile uint8_t disp_characters[4] = {0,0,0,0};

static volatile uint8_t disp_position = 0;

void init_display(void)
{
	//Ds1 -Ds4: PD4 - PD7 output
	DDRD |= (1 << PD4)|(1 << PD5)|(1 << PD6)|(1 << PD7);
	
	//SH_CP, SH_DS, SH_ST: PC3-PC5 output
	DDRC |= (1 << PC3)|(1 << PC4)|(1 << PC5);
	
	//disable Ds1, Ds2, Ds3, Ds4
	PORTD |= (1 << PD4);
	PORTD |= (1 << PD5);
	PORTD |= (1 << PD6);
	PORTD |= (1 << PD7);
	
	//Initially SH_CP and SH_ST = 0
	PORTC &= ~(1 << PC3);
	PORTC &= ~(1 << PC5);
}


void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos){
	uint8_t digit;
	
	for(uint8_t i = 0; i < 4; i++){
		digit = number % 10;
		disp_characters[i] = seg_pattern[digit];
		number = number/10;
	}
	if (decimal_pos < 4)
	{
		disp_characters[decimal_pos] |= 0x80;
	}
}

void send_next_character_to_display(void){
	uint8_t data;
	data = disp_characters[disp_position];
	
	PORTC &= ~(1 << PC3);
	PORTC &= ~(1 << PC5);
	
	for(uint8_t i = 0; i < 8; i++){
		if((data & 0x80) != 0){
			PORTC |= (1 << PC4);
		} else {
			PORTC &= ~(1 << PC4);
		}
		
		PORTC |= (1 << PC3);
		PORTC &= ~(1 << PC3);
		
		data = data << 1;
	}
	
	PORTD |= (1 << PD4);
	PORTD |= (1 << PD5);
	PORTD |= (1 << PD6);
	PORTD |= (1 << PD7);
	
	PORTC |= (1 << PC5);
	PORTC &= ~(1 << PC5);
	if(disp_position == 0){
		PORTD &= ~ (1 << PD7);
	}else if(disp_position == 1){
		PORTD &= ~ (1 << PD6);
	}else if(disp_position == 2){
	    PORTD &= ~ (1 << PD5);
    }else{
        PORTD &= ~ (1 << PD4);
    }
	
	
	disp_position++;
	if(disp_position > 3){
		disp_position = 0;
	}
}