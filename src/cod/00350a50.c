/* cygnus-2.96 matched TU. */
#include "godhand/sftim.h"
#include "godhand/MpvHandle.h"

extern int WaitSema(int sid);
extern int SignalSema(int sid);
extern void setD3_CHCR(unsigned int chcr);

/* cygnus-2.96 matched TU. */

extern int sfmpv_GetTermSrc(void *hn);                    /* sfmpv_GetTermSrc */
extern int SFBUF_GetWTot(void *hn, int f);             /* SFBUF_GetWTot */
extern int Obj35C0_IsIndexedSet_1F3C_C380(void *hn, int f);   /* SFTRN_IsSetup */
extern int SFBUF_GetRingBufSiz(void *hn, int f);             /* SFBUF_GetRingBufSiz */

__attribute__((section(".text.sfmpv_IsVbvEnough")))
int sfmpv_IsVbvEnough(SftimHn *hn)
{
    SfdHdInf *hdr = &hn->hdr;
    SfdWork *w = hn->work;
    MpvHandle *mpv = w->dec;
    unsigned int rate;
    int f;

    if (sfmpv_GetTermSrc(hn) == 1)
        return 1;
    if (hdr->valid != 0 && hdr->f7C == 0)
        return 1;
    MPV_GetBitRate(mpv, &rate);
    if (rate == 0x3FFFF)
        return 1;
    if (SFBUF_GetWTot(hn, 1) >= w->f114)
        return 1;
    f = Obj35C0_IsIndexedSet_1F3C_C380(hn, 1) == 0;
    if (SFBUF_GetWTot(hn, f) < SFBUF_GetRingBufSiz(hn, f))
        return 0;
    return 1;
}

/* cygnus-2.96 matched TU. */

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
