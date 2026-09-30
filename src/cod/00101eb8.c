/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void CopyVec3From110To120_14A2B0(void *a0);
extern void Forward30A2B0_2DA9B8(void *a0);
extern unsigned int D_00747A78;
extern char D_005FEE00[];
extern void func_0028E580(void);
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(char *a0, int a1, float f12);
extern void cObjBase_SetSeqEffect(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void func_002A87E8(void *a0, int a1);
extern int cSnd_SeEndCk(void *a0, int a1);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int func_00291010(void *a0, void *a1, int a2, int a3, float f12, float f13, float f14, int t0);
extern char D_005864F0[];
extern int cModel_setupModel(void *a0, int a1, int a2, int a3, int a4);
extern void cParts_setRotationOrder(void *a0, int a1);
extern void cObjBase_KageInit(void *a0, void *a1, void *a2);
extern int AllocActiveSlot_1FE218(void *a0, void *a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, void *a2, float f);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);
extern int GetField80ViaPtr_1FAC80(void *a0);
extern int Obj0000_Get_Field_84_Or_ReturnK_64_1FAC68(void *a0);
extern int D_00462FC0;
extern char D_00574380[];
extern char D_003C3F58[];
extern char D_00569B70[];
extern char *D_00586A88;

__attribute__((section(".text.func_002826C8")))
void func_002826C8(void *a0)
{
    char *s0 = (char *)a0;
    int v0;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s0 + 0x2F7)) {
            if (*(unsigned char *)(s0 + 0x15B0)) {
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0x100) + v0, *(int *)(v0 + 0x104) + v0, 2, 0.0f, 0, 0);
            } else {
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xF0) + v0, *(int *)(v0 + 0xF4) + v0, 2, 0.0f, 0, 0);
            }
        } else {
            if (*(unsigned char *)(s0 + 0x15B0)) {
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xF8) + v0, *(int *)(v0 + 0xFC) + v0, 2, 0.0f, 0, 0);
            } else {
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xE8) + v0, *(int *)(v0 + 0xEC) + v0, 2, 0.0f, 0, 0);
            }
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        break;
    }
}

__attribute__((section(".text.func_002865F0")))
void func_002865F0(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    float *p;
    float *q;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x140) + v0, *(int *)(v0 + 0x144) + v0, 0xA, 0.0f, 0, 0);
        q = (float *)(s0 + 0x5C0);
        p = *(float **)(s0 + 0xF0);
        if (q != p) {
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        (*(float **)(s0 + 0xF0))[0] = (*(float **)(s0 + 0xF0))[0] * 0.99f + *(float *)(s0 + 0x5C0) * 0.01f;
        (*(float **)(s0 + 0xF0))[2] = (*(float **)(s0 + 0xF0))[2] * 0.99f + *(float *)(s0 + 0x5C8) * 0.01f;
        moveMotion(s0);
        CopyVec3From110To120_14A2B0(s0);
        Forward30A2B0_2DA9B8(s0);
        break;
    }
}

__attribute__((section(".text.func_0028A560")))
void func_0028A560(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    float *p;
    float *q;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        switch (*(int *)(s0 + 0x564)) {
        default:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x50) + v0, *(int *)(v0 + 0x54) + v0, 5, 0.0f, 0, 0);
            break;
        case 0x2A7:
        case 0x2AB:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x78) + v0, *(int *)(v0 + 0x7C) + v0, 5, 0.0f, 0, 0);
            break;
        }
        q = (float *)(s0 + 0x5C0);
        p = *(float **)(s0 + 0xF0);
        if (q != p) {
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        (*(float **)(s0 + 0xF0))[0] = (*(float **)(s0 + 0xF0))[0] * 0.99f + *(float *)(s0 + 0x5C0) * 0.01f;
        (*(float **)(s0 + 0xF0))[2] = (*(float **)(s0 + 0xF0))[2] * 0.99f + *(float *)(s0 + 0x5C8) * 0.01f;
        *(int *)(s0 + 0x15A0) = *(int *)(s0 + 0x15A0) | 1;
        moveMotion(s0);
        CopyVec3From110To120_14A2B0(s0);
        Forward30A2B0_2DA9B8(s0);
        break;
    }
}

__attribute__((section(".text.func_0028E420")))
void func_0028E420(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    float *p;
    float *q;

    if ((D_00747A78 & 0x40000000) != 0)
        return;
    func_0028E580();
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0xC) + v0, 0, 0, 0.0f, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        v0 = Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(int *)(v0 + 0xF0), *(float *)(s0 + 0x5A8) * 0.09817477f);
        moveMotion(s0);
        break;
    }
    cObjBase_SetSeqEffect(s0);
    cModel_calcParts(s0);
    IK_InverseKinematics(s0 + 0x448, s0);
    cModel_calcWorldParts(s0);
    func_002A87E8(s0, 0);
    if (cSnd_SeEndCk(D_005FEE00, *(int *)(s0 + 0x1550)) != 0) {
        *(int *)(s0 + 0x1550) = cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x12, s0, 0, 0, 0, 0);
    }
    q = (float *)(s0 + 0x490);
    p = *(float **)(s0 + 0xF0);
    if (q != p) {
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
    }
}

