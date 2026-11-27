/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/globals.h"

/* sn-2.95.3-136 matched TU. */


extern void func_002799B8(char *a0);

#include "godhand/motion.h"
#include "godhand/cDamageManage.h"
#include "godhand/cGameObj.h"
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void cParts_setRotationOrder(void *a0, int a1);

struct sph { int a; float b; int c; float d; };

__attribute__((section(".text.func_00278110")))
int func_00278110(char *a0, char *a1, void *a2)
{
    char buf[0x20];
    cGameObj *s1 = a0;
    int v0;
    int n;
    char *base;
    struct sph *q;
    char *p;

    s1->emNo = *(int *)(a1 + 0x28);
    if (func_00279938(s1) == 0) {
        return 0;
    }
    func_0028EBF0(s1, a1, a2);
    s1->mode = 0;
    s1->phase = 0;
    s1->step = 0;
    s1->stepArg = 0;
    *(int *)((char *)s1 + 0x1580) = 0;
    *(int *)((char *)s1 + 0x1584) = 0;
    if (s1->emNo == 0x232) {
        func_002799B8(s1);
    }
    v0 = *(int *)((char *)s1 + 0x304);
    func_002A8578(s1, *(int *)(v0 + 0xC) + v0, *(int *)(v0 + 0x10) + v0, 0, 0.0f, 0, 0);
    moveMotion(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics((char *)s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    *(unsigned char *)((char *)s1 + 0x616) = 1;
    *(char *)((char *)s1 + 0x531) = -1;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cParts_setRotationOrder(s1, 4);
    s1->hp = s1->hpMax = 1;
    *(int *)((char *)s1 + 0x670) = 0;
    if (s1->emNo != 0x232) {
        struct sph *r;
        *(cDamageTake **)((char *)s1 + 0x670) = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)s1, 1);
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
        r = (struct sph *)(buf + 0x10);
        *(int *)(buf + 0x10) = 0;
        *(int *)(buf + 0x14) = 0;
        *(int *)(buf + 0x18) = 0;
        r->d = 1.0f;
        *(int *)((char *)s1 + 0x674) = cDamageUnit_AddDamageCollSphere(
            *(cDamageUnit **)((char *)s1 + 0x670), (const struct cMatrix *)(base + 0x80), (const cVec *)r, 0.25f);
    }
    cCollisionSolidManage_CreateUnit(&D_00462FC0, (cGameObj *)s1, 5, 0.2f);
    q = (struct sph *)(buf + 0x0);
    *(int *)(buf + 0x0) = 0;
    q->b = 0.5f;
    *(int *)(buf + 0x8) = 0;
    q->d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, (cGameObj *)s1, (const struct cMatrix *)((char *)s1 + 0x80), (const cVec *)q, 0.5f);
    *(void **)((char *)s1 + 0x156C) = cModel_getMeshPtr_14B730(s1, D_00447CB8);
    *(void **)((char *)s1 + 0x1570) = cModel_getMeshPtr_14B730(s1, D_00447CC0);
    p = *(char **)((char *)s1 + 0x156C);
    if (p != 0) {
        *(int *)(p + 0x380) |= 1;
    }
    *(char *)((char *)s1 + 0x617) = 1;
    *(float *)((char *)s1 + 0x1564) = 0.02f;
    *(int *)((char *)s1 + 0x1568) = 0;
    return 1;
}
