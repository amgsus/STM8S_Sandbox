#ifndef SERIAL_H
#define SERIAL_H

#include "stdint.h"
#include "stdbool.h"

#ifndef SERIAL_PERIPH
#   ifdef STM8S103F3_MCU
#       define SERIAL_PERIPH 1
#   else
#       error "Unknown MCU! Please, specify SERIAL_PERIPH manually."
#   endif
# endif

#ifndef SERIAL_TX_BUFFER_SIZE
#   define SERIAL_TX_BUFFER_SIZE 32u
# endif

#ifndef SERIAL_RX_BUFFER_SIZE
#   define SERIAL_RX_BUFFER_SIZE 32u
# endif

#ifndef SERIAL_BAUDRATE
#   define SERIAL_BAUDRATE  9600
# endif

typedef uint8_t RxSize_t;
typedef uint8_t TxSize_t;

void InitUART(void);

char S_Get(void);
bool S_Put(char byte);
RxSize_t S_HowMuchAvailable(void);
char S_Peek(void);
TxSize_t S_HowMuchFree(void);
char S_PeekAt(RxSize_t index);
int S_Find(char charToFind, RxSize_t searchDepth);
RxSize_t S_Drop(RxSize_t bytesToDrop);
TxSize_t S_Write(const char *buffer, TxSize_t count);
RxSize_t S_Read(char *buffer, RxSize_t bufSize);
TxSize_t S_WriteAwait(const char *buffer, TxSize_t count);
TxSize_t S_Print(char *s);

# endif // End of Include Guard //
