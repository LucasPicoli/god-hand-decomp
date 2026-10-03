/* sn-2.95.3-136 matched TU. */

#include "godhand/cEmManage.h"
#include "godhand/cEmWrap.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"

extern cEmActor *cEmManage_GetEm(cEmManage *mgr, unsigned char entryNo);
extern void cEm00_setEm65Separate(cEmActor *em);
extern void cScenario_startSoftEvent(int scenario, int arg);
extern void cScenario__endSoftEvent(int scenario);
extern int D_004282F0;
extern char D_005FEE00[];
extern char D_00574380[];
extern void cSnd_SeStop(void *snd, int handle);
extern int cDamageManage_ReleaseDamageGive(void *mgr, void *give);
extern void KillEffect(void *obj, int a, int b);
extern void SetField214PtrThenInit_1B6F38(void *obj, int flag);

/* Arena boss intro: step 0 defeats every enemy; step 1 waits until the boss is wounded to half life or less (and alive), then starts a soft event, suspends the boss and sets its separate mode, for 191 frames; step 2 counts those frames down, ends the soft event and moves on. */



#define ARENA_BOSS_WAIT_FRAMES  0xBF

typedef struct ArenaEm {
    char unk000[0xB94];
    int introStep;                      /* 0xB94 */
    char unkB98[8];
    int timer;                          /* 0xBA0 frames left in the step */
} ArenaEm;

/* The handle of the boss enemy: its entry number is the first byte. */
typedef struct EmHandle {
    unsigned char entryNo;
    char unk01[0xF];
} EmHandle;

extern void ColiseumBattle_DefeatAllEnemies(ArenaEm *self);
extern int cEmWrap_GetVitalMax(EmHandle *h);
extern int cEmWrap_GetVital(EmHandle *h);
extern void cEmWrap_setSuspend(EmHandle *h, int flag);




extern int D_003C2F84;                  /* scenario */

__attribute__((section(".text.ArenaEm_stepBossIntro")))
void ArenaEm_stepBossIntro(ArenaEm *self)
{
    EmHandle h;
    int vitalMax;
    int vital;
    h.entryNo = 0;
    switch (self->introStep) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->introStep = self->introStep + 1;
        break;
    case 1:
        vitalMax = cEmWrap_GetVitalMax(&h);
        vital = cEmWrap_GetVital(&h);
        if (vital <= 0 || vitalMax < vital * 2) {
            break;
        }
        cScenario_startSoftEvent(D_003C2F84, 0);
        cEmWrap_setSuspend(&h, 0);
        cEm00_setEm65Separate(cEmManage_GetEm(&D_005864F0, h.entryNo));
        self->timer = ARENA_BOSS_WAIT_FRAMES;
        self->introStep = self->introStep + 1;
        break;
    case 2:
        if (self->timer == 0) {
            cScenario__endSoftEvent(D_003C2F84);
            self->introStep = self->introStep + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    }
}

/* A game object with a sound handle and two damage-give records. */
typedef struct cGiveOwner {
    cGameObj base;
    char unk5AC[0x668 - sizeof(cGameObj)];
    int seHandle;                       /* 0x668 sound voice, 0 when none */
    void *give[2];                      /* 0x66C damage-give records, 0 when none */
    int giveId[2];                      /* 0x674 -1 when none */
} cGiveOwner;









/* Destructor: install the class method table, stop the sound, release both damage-give records, kill the effects and run the base destructor. */
__attribute__((section(".text.cGiveOwner_destruct")))
void cGiveOwner_destruct(cGiveOwner *self, int flag) {
    self->base.vt = (cGameObjVt *)&D_004282F0;
    if (self->seHandle != 0) {
        cSnd_SeStop(D_005FEE00, self->seHandle);
        self->seHandle = 0;
    }
    if (cDamageManage_ReleaseDamageGive(D_00574380, self->give[0]) != 0) {
        self->give[0] = 0;
        self->giveId[0] = -1;
    }
    if (cDamageManage_ReleaseDamageGive(D_00574380, self->give[1]) != 0) {
        self->give[1] = 0;
        self->giveId[1] = -1;
    }
    KillEffect(self, 7, 2);
    SetField214PtrThenInit_1B6F38(self, flag);
}

/* Phase tick: wrap the phase byte to 0..1, then call the handler the phase's table entry names. An entry with a
 * non-negative index takes the handler from a method table found through the object; a negative one holds it inline. */

#define PHASE_NUM  2

/* One phase entry: this-adjust, method index (or -1), table offset in the object, or the inline handler. */
typedef struct PhaseEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler is inline */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} PhaseEnt;

typedef struct { char b[0x10]; } PhaseTbl;
extern PhaseTbl D_00448170;             /* the two entries */

__attribute__((section(".text.cEm00_tickPhaseDispatch2")))
void cEm00_tickPhaseDispatch2(cEm00 *self) {
    PhaseEnt tbl[PHASE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(PhaseTbl *)tbl = D_00448170;
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
