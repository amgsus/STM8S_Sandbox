#ifndef INT_TO_STR_H
#define INT_TO_STR_H

#include "stdint.h"

#ifndef RADIX_10
    #define RADIX_10 10
#endif
#ifndef RADIX_16
    #define RADIX_16 16
#endif

unsigned char * ubtos( uint8_t value, unsigned char * buffer, uint8_t base);
unsigned char * uwtos(uint16_t value, unsigned char * buffer, uint8_t base);

#endif
