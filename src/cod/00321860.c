/* ee-2.9-991111 matched TU. */

extern int D_007866F8;
extern char D_004512A0[];
extern char D_00460DA8[];
extern void func_003218F8();
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

__attribute__((section(".text.func_00321860")))
void *func_00321860(void) {
    int *s0 = &D_007866F8;
    if (!*s0) {
        func_003218F8();
        SetField_0_4_8_31EEA8(s0, &D_004512A0, &D_00460DA8);
    }
    return s0;
}
