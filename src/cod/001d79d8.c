/* sn-2.95.3-136 matched TU. */

extern void func_001DD770(void *a0, int a1);
extern void func_001DD840(void *a0, int a1);
extern void func_001DD910(void *a0, int a1);
extern void func_001DD5A0(void *a0, int a1);
extern void SetBlendField348_1DDBB8(void *a0, int a1);
extern void CustomIDWork_SetNumber_1DD218(char *a0, int a1);
extern void SetCustomIDNumberIndexed_1DD648(char *a0, int a1, int a2);
extern void cCoreSave_addGold(void *a0, int a1, int a2);
extern void cCoreSave_subGold(void *a0, int a1);
extern int GetTimerValue_1FA710(void *a0);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern int D_007474A0;
extern unsigned char D_005FEE00[];
extern int D_00569B70;
extern void PushEntryAtField10000_299868(char *a0, long a1, long a2);
extern int D_003C1180;
extern int D_003C118C;
extern int D_003C11B4;
extern int D_003C11BC;
extern int D_00586B80;

__attribute__((section(".text.func_001D79D8")))
void func_001D79D8(void *a0) {
    char *o = (char *)a0;
    char *g;

    switch (*(unsigned char *)(o + 0x3025)) {
    case 0:
        func_001DD840(o, 0);
        SetBlendField348_1DDBB8(o, 1);
        *(unsigned char *)(o + 0x3025) = *(unsigned char *)(o + 0x3025) + 1;
        /* fallthrough */
    case 1:
        g = (char *)&D_007474A0;
        if (*(long *)(g + 0x1B0) & 0xCC0000C000000L) {
            func_001DD840(o, 1);
            SetBlendField348_1DDBB8(o, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            *(unsigned char *)(o + 0x3025) = 0;
            *(unsigned char *)(o + 0x3024) = 4;
        } else if (*(long *)(g + 0x1B0) & 0x3300003000000L) {
            func_001DD840(o, 1);
            SetBlendField348_1DDBB8(o, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            *(unsigned char *)(o + 0x3025) = 0;
            *(unsigned char *)(o + 0x3024) = 1;
        } else if (*(long *)(g + 0x1A0) & 0x10000000) {
            while (*(int *)(o + 0x3034) < *(int *)(o + 0x3030) && GetTimerValue_1FA710(&D_00569B70) >= 0x64) {
                cCoreSave_subGold(&D_00569B70, 0x64);
                *(int *)(o + 0x3034) = *(int *)(o + 0x3034) + 0x64;
                *(int *)(o + 0x3020) = *(int *)(o + 0x3020) | 8;
            }
            if (*(int *)(o + 0x3034) != 0) {
                CustomIDWork_SetNumber_1DD218(o, *(int *)(o + 0x3034));
                func_001DD840(o, 2);
                SetBlendField348_1DDBB8(o, 0);
                func_001DD770(o, 2);
                func_001DD5A0(o, 0);
                *(unsigned char *)(o + 0x3025) = 0;
                *(unsigned char *)(o + 0x3024) = 3;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        } else if (*(long *)(g + 0x1A0) & 0x20000000) {
            if (*(int *)(o + 0x3034) > 0) {
                cCoreSave_addGold(&D_00569B70, 0x64, 0);
                *(int *)(o + 0x3034) = *(int *)(o + 0x3034) - 0x64;
                CustomIDWork_SetNumber_1DD218(o, *(int *)(o + 0x3034));
                if (*(int *)(o + 0x3034) == 0) {
                    func_001DD910(o, 2);
                    func_001DD5A0(o, 1);
                }
            } else {
                func_001DD840(o, 1);
                SetBlendField348_1DDBB8(o, 0);
                *(unsigned char *)(o + 0x3025) = 0;
                *(unsigned char *)(o + 0x3024) = 4;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
        }
        break;
    }
    SetCustomIDNumberIndexed_1DD648(o, 0, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 0x32 : 0x32);
    SetCustomIDNumberIndexed_1DD648(o, 1, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 0x14 : 0x14);
    SetCustomIDNumberIndexed_1DD648(o, 2, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 0xF : 0xF);
    SetCustomIDNumberIndexed_1DD648(o, 3, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 0xA : 0xA);
    SetCustomIDNumberIndexed_1DD648(o, 4, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 8 : 8);
    SetCustomIDNumberIndexed_1DD648(o, 5, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 8 : 8);
    SetCustomIDNumberIndexed_1DD648(o, 6, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 3 : 3);
    SetCustomIDNumberIndexed_1DD648(o, 7, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 2 : 2);
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


__attribute__((section(".text.func_0029FAD8")))
void func_0029FAD8(char *ctx, int p1, int p2)
{
    int i;

    PushEntryAtField10000_299868(ctx, 0x3F, 0xFF);
    PushEntryAtField10000_299868(ctx, 0, 0x316);
    PushEntryAtField10000_299868(ctx, 0x4D,
        GS_SET_FRAME((D_003C11AC + D_003C11C8 * p2) >> 5, D_003C1180 / 128, 0, 0));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C11AC + D_003C11C8 * p1, D_003C1180 / 128, 0, 8, D_003C11BC, 1, 1, 0, 0, 1, 0, 2));
    PushEntryAtField10000_299868(ctx, 0x15, 0x60);
    for (i = 0; i < D_003C1180 / 64; i++) {
        PushEntryAtField10000_299868(ctx, 0x41,
            GS_SET_SCISSOR(i * 32, i * 32 + 0x1F, 0, D_003C11B4 - 1));
        PushEntryAtField10000_299868(ctx, 3,
            GS_SET_UV(*(u_int *)(ctx + 0x10018) << 4, *(u_int *)(ctx + 0x10018) << 4));
        PushEntryAtField10000_299868(ctx, 0xD,
            GS_SET_XYZ((0x800 - D_003C1180 / 2) << 4, D_00586B80 << 4, 0xFFFF));
        PushEntryAtField10000_299868(ctx, 3,
            GS_SET_UV((D_003C1180 / 2 << 4) + *(u_int *)(ctx + 0x10018) * 0x12,
                      (D_003C118C / 2 << 4) + *(u_int *)(ctx + 0x10018) * 0x12));
        PushEntryAtField10000_299868(ctx, 5,
            GS_SET_XYZ(0x8000, (D_00586B80 + D_003C118C / 2) << 4, 0xFFFF));
    }
    *(int *)(ctx + 0x10018) ^= 1;
}
