#include "comdefs.h"

int MapValue(int x, int srcDimMin, int srcDimMax, int dstDimMin, int dstDimMax)
{
    return (x - srcDimMin) * (dstDimMax - dstDimMin) / (srcDimMax - srcDimMin) + dstDimMin;
}

int MapValuePrecise(int x, int srcDimMin, int srcDimMax, int dstDimMin,
                    int dstDimMax)
{
    int range;
    float scale;

    ForceBounds(x, srcDimMin, srcDimMax);

    range = srcDimMax - srcDimMin;
    scale = (float)(x - srcDimMin) / (float)(range);

    range = dstDimMax - dstDimMin;
    return (dstDimMin + (int)(scale * range));
}