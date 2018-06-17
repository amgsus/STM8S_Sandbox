#ifndef COSMIC_DEFINITIONS_MASKED_H
#define COSMIC_DEFINITIONS_MASKED_H

#define ISR(vect) void vect(void)
#define DECLARE_ISR(vect) extern ISR(vect)

typedef void (*InterruptHandlerProcedure_t)(void);

# endif // End of Include Guard //
