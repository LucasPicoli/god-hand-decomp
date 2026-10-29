/* sn-2.95.3-136 matched TU. */

#include "godhand/cEmSetParam.h"
#include "godhand/cOmBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/cGameObj.h"
#include "godhand/vu0.h"

extern void cEmSetParam_setEm(cEmSetParam *param, int entry);
extern void cEmWrap_StartAction(void *wrap);
extern char D_005E8040[];
extern char *Pool_createObjWithScale(char *pool);
extern void KeySlotTable_set(char *slot, int a1, int a2);
extern void CustomIDWork_SetOffsetPosY(CustomIDWork *self, int y);
extern void CustomIDWork_SetMoveOffsetPosY(CustomIDWork *self, int from, int to, int frames);
extern void func_001DEE60(void *self, int sel, int on);
extern char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *snd, int b, int c, void *obj, int e, int f, int g, int h);
extern float Turn_dest_dir(float cur, float dest, float speed);
extern float Adjust_theta(float f12);
extern void StoreVecFromFieldB0_2B6160(cVec *dst, void *obj);
extern void func_002E6B88(void *obj, float y);
extern int ClearField5B4IfFlagUnset_1B76B0(int self);
extern void func_001B76D8(void *self);

/* Arena wave step: step 0 defeats every enemy and starts a 600 frame timer; step 1 waits until two enemies are down or the timer runs out, then sets the first enemy up and starts its action. */
#define ARENA_WAIT_FRAMES  0x258
#define ARENA_DOWN_NEEDED  2

typedef struct ArenaEm {
    char unk000[0xB88];
    int downNum;                        /* 0xB88 enemies knocked down this wave */
    int waveNum;                        /* 0xB8C waves started */
    char unkB90[4];
    int introStep;                      /* 0xB94 */
    char unkB98[8];
    int timer;                          /* 0xBA0 frames left to wait */
} ArenaEm;

extern void ColiseumBattle_DefeatAllEnemies(ArenaEm *self);

__attribute__((section(".text.ArenaEm_stepFirstWave")))
void ArenaEm_stepFirstWave(ArenaEm *self)
{
    char buf[0x10];
    switch (self->introStep) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->timer = ARENA_WAIT_FRAMES;
        self->introStep = self->introStep + 1;
        break;
    case 1:
        if (self->downNum >= ARENA_DOWN_NEEDED || self->timer == 0) {
            buf[0] = 0;
            cEmSetParam_setEm(&D_00586AB0, 0);
            cEmWrap_StartAction(buf);
            self->waveNum = self->waveNum + 1;
            self->introStep = self->introStep + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    }
}

typedef struct KeyHolder {
    char unk00[0xC0];
    cVec *pos;              /* 0xC0 */
} KeyHolder;

typedef struct KeyLink {
    char unk00[0x34];
    KeyHolder *holder;      /* 0x34 */
} KeyLink;

/* An object that follows a position taken from a key-slot holder. */
typedef struct KeyFollower {
    cVec posA;              /* 0x00 */
    cVec posB;              /* 0x10 */
    char unk20[8];
    KeyLink *link;          /* 0x28 */
    short id;               /* 0x2C */
    unsigned char ready;    /* 0x2E */
} KeyFollower;





/* Take a key slot from the scaled pool (-1 when none is left), register it, and start both
 * position copies from the holder's position. Returns the object id. */
__attribute__((section(".text.KeyFollower_attachScaled")))
int KeyFollower_attachScaled(KeyFollower *self, int a1, int a2, int a3, int key)
{
    char *slot;
    slot = Pool_createObjWithScale(D_005E8040);
    self->link = (KeyLink *)slot;
    if (slot == 0) {
        return -1;
    }
    KeySlotTable_set(slot + 0x14, 1, key);
    cVec_copy3(&self->posB, self->link->holder->pos);
    cVec_copy3(&self->posA, &self->posB);
    self->ready = 1;
    return self->id;
}

/* The element that slides in and out sits at 0xDC of the owner. */
#define OWNER_SLIDE_IDW(self) ((CustomIDWork *)((char *)(self) + 0xDC))
#define SLIDE_HIDDEN_Y  (-0x46)

/* Place or slide the element in (sel 2: down from hidden to shown over 10 frames; sel 3:
 * the way back; sel 1: shown at once; others: hidden). */
