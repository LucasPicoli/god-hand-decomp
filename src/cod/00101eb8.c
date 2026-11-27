/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/globals.h"
#include "godhand/cObj.h"

extern int moveMotion(void *a0);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern unsigned int D_00747A78;
extern void cEmBase_setTalkButton(void);
extern int Getplayer(void);
extern void cObjBase_SetSeqEffect(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void func_002A87E8(void *a0, int a1);
extern int cSnd_SeEndCk(void *a0, int a1);
extern int func_00291010(void *a0, void *a1, int a2, int a3, float f12, float f13, float f14, int t0);
extern char D_005864F0[];
extern int cModel_setupModel(void *a0, int a1, int a2, int a3, int a4);
extern void cParts_setRotationOrder(void *a0, int a1);
extern void cObjBase_KageInit(void *a0, void *a1, void *a2);

__attribute__((section(".text.func_002826C8")))
void func_002826C8(void *a0)
{
    cObj *s0 = a0;
    int v0;

    switch (s0->step) {
    case 0:
        if (s0->stepArg) {
            if (*(unsigned char *)((char *)s0 + 0x15B0)) {
                v0 = *(int *)((char *)s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0x100) + v0, *(int *)(v0 + 0x104) + v0, 2, 0.0f, 0, 0);
            } else {
                v0 = *(int *)((char *)s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xF0) + v0, *(int *)(v0 + 0xF4) + v0, 2, 0.0f, 0, 0);
            }
        } else {
            if (*(unsigned char *)((char *)s0 + 0x15B0)) {
                v0 = *(int *)((char *)s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xF8) + v0, *(int *)(v0 + 0xFC) + v0, 2, 0.0f, 0, 0);
            } else {
                v0 = *(int *)((char *)s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xE8) + v0, *(int *)(v0 + 0xEC) + v0, 2, 0.0f, 0, 0);
            }
        }
        s0->step = s0->step + 1;
    case 1:
        moveMotion(s0);
        break;
    }
}

__attribute__((section(".text.func_002865F0")))
void func_002865F0(void *a0)
{
    cObj *s0 = a0;
    int v0;
    float *p;
    float *q;

    switch (s0->step) {
    case 0:
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x140) + v0, *(int *)(v0 + 0x144) + v0, 0xA, 0.0f, 0, 0);
        q = (float *)((char *)s0 + 0x5C0);
        p = *(float **)((char *)s0 + 0xF0);
        if (q != p) {
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
        }
        s0->step = s0->step + 1;
    case 1:
        (*(float **)((char *)s0 + 0xF0))[0] = (*(float **)((char *)s0 + 0xF0))[0] * 0.99f + *(float *)((char *)s0 + 0x5C0) * 0.01f;
        (*(float **)((char *)s0 + 0xF0))[2] = (*(float **)((char *)s0 + 0xF0))[2] * 0.99f + *(float *)((char *)s0 + 0x5C8) * 0.01f;
        moveMotion(s0);
        cModel_calcNullPart(s0);
        Add_nullspeed(s0);
        break;
    }
}

__attribute__((section(".text.func_0028A560")))
void func_0028A560(void *a0)
{
    cGameObj *s0 = a0;
    int v0;
    float *p;
    float *q;

    switch (s0->step) {
    case 0:
        switch (s0->emNo) {
        default:
            v0 = *(int *)((char *)s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x50) + v0, *(int *)(v0 + 0x54) + v0, 5, 0.0f, 0, 0);
            break;
        case 0x2A7:
        case 0x2AB:
            v0 = *(int *)((char *)s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x78) + v0, *(int *)(v0 + 0x7C) + v0, 5, 0.0f, 0, 0);
            break;
        }
        q = (float *)((char *)s0 + 0x5C0);
        p = *(float **)((char *)s0 + 0xF0);
        if (q != p) {
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
        }
        s0->step = s0->step + 1;
    case 1:
        (*(float **)((char *)s0 + 0xF0))[0] = (*(float **)((char *)s0 + 0xF0))[0] * 0.99f + *(float *)((char *)s0 + 0x5C0) * 0.01f;
        (*(float **)((char *)s0 + 0xF0))[2] = (*(float **)((char *)s0 + 0xF0))[2] * 0.99f + *(float *)((char *)s0 + 0x5C8) * 0.01f;
        *(int *)((char *)s0 + 0x15A0) = *(int *)((char *)s0 + 0x15A0) | 1;
        moveMotion(s0);
        cModel_calcNullPart(s0);
        Add_nullspeed(s0);
        break;
    }
}

__attribute__((section(".text.func_0028E420")))
void func_0028E420(void *a0)
{
    cGameObj *s0 = a0;
    int v0;
    float *p;
    float *q;

    if ((D_00747A78 & 0x40000000) != 0)
        return;
    cEmBase_setTalkButton();
    switch (s0->step) {
    case 0:
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0xC) + v0, 0, 0, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    case 1:
        v0 = Getplayer();
        cGameObj_SetTgtTurn((cGameObj *)s0, *(cVec **)(v0 + 0xF0), s0->speedRate * 0.09817477f);
        moveMotion(s0);
        break;
    }
    cObjBase_SetSeqEffect(s0);
    cModel_calcParts(s0);
    IK_InverseKinematics((char *)s0 + 0x448, s0);
    cModel_calcWorldParts(s0);
    func_002A87E8(s0, 0);
    if (cSnd_SeEndCk(&D_005FEE00, *(int *)((char *)s0 + 0x1550)) != 0) {
        *(int *)((char *)s0 + 0x1550) = cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x12, a0, 0, 0, 0, 0);
    }
    q = (float *)((char *)s0 + 0x490);
    p = *(float **)((char *)s0 + 0xF0);
    if (q != p) {
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
    }
}

