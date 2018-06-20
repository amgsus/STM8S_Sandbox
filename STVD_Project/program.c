// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      Project:    STM8S_Sandbox                                     *** //
// ***      Module:     program                                           *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Toolchain:  CXSTM8                                            *** //
// ***      Created:    Jun 17, 2018 09:24 PM                             *** //
// ***      Modified:   Jun 20, 2018 11:38 PM                             *** //
// ************************************************************************** //

#include "platform.h"
#include "serial.h"

void init()
{
    SetupPinAsOD(PB, 5);
}

void loop()
{
    if (S_HowMuchAvailable()) {
        S_Put(S_Get()); // Ping-pong.
    }

    PIN(PB, 5, OD_OPEN);
    delay_ms(100);
    PIN(PB, 5, OD_HIGH_Z);
    delay_ms(100);
}

