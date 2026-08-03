/* ee-2.9-991111 matched TU. */

extern void *D_00786718;
extern char D_0045D1F7[];
extern char D_0045D208[];
extern void func_0038C0D8();
extern void __rtti_class(void *a, void *b, void *c, int d);
extern char D_0045D20F[];

/* clone */







__attribute__((section(".text.func_0038A7E0")))
void *func_0038A7E0(void) {
    void **s0 = (void **)&D_00786718;
    if (*s0 == 0) {
        func_0038C0D8();
        __rtti_class(s0, (D_0045D20F+0x1), D_0045D208, 1);
    }
    return s0;
}
