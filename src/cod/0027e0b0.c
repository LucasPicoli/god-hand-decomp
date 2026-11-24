/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/cOmBase.h"

extern float cEmManage_GetSpeedRate(void *mgr);
extern void SetMotionStep(void *self, float step);
extern cOmBase *Getplayer(void);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);
extern void func_0027E228(void *self);
extern void cModel_ScrollTexture(void *self, float f);
extern void cObjBase_SetSeqEffect(void *self);
extern void func_0027E950(void *self);
extern void cModel_calcParts(void *self);
extern void IK_InverseKinematics(void *ik, void *self);
extern void cModel_calcWorldParts(void *self);
extern void func_0027EDF0(void *self);
extern int D_00747A78;
extern char D_005864F0[];

#define SYSFLAG_FREEZE   0x40000000     /* bit of D_00747A78: the game is frozen */
#define PHASE_OBJ_STATE  0x2F4
#define PHASE_OBJ_RATE   0x5A8         /* speed rate float, past what cOmBase names */

/* One phase entry: this-adjust, method index (or negative: inline handler), table offset in the object. */
typedef struct PhaseEnt {
    short adjust;                       /* 0x00 */
    short index;                        /* 0x02 */
    short tableOff;                     /* 0x04 */
    short unk06;
} PhaseEnt;
typedef struct PhaseTable { PhaseEnt e[1]; } PhaseTable;

extern PhaseTable D_003BFE70;

/* The enemy past cOmBase: the speed rate, the squared distance to the player and the 0x448 IK block. */
typedef struct PhaseEm {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x38];
    float playerDistSq;                 /* 0x618 */
} PhaseEm;

/* Per-frame enemy update unless the game is frozen: refresh the speed rate and motion step, measure the distance to the player, update the model, run the handler of the state's table entry, then the effect, parts, IK, world parts and collision updates, and copy the position. */
__attribute__((section(".text.EmPhase_updateNearPlayer")))
void EmPhase_updateNearPlayer(PhaseEm *self)
{
    char *s0 = (char *)self;
    char *e;
    int i8;
    int f0;
    float rate;
    int type; int arg; int (*fp)(int); long entry;
    if ((D_00747A78 & SYSFLAG_FREEZE) != 0) {
        return;
    }
    rate = cEmManage_GetSpeedRate(D_005864F0);
    *(float *)(s0 + PHASE_OBJ_RATE) = rate;
    SetMotionStep(self, rate);
    self->playerDistSq = capVu0MagnitudeSqXZ(Getplayer()->pos, self->base.pos);
    func_0027E228(self);
    cModel_ScrollTexture(self, *(float *)(s0 + PHASE_OBJ_RATE));
    i8 = *(unsigned char *)(s0 + PHASE_OBJ_STATE) * 8;
    e = (char *)&D_003BFE70 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BFE70 + i8 + 4);
    }
    f0 = D_003BFE70.e[*(unsigned char *)(s0 + PHASE_OBJ_STATE)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cObjBase_SetSeqEffect(self);
    func_0027E950(self);
    cModel_calcParts(self);
    IK_InverseKinematics(s0 + 0x448, self);
    cModel_calcWorldParts(self);
    func_0027EDF0(self);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)self, 0);
    cVec_copy3(&self->base.posA, self->base.pos);
}
