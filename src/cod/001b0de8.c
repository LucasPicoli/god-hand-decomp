/* sn-2.95.3-136 matched TU. */

/* Set up an object with two damage-give volumes: clear its counters and 150 radius field, create a volume per slot (kinds 0 and 1), add a 3.0 sphere on its first child body to each and switch them off. Actor 0x360 is scaled 2.0. Returns 1. */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

#define OMGIVE_RADIUS      150.0f
#define OMGIVE_SPHERE      3.0f
#define OMGIVE_ACTOR_BIG   0x360
#define OMGIVE_BIG_SCALE   2.0f
#define OM_OFFSET_SCALE    0x110        /* model scale x, y, z; cOmBase.h does not name it */
#define OM_SCALE(self, i)  (((float *)((char *)(self) + OM_OFFSET_SCALE))[i])
#define OM_F2_SET          0x8
#define OM_F2_CLEAR        0x40

typedef struct cOmTwoVol {
    cOmBase base;
    char unk5E0[0x20];
    int field600;                       /* 0x600 */
    int field604;                       /* 0x604 */
    char unk608[0x28];
    float radius;                       /* 0x630 */
    char unk634[0x1C];
    int field650;                       /* 0x650 */
    int field654;                       /* 0x654 */
    int field658;                       /* 0x658 */
    char unk65C[0xB];
    unsigned char field667;             /* 0x667 */
    int field668;                       /* 0x668 */
    int giveA;                          /* 0x66C damage-give volume 0 */
    int giveB;                          /* 0x670 damage-give volume 1 */
    int sphereA;                        /* 0x674 */
    int sphereB;                        /* 0x678 */
} cOmTwoVol;

extern void func_001B6FB8(void *self);
extern int cDamageManage_CreateDamageGive(void *mgr, int kind, void *obj);
extern int cDamageUnit_AddDamageCollSphere(int unit, void *mtx, void *ofs, float radius);
extern void cDamageUnit_SetDamageCollActive(int unit, int active);
extern char D_00574380[];

__attribute__((section(".text.cOmTwoVol_init")))
int cOmTwoVol_init(cOmTwoVol *self)
{
    float vb[4] __attribute__((aligned(16)));
    float va[4] __attribute__((aligned(16)));
    cOmBase *child;
    float *pa;
    cOmBase *child2;

    func_001B6FB8(self);
    self->field600 = 0;
    self->field604 = 0;
    self->radius = OMGIVE_RADIUS;
    self->giveA = cDamageManage_CreateDamageGive(D_00574380, 0, self);
    child = cOmBase_childAt(&self->base, (int *)vb, 0);
    va[0] = 0.0f;
    pa = va;
    va[1] = 0.0f;
    va[2] = 0.0f;
    pa[3] = 1.0f;
    self->sphereA = cDamageUnit_AddDamageCollSphere(self->giveA, (char *)child + 0x80, pa, OMGIVE_SPHERE);
    cDamageUnit_SetDamageCollActive(self->giveA, 0);
    self->giveB = cDamageManage_CreateDamageGive(D_00574380, 1, self);
    child2 = cOmBase_childAt(&self->base, (int *)vb, 0);
    vb[0] = 0.0f;
    vb[1] = 0.0f;
    vb[2] = 0.0f;
    vb[3] = 1.0f;
    self->sphereB = cDamageUnit_AddDamageCollSphere(self->giveB, (char *)child2 + 0x80, vb, OMGIVE_SPHERE);
    cDamageUnit_SetDamageCollActive(self->giveB, 0);
    self->field650 = 0;
    self->field654 = 0;
    self->field658 = 0;
    if (self->base.actorId == OMGIVE_ACTOR_BIG) {
        OM_SCALE(self, 0) = OMGIVE_BIG_SCALE;
        OM_SCALE(self, 1) = OMGIVE_BIG_SCALE;
        OM_SCALE(self, 2) = OMGIVE_BIG_SCALE;
    }
    self->field668 = 0;
    self->base.flags2 |= OM_F2_SET;
    self->field667 = 0;
    self->base.flags2 &= ~OM_F2_CLEAR;
    return 1;
}
