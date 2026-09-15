/*
 * adc.h
 *
 * Created: 15/09/2026 1:18:14 PM
 *  Author: zmen433
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void adc_init(void);
uint16_t adc_read(uint8_t chan);

#endif /* ADC_H_ */