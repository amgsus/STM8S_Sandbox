#ifndef COSMIC_DEFINITIONS_H
#define COSMIC_DEFINITIONS_H

#if defined(__CSMC__)
#include "csmc_production.h"
#else
#include "csmc_masked.h"
#endif

typedef void FAR_MODIFIER (*InterruptHandlerProcedure_t)(void);

#define SFR(name, addr) unsigned char name AT_MEMADDR(addr)

# endif // End of Include Guard //
