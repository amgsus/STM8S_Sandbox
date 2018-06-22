// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      Project:    STM8S_Sandbox                                     *** //
// ***      Module:     intvect                                           *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Toolchain:  CXSTM8                                            *** //
// ***      Created:    Jun 17, 2018 09:24 PM                             *** //
// ***      Modified:   Jun 21, 2018 03:46 PM                             *** //
// ************************************************************************** //

#include "stdint.h"
#include "cosmic.h"

typedef struct {
    uint8_t instruction;
    InterruptHandlerProcedure_t serviceRoutinePtr;
} InterruptTableEntry_t;

#if defined(USING_CLION)
void _stext() {}
#else
extern void _stext();     /* startup routine */
#endif

// ISRs //

ISR(NonHandledInterrupt) {
    while (1); // ToDo: In order to detected unexpected interrupts put a breakpoint here.
}

#if ENABLE_SERIAL_INTERFACE
DECLARE_ISR(UART_RequestToTransmit_ISR);
DECLARE_ISR(UART_DataRecept_ISR);
#endif

DECLARE_ISR(ADC_EOC_AWI_ISR);

#if FREE_RUNNING_TIMER_ISR_CONTEXT
DECLARE_ISR(TIM4_OVF_ISR);
#endif

// Interrupt Vector Table //

#define OPCODE 0x82 /* See PM0044 sheet */

InterruptTableEntry_t const _vectab[] = {
    {OPCODE, (InterruptHandlerProcedure_t) _stext}, /* Reset */
    {OPCODE, NonHandledInterrupt}, /* Software Trap */
    {OPCODE, NonHandledInterrupt}, /* IRQ0  : TLI */
    {OPCODE, NonHandledInterrupt}, /* IRQ1  : AWU */
    {OPCODE, NonHandledInterrupt}, /* IRQ2  : CLK */
    {OPCODE, NonHandledInterrupt}, /* IRQ3  : EXTI0 (PAx) */
    {OPCODE, NonHandledInterrupt}, /* IRQ4  : EXTI1 (PBx) */
    {OPCODE, NonHandledInterrupt}, /* IRQ5  : EXTI2 (PCx) */
    {OPCODE, NonHandledInterrupt}, /* IRQ6  : EXTI3 (PDx) */
    {OPCODE, NonHandledInterrupt}, /* IRQ7  : EXTI4 (PEx) */
    {OPCODE, NonHandledInterrupt}, /* IRQ8  */
    {OPCODE, NonHandledInterrupt}, /* IRQ9  */
    {OPCODE, NonHandledInterrupt}, /* IRQ10 : SPI */
    {OPCODE, NonHandledInterrupt}, /* IRQ11 : TIM1 Update/OVF/UVF/Break */
    {OPCODE, NonHandledInterrupt}, /* IRQ12 : TIM1 CAPCOM */
    {OPCODE, NonHandledInterrupt}, /* IRQ13 : TIM2 Update/OVF */
    {OPCODE, NonHandledInterrupt}, /* IRQ14 : TIM2 CAPCOM */
    {OPCODE, NonHandledInterrupt}, /* IRQ15 */
    {OPCODE, NonHandledInterrupt}, /* IRQ16 */
#if ENABLE_SERIAL_INTERFACE
    {OPCODE, UART_RequestToTransmit_ISR}, /* IRQ17 : UART1 TXE */
    {OPCODE, UART_DataRecept_ISR}, /* IRQ18 : UART1 RXNE */
#else
    {OPCODE, NonHandledInterrupt}, /* IRQ17 : UART1 TXE */
    {OPCODE, NonHandledInterrupt}, /* IRQ18 : UART1 RXNE */
#endif
    {OPCODE, NonHandledInterrupt}, /* IRQ19 : I2C */
    {OPCODE, NonHandledInterrupt}, /* IRQ20 */
    {OPCODE, NonHandledInterrupt}, /* IRQ21 */
    {OPCODE, ADC_EOC_AWI_ISR},     /* IRQ22 : ADC1 EOC */
#if FREE_RUNNING_TIMER_ISR_CONTEXT
    {OPCODE, TIM4_OVF_ISR},        /* IRQ23 : TIM4 Update/OVF */
#else
    {OPCODE, NonHandledInterrupt}, /* IRQ23 : TIM4 Update/OVF */
#endif
    {OPCODE, NonHandledInterrupt}, /* IRQ24 : Flash EOP/WR_PG_DIS */
    {OPCODE, NonHandledInterrupt}, /* IRQ25 */
    {OPCODE, NonHandledInterrupt}, /* IRQ26 */
    {OPCODE, NonHandledInterrupt}, /* IRQ27 */
    {OPCODE, NonHandledInterrupt}, /* IRQ28 */
    {OPCODE, NonHandledInterrupt}, /* IRQ29 */
};
