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

# endif // End of Include Guard //
