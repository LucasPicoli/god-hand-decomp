/* cygnus-2.96 matched TU. */

extern int D_003EE2F4;
extern unsigned char D_00766C28[0x48];
extern void sceMpegInit(void);
extern void func_003B63A0(void);
extern void func_003B63F0(void);
extern int WaitSema(int sid);
extern int SignalSema(int sid);

/* cygnus-2.96 matched TU. */





extern void Obj0000_Memset_Backward_366B80(void *p, int c, int n);   /* UTY_MemsetByte */

__attribute__((section(".text.SFMPVP_Init")))
void SFMPVP_Init(void)
{
    if (D_003EE2F4 != 0) {
        sceMpegInit();
        Obj0000_Memset_Backward_366B80(D_00766C28, 0, 0x48);
    }
}

/* cygnus-2.96 matched TU. */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
} SfMpvCond;

__attribute__((section(".text.func_00353500")))
int func_00353500(char *p, unsigned int ptype)
{
    SfMpvCond *c = (SfMpvCond *) (p + 0xA0C);

    int v;

    switch (ptype) {
    case 1: v = c->f8; break;
    case 2: v = c->fC; break;
    case 3: v = c->f10; break;
    default: return 1;
    }
    return v == 0;
}

/* cygnus-2.96 matched TU. */

typedef struct {
    unsigned char b[0x24];
    int cnt;
    int f28;
} Ttu;

__attribute__((section(".text.func_003538B0")))
void func_003538B0(char *p)
{
    Ttu *cur = (Ttu *) (p + 0xDF0);
    Ttu *nxt = cur + 1;

    if (cur->cnt < *(int *) (p + 0xE6C))
        *nxt = *cur;
}

/* cygnus-2.96 matched TU. */




#define D_ENABLER (*(volatile unsigned int *) 0x1000F520)
#define D_ENABLEW (*(volatile unsigned int *) 0x1000F590)

__attribute__((section(".text.func_00355880")))
void func_00355880(unsigned int chcr) {
    func_003B63A0();
    D_ENABLEW = D_ENABLER | 0x00010000;
    *(volatile unsigned int *) 0x1000B400 = chcr;
    D_ENABLEW = D_ENABLER & 0xFFFEFFFF;
    func_003B63F0();
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
    /* 0x1C */ unsigned char pad1C[0x40 - 0x1C];
    /* 0x40 */ int sema;
    /* 0x44 */ int active;
    /* 0x48 */ long long total;
    /* 0x50 */ void *ent;
    /* 0x54 */ int nent;
    /* 0x58 */ int f58;
    /* 0x5C */ int f5C;
} ViBuf;




__attribute__((section(".text.func_00355C08")))
int func_00355C08(ViBuf *b, int n)
{
    WaitSema(b->sema);
    b->wr -= n;
    b->total -= n;
    if (b->wr < 0) {
        for (;;) {
        }
    }
    SignalSema(b->sema);
    return n;
}
