/* ee-2.9-991111 matched TU. */

extern int D_00786698;
extern char D_004511E0[];
extern char D_00460DA0[];
extern void func_0031F4A0();
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern int D_007866A8;
extern char D_004511F8[];
extern int D_007866B8;
extern char D_00451210[];

__attribute__((section(".text.func_0031FFC0")))
void *func_0031FFC0(void) {
    int *s0 = &D_00786698;
    if (!*s0) {
        func_0031F4A0();
        SetField_0_4_8_31EEA8(s0, &D_004511E0, &D_00460DA0);
    }
    return s0;
}

__attribute__((section(".text.func_00320030")))
void *func_00320030(void) {
    int *s0 = &D_007866A8;
    if (!*s0) {
        func_0031F4A0();
        SetField_0_4_8_31EEA8(s0, &D_004511F8, &D_00460DA0);
    }
    return s0;
}

__attribute__((section(".text.func_003200A0")))
void *func_003200A0(void) {
    int *s0 = &D_007866B8;
    if (!*s0) {
        func_0031F4A0();
        SetField_0_4_8_31EEA8(s0, &D_00451210, &D_00460DA0);
    }
    return s0;
}
