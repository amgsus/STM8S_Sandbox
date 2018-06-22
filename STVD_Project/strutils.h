#ifndef STRUTILS_H
#define STRUTILS_H

#include <stdint.h>
#include <stdbool.h>

bool isAlphaNumeric(char *s, uint8_t n);
int8_t xtoi(char xch);
int16_t hex2ctoui(const char *s); // Takes only 2 chars.

# endif
