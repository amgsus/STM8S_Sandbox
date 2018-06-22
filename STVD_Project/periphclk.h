// ************************************************************************** //
// ***      MCU STM8S103F3P6 PERIPHERAL's CLOCK GATING BITS               *** //
// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Created:    Jun 22, 2018 10:32 AM                             *** //
// ***      Modified:   Jun 22, 2018 10:32 AM                             *** //
// ************************************************************************** //

#ifndef STM8S_PERIPHERALS_CLK_H
// -------------------------------------------------------------------------- //
#define STM8S_PERIPHERALS_CLK_H

#include "comdefs.h"
#include "platform.h"

// CLK_PCKENR1 //

#define PCKEN_TIM1  BIT(7)
#define PCKEN_TIM2  BIT(5)
#define PCKEN_TIM4  BIT(4)
#define PCKEN_UART  BIT(3)
#define PCKEN_SPI   BIT(1)
#define PCKEN_I2C   BIT(0)

// CLK_PCKENR2 //

#define PCKEN_ADC   BIT(3)
#define PCKEN_AWU   BIT(2)

#define EnablePeripheralClock(periph) \
    ((periph) == PCKEN_TIM1 || (periph) == PCKEN_TIM2 || \
        (periph) == PCKEN_TIM4 || (periph) == PCKEN_UART || \
        (periph) == PCKEN_SPI || (periph) == PCKEN_I2C) ? \
        SET(CLK_PCKENR1, (periph)) : \
        ((periph) == PCKEN_ADC || (periph) == PCKEN_AWU) ? \
        SET(CLK_PCKENR1, (periph)) : 0;

#define DisablePeripheralClock(periph) \
    ((periph) == PCKEN_TIM1 || (periph) == PCKEN_TIM2 || \
        (periph) == PCKEN_TIM4 || (periph) == PCKEN_UART || \
        (periph) == PCKEN_SPI || (periph) == PCKEN_I2C) ? \
        CLEAR(CLK_PCKENR1, (periph)) : \
        ((periph) == PCKEN_ADC || (periph) == PCKEN_AWU) ? \
        CLEAR(CLK_PCKENR1, (periph)) : 0;

// -------------------------------------------------------------------------- //
# endif // End of Include Guard //
