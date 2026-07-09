/* cygnus-2.96 matched TU. */

extern void func_0036DD18(void *);
extern void func_0036D320(void *);
extern void *memcpy(void *, const void *, unsigned int);
extern char D_0076A590;

__attribute__((section(".text.func_0036D460")))
void *func_0036D460(char *o) {
    memcpy(o + 0x18, &D_0076A590, 0x40);
    func_0036DD18(o);
    func_0036D320(o + 0x58);
    *(int *)(o + 0x118) = 0;
    *(int *)(o + 0x0) = 2;
    return o;
}
