/*
 * adc.h
 *
 *  Created on: Dec 19, 2024
 *      Author: khans
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
#include "stm32f4xx.h"

#define 	ADC1_CLOCK_ENABLE()		(RCC->APB2ENR |= (1u << 8))
#define 	ADC2_CLOCK_ENABLE()		(RCC->APB2ENR |= (1u << 9))
#define 	ADC3_CLOCK_ENABLE()		(RCC->APB2ENR |= (1u << 10))

#define 	ADC1_CLOCK_DISABLE()	(RCC->APB2ENR &= ~(1u << 8))
#define 	ADC2_CLOCK_DISABLE()	(RCC->APB2ENR &= ~(1u << 9))
#define 	ADC3_CLOCK_DISABLE()	(RCC->APB2ENR &= ~(1u << 10))

typedef enum {

	ADC_RESOLUTION_12, ADC_RESOLUTION_10, ADC_RESOLUTION_8, ADC_RESOLUTION_6

}ADC_RESOLUTION_SELECTION_e;

typedef enum {

	ADC_MODE_SINGLE_CONV, ADC_MODE_CONTINUOUS_CONV

}ADC_MODE_SELECTION_e;

typedef enum {

	ADC_SAMPLING_3_CYCLE, ADC_SAMPLING_15_CYCLE, ADC_SAMPLING_28_CYCLE, ADC_SAMPLING_56_CYCLE,
	ADC_SAMPLING_84_CYCLE, ADC_SAMPLING_112_CYCLE, ADC_SAMPLING_144_CYCLE, ADC_SAMPLING_480_CYCLE

}ADC_SAMPLING_SELECTION_e;

typedef enum {

	ADC_CHANNEL_0, ADC_CHANNEL_1, ADC_CHANNEL_2, ADC_CHANNEL_3, ADC_CHANNEL_4, ADC_CHANNEL_5, ADC_CHANNEL_6, ADC_CHANNEL_7, ADC_CHANNEL_8, ADC_CHANNEL_9,
	ADC_CHANNEL_10, ADC_CHANNEL_11, ADC_CHANNEL_12, ADC_CHANNEL_13, ADC_CHANNEL_14, ADC_CHANNEL_15, ADC_CHANNEL_16, ADC_CHANNEL_17, ADC_CHANNEL_18

}ADC_CHANNEL_SELECTION_e;

typedef enum {

	ADC_CONVERSION_LENGTH_1, ADC_CONVERSION_LENGTH_2, ADC_CONVERSION_LENGTH_3, ADC_CONVERSION_LENGTH_4, ADC_CONVERSION_LENGTH_5, ADC_CONVERSION_LENGTH_6,
	ADC_CONVERSION_LENGTH_7, ADC_CONVERSION_LENGTH_8, ADC_CONVERSION_LENGTH_9, ADC_CONVERSION_LENGTH_10, ADC_CONVERSION_LENGTH_11, ADC_CONVERSION_LENGTH_12,
	ADC_CONVERSION_LENGTH_13, ADC_CONVERSION_LENGTH_14, ADC_CONVERSION_LENGTH_15, ADC_CONVERSION_LENGTH_16

}ADC_CONVERSION_LENGTH_SELECTION_e;

typedef enum {
	ADC_CHANNEL_SEQUENCE_1, ADC_CHANNEL_SEQUENCE_2, ADC_CHANNEL_SEQUENCE_3, ADC_CHANNEL_SEQUENCE_4, ADC_CHANNEL_SEQUENCE_5, ADC_CHANNEL_SEQUENCE_6,
	ADC_CHANNEL_SEQUENCE_7, ADC_CHANNEL_SEQUENCE_8, ADC_CHANNEL_SEQUENCE_9, ADC_CHANNEL_SEQUENCE_10, ADC_CHANNEL_SEQUENCE_11, ADC_CHANNEL_SEQUENCE_12,
	ADC_CHANNEL_SEQUENCE_13, ADC_CHANNEL_SEQUENCE_14, ADC_CHANNEL_SEQUENCE_15, ADC_CHANNEL_SEQUENCE_16
}ADC_CHANNEL_SEQUENCE_e;

typedef struct {

	volatile uint32_t ADC_SR;
	volatile uint32_t ADC_CR1;
	volatile uint32_t ADC_CR2;
	volatile uint32_t ADC_SMPR1;
	volatile uint32_t ADC_SMPR2;
	volatile uint32_t ADC_JOFR1;
	volatile uint32_t ADC_JOFR2;
	volatile uint32_t ADC_JOFR3;
	volatile uint32_t ADC_JOFR4;
	volatile uint32_t ADC_HTR;
	volatile uint32_t ADC_LTR;
	volatile uint32_t ADC_SQR1;
	volatile uint32_t ADC_SQR2;
	volatile uint32_t ADC_SQR3;
	volatile uint32_t ADC_JSQR;
	volatile uint32_t ADC_JDR1;
	volatile uint32_t ADC_JDR2;
	volatile uint32_t ADC_JDR3;
	volatile uint32_t ADC_JDR4;
	volatile uint32_t ADC_DR;
	volatile uint32_t ADC_CSR;
	volatile uint32_t ADC_CCR;
	volatile uint32_t ADC_CDR;

}ADC_RegDef_t;

#define 			ADC_1    				 ((ADC_RegDef_t*)(ADC1_BASE_ADDR))
#define 			ADC_2					 ((ADC_RegDef_t*)(ADC2_BASE_ADDR))
#define 			ADC_3     				 ((ADC_RegDef_t*)(ADC3_BASE_ADDR))

#define 			ADC1_ENABLE()			 (ADC_1->ADC_CR2 |= (1u << 0))
#define 			ADC2_ENABLE()			 (ADC_2->ADC_CR2 |= (1u << 0))
#define 			ADC3_ENABLE()			 (ADC_3->ADC_CR2 |= (1u << 0))

#define 			ADC1_DISABLE()			 (ADC_1->ADC_CR2 &= ~(1u << 0))
#define 			ADC2_DISABLE()			 (ADC_2->ADC_CR2 &= ~(1u << 0))
#define 			ADC3_DISABLE()			 (ADC_3->ADC_CR2 &= ~(1u << 0))

#define				ADC1_START_CONVERSION()	 (ADC_1->ADC_CR2 |= (1u << 30))
#define				ADC2_START_CONVERSION()	 (ADC_2->ADC_CR2 |= (1u << 30))
#define				ADC3_START_CONVERSION()	 (ADC_3->ADC_CR2 |= (1u << 30))

#define				ADC1_MODE_CONTINUOUS()	 (ADC_1->ADC_CR2 |= (1u << 1))
#define				ADC2_MODE_CONTINUOUS()	 (ADC_2->ADC_CR2 |= (1u << 1))
#define				ADC3_MODE_CONTINUOUS()	 (ADC_3->ADC_CR2 |= (1u << 1))

#define				ADC1_MODE_SINGLE()		 (ADC_1->ADC_CR2 &= ~(1u << 1))

#define 	ADC_1_CLEAR_SEQUENCE_LENGTH()	 (ADC_1->ADC_SQR1 &= ~(0b1111 < 20))

void adc1Configuration(ADC_RESOLUTION_SELECTION_e resolution, ADC_MODE_SELECTION_e mode, ADC_CHANNEL_SELECTION_e channel, ADC_SAMPLING_SELECTION_e sampling );
void adc1Init(void);
void adc1SequenceLength(ADC_CONVERSION_LENGTH_SELECTION_e conversionLength);
void adc1ChannelSequence(ADC_CHANNEL_SELECTION_e channel, ADC_CHANNEL_SEQUENCE_e sequence);
uint16_t adc1ReadValue(void);
#endif /* ADC_H_ */
