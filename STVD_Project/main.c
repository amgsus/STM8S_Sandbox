// ************************************************************************** //
// ***      STM8S QUICK START PROJECT & SANDBOX                           *** //
// ************************************************************************** //
// ***      Author:     A.G. [ http://github.com/amgsus ]                 *** //
// ***      Project:    STM8S_Sandbox                                     *** //
// ***      Module:     main                                              *** //
// ***      MCU:        STM8S103F3                                        *** //
// ***      Toolchain:  CXSTM8                                            *** //
// ***      Created:    Jun 17, 2018 09:22 PM                             *** //
// ***      Modified:   Jun 17, 2018 09:22 PM                             *** //
// ***      Revision:   18w24a                                            *** //
// ************************************************************************** //

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
    init();
    do { loop(); } while (1);
}