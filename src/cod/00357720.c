/* cygnus-2.96 matched TU. */

typedef struct Sub {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1c[0x3C - 0x1C];
    int f3C;
} Sub;

extern void func_0035A000(void *p, int a1, int a2);

__attribute__((section(".text.func_00357720")))
void func_00357720(char *p)
{
    Sub *s;

    s = (Sub *)(p + 0xA0C);
    if (s->f18 == 0 && s->f3C == 2) {
        func_0035A000(p, 0xF, 1);
    }
    if (s->f14 == 0 && s->f3C == 1) {
        func_0035A000(p, 0xF, 2);
    }
}
