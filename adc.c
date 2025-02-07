/*
 * adc.c
 *
 *  Created on: Dec 19, 2024
 *      Author: khans
 */
#include "adc.h"



void adc1Init(void)
{
	ADC1_ENABLE();
	ADC1_START_CONVERSION();
}
void adc1DeInit(void)
{
	ADC1_DISABLE();
	ADC1_CLOCK_DISABLE();
}
uint16_t adc1ReadValue(void)
{
	if((ADC_1->ADC_SR) & (1u << 1))
	{
		return ADC_1->ADC_DR;
	}
	return -1;
}
void adc1Configuration(ADC_RESOLUTION_SELECTION_e resolution, ADC_MODE_SELECTION_e mode, ADC_CHANNEL_SELECTION_e channel, ADC_SAMPLING_SELECTION_e sampling )
{
	ADC1_CLOCK_ENABLE();
	ADC_1->ADC_CR1 &= ~(0b11 << 24);
	switch(resolution)
	{
		case  ADC_RESOLUTION_6:    ADC_1->ADC_CR1 |= (ADC_RESOLUTION_6 << 24); break;
		case  ADC_RESOLUTION_8:    ADC_1->ADC_CR1 |= (ADC_RESOLUTION_8 << 24); break;
		case ADC_RESOLUTION_10:   ADC_1->ADC_CR1 |= (ADC_RESOLUTION_10 << 24); break;
		case ADC_RESOLUTION_12:   ADC_1->ADC_CR1 |= (ADC_RESOLUTION_12 << 24); break;
		default: break;
	}

	switch(mode)
	{
		case     ADC_MODE_SINGLE_CONV:        ADC1_MODE_SINGLE();     break;
		case ADC_MODE_CONTINUOUS_CONV:    ADC1_MODE_CONTINUOUS();	  break;
		default: break;
	}

	uint8_t SMPRx = channel / 10;
	uint8_t smpBitField = (channel % 10) * 3;
	if(SMPRx)
	{
			switch(sampling)
			{
				case ADC_SAMPLING_3_CYCLE: {
					ADC_1->ADC_SMPR1 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR1 |= (ADC_SAMPLING_3_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_15_CYCLE: {
					ADC_1->ADC_SMPR1 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR1 |= (ADC_SAMPLING_15_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_28_CYCLE: {
					ADC_1->ADC_SMPR1 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR1 |= (ADC_SAMPLING_28_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_56_CYCLE: {
					ADC_1->ADC_SMPR1 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR1 |= (ADC_SAMPLING_56_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_84_CYCLE: {
					ADC_1->ADC_SMPR1 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR1 |= (ADC_SAMPLING_84_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_112_CYCLE: {
					ADC_1->ADC_SMPR1 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR1 |= (ADC_SAMPLING_112_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_144_CYCLE: {
					ADC_1->ADC_SMPR1 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR1 |= (ADC_SAMPLING_144_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_480_CYCLE: {
					ADC_1->ADC_SMPR1 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR1 |= (ADC_SAMPLING_480_CYCLE << smpBitField);
				} break;

				default: break;
			}
	}
	else
	{
		switch(sampling)
			{
				case ADC_SAMPLING_3_CYCLE: {
					ADC_1->ADC_SMPR2 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR2 |= (ADC_SAMPLING_3_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_15_CYCLE: {
					ADC_1->ADC_SMPR2 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR2 |= (ADC_SAMPLING_15_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_28_CYCLE: {
					ADC_1->ADC_SMPR2 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR2 |= (ADC_SAMPLING_28_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_56_CYCLE: {
					ADC_1->ADC_SMPR2 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR2 |= (ADC_SAMPLING_56_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_84_CYCLE: {
					ADC_1->ADC_SMPR2 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR2 |= (ADC_SAMPLING_84_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_112_CYCLE: {
					ADC_1->ADC_SMPR2 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR2 |= (ADC_SAMPLING_112_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_144_CYCLE: {
					ADC_1->ADC_SMPR2 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR2 |= (ADC_SAMPLING_144_CYCLE << smpBitField);
				} break;

				case ADC_SAMPLING_480_CYCLE: {
					ADC_1->ADC_SMPR2 &= ~(0b111 << smpBitField);
					ADC_1->ADC_SMPR2 |= (ADC_SAMPLING_480_CYCLE << smpBitField);
				} break;

				default: break;
			}
	}
	/*
	 * 1-) çözünürlük
	 * 2-) mod
	 * 3-) örnekleme miktarı
	 * 4-)
	 */
}
void adc1SequenceLength(ADC_CONVERSION_LENGTH_SELECTION_e conversionLength) // bu fonksiyonu test et
{
		ADC_1_CLEAR_SEQUENCE_LENGTH();
		ADC_1->ADC_SQR1 |= (conversionLength << 20);
}
void adc1ChannelSequence(ADC_CHANNEL_SELECTION_e channel, ADC_CHANNEL_SEQUENCE_e sequence)
{
	//  5'e bölerek 3 e ayır. bit belirlemek için 5 ile çarp
	uint8_t SQRx = sequence / 6;
	uint8_t sqrxBitField = (sequence % 6) * 5;
	if(SQRx == 0)
	{
		ADC_1->ADC_SQR3 &= ~(0b11111 << sqrxBitField);
		ADC_1->ADC_SQR3 |=  (channel << sqrxBitField);
	}
	else if(SQRx == 1)
	{
		ADC_1->ADC_SQR2 &= ~(0b11111 << sqrxBitField);
		ADC_1->ADC_SQR2 |=  (channel << sqrxBitField);
	}
	else
	{
		ADC_1->ADC_SQR1 &= ~(0b11111 << sqrxBitField);
		ADC_1->ADC_SQR1 |=  (channel << sqrxBitField);
	}
}
