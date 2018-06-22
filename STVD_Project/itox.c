#include "itox.h"

static const char heximal_digits[17] = "0123456789ABCDEF";

char* btox(unsigned char byte, char *buff)
{
    *buff++ = heximal_digits[((unsigned char) byte >> 4) & 0x0F];
    *buff++ = heximal_digits[((unsigned char) byte) & 0x0F];

    return buff;
}

char* wtox(unsigned short word, char *buff)
{
    buff += 3;

    *buff-- = heximal_digits[((unsigned char) word) & 0x0F];
    word >>= 4;
    *buff-- = heximal_digits[((unsigned char) word) & 0x0F];
    word >>= 4;
    *buff-- = heximal_digits[((unsigned char) word) & 0x0F];
    word >>= 4;
    *buff   = heximal_digits[((unsigned char) word) & 0x0F];

    return buff + 4;
}