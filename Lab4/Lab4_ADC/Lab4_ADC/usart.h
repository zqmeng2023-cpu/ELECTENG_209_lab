/*
 * usart.h
 *
 * Created: 16/09/2026 11:30:59 AM
 *  Author: ZMEN433
 */ 


#ifndef USART_H_
#define USART_H_

#include <stdint.h>

void usart_init(uint16_t ubrr);
void usart_transmit(uint8_t data);
void usart_transmit_uint16(uint16_t value);
void usart_transmit_string(const char *text);



#endif /* USART_H_ */