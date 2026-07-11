/* sn-2.95.3-136 matched TU. */

extern int SearchData(int a0, void *a1, int a2);
extern int cModel_setupModel(void *a0, int a1, int a2, int a3, int a4);
extern void ReleaseObj(void *a0);
extern void cOmBase_setTexChange(void *a0, int a1);
extern void cParts_setRotationOrder(void *a0, int a1);
extern int D_004289F8;
extern int D_00428A00;
extern int D_00428A08;
extern int D_00428A10;
extern int D_003BD6E8;
extern void ReleaseField6ECByTag564_26B1E8(void *);
extern void func_002B6420(void *a0);
extern void func_00147C88(void *a0, void *a1, int a2);

__attribute__((section(".text.func_001B6FB8")))
int func_001B6FB8(void *a0)
{
    void *s0 = a0;
    int s1;
    int t0;
    int v0;
    int *v1;
    int t8;

    s1 = SearchData(*(int *)((char *)s0 + 0x304), &D_004289F8, 0);
    v0 = SearchData(*(int *)((char *)s0 + 0x304), &D_00428A00, 0);
    if (v0 != 0) {
        t0 = 0;
    } else {
        v0 = SearchData(*(int *)((char *)s0 + 0x304), &D_00428A08, 0);
        if (v0 != 0) {
            t0 = 1;
        } else {
            v0 = SearchData(*(int *)((char *)s0 + 0x304), &D_00428A10, 0);
            t0 = 0;
        }
    }
    if (cModel_setupModel(s0, s1, v0, 0, t0) == 0) {
        ReleaseObj(s0);
        return 0;
    }
    v1 = *(int **)((char *)s0 + 0x5E0);
    if (v1 != 0 && *(unsigned char *)((char *)v1 + 0x2D) != 0) {
        cOmBase_setTexChange(s0, *(unsigned char *)((char *)v1 + 0x2D) - 1);
    }
    cParts_setRotationOrder(s0, 0);
    {
        int f254 = *(int *)((char *)s0 + 0x254);
        int f5B8 = *(int *)((char *)s0 + 0x5B8);
        int f4A8 = *(int *)((char *)s0 + 0x4A8);
        f254 = f254 | 0x80000000;
        *(int *)((char *)s0 + 0x5B8) = f5B8 | 0x40;
        *(int *)((char *)s0 + 0x254) = f254 | 0x8000000;
        *(int *)((char *)s0 + 0x4A8) = f4A8 | 0x10000000;
    }
    *(short *)((char *)s0 + 0x570) = -1;
    *(int *)((char *)s0 + 0x574) = 2;
    *(float *)((char *)s0 + 0x3A8) = 1.0f;
    t8 = *(unsigned short *)((char *)s0 + 0x2FE);
    if (t8 == 0x359) {
        func_0013F558(D_003BD6E8 + 0x1E90, s0);
    }
    return 1;
}

__attribute__((section(".text.func_00270C78")))
void func_00270C78(void *a0) {
    char *s0 = (char *)a0;
    int t;
    if (*(int *)(s0 + 0x564) == 0x265 && (*(int *)(s0 + 0x16D4) & 0x20000000)) {
        t = 0x9F;
        *(unsigned char *)(s0 + 0x2F7) = 1;
        *(unsigned char *)(s0 + 0x2F5) = t;
        *(unsigned char *)(s0 + 0x2F4) = 0;
    } else {
        if (*(int *)(s0 + 0x564) == 0x279) {
            ReleaseField6ECByTag564_26B1E8(s0);
        }
        *(unsigned char *)(s0 + 0x2F4) = 1;
        *(unsigned char *)(s0 + 0x2F5) = 0xF;
        *(unsigned char *)(s0 + 0x2F7) = 0;
    }
    *(unsigned char *)(s0 + 0x2F6) = 0;
}

#include "godhand/vu0.h"




__attribute__((section(".text.func_002B60D0")))
void *func_002B60D0(void *a0, void *a1) {
    unsigned char buf[16] __attribute__((aligned(16)));
    func_002B6420(a1);
    VU0_SQC2_VF0(buf, 0);
    if (*(float *)((char *)a1 + 0x20) != 0.0f &&
        *(float *)((char *)a1 + 0x24) != 0.0f &&
        *(float *)((char *)a1 + 0x28) != 0.0f) {
        func_00147C88(buf, (char *)a1 + 0xB0, 0);
    }
    VU0_LQC2(4, buf, 0);
    VU0_SQC2(4, a0, 0);
    return a0;
}
