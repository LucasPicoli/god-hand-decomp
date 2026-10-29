/* sn-2.95.3-136 matched TU. */

#include "godhand/classFADE.h"
#include "godhand/cScenario.h"
#include "godhand/cOl2b.h"
#include "godhand/cCoreSave.h"
#include "godhand/cRecordIndex.h"

extern char D_0044ACF0[];
extern void Moji_size_set(int w, int h);
extern void printf_2E0DA8(int x, int y, int a2, int a3, char *fmt, ...);
extern void cTaskWork_sleep(void *work, int frames);
extern void cOl2b_setOpenFix(cOl2b *self);
extern int D_003C2388;
extern int cIDBase_initialize(void *part, int a1, int id);
extern void *cIDManager_getTexAddr_2ACE28(int mgr, int id);

/* Debug overlay owner: the value shown on screen sits at 0x2A08C. */
typedef struct DebugView {
    char unk00000[0x2A08C];
    int shown;                          /* 0x2A08C */
} DebugView;


extern void func_002A4ED8(DebugView *self);



/* Refresh the view, reset the text size and print the shown value at (0x28, 0x12C). */
__attribute__((section(".text.DebugView_printShown")))
void DebugView_printShown(DebugView *self)
{
    func_002A4ED8(self);
    Moji_size_set(0, 0);
    printf_2E0DA8(0x28, 0x12C, 0, 6, D_0044ACF0, self->shown);
}

/* A scene step: its stage byte at +4. */
typedef struct FadeStep {
    char unk00[4];
    unsigned char stage;                /* 0x04 */
} FadeStep;

#define FADE_FRAMES 10

/* Fade the screen to black over 10 frames, sleep the scenario task for as
 * long, then move the step to stage 1. */
__attribute__((section(".text.FadeStep_fadeOutAndAdvance")))
void FadeStep_fadeOutAndAdvance(FadeStep *self)
{
    classFADE_start(&D_00747470, 0, 0xA, 0, 0, 0xFF000000, FADE_FRAMES);
    cTaskWork_sleep(D_003C2F84->task.cur, FADE_FRAMES);
    self->stage = 1;
}

/* Init the base, mark the object fixed and open, reset its sub-states and
 * start it opening. Always succeeds. */
__attribute__((section(".text.cOl2b_startOpening")))
int cOl2b_startOpening(cOl2b *self)
{
    func_001B6FB8(self);
    self->flags5B8 |= COL2B_FLAG5B8_FIXED;
    self->flags250 |= COL2B_FLAG250_OPEN;
    self->stateA29 = 0;
    self->stateA28 = 0;
    self->state = COL2B_STATE_OPENING;
    cOl2b_setOpenFix(self);
    return 1;
}

/* Forget the skill that slot i of the index points at, when it is at level 1. */
__attribute__((section(".text.cRecordIndex_clearSkillIfLevel1")))
void cRecordIndex_clearSkillIfLevel1(cRecordIndex *self, int i)
{
    signed char *base;
    signed char *skill;

    if (self->table != 0) {
        /* Two statements: one expression adds i first and swaps the addu operands. */
        base = self->index;
        skill = base + i;
        if (cCoreSave_getSkill(&D_00569B70, *skill) == 1)
            cCoreSave_setSkill(&D_00569B70, *skill, 0);
    }
}

#define PHASE_START 0
#define PHASE_RUN   1

/* A two-phase job: the phase byte at +0xD. */
typedef struct PhaseJob {
    char unk00[0xD];
    unsigned char phase;                /* 0x0D */
} PhaseJob;

extern void func_002B41F0(PhaseJob *job);

extern void func_002B42F0(PhaseJob *job);

/* Start the job on phase 0 and move to the run phase; in the run phase
 * step it, and finish it once the step reports done. */
__attribute__((section(".text.PhaseJob_step")))
void PhaseJob_step(PhaseJob *job)
{
    switch (job->phase) {
    case PHASE_START:
        func_002B41F0(job);
        job->phase++;
        /* fallthrough */
    case PHASE_RUN:
        if (func_002B4228(job) != 0)
            func_002B42F0(job);
        break;
    }
}

#define SCREEN_PART_ID_A 0xF
#define SCREEN_PART_ID_B 0xE
#define SCREEN_PART_ID_C 0x15
#define SCREEN_PART_ID_D 0xD
#define SCREEN_TEX_ID    0x36

/* A screen made of four cIDBase parts: the first at 0, the others at 0x500,
 * 0x550 and 0x4B0; the counter at 0x90 and the texture address at 0x94. */
typedef struct IdScreen {
    char unk00[0x90];
    int count;                          /* 0x90 */
    void *tex;                          /* 0x94 */
} IdScreen;





/* Initialise the four id parts and fetch the screen texture. */
__attribute__((section(".text.IdScreen_init")))
void IdScreen_init(IdScreen *self)
{
    self->count = 0;
    cIDBase_initialize(self, 1, SCREEN_PART_ID_A);
    cIDBase_initialize((char *)self + 0x500, 1, SCREEN_PART_ID_B);
    cIDBase_initialize((char *)self + 0x550, 1, SCREEN_PART_ID_C);
    cIDBase_initialize((char *)self + 0x4B0, 1, SCREEN_PART_ID_D);
    self->tex = cIDManager_getTexAddr_2ACE28(D_003C2388, SCREEN_TEX_ID);
}
