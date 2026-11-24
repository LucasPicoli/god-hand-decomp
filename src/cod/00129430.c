/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmb2.h"
#include "godhand/cOmBase.h"
#include "godhand/cSnd.h"
#include "godhand/pl00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cDamageManage.h"
#include "godhand/globals.h"

extern int cOmSub_move(void *move);
extern void cOmSub_initMove3_y(void *dst, void *obj, int idx, int a3, float f12, float f13, float f14);
extern void cOmSub_initMove1_pos(void *dst, void *obj, int idx, int a3, void *t0, float f12, float f13);
extern char D_00747B00[];
extern char D_00747AC0[];
extern int cOmBase_checkDamage(void *self, int damage);
extern void cHeatSys_AddHeatGage(void *heat, int a1, float amount);
extern int D_005CB000;
extern int cModel_setMeshDisplay(void *model, char *name, int on);

#define MOVE_STEP_PHASE_START  0
#define MOVE_STEP_PHASE_RUN    1
#define MOVE_RISE_RATE   (-0.02f)
#define MOVE_DROP_SPEED  0.2f
#define MOVE_FRAMES      0x1E

/* A map object that follows a move record (cOmb2 plus two flag bytes at 0x774 and 0x775 and a height at 0x770). */
typedef struct MoveObj {
    cOmb2 base;
    char unk630[0x770 - 0x630];
    float height;               /* 0x770 */
    unsigned char armed;        /* 0x774 a move was requested */
    unsigned char running;      /* 0x775 the move is running */
    char unk776[2];
    int pos;                    /* 0x778 non-zero: move to a position, else drop */
} MoveObj;

/* Phase 0 starts the requested move (to a position when 0x778 is set, else a drop along the height) and falls into
 * phase 1, which steps the move and, once it ends, clears the flags and the state bytes. */
__attribute__((section(".text.cOmb2_stepMove")))
void cOmb2_stepMove(MoveObj *self)
{
    switch (self->base.base.phase) {
    case MOVE_STEP_PHASE_START:
        if (self->armed == 0) {
            self->base.base.stepArg = 0;
            goto reset;
        }
        if (self->pos == 0) {
            cOmSub_initMove3_y(self->base.move, self, -1, (int)D_00747B00, MOVE_RISE_RATE, -self->height, MOVE_DROP_SPEED);
        } else {
            float vec[4];

            vec[0] = 0.0f;
            vec[1] = self->height;
            vec[2] = 0.0f;
            vec[3] = 1.0f;
            cOmSub_initMove1_pos(self->base.move, self, -1, MOVE_FRAMES, vec, MOVE_DROP_SPEED, MOVE_DROP_SPEED);
        }
        self->base.base.step = 0;
        self->running = 1;
        self->base.base.phase = MOVE_STEP_PHASE_RUN;
        self->base.base.stepArg = 0;
    case MOVE_STEP_PHASE_RUN:
        if (cOmSub_move(self->base.move) != 0)
            return;
        self->base.base.stepArg = 0;
        self->armed = 0;
        self->running = 0;
    reset:
        self->base.base.phase = 0;
        self->base.base.step = 0;
        self->base.base.mode = 0;
        break;
    }
}

#define GIVE_KIND         3
#define GIVE_SPHERE       2.5f
#define GIVE_HIT_KIND     0x52
#define GIVE_DAMAGE       0x14
#define GIVE_FLAG_ON      0x1       /* flags word of the give unit: armed */
#define TAKE_KIND         1
#define TAKE_SPHERE       1.5f
#define TAKE_OFFSET_Z     3.0f
#define OM_F2_HIT_OFF     0x1       /* flags2 bit cleared once the volumes exist */

typedef struct cOmGiveTake {
    cOmBase base;
    char unk5E0[0x40];
    cDamageGive *give;          /* 0x620 */
    cDamageTake *take;          /* 0x624 */
} cOmGiveTake;






/* Create the give volume (kind 3, a 2.5 sphere at the origin, hit kind 0x52, damage 20) and the take volume (a 1.5
 * sphere 3.0 up the first child), switch both off and clear bit 0 of flags2. Returns 1. */
__attribute__((section(".text.cOmGiveTake_init")))
int cOmGiveTake_init(cOmGiveTake *self)
{
    float v[4] __attribute__((aligned(16)));

    func_001B6FB8(self);
    self->give = cDamageManage_CreateDamageGive(&D_00574380, GIVE_KIND, (cGameObj *)self);
    if (self->give != 0) {
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 1.0f;
        cDamageUnit_AddDamageCollSphere((cDamageUnit *)self->give, (const struct cMatrix *)D_00747AC0, (const cVec *)v, GIVE_SPHERE);
        self->give->kind = GIVE_HIT_KIND;
        self->give->power = GIVE_DAMAGE;
        cDamageUnit_SetDamageCollActive((cDamageUnit *)self->give, 0);
        self->give->flags |= GIVE_FLAG_ON;
    }
    self->take = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, TAKE_KIND);
    if (self->take != 0) {
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = TAKE_OFFSET_Z;
        v[3] = 1.0f;
        cDamageUnit_AddDamageCollSphere((cDamageUnit *)self->take, (const struct cMatrix *)self->base.mtx, (const cVec *)v, TAKE_SPHERE);
        cDamageUnit_SetDamageCollActive((cDamageUnit *)self->take, 0);
    }
    self->base.flags2 &= ~OM_F2_HIT_OFF;
    return 1;
}

