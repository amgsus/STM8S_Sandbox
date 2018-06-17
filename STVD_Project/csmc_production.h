#ifndef COSMIC_DEFINITIONS_PRODUCTION_H
#define COSMIC_DEFINITIONS_PRODUCTION_H

#if defined(__CSMC__)

#define ISR(vect) @far @interrupt void vect(void)
#define DECLARE_ISR(vect) extern ISR(vect)

typedef void @far (*InterruptHandlerProcedure_t)(void);

#endif

# endif // End of Include Guard //
