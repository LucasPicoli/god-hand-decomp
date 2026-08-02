/* ee-2.9-991111 matched TU. */

extern int D_00786638;
extern char D_00451048[];
extern char D_00786648[];
extern void func_0031F2C0();
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern int D_00786658;
extern char D_00451060[];
extern int D_00786668;
extern char D_00451090[];
extern char D_00460DA8[];
extern void func_003218F8();
extern int D_00786678;
extern char D_004510A0[];

__attribute__((section(".text.func_0031F1A8")))
void *func_0031F1A8(void) {
    int *s0 = &D_00786638;
    if (!*s0) {
        func_0031F2C0();
        SetField_0_4_8_31EEA8(s0, &D_00451048, &D_00786648);
    }
    return s0;
}

__attribute__((section(".text.func_0031F238")))
void *func_0031F238(void) {
    int *s0 = &D_00786658;
    if (!*s0) {
        func_0031F2C0();
        SetField_0_4_8_31EEA8(s0, &D_00451060, &D_00786648);
    }
    return s0;
}

__attribute__((section(".text.func_0031F378")))
void *func_0031F378(void) {
    int *s0 = &D_00786668;
    if (!*s0) {
        func_003218F8();
        SetField_0_4_8_31EEA8(s0, &D_00451090, &D_00460DA8);
    }
    return s0;
}

__attribute__((section(".text.func_0031F410")))
void *func_0031F410(void) {
    int *s0 = &D_00786678;
    if (!*s0) {
        func_003218F8();
        SetField_0_4_8_31EEA8(s0, &D_004510A0, &D_00460DA8);
    }
    return s0;
}