#include "godhand/vu0.h"








__attribute__((section(".text.func_00288350")))
void func_00288350(void *a0)
{
    char *s0 = (char *)a0;
    float buf[4];

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int v0 = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1560) = 5;
        func_002A8578(s0, *(int *)(v0 + 0x140) + v0, *(int *)(v0 + 0x144) + v0, 0xA, 0.0f, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 1:
        moveMotion(s0);
        CopyVec3From110To120_14A2B0(s0);
        Forward30A2B0_2DA9B8(s0);
        VU0_LQC2(4, *(char **)(s0 + 0xF0), 0);
        VU0_SQC2(4, buf, 0);
        if (func_00291010(D_005864F0, buf, 0, 1, *(float *)(s0 + 0x104), 10.0f, 3.14159274f, 0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 2: {
        int v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x48) + v0, *(int *)(v0 + 0x4C) + v0, 0xA, 0.0f, 0, 0);
        *(int *)(s0 + 0x15B0) = *(int *)(s0 + 0x15B0) | 2;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 3:
        *(int *)(s0 + 0x15B0) = *(int *)(s0 + 0x15B0) | 1;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 2;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        CopyVec3From110To120_14A2B0(s0);
        Forward30A2B0_2DA9B8(s0);
        break;
    }
}

struct sph { int a; float b; int c; float d; };

__attribute__((section(".text.func_00101EB8")))
int func_00101EB8(char *a0)
{
    char buf[0x10];
    char *s1 = a0;
    int v0;
    int v3;
    int n;
    int base;
    struct sph *q;
    float z;
    float *p;
    float *r;

    if (cModel_setupModel(s1, *(int *)(*(int *)(s1 + 0x304) + 8) + *(int *)(s1 + 0x304), *(int *)(*(int *)(s1 + 0x304) + 4) + *(int *)(s1 + 0x304), 0, 0) == 0) {
        return 0;
    }
    *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x8000000;
    cParts_setRotationOrder(s1, 4);
    cObjBase_KageInit(s1, s1 + 0x5C0, D_003C3F58);
    cCollisionSolidManage_CreateUnit(&D_00462FC0, s1, 5, 0.2f);
    q = (struct sph *)(buf + 0x0);
    *(int *)(buf + 0x0) = 0;
    q->b = 0.5f;
    *(int *)(buf + 0x8) = 0;
    q->d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, s1, s1 + 0x80, q, 0.5f);
    *(short *)(s1 + 0x548) = GetField80ViaPtr_1FAC80(D_00569B70);
    v3 = Obj0000_Get_Field_84_Or_ReturnK_64_1FAC68(D_00569B70);
    if (v3 >= *(short *)(s1 + 0x548)) {
        *(short *)(s1 + 0x54A) = *(unsigned short *)(s1 + 0x548);
    } else {
        *(short *)(s1 + 0x54A) = v3;
    }
    *(int *)(s1 + 0x5B0) = AllocActiveSlot_1FE218(D_00574380, s1, 0);
    if (*(int *)(s1 + 0x5B0) != 0) {
        struct sph *rr;
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
        rr = (struct sph *)(buf + 0x0);
        *(int *)(buf + 0x0) = 0;
        *(int *)(buf + 0x4) = 0;
        *(int *)(buf + 0x8) = 0;
        rr->d = 1.0f;
        *(int *)(s1 + 0x5B4) = cDamageUnit_AddDamageCollSphere(
            *(int *)(s1 + 0x5B0), base + 0x80, rr, 0.25f);
    }
    *(unsigned char *)(s1 + 0x2F5) = 6;
    v0 = *(int *)(s1 + 0x304);
    *(unsigned char *)(s1 + 0x2F4) = 0;
    *(unsigned char *)(s1 + 0x2F6) = 0;
    *(unsigned char *)(s1 + 0x2F7) = 0;
    z = 0.0f;
    func_002A8578(s1, *(int *)(v0 + 0xC) + v0, *(int *)(v0 + 0x10) + v0, 0, z, 0, 0);
    moveMotion(s1);
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 2;
    *(float *)(s1 + 0x5BC) = z;
    *(float *)(s1 + 0x5B8) = 0.02f;
    r = (float *)(s1 + 0x490);
    p = *(float **)(s1 + 0xF0);
    if (r != p) {
        r[0] = p[0];
        r[1] = p[1];
        r[2] = p[2];
    }
    D_00586A88 = s1;
    return 1;
}
