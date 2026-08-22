/* TU: pl00 [player] - recovered C++ class. */
extern void pl00_reset(void);
#include "include_asm.h"

#include "godhand/vu0.h"

extern void func_001C8D48(void *obj);

extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern int D_005FEE00[];

__attribute__((section(".text.pl00_CannonGameMode")))
void pl00_CannonGameMode(void *a0, int a1) {
    if (a1) {
        *(unsigned char*)((char*)a0+0x2F4) = 6;
        *(float*)((char*)a0+0x54C) = 5.0f;
        *(unsigned char*)((char*)a0+0x2F5) = 0;
        *(unsigned char*)((char*)a0+0x2F6) = 0;
        *(unsigned char*)((char*)a0+0x2F7) = 0;
    } else {
        pl00_reset();
    }
}

__attribute__((section(".text.pl00_ckMotionCam")))
int pl00_ckMotionCam(char *a0) {
    int v = *(int*)(a0 + 0x15F4) & 0x2;
    return v != 0;
}

__attribute__((section(".text.pl00_setIgnition")))
void pl00_setIgnition(void *a0, float *a1, float f12) {
    float *v0 = (float*)((char*)a0+0x660);
    if (v0 != a1) {
        *v0 = *a1;
        v0[1] = a1[1];
        v0[2] = a1[2];
    }
    *(float*)((char*)a0+0x670) = f12;
    *(unsigned char*)((char*)a0+0x2F5) = 0x34;
    *(unsigned char*)((char*)a0+0x2F4) = 0;
    *(unsigned char*)((char*)a0+0x2F6) = 0;
    *(unsigned char*)((char*)a0+0x2F7) = 0;
}

__attribute__((section(".text.pl00_setPyramidIn")))
void pl00_setPyramidIn(char *a0) {
    *(unsigned char*)(a0 + 0x2F4) = 0;
    *(unsigned char*)(a0 + 0x2F5) = 0x36;
    *(unsigned char*)(a0 + 0x2F6) = 0;
    *(unsigned char*)(a0 + 0x2F7) = 0;
}

/* sn-2.95.3-136 matched TU. */


extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0,
                               int t1, int t2, int t3);

__attribute__((section(".text.pl00_SetCannonDamage")))
void pl00_SetCannonDamage(unsigned char *p)
{
    char hold[16];
    char *e;
    int cnt;
    int i4;
    int n;

    if (*((short *) (p + 0x54A)) > 0) {
        i4 = 4;
        cnt = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = cnt;
        if (i4 < cnt) {
            e = *((char **) (*((char **) (p + 0x278)) + 0x10));
        } else {
            e = 0;
        }
        if (e != 0) {
            SetEffectPos(0, 3, 0, *((void **) (e + 0xF0)), -1, 1.0f);
        }
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x123, p, 0, 0, 0, 0);
        n = *((unsigned short *) (p + 0x54A)) - 10;
        *((short *) (p + 0x54A)) = n;
        if ((short) n <= 0) {
            p[0x2F4] = 2;
            *((short *) (p + 0x54A)) = 0;
            p[0x2F5] = 1;
            p[0x2F6] = 0;
            p[0x2F7] = 1;
        } else {
            p[0x2F4] = 6;
            p[0x2F6] = 4;
            p[0x2F5] = 0;
            p[0x2F7] = 0;
        }
    }
}

__attribute__((section(".text.pl00_DiscardThrowObj")))
void pl00_DiscardThrowObj(void *a0)
{
    char *s0 = (char *)a0;
    char *obj;
    char *objF0;
    char *plF0;
    char *p;
    char *obj2;
    char *p2;
    char *dst;
    volatile float buf[4];

    obj = *(char **)(s0 + 0x6A0);
    if (obj == 0)
        return;

    VU0_SQC2_VF0((void *)buf, 0x0);
    buf[0] = 0.0f;
    buf[1] = 0.1f;
    buf[2] = 0.0f;
    func_001C8D48(obj);

    plF0 = *(char **)(s0 + 0xF0);
    objF0 = *(char **)(*(char **)(s0 + 0x6A0) + 0xF0);
    if (objF0 != plF0) {
        *(float *)(objF0 + 0x0) = *(float *)(plF0 + 0x0);
        *(float *)(objF0 + 0x4) = *(float *)(plF0 + 0x4);
        *(float *)(objF0 + 0x8) = *(float *)(plF0 + 0x8);
    }
    p = *(char **)(*(char **)(s0 + 0x6A0) + 0xF0);
    *(float *)(p + 0x4) = *(float *)(p + 0x4) + 1.6f;

    obj2 = *(char **)(s0 + 0x6A0);
    dst = obj2 + 0x490;
    p2 = *(char **)(obj2 + 0xF0);
    if (dst != p2) {
        *(float *)(obj2 + 0x490) = *(float *)(p2 + 0x0);
        *(float *)(dst + 0x4) = *(float *)(p2 + 0x4);
        *(float *)(dst + 0x8) = *(float *)(p2 + 0x8);
    }
    *(int *)(s0 + 0x6A0) = 0;
}

