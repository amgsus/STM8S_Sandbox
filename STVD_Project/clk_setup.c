#include "platform.h"

#if HSI_DIV_FACTOR == 1
#   define HSI_DIV_FACTOR_VALUE 0
#elif HSI_DIV_FACTOR == 2
#   define HSI_DIV_FACTOR_VALUE 1
#elif HSI_DIV_FACTOR == 4
#   define HSI_DIV_FACTOR_VALUE 2
#elif HSI_DIV_FACTOR == 8
#   define HSI_DIV_FACTOR_VALUE 3
#else
#   define HSI_DIV_FACTOR_VALUE 3   /* Default */
#   warning "Specified HSI_DIV_FACTOR is not supported!"
#endif

#if F_CPU_DIV_FACTOR == 1
#   define F_CPU_DIV_FACTOR_VALUE 0
#elif F_CPU_DIV_FACTOR == 2
#   define F_CPU_DIV_FACTOR_VALUE 1
#elif F_CPU_DIV_FACTOR == 4
#   define F_CPU_DIV_FACTOR_VALUE 2
#elif F_CPU_DIV_FACTOR == 8
#   define F_CPU_DIV_FACTOR_VALUE 3
#elif F_CPU_DIV_FACTOR == 16
#   define F_CPU_DIV_FACTOR_VALUE 4
#elif F_CPU_DIV_FACTOR == 32
#   define F_CPU_DIV_FACTOR_VALUE 5
#elif F_CPU_DIV_FACTOR == 64
#   define F_CPU_DIV_FACTOR_VALUE 6
#elif F_CPU_DIV_FACTOR == 128
#   define F_CPU_DIV_FACTOR_VALUE 7
#else
#   define F_CPU_DIV_FACTOR_VALUE 0 /* Default */
#   warning "Specified F_CPU_DIV_FACTOR is not supported!"
#endif

void SetupSYSCLK()
{
    CLK_CKDIVR = (HSI_DIV_FACTOR_VALUE << 3) | (F_CPU_DIV_FACTOR_VALUE);
}