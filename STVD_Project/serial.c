// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      Project:    STM8S_Sandbox                                     *** //
// ***      Module:     serial                                            *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Toolchain:  CXSTM8                                            *** //
// ***      Created:    Jun 19, 2018 04:18 PM                             *** //
// ***      Modified:   Jun 20, 2018 11:36 PM                             *** //
// ************************************************************************** //

#include <string.h>
#include <stdlib.h>

#include "platform.h"
#include "serial.h"

// ToDo: Requires refactoring.

#define CONCAT(a, b) a##b
#define C(a, b) CONCAT(a, b)
#define _3 UART
#define _2 C(_3, SERIAL_PERIPH)
#define _1 C(_2, _)
#define REG(name) C(_1, name)

#define UARTx_DR    REG(DR)
#define UARTx_SR    REG(SR)
#define UARTx_BRR1  REG(BRR1)
#define UARTx_BRR2  REG(BRR2)
#define UARTx_CR1   REG(CR1)
#define UARTx_CR2   REG(CR2)
#define UARTx_CR3   REG(CR3)

#define _UART_DIV     \
    ((uint16_t) ((float)(F_MASTER) / (float)(SERIAL_BAUDRATE) + 0.5))
#define _PRECALC_BRR2 \
    ((((_UART_DIV) & 0xF000) >> 8) | ((_UART_DIV) & 0x000F))
#define _PRECALC_BRR1 \
    ((((_UART_DIV) & 0x0FF0) >> 4))

#define DECLARE_CRITICAL(cs) volatile uint8_t cs = 0

#define SERIAL_ENTER_TX_CRITICAL(cs) \
    do { \
        cs = UARTx_CR2 & UART_TIEN; \
        if (cs) { \
            CLEAR(UARTx_CR2, UART_TIEN); \
        } \
    } while (0)

#define SERIAL_LEAVE_TX_CRITICAL(cs) \
    do { \
        if (cs) { \
            SET(UARTx_CR2, UART_TIEN); \
        } \
    } while (0)

#define SERIAL_ENTER_RX_CRITICAL(cs) \
    do { \
        CLEAR(UARTx_CR2, UART_RIEN); \
    } while (0)

#define SERIAL_LEAVE_RX_CRITICAL(cs) \
    do { \
        SET(UARTx_CR2, UART_RIEN); \
    } while (0)

#define StartTransmission() \
    do { \
        SET(UARTx_CR2, UART_TIEN); \
    } while (0)

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define LIMIT_VALUE(variable, threshold_value) \
    do { \
        if (variable > (threshold_value)) { \
            variable = (threshold_value); \
        } \
    } while (0)

#define MASK(size) ((size) - 1)
#define IX(start, count, size) (((start) + (count)) & MASK(size))
#define INC(ix, size) do { ix = IX(ix, 1, size); } while (0)

static volatile char     TxBuffer[SERIAL_TX_BUFFER_SIZE+2];
static volatile TxSize_t TxBufferHead;
static volatile TxSize_t TxBufferTail;
static volatile TxSize_t TxBufferLength;

static volatile char     RxBuffer[SERIAL_RX_BUFFER_SIZE+2];
static volatile RxSize_t RxBufferHead;
static volatile RxSize_t RxBufferTail;
static volatile RxSize_t RxBufferLength;

void InitUART(void)
{
    TxBufferHead = 0;
    TxBufferTail = 0;
    TxBufferLength = 0;
    RxBufferHead = 0;
    RxBufferTail = 0;
    RxBufferLength = 0;

    UARTx_BRR2 = _PRECALC_BRR2;
    UARTx_BRR1 = _PRECALC_BRR1;
    UARTx_CR1  = 0x00;
    UARTx_CR3  = 0x00;
    UARTx_CR2  = UART_TEN | UART_REN | UART_RIEN;
}

char S_Get(void)
{
    char x = 0;
    DECLARE_CRITICAL(cs);

    SERIAL_ENTER_RX_CRITICAL(cs);
    if (RxBufferLength) {
        x = RxBuffer[RxBufferTail];
        INC(RxBufferTail, SERIAL_RX_BUFFER_SIZE);
        RxBufferLength--;
    }
    SERIAL_LEAVE_RX_CRITICAL(cs);

    return x;
}

bool S_Put(char x)
{
    bool r = false;
    DECLARE_CRITICAL(cs);

    SERIAL_ENTER_TX_CRITICAL(cs);
    if (TxBufferLength != SERIAL_TX_BUFFER_SIZE) {
        TxBuffer[TxBufferHead] = x;
        INC(TxBufferHead, SERIAL_TX_BUFFER_SIZE);
        TxBufferLength++;
        r = true;
        StartTransmission();
    }
    SERIAL_LEAVE_TX_CRITICAL(cs);

    return r;
}

RxSize_t S_HowMuchAvailable(void)
{
    RxSize_t n;
    DECLARE_CRITICAL(cs);
    SERIAL_ENTER_RX_CRITICAL(cs);
    n = RxBufferLength;
    SERIAL_LEAVE_RX_CRITICAL(cs);
    return n;
}

