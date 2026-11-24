/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageUnit.h"
#include "godhand/cEmSetParam.h"
#include "godhand/cEm00.h"
#include "godhand/cDamageManage.h"
#include "godhand/globals.h"

extern void cEmSetParam_setEm(cEmSetParam *param, int entry);
extern void cEmWrap_StartAction(void *wrap);
extern int D_005CAE50;
extern void func_0012EC58(void *pool, void *handle);

/* Arena wave step: step 0 defeats every enemy and starts a 300 frame timer; step 1 waits until the ring is clear or the timer runs out, then sets the next enemy up and starts its action. */


#define ARENA_WAIT_FRAMES  0x12C

typedef struct ArenaEm {
    char unk000[0xB8C];
    int waveNum;                        /* 0xB8C waves started */
    char unkB90[4];
    int introStep;                      /* 0xB94 */
    char unkB98[8];
    int timer;                          /* 0xBA0 frames left to wait */
} ArenaEm;

extern void ColiseumBattle_DefeatAllEnemies(ArenaEm *self);
extern int ColiseumBattle_CountLiveEnemies(ArenaEm *self);



__attribute__((section(".text.ArenaEm_stepWave")))
void ArenaEm_stepWave(ArenaEm *self)
{
    char buf[0x10];
    switch (self->introStep) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->timer = ARENA_WAIT_FRAMES;
        self->introStep = self->introStep + 1;
        break;
    case 1:
        if (ColiseumBattle_CountLiveEnemies(self) == 0 || self->timer == 0) {
            buf[0] = 2;
            cEmSetParam_setEm(&D_00586AB0, 2);
            cEmWrap_StartAction(buf);
            self->waveNum = self->waveNum + 1;
            self->introStep = self->introStep + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    }
}

/* Switch off the five damage volumes of the object: clear each unit's hit kind, deactivate it, shrink its radius to 0 and clear its damage word. Does nothing unless all five exist. */
#define DMG_PAIR_NUM  5

typedef struct DmgPair {
    cDamageUnit *unit;                  /* +0x00 */
    int radiusId;                       /* +0x04 node id handed to SetDamageCollRadius */
} DmgPair;

typedef struct DmgObj {
    char unk000[0x5B0];
    DmgPair pair[DMG_PAIR_NUM];         /* 0x5B0 */
} DmgObj;
extern void cDamageUnit_SetDamageCollRadius(cDamageUnit *self, int id, float radius);

__attribute__((section(".text.DmgObj_stopDamageVolumes")))
void DmgObj_stopDamageVolumes(DmgObj *self)
{
    float zero;
    if (self->pair[0].unit == 0) return;
    if (self->pair[1].unit == 0) return;
    if (self->pair[2].unit == 0) return;
    if (self->pair[3].unit == 0) return;
    if (self->pair[4].unit == 0) return;
    zero = 0.0f;
    self->pair[0].unit->kind = 0;
    cDamageUnit_SetDamageCollActive(self->pair[0].unit, 0);
    cDamageUnit_SetDamageCollRadius(self->pair[0].unit, self->pair[0].radiusId, zero);
    self->pair[0].unit->power = 0;
    self->pair[1].unit->kind = 0;
    cDamageUnit_SetDamageCollActive(self->pair[1].unit, 0);
    cDamageUnit_SetDamageCollRadius(self->pair[1].unit, self->pair[1].radiusId, zero);
    self->pair[1].unit->power = 0;
    self->pair[2].unit->kind = 0;
    cDamageUnit_SetDamageCollActive(self->pair[2].unit, 0);
    cDamageUnit_SetDamageCollRadius(self->pair[2].unit, self->pair[2].radiusId, zero);
    self->pair[2].unit->power = 0;
    self->pair[3].unit->kind = 0;
    cDamageUnit_SetDamageCollActive(self->pair[3].unit, 0);
    cDamageUnit_SetDamageCollRadius(self->pair[3].unit, self->pair[3].radiusId, zero);
    self->pair[3].unit->power = 0;
    self->pair[4].unit->kind = 0;
    cDamageUnit_SetDamageCollActive(self->pair[4].unit, 0);
    cDamageUnit_SetDamageCollRadius(self->pair[4].unit, self->pair[4].radiusId, zero);
    self->pair[4].unit->power = 0;
}


