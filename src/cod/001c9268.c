/* sn-2.95.3-136 matched TU. */

extern int cDamageManage_CreateDamageGive(int a0, int a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, int a2, float f);
extern void cDamageUnit_SetDamageCollActive(int a0, int a1);
extern void CopyVec3At10_FD308(char *a0, float *a1);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned int t1);
extern int espSys_effDataRegist(void *a0, int a1, void *a2);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern char *CreateObj(int a0, int a1);
extern int cOmWeapon_setParent();
extern int D_00574380;
extern int D_00747B00;
extern int D_007419A0;

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"















__attribute__((section(".text.func_001C9268")))
int func_001C9268(char *p)
{
    float buf[12];
    int n;
    int flag;
    float *sph;

    if (func_001B6FB8(p) == 0) {
        return 0;
    }
    *(int *)(p + 0x600) = 0;
    *(int *)(p + 0x604) = 0;
    *(int *)(p + 0x630) = 0;
    switch (*(unsigned short *)(p + 0x2FE)) {
    default:
        *(int *)(p + 0x668) = 0x64;
        break;
    case 0x361:
        *(int *)(p + 0x668) = 0x78;
        break;
    case 0x362:
        *(int *)(p + 0x668) = 0x5A;
        break;
    case 0x363:
        *(int *)(p + 0x668) = 0x3C;
        break;
    case 0x368:
        *(int *)(p + 0x668) = 0x96;
        break;
    case 0x3B7:
        *(int *)(p + 0x668) = 0x28;
        break;
    case 0x3B4:
        *(int *)(p + 0x668) = 0x3C;
        break;
    case 0x3AD:
        *(int *)(p + 0x668) = 0x3C;
        break;
    case 0x3AE:
        *(int *)(p + 0x668) = 0x3C;
        break;
    case 0x3AA:
        *(int *)(p + 0x668) = 0x3C;
        break;
    case 0x3AB:
        *(int *)(p + 0x668) = 0x3C;
        break;
    case 0x3AF:
        *(int *)(p + 0x668) = 0x1;
        break;
    case 0x36D:
        *(int *)(p + 0x668) = 0x50;
        break;
    case 0x3A9:
        *(int *)(p + 0x668) = 0x5A;
        break;
    case 0x3A8:
        *(int *)(p + 0x668) = 0x5A;
        break;
    case 0x379:
        *(int *)(p + 0x668) = 0x5A;
        break;
    case 0x375:
        *(int *)(p + 0x668) = 0x64;
        break;
    case 0x377:
        *(int *)(p + 0x668) = 0x64;
        break;
    case 0x378:
        *(int *)(p + 0x668) = 0x64;
        break;
    case 0x37B:
        *(int *)(p + 0x668) = 0x5A;
        break;
    case 0x380:
        *(int *)(p + 0x668) = 0x96;
        break;
    case 0x390:
        *(int *)(p + 0x668) = 0x3E7;
        break;
    }

    *(int *)(p + 0x650) = cDamageManage_CreateDamageGive((int)&D_00574380, 1, (int)p);
    flag = *(unsigned char *)(p + 0x2B4);
    *(int *)buf = flag;
    if (flag) {
        n = **(int **)(p + 0x278);
    } else {
        n = 0;
    }
    buf[4] = 0.0f;
    buf[5] = 0.0f;
    buf[6] = 0.0f;
    sph = buf + 4;
    sph[3] = 1.0f;
    *(int *)(p + 0x654) = cDamageUnit_AddDamageCollSphere(*(int *)(p + 0x650), n + 0x80,
                                                          (int)sph, 0.3f);
    cDamageUnit_SetDamageCollActive(*(int *)(p + 0x650), 0);

    *(int *)(p + 0x658) = cDamageManage_CreateDamageGive((int)&D_00574380, 0, (int)p);
    if (*(int *)(p + 0x658) != 0) {
        int flag2 = *(unsigned char *)(p + 0x2B4);
        int n2;
        *(int *)buf = flag2;
        if (flag2) {
            n2 = **(int **)(p + 0x278);
        } else {
            n2 = 0;
        }
        buf[3] = 1.0f;
        buf[0] = 0.0f;
        buf[1] = 0.0f;
        buf[2] = 0.0f;
        *(int *)(p + 0x65C) = cDamageUnit_AddDamageCollSphere(*(int *)(p + 0x658), n2 + 0x80,
                                                              (int)buf, 0.4f);
        cDamageUnit_SetDamageCollActive(*(int *)(p + 0x658), 0);
        *(short *)(*(int *)(p + 0x658) + 0x46) = 0x2F;
        *(int *)(*(int *)(p + 0x658) + 0x4C) = 0x32;
        CopyVec3At10_FD308(*(char **)(p + 0x658), (float *)&D_00747B00);
        {
            char *dg = *(char **)(p + 0x658);
            *(int *)(dg + 0x40) = -1;
            *(short *)(dg + 0x44) = 0;
        }
    }

    if (*(unsigned short *)(p + 0x2FE) == 0x3B7) {
        SetEffect(0x58, 0x8D, p, 0, 8, 0xFFFFFFFF);
    }
    switch (*(unsigned short *)(p + 0x2FE)) {
    case 0x3AE:
        {
            char *e = *(char **)(p + 0x304);
            espSys_effDataRegist(&D_007419A0, 0x206,
                                 (void *)(*(int *)(e + 0xC) + (int)e));
        }
        SetEffect(0x206, 1, p, 0, 8, 0xFFFFFFFF);
        break;
    case 0x3B7:
        SetEffect(0x58, 0x8D, p, 0, 8, 0xFFFFFFFF);
        break;
    case 0x3B8:
        SetEffect(0x69, 4, p, 0, 8, 0xFFFFFFFF);
        SetEffect(0x69, 9, p, 0, -1, 0xFFFFFFFF);
        break;
    case 0x3B9:
        SetEffect(0x69, 5, p, 0, 8, 0xFFFFFFFF);
        SetEffect(0x69, 0xA, p, 0, -1, 0xFFFFFFFF);
        break;
    case 0x3BA:
        SetEffect(0x69, 6, p, 0, 8, 0xFFFFFFFF);
        SetEffect(0x69, 0xB, p, 0, -1, 0xFFFFFFFF);
        break;
    case 0x369:
        break;
    }
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);

    switch (*(unsigned short *)(p + 0x2FE)) {
    default:
        *(char *)(p + 0x2F4) = 0;
        *(char *)(p + 0x2F6) = 2;
        *(char *)(p + 0x2F5) = 0;
        *(char *)(p + 0x2F7) = 0;
        break;
    case 0x3A8:
    case 0x3A9:
    case 0x3AA:
    case 0x3AB:
    case 0x3AD:
    case 0x3AE:
    case 0x3B4:
        *(char *)(p + 0x2F4) = 0;
        *(char *)(p + 0x2F6) = 3;
        *(char *)(p + 0x2F5) = 0;
        *(char *)(p + 0x2F7) = 0;
        break;
    case 0x36A:
        *(float *)(p + 0x118) = 1.3f;
        *(float *)(p + 0x114) = 1.3f;
        *(float *)(p + 0x110) = 1.3f;
        break;
    case 0x382:
        *(char *)(p + 0x2F4) = 0;
        *(char *)(p + 0x2F5) = 0x17;
        *(char *)(p + 0x2F6) = 0;
        *(char *)(p + 0x2F7) = 0;
        break;
    case 0x42A:
        *(char *)(p + 0x2F4) = 0;
        *(char *)(p + 0x2F5) = 0x16;
        *(char *)(p + 0x2F6) = 0;
        *(char *)(p + 0x2F7) = 0;
        break;
    }

    if (*(unsigned short *)(p + 0x2FE) == 0x42A) {
        *(int *)(p + 0x5B8) |= 0x40;
    } else {
        *(int *)(p + 0x5B8) &= ~0x40;
    }

    *(char *)(p + 0x688) = 0;
    *(int *)(p + 0x68C) = 0;
    if (*(unsigned short *)(p + 0x2FE) == 0x37B || *(unsigned short *)(p + 0x2FE) == 0x390) {
        char *obj = CreateObj(0x37C, 0xFFFF);
        *(char **)(p + 0x68C) = obj;
        if (obj != 0) {
            char *cls;
            int (*fn)(char *);
            short off;
            float *src;
            float *src2;
            float *dst;
            float *d490;
            int *p100;

            VU0_SQC2_VF0(buf, 0x0);
            VU0_SQC2_VF0(buf, 0x20);
            cls = *(char **)(obj + 0x214);
            fn = *(int (**)(char *))(cls + 0x44);
            off = *(short *)(cls + 0x40);
            fn(obj + off);

            dst = *(float **)(*(char **)(p + 0x68C) + 0xF0);
            src = *(float **)(p + 0xF0);
            if (dst != src) {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
            src2 = *(float **)(p + 0xF0);
            d490 = (float *)(*(char **)(p + 0x68C) + 0x490);
            if (d490 != src2) {
                d490[0] = src2[0];
                d490[1] = src2[1];
                d490[2] = src2[2];
            }
            p100 = (int *)(*(char **)(p + 0x68C) + 0x100);
            p100[0] = 0;
            p100[1] = 0;
            p100[2] = 0;
            buf[0] = 0.0f;
            buf[1] = 0.0f;
            buf[2] = 0.0f;
            buf[8] = 0.0f;
            buf[9] = 0.0f;
            buf[10] = 0.0f;
            cOmWeapon_setParent(*(int *)(p + 0x68C), p, 2, buf, (char *)buf + 0x20);
        }
    }

    if (*(unsigned short *)(p + 0x2FE) == 0x376) {
        int f = *(int *)(p + 0x2D0);
        f &= ~0x20000000;
        f |= 0x80000000;
        *(int *)(p + 0x2D0) = f;
    }
    return 1;
}
