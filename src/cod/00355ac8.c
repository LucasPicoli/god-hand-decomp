/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct ViBuf {
    unsigned char *base;
    unsigned int tagp;
    int nblk;
    int rd;
    int rdofs;
    int wr;
    int size;
    unsigned char pad1C[0x40 - 0x1C];
    int sema;
} ViBuf;

extern int WaitSema(int sid);
extern int SignalSema(int sid);

__attribute__((section(".text.viBufBeginPut")))
int viBufBeginPut(ViBuf *b, unsigned char **d0, int *n0,
                  unsigned char **d1, int *n1)
{
    int ofs;
    int n;
    int m;
    int t;
    int rd;
    int rdofs;
    int wr;
    int size;
    int nblk;
    unsigned char *base;

    WaitSema(b->sema);
    rd = b->rd;
    rdofs = b->rdofs;
    wr = b->wr;
    size = b->size;
    nblk = b->nblk;
    ofs = (((rd + rdofs) << 11) + wr) % size;
    t = ((nblk - rdofs) << 11) - 0x1000;
    m = t - wr;
    n = size - ofs;
    if (n >= m) {
        *n0 = m;
        *d0 = b->base + ofs;
        *d1 = 0;
        *n1 = 0;
    } else {
        *n0 = n;
        base = b->base;
        *d0 = base + ofs;
        *d1 = base;
        *n1 = m - (b->size - ofs);
    }
    return SignalSema(b->sema);
}