/* Take a free unit from the pool and build a cylinder in it: the group, the shape (vtable D_0044BCA0), state 2, then the radius and the height through the shape's methods 3 and 5. A unit that isn't free goes back through the pool's method 6. Returns the unit, or 0. */
__attribute__((section(".text.Pool_createObjWithTable")))
cCollisionUnit *Pool_createObjWithTable(cCollisionManager *pool, int group, const struct cMatrix *mtx,
                                        const cVec *ofs, const cVec *rot, float height, float radius)
{
    cCollisionUnit *obj = create(pool, CCOLLISION_SHAPE_CYLINDER);
    cCollisionShape *shape;
    if (obj == 0) {
        return 0;
    }
    if (((obj->flags & COLL_UNIT_FLAGS_READY_MASK) ^ COLL_UNIT_FLAGS_READY) != 0) {
        ((void (*)(void *, cCollisionUnit *))pool->vt[CCOLLISION_MANAGER_RELEASE].pfn)(
            (char *)pool + pool->vt[CCOLLISION_MANAGER_RELEASE].delta, obj);
        return 0;
    }
    func_002B8A70(obj, group);
    shape = &obj->body;
    cCollisionShape_construct(shape, mtx, ofs, rot);
    shape->vt = D_0044BCA0;
    shape->state = CCOLLISION_SHAPE_CYLINDER;
    ((void (*)(void *, float))shape->vt[CCOLLISION_SHAPE_SETRADIUS].pfn)(
        (char *)shape + shape->vt[CCOLLISION_SHAPE_SETRADIUS].delta, radius);
    ((void (*)(void *, float))shape->vt[CCOLLISION_SHAPE_SETHEIGHT].pfn)(
        (char *)shape + shape->vt[CCOLLISION_SHAPE_SETHEIGHT].delta, height);
    obj->shape = shape;
    return obj;
}

/* The four resource handles an object owns. */
typedef struct HandleSet {
    char unk00[0x64C];
    void *effect;                       /* 0x64C released through func_0012EC58 */
    void *field;                        /* 0x650 released with ClearAndResetFields */
    void *giveA;                        /* 0x654 damage-give records */
    void *giveB;                        /* 0x658 */
} HandleSet;

/* Release every handle that is set and clear it. */
__attribute__((section(".text.func_001B55A0")))
void func_001B55A0(HandleSet *self) {
    if (self->effect != 0) {
        func_0012EC58(&D_005CAE50, self->effect);
        self->effect = 0;
    }
    if (self->field != 0) {
        ClearAndResetFields_1FE278(&D_00574380, self->field);
        self->field = 0;
    }
    if (self->giveA != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, self->giveA);
        self->giveA = 0;
    }
    if (self->giveB != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, self->giveB);
        self->giveB = 0;
    }
}

/* Phase tick: wrap the phase byte to 0, then call the handler the phase's table entry names. An entry with a
 * non-negative index takes the handler from a method table found through the object; a negative one holds it inline. */

#define PHASE_NUM  1

/* One phase entry: this-adjust, method index (or -1), table offset in the object, or the inline handler. */
typedef struct PhaseEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler is inline */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} PhaseEnt;

typedef struct { char b[0x8]; } PhaseTbl;
extern PhaseTbl D_00448DF8;             /* the entry */

__attribute__((section(".text.cEm00_tickPhaseDispatch1")))
void cEm00_tickPhaseDispatch1(cEm00 *self) {
    PhaseEnt tbl[PHASE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(PhaseTbl *)tbl = D_00448DF8;
    if (self->phase >= PHASE_NUM)
        self->phase = 0;
    i8 = self->phase * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)self + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[self->phase].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)self + arg));
}
