#ifndef COSMIC_DEFINITIONS_PRODUCTION_H
#define COSMIC_DEFINITIONS_PRODUCTION_H

#if defined(__CSMC__)

#define ISR(vect) @far @interrupt void vect(void)
#define DECLARE_ISR(vect) extern ISR(vect)

#define FAR_MODIFIER @far

#define AT_MEMADDR(addr) @addr

#define ASM(s) _asm(s)

#endif

# endif // End of Include Guard //
