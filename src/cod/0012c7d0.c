/* sn-2.95.3-136 matched TU. */

#include "godhand/ColiseumBattle.h"
#include "godhand/cEmSetParam.h"
#include "godhand/pl00.h"
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"

extern void ColiseumBattle_DefeatAllEnemies(ColiseumBattle *self);
extern int ColiseumBattle_CountLiveEnemies(ColiseumBattle *self);
extern void cEmSetParam_setEm(cEmSetParam *param, int entry);
extern void cEmWrap_SetVitalMax(void *wrap, int vital);
extern void cEmWrap_SetVital(void *wrap, int vital);
extern void cEmWrap_StartAction(void *wrap);
extern int cRoomSave_clearEmDeadFlag(void *self, int id);
extern cGameObj *GetJacket(void);
extern char D_005FEE00[];
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float f12);
extern int cSnd_SeCall(void *a0, int a1, int a2, void *a3, int a4, int a5);

#define ARENA_PHASE_DEFEAT    0
#define ARENA_PHASE_WAVES     1
#define ARENA_PHASE_DONE      2
#define ARENA_LIVE_REFILL     5     /* spawn the next enemy below this many live ones */
#define ARENA_EM_SLOTS        12    /* enemy picks cycle through 0..11 */
#define ARENA_EM_VITAL        0x19

/* Arena wave step: phase 0 defeats every enemy; phase 1 spawns the next enemy in the cycle whenever fewer than 5 are
 * alive and the wave count is below the ring's limit, then moves to phase 2 once the limit is reached. */
__attribute__((section(".text.ColiseumBattle_stepEnemyWaves")))
void ColiseumBattle_stepEnemyWaves(ColiseumBattle *self)
{
    char buf[0x10];

    switch (self->phase) {
    case ARENA_PHASE_DEFEAT:
        ColiseumBattle_DefeatAllEnemies(self);
        self->phase = self->phase + 1;
        break;
    case ARENA_PHASE_WAVES:
        if (self->enemyNum < self->ring.unk0A) {
            if (ColiseumBattle_CountLiveEnemies(self) < ARENA_LIVE_REFILL) {
                self->unkB90 = self->unkB90 + 1;
                if (self->unkB90 >= ARENA_EM_SLOTS)
                    self->unkB90 = 0;
                cRoomSave_clearEmDeadFlag(&D_005E8658, self->unkB90);
                buf[0] = self->unkB90;
                cEmSetParam_setEm(&D_00586AB0, (unsigned char)buf[0]);
                cEmWrap_SetVitalMax(buf, ARENA_EM_VITAL);
                cEmWrap_SetVital(buf, ARENA_EM_VITAL);
                cEmWrap_StartAction(buf);
                self->enemyNum = self->enemyNum + 1;
            }
        } else {
            self->phase = ARENA_PHASE_DONE;
        }
        break;
    }
}

/* Call setSuspend(on) on obj through its method table. */
#define PL00_FORWARD_SUSPEND(obj, on) \
    do { \
        pl00VtEnt *ent_ = &((pl00VtEnt *)(obj)->vtable)[PL00_VT_SETSUSPEND]; \
        ent_->pfn((char *)(obj) + ent_->delta, (on)); \
    } while (0)

/* Set (on == 1) or clear the suspend bits of the player, then pass the state on to the jacket and to the three objects
 * that fight beside the player. */
__attribute__((section(".text.pl00_setSuspend")))
void pl00_setSuspend(pl00 *self, int on)
{
    if (on == 1)
        self->base.objFlags |= GAMEOBJ_OBJ_SUSPEND;
    else
        self->base.objFlags &= ~GAMEOBJ_OBJ_SUSPEND;
    if (on == 1)
        self->base.scrFlags |= GAMEOBJ_SCR_SUSPEND;
    else
        self->base.scrFlags &= ~GAMEOBJ_SCR_SUSPEND;
    if (GetJacket() != 0) {
        cGameObj *jacket = GetJacket();
        pl00VtEnt *ent = &((pl00VtEnt *)jacket->vtable)[PL00_VT_SETSUSPEND];
        int arg = on;   /* a copy of on: puts the argument move ahead of the delta load, as in retail */

        ent->pfn((char *)jacket + ent->delta, arg);
    }
    if (self->sub698 != 0)
        PL00_FORWARD_SUSPEND(self->sub698, on);
    if (self->sub6A0 != 0)
        PL00_FORWARD_SUSPEND(self->sub6A0, on);
    if (self->sub6A8 != 0)
        PL00_FORWARD_SUSPEND(self->sub6A8, on);
}

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

#define SURFACE_WATER  0x400
#define FRAME ((char *)buf - 0x30)

typedef struct HitRec {
    int unk0;
    unsigned int surface;               /* 0x4 */
} HitRec;

/* A game object that can splash: past the base part it keeps a vertical speed and a once-only flag. */
typedef struct SplashObj {
    cGameObj base;
    char unk5AC[0x1710 - 0x5AC];
    float fall;                         /* 0x1710 negative while falling */
    char unk1714[0x17C2 - 0x1714];
    unsigned char splashed;             /* 0x17C2 */
} SplashObj;

/* Once, while the object is falling or its motion flag 4 is set and it sits above its ground position: cast a line
 * from the object's position; when it hits water (surface flag 0x400), spawn effect 0x55 at the hit point, play
 * sound 0x50 and set the flag. */
__attribute__((section(".text.cGameObj_checkWaterSplash")))
void cGameObj_checkWaterSplash(SplashObj *self)
{
    float buf[8];
    cVec *pos;

    if (self->splashed != 0)
        return;
    pos = self->base.pos;
    if (self->base.posA.y <= pos->y)
        return;
    if ((self->base.seqFlags & 4) == 0 && !(self->fall < 0.0f))
        return;
    {
        float *v = buf;
        int one;

        VU0_SQC2_VF0(FRAME, 0x30);
        one = 1;
        if (ChkLine(&self->base.posA, pos, v, 0, 7, 0, &buf[4], 1, 0, 0, 0, 0, one) != 0
            && (((HitRec *)*(void **)&buf[4])->surface & SURFACE_WATER) != 0) {
            SetEffectPos(0, 0x55, 0, v, -1, 1.0f);
            cSnd_SeCall(D_005FEE00, 2, 0x50, self->base.pos, 0, 0);
            self->splashed = one;
        }
    }
}
