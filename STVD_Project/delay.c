#include "platform.h"

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