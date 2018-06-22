#include "platform.h"
#include "adc.h"

#define ADC_CSR_CHANNEL_MASK ( ADC_CH_BIT0 | ADC_CH_BIT1 | ADC_CH_BIT2 | ADC_CH_BIT3 )

static volatile bool done;

bool ADC_WakeUp()
{
    if (ADC_IsRunning())
        return false;       // Prevent ADC from starting a conversion if ADON is already set.

    ADC_CSR |= ADC_EOCIE;   // Enable interrupt on EOC.
    ADC_CR1 |= ADC_ADON;    // Wake up ADC.

    return true;
}

void ADC_SelectChannel(uint8_t channel)
{
    ADC_CSR &= ~ADC_CSR_CHANNEL_MASK;       // Clear CH[3:0] bits.
    ADC_CSR |= (channel & ADC_CSR_CHANNEL_MASK);  // Set only necessary bits.
}

void ADC_StartConversion()
{
    if (ADC_IsRunning()) {
        done = false;
        ADC_CR1 |= ADC_ADON;                // Start conversion (set the ADON bit 2nd time).
    }
}

uint16_t ADC_Read()
{
    uint16_t value;

    ADC_CSR &= ~ADC_EOC;

    if (ADC_CR2 & ADC_ALIGN) {
        // R-alignment. Read LSB then MSB.
        value  = ADC_DRL;
        value |= ((uint16_t) ADC_DRH) << 8;
    } else {
        // L-alignment. Read MSB then LSB.
        value   = ADC_DRH;
        value <<= 2;
        value  |= ADC_DRL;
    }

    return value;
}

bool ADC_PollReady(uint16_t *adcValue)
{
    if (done) {
        *adcValue = ADC_Read();
        return true;
    }

    return false;
}

ISR(ADC_EOC_AWI_ISR)
{
    ADC_CSR &= ~ADC_EOC;
    done = true;
}