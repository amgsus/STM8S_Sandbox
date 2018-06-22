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
#include "adc.h"
#include "adc_pins.h"
#include "map_i2i.h"
#include "itos.h"
#include <string.h>

#define MAX_ADC_MEASUREMENTS 10

static uint16_t avgValue;
static uint8_t  samplesCount;

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
    SetupPinAsFloatingInput(PD, 3);
    SetupPinAsPP(PA, 3);
    ADC_WakeUp();
    ADC_SelectChannel(AIN_PD3);
    avgValue = 0;
    samplesCount = 0;
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
    static uint16_t count_100ms = 0;
    static bool     adcRunning = false;
    static uint16_t measuredVoltage = 0;
    uint16_t sampledValue = 0;
    char     sVoltage[8];
    char    *s;

    // Toggle PB5 every 1 second.

    count_100ms++;
    if (count_100ms == 100) {
        count_100ms = 0;
        PB_ODR ^= BIT(5);

        s = uwtos(measuredVoltage, sVoltage, RADIX_10); // FixMe: !!!!!
        S_Print(s);
        S_Put('\n');
    }

    if (adcRunning)
    {
        if (ADC_PollReady(&sampledValue)) // Wait until data is ready.
        {
            adcRunning = false;

            avgValue += sampledValue;
            samplesCount++;

            if (samplesCount == MAX_ADC_MEASUREMENTS)
            {
                avgValue /= samplesCount;
                measuredVoltage = map_i2i(avgValue, 0, MAX_ADC_VALUE, 0, 330); // 3V3
                avgValue = 0;
                samplesCount = 0;
            }
        }
    }
    else
    {
        ADC_StartConversion();
        adcRunning = true;
    }

    PA_ODR ^= BIT(3);
}

