/* sn-2.95.3-136 matched TU. */

extern void MaxField514_292030(void *a0, int a1);
extern void Obj293_SetByte_53C_2(char *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void MtxInitRotY(void *a0, float angle);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void func_001CF340(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00124EC0(void *a0);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_0012A8D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int func_00123938(void *a0, int a1);
extern char D_005864F0[];
extern char D_00462FC0[];

/* SN ProDG ee-gcc 2.95.3 matched TU — func_00115030.
 *
 * Per-frame update for the "state 0x2F6" actor phase.  Same family as the
 * already-matched UpdateAttackState2F6_1161E0 (src/cod/001161e0.c) and
 * UpdateStatePhase2F6_10CC58 (src/cod/0010cc58.c): a 5.0f cooldown store,
 * a two-case switch on the phase byte at +0x2F6, then the common
 * moveMotion/AddScaled.../func_00123938 tail.
 *
 * Phase 0 additionally binds the "carried object" slot (+0x69C -> +0x698),
 * pushes it one unit along the actor's -Z axis rotated by the actor's Y
 * heading (+0x104), and copies the actor's world position (+0xF0 vector)
 * and heading (+0x100) onto it.
 */

#include "godhand/vu0.h"





















#define OTHER (*(char **)(s1 + 0x698))

__attribute__((section(".text.func_00115030")))
void func_00115030(void *a0) {
    char *s1 = (char *)a0;
    float mv[20]; /* mv[0..15]: rotation matrix; mv[16..19]: direction vector */
    float *d;
    float *s;
    float *d2;
    float *s2;
    char *o;
    int t;
    int tt;
    int p1;
    int p2;

    *(float *)(s1 + 0x54C) = 5.0f;
    MaxField514_292030(D_005864F0, 2);
    Obj293_SetByte_53C_2(D_005864F0);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_001268F0(s1);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        t = *(int *)(s1 + 0x304);
        p1 = *(int *)(t + 0x8C8) + t;
        p2 = *(int *)(t + 0x8CC) + t;
        o = *(char **)(s1 + 0x69C);
        *(char **)(s1 + 0x698) = o;
        if (o != 0) {
            VU0_SQC2_VF0(mv, 0x40);
            MtxInitRotY(mv, *(float *)(s1 + 0x104));
            mv[16] = 0.0f;
            mv[17] = 0.0f;
            mv[18] = -1.0f;
            sceVu0ApplyMatrix(&mv[16], mv, &mv[16]);
            (*(float **)(s1 + 0xF0))[0] = (*(float **)(OTHER + 0xF0))[0] + mv[16];
            (*(float **)(s1 + 0xF0))[2] = (*(float **)(OTHER + 0xF0))[2] + mv[18];
            func_001CF340(OTHER);
            d = *(float **)(OTHER + 0xF0);
            s = *(float **)(s1 + 0xF0);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            d = (float *)(OTHER + 0x100);
            s = (float *)(s1 + 0x100);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            tt = *(int *)(s1 + 0x304);
            func_002A8578(OTHER, *(int *)(tt + 0x900) + tt, 0, 0.0f, 0, 0, 0);
        }
        func_002A8578(s1, p1, p2, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (OTHER != 0) {
            d2 = *(float **)(OTHER + 0xF0);
            s2 = *(float **)(s1 + 0xF0);
            if (d2 != s2) {
                d2[0] = s2[0];
                d2[1] = s2[1];
                d2[2] = s2[2];
            }
            d = (float *)(OTHER + 0x100);
            s = (float *)(s1 + 0x100);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
        }
        InvokeVirtualAtField214AndForward_124E68(s1, 0.19634954f);
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            func_0012A8D8(s1);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if (func_00123938(s1, 1) != 0) {
        ClearField15F4Bit1_124F60(s1, 0, 0);
        func_0012A8D8(s1);
    }
}
