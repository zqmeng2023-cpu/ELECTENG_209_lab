
#define F_CPU 2000000UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>



void usart_init(uint16_t ubrr)
{
UBRR0H = (uint8_t)(ubrr>>8);
UBRR0L = (uint8_t)(ubrr);

UCSR0B = (1 << TXEN0);

UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void usart_transmit(uint8_t data)
{
while(!(UCSR0A & (1 << UDRE0)))
{

}
UDR0 = data;
}

int main(void)
{
/* Replace with your application code */
usart_init(12);
while (1)
{
usart_transmit('3');
_delay_ms(500);
}
}

