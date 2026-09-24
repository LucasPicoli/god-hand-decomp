/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float f12);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void KillEffect(void *a0, int a1, int a2);
extern void MtxInitRotVec(void *a0, void *a1, int a2);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void cDamageUnit_SetDamageCollActive(int a0, int a1);
extern void cDamageGive_SetDmgGiveHitVecDir(int a0, void *a1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5,
                              int a6, int a7);
extern float cEmManage_GetSpeedRate(void *a0);
extern int ChkLine(void *a0, int a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern char D_005FEE00[];
extern char D_005864F0[];

#include "godhand/vu0.h"

#define FRAME ((char *)mtx - 0x30)

__attribute__((section(".text.func_001B6A30")))
void func_001B6A30(void *a0)
{
    float mtx[16];
    char *s1 = (char *)a0;

    if (*(int *)(s1 + 0x62C) >= 0) {
        *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) & 0xFFFFFFFDU;
    }
    switch (*(unsigned char *)(s1 + 0x2F5)) {
    case 0:
    {
        float *d;
        float *sr;

        d = *(float **)(s1 + 0xF0);
        sr = (float *)(s1 + 0x600);
        if (d != sr) {
            d[0] = sr[0];
            d[1] = sr[1];
            d[2] = sr[2];
        }
        *(short *)(s1 + 0x628) = 0x28;
        *(char *)(s1 + 0x2F5) = 1;
        *(char *)(s1 + 0x2F6) = 0;
        *(char *)(s1 + 0x2F7) = 0;
    }
        /* fallthrough */
    case 1:
    {
        char *v0;
        char *v2;
        int d;

        unsigned long fl = *(unsigned int *)(s1 + 0x5B8);
        if ((fl & 1) == 0) {
            if (*(int *)(s1 + 0x62C) < 0) {
                *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 2;
            }
            break;
        }
        if (*(short *)(s1 + 0x628) <= 0) {
        SetEffectPos(1, 1, 0, s1 + 0x600, -1, 1.0f);
        v0 = s1 + 0x610;
        v2 = s1 + 0x100;
        SetEffect(1, 2, s1, 0, 1, 0xFFFFFFFFu);
        *(int *)(s1 + 0x610) = 0;
        *(int *)(v0 + 0x4) = 0;
        *(float *)(v0 + 0x8) = 1.0f;
        *(float *)(v0 + 0xC) = 1.0f;
        MtxInitRotVec(mtx, v2, 0);
        sceVu0ApplyMatrix(v0, mtx, v0);
        d = *(int *)(s1 + 0x620);
        if (d != 0) {
            cDamageUnit_SetDamageCollActive(d, 1);
            cDamageGive_SetDmgGiveHitVecDir(*(int *)(s1 + 0x620), v2);
        }
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x46, s1, 0, 0, 0, 0);
        *(short *)(s1 + 0x628) = 0x5A;
        *(char *)(s1 + 0x2F6) = 0;
        *(char *)(s1 + 0x2F5) = 2;
        *(char *)(s1 + 0x2F7) = 0;
        break;
        }
        *(short *)(s1 + 0x628) = *(unsigned short *)(s1 + 0x628) - 1;
        break;
    }
    case 2:
    {
        float rate;
        char *vp;
        float *v;
        float *p;
        int n;
        int hit;
        int eff;
        int ph;
        int d;

        rate = cEmManage_GetSpeedRate(D_005864F0);
        vp = (char *)&mtx[4];
        VU0_LQC2(4, s1 + 0x610, 0);
        VU0_SQC2(4, FRAME, 0x40);
        VU0_LQC2(4, FRAME, 0x40);
        VU0_LOAD_SCALAR(5, rate);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, FRAME, 0x40);
        VU0_LQC2(4, vp, 0);
        VU0_SQC2(4, FRAME, 0x30);
        v = mtx;
        p = *(float **)(s1 + 0xF0);
        VU0_VADD_XYZ_IP(p, 0, v);
        n = *(unsigned short *)(s1 + 0x628) - 1;
        *(short *)(s1 + 0x628) = n;
        if (*(short *)(s1 + 0x628) < 0) {
            goto ph3;
        }
        VU0_SQC2_VF0(FRAME, 0x30);
        hit = 0;
        eff = 0;
        d = ChkLine(s1 + 0x490, *(int *)(s1 + 0xF0), v, 0, 7, 0, 0, 0, 0, 0, 0,
                    0, 1);
        if (d != 0) {
            hit = 1;
            eff = 1;
        }
        {
            int t = *(int *)(s1 + 0x620);
            if (t != 0) {
                int u = *(int *)(t + 0x34);
                if (u != 0) {
                    int w = *(int *)(u + 0xF0);
                    hit = 1;
                    if (v != (float *)w) {
                        v[0] = *(float *)w;
                        v[1] = *(float *)(w + 4);
                        v[2] = *(float *)(w + 8);
                    }
                    mtx[1] = *(float *)(*(int *)(s1 + 0xF0) + 4);
                }
            }
        }
        if (hit != 1) {
            break;
        }
        KillEffect(s1, 1, 2);
        if (eff != 0) {
            SetEffectPos(1, 3, 0, mtx, -1, 1.0f);
        }
        d = *(int *)(s1 + 0x620);
        if (d != 0) {
            cDamageUnit_SetDamageCollActive(d, 0);
        }
        d = *(int *)(s1 + 0x624);
        if (d != 0) {
            cDamageUnit_SetDamageCollActive(d, 0);
        }
        ph = 4;
        goto setph;
    ph3:
        ph = 3;
    setph:
        *(char *)(s1 + 0x2F7) = 0;
        do { } while (0);
        *(char *)(s1 + 0x2F5) = ph;
        *(char *)(s1 + 0x2F6) = 0;
        break;
    }
    case 3:
    {
        int d;

        *(char *)(s1 + 0x2F5) = 0;
        *(char *)(s1 + 0x2F6) = 0;
        *(char *)(s1 + 0x2F7) = 0;
        KillEffect(s1, 1, 2);
        d = *(int *)(s1 + 0x620);
        if (d != 0) {
            cDamageUnit_SetDamageCollActive(d, 0);
        }
        break;
    }
    case 4:
    {
        int f;
        int n;

        f = *(int *)(s1 + 0x250) | 2;
        *(int *)(s1 + 0x250) = f;
        n = *(unsigned short *)(s1 + 0x628) - 1;
        *(short *)(s1 + 0x628) = n;
        if (*(short *)(s1 + 0x628) < 0) {
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
            *(int *)(s1 + 0x250) = f & 0xFFFFFFFDU;
        }
        break;
    }
    default:
        break;
    }
}
