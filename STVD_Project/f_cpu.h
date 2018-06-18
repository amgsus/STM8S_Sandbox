#ifndef STM8S_F_CPU_H
#define STM8S_F_CPU_H

// Refer to a figure 20 (Clock tree) of the datasheet.

#ifndef HSI_DIV_FACTOR
#   define HSI_DIV_FACTOR 8 /* Default */
#else
#   if (HSI_DIV_FACTOR != 1) && (HSI_DIV_FACTOR != 2) && \
            (HSI_DIV_FACTOR != 4) && (HSI_DIV_FACTOR != 8)
#       error "HSI_DIV_FACTOR must be 1, 2, 4 or 8!"
#   endif
# endif

#ifndef F_CPU_DIV_FACTOR
#   define F_CPU_DIV_FACTOR 1 /* Default */
#else
#   if (F_CPU_DIV_FACTOR != 1) && (F_CPU_DIV_FACTOR != 2) && \
            (F_CPU_DIV_FACTOR != 4) && (F_CPU_DIV_FACTOR != 8) && \
            (F_CPU_DIV_FACTOR != 16) && (F_CPU_DIV_FACTOR != 32) && \
            (F_CPU_DIV_FACTOR != 64) && (F_CPU_DIV_FACTOR != 128)
#       error "F_CPU_DIV_FACTOR must be of power of 2 (1..128)!"
#   endif
# endif

/**
 * LSI (Low Speed Internal RC-Oscillator) frequency.
 */
#define F_LSI        128000U

/**
 * HSI (High Speed Internal RC-Oscillator) frequency.
 */
#define F_HSI        16000000U

/**
 * Divided HSI (High Speed Internal RC-Oscillator) frequency.
 */
#define F_HSIDIV    (F_HSI / HSI_DIV_FACTOR)

/**
 * CPU clock frequency.
 */
#define F_CPU       (F_MASTER / F_CPU_DIV_FACTOR)

/**
 * The peripheral clock frequency (F_PSC) is equal to F_MASTER.
 */
#define F_CK_PSC    (F_MASTER)

# endif // End of Include Guard //