__attribute__((section(".text.CustomIDOwner_setSlideStateB")))
void CustomIDOwner_setSlideStateB(void *self, unsigned char sel)
{
    switch (sel) {
    case 0:
    default:
        CustomIDWork_SetOffsetPosY(OWNER_SLIDE_IDW(self), SLIDE_HIDDEN_Y);
        func_001DEE60(self, 1, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosY(OWNER_SLIDE_IDW(self), 0);
        func_001DEE60(self, 1, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosY(OWNER_SLIDE_IDW(self), SLIDE_HIDDEN_Y, 0, 10);
        func_001DEE60(self, 1, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosY(OWNER_SLIDE_IDW(self), 0, SLIDE_HIDDEN_Y, 10);
        func_001DEE60(self, 1, 1);
        break;
    }
}

#define TURN_SPEED   0.13962634f        /* 8 degrees in radians */
#define ACTOR_ID_A   0x314              /* actors that turn silently */
#define ACTOR_ID_B   0x354

/* A game object that turns toward a goal heading at 0x640. */
typedef struct cGameObjTurnB {
    cGameObj base;
    char unk5AC[0x640 - sizeof(cGameObj)];
    float goalRot;                      /* 0x640 */
} cGameObjTurnB;

/* Turn step: the first call plays the turn sound and enters step 1; step 1 turns the heading toward goalRot and, once there, resets the four state bytes. */
__attribute__((section(".text.cGameObjTurnB_stepTurn")))
void cGameObjTurnB_stepTurn(cGameObjTurnB *self) {
    float rot;

    switch (self->base.step) {
    case 0:
        if (self->base.actorId != ACTOR_ID_A && self->base.actorId != ACTOR_ID_B) {
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 3, self, 0, 0, 0, 0);
        }
        self->base.stepArg = 0;
        self->base.step = 1;
    case 1:
        break;
    default:
        return;
    }
    rot = self->base.rot.y + Turn_dest_dir(self->base.rot.y, self->goalRot, TURN_SPEED);
    self->base.rot.y = rot;
    self->base.rot.y = Adjust_theta(rot);
    if (self->base.rot.y == self->goalRot) {
        self->base.mode = 0;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

extern int ChkLine(void *a0, void *a1, void *a2, void *a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

#define DROP_UP     1.0f
#define DROP_DOWN   11.0f
#define GROUNDED    0x2
#define GROUND_FLAGS(self)   (*(unsigned int *)((self) + 0x2DC))   /* raw offsets: the owner class is not typed yet */
#define GROUND_Y(self)       (*(float *)((self) + 0x2E0))
#define FRAME ((char *)&pos - 0x30)

/* Keep an object on the ground: unless already grounded, cast a line from 1 unit above the
 * object's position to 11 units below it; on a hit keep the hit height at 0x2E0 and set the
 * flag in 0x2DC. While the flag is set, hand the kept height to func_002E6B88. */
__attribute__((section(".text.Pos_followGroundB")))
void Pos_followGroundB(char *self)
{
    cVec pos;                           /* sp+0x30 object position */
    cVec from;                          /* sp+0x40 */
    cVec to;                            /* sp+0x50 */
    cVec hit;                           /* sp+0x60 */
    cVec normal;                        /* sp+0x70 */

    if ((GROUND_FLAGS(self) & GROUNDED) == 0) {
        StoreVecFromFieldB0_2B6160(&pos, self);
        VU0_LQC2(4, &pos, 0);
        VU0_SQC2(4, FRAME, 0x40);
        VU0_LQC2(4, &pos, 0);
        VU0_SQC2(4, FRAME, 0x50);
        VU0_SQC2_VF0(FRAME, 0x60);
        VU0_SQC2_VF0(FRAME, 0x70);
        from.y += DROP_UP;
        to.y -= DROP_DOWN;
        if (ChkLine(&from, &to, &hit, &normal, 2, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
            GROUND_Y(self) = hit.y;
            GROUND_FLAGS(self) |= GROUNDED;
        }
    }
    if ((GROUND_FLAGS(self) & GROUNDED) != 0)
        func_002E6B88(self, GROUND_Y(self));
}

/* Run the state handler of the object: the state byte (0x2F4) indexes a copy
 * of the 4-entry table D_004235D0. An entry holds a this-adjustment (0), a
 * selector (2) and a table offset (4). A selector >= 0 reads the handler from
 * the object's own table (entry selector - 1 of the table at self + offset,
 * pointer in the high word, adjustment in the low half), otherwise the
 * handler is the pointer stored at entry + 4. Then run func_001B76D8. */



typedef struct StateEntry {
    short adjust;                       /* 0x0 */
    short selector;                     /* 0x2 */
    short tableOff;                     /* 0x4 */
    short pad6;
} StateEntry;

typedef struct StateTable {
    StateEntry e[4];
} StateTable;

extern StateTable D_004235D0;

__attribute__((section(".text.StateObj_runHandlerB")))
void StateObj_runHandlerB(void *a0)
{
    char *s0 = (char *)a0;
    StateTable tbl;
    char *e;
    int i8;
    int f0;
    int type;
    int arg;
    int (*fp)(int);
    long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    tbl = D_004235D0;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&tbl + i8 + 4);
    }
    f0 = tbl.e[*(unsigned char *)(s0 + 0x2F4)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001B76D8(s0);
}
