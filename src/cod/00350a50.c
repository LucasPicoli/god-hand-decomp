/* cygnus-2.96 matched TU. */

extern int WaitSema(int sid);
extern int SignalSema(int sid);
extern void setD3_CHCR(unsigned int chcr);

/* cygnus-2.96 matched TU. */

typedef struct {
    int f0;
    unsigned char pad4[0x7C - 4];
    int f7C;
} SfCond;

typedef struct {
    int f0;
    unsigned char pad4[0x114 - 4];
    int f114;
} SfSrc;

extern int func_00351C00(void *hn);                    /* sfmpv_GetTermSrc */
extern void func_0036A1D8(int h, unsigned int *rate);  /* MPV_GetBitRate */
extern int func_0034C7F0(void *hn, int f);             /* SFBUF_GetWTot */
extern int Obj35C0_IsIndexedSet_1F3C_C380(void *hn, int f);   /* SFTRN_IsSetup */
extern int func_0034C7B0(void *hn, int f);             /* SFBUF_GetRingBufSiz */

__attribute__((section(".text.func_00350A50")))
int func_00350A50(char *hn)
{
    SfCond *cond = (SfCond *) (hn + 0x78);
    SfSrc *src = *(SfSrc **) (hn + 0x1FC0);
    int h = src->f0;
    unsigned int rate;
    int f;

    if (func_00351C00(hn) == 1)
        return 1;
    if (cond->f0 != 0 && cond->f7C == 0)
        return 1;
    func_0036A1D8(h, &rate);
    if (rate == 0x3FFFF)
        return 1;
    if (func_0034C7F0(hn, 1) >= src->f114)
        return 1;
    f = Obj35C0_IsIndexedSet_1F3C_C380(hn, 1) == 0;
    if (func_0034C7F0(hn, f) < func_0034C7B0(hn, f))
        return 0;
    return 1;
}

/* cygnus-2.96 matched TU. */

typedef struct {
    /* 0x00 */ unsigned int base;
    /* 0x04 */ unsigned int tagp;
    /* 0x08 */ int nblk;
    /* 0x0C */ int rd;
    /* 0x10 */ int rdofs;
    /* 0x14 */ int wr;
    /* 0x18 */ int size;
    /* 0x1C */ unsigned int f1C;
    /* 0x20 */ unsigned int f20;
    /* 0x24 */ unsigned int f24;
    /* 0x28 */ unsigned int f28;
    /* 0x2C */ unsigned int f2C;
    /* 0x30 */ unsigned int f30;
    /* 0x34 */ unsigned int f34;
    /* 0x38 */ unsigned int f38;
    /* 0x3C */ unsigned int f3C;
    /* 0x40 */ int sema;
    /* 0x44 */ int active;
    /* 0x48 */ long long total;
    /* 0x50 */ void *ent;
    /* 0x54 */ int nent;
    /* 0x58 */ int f58;
    /* 0x5C */ int f5C;
} ViBuf;



extern void func_00355880(unsigned int chcr);   /* setD4_CHCR */


#define D3_CHCR    (*(volatile unsigned int *) 0x1000B000)
#define D3_MADR    (*(volatile unsigned int *) 0x1000B010)
#define D3_QWC     (*(volatile unsigned int *) 0x1000B020)
#define D4_CHCR    (*(volatile unsigned int *) 0x1000B400)
#define D4_MADR    (*(volatile unsigned int *) 0x1000B410)
#define D4_QWC     (*(volatile unsigned int *) 0x1000B420)
#define D4_TADR    (*(volatile unsigned int *) 0x1000B430)
#define VIF1_STAT  (*(volatile unsigned int *) 0x10002010)
#define VIF1_FBRST (*(volatile unsigned int *) 0x10002020)

__attribute__((section(".text.func_00355E88")))
int func_00355E88(ViBuf *b)
{
    WaitSema(b->sema);
    b->active = 0;
    func_00355880(5);
    b->f1C = D4_MADR;
    b->f20 = D4_TADR;
    b->f24 = D4_QWC;
    b->f28 = D4_CHCR;
    while ((VIF1_STAT & 0xF0) != 0) {
    }
    setD3_CHCR(0);
    b->f2C = D3_MADR;
    b->f30 = D3_QWC;
    b->f34 = D3_CHCR;
    b->f38 = VIF1_FBRST;
    b->f3C = VIF1_STAT;
    SignalSema(b->sema);
    return 1;
}
