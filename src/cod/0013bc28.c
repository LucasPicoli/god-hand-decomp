/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/cDamageUnit.h"

extern int D_00747A78;
extern cOmBase *Getplayer(void);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);
extern void SetCustomIDDispOneOrAll_1F29C0(void *self, int id, int on);
extern void CustomIDWork_SetNumber(void *work, int value);
extern int cIDBase_initialize(void *self, int a1, int a2);
extern int cIDBase_getIDWork(void *self, int idx);
extern int ChkLine(cVec *from, cVec *to, cVec *hit, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

#define SYSFLAG_FREEZE  0x40000000      /* bit of D_00747A78: the game is frozen */

/* A cOmBase-derived enemy that keeps its squared distance to the player at 0x618. */
typedef struct cEmNear {
    cOmBase base;
    char unk5E0[0x38];
    float playerDistSq;                 /* 0x618 */
} cEmNear;




extern void func_00279FF0(cEmNear *self);
extern void cModel_calcParts(cEmNear *self);

/* Per-frame update unless the game is frozen: measure the distance to the player, update the AI, rebuild the parts, copy the position. */
__attribute__((section(".text.cEmNear_updateNearPlayer")))
void cEmNear_updateNearPlayer(cEmNear *self) {
    if ((D_00747A78 & SYSFLAG_FREEZE) == 0) {
        self->playerDistSq = capVu0MagnitudeSqXZ(Getplayer()->pos, self->base.pos);
        func_00279FF0(self);
        cModel_calcParts(self);
        cVec_copy3(&self->base.posA, self->base.pos);
    }
}

/* Number display: shows or hides the five digit elements 0xD..0x11, then sets the number in the work at 0x728. */
__attribute__((section(".text.DigitDisplay_setNumber")))
void DigitDisplay_setNumber(char *self, int on, int value) {
    SetCustomIDDispOneOrAll_1F29C0(self, 0xD, on);
    SetCustomIDDispOneOrAll_1F29C0(self, 0xE, on);
    SetCustomIDDispOneOrAll_1F29C0(self, 0xF, on);
    SetCustomIDDispOneOrAll_1F29C0(self, 0x10, on);
    SetCustomIDDispOneOrAll_1F29C0(self, 0x11, on);
    CustomIDWork_SetNumber(self + 0x728, value);
}

#define IDSET_WORK_NUM  13

/* The id elements this display owns: the first one's local position is mirrored at 0xA0. */
typedef struct IdWork {
    char unk00[0x38];
    float x;                            /* 0x38 */
    float y;                            /* 0x3C */
} IdWork;

typedef struct IdSet {
    char unk000[0x90];
    int unk90;                          /* 0x90 */
    char unk94[0xC];
    float x;                            /* 0xA0 */
    float y;                            /* 0xA4 */
    char unkA8[8];
    IdWork *work[IDSET_WORK_NUM];       /* 0xB0 */
    char unkE4Pad[0xE4 - 0xB0 - 4 * IDSET_WORK_NUM];
    int unkE4;                          /* 0xE4 */
} IdSet;

/* Builds the id set (kind 4): collects the 13 element works and copies the first one's position. */
__attribute__((section(".text.func_0013BC28")))
void func_0013BC28(IdSet *self) {
    IdWork **tbl = self->work;
    unsigned short i;

    self->unk90 = 0;
    cIDBase_initialize(self, 1, 4);
    i = 0;
    do {
        /* byte-offset form: tbl[i] swaps the addu operands */
        *(int *)((char *)tbl + (i << 2)) = cIDBase_getIDWork(self, i);
        i = i + 1;
    } while (i < IDSET_WORK_NUM);
    self->x = self->work[0]->x;
    self->y = self->work[0]->y;
    self->unkE4 = -1;
}

#define FRAME ((char *)&from - 0x30)

/* Casts a probe line from 49 units below the zeroed start point; returns the hit height, or pos->y when nothing is hit.
   The start is never filled from pos: retail copies from's own address onto itself, which gcc drops but keeps the address pseudo. */
__attribute__((section(".text.Pos_probeGroundBelow")))
float Pos_probeGroundBelow(cVec *pos)
{
    cVec from;
    cVec to;
    cVec hit;
    cVec *start = &from;
    int one;

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    cVec_copy3(&from, start);
    one = 1;
    from.y += 1.0f;
    from.y -= 50.0f;
    if (ChkLine(&from, &to, &hit, 0, 2, 0, 0, 0, 0, 0, 0, 0, one) == one) {
        return hit.y;
    }
    return pos->y;
}

/* Resets a damage record: zero flags, two zeroed vectors (w 1.0), the 0x30..0x4C fields, and unit kind 4. */
__attribute__((section(".text.ActorRec_reset")))
void ActorRec_reset(cDamageUnit *self) {
    cVec zero;

    self->flags = 0;
    self->live = 0;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 1.0f;
    cVec_copy3(&self->hitVec, &zero);
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 1.0f;
    cVec_copy3(&self->unk20, &zero);
    self->owner = 0;
    self->unk38 = 0;
    self->nodes = 0;
    self->unk40 = -1;
    self->unk44 = 0;
    self->kind = 0;
    func_001FD988(self, 4);
    self->power = 0;
}
