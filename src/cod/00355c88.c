/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct ViBuf {
    /* 0x00 */ unsigned int base;
    /* 0x04 */ unsigned int tagp;
    /* 0x08 */ int nblk;
    /* 0x0C */ int rd;
    /* 0x10 */ int rdofs;
    /* 0x14 */ int wr;
    /* 0x18 */ int size;
    /* 0x1C */ unsigned char pad1C[0x40 - 0x1C];
    /* 0x40 */ int sema;
    /* 0x44 */ int active;
} ViBuf;

extern int WaitSema(int sid);
extern int SignalSema(int sid);
extern void func_00355880(unsigned int chcr);
extern int getFIFOindex(ViBuf *b, unsigned int madr);
extern void scTag2(void *p, unsigned int a, unsigned int b, unsigned int c);

#define D4_CHCR (*(volatile unsigned int *) 0x1000B400)
#define D4_MADR (*(volatile unsigned int *) 0x1000B410)

__attribute__((section(".text.viBufAddDMA")))
int viBufAddDMA(ViBuf *b)
{
    int flag = 0;
    unsigned int chcr;
    unsigned int madr;
    int idx;
    int cnt;
    int cur;
    int q;
    int id;
    int nb;
    int i;
    int prev;

    WaitSema(b->sema);
    if (b->active == 0) {
        SignalSema(b->sema);
        return 0;
    }
    func_00355880(5);
    chcr = D4_CHCR;
    madr = D4_MADR;
    idx = getFIFOindex(b, madr);
    cnt = (idx + b->nblk - b->rd) % b->nblk;
    b->rd = (b->rd + cnt) % b->nblk;
    b->rdofs = b->rdofs - cnt;
    q = (b->rd + b->rdofs) % b->nblk;
    nb = b->wr / 0x800;
    b->wr = b->wr % 0x800;
    if (nb > 0) {
        prev = (b->rd + b->rdofs + b->nblk - 1) % b->nblk;
        flag = 1;
        scTag2((char *) b->tagp + prev * 16, b->base + (prev << 11), 3, 0x80);
    }
    cur = q;
    for (i = 0; i < nb; i++) {
        id = (i != nb - 1) ? 3 : 0;
        scTag2((char *) b->tagp + cur * 16, b->base + (cur << 11), id, 0x80);
        cur = (cur + 1) % b->nblk;
    }
    b->rdofs = b->rdofs + nb;
    if (b->rdofs != 0) {
        if (flag != 0) {
            chcr = (chcr & 0x0FFFFFFF) | 0x30000000;
        }
        func_00355880(chcr | 0x100);
    }
    SignalSema(b->sema);
    return 1;
}
