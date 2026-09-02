/* sn-2.95.3-136 matched TU. */

extern void func_0028EBF0(char *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void moveMotion(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void cParts_setRotationOrder(void *a0, int a1);
extern int AllocActiveSlot_1FE218(void *a0, void *a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, void *a2, float f);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);
extern int AddActiveEntry_1FECE0(void *a0, int a1, int a2);
extern char *CreateObj(int a0, int a1);
extern int cOmWeapon_setParent();
extern void Obj1D00_ClearState_8(char *a0);
extern int D_00462FC0;
extern char D_00574380[];
extern char D_005864E0[];

/* func_0027B810 - object/enemy Init.  MATCH (exact) under sn-2.95.3-136.
 *
 * Sets state 0x263, runs func_0027D150 (early-return 0 on failure), rebuilds
 * the model (func_0028EBF0 / func_002A8578 / moveMotion / cModel_calcParts /
 * IK / cModel_calcWorldParts), registers the collision unit + sphere, allocates
 * the damage slot when the state word moved, then spawns object 0x369, copies
 * its position from ours through the vtable slot at +0x40/+0x44, and parents it
 * as a weapon.
 *
 * Steering notes (all byte-verified by A/B on this function):
 *   - ONE 0x70-byte local rooted at sp+0 so every sqc2 $vf0 keeps an $sp base
 *     (levers: vu0-sqc2-sp-resident-base).
 *   - `int one = 1; if (one < n)` is what produces retail's `li $v1,1` +
 *     `slt $v1,$v1,$a0`; the literal `n > 1` folds to `slti`.  The variable
 *     MUST be block-scoped after the call, or cse hoovers up every other
 *     literal 1 in the function and burns a callee-saved register.
 *   - the paired `sh` needs the chained assignment to emit high-offset-first.
 *   - the two `*(s1+0x15B0)` reloads and the two `*(s1+0xF0)` reloads are
 *     DISTINCT locals; reusing one variable collapses them into one pseudo and
 *     permutes $v0/$v1/$a0 across both copy blocks.
 *   - the vtable temporaries must be declared vt, off, fn in that order.
 */
#include "godhand/vu0.h"






















struct sph { int a; float b; int c; float d; };

__attribute__((section(".text.func_0027B810")))
int func_0027B810(char *a0)
{
    char buf[0x70];
    char *s1 = a0;
    int v0;
    int n;
    int base;
    struct sph *q;

    VU0_SQC2_VF0(buf, 0x10);
    *(int *)(s1 + 0x564) = 0x263;
    *(unsigned char *)(buf + 0x31) = 0xFF;
    *(int *)(buf + 0x10) = 0;
    *(int *)(buf + 0x14) = 0;
    *(int *)(buf + 0x18) = 0;
    *(int *)(buf + 0x20) = 0;
    if (func_0027D150(s1) == 0) {
        return 0;
    }
    func_0028EBF0(s1, buf, 0);
    v0 = *(int *)(s1 + 0x304);
    *(unsigned char *)(s1 + 0x2F4) = 0;
    *(unsigned char *)(s1 + 0x2F5) = 0;
    *(unsigned char *)(s1 + 0x2F6) = 0;
    *(unsigned char *)(s1 + 0x2F7) = 0;
    *(int *)(s1 + 0x1580) = 0;
    *(int *)(s1 + 0x1584) = 0;
    func_002A8578(s1, *(int *)(v0 + 0x10) + v0, *(int *)(v0 + 0x14) + v0, 0.0f, 0, 0, 0);
    moveMotion(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics(s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    *(unsigned char *)(s1 + 0x616) = 1;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    cParts_setRotationOrder(s1, 4);
    *(short *)(s1 + 0x54A) = *(short *)(s1 + 0x548) = 1;
    *(int *)(s1 + 0x670) = 0;
    if (*(int *)(s1 + 0x564) != 0x263) {
        struct sph *r;
        *(int *)(s1 + 0x670) = AllocActiveSlot_1FE218(&D_00574380, s1, 1);
        n = *(unsigned char *)(s1 + 0x2B4);
        *(int *)(buf + 0x40) = n;
        {
            int one = 1;
            if (one < n) {
                base = *(int *)(*(int *)(s1 + 0x278) + 4);
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
            *(int *)(s1 + 0x670), base + 0x80, r, 0.25f);
    }
    cCollisionSolidManage_CreateUnit(&D_00462FC0, s1, 5, 0.2f);
    q = (struct sph *)(buf + 0x40);
    *(int *)(buf + 0x40) = 0;
    q->b = 0.5f;
    *(int *)(buf + 0x48) = 0;
    q->d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, s1, s1 + 0x80, q, 0.5f);
    v0 = *(int *)(s1 + 0x304);
    AddActiveEntry_1FECE0(&D_005864E0, 0x369, *(int *)(v0 + 0xC) + v0);
    {
        char *obj = CreateObj(0x369, 0xFFFF);
        *(char **)(s1 + 0x15B0) = obj;
        if (obj != 0) {
            char *p2;
            char *p3;
            float *src1;
            float *src2;
            float *dst;
            float *p490;
            int *p100;

            VU0_SQC2_VF0(buf, 0x40);
            VU0_SQC2_VF0(buf, 0x60);
            {
                char *v1 = *(char **)(obj + 0x214);
                short off = *(short *)(v1 + 0x40);
                int (*fn)(char *) = *(int (**)(char *))(v1 + 0x44);
                fn(obj + off);
            }
            src1 = *(float **)(s1 + 0xF0);
            dst = *(float **)(*(char **)(s1 + 0x15B0) + 0xF0);
            if (dst != src1) {
                dst[0] = src1[0];
                dst[1] = src1[1];
                dst[2] = src1[2];
            }
            p2 = *(char **)(s1 + 0x15B0);
            src2 = *(float **)(s1 + 0xF0);
            p490 = (float *)(p2 + 0x490);
            if (p490 != src2) {
                p490[0] = src2[0];
                p490[1] = src2[1];
                p490[2] = src2[2];
            }
            p3 = *(char **)(s1 + 0x15B0);
            p100 = (int *)(p3 + 0x100);
            p100[0] = 0;
            p100[1] = 0;
            p100[2] = 0;
            *(int *)(buf + 0x40) = 0;
            *(int *)(buf + 0x44) = 0;
            *(int *)(buf + 0x48) = 0;
            *(int *)(buf + 0x60) = 0;
            *(int *)(buf + 0x64) = 0;
            *(int *)(buf + 0x68) = 0;
            cOmWeapon_setParent(*(char **)(s1 + 0x15B0), s1, 0x12, q, buf + 0x60);
            Obj1D00_ClearState_8(*(char **)(s1 + 0x15B0));
        }
    }
    *(char *)(s1 + 0x531) = -1;
    *(char *)(s1 + 0x617) = 1;
    *(float *)(s1 + 0x1564) = 0.02f;
    *(int *)(s1 + 0x15B4) = 0;
    *(int *)(s1 + 0x1568) = 0;
    *(int *)(s1 + 0x15D4) = 0;
    return 1;
}