#define OBJ_DAMAGE_OFFSET  0x600     /* damage-take record handle */
#define OM_F0_HIT          0x1       /* flags0 bit 0: the object was hit */

/* One row of the phase table: this adjust, method index (or -1), table offset in the object, or the inline handler. */
struct Entry_func_001BC1C8 { short f0; short f2; short f4; short f6; };
typedef struct { char b[0x18]; } Blob18;
extern Blob18 D_00429278;

/* Phase tick: run the handler of the phase's table row, then take a damage hit: with hp left the object restarts in
 * mode 1, with none it enters mode 2 and sets bit 0 of its flags (0x5B0). Both clear phase, step and step argument. */
__attribute__((section(".text.cOmBase_tickPhaseWithHit")))
void cOmBase_tickPhaseWithHit(cOmBase *self)
{
    char *s0 = (char *)self;
    struct Entry_func_001BC1C8 tbl[3];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    int v1;

    *(Blob18 *)tbl = D_00429278;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[*(unsigned char *)(s0 + 0x2F5)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    v1 = cOmBase_checkDamage(self, *(int *)(s0 + OBJ_DAMAGE_OFFSET));
    if (v1 == 1) {
        if (self->hp <= 0) {
            int flags = self->flags0;
            self->mode = 2;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
            self->flags0 = flags | OM_F0_HIT;
        } else {
            self->mode = v1;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
    }
}

#define COMBO_WINDOW        0x2D        /* frames a combo stays open */
#define COMBO_TOP_HITS      5           /* hit count that earns the bonus */
#define COMBO_SE_TOP        0x36
#define COMBO_SE_STEP       0xEE
#define COMBO_BONUS_POINTS  100
#define COMBO_STEP_POINTS   0x32
#define COMBO_HEAT_FIRST    1.5f
#define COMBO_HEAT_LATER    0.5f
#define COMBO_LEVEL_TOP     5           /* game level that halves the heat */

/* Count one more hit of the player's combo (a new combo restarts at 1 when the window ran out) and reopen the 45 frame
 * window. The fifth hit plays a sound and adds 100 level points; every hit adds heat (1.5 for the first, 0.5 after,
 * halved at the top level) and every third hit from the first plays a sound; every call adds 50 level points. */
__attribute__((section(".text.pl00_addComboHit")))
void pl00_addComboHit(pl00 *self)
{
    float heat;

    if (self->comboTimer == 0)
        self->comboCount = 0;
    self->comboCount = (unsigned char)self->comboCount + 1;
    self->comboTimer = COMBO_WINDOW;
    if (self->comboCount == COMBO_TOP_HITS) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, COMBO_SE_TOP, (cObj *)self, 0, 0, 0, 0);
        cCoreSave_addGameLevelPoint(&D_00569B70, COMBO_BONUS_POINTS);
    }
    heat = COMBO_HEAT_FIRST;
    if (self->comboCount >= 2)
        heat = COMBO_HEAT_LATER;
    if (cCoreSave_getGameLevel(&D_00569B70) == COMBO_LEVEL_TOP)
        heat = heat * COMBO_HEAT_LATER;
    cHeatSys_AddHeatGage(&D_005CB000, 0, heat);
    if (self->comboCount % 3 == 1)
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, COMBO_SE_STEP, (cObj *)self, 0, 0, 0, 0);
    cCoreSave_addGameLevelPoint(&D_00569B70, COMBO_STEP_POINTS);
}

#define ACTOR_BOSS_A   0x625
#define ACTOR_BOSS_C   0x627
#define LEVEL_FIRST    6            /* levels 6 to 8 swap the meshes */
#define LEVEL_SWAP_NUM 3
#define LEVEL_LAST     8
#define RATE_STAY      17.0f        /* at the last level the swap waits until the rate reaches this */

/* Show the right meshes of a boss model for its damage level: actors 0x625 and 0x627 show the first mesh and hide the
 * second, and at levels 6 to 8 swap them (at level 8 only once rate is below 17). */
__attribute__((section(".text.cModel_setBossMeshesB")))
void cModel_setBossMeshesB(char *model, int unused, int level, float rate)
{
    char *a1;
    char *b1;
    char *a2;
    char *b2;

    if (model == 0)
        return;
    switch (*(unsigned short *)(model + 0x2FE)) {
    case ACTOR_BOSS_A:
        a1 = D_0044ABB0;
        cModel_setMeshDisplay(model, a1, 1);
        b1 = D_0044ABB8;
        cModel_setMeshDisplay(model, b1, 0);
        if ((unsigned int)(level - LEVEL_FIRST) >= LEVEL_SWAP_NUM)
            return;
        if (level == LEVEL_LAST && RATE_STAY <= rate)
            return;
        cModel_setMeshDisplay(model, a1, 0);
        cModel_setMeshDisplay(model, b1, 1);
        break;
    case ACTOR_BOSS_C:
        a2 = D_0044ABB0;
        cModel_setMeshDisplay(model, a2, 1);
        b2 = D_0044ABB8;
        cModel_setMeshDisplay(model, b2, 0);
        if ((unsigned int)(level - LEVEL_FIRST) >= LEVEL_SWAP_NUM)
            return;
        if (level == LEVEL_LAST && RATE_STAY <= rate)
            return;
        cModel_setMeshDisplay(model, a2, 0);
        cModel_setMeshDisplay(model, b2, 1);
        break;
    }
}
