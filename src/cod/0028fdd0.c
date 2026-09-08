/* sn-2.95.3-136 matched TU. */

extern void __builtin_delete(void);
extern int D_00451038;
extern int D_007861D8;
extern int D_0044A750;
extern int D_007854D8;
extern void func_002A9300(void);
extern void SetField_0_4_8_31EEA8(int *, int *, int *);

__attribute__((section(".text.func_0031EE10")))
void func_0031EE10(void *a0, int a1) {
    *(int **)((char *)a0 + 4) = &D_00451038;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.func_0028FDD0")))
void *func_0028FDD0(void) {
    if (D_007861D8 == 0) {
        func_002A9300();
        SetField_0_4_8_31EEA8(&D_007861D8, &D_0044A750, &D_007854D8);
    }
    return &D_007861D8;
}
