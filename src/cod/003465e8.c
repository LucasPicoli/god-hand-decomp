/* cygnus-2.96 matched TU. */

typedef struct D {
    char pad0[0x80];
    void *sadr;                 /* 0x80 scratchpad address */
} D;


extern void func_00397450(D *d, void *p, int n);

/* Copy size bytes from src into scratchpad over DMA channel 9 (toSPR). */
__attribute__((section(".text.MWSPR_RestoreSprMem")))
int MWSPR_RestoreSprMem(void *src, int size, void *sprAddr)
{
    D *d;

    d = func_00397100(9);
    d->sadr = sprAddr;
    func_00397450(d, src, size / 16);
    return 0;
}
