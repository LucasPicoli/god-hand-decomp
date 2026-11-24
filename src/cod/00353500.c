/* cygnus-2.96 matched TU. */
#include "godhand/eeKernel.h"
#include "godhand/globals.h"
#include "godhand/sftim.h"

extern unsigned char D_00766C28[0x48];
extern void sceMpegInit(void);
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

__attribute__((section(".text.sfmpv_IsPtypeSkip")))
int sfmpv_IsPtypeSkip(char *p, unsigned int ptype)
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

__attribute__((section(".text.sfmpv_SetSkipTtu")))
void sfmpv_SetSkipTtu(SftimHn *hn)
{
    SftimRec *cur = &hn->tim.rec[3];
    SftimRec *nxt = cur + 1;

    if (cur->time < hn->tim.rec[5].time)
        *nxt = *cur;
}

/* cygnus-2.96 matched TU. */

#define D_ENABLER (*(volatile unsigned int *) 0x1000F520)
#define D_ENABLEW (*(volatile unsigned int *) 0x1000F590)

__attribute__((section(".text.func_00355880")))
void func_00355880(unsigned int chcr) {
    DIntr();
    D_ENABLEW = D_ENABLER | 0x00010000;
    *(volatile unsigned int *) 0x1000B400 = chcr;
    D_ENABLEW = D_ENABLER & 0xFFFEFFFF;
    EIntr();
}

/* cygnus-2.96 matched TU. */

__attribute__((section(".text.viBufUnput")))
int viBufUnput(ViBuf *b, int n)
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
