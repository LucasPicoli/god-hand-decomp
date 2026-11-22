/* cygnus-2.96 matched TU. */

typedef struct D {
    char pad0[0x80];
    void *sadr;                 /* 0x80 scratchpad address */
} D;


extern void sceDmaRecvN(D *d, void *p, int n);

/* Copy size bytes from scratchpad to dst over DMA channel 8 (fromSPR). */
__attribute__((section(".text.MWSPR_SaveSprMem")))
int MWSPR_SaveSprMem(void *sprAddr, int size, void *dst)
{
    D *d;

    d = sceDmaGetChan(8);
    d->sadr = sprAddr;
    sceDmaRecvN(d, dst, size / 16);
    return 0;
}
