#ifndef _TEST_1_H
#define _TEST_1_H

#ifdef __cplusplus
extern "C"{
#endif

#define HAL_MODULE_INFO_SYM         HMI
#define HAL_MODULE_INFO_SYM_AS_STR  "HMI"

struct pz_struct_t {
    int (*pz_add)(int a, int b);
    float (*pz_sub)(float a, float b);
};

#ifdef __cplusplus
}
#endif

#endif
