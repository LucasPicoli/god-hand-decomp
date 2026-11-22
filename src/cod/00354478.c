/* cygnus-2.96: find the next MPEG delimiter in the stream's ring, advance past the bytes before it,
 * and count them as data when any of the first three is nonzero. */
typedef struct SfdRing {
    unsigned char *p0;  /* 0x00 */
    int n0;             /* 0x04 */
    unsigned char *p1;  /* 0x08 */
    int n1;             /* 0x0C */
    int pad10[2];
} SfdRing;

typedef struct SfdRingView {
    char pad0[0x9A8];
    long total;         /* 0x9A8 */
    long data;          /* 0x9B0 */
    char pad9B8[0x1FC8 - 0x9B8];
    int sj;             /* 0x1FC8 */
} SfdRingView;

extern int SFBUF_RingGetRead(SfdRingView *sf, int sj, SfdRing *r);
extern unsigned char *sfmpv_SearchDelim(SfdRing *r, int mask, int *found);
extern void sfmpv_RingAddRead(SfdRingView *sf, int n);

__attribute__((section(".text.sfmpv_GoDdelim")))
int sfmpv_GoDdelim(SfdRingView *sf, int unused, int mask)
{
    SfdRing r;
    int found;
    unsigned char *p;
    int n;
    int i;
    int nz;
    unsigned char *q;

    if (SFBUF_RingGetRead(sf, sf->sj, &r) != 0)
        return 0;
    if (r.n0 == 0)
        return 0;
    p = sfmpv_SearchDelim(&r, mask, &found);
    if (p == 0) {
        n = r.n0 + r.n1 - 3;
        if (n < 0)
            n = 0;
    } else if (p >= r.p0 && p < r.p0 + r.n0) {
        n = p - r.p0;
    } else if (p >= r.p1 && p < r.p1 + r.n1) {
        n = p - r.p1 + r.n0;
    } else {
        n = 0;
    }
    sfmpv_RingAddRead(sf, n);
    nz = 0;
    for (i = 0; i < (n < 4 ? n : 3); i++) {
        if (i < r.n0)
            q = r.p0 + i;
        else
            q = r.p1 + (i - r.n0);
        if (*(signed char *)q != 0) {
            nz = 1;
            break;
        }
    }
    if (nz)
        sf->data += n;
    sf->total += n;
    return n;
}
