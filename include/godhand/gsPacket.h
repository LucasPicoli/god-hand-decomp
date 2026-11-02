/* include/godhand/gsPacket.h - GS register packets and the screen settings they use.
 *
 * PushEntryAtField10000_299868 appends one register write (data, then the
 * register number) to the packet queue of a draw context, at +0x10000. The
 * GS_SET_* macros pack register values the way the SDK's libgraph does, and
 * the register numbers are the SDK's names.
 */
#ifndef GODHAND_GSPACKET_H
#define GODHAND_GSPACKET_H

#define GS_PRIM       0x00
#define GS_XYZ2       0x05
#define GS_XYZ3       0x0D
#define GS_TEXFLUSH   0x3F
#define GS_TEXFLUSH_DATA  0xFF          /* the GS ignores TEXFLUSH's value; the game writes 0xFF */
#define GS_SCISSOR_2  0x41
#define GS_FRAME_2    0x4D

#define GS_SET_FRAME(fbp, fbw, psm, fbmsk) \
    ((unsigned long)(fbp) | ((unsigned long)(fbw) << 16) | ((unsigned long)(psm) << 24) | \
     ((unsigned long)(fbmsk) << 32))
#define GS_SET_SCISSOR(x0, x1, y0, y1) \
    ((unsigned long)(x0) | ((unsigned long)(x1) << 16) | ((unsigned long)(y0) << 32) | \
     ((unsigned long)(y1) << 48))
#define GS_SET_XYZ(x, y, z) \
    ((unsigned long)(x) | ((unsigned long)(y) << 16) | ((unsigned long)(z) << 32))
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((unsigned long)(tbp) | ((unsigned long)(tbw) << 14) | ((unsigned long)(psm) << 20) | \
     ((unsigned long)(tw) << 26) | ((unsigned long)(th) << 30) | ((unsigned long)(tcc) << 34) | \
     ((unsigned long)(tfx) << 35) | ((unsigned long)(cbp) << 37) | ((unsigned long)(cpsm) << 51) | \
     ((unsigned long)(csm) << 55) | ((unsigned long)(csa) << 56) | ((unsigned long)(cld) << 61))
#define GS_SET_ALPHA(a, b, c, d, fix) \
    ((unsigned long)(a) | ((unsigned long)(b) << 2) | ((unsigned long)(c) << 4) | \
     ((unsigned long)(d) << 6) | ((unsigned long)(fix) << 32))
#define GS_SET_UV(u, v) ((unsigned long)(u) | ((unsigned long)(v) << 16))
#define GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((unsigned long)(ate) | ((unsigned long)(atst) << 1) | ((unsigned long)(aref) << 4) | \
     ((unsigned long)(afail) << 12) | ((unsigned long)(date) << 14) | ((unsigned long)(datm) << 15) | \
     ((unsigned long)(zte) << 16) | ((unsigned long)(ztst) << 17))

#define GS_ZTST_ALWAYS  1               /* TEST's ZTST: every pixel passes */

/* The GS window coordinate of the screen's horizontal centre. */
#define GS_WINDOW_CENTER  0x800

extern int D_003C1180;                  /* screen width */
extern int D_003C118C;                  /* screen height */
extern unsigned int D_003C11AC;         /* frame buffer base address, in 64-word blocks */
extern int D_003C11B4;                  /* frame buffer height */
extern int D_003C11BC;                  /* log2 of the frame buffer height, TEX0's th */
extern unsigned int D_003C11C8;         /* size of one frame buffer, in 64-word blocks */
extern int D_00586B80;                  /* GS window y of the screen's top row */

void PushEntryAtField10000_299868(char *ctx, long reg, long data);

#endif
