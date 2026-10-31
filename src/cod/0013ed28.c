/* sn-2.95.3-136 matched TU. */

#include "godhand/WaveObj.h"
#include "godhand/cSnd.h"
#include "godhand/MarkPanel.h"
#include "godhand/cOmBase.h"
#include "godhand/cEm00.h"
#include "godhand/Poker.h"
#include "godhand/cNowLoading.h"

extern void func_002E8038(WaveObj *self, float width);
extern void WaveObj_fillWaveTable(WaveObj *self, float step);
extern void *cSnd_GetSeData(cSnd *self, int idx);
extern void cSeData_Release(void *data);
extern void cSnd_releaseEmSeAll(cSnd *self);
extern void cSndMemHeap_Close(void *heap);
extern void cSndBgmNode_FadeIn(cSndBgmNode *node, float time);
extern void cSndBgmNode_Release(cSndBgmNode *node);
extern char D_006036A0[];
extern char D_00603310[];
extern void displayScrollLayer(int layer, int on);
extern int ClearField5B4IfFlagUnset_1B76B0(void *self);
extern void cModel_calcParts(void *self);
extern void cSnd_BgmEventStart(void *snd, int event, int a2, int a3);
extern void func_001DF528(void *p, int a1, int a2);
extern void func_001DEE40(void *p, int a1);
extern char D_005FEE00[];
extern void cIDBase_initIDWork(cNowLoading *self, int idx);
extern cIDBaseEnt *cIDBase_getIDWork(cNowLoading *self, int idx);
extern void cIDBase_restartAnim(cNowLoading *self);

/* Copies the wave settings from the parameter block, clamps the entry count
 * to 1..32 (0 or less gives 25), builds the smoothing table from the squared
 * width and fills the wave table from the step. Always returns 1. */
__attribute__((section(".text.WaveObj_initFromParam")))
int WaveObj_initFromParam(WaveObj *self)
{
    WaveParam *param = self->param;

    self->mode = param->mode;
    self->count = param->count;
    self->width = param->width;
    self->step = param->step;
    if (self->count <= 0)
        self->count = WAVE_COUNT_DEFAULT;
    if (self->count > WAVE_TABLE_MAX)
        self->count = WAVE_TABLE_MAX;
    if (self->width != 0.0f)
        func_002E8038(self, self->width * self->width);
    else
        func_002E8038(self, WAVE_WIDTH_DEFAULT);
    if (self->step != 0.0f)
        WaveObj_fillWaveTable(self, self->step);
    else
        WaveObj_fillWaveTable(self, WAVE_STEP_DEFAULT);
    return 1;
}

#define CSND_FLAG_QUIET      0xFF7FFFFF   /* mask that clears bit 0x800000 of flagsAC and flagsB0 */
#define CSND_BGM_FLAG_FREE   0x100        /* node is to be released */
#define CSND_BGM_FLAG_FADE   0x1FF00      /* any of these bits: node is faded in */
#define CSND_BGM_FADE_CLEAR  0xFFFE00FF   /* the fade request bits are cleared once it starts */
#define CSND_BGM_FADE_TIME   30.0f        /* frames */
#define CSND_UNK_A4_OFFSET   0xA4        /* cleared at the end; not named in cSnd yet */

/* Shuts the sound manager down: clears the 0x800000 flag in both flag words,
 * frees the sound-effect slot 2, all emitter sounds and two memory heaps,
 * then walks the BGM list releasing nodes marked to free and fading in nodes
 * that asked for a fade. */
__attribute__((section(".text.cSnd_shutdown")))
void cSnd_shutdown(cSnd *self)
{
    cSndBgmNode *node;

    self->flagsB0 &= CSND_FLAG_QUIET;
    self->flagsAC &= CSND_FLAG_QUIET;
    cSeData_Release(cSnd_GetSeData(self, 2));
    cSnd_releaseEmSeAll(self);
    cSndMemHeap_Close(D_006036A0);
    cSndMemHeap_Close(D_00603310);
    for (node = self->bgmHead; node != 0; node = node->next) {
        if ((node->flags & CSND_BGM_FLAG_FREE) == 0) {
            if (node->flags & CSND_BGM_FLAG_FADE) {
                node->flags &= CSND_BGM_FADE_CLEAR;
                cSndBgmNode_FadeIn(node, CSND_BGM_FADE_TIME);
            }
        } else {
            cSndBgmNode_Release(node);
        }
    }
    *(int *)((char *)self + CSND_UNK_A4_OFFSET) = 0;
}

/* Sets up mark `mark` (0 to 2): clears its flag word, sets the start-lit bit
 * if startLit, and shows or hides its scroll layer; showing also sets the on bit. */
