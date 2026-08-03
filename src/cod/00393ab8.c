/* ee-2.9-991111 matched TU. */

extern void *D_786788;
extern char D_0045D1F7[];
extern char D_0045DB88[];
extern void func_0038A7E0();
extern void __rtti_class(void *a, void *b, void *c, int d);
extern char D_0045DB78[];
extern void *D_786798;
extern char D_0045DBA0[];
extern void func_0038A340();
extern char D_0045DB8F[];
extern int D_7867A8;
extern char D_0045DBA8[];
extern char D_786768[];
extern void func_0038B8B0();
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

/* clone */







__attribute__((section(".text.func_00393AB8")))
void *func_00393AB8(void) {
    void **s0 = (void **)&D_786788;
    if (*s0 == 0) {
        func_0038A7E0();
        __rtti_class(s0, (D_0045DB78), D_0045DB88, 1);
    }
    return s0;
}

/* clone */







__attribute__((section(".text.func_00393DD0")))
void *func_00393DD0(void) {
    void **s0 = (void **)&D_786798;
    if (*s0 == 0) {
        func_0038A340();
        __rtti_class(s0, (D_0045DB8F+0x1), D_0045DBA0, 1);
    }
    return s0;
}

/* clone */






__attribute__((section(".text.func_00393F30")))
void *func_00393F30(void) {
    int *s0 = &D_7867A8;
    if (!*s0) {
        func_0038B8B0();
        SetField_0_4_8_31EEA8(s0, &D_0045DBA8, &D_786768);
    }
    return s0;
}
