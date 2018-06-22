//int map_i2i(int x, int srcDimMin, int srcDimMax, int dstDimMin, int dstDimMax)
//{
//    return (x - srcDimMin) * (dstDimMax - dstDimMin) / (srcDimMax - srcDimMin) + dstDimMin;
//}

int map_i2i(int x, int srcDimMin, int srcDimMax, int dstDimMin, int dstDimMax)
{
    float a;
    int range;

    if (x < srcDimMin)
        x = srcDimMin;
    else if (x > srcDimMax)
        x = srcDimMax;

    a = (float)(x - srcDimMin) / (float)(srcDimMax - srcDimMin);
    range = dstDimMax - dstDimMin;
    return dstDimMin + (int)(a * range);
}