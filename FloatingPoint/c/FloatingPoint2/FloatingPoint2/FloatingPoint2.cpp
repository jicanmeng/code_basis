// FloatingPoint2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <float.h>

int main()
{
    int a = 0x1;
    float *pF = (float *)&a;
    printf("%.60f\n", *pF);

    printf("%.60f\n", FLT_MIN);
    a = 0x00800000;
    printf("%.60f\n", *pF);

    printf("%.10f\n", FLT_MAX);
    a = 0x7f7fffff;
    printf("%.10f\n", *pF);

    printf("%.50f\n", FLT_EPSILON);

    return 0;
}

