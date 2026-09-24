/* sn-2.95.3-136 matched TU. */

typedef unsigned long u_long;
typedef unsigned int u_int;

#define GS_SET_FRAME(fbp, fbw, psm, fbmsk) \
    ((u_long)(fbp) | ((u_long)(fbw) << 16) | ((u_long)(psm) << 24) | ((u_long)(fbmsk) << 32))
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u_long)(tbp) | ((u_long)(tbw) << 14) | ((u_long)(psm) << 20) | ((u_long)(tw) << 26) | \
     ((u_long)(th) << 30) | ((u_long)(tcc) << 34) | ((u_long)(tfx) << 35) | ((u_long)(cbp) << 37) | \
     ((u_long)(cpsm) << 51) | ((u_long)(csm) << 55) | ((u_long)(csa) << 56) | ((u_long)(cld) << 61))
#define GS_SET_SCISSOR(x0, x1, y0, y1) \
    ((u_long)(x0) | ((u_long)(x1) << 16) | ((u_long)(y0) << 32) | ((u_long)(y1) << 48))
#define GS_SET_ALPHA(a, b, c, d, fix) \
    ((u_long)(a) | ((u_long)(b) << 2) | ((u_long)(c) << 4) | ((u_long)(d) << 6) | ((u_long)(fix) << 32))
#define GS_SET_UV(u, v) ((u_long)(u) | ((u_long)(v) << 16))
#define GS_SET_XYZ(x, y, z) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))

extern void PushEntryAtField10000_299868(char *a0, long a1, long a2);
extern int D_003C1180;
extern int D_003C118C;
extern u_int D_003C11AC;
extern int D_003C11B4;
extern int D_003C11BC;
extern u_int D_003C11C8;
extern int D_00586B80;

__attribute__((section(".text.func_002A0608")))
void func_002A0608(char *ctx, int p1, int p2, int xo, int yo, int fix)
{
    int i;
    int yh = yo >> 1;

    PushEntryAtField10000_299868(ctx, 0x3F, 0xFF);
    PushEntryAtField10000_299868(ctx, 0, 0x356);
    PushEntryAtField10000_299868(ctx, 0x4D,
        GS_SET_FRAME((D_003C11AC + D_003C11C8 * p2) >> 5, D_003C1180 / 128, 0, 0));
    PushEntryAtField10000_299868(ctx, 0x43, GS_SET_ALPHA(0, 2, 2, 1, fix));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C11AC + D_003C11C8 * p1, D_003C1180 / 128, 0, 8, D_003C11BC, 1, 1, 0, 0, 1, 0, 2));
    PushEntryAtField10000_299868(ctx, 0x15, 0x60);
    for (i = 0; i < D_003C1180 / 128; i++) {
        PushEntryAtField10000_299868(ctx, 0x41,
            GS_SET_SCISSOR(i * 64, i * 64 + 0x3F, 0, D_003C11B4 - 1));
        PushEntryAtField10000_299868(ctx, 3,
            GS_SET_UV(*(u_int *)(ctx + 0x10018) << 4, *(u_int *)(ctx + 0x10018) << 4));
        PushEntryAtField10000_299868(ctx, 0xD,
            GS_SET_XYZ(((0x800 - D_003C1180 / 2) << 4) + xo, (D_00586B80 << 4) + yh, 0xFFFF));
        PushEntryAtField10000_299868(ctx, 3,
            GS_SET_UV((D_003C1180 / 2 << 4) + *(u_int *)(ctx + 0x10018) * 0x12,
                      (D_003C118C / 2 << 4) + *(u_int *)(ctx + 0x10018) * 0x12));
        PushEntryAtField10000_299868(ctx, 5,
            GS_SET_XYZ(0x8000 + xo, ((D_00586B80 + D_003C118C / 2) << 4) + yh, 0xFFFF));
    }
    *(int *)(ctx + 0x10018) ^= 1;
}
