/* ee-2.9-991111 matched TU. */

extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern int D_00786648;
extern char D_00451078[];
extern char D_00460DA0[];
extern void func_0031F4A0();

__attribute__((section(".text.func_0031F2C0")))
void *func_0031F2C0(void) {
    int *s0 = &D_00786648;
    if (!*s0) {
        func_0031F4A0();
        SetField_0_4_8_31EEA8(s0, &D_00451078, &D_00460DA0);
    }
    return s0;
}
