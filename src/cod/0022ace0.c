/* sn-2.95.3-136 matched TU. */

/* func_0022ACE0 — 0x0022ACE0, 688 B — sn-2.95.3-136.
 * Template src/cod/00225e30.c (func_00225E30, jaccard 0.67). */

extern int  Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int Forward30F348_31CFE0(void);
extern int  cCoreSave_getGameLevel(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int  Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int  moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_0026A638(void *a0, int a1);
extern void func_0026A938(void *a0, int a1, int a2);
extern void func_0026A838(void *a0, int a1);
extern char D_00569B70[];

__attribute__((section(".text.func_0022ACE0")))
void func_0022ACE0(void *a0)
{
    char *s0 = (char *)a0;

    *(unsigned char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int r;
        int c;
        int p1;
        int p2;

        r = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        c = Forward30F348_31CFE0() & 1;
        if (64.0f < *(float *)(s0 + 0x618))
            c = 0;
        if (*(float *)(s0 + 0x618) < 16.0f)
            c = 1;
        if (c != 0) {
            int w = *(int *)(s0 + 0x304);
            p1 = *(int *)(w + 0xDD0) + w;
            p2 = *(int *)(w + 0xDD4) + w;
            if (cCoreSave_getGameLevel(D_00569B70) == 5) {
                int w2 = *(int *)(s0 + 0x304);
                p2 = *(int *)(w2 + 0xDD4) + w2;
            }
            *(unsigned char *)(s0 + 0x2F7) = 1;
        } else {
            int w = *(int *)(s0 + 0x304);
            p1 = *(int *)(w + 0xDC4) + w;
            p2 = *(int *)(w + 0xDC8) + w;
            if (cCoreSave_getGameLevel(D_00569B70) == 5) {
                int w2 = *(int *)(s0 + 0x304);
                p2 = *(int *)(w2 + 0xDCC) + w2;
            }
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        func_002A8578(s0, p1, p2, 0.0f, 3, r, 0);
        *(int *)(s0 + 0x5F0) = 0x64;
        *(int *)(s0 + 0x5FC) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        *(int *)(s0 + 0x16DC) = 0x64;
        *(int *)(s0 + 0x16E0) = 0x96;
        if (*(int *)(s0 + 0x5F0) != 0) {
            int q;
            *(int *)(s0 + 0x5F0) = *(int *)(s0 + 0x5F0) - 1;
            q = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(q + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.19634954f);
        }
        if (moveMotion(s0))
            func_002705D8(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(unsigned char *)(s0 + 0x17C3) != 0) {
                func_0026A638(s0, 1);
            } else {
                func_0026A638(s0, 0);
            }
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 2) {
            if (*(unsigned char *)(s0 + 0x2F7) != 0) {
                func_0026A938(s0, 0, 0);
                func_0026A938(s0, 1, 0);
            } else {
                func_0026A838(s0, 0);
                func_0026A838(s0, 1);
            }
        }
        break;
    default:
        break;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 3)
        *(int *)(s0 + 0x5FC) = 1;
    if (*(int *)(s0 + 0x5FC) != 0)
        *(unsigned int *)(s0 + 0x16D4) &= 0xFFFFFBFFU;
}
