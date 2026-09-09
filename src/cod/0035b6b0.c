/* cygnus-2.96 matched TU. */

typedef struct Tim {
    char pad0[0x38];
    int f38;
    char pad3c[0xB0 - 0x3C];
    int fB0;
} Tim;

extern void func_0035B6F8(void *p, int a1, int a2, int *out, int tunit);

__attribute__((section(".text.func_0035B6B0")))
int func_0035B6B0(char *p, int a1, int a2)
{
    int out;
    Tim *t;

    t = (Tim *)(p + 0xA0C);
    if (t->f38 != 0) return 1;
    func_0035B6F8(p, a1, a2, &out, t->fB0);
    return out;
}
