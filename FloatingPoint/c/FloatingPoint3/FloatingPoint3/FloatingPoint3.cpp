// FloatingPoint3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    float a = 999999.9999f;
    float b = 8388608.6f;
    printf("%f %f\n", a, b);

    a = 999999.9375f;
    b = 8388608.4f;
    printf("%f %f\n", a, b);

    printf("0.000989 is %.20f\n", 0.000989f);

    return 0;
}

