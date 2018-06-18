#ifndef COMMON_DEFINITIONS_H
#define COMMON_DEFINITIONS_H

#ifndef NULL
#   define NULL ((void *) 0)
# endif

#define BIT(n)              (1u << (n))
#define BITSET(var, bit)    (var |=  BIT(bit))
#define BITCLR(var, bit)    (var &= ~BIT(bit))

# endif // End of Include Guard //
