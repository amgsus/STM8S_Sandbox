#ifndef STM8S_ADC_H
#define STM8S_ADC_H

#include "stdint.h"
#include "stdbool.h"
#include "platform.h"
#include "adc.h"

#define MAX_ADC_VALUE 1023

bool ADC_WakeUp(void);
void ADC_SelectChannel(uint8_t channel);
void ADC_StartConversion(void);
uint16_t ADC_Read(void);
bool ADC_PollReady(uint16_t *adcValue);
void ADC_Shutdown();

#define ADC_IsRunning() (ADC_CR1 & ADC_ADON)
#define ADC_IsEOC()     ((bool)(ADC_CSR & ADC_EOC))
#define ADC_Shutdown()  (ADC_CR1 &= ~ADC_ADON)

# endif // End of Include Guard //
