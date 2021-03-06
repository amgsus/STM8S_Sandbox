#ifndef COMMON_DEFINITIONS_H
#define COMMON_DEFINITIONS_H

#ifndef NULL
#   define NULL ((void *) 0)
# endif

#define BIT(n)              (1u << (n))
#define BITSET(var, bit)    (var |=  BIT(bit))
#define BITCLR(var, bit)    (var &= ~BIT(bit))

#define SET(x, bitMask)     (x |=  (bitMask))
#define CLEAR(x, bitMask)   (x &= ~(bitMask))

#define ForceBounds(x, minBound, maxBound) \
    do { \
        if (x > (maxBound)) { \
            x = (maxBound); \
        } else if (x < (minBound)) { \
            x = (minBound); \
        } \
    } while (0)

#define GetValueInBounds(value, minBound, maxBound) \
    ((value) > (maxBound) ? (maxBound): ((value) < (minBound) ? (minBound) : (value)))

# endif // End of Include Guard //
