#include "strutils.h"
#include <ctype.h> // For isalnum().

bool
isAlphaNumeric(char *s, uint8_t n)
{
    while (n) {
        if (!(isalnum(*s++))) {
            return 0;
        }
        n--;
    }

    return 1;
}

/**
 * Converts a single hexadecimal character (0-9, A-Z, a-z) into a number. The
 * input is NOT case-sensitive.
 *
 * @param xch
 *      A character to convert.
 *
 * @return
 *      Returns a value in range 0..15 on successful conversion. In case of
 *      invalid character returns negative number (-1).
 */
int8_t
xtoi(char xch)
{
    if (xch >= '0' && xch <= '9')
        return xch - '0';

    if (xch >= 'A' && xch <= 'F') // Replace with ASCII code in the future.
        return xch - 'A' + 10;

    if (xch >= 'a' && xch <= 'f') // Replace with ASCII code in the future.
        return xch - 'a' + 10;

    return -1;
}

/**
 * *** Hexadecimal (2 Characters) To Unsigned Integer ***
 *
 * Converts two hexadecimal characters into a number (8-bit). The result of
 * successful conversion is unsigned.
 *
 * @param s
 *      Pointer to a first hexadecimal character in a string (or a character
 *      buffer without the null-terminator).
 *
 * @return
 *      Returns a value in range 0..255 if the convertion is successful. In
 *      case of error (invalid hexadecimals) returns negative number (-1).
 */
int16_t
hex2ctoui(const char *s)
{
    int8_t msq;
    int8_t lsq;

    msq = xtoi(s[0]);
    if (msq < 0)
        return -1;

    lsq = xtoi(s[1]);
    if (lsq < 0)
        return -1;

    return ((uint8_t) msq << 4) | (uint8_t) lsq;
}