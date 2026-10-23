/* sn-2.95.3-136 */
#include "godhand/cObjBase.h"
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/player.h"
#include "godhand/vu0.h"
#include "godhand/cCollisionSolid.h"

/* The derived enemy's fall state, laid over cEm00.unk1560. */
typedef struct cEmFallWork {
    unsigned int flags;                 /* 0x1560 EMFALL_* */
    float gravity;                      /* 0x1564 subtracted from fallVel each frame */
    float fallVel;                      /* 0x1568 */
} cEmFallWork;

#define EMFALL(self)       ((cEmFallWork *)&(self)->unk1560)
#define EMFALL_GROUNDED    1            /* skip the wall and floor checks */

#define EMFALL_WALL_RADIUS 0.4f
#define EMFALL_FLOOR_RANGE 10.0f

extern unsigned int D_00747A78;
extern char D_00462FC0[];
extern cPmf D_003BFAC0[];
extern float capVu0MagnitudeSqXZ(void *a, void *b);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void cObjBase_SetSeqEffect(cObjBase *a0);
extern void cModel_calcParts(cModel *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(cModel *a0);
extern int ChkCollScrWall(void *a0, void *a1, int a2, void *a3, int t0, int t1, float f12);
extern int func_001329C0(void *a0, void *a1, int a2, void *a3, float f12);

/* Per-frame update: run the handler for the current mode, solve the body, then
 * push out of walls and fall onto the floor unless grounded. */
__attribute__((section(".text.func_00277568")))
void func_00277568(cEm00 *self)
{
    cVec wall;
    cVec floor;
    cVec norm;
    short idx;
    void (*fn)(void *self);
    cVtEnt8 e;
    float floorY;

    if (D_00747A78 & 0x40000000) {
        return;
    }
    self->playerDist = capVu0MagnitudeSqXZ(Getplayer()->pos, self->pos);
    EMFALL(self)->flags &= ~EMFALL_GROUNDED;
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    idx = D_003BFAC0[self->mode].index;
    if (idx >= 0) {
        e = (*(cVtEnt8 **)((char *)self + D_003BFAC0[self->mode].u.delta2))[idx - 1];
        fn = e.pfn;
    } else {
        fn = D_003BFAC0[self->mode].u.pfn;
    }
    {
        short d = D_003BFAC0[self->mode].delta;
        int off = idx >= 0 ? e.delta + d : d;

        fn((char *)self + off);
    }
    cObjBase_SetSeqEffect(self);
    cModel_calcParts(self);
    IK_InverseKinematics(self->ik, self);
    cModel_calcWorldParts(self);
    cCollisionSolidManage_ChkHit(D_00462FC0, self);
    if (!(EMFALL(self)->flags & EMFALL_GROUNDED)) {
        VU0_SQC2_VF0(&wall, 0);
        if (ChkCollScrWall(self, &wall, 0, &norm, 0, 0, EMFALL_WALL_RADIUS) != 0) {
            self->pos->x = wall.x;
            self->pos->z = wall.z;
        }
        floorY = self->pos->y;
        VU0_SQC2_VF0_MEM(&floor, 0);
        if (func_001329C0(self, &floor, 0, &norm, EMFALL_FLOOR_RANGE) != 0) {
            floorY = floor.y;
        }
        EMFALL(self)->fallVel -= EMFALL(self)->gravity;
        self->pos->y += EMFALL(self)->fallVel;
        if (self->pos->y < floorY) {
            self->pos->y = floorY;
            EMFALL(self)->fallVel = 0.0f;
        }
    }
    cVec_copy3(&self->posA, self->pos);
}
