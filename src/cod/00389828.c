/* ee-2.9-991111 matched TU. */

extern void *D_00786708;
extern char D_0045D188[];
extern char D_0045D1A8[];
extern void func_0038A7E0();
extern void __rtti_class(void *a, void *b, void *c, int d);

__attribute__((section(".text.func_00389828")))
void *func_00389828(void) {
    void **s0 = (void **)&D_00786708;
    if (*s0 == 0) {
        func_0038A7E0();
        __rtti_class(s0, D_0045D188, D_0045D1A8, 1);
    }
    return s0;
}
