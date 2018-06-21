// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      Project:    STM8S_Sandbox                                     *** //
// ***      Module:     program                                           *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Toolchain:  CXSTM8                                            *** //
// ***      Created:    Jun 17, 2018 09:24 PM                             *** //
// ***      Modified:   Jun 21, 2018 00:41 AM                             *** //
// ************************************************************************** //

#include "platform.h"
#include "serial.h"

/**
 * The initialization routine.
 *
 * Called once from the main context at the startup.
 *
 * Note: Be aware, that interrupts might be already enabled before this
 * procedure is called (when using additional features such as
 * ENABLE_SERIAL_INTERFACE, etc.).
 */
void init()
{
    SetupPinAsOD(PB, 5);
}

/**
 * The body of the main loop.
 */
void loop()
{
}

/**
 * The free-running timer callback. Can be used as a timebase for user tasks,
 * which should to be invoked with some periodic intervals.
 *
 * To enable this feature add a definition ENABLE_FREE_RUNNING_TIMER (=1) in
 * the project settings.
 *
 * This procedure is called from the main loop context if
 * FREE_RUNNING_TIMER_ISR_CONTEXT is equal to 0 or not defined. Otherwise, this
 * procedure will be invoked from the timer's ISR context when it overflows.
 *
 * Note: This procedure has a higher priority than `loop()` (even if running in
 * the context of the main loop)!
 */
void tick()
{
    static uint16_t counter = 0;

    // Toggle PB5 every 1 second.

    counter++;
    if (counter == 1000) {
        counter = 0;
        PB_ODR ^= BIT(5);
    }
}

