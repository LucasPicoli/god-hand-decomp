typedef struct SfdRange {
    int pos;
    int len;
} SfdRange;

typedef struct SfdRangeHdr {
    int unk0;
    int size;
    SfdRange rng;
    char pad10[0x18];
    int unit;
} SfdRangeHdr;

typedef struct SfdBufPtr {
    int w[8];
} SfdBufPtr;

extern void sfbuf_MakeBufPtr(SfdBufPtr *bp, SfdRange *rng, int size);
extern int sfbuf_InitRingSj(void *sfb, SfdBufPtr *bp, SfdRange *rng, int idx, int n);
extern void sfbuf_InitVfrmBuf(void *sfd, void *sfb, SfdBufPtr *bp, SfdRange *rng, int idx);
extern void sfbuf_InitAringBuf(void *sfb, SfdBufPtr *bp, SfdRange *rng, int idx);
extern void sfbuf_InitUoSjBuf(void *sfb, SfdBufPtr *bp, SfdRange *rng, int idx);

__attribute__((section(".text.SFBUF_InitHn")))
int SFBUF_InitHn(void *sfd, void *sfb, SfdRangeHdr *h)
{
    SfdBufPtr bp;
    SfdRange *rng = &h->rng;
    int r;

    sfbuf_MakeBufPtr(&bp, rng, h->size);
    r = sfbuf_InitRingSj(sfb, &bp, rng, 0, rng->pos % h->unit);
    if (r != 0)
        return r;
    r = sfbuf_InitRingSj(sfb, &bp, rng, 1, 0x800);
    if (r != 0)
        return r;
    r = sfbuf_InitRingSj(sfb, &bp, rng, 2, 0);
    if (r != 0)
        return r;
    sfbuf_InitVfrmBuf(sfd, sfb, &bp, rng, 3);
    sfbuf_InitAringBuf(sfb, &bp, rng, 4);
    sfbuf_InitVfrmBuf(sfd, sfb, &bp, rng, 5);
    sfbuf_InitAringBuf(sfb, &bp, rng, 6);
    sfbuf_InitUoSjBuf(sfb, &bp, rng, 7);
    return 0;
}
