#include "test1.h"

int pz_add(int a, int b)
{
    return a+b;
}

float pz_sub(float a, float b)
{
    return a-b;
}

struct pz_struct_t HAL_MODULE_INFO_SYM = {
	.pz_add = pz_add,
	.pz_sub = pz_sub,
};


