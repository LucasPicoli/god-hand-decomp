/* sn-2.95.3-136 matched TU. */

#include "godhand/ActorMove.h"
#include "godhand/cOmBase.h"

extern int cOmBase_checkDamage();
extern void SetField_9E0_1AA500(void *self);
extern void func_001B7EE0(void *self, float f);
extern int cSnd_SeCall_2CBA48(void *a, int b, short c, void *d, void *e, void *f, unsigned int g, int h);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 */


/* End a motion step: clear the step flag; an ending motion or an end command
   goes to the end phase, a restart command runs its move, anything else clears
   the phase. */
__attribute__((section(".text.ActorMove_endStep")))
void ActorMove_endStep(ActorMove *self) {
    int fi = self->flags;
    unsigned long f = fi;
    unsigned long ending;
    unsigned short *cmd;

    self->flags = fi & ~ACTORMOVE_FLAG_STEP;
    ending = (f >> ACTORMOVE_BIT_ENDING) & 1;
    if (ending != 0) {
        ActorMove_setPhase(self, ACTORMOVE_PHASE_END, 0, 0, 0);
        return;
    }
    cmd = self->script;
    switch (cmd[0] & ACTORMOVE_CMD_TYPE) {
    case ACTORMOVE_CMD_END:
        ActorMove_setPhase(self, ACTORMOVE_PHASE_END, 0, 0, 0);
        break;
    case ACTORMOVE_CMD_RESTART:
        func_002B21F0(self, cmd[1]);
    default:
        ActorMove_setPhase(self, 0, 0, 0, 0);
        break;
    }
}

/* sn-2.95.3-136 */


#define HITOBJ_HIT_SE      0x8C        /* hit cue */
#define HITOBJ_SE_PART     5           /* the cue sounds at this child */

/* A breakable object with a damage record and a five-state handler table. */
typedef struct cOmHitObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x24];
    int take;                           /* 0x604 damage record for cOmBase_checkDamage */
} cOmHitObj;

/* One state handler: an adjust added to self, a vtable slot (or -1) and a plain function. */
typedef struct HitObjState { short adj; short slot; int fn; } HitObjState;
typedef struct HitObjStates { HitObjState e[5]; } HitObjStates;






extern HitObjStates D_00427C68;

/* Set the four state bytes. Written with parameters, the stores come out in retail's order. */
static __inline__ void HitObj_setMode(cOmHitObj *self, int mode, int phase, int step, int stepArg)
{
    self->base.mode = mode;
    self->base.phase = phase;
    self->base.step = step;
    self->base.stepArg = stepArg;
}

/* Child idx when it exists, else 0; writes the child count to *frame (a dead store retail keeps). */
static __inline__ int HitObj_child(cOmHitObj *self, unsigned char *frame, int idx)
{
    int n;
    unsigned char ok;
    ok = ((*(int *)frame = n = self->base.partNum), (idx >= 0 && idx < n));
    if (ok) return (int)self->base.children[idx];
    return 0;
}

/* On a hit, finish the object when its hp is gone, else play the hit cue; then run the state handler. */
__attribute__((section(".text.cOmHitObj_damageStep")))
void cOmHitObj_damageStep(cOmHitObj *self)
{
    unsigned char frame[0x10];
    HitObjStates tbl;
    char *e;
    int i8;
    int adj;
    int r;
    int slot; int arg; int (*fp)(int); long entry;

    r = cOmBase_checkDamage(self, self->take);
    if (r == 1) {
        if (self->base.hp <= 0) {
            HitObj_setMode(self, r, 0, 0, 0);
            self->base.flags0 |= COMBASE_F0_ACTIVE;
            return;
        } else {
            int part;
            SetField_9E0_1AA500(self);
            part = HitObj_child(self, frame, HITOBJ_SE_PART);
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, HITOBJ_HIT_SE, self, 0, (void *)part, 0, 0);
        }
    }
    tbl = D_00427C68;
    i8 = self->base.phase * 8;
    e = (char *)&tbl + i8;
    slot = (short)*(unsigned short *)(e + 2);
    if (slot >= 0) {
        int vt = *(int *)((char *)self + (short)*(unsigned short *)(e + 4));
        entry = *(long *)(vt + slot * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&tbl + i8 + 4);
    }
    adj = tbl.e[self->base.phase].adj;
    if (slot >= 0)
        arg = (short)entry + adj;
    else
        arg = adj;
    fp((int)((char *)self + arg));
    func_001B7EE0(self, 3.0f);
}