char S_Peek(void)
{
    if ( S_HowMuchAvailable()) {
        return RxBuffer[RxBufferTail];
    }

    return 0;
}

TxSize_t S_HowMuchFree(void)
{
    TxSize_t n;
    DECLARE_CRITICAL(cs);
    SERIAL_ENTER_TX_CRITICAL(cs);
    n = TxBufferLength;
    SERIAL_LEAVE_TX_CRITICAL(cs);
    return SERIAL_TX_BUFFER_SIZE - n;
}

char S_PeekAt(RxSize_t index)
{
    if ( index < S_HowMuchAvailable()) {
        return RxBuffer[IX(RxBufferTail, index, SERIAL_RX_BUFFER_SIZE)];
    }

    return 0;
}

RxSize_t S_Drop(RxSize_t bytesToDrop)
{
    DECLARE_CRITICAL(cs);
    RxSize_t availableToRead;

    availableToRead = S_HowMuchAvailable();
    LIMIT_VALUE(bytesToDrop, availableToRead);

    RxBufferTail = IX(RxBufferTail, bytesToDrop, SERIAL_RX_BUFFER_SIZE);
    SERIAL_ENTER_RX_CRITICAL(cs);
    RxBufferLength -= bytesToDrop;
    SERIAL_LEAVE_RX_CRITICAL(cs);

    return bytesToDrop;
}

int S_Find(char charToFind, RxSize_t searchDepth)
{
    RxSize_t i;
    RxSize_t available;

    available = S_HowMuchAvailable();
    LIMIT_VALUE(searchDepth, available);

    for ( i = 0; i < searchDepth; i++ ) {
        if (RxBuffer[IX(RxBufferTail, i, SERIAL_RX_BUFFER_SIZE)] == charToFind) {
            return i;
        }
    }

    return -1;
}

TxSize_t S_Write(const char *buffer, TxSize_t count)
{
    TxSize_t n;
    DECLARE_CRITICAL(cs);

    SERIAL_ENTER_TX_CRITICAL(cs);
    n = SERIAL_TX_BUFFER_SIZE - TxBufferLength; // Remaining free space.
    SERIAL_LEAVE_TX_CRITICAL(cs);

    count = MIN(n, count);

    if (count)
    {
        n = count;

        while (n) {
            TxBuffer[TxBufferHead] = *buffer;
            INC(TxBufferHead, SERIAL_TX_BUFFER_SIZE);
            buffer++;
            n--;
        }

        SERIAL_ENTER_TX_CRITICAL(cs);
        TxBufferLength += count;
        SERIAL_LEAVE_TX_CRITICAL(cs);

        StartTransmission();
    }

    return count;
}

RxSize_t S_Read(char *buffer, RxSize_t bufSize)
{
    RxSize_t n;
    DECLARE_CRITICAL(cs);

    SERIAL_ENTER_RX_CRITICAL(cs);
    n = RxBufferLength;
    SERIAL_LEAVE_RX_CRITICAL(cs);

    bufSize = MIN(n, bufSize);

    if (bufSize)
    {
        n = bufSize;

        while (n) {
            *buffer = RxBuffer[RxBufferTail];
            INC(RxBufferTail, SERIAL_RX_BUFFER_SIZE);
            buffer++;
            n--;
        }

        SERIAL_ENTER_RX_CRITICAL(cs);
        RxBufferLength -= bufSize;
        SERIAL_LEAVE_RX_CRITICAL(cs);
    }

    return bufSize;
}

TxSize_t S_WriteAwait(const char *buffer, TxSize_t count)
{
    TxSize_t i = 0;

    do {
        if (i) {
            // Чтобы не пытался "ломиться" в буфер!!! Обождите немного,
            // дайте времени прерыванию UART'а отработать и прожевать часть
            // данных. Другие подождут...
            // delay_ms(1);
        }
        i += S_Write(&(buffer[i]), count - i);
    } while (i != count);

    return i;
}

TxSize_t S_Print(char *s)
{
    size_t len;
    len = strlen(s);
    S_WriteAwait(s, len);
}

// -------------------------------------------------------------------------- //

ISR(UART_RequestToTransmit_ISR)
{
    if (UARTx_SR & UART_TXE) {
        if (TxBufferLength) {
            UARTx_DR = TxBuffer[TxBufferTail];
            INC(TxBufferTail, SERIAL_TX_BUFFER_SIZE);
            TxBufferLength--;
        } else {
            if (UARTx_SR & UART_TC) {
                CLEAR(UARTx_CR2, UART_TIEN);
            }
        }
    }
}

ISR(UART_DataRecept_ISR)
{
    char data;

    if (UARTx_SR & UART_RXNE) {
        data = UARTx_DR;
        if (RxBufferLength != SERIAL_RX_BUFFER_SIZE) {
            RxBuffer[RxBufferHead] = data;
            INC(RxBufferHead, SERIAL_RX_BUFFER_SIZE);
            RxBufferLength++;
        }
    }
}