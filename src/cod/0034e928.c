/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct {
    int f0;
    int f4;
    unsigned int f8;
    unsigned int fC;
    int f10;
    int f14;
} SjInf;

extern SjInf *func_0034E988(void *mps);   /* sfmps_GetSupSj */

__attribute__((section(".text.sfmps_IsEndOfRingBuf")))
int sfmps_IsEndOfRingBuf(void *mps, unsigned int p)
{
    SjInf *r = func_0034E988(mps);

    if (r->f0 == 0 && (r->f10 != 0 || r->f14 != 0))
        return 0;
    return p == r->f8 + r->fC;
}
