/* ee-2.9-991111 matched TU. */

#include "godhand/sync.h"
typedef unsigned int  u_int;
typedef unsigned long u_long;

typedef struct {
    u_long frame1;          /* 0x00 */
    u_long frame1addr;      /* 0x08 */
    u_long zbuf1;           /* 0x10 */
    long   zbuf1addr;       /* 0x18 */
    u_long xyoffset1;       /* 0x20 */
    long   xyoffset1addr;   /* 0x28 */
    u_long scissor1;        /* 0x30 */
    long   scissor1addr;    /* 0x38 */
    u_long prmodecont;      /* 0x40 */
    long   prmodecontaddr;  /* 0x48 */
    u_long colclamp;        /* 0x50 */
    long   colclampaddr;    /* 0x58 */
    u_long dthe;            /* 0x60 */
    long   dtheaddr;        /* 0x68 */
    u_long test1;           /* 0x70 */
    long   test1addr;       /* 0x78 */
} sceGsDrawEnv1;

extern int sceGszbufaddr(short psm, short w, short h);

#define SCE_GS_FRAME_1      (0x4C)
#define SCE_GS_ZBUF_1       (0x4E)
#define SCE_GS_XYOFFSET_1   (0x18)
#define SCE_GS_SCISSOR_1    (0x40)
#define SCE_GS_PRMODECONT   (0x1A)
#define SCE_GS_COLCLAMP     (0x46)
#define SCE_GS_DTHE         (0x45)
#define SCE_GS_TEST_1       (0x47)

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

#define SCE_GS_SET_TEST_1(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((u_long)(ate)         | ((u_long)(atst) << 1) | \
    ((u_long)(aref) << 4)  | ((u_long)(afail) << 12) | \
    ((u_long)(date) << 14) | ((u_long)(datm) << 15) | \
    ((u_long)(zte) << 16)  | ((u_long)(ztst) << 17))

__attribute__((section(".text.func_00396A70")))
int func_00396A70(sceGsDrawEnv1 *draw, short psm, short w, short h,
                  short ztest, short zpsm)
{
    long cx;
    long cy;

    draw->frame1addr = SCE_GS_FRAME_1;
    draw->frame1 = SCE_GS_SET_FRAME(0, ((w + 63) >> 6) & 0x3F, psm & 0xF, 0);
    draw->zbuf1addr = SCE_GS_ZBUF_1;
    if (ztest == 0) {
        draw->zbuf1 = SCE_GS_SET_ZBUF((short)sceGszbufaddr(psm, w, h),
                                      zpsm & 0xF, 1);
    } else {
        draw->zbuf1 = SCE_GS_SET_ZBUF((short)sceGszbufaddr(psm, w, h),
                                      zpsm & 0xF, 0);
    }
    cx = (short)(w >> 1);
    cy = (short)(h >> 1);
    draw->xyoffset1addr = SCE_GS_XYOFFSET_1;
    draw->xyoffset1 = SCE_GS_SET_XYOFFSET((2048 - cx) * 16, (2048 - cy) * 16);
    draw->scissor1addr = SCE_GS_SCISSOR_1;
    draw->scissor1 = SCE_GS_SET_SCISSOR(0, w - 1, 0, h - 1);
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
    draw->test1addr = SCE_GS_TEST_1;
    if (ztest) {
        draw->test1 = SCE_GS_SET_TEST_1(0, 0, 0, 0, 0, 0, 1, ztest & 3);
    } else {
        draw->test1 = SCE_GS_SET_TEST_1(0, 0, 0, 0, 0, 0, 1, 1);
    }
    GH_SYNC();
    return 8;
}
