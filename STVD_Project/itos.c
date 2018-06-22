#include "itos.h"

unsigned char * ubtos( uint8_t value, unsigned char * buffer,
    uint8_t base)
{
    uint8_t i;
    for ( i = 4 ; value && (i > 0) ; --i, value /= base )
        buffer[i] = "0123456789ABCDEF"[value % base];
    return &buffer[i+1];
}

unsigned char * uwtos(uint16_t value, unsigned char * buffer,
    uint8_t base)
{
    uint8_t i;
    for ( i = 6 ; value && (i > 0) ; --i, value /= base )
        buffer[i] = "0123456789ABCDEF"[value % base];
    return &buffer[i+1];
}
