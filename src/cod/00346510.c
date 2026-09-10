/* cygnus-2.96 matched TU. */

typedef struct D {
    char pad0[0x80];
    void *f80;
} D;


extern void func_003974D0(D *d, void *p, int n);

__attribute__((section(".text.MWSPR_SaveSprMem")))
int MWSPR_SaveSprMem(void *dst, int size, void *src)
{
    D *d;

    d = func_00397100(8);
    d->f80 = dst;
    func_003974D0(d, src, size / 16);
    return 0;
}
