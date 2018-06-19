#include "platform.h"
#include "f_cpu.h"

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

#define DELAY_MS_MAGIC 6.5
#define CPU_CYCLES_PER_MS ( (uint16_t)(F_CPU / 1000 / 2 / DELAY_MS_MAGIC) ) /* CPU cycles per 1 ms. */

void delay_ms(uint16_t millis) // ToDo: Write in ASM.
{
    uint16_t i;

    while (millis)
    {
        millis--;
        i = CPU_CYCLES_PER_MS;
        while (i) i--;
    }
}