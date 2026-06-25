/* sn-2.95.3-136 matched TU. */

extern void GetOrInitSingletonB_138B78(void);
extern void SetField_0_4_8_31EEA8(void *a0, void *a1, void *a2);
extern int D_00785578;
extern int D_0041D920;
extern int D_00460D20;
extern int D_00785588;
extern int D_0041D950;

__attribute__((section(".text.func_00139820")))
void *func_00139820(void) {
    int *s0 = &D_00785578;
    if (!*s0) {
        GetOrInitSingletonB_138B78();
        SetField_0_4_8_31EEA8(s0, &D_0041D920, &D_00460D20);
    }
    return s0;
}

__attribute__((section(".text.func_00139B78")))
void *func_00139B78(void) {
    int *s0 = &D_00785588;
    if (!*s0) {
        GetOrInitSingletonB_138B78();
        SetField_0_4_8_31EEA8(s0, &D_0041D950, &D_00460D20);
    }
    return s0;
}
