#ifndef COSMIC_DEFINITIONS_MASKED_H
#define COSMIC_DEFINITIONS_MASKED_H

#define ISR(vect) void vect(void)
#define DECLARE_ISR(vect) extern ISR(vect)

#define FAR_MODIFIER /* Nothing */

#define AT_MEMADDR(addr) /* Nothing */

#define ASM(s) /* Nothing */

# endif // End of Include Guard //
