/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 matched TU. */

#include "godhand/sync.h"
typedef unsigned int  u_int;
typedef unsigned long u_long;

typedef struct {
    u_long frame2;          /* 0x00 */
    u_long frame2addr;      /* 0x08 */
    u_long zbuf2;           /* 0x10 */
    long   zbuf2addr;       /* 0x18 */
    u_long xyoffset2;       /* 0x20 */
    long   xyoffset2addr;   /* 0x28 */
    u_long scissor2;        /* 0x30 */
    long   scissor2addr;    /* 0x38 */
    u_long prmodecont;      /* 0x40 */
    long   prmodecontaddr;  /* 0x48 */
    u_long colclamp;        /* 0x50 */
    long   colclampaddr;    /* 0x58 */
    u_long dthe;            /* 0x60 */
    long   dtheaddr;        /* 0x68 */
    u_long test2;           /* 0x70 */
    long   test2addr;       /* 0x78 */
} sceGsDrawEnv2;

extern int sceGszbufaddr(short psm, short w, short h);

#define SCE_GS_FRAME_2      (0x4D)
#define SCE_GS_ZBUF_2       (0x4F)
#define SCE_GS_XYOFFSET_2   (0x19)
#define SCE_GS_SCISSOR_2    (0x41)
#define SCE_GS_PRMODECONT   (0x1A)
#define SCE_GS_COLCLAMP     (0x46)
#define SCE_GS_DTHE         (0x45)
#define SCE_GS_TEST_2       (0x48)

#define SCE_GS_SET_FRAME(fbp, fbw, psm, fbmsk) \
    ((u_long)(fbp)        | ((u_long)(fbw) << 16) | \
    ((u_long)(psm) << 24) | ((u_long)(fbmsk) << 32))

#define SCE_GS_SET_ZBUF(zbp, psm, zmsk) \
    ((u_long)(zbp) | ((u_long)(psm) << 24) | ((u_long)(zmsk) << 32))

#define SCE_GS_SET_XYOFFSET(ofx, ofy) \
    ((u_long)(ofx) | ((u_long)(ofy) << 32))

#define SCE_GS_SET_SCISSOR(scax0, scax1, scay0, scay1) \
    ((u_long)(scax0)        | ((u_long)(scax1) << 16) | \
    ((u_long)(scay0) << 32) | ((u_long)(scay1) << 48))

#define SCE_GS_SET_TEST_2(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((u_long)(ate)         | ((u_long)(atst) << 1) | \
    ((u_long)(aref) << 4)  | ((u_long)(afail) << 12) | \
    ((u_long)(date) << 14) | ((u_long)(datm) << 15) | \
    ((u_long)(zte) << 16)  | ((u_long)(ztst) << 17))

__attribute__((section(".text.sceGsSetDefDrawEnv2")))
int sceGsSetDefDrawEnv2(sceGsDrawEnv2 *draw, short psm, short w, short h,
                  short ztest, short zpsm)
{
    long cx;
    long cy;

    draw->frame2addr = SCE_GS_FRAME_2;
    draw->frame2 = SCE_GS_SET_FRAME(0, (w >> 6) & 0x3F, psm & 0xF, 0);
    draw->zbuf2addr = SCE_GS_ZBUF_2;
    if (ztest == 0) {
        draw->zbuf2 = SCE_GS_SET_ZBUF((short)sceGszbufaddr(psm, w, h),
                                      zpsm & 0xF, 1);
    } else {
        draw->zbuf2 = SCE_GS_SET_ZBUF((short)sceGszbufaddr(psm, w, h),
                                      zpsm & 0xF, 0);
    }
    cx = (short)(w >> 1);
    cy = (short)(h >> 1);
    draw->xyoffset2addr = SCE_GS_XYOFFSET_2;
    draw->xyoffset2 = SCE_GS_SET_XYOFFSET((2048 - cx) * 16, (2048 - cy) * 16);
    draw->scissor2addr = SCE_GS_SCISSOR_2;
    draw->scissor2 = SCE_GS_SET_SCISSOR(0, w - 1, 0, h - 1);
    draw->prmodecontaddr = SCE_GS_PRMODECONT;
    draw->prmodecont |= 1;
    draw->colclampaddr = SCE_GS_COLCLAMP;
    draw->colclamp |= 1;
    draw->dtheaddr = SCE_GS_DTHE;
    if (psm & 2) {
        draw->dthe |= 1;
    } else {
        draw->dthe &= ~1L;
    }
    draw->test2addr = SCE_GS_TEST_2;
    if (ztest) {
        draw->test2 = SCE_GS_SET_TEST_2(0, 0, 0, 0, 0, 0, 1, ztest & 3);
    } else {
        draw->test2 = SCE_GS_SET_TEST_2(0, 0, 0, 0, 0, 0, 1, 1);
    }
    GH_SYNC();
    return 8;
}
