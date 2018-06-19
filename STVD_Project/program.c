#include "platform.h"

void init()
{
    SetupPinAsOD(PB, 5);
}

void loop()
{
    PIN(PB, 5, OD_OPEN);
    delay_ms(1000);
    PIN(PB, 5, OD_HIGH_Z);
    delay_ms(1000);
}

