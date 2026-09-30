/*
 * Lab6_Part2.c
 *
 * Created: 30/09/2026 1:18:39 pm
 * Author : zmen433
 */ 

#include <avr/io.h>
#include <stdint.h>

void init_display(void)
{
	//Ds1 -Ds4: PD4 - PD7 output
	DDRD |= (1 << PD4)|(1 << PD5)|(1 << PD6)|(1 << PD7);
	
	//SH_CP, SH_DS, SH_ST: PC3-PC5 output
	DDRC |= (1 << PC3)|(1 << PC4)|(1 << PC5);
	
	//disable Ds1, Ds2, Ds3
	PORTD |= (1 << PD4);
	PORTD |= (1 << PD5);
	PORTD |= (1 << PD6);
	
	//enable Ds4
	PORTD &= ~(1 << PD7);
	
	//Initially SH_CP and SH_ST = 0
	PORTC &= ~(1 << PC3);
	PORTC &= ~(1 << PC5);
}

void send_next_character_to_display(void){
	uint8_t data = 0x07; //number 7
	
	// SH_CP = 0
	PORTC &= ~(1 << PC3);
	PORTC &= ~(1 << PC5);
	
	for (uint8_t i = 0; i < 8; i++)
	{
		//check MSB 
		if ((data & 0x80)!=0)
		{
			//SH_DS = 1
			PORTC |= (1 << PC4);
			
		} 
		else
		{
			//SH_DS=0
			PORTC &= ~(1 << PC4);
			
		}
		
		// Toggle Sh_CP : 0 to 1 to 0
		PORTC |= (1 << PC3);
		PORTC &= ~(1 << PC3);
		
		//Move next bit to MSB
		data = data << 1;
	}
	
	//Toggle SH_ST to latch output
	PORTC |= (1 << PC5);
	PORTC &= ~(1 << PC5);
	
}
int main(void)
{
    /* Replace with your application code */
	init_display();
	send_next_character_to_display();
	
    while (1) 
    {
    }
	return 0;
}

