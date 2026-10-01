/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"

extern void func_001D5360(void *a0, int a1);
extern void func_001D5430(void *a0, int a1);
extern void func_001D5500(void *a0, int a1);
extern void SetBlendField5B4_1D57A0(void *a0, int a1);
extern void NoOp_1D4B70(void *a0);
extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern int cCoreSave_getGold(char *a0);
extern void cCoreSave_addGold(char *a0, int a1, int a2);
extern void cCoreSave_subGold(char *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_007474A0;
extern int D_00747A2C;
extern void PushEntryAtField10000_299868(char *a0, long a1, long a2);
extern int D_003C1180;
extern int D_003C118C;
extern int D_003C11B4;
extern int D_003C11BC;
extern int D_00586B80;

/* Betting state with the toggle button: pad buttons confirm the bet or step it by 100. */
__attribute__((section(".text.BlackJack_UpdateAddBetMenu")))
void BlackJack_UpdateAddBetMenu(BlackJack *self)
{
    switch (self->phase) {
    case 0:
        func_001D5360(self, 0);
        SetBlendField5B4_1D57A0(self, 1);
        self->phase += 1;
        /* fallthrough */
    case 1: {
        char *g;
        long f;

        {
            char *p = (char *)&D_00747A2C;
            if (*(int *)p & 0x200) {
                if (*(long *)(p - 0x3EC) & 0x80000000000L) {
                    long q = (unsigned int)self->flags;
                    if (((q >> 1) & 1) == 1)
                        self->flags &= ~2;
                    else
                        self->flags |= 2;
                }
            }
        }
        {
            long q = (unsigned int)self->flags;
            if (((q >> 1) & 1) == 1) {
                NoOp_1D4B70(self);
                return;
            }
        }
        g = (char *)&D_007474A0;
        f = *(long *)(g + 0x1B0);

        if ((f & 0x8800004000000L) != 0) {
            func_001D5360(self, 1);
            SetBlendField5B4_1D57A0(self, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            self->phase = 0;
            self->state = 2;
            return;
        }
        if ((f & 0x4400008000000L) != 0) {
            func_001D5360(self, 1);
            SetBlendField5B4_1D57A0(self, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            if (self->bet != 0) {
                self->phase = 0;
                self->state = 3;
            } else {
                self->phase = 0;
                self->state = 2;
            }
            return;
        }
        if ((f & 0x3300003000000L) != 0) {
            func_001D5360(self, 1);
            SetBlendField5B4_1D57A0(self, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            self->phase = 0;
            self->state = 4;
            return;
        }
        {
            long h = *(long *)(g + 0x1A0);

            if ((h & 0x10000000L) != 0) {
                if (self->bet < self->betMax &&
                    cCoreSave_getGold(D_00569B70) >= 0x64) {
                    int v;

                    cCoreSave_subGold(D_00569B70, 0x64);
                    v = self->bet + 0x64;
                    self->bet = v;
                    CustomIDWork_SetNumber_1D5760(self, v);
                    func_001D5500(self, 1);
                    if (self->bet >= self->betMax) {
                        func_001D5360(self, 2);
                        SetBlendField5B4_1D57A0(self, 0);
                        func_001D5430(self, 2);
                        self->phase = 0;
                        self->state = 3;
                    }
                    self->flags &= ~8;
                }
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                return;
            }
            if ((h & 0x20000000L) != 0) {
                if (self->bet > 0) {
                    int v;

                    cCoreSave_addGold(D_00569B70, 0x64, 0);
                    v = self->bet - 0x64;
                    self->bet = v;
                    CustomIDWork_SetNumber_1D5760(self, v);
                    if (self->bet == 0)
                        func_001D5500(self, 2);
                } else {
                    func_001D5360(self, 1);
                    SetBlendField5B4_1D57A0(self, 0);
                    self->phase = 0;
                    self->state = 4;
                }
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            }
        }
        break;
    }
    }
}

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
#define GS_SET_UV(u, v) ((u_long)(u) | ((u_long)(v) << 16))
#define GS_SET_XYZ(x, y, z) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))




extern u_int D_003C11AC;


extern u_int D_003C11C8;


__attribute__((section(".text.func_0029FFB0")))
void func_0029FFB0(char *ctx, int p1, int p2, int xo, int yo)
{
    int i;
    int yh = yo >> 1;

    PushEntryAtField10000_299868(ctx, 0x3F, 0xFF);
    PushEntryAtField10000_299868(ctx, 0, 0x316);
    PushEntryAtField10000_299868(ctx, 0x4D,
        GS_SET_FRAME((D_003C11AC + D_003C11C8 * p2) >> 5, D_003C1180 / 128, 0, 0));
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
