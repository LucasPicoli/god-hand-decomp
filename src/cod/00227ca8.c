/* sn-2.95.3-136 matched TU. */

/* func_00227CA8 — 0x00227CA8, 828 B — sn-2.95.3-136.
 * Template src/cod/00225e30.c (func_00225E30, jaccard 0.93). */

extern int  Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int Forward30F348_31CFE0(void);
extern int  cCoreSave_getGameLevel(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int  Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int  moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern void func_00260B30(void *a0);
extern char D_00569B70[];

__attribute__((section(".text.func_00227CA8")))
void func_00227CA8(void *a0)
{
    char *s0 = (char *)a0;

    *(unsigned char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int r;
        int p1;
        int p2;

        *(unsigned char *)(s0 + 0x1864) = 0;
        r = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        if (9.0f < *(float *)(s0 + 0x618)) {
            *(unsigned char *)(s0 + 0x2F7) = 0;
        } else {
            *(unsigned char *)(s0 + 0x2F7) = 1;
        }
        if ((Forward30F348_31CFE0() & 3) == 0) {
            *(unsigned char *)(s0 + 0x2F7) = 2;
        }
        switch (*(unsigned char *)(s0 + 0x2F7)) {
        default:
        case 0: {
            int w = *(int *)(s0 + 0x304);
            p1 = *(int *)(w + 0x300C) + w;
            p2 = *(int *)(w + 0x3010) + w;
            if (cCoreSave_getGameLevel(D_00569B70) == 5) {
                int w2 = *(int *)(s0 + 0x304);
                p2 = *(int *)(w2 + 0x3014) + w2;
            }
            *(float *)(s0 + 0x600) = 35.0f;
            break;
        }
        case 1: {
            int w = *(int *)(s0 + 0x304);
            p1 = *(int *)(w + 0x3018) + w;
            p2 = *(int *)(w + 0x301C) + w;
            if (cCoreSave_getGameLevel(D_00569B70) == 5) {
                int w2 = *(int *)(s0 + 0x304);
                p2 = *(int *)(w2 + 0x3020) + w2;
            }
            *(float *)(s0 + 0x600) = 25.0f;
            break;
        }
        case 2: {
            int w = *(int *)(s0 + 0x304);
            p1 = *(int *)(w + 0x3024) + w;
            p2 = *(int *)(w + 0x3028) + w;
            if (cCoreSave_getGameLevel(D_00569B70) == 5) {
                int w2 = *(int *)(s0 + 0x304);
                p2 = *(int *)(w2 + 0x302C) + w2;
            }
            *(float *)(s0 + 0x600) = 90.0f;
            break;
        }
        }
        StoreMotionParamsBoth_2609A8(s0, 0x14, 0x1B, 0x3E, -1, 0);
        func_002A8578(s0, p1, p2, 0.0f, 3, r, 0);
        *(int *)(s0 + 0x5F4) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1: {
        float t = *(float *)(s0 + 0x600);

        if (0.0f < t) {
            int q;
            *(float *)(s0 + 0x600) = t - *(float *)(s0 + 0x5A8);
            q = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(q + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.19634954f);
        }
        if (moveMotion(s0)) {
            if (25.0f < *(float *)(s0 + 0x618)) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x6C;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
            } else {
                func_002705D8(s0);
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 2) {
            if (*(int *)(s0 + 0x5F4) != 0) {
                *(int *)(s0 + 0x5F4) = 0;
                switch (*(unsigned char *)(s0 + 0x2F7)) {
                default:
                case 0:
                    func_0026BEF0(s0, 0xA, 0);
                    break;
                case 1:
                    func_0026BEF0(s0, 0xB, 0);
                    break;
                case 2:
                    func_0026BEF0(s0, 0xC, 0);
                    break;
                }
            }
        } else {
            *(int *)(s0 + 0x5F4) = 1;
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 1)
            func_00260B30(s0);
        break;
    }
    default:
        break;
    }
}
