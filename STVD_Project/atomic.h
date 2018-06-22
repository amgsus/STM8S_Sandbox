#ifndef _ATOMIC_COSMIC_H_
// -------------------------------------------------------------------------- //
#define _ATOMIC_COSMIC_H_

#include "platform.h"

#ifndef __CSMC__

    // X - unsigned char variable for storing CC register value.

    #define CRITICAL_SECTION()
    #define END_OF_CRITICAL_SECTION()
    #define CRITICAL_SECTION_EX(X)
    #define END_OF_CRITICAL_SECTION_EX(X)

//#   error "This version of critsec.h requires COSMIC C compiler!"
#else

    // X - unsigned char variable for storing CC register value.

    #define CRITICAL_SECTION() \
        (_asm("push cc \n rim \n"))

    #define END_OF_CRITICAL_SECTION() \
        (_asm("pop  cc \n"))

    #define CRITICAL_SECTION_EX(X) \
        (##X = (unsigned char)(_asm("push cc \n pop a \n rim \n")))

    #define END_OF_CRITICAL_SECTION_EX(X) \
        (_asm("push a \n pop cc \n", (unsigned char)(X)))

# endif

#define EnterCriticalSection() CRITICAL_SECTION()
#define LeaveCriticalSection() END_OF_CRITICAL_SECTION()

#define EnterCriticalSectionEx(X) CRITICAL_SECTION_EX(X)
#define LeaveCriticalSectionEx(X) END_OF_CRITICAL_SECTION_EX(X)

// -------------------------------------------------------------------------- //

#define AtomicInc(X) \
{ \
    EnterCriticalSection(); \
    ##X++; \
    LeaveCriticalSection(); \
}

#define AtomicDec(X) \
{ \
    EnterCriticalSection(); \
    ##X--; \
    LeaveCriticalSection(); \
}

// -------------------------------------------------------------------------- //
# endif // End of Include Guard //
