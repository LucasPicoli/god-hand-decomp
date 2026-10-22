/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"
#include "godhand/vu0.h"
#include "godhand/cCollisionSolid.h"

#define GIM_WALL_RADIUS     0.3f
#define GIM_FLOOR_RANGE     20.0f


/* A map gimmick that runs a per-mode handler and then keeps itself out of
 * the walls and on the floor, as its check bits ask. */
typedef struct cOmGimmick {
    cOmBase base;
    char unk5E0[0x20];
    unsigned int checks;                /* 0x600 bit 4 floor, bit 5 walls, bit 6 solids */
} cOmGimmick;

extern EmPhaseTable D_003BDCE0;
extern char D_00462FC0[];

extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern int ChkCollScrWall(void *a0, void *a1, int a2, void *a3, int t0, int t1, float f12);
extern int func_001329C0(void *a0, void *a1, int a2, void *a3, float f12);
extern void cObjBase_SetSeqEffect(void *self);
extern void func_001B76D8(void *self);

/* Per-frame update: run the handler for the current mode, then the solid,
 * wall and floor checks the object has switched on. */
__attribute__((section(".text.func_001B1C78")))
void func_001B1C78(cOmGimmick *self)
{
    cVec hit __attribute__((aligned(16)));
    EmPhaseEnt *e;
    void (*fn)(char *);
    cVtEnt8 entry;
    int index;
    int adjust;
    int delta;
    int slot;

    if (ClearField5B4IfFlagUnset_1B76B0(&self->base) == 0) {
        return;
    }
    slot = self->base.mode * sizeof(EmPhaseEnt);
    e = (EmPhaseEnt *)((char *)&D_003BDCE0 + slot);
    index = e->index;
    if (index >= 0) {
        entry = (*(cVtEnt8 **)((char *)self + e->tableOff))[index - 1];
        fn = (void (*)(char *))entry.pfn;
    } else {
        fn = *(void (**)(char *))((char *)&D_003BDCE0 + slot + 4);
    }
    adjust = D_003BDCE0.e[self->base.mode].adjust;
    if (index >= 0) {
        delta = entry.delta + adjust;
    } else {
        delta = adjust;
    }
    fn((char *)self + delta);
    {
        long solids = self->checks;

        if (((solids >> 6) & 1) == 1) {
            cCollisionSolidManage_ChkHit(D_00462FC0, self);
        }
    }
    {
        long walls = self->checks;

        if (((walls >> 5) & 1) == 1) {
            VU0_SQC2_VF0(&hit, 0);
            if (ChkCollScrWall(self, &hit, 0, 0, 0, 0, GIM_WALL_RADIUS) != 0) {
                self->base.pos->x = hit.x;
                self->base.pos->z = hit.z;
            }
        }
    }
    {
        long floor = self->checks;

        if (((floor >> 4) & 1) == 1) {
            VU0_SQC2_VF0(&hit, 0);
            if (func_001329C0(self, &hit, 0, 0, GIM_FLOOR_RANGE) != 0) {
                self->base.pos->y = hit.y;
            }
        }
    }
    cObjBase_SetSeqEffect(self);
    func_001B76D8(self);
}
