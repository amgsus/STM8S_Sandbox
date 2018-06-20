// ************************************************************************** //
// ***      STM8S QUICK START PROJECT & SANDBOX                           *** //
// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      Project:    STM8S_Sandbox                                     *** //
// ***      Module:     main                                              *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Toolchain:  CXSTM8                                            *** //
// ***      Created:    Jun 17, 2018 09:22 PM                             *** //
// ***      Modified:   Jun 20, 2018 10:05 PM                             *** //
// ***      Revision:   18w24a                                            *** //
// ************************************************************************** //

#include "platform.h"
#include "serial.h"

extern void init(void); // Declared in 'program.c'
extern void loop(void); // Declared in 'program.c'
extern void SetupSYSCLK(void); // Declared in 'clk_setup.c'

#ifdef USING_CLION
int mai_()
#else
main()
#endif
{
    SetupSYSCLK();

#if ENABLE_SERIAL_INTERFACE
    SetupPinAsPP(PD, 5); // UART1_TX
    SetupPinAsFloatingInput(PD, 6); // UART1_RX
    InitUART();
    EnableInterrupts();
#endif

    init();
    do { loop(); } while (1);
}