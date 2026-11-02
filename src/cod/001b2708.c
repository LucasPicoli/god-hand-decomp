/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cModel.h"
#include "godhand/cEmSetParam.h"

extern char D_003BDD08[];
extern char D_003BDE98[];
extern int cModel_setMeshDisplay(void *model, char *name, int on);
extern char D_0044A9D0[];
extern char D_0044A9D8[];
extern cModelNode *cModel_getMeshPtr(cModel *self, int idx);
extern int cModel_getMeshNum(cModel *self);
extern void func_00155D60(cModelNode *node, int value, int slot);
extern void cEmSetParam_setEm(cEmSetParam *param, int entry);
extern void cEmWrap_StartAction(void *wrap);

/* sn-2.95.3-136 */





#define EM_HIT_FLASH_FULL  3.0f
#define EM_FADE_STEP       0.1f

/* Phase 0: start the death and flash the body. Phase 1: slow the animation to a stop, then release the enemy. */
__attribute__((section(".text.cEm00_stepFadeOutAndReleaseB")))
void cEm00_stepFadeOutAndReleaseB(cEm00 *self) {
    self->hitFlash = EM_HIT_FLASH_FULL;
    switch (self->step) {
    case 0:
        func_0028FB08(self);
        self->step = self->step + 1;
    case 1:
        self->animRate = self->animRate - EM_FADE_STEP;
        if (self->animRate <= 0.0f) {
            self->animRate = 0.0f;
            cEmManage_ReleaseEm(&D_005864F0, (cEmActor *)self);
            self->step = self->step + 1;
        }
        break;
    }
}

/* sn-2.95.3-136 */


#define PHASE_OFFSET      0x2F5         /* row number, a byte of the object */
#define ROW_ADJUST        0
#define ROW_SLOT          2
#define ROW_TBL_OFS       4
#define ROW_FN            4

/* Call the function of the dispatch row selected by the phase byte, with this adjusted by the row and by the table entry. */
__attribute__((section(".text.PhaseDispatch_callRowB")))
void PhaseDispatch_callRowB(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    i8 = *(unsigned char *)(s0 + PHASE_OFFSET) * 8;
    e = D_003BDD08 + i8;
    type = *(short *)(e + ROW_SLOT);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + ROW_TBL_OFS));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BDD08 + i8 + ROW_FN);
    }
    f0 = *(short *)(D_003BDD08 + *(unsigned char *)(s0 + PHASE_OFFSET) * 8 + ROW_ADJUST);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

/* sn-2.95.3-136 */


#define PHASE_OFFSET      0x2F5         /* row number, a byte of the object */
#define ROW_ADJUST        0
#define ROW_SLOT          2
#define ROW_TBL_OFS       4
#define ROW_FN            4

/* Call the function of the dispatch row selected by the phase byte, with this adjusted by the row and by the table entry. */
__attribute__((section(".text.PhaseDispatch_callRowC")))
void PhaseDispatch_callRowC(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    i8 = *(unsigned char *)(s0 + PHASE_OFFSET) * 8;
    e = D_003BDE98 + i8;
    type = *(short *)(e + ROW_SLOT);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + ROW_TBL_OFS));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BDE98 + i8 + ROW_FN);
    }
    f0 = *(short *)(D_003BDE98 + *(unsigned char *)(s0 + PHASE_OFFSET) * 8 + ROW_ADJUST);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

/* sn-2.95.3-136 */




/* Costume hook for the objects with actor id 0x605 and 0x607: from costume 0x12 on, hide the first part mesh (and show the second one on 0x605). */
#define ACTOR_ID_COSTUME_A   0x605
#define ACTOR_ID_COSTUME_B   0x607
#define COSTUME_PART_MIN     0x12

typedef struct CostumeObj {
    char unk000[0x2FE];
    unsigned short actorId;             /* 0x2FE */
} CostumeObj;

__attribute__((section(".text.CostumeObj_applyTailPartMeshes")))
void CostumeObj_applyTailPartMeshes(CostumeObj *self, int unused, int costume)
{
    if (self == 0) {
        return;
    }
    switch (self->actorId) {
    case ACTOR_ID_COSTUME_A:
        if (costume >= COSTUME_PART_MIN) {
            cModel_setMeshDisplay(self, D_0044A9D0, 0);
            cModel_setMeshDisplay(self, D_0044A9D8, 1);
        }
        break;
    case ACTOR_ID_COSTUME_B:
        if (costume >= COSTUME_PART_MIN) {
            cModel_setMeshDisplay(self, D_0044A9D0, 0);
        }
        break;
    }
}

/* sn-2.95.3-136 */






/* Set value in both slots of every mesh node, by index. */
__attribute__((section(".text.objScroll_Set_test")))
void objScroll_Set_test(cModel *self, int value) {
    int num = cModel_getMeshNum(self);
    int i = 0;
    if (num > 0) {
        do {
            cModelNode *node = cModel_getMeshPtr(self, i);
            i++;
            func_00155D60(node, value, 0);
            func_00155D60(node, value, 1);
        } while (i < num);
    }
}

/* sn-2.95.3-136 */






/* Arena wave step: step 0 defeats every enemy and starts a 1800 frame timer; step 1 waits until two enemies are down or the timer runs out, then sets the next enemy up and starts its action. */
#define ARENA_WAIT_FRAMES  0x708
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

__attribute__((section(".text.ArenaEm_stepSecondWave")))
void ArenaEm_stepSecondWave(ArenaEm *self)
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
            buf[0] = 1;
            cEmSetParam_setEm(&D_00586AB0, 1);
            cEmWrap_StartAction(buf);
            self->waveNum = self->waveNum + 1;
            self->introStep = self->introStep + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    }
}