__attribute__((section(".text.MarkPanel_setMark")))
void MarkPanel_setMark(MarkPanel *self, unsigned short mark, int show, int startLit)
{
    switch (mark) {
    case 0:
        self->markFlag[0] = 0;
        if (startLit)
            self->markFlag[0] = MARKPANEL_F_START_LIT;
        if (show) {
            displayScrollLayer(self->layer[0], 1);
            self->markFlag[0] = self->markFlag[0] | MARKPANEL_F_ON;
        } else {
            displayScrollLayer(self->layer[0], 0);
        }
        break;
    case 1:
        self->markFlag[1] = 0;
        if (startLit)
            self->markFlag[1] = MARKPANEL_F_START_LIT;
        if (show) {
            displayScrollLayer(self->layer[1], 1);
            self->markFlag[1] = self->markFlag[1] | MARKPANEL_F_ON;
        } else {
            displayScrollLayer(self->layer[1], 0);
        }
        break;
    case 2:
        self->markFlag[2] = 0;
        if (startLit)
            self->markFlag[2] = MARKPANEL_F_START_LIT;
        if (show) {
            displayScrollLayer(self->layer[2], 1);
            self->markFlag[2] = self->markFlag[2] | MARKPANEL_F_ON;
        } else {
            displayScrollLayer(self->layer[2], 0);
        }
        break;
    }
}

#define OM_OFFSET_MODE  0x2F4           /* mode byte, read through the raw offset as retail does */
#define OM_MODE(s)      (*(unsigned char *)((s) + OM_OFFSET_MODE))

/* One pointer-to-member record, g++ 2.x layout: this adjust, vtable index (-1 for a plain function) and the vtable offset or function. */
typedef struct PhaseMemFn {
    short delta;
    short index;
    short vtOfs;
    short pad6;
} PhaseMemFn;

extern PhaseMemFn D_003BDD88[];

/* Per-frame update: run the handler picked by the mode byte (one
 * pointer-to-member record), rebuild the model parts and copy the live
 * positions to the saved ones. */
__attribute__((section(".text.cOmBase_updatePhaseAndCalcParts")))
void cOmBase_updatePhaseAndCalcParts(cOmBase *self)
{
    char *s0 = (char *)self;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0)
        return;
    i8 = OM_MODE(s0) * 8;
    e = (char *)D_003BDD88 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)D_003BDD88 + i8 + 4);
    }
    f0 = D_003BDD88[OM_MODE(s0)].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cModel_calcParts(self);
    cVec_copy3(&self->posA, self->pos);
    cVec_copy3(&self->posB, &self->rot);
}

#define POKER_OFFSET_UI     0x25B0    /* the table's UI record is not typed yet */
#define POKER_UI(self)      ((char *)(self) + POKER_OFFSET_UI)
#define POKER_BGM_EVENT     0x28
#define POKER_WAIT_FRAMES   0x1E
#define POKER_STATE_IDLE    0x14      /* state the table returns to */

/* Counts the timer down; nonzero once it has reached 0. */
static __inline__ unsigned char Poker_timerDone(Poker *self)
{
    if (self->timer == 0)
        return 1;
    self->timer--;
    return 0;
}

/* Result screen: phase 0 starts the next wait, phase 1 waits then starts the
 * result music and the UI animation, phase 2 waits then resets the bet and
 * returns the table to idle. */
__attribute__((section(".text.Poker_updateResultWait")))
void Poker_updateResultWait(Poker *self)
{
    switch (self->phase) {
    case 1:
        if (!Poker_timerDone(self))
            return;
        cSnd_BgmEventStart(D_005FEE00, POKER_BGM_EVENT, 0, 0);
        func_001DF528(POKER_UI(self), 1, 4);
        /* fall through */
    case 0:
        self->timer = POKER_WAIT_FRAMES;
        self->phase = self->phase + 1;
        break;
    case 2:
        if (Poker_timerDone(self)) {
            char *ui = POKER_UI(self);
            self->bet = 0;
            func_001DEE40(ui, 0);
            func_001DF528(ui, 1, 3);
            self->phase = 0;
            self->state = POKER_STATE_IDLE;
        }
        break;
    }
}

/* Sets the screen up: initialises its four display entries, restarts the
 * animation, marks it playing, gives both slots their constants and the
 * values copied from display entries 0 and 1, and takes the bar position
 * from entry 2. */
__attribute__((section(".text.cNowLoading_setup")))
void cNowLoading_setup(cNowLoading *self)
{
    cIDBaseEnt *ent[3];
    cIDBaseEnt *barEnt;
    unsigned short i;

    cIDBase_initIDWork(self, 0);
    cIDBase_initIDWork(self, 1);
    cIDBase_initIDWork(self, 2);
    cIDBase_initIDWork(self, 3);
    cIDBase_restartAnim(self);
    self->base.playing = 1;
    ent[0] = cIDBase_getIDWork(self, 0);
    ent[1] = cIDBase_getIDWork(self, 1);
    barEnt = cIDBase_getIDWork(self, 2);
    ent[2] = cIDBase_getIDWork(self, 3);
    for (i = 0; i < NOWLOADING_SLOT_NUM; i++) {
        self->slot[i].one = NOWLOADING_SLOT_ONE;
        self->slot[i].two = NOWLOADING_SLOT_TWO;
        self->slot[i].copyA = ent[i]->f70[1];
        self->slot[i].copyB = ent[i]->f70[3];
    }
    self->barX = barEnt->posX;
    self->barLen = NOWLOADING_BAR_LEN;
    self->unkB0 = 0;
    self->unkBC = 0;
}