#include "godhand/vu0.h"
#include "godhand/cDamageManage.h"








__attribute__((section(".text.func_00288350")))
void func_00288350(void *a0)
{
    cObj *s0 = a0;
    float buf[4];

    switch (s0->step) {
    case 0: {
        int v0 = *(int *)((char *)s0 + 0x304);
        *(unsigned char *)((char *)s0 + 0x1560) = 5;
        func_002A8578(s0, *(int *)(v0 + 0x140) + v0, *(int *)(v0 + 0x144) + v0, 0xA, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    }
    case 1:
        moveMotion(s0);
        cModel_calcNullPart(s0);
        Add_nullspeed(s0);
        VU0_LQC2(4, *(char **)((char *)s0 + 0xF0), 0);
        VU0_SQC2(4, buf, 0);
        if (func_00291010(D_005864F0, buf, 0, 1, s0->rot.y, 10.0f, 3.14159274f, 0) != 0) {
            s0->step = s0->step + 1;
        }
        break;
    case 2: {
        int v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x48) + v0, *(int *)(v0 + 0x4C) + v0, 0xA, 0.0f, 0, 0);
        *(int *)((char *)s0 + 0x15B0) = *(int *)((char *)s0 + 0x15B0) | 2;
        s0->step = s0->step + 1;
    }
    case 3:
        *(int *)((char *)s0 + 0x15B0) = *(int *)((char *)s0 + 0x15B0) | 1;
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 2;
            s0->step = 0;
            s0->stepArg = 0;
        }
        cModel_calcNullPart(s0);
        Add_nullspeed(s0);
        break;
    }
}

struct sph { int a; float b; int c; float d; };

__attribute__((section(".text.func_00101EB8")))
int func_00101EB8(char *a0)
{
    char buf[0x10];
    cGameObj *s1 = a0;
    int v0;
    int v3;
    int n;
    char *base;
    struct sph *q;
    float z;
    float *p;
    float *r;

    if (cModel_setupModel(s1, *(int *)(*(int *)((char *)s1 + 0x304) + 8) + *(int *)((char *)s1 + 0x304), *(int *)(*(int *)((char *)s1 + 0x304) + 4) + *(int *)((char *)s1 + 0x304), 0, 0) == 0) {
        return 0;
    }
    s1->texFlags = s1->texFlags | 0x8000000;
    cParts_setRotationOrder(s1, 4);
    cObjBase_KageInit(s1, (char *)s1 + 0x5C0, D_003C3F58);
    cCollisionSolidManage_CreateUnit(&D_00462FC0, (cGameObj *)s1, 5, 0.2f);
    q = (struct sph *)(buf + 0x0);
    *(int *)(buf + 0x0) = 0;
    q->b = 0.5f;
    *(int *)(buf + 0x8) = 0;
    q->d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, (cGameObj *)s1, (const struct cMatrix *)((char *)s1 + 0x80), (const cVec *)q, 0.5f);
    s1->hpMax = cCoreSave_getVitalMax(&D_00569B70);
    v3 = cCoreSave_getVital(&D_00569B70);
    if (v3 >= s1->hpMax) {
        s1->hp = *(unsigned short *)((char *)s1 + 0x548);
    } else {
        s1->hp = v3;
    }
    *(cDamageTake **)((char *)s1 + 0x5B0) = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)s1, 0);
    if (*(int *)((char *)s1 + 0x5B0) != 0) {
        struct sph *rr;
        n = s1->partNum;
        *(int *)(buf + 0x0) = n;
        {
            int one = 1;
            if (one < n) {
                base = *(char **)(*(char **)((char *)s1 + 0x278) + 4);
            } else {
                base = 0;
            }
        }
        rr = (struct sph *)(buf + 0x0);
        *(int *)(buf + 0x0) = 0;
        *(int *)(buf + 0x4) = 0;
        *(int *)(buf + 0x8) = 0;
        rr->d = 1.0f;
        *(int *)((char *)s1 + 0x5B4) = cDamageUnit_AddDamageCollSphere(
            *(cDamageUnit **)((char *)s1 + 0x5B0), (const struct cMatrix *)(base + 0x80), (const cVec *)rr, 0.25f);
    }
    s1->phase = 6;
    v0 = *(int *)((char *)s1 + 0x304);
    s1->mode = 0;
    s1->step = 0;
    s1->stepArg = 0;
    z = 0.0f;
    func_002A8578(s1, *(int *)(v0 + 0xC) + v0, *(int *)(v0 + 0x10) + v0, 0, z, 0, 0);
    moveMotion(s1);
    s1->objFlags = s1->objFlags | 2;
    *(float *)((char *)s1 + 0x5BC) = z;
    *(float *)((char *)s1 + 0x5B8) = 0.02f;
    r = (float *)((char *)s1 + 0x490);
    p = *(float **)((char *)s1 + 0xF0);
    if (r != p) {
        r[0] = p[0];
        r[1] = p[1];
        r[2] = p[2];
    }
    D_00586A88 = s1;
    return 1;
}
