/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

#include <godhand/sync.h>

typedef unsigned int  u_int;
typedef unsigned long u_long;
typedef int u_long128 __attribute__((mode(TI)));

typedef struct {
    u_long NLOOP:15;
    u_long EOP:1;
    u_long pad16:16;
    u_long ID:14;
    u_long PRE:1;
    u_long PRIM:11;
    u_long FLG:2;
    u_long NREG:4;
    u_long REGS0:4;
    u_long REGS1:4;
    u_long REGS2:4;
    u_long REGS3:4;
    u_long REGS4:4;
    u_long REGS5:4;
    u_long REGS6:4;
    u_long REGS7:4;
    u_long REGS8:4;
    u_long REGS9:4;
    u_long REGS10:4;
    u_long REGS11:4;
    u_long REGS12:4;
    u_long REGS13:4;
    u_long REGS14:4;
    u_long REGS15:4;
} sceGifTag;

typedef struct {
    u_int     vifnop;
    u_int     vifmskpath3;
    u_int     vifflusha;
    u_int     vifdirect;
    sceGifTag giftag;
    u_long    bitbltbuf;
    long      bitbltbufaddr;
    u_long    trxpos;
    long      trxposaddr;
    u_long    trxreg;
    long      trxregaddr;
    u_long    fintag;
    long      fintagaddr;
    u_long    trxdir;
    long      trxdiraddr;
} sceGsStoreImage;

#define SCE_GS_BITBLTBUF (0x50)
#define SCE_GS_TRXPOS    (0x51)
#define SCE_GS_TRXREG    (0x52)
#define SCE_GS_TRXDIR    (0x53)
#define SCE_GS_FINISH    (0x61)

#define SCE_GS_SET_BITBLTBUF(sbp, sbw, spsm, dbp, dbw, dpsm) \
    ((u_long)(sbp)         | ((u_long)(sbw) << 16) | \
    ((u_long)(spsm) << 24) | ((u_long)(dbp) << 32) | \
    ((u_long)(dbw) << 48)  | ((u_long)(dpsm) << 56))

#define SCE_GS_SET_TRXPOS(ssax, ssay, dsax, dsay, dir) \
    ((u_long)(ssax)        | ((u_long)(ssay) << 16) | \
    ((u_long)(dsax) << 32) | ((u_long)(dsay) << 48) | ((u_long)(dir) << 59))

#define SCE_GS_SET_TRXREG(rrw, rrh) \
    ((u_long)(rrw) | ((u_long)(rrh) << 32))

__attribute__((section(".text.func_00395618")))
int func_00395618(sceGsStoreImage *sg, short sbp, short sbw, short spsm,
                  short ssax, short ssay, short rrw, short rrh)
{
    sg->vifnop      = 0;
    sg->vifmskpath3 = 0x06008000;
    sg->vifflusha   = 0x13000000;
    sg->vifdirect   = 0x50000006;
    *(u_long128 *)&sg->giftag = 0;
    sg->giftag.NLOOP = 5;
    sg->giftag.EOP   = 1;
    sg->giftag.NREG  = 1;
    sg->giftag.REGS0 = 0xE;
    sg->bitbltbuf     = SCE_GS_SET_BITBLTBUF(sbp, sbw, spsm, 0, 0, 0);
    sg->bitbltbufaddr = SCE_GS_BITBLTBUF;
    sg->trxpos        = SCE_GS_SET_TRXPOS(ssax, ssay, 0, 0, 0);
    sg->trxposaddr    = SCE_GS_TRXPOS;
    sg->trxreg        = SCE_GS_SET_TRXREG(rrw, rrh);
    sg->trxregaddr    = SCE_GS_TRXREG;
    sg->fintag        = 0;
    sg->fintagaddr    = SCE_GS_FINISH;
    sg->trxdir        = 1;
    sg->trxdiraddr    = SCE_GS_TRXDIR;
    GH_SYNC();
    return 7;
}
