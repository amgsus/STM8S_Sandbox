#ifndef STM8_GPIO_SETUP_H
#define STM8_GPIO_SETUP_H

// Note: The compiler will generate BSET/BCLR (atomic) for the next macros if
// pin is passed as a number.

#define SetupPinAsPP(port, pin)  \
    do { \
        BITSET(port##_DDR, pin); \
        BITSET(port##_CR1, pin); \
        BITCLR(port##_CR2, pin); \
    } while (0)

#define SetupPinAsPPFast(port, pin) \
    do { \
        BITSET(port##_DDR, pin); \
        BITSET(port##_CR1, pin); \
        BITSET(port##_CR2, pin); \
    } while (0)

#define SetupPinAsOD(port, pin)  \
    do { \
        BITSET(port##_DDR, pin); \
        BITCLR(port##_CR1, pin); \
        BITCLR(port##_CR2, pin); \
    } while (0)

#define SetupPinAsODFast(port, pin) \
    do { \
        BITSET(port##_DDR, pin); \
        BITCLR(port##_CR1, pin); \
        BITSET(port##_CR2, pin); \
    } while (0)

#define SetupPinAsFloatingInput(port, pin) \
    do { \
        BITCLR(port##_DDR, pin); \
        BITCLR(port##_CR1, pin); \
        BITCLR(port##_CR2, pin); \
    } while (0)

#define SetupPinAsFloatingInputEXTI(port, pin) \
    do { \
        BITCLR(port##_DDR, pin); \
        BITCLR(port##_CR1, pin); \
        BITSET(port##_CR2, pin); \
    } while (0)

#define SetupPinAsInputWithPullup(port, pin) \
    do { \
        BITCLR(port##_DDR, pin); \
        BITSET(port##_CR1, pin); \
        BITCLR(port##_CR2, pin); \
    } while (0)

#define SetupPinAsInputWithPullupEXTI(port, pin) \
    do { \
        BITCLR(port##_DDR, pin); \
        BITSET(port##_CR1, pin); \
        BITSET(port##_CR2, pin); \
    } while (0)

# endif // End of Include Guard //
