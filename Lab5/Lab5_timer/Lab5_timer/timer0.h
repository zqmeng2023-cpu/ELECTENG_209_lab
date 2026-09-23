/*
 * timer0.h
 *
 * Created: 23/09/2026 11:21:27 AM
 *  Author: zmen433
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include <stdint.h>

void timer0_init(void);

uint8_t timer0_check_clear_compare(void);

#endif /* TIMER0_H_ */