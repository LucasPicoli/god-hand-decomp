/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct {
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
    /* 0x48 */ long long total;
    /* 0x50 */ void *ent;
    /* 0x54 */ int nent;
    /* 0x58 */ int f58;
    /* 0x5C */ int f5C;
} ViBuf;

typedef struct {
    /* 0x00 */ long long tag;
    /* 0x08 */ long long tag2;
    /* 0x10 */ int f10;
    /* 0x14 */ int f14;
} ViEnt;

extern void scTag2(void *p, unsigned int a, unsigned int b, unsigned int c);
extern void func_00355880(unsigned int chcr);   /* setD4_CHCR */

#define D4_MADR (*(volatile unsigned int *) 0x1000B410)
#define D4_QWC  (*(volatile unsigned int *) 0x1000B420)
#define D4_TADR (*(volatile unsigned int *) 0x1000B430)

__attribute__((section(".text.viBufReset")))
int viBufReset(ViBuf *b)
{
    ViEnt *e;
    int i;
    unsigned int madr;
    unsigned int tadr;
    volatile unsigned int *qwc;

    b->active = 1;
    b->rd = 0;
    b->rdofs = 0;
    b->wr = 0;
    b->f58 = 0;
    b->f5C = 0;
    i = 0;
    if (b->nent > 0) {
        e = (ViEnt *) b->ent;
        do {
            e->f10 = 0;
            e->f14 = 0;
            e->tag = -1;
            e->tag2 = -1;
            i++;
            e++;
        } while (i < b->nent);
    }
    for (i = 0; i < b->nblk; i++) {
        scTag2((char *) b->tagp + i * 16,
               ((i << 11) + b->base) & 0x0FFFFFFF, 3, 0x80);
    }
    scTag2((char *) b->tagp + i * 16, b->tagp & 0x0FFFFFFF, 2, 0);
    qwc = (volatile unsigned int *) 0x1000B420;
    madr = b->base & 0x0FFFFFFF;
    tadr = b->tagp & 0x0FFFFFFF;
    *qwc = 0;
    D4_MADR = madr;
    D4_TADR = tadr;
    func_00355880(5);
    return 1;
}
