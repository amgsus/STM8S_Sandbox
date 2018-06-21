// ************************************************************************** //
// ***      STM8S QUICK START PROJECT & SANDBOX                           *** //
// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      Project:    STM8S_Sandbox                                     *** //
// ***      Module:     main                                              *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Toolchain:  CXSTM8                                            *** //
// ***      Created:    Jun 17, 2018 09:22 PM                             *** //
// ***      Modified:   Jun 22, 2018 01:18 AM                             *** //
// ***      Revision:   18w24a                                            *** //
// ************************************************************************** //

#include "platform.h"
#include "serial.h"

extern void init(void); // Implemented in 'program.c'
extern void loop(void); // Implemented in 'program.c'
extern void SetupSYSCLK(void); // Implemented in 'clk_setup.c'
#if ENABLE_FREE_RUNNING_TIMER
extern void SetupFreeRunningTimer(void); // Implemented in 'free_run.c'.
extern void tick(void); // Implemented in 'program.c'
#endif

#define IS_FREE_RUNNING_TIMER_EVENT \
    ( (TIM4_SR & TIM4_UIF) ? (CLEAR(TIM4_SR, TIM4_UIF), 1) : (0) )

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

#ifdef USING_CLION
int mai_()
#else
main()
#endif
{
    SetupSYSCLK();
#if ENABLE_FREE_RUNNING_TIMER
    SetupFreeRunningTimer();
#endif

#if ENABLE_SERIAL_INTERFACE
    SetupPinAsPP(PD, 5); // UART1_TX
    SetupPinAsFloatingInput(PD, 6); // UART1_RX
    InitUART();
#endif

#if ENABLE_SERIAL_INTERFACE || \
        (ENABLE_FREE_RUNNING_TIMER && FREE_RUNNING_TIMER_ISR_CONTEXT)
    EnableInterrupts();
#endif

    init();

    while (1)
    {
#if ENABLE_FREE_RUNNING_TIMER && !FREE_RUNNING_TIMER_ISR_CONTEXT
        if (IS_FREE_RUNNING_TIMER_EVENT) {
            tick();
        }
#endif
        loop();
    }
}

#if ENABLE_FREE_RUNNING_TIMER &&  FREE_RUNNING_TIMER_ISR_CONTEXT
ISR(TIM4_OVF_ISR)
{
    tick();
}
#endif

#pragma clang diagnostic pop