/* ee-2.9-991111 matched TU. */

extern void *D_00786728;
extern char D_0045D1AF[];
extern char D_0045D1D0[];
extern void func_0038A340();
extern void __rtti_class(void *a, void *b, void *c, int d);

__attribute__((section(".text.func_00389980")))
void *func_00389980(void) {
    void **s0 = (void **)&D_00786728;
    if (*s0 == 0) {
        func_0038A340();
        __rtti_class(s0, (D_0045D1AF+0x1), D_0045D1D0, 1);
    }
    return s0;
}
