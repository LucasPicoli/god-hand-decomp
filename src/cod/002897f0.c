/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern void func_0028EBF0(char *a0, void *a1, void *a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void moveMotion(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void cParts_setRotationOrder(void *a0, int a1);
extern void cObjBase_KageInit(void *a, void *b, void *c);
extern int cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, void *a2, float f);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);
extern float fRand0_1(void);

extern int Rnd(void);
extern int D_00462FC0;
extern char D_00574380[];
extern char D_003C3F68[];
extern char D_00448DB8[];
extern char D_00448DC0[];
extern char D_00448DC8[];
extern char D_00448DD0[];
extern char D_00448DD8[];
extern char D_00448DE0[];
extern char D_00448DE8[];
extern char D_00448DF0[];
struct sph { int a; float b; int c; float d; };
__attribute__((section(".text.func_002897F0")))
int func_002897F0(char *a0, char *a1, void *a2)
{
    char buf[0x20];
    char *s1 = a0;
    char *s0 = a1;
    int v0;
    int n;
    int base;
    struct sph *r;
    {
        char *a = s1 + 0x1530;
        float *dst = (float *)(s1 + 0x1540);
        float *src = (float *)(s0 + 0x10);
        *(int *)a = *(int *)s0;
        if (dst != src) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
        }
        *(float *)(a + 0x20) = *(float *)(s0 + 0x20);
        *(int *)(a + 0x24) = *(int *)(s0 + 0x24);
        *(int *)(a + 0x28) = *(int *)(s0 + 0x28);
        *(int *)(a + 0x2C) = *(int *)(s0 + 0x2C);
        *(unsigned char *)(a + 0x30) = *(unsigned char *)(s0 + 0x30);
        *(unsigned char *)(a + 0x31) = *(unsigned char *)(s0 + 0x31);
    }
    *(int *)(s1 + 0x564) = *(int *)(s0 + 0x28);
    if (func_0028AC58(s1) == 0) {
        return 0;
    }
    func_0028EBF0(s1, s0, a2);
    {
        float f = 1.1f;
        *(unsigned char *)(s1 + 0x616) = 1;
        *(float *)(s1 + 0x118) = f;
        *(float *)(s1 + 0x114) = f;
        *(float *)(s1 + 0x110) = f;
        *(char *)(s1 + 0x531) = 0;
        *(short *)(s1 + 0x548) = 500;
        *(short *)(s1 + 0x54A) = 500;
    }
    *(unsigned char *)(s1 + 0x2F4) = 0;
    *(unsigned char *)(s1 + 0x2F5) = 0;
    *(unsigned char *)(s1 + 0x2F6) = 0;
    *(unsigned char *)(s1 + 0x2F7) = 0;
    switch (*(int *)(s1 + 0x564)) {
    default:
        v0 = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x50) + v0, *(int *)(v0 + 0x54) + v0, 0.0f, 0, 0, 0);
        break;
    case 0x2A7: case 0x2AB:
        v0 = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x78) + v0, *(int *)(v0 + 0x7C) + v0, 0.0f, 0, 0, 0);
        break;
    }
    moveMotion(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics(s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    cCollisionSolidManage_SetActive(&D_00462FC0, s1, 0);
    {
        float *dst = (float *)(s1 + 0x1590);
        float *src = *(float **)(s1 + 0xF0);
        if (dst != src) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
        }
    }
    cParts_setRotationOrder(s1, 4);
    cObjBase_KageInit(s1, s1 + 0x690, D_003C3F68);
    *(int *)(s1 + 0x670) = cDamageManage_CreateDamageTake(D_00574380, s1, 1);
    n = *(unsigned char *)(s1 + 0x2B4);
    *(int *)(buf + 0x0) = n;
    {
        int one = 1;
        if (one < n) {
            base = *(int *)(*(int *)(s1 + 0x278) + 4);
        } else {
            base = 0;
        }
    }
    r = (struct sph *)(buf + 0x10);
    *(int *)(buf + 0x10) = 0;
    *(int *)(buf + 0x14) = 0;
    *(int *)(buf + 0x18) = 0;
    r->d = 1.0f;
    *(int *)(s1 + 0x674) = cDamageUnit_AddDamageCollSphere(*(int *)(s1 + 0x670), base + 0x80, r, 0.25f);
    n = *(unsigned char *)(s1 + 0x2B4);
    *(int *)(buf + 0x0) = n;
    {
        int three = 3;
        if (three < n) {
            base = *(int *)(*(int *)(s1 + 0x278) + 0xC);
        } else {
            base = 0;
        }
    }
    *(float *)(buf + 0xC) = 1.0f;
    *(int *)(buf + 0x0) = 0;
    *(int *)(buf + 0x4) = 0;
    *(int *)(buf + 0x8) = 0;
    *(int *)(s1 + 0x678) = cDamageUnit_AddDamageCollSphere(*(int *)(s1 + 0x670), base + 0x80, buf, 0.25f);
    n = *(unsigned char *)(s1 + 0x2B4);
    *(int *)(buf + 0x0) = n;
    {
        int t19 = 0x13;
        if (t19 < n) {
            base = *(int *)(*(int *)(s1 + 0x278) + 0x4C);
        } else {
            base = 0;
        }
    }
    *(float *)(buf + 0xC) = 1.0f;
    *(int *)(buf + 0x0) = 0;
    *(int *)(buf + 0x4) = 0;
    *(int *)(buf + 0x8) = 0;
    *(int *)(s1 + 0x67C) = cDamageUnit_AddDamageCollSphere(*(int *)(s1 + 0x670), base + 0x80, buf, 0.25f);
    n = *(unsigned char *)(s1 + 0x2B4);
    *(int *)(buf + 0x0) = n;
    {
        int t23 = 0x17;
        if (t23 < n) {
            base = *(int *)(*(int *)(s1 + 0x278) + 0x5C);
        } else {
            base = 0;
        }
    }
    *(int *)(buf + 0x0) = 0;
    *(int *)(buf + 0x4) = 0;
    *(int *)(buf + 0x8) = 0;
    *(float *)(buf + 0xC) = 1.0f;
    *(int *)(s1 + 0x680) = cDamageUnit_AddDamageCollSphere(*(int *)(s1 + 0x670), base + 0x80, buf, 0.25f);
    cCollisionSolidManage_CreateUnit(&D_00462FC0, s1, 5, 0.2f);
    *(float *)(buf + 0xC) = 1.0f;
    *(float *)(buf + 0x4) = 0.5f;
    *(int *)(buf + 0x0) = 0;
    *(int *)(buf + 0x8) = 0;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, s1, s1 + 0x80, buf, 0.5f);
    *(int *)(s1 + 0x15A8) = 0;
    *(float *)(s1 + 0x15A4) = 0.02f;
    *(float *)(s1 + 0x15AC) = fRand0_1() * 90.0f + 90.0f;
    *(void **)(s1 + 0x15B4) = cModel_getMeshPtr_14B730(s1, D_00448DB8);
    *(void **)(s1 + 0x15B8) = cModel_getMeshPtr_14B730(s1, D_00448DC0);
    *(void **)(s1 + 0x15BC) = cModel_getMeshPtr_14B730(s1, D_00448DC8);
    *(void **)(s1 + 0x15C0) = cModel_getMeshPtr_14B730(s1, D_00448DD0);
    *(void **)(s1 + 0x15C4) = cModel_getMeshPtr_14B730(s1, D_00448DD8);
    *(void **)(s1 + 0x15C8) = cModel_getMeshPtr_14B730(s1, D_00448DE0);
    *(void **)(s1 + 0x15CC) = cModel_getMeshPtr_14B730(s1, D_00448DE8);
    *(void **)(s1 + 0x15D0) = cModel_getMeshPtr_14B730(s1, D_00448DF0);
    { char *p = *(char **)(s1 + 0x15B4);
      if (p != 0) *(int *)(p + 0x380) |= 1; }
    { char *p = *(char **)(s1 + 0x15B8);
      if (p != 0) *(int *)(p + 0x380) |= 1; }
    { char *p = *(char **)(s1 + 0x15BC);
      if (p != 0) *(int *)(p + 0x380) |= 1; }
    { char *p = *(char **)(s1 + 0x15C0);
      if (p != 0) *(int *)(p + 0x380) |= 1; }
    { char *p = *(char **)(s1 + 0x15C4);
      if (p != 0) *(int *)(p + 0x380) |= 1; }
    { char *p = *(char **)(s1 + 0x15C8);
      if (p != 0) *(int *)(p + 0x380) |= 1; }
    { char *p = *(char **)(s1 + 0x15CC);
      if (p != 0) *(int *)(p + 0x380) |= 1; }
    { char *p = *(char **)(s1 + 0x15D0);
      if (p != 0) *(int *)(p + 0x380) |= 1; }
    { char *p = *(char **)(s1 + 0x15B4);
      if (p != 0) *(int *)(p + 0x380) &= 0xFFFFFFFE; }
    { char *p = *(char **)(s1 + 0x15C4);
      if (p != 0) *(int *)(p + 0x380) &= 0xFFFFFFFE; }
    *(unsigned char *)(s1 + 0x15F4) = 1;
    {
        unsigned int k = Rnd() & 0xF;
        *(int *)(s1 + 0x560) = 0x3C1;
        if (k >= 7) *(int *)(s1 + 0x560) = 0x3C8;
        if (k >= 13) *(int *)(s1 + 0x560) = 0x3D1;
        if (k >= 15) *(int *)(s1 + 0x560) = 0x3D0;
    }
    if ((Rnd() & 7) == 0) *(int *)(s1 + 0x560) = 0x3D8;
    if (*(int *)(s1 + 0x1554) & 0x10000000)
        *(int *)(s1 + 0x15A0) |= 0x40;
    return 1;
}
