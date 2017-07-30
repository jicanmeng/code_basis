// FloatingPoint1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
    int num = 9;
    float* pFloat = (float *)&num;

    printf("sizeof(int) is %d, sizeof(float) is %d\n",
        sizeof(int), sizeof(float));
    printf("value of num is %d\n", num);
    printf("value of *pFloat is %f\n", *pFloat);

    *pFloat = 9.0;
    printf("value of num is %d\n", num);
    printf("value of *pFloat is %f\n", *pFloat);

    return 0;
}

