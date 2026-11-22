/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/motion.h"
#include "godhand/cDamageManage.h"

extern void func_0028EBF0(char *a0, void *a1, int a2);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void cParts_setRotationOrder(void *a0, int a1);

struct sph { int a; float b; int c; float d; };
__attribute__((section(".text.func_0027DE60")))
int func_0027DE60(char *a0)
{
    char buf[0x60];
    char *s1 = a0;
    int v0;
    int n;
    char *base;
    struct sph *q;

    VU0_SQC2_VF0(buf, 0x10);
    *(int *)(s1 + 0x564) = 0x266;
    *(unsigned char *)(buf + 0x31) = 0xFF;
    *(int *)(buf + 0x10) = 0;
    *(int *)(buf + 0x14) = 0;
    *(int *)(buf + 0x18) = 0;
    *(int *)(buf + 0x20) = 0;
    if (func_0027E638(s1) == 0) {
        return 0;
    }
    func_0028EBF0(s1, buf, 0);
    func_0027EDC8(s1);
    v0 = *(int *)(s1 + 0x304);
    *(unsigned char *)(s1 + 0x2F4) = 0;
    *(unsigned char *)(s1 + 0x2F5) = 0;
    *(unsigned char *)(s1 + 0x2F6) = 0;
    *(unsigned char *)(s1 + 0x2F7) = 0;
    *(int *)(s1 + 0x1580) = 0;
    *(int *)(s1 + 0x1584) = 0;
    func_002A8578(s1, *(int *)(v0 + 0xC) + v0, 0, 0, 0.0f, 0, 0);
    moveMotion(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics(s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    *(unsigned char *)(s1 + 0x616) = 1;
    *(char *)(s1 + 0x531) = -1;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cParts_setRotationOrder(s1, 4);
    *(short *)(s1 + 0x54A) = *(short *)(s1 + 0x548) = 1;
    *(int *)(s1 + 0x670) = 0;
    if (*(int *)(s1 + 0x564) != 0x266) {
        struct sph *r;
        *(cDamageTake **)(s1 + 0x670) = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)s1, 1);
        n = *(unsigned char *)(s1 + 0x2B4);
        *(int *)(buf + 0x40) = n;
        {
            int one = 1;
            if (one < n) {
                base = *(char **)(*(char **)(s1 + 0x278) + 4);
            } else {
                base = 0;
            }
        }
        r = (struct sph *)(buf + 0x50);
        *(int *)(buf + 0x50) = 0;
        *(int *)(buf + 0x54) = 0;
        *(int *)(buf + 0x58) = 0;
        r->d = 1.0f;
        *(int *)(s1 + 0x674) = cDamageUnit_AddDamageCollSphere(
            *(cDamageUnit **)(s1 + 0x670), (const struct cMatrix *)(base + 0x80), (const cVec *)r, 0.25f);
    }
    cCollisionSolidManage_CreateUnit(&D_00462FC0, (cGameObj *)s1, 5, 0.2f);
    q = (struct sph *)(buf + 0x40);
    *(int *)(buf + 0x40) = 0;
    q->b = 0.5f;
    *(int *)(buf + 0x48) = 0;
    q->d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, (cGameObj *)s1, (const struct cMatrix *)(s1 + 0x80), (const cVec *)q, 0.5f);
    *(char *)(s1 + 0x617) = 1;
    *(float *)(s1 + 0x1564) = 0.02f;
    *(int *)(s1 + 0x1568) = 0;
    return 1;
}
