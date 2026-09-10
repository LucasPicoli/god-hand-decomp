/* cygnus-2.96 matched TU. */

typedef struct D {
    char pad0[0x80];
    void *f80;
} D;


extern void func_00397450(D *d, void *p, int n);

__attribute__((section(".text.MWSPR_RestoreSprMem")))
int MWSPR_RestoreSprMem(void *dst, int size, void *src)
{
    D *d;

    d = func_00397100(9);
    d->f80 = src;
    func_00397450(d, dst, size / 16);
    return 0;
}
