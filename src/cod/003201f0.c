/* ee-2.9-991111 matched TU. */

extern int D_007866E8;
extern char D_00451258[];
extern char D_00460DA0[];
extern void func_0031F4A0();
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

__attribute__((section(".text.func_003201F0")))
void *func_003201F0(void) {
    int *s0 = &D_007866E8;
    if (!*s0) {
        func_0031F4A0();
        SetField_0_4_8_31EEA8(s0, &D_00451258, &D_00460DA0);
    }
    return s0;
}
