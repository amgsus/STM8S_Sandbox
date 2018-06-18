#ifndef STM8_GPIO_MACRO_H
#define STM8_GPIO_MACRO_H

// Note: It's recommended to enable compiler optimizations (unreachable code
// removal, loop unrolling) when using GPIO macros!

// Note: Be careful when passing variables as the 2nd/3rd parameters to a macro
// PIN(...) -- in this case a compiler will generate "Read-Modify-Write" block
// instead of generating atomic instructions such as BSET (bit set) and
// BRES (bit reset).
//
// See: https://download.mikroe.com/documents/compilers/mikroc/pic/help/rmw.htm

#define PP_HIGH     1
#define PP_LOW      0
#define OD_FLOW     PP_LOW
#define OD_OPEN     OD_FLOW
#define OD_HIGH_Z   PP_HIGH

/**
 * With this macro you can switch the state of a pin.
 *
 * For example:
 *
 * -- PIN(PA, 3, PP_LOW); // Sets '0' on PA3 (assuming this pin is configured
 * as Push-Pull).
 *
 * -- PIN(PB, 5, OD_HIGH_Z); // Puts PB5 into High-Z (assuming this pin is
 * configured as Open Drain).
 */
#define PIN(port, pin, value) \
    do { (value) ? BITSET(port##_ODR, pin) : BITCLR(port##_ODR, pin); } while (0)

# endif // End of Include Guard //
