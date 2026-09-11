/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libgraph 3.0.2, graph015.o :: sceGsSetDefLoadImage */

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
    sceGifTag giftag;           /* 0x00 */
    u_long    bitbltbuf;        /* 0x10 */
    long      bitbltbufaddr;    /* 0x18 */
    u_long    trxpos;           /* 0x20 */
    long      trxposaddr;       /* 0x28 */
    u_long    trxreg;           /* 0x30 */
    long      trxregaddr;       /* 0x38 */
    u_long    trxdir;           /* 0x40 */
    long      trxdiraddr;       /* 0x48 */
    sceGifTag giftag2;          /* 0x50 */
} sceGsLoadImage;

#define SCE_GS_BITBLTBUF (0x50)
#define SCE_GS_TRXPOS    (0x51)
#define SCE_GS_TRXREG    (0x52)
#define SCE_GS_TRXDIR    (0x53)

#define SCE_GS_SET_BITBLTBUF(sbp, sbw, spsm, dbp, dbw, dpsm) \
    ((u_long)(sbp)         | ((u_long)(sbw) << 16) | \
    ((u_long)(spsm) << 24) | ((u_long)(dbp) << 32) | \
    ((u_long)(dbw) << 48)  | ((u_long)(dpsm) << 56))

#define SCE_GS_SET_TRXPOS(ssax, ssay, dsax, dsay, dir) \
    ((u_long)(ssax)        | ((u_long)(ssay) << 16) | \
    ((u_long)(dsax) << 32) | ((u_long)(dsay) << 48) | ((u_long)(dir) << 59))

#define SCE_GS_SET_TRXREG(rrw, rrh) \
    ((u_long)(rrw) | ((u_long)(rrh) << 32))

extern char D_0045DC20[];                    /* the scePrintf format string */
extern void func_003B1F28(const char *fmt);  /* scePrintf */

__attribute__((section(".text.sceGsSetDefLoadImage")))
int sceGsSetDefLoadImage(sceGsLoadImage *di, short dbp, short dbw, short dpsm,
                  short dsax, short dsay, short rrw, short rrh)
{
    int qwc;

    qwc = 0;
    switch (dpsm) {
    case 0x00:                        /* SCE_GS_PSMCT32  */
    case 0x30:                        /* SCE_GS_PSMZ32   */
        qwc = (rrw * rrh) >> 2;
        break;
    case 0x01:                        /* SCE_GS_PSMCT24  */
    case 0x31:                        /* SCE_GS_PSMZ24   */
        qwc = (rrw * rrh * 3) >> 4;
        break;
    case 0x02:                        /* SCE_GS_PSMCT16  */
    case 0x0A:                        /* SCE_GS_PSMCT16S */
    case 0x32:                        /* SCE_GS_PSMZ16   */
    case 0x3A:                        /* SCE_GS_PSMZ16S  */
        qwc = (rrw * rrh) >> 3;
        break;
    case 0x13:                        /* SCE_GS_PSMT8    */
    case 0x1B:                        /* SCE_GS_PSMT8H   */
        qwc = (rrw * rrh) >> 4;
        break;
    case 0x14:                        /* SCE_GS_PSMT4    */
    case 0x24:                        /* SCE_GS_PSMT4HL  */
    case 0x2C:                        /* SCE_GS_PSMT4HH  */
        qwc = (rrw * rrh) >> 5;
        break;
    }
    if (qwc > 0x7FFF) {
        func_003B1F28(D_0045DC20);
        return 0;
    }
    *(u_long128 *)&di->giftag  = 0;
    di->giftag.NLOOP  = 4;
    di->giftag.NREG   = 1;
    di->giftag.REGS0  = 0xE;
    di->bitbltbuf     = SCE_GS_SET_BITBLTBUF(0, 0, 0, dbp, dbw, dpsm);
    di->bitbltbufaddr = SCE_GS_BITBLTBUF;
    di->trxpos        = SCE_GS_SET_TRXPOS(0, 0, dsax, dsay, 0);
    di->trxposaddr    = SCE_GS_TRXPOS;
    di->trxreg        = SCE_GS_SET_TRXREG(rrw, rrh);
    di->trxregaddr    = SCE_GS_TRXREG;
    di->trxdir        = 0;
    di->trxdiraddr    = SCE_GS_TRXDIR;
    *(u_long128 *)&di->giftag2 = 0;
    di->giftag2.NLOOP = qwc;
    di->giftag2.EOP   = 1;
    di->giftag2.FLG   = 2;
    GH_SYNC();
    return 6;
}
