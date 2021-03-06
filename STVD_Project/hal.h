#ifndef HAL_H
#define HAL_H

#include "iostm8s103.h"
#include "f_cpu.h"

#define EnableInterrupts() ASM("rim")

// Todo: Move bit masks somewhere else...

// UARTx_SR: UART Status Register

#define UART_TXE    BIT(7)
#define UART_TC     BIT(6)
#define UART_RXNE   BIT(5)
#define UART_OR     BIT(3)

// UARTx_CR2: UART Control Register #2

#define UART_TIEN   BIT(7)
#define UART_TCIEN  BIT(6)
#define UART_RIEN   BIT(5)
#define UART_TEN    BIT(3)
#define UART_REN    BIT(2)

// TIMx_SR: Status Register #1

#define TIM4_UIF     BIT(0)

// TIMx_IER: Interrupt Enable Register

#define TIM4_IER_UIE BIT(0)

// TIM4_CR1 (TIM6_CR1): Control Register #1

#define TIM4_ARPE   BIT(7)
#define TIM4_OPM    BIT(3)
#define TIM4_URS    BIT(2)
#define TIM4_UDIS   BIT(1)
#define TIM4_CEN    BIT(0)

// ADC_CSR   //

/**
 * A/D Converter End of Conversion Flag bit.<br/>
 * Register: ADC_CSR.
 */
#define ADC_EOC     BIT(7)
#define ADC_AWD     BIT(6)
/**
 * A/D Converter End of Conversion (EOC) Interrupt Enable bit.<br/>
 * Register: ADC_CSR.
 */
#define ADC_EOCIE   BIT(5)
#define ADC_AWDIE   BIT(4)

#define ADC_CH_BIT3 BIT(3)
#define ADC_CH_BIT2 BIT(2)
#define ADC_CH_BIT1 BIT(1)
#define ADC_CH_BIT0 BIT(0)

// ADC_CR1   //

/**
 * A/D Converter Continuous Conversion Enable bit.<br/>
 * Register: ADC_CR1.
 */
#define ADC_CONT    BIT(1)
/**
 * A/D Converter On/Off bit.<br/>
 * Register: ADC_CR1.
 */
#define ADC_ADON    BIT(0)

// ADC_CR2   //

#define ADC_EXTTRIG BIT(7)
/**
 * A/D Converter Data Alignment bit.<br/>
 * Register: ADC_CR2.
 */
#define ADC_ALIGN   BIT(3)
#define ADC_SCAN    BIT(1)


# endif // End of Include Guard //
