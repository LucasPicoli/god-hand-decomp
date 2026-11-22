/* ee-2.9-991111 matched TU. */
#include "godhand/globals.h"

extern char D_00460DA0[];
extern void func_0031F4A0();
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

__attribute__((section(".text.func_00320110")))
void *func_00320110(void) {
    int *s0 = &D_007866C8;
    if (!*s0) {
        func_0031F4A0();
        SetField_0_4_8_31EEA8(s0, &D_00451228, &D_00460DA0);
    }
    return s0;
}

__attribute__((section(".text.func_00320180")))
void *func_00320180(void) {
    int *s0 = &D_007866D8;
    if (!*s0) {
        func_0031F4A0();
        SetField_0_4_8_31EEA8(s0, &D_00451240, &D_00460DA0);
    }
    return s0;
}
