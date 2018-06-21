// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      Project:    STM8S_Sandbox                                     *** //
// ***      Module:     free_run                                          *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Toolchain:  CXSTM8                                            *** //
// ***      Created:    Jun 21, 2018 08:56 PM                             *** //
// ***      Modified:   Jun 22, 2018 01:54 AM                             *** //
// ************************************************************************** //

#if ENABLE_FREE_RUNNING_TIMER

#include "platform.h"
#include "f_cpu.h"

#ifndef TIME_BASE
#   define TIME_BASE 1000
#   warning "TIME_BASE was not specified. Using the default - 1 ms."
# endif

#define F_MASTER_MHZ (F_MASTER / 1000000)

#define DIV_1   0
#define DIV_2   1
#define DIV_4   2
#define DIV_8   3
#define DIV_16  4
#define DIV_32  5
#define DIV_64  6
#define DIV_128 7

#if   TIME_BASE == 500
#   if   F_MASTER_MHZ == 2
#       define _PRESCALER   DIV_4
#   elif F_MASTER_MHZ == 4
#       define _PRESCALER   DIV_8
#   elif F_MASTER_MHZ == 8
#       define _PRESCALER   DIV_16
#   elif F_MASTER_MHZ == 16
#       define _PRESCALER   DIV_32
#   elif F_MASTER_MHZ == 20
#       define _PRESCALER   DIV_64
#   elif F_MASTER_MHZ == 24
#       define _PRESCALER   DIV_64
#   endif
#elif TIME_BASE == 1000
#   if   F_MASTER_MHZ == 2
#       define _PRESCALER   DIV_8
#   elif F_MASTER_MHZ == 4
#       define _PRESCALER   DIV_16
#   elif F_MASTER_MHZ == 8
#       define _PRESCALER   DIV_32
#   elif F_MASTER_MHZ == 16
#       define _PRESCALER   DIV_64
#   elif F_MASTER_MHZ == 20
#       define _PRESCALER   DIV_128
#   endif
#elif TIME_BASE == 5000
#   if   F_MASTER_MHZ == 2
#       define _PRESCALER   DIV_64
#   elif F_MASTER_MHZ == 4
#       define _PRESCALER   DIV_128
#   endif
#endif

#ifndef _PRESCALER
#   define _PRESCALER   0
#   error "Could not determine a prescaler for FRT with such F_MASTER or TIME_BASE."
#endif

#define _US_PER_1_SECOND 1000000
#define _RELOAD_VALUE (TIME_BASE / (_US_PER_1_SECOND / (F_MASTER / (1 << (_PRESCALER)))))

void SetupFreeRunningTimer()
{
    TIM4_CR1  = 0x00; // Stop.
    TIM4_PSCR = _PRESCALER;
    TIM4_CNTR = 0;
    TIM4_ARR  = _RELOAD_VALUE;
#if FREE_RUNNING_TIMER_ISR_CONTEXT
    SET(TIM4_IER, TIM4_IER_UIE); // Enable TIM4 interrupt.
#else
    TIM4_IER  = 0x00; // Disable TIM4 interrupts.
#endif
    SET(TIM4_CR1, TIM4_CEN | TIM4_URS); // Start.
}

#endif // End of ENABLE_FREE_RUNNING_TIMER //