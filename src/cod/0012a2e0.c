/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cNode.h"
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"

extern int D_0044B310;
extern void func_002B5D58(cNode *self, cNode *parent);
extern unsigned char cOmbb_ckFire(void *actor);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);

/* Construct a node: set its name and method table, clear its links, scale it to 1, give both matrices the identity and attach it to parent. */
__attribute__((section(".text.cNode_construct")))
cNode *cNode_construct(cNode *self, int name, cNode *parent) {
    char *m;
    char *m2;
    float one = 1.0f;
    cVec *sc;

    self->name = name;
    self->vt = &D_0044B310;
    sc = &self->scale;
    self->scale.x = one;
    self->parent = 0;
    self->child = 0;
    self->prev = 0;
    self->next = 0;
    self->flagA = 0;
    self->flagB = 0;
    self->flagC = 0;
    sc->y = one;
    sc->z = one;
    sc->w = one;
    VU0_SQC2_VF0(self, 0x30);
    VU0_SQC2_VF0(self, 0x40);
    self->unk90 = 0;
    VU0_SQC2_VF0(self, 0xA0);
    func_002B5D58(self, parent);
    m = self->matLocal;
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, m, 0x30);
    VU0_SQC2(5, m, 0x20);
    VU0_SQC2(6, m, 0x10);
    VU0_SQC2(7, m, 0x0);
    m2 = self->matWorld;
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, m2, 0x30);
    VU0_SQC2(5, m2, 0x20);
    VU0_SQC2(6, m2, 0x10);
    VU0_SQC2(7, m2, 0x0);
    return self;
}

#define FIRE_ACTOR_NUM    2
#define FIRE_RANGE_SQ     12.25f        /* squared XZ distance (3.5 units) */

/* Find the position of a burning actor within range of this object and return it; return this object's own position when there is none. */
__attribute__((section(".text.cGameObj_findBurningPos")))
cVec *cGameObj_findBurningPos(cGameObj *self) {
    cVec pos __attribute__((aligned(16)));
    cEmActor *actor;
    unsigned int i;

    VU0_SQC2_VF0(&pos, 0);
    for (i = 0; i < FIRE_ACTOR_NUM; i++) {
        actor = func_002948C8(&D_005864F0, i);
        if (actor != 0) {
            if (cOmbb_ckFire(actor) != 0) {
                cVec_copy3(&pos, func_001B8720(actor));
                if (!(FIRE_RANGE_SQ < capVu0MagnitudeSqXZ(&pos, self->pos))) {
                    return func_001B8720(actor);
                }
            }
        }
    }
    return self->pos;
}
