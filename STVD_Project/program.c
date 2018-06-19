#include "platform.h"

void init()
{
    PB_DDR |= BIT(5); // Configure PB5 as output.
    PA_DDR |= BIT(3); // Configure PA3 as output.
    PA_CR1 |= BIT(3); // PA3 as Push-Pull.
    PA_CR2 |= BIT(3); // PA3 10 Mhz.
}

void loop()
{
    PIN(PB, 5, OD_OPEN);
    delay_ms(1000);
    PIN(PB, 5, OD_HIGH_Z);
    delay_ms(1000);
}

