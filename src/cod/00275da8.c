/* sn-2.95.3-136: func_00275DA8, rebuild collision unit/spheres and the three damage-take spheres for enemy type 0x265. */
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"
extern int ClearAndResetFields_1FE278(void *a0, int a1);
extern void cCollisionSolidManage_ReleaseUnit(void *a0, void *a1);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);
extern int D_00462FC0;
extern char D_00574380[];
struct sph { int a; float b; float c; float d; };

__attribute__((section(".text.func_00275DA8")))
void func_00275DA8(char *self)
{
    struct sph q;
    unsigned int i;
    cOmBase *child;

    if ((*(int *)(self + 0x564) ^ 0x265) != 0)
        return;
    if (ClearAndResetFields_1FE278(D_00574380, *(int *)(self + 0x698))) {
        *(int *)(self + 0x698) = 0;
        for (i = 0; i < 5; i++)
            ((int *)(self + 0x69C))[i] = -1;
    }
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, self);
    cCollisionSolidManage_CreateUnit(&D_00462FC0, self, 0, 0.2f);
    q.a = 0;
    q.b = 0.5f;
    q.c = 0.0f;
    q.d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self + 0x80, &q, 1.8f);
    q.a = 0;
    q.b = 0.5f;
    q.c = -0.8f;
    q.d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self + 0x80, &q, 1.0f);
    q.a = 0;
    q.b = 0.5f;
    q.c = -1.4f;
    q.d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self + 0x80, &q, 1.0f);
    *(int *)(self + 0x698) = cDamageManage_CreateDamageTake(D_00574380, self, 1);

    child = cOmBase_childAt((cOmBase *)self, &q.a, 2);
    q.a = 0;
    q.b = -0.3f;
    q.c = 0.0f;
    q.d = 1.0f;
    *(int *)(self + 0x69C) = cDamageUnit_AddDamageCollSphere(*(int *)(self + 0x698), (char *)child + 0x80, &q,
                                                           *(float *)(self + 0x118) * 0.7f);

    child = cOmBase_childAt((cOmBase *)self, &q.a, 0x13);
    q.a = 0;
    q.b = -0.3f;
    q.c = 0.4f;
    q.d = 1.0f;
    *(int *)(self + 0x6A0) = cDamageUnit_AddDamageCollSphere(*(int *)(self + 0x698), (char *)child + 0x80, &q,
                                                           *(float *)(self + 0x118) * 0.8f);

    child = cOmBase_childAt((cOmBase *)self, &q.a, 0x20);
    q.a = 0;
    q.b = 0.0f;
    q.c = 0.0f;
    q.d = 1.0f;
    *(int *)(self + 0x6A4) = cDamageUnit_AddDamageCollSphere(*(int *)(self + 0x698), (char *)child + 0x80, &q,
                                                           *(float *)(self + 0x118) * 0.7f);
    *(int *)(self + 0x6A8) = -1;
    *(int *)(self + 0x6AC) = -1;
}
