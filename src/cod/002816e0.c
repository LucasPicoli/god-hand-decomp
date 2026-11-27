/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */


extern void func_0028EBF0(char *a0, void *a1, int a2);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void cParts_setRotationOrder(void *a0, int a1);
extern void cWorldLight_Init_SatanLight(void *a0, void *a1);
extern char D_00604700[];

#include "godhand/vu0.h"
#include "godhand/cDamageManage.h"
#include "godhand/cGameObj.h"

struct sph { int a; float b; int c; float d; };

__attribute__((section(".text.func_002816E0")))
int func_002816E0(char *a0)
{
    char buf[0x60];
    cGameObj *s1 = a0;
    int v0;
    int n;
    char *base;
    struct sph *q;
    int st;

    VU0_SQC2_VF0(buf, 0x10);
    st = 0x26C;
    s1->emNo = st;
    *(unsigned char *)(buf + 0x31) = 0xFF;
    *(int *)(buf + 0x10) = 0;
    *(int *)(buf + 0x14) = 0;
    *(int *)(buf + 0x18) = 0;
    *(int *)(buf + 0x20) = 0;
    if (func_00282EC0(s1) == 0) {
        return 0;
    }
    func_0028EBF0(s1, buf, 0);
    v0 = *(int *)((char *)s1 + 0x304);
    s1->mode = 0;
    s1->phase = 0;
    s1->step = 0;
    s1->stepArg = 0;
    *(int *)((char *)s1 + 0x1580) = 0;
    *(int *)((char *)s1 + 0x1584) = 0;
    func_002A8578(s1, *(int *)(v0 + 0xC) + v0, *(int *)(v0 + 0x10) + v0, 0, 0.0f, 0, 0);
    moveMotion(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics((char *)s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    s1->objFlags = s1->objFlags | 0x10000;
    s1->life = 0x1770;
    *(unsigned char *)((char *)s1 + 0x616) = 1;
    *(char *)((char *)s1 + 0x531) = -1;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cParts_setRotationOrder(s1, 4);
    s1->hp = s1->hpMax = 1;
    *(int *)((char *)s1 + 0x670) = 0;
    if (s1->emNo != st) {
        struct sph *r;
        *(cDamageTake **)((char *)s1 + 0x670) = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)s1, 1);
        n = s1->partNum;
        *(int *)(buf + 0x40) = n;
        {
            int one = 1;
            if (one < n) {
                base = *(char **)(*(char **)((char *)s1 + 0x278) + 4);
            } else {
                base = 0;
            }
        }
        r = (struct sph *)(buf + 0x50);
        *(int *)(buf + 0x50) = 0;
        *(int *)(buf + 0x54) = 0;
        *(int *)(buf + 0x58) = 0;
        r->d = 1.0f;
        *(int *)((char *)s1 + 0x674) = cDamageUnit_AddDamageCollSphere(
            *(cDamageUnit **)((char *)s1 + 0x670), (const struct cMatrix *)(base + 0x80), (const cVec *)r, 0.25f);
    }
    cCollisionSolidManage_CreateUnit(&D_00462FC0, (cGameObj *)s1, 5, 0.2f);
    q = (struct sph *)(buf + 0x40);
    *(int *)(buf + 0x40) = 0;
    q->b = 0.5f;
    *(int *)(buf + 0x48) = 0;
    q->d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, (cGameObj *)s1, (const struct cMatrix *)((char *)s1 + 0x80), (const cVec *)q, 0.5f);
    *(int *)((char *)s1 + 0x2D0) = *(int *)((char *)s1 + 0x2D0) & 0xBFFFFFFF;
    *(unsigned char *)((char *)s1 + 0x15B0) = 0;
    cWorldLight_Init_SatanLight(D_00604700, s1);
    *(char *)((char *)s1 + 0x617) = 1;
    *(float *)((char *)s1 + 0x1564) = 0.02f;
    *(int *)((char *)s1 + 0x1568) = 0;
    return 1;
}
