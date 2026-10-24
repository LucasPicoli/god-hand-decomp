/* sn-2.95.3-136 matched TU. */

#include "godhand/comboObj.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/Slot2.h"

extern void func_002CAF28(cSnd *self);
extern void cSnd_BgmControl(cSnd *self);
extern void Forward33F690_325DD8(void);
extern void cSnd_flushPendingSe(cSnd *self);
extern void func_00375380(void);
extern void func_00375500(void);
extern void cSnd_updateLoads(cSnd *self);
extern void Ring_stepToAccepted(void *p);
extern int cSnd_SeFadeOut(cSnd *self, int handle, short fade);
extern char D_00603A40[];
extern void cNode_clearActiveRecursive(void *self);
extern int CallThenReturnPlusB0_002B6420_2B61B0(void *parent);
extern void MtxInverse(void *dst, void *src);
extern void sceVu0ApplyMatrix(void *dst, void *mtx, void *vec);
extern void cNode_setLocalTranslation(void *self, void *v);
extern int strlen(const char *s);
extern char D_0044B060[];
extern char D_0044B090[];
extern void BlendWork_copyShortTable(void *self, void *src, short num);
extern void BlendWork_copyTable(void *self, void *src, short num);
extern void func_001451A0(void *self, void *src, short num);
extern void SetFlagAfterCopy_145160(void *self, void *src);
extern char D_003BD6F8[];
extern unsigned short D_003BD70C;
extern void func_001269E0(void *self, int combo, int arg);
extern void cSnd_BgmEventFade(void *snd, int reqNo, float time, float level, float weight);
extern void displayScrollLayer(int id, int on);
extern void func_00143A90(char *p);
extern char *D_003BD6E8;

#define SE_STOP_FADE  5

/* Per-frame sound update: run every sub-update, then fade out and clear each SeStop handle that is set. */
__attribute__((section(".text.cSnd_update")))
void cSnd_update(cSnd *self)
{
    unsigned int i;
    int *stop;

    func_002CAF28(self);
    stop = self->seStop;
    cSnd_BgmControl(self);
    Forward33F690_325DD8();
    cSnd_flushPendingSe(self);
    func_00375380();
    func_00375500();
    cSnd_updateLoads(self);
    Ring_stepToAccepted(D_00603A40);
    for (i = 0; i < CSND_SE_STOP_NUM; i++) {
        if (*stop != 0) {
            cSnd_SeFadeOut(self, *stop, SE_STOP_FADE);
            *stop = 0;
        }
        stop++;
    }
}

/* Set the node's local translation from a world-space position: bring `pos` into the parent's space with the inverse of the parent matrix (identity when there is no parent). */
__attribute__((section(".text.cNode_setTranslationFromWorld")))
void cNode_setTranslationFromWorld(void *self, float *pos)
{
    char frame[0x60] __attribute__((aligned(16)));
    char *vec;
    void *parent;

    cNode_clearActiveRecursive(self);
    parent = func_002B5E50(self);
    if (parent != 0) {
        MtxInverse(frame, (void *)CallThenReturnPlusB0_002B6420_2B61B0(parent));
        vec = frame + 0x50;
    } else {
        VU0_VMOVE_XYZW(4, 0);
        VU0_VMR32_XYZW(5, 4);
        VU0_VMR32_XYZW(6, 5);
        VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, frame, 0x30);
        VU0_SQC2(5, frame, 0x20);
        VU0_SQC2(6, frame, 0x10);
        VU0_SQC2(7, frame, 0x0);
        vec = frame + 0x50;
    }
    VU0_LQC2(4, pos, 0);
    VU0_SQC2(4, frame, 0x50);
    sceVu0ApplyMatrix(vec, frame, vec);
    VU0_LQC2(4, vec, 0);
    VU0_SQC2(4, frame, 0x40);
    cNode_setLocalTranslation(self, frame + 0x40);
}

extern char D_005E8140[];               /* request queue */

extern char D_0044B080[];               /* 10 byte string constant */


typedef struct { char b[10]; } Str10;

typedef struct SlotIds {
    char unk00[0xC];
    int idA;                            /* 0x0C */
    int idB;                            /* 0x10 */
} SlotIds;

/* Send the two setup requests to the queue, retrying each until it is accepted, then clear both ids. */
__attribute__((section(".text.SlotIds_sendSetup")))
void SlotIds_sendSetup(SlotIds *self)
{
    Str10 text;

    while (func_002BE240(D_005E8140, D_0044B060, 0, 0) < 0) {
    }
    text = *(Str10 *)D_0044B080;
    while (func_002BE240(D_005E8140, D_0044B090, strlen(text.b) + 1, text.b) < 0) {
    }
    self->idA = -1;
    self->idB = -1;
}

#define BLEND_CUR_MAX  0x23             /* highest valid cur value */

typedef struct BlendSetup {
    char unk000[0x422];
    short cur;                          /* 0x422 current entry, 0..0x23 */
    char unk424[0xAC];
    unsigned short extra;               /* 0x4D0 */
} BlendSetup;

/* Load the three tables and the default table, then store `start - 1` as the current entry (clamped to 0..0x23; before the first entry wraps to num - 1). */
__attribute__((section(".text.BlendSetup_load")))
void BlendSetup_load(BlendSetup *self, void *tblA, void *tblB, void *tblC, short num, unsigned short start)
{
    int idx;

    BlendWork_copyShortTable(self, tblB, num);
    BlendWork_copyTable(self, tblA, num);
    func_001451A0(self, tblC, num);
    SetFlagAfterCopy_145160(self, D_003BD6F8);
    idx = start - 1;
    if (idx < 0) {
        self->cur = num - 1;
    } else if (idx >= BLEND_CUR_MAX + 1) {
        self->cur = BLEND_CUR_MAX;
    } else {
        self->cur = idx;
    }
    self->extra = D_003BD70C;
}

extern int D_003BC7D0[];                /* combo table, 0x14 bytes per combo, first word used */

#define COMBO_ENTRY_WORDS  5            /* 0x14 bytes */

/* Start the next combo of the current set: wrap to slot 0 of set 0 once the slot passes the set's size, look up the combo, load its first word as the move, start it and advance the slot. Returns the combo id. */
__attribute__((section(".text.ComboObj_startNext")))
int ComboObj_startNext(ComboObj *self)
{
    int combo;
    int move;

    if (!(self->slot < cCoreSave_getComboMax(&D_00569B70, self->set))) {
        self->set = 0;
        self->slot = 0;
    }
    combo = cCoreSave_getCombo(&D_00569B70, self->set, self->slot);
    cCoreSave_getComboLv(&D_00569B70, self->set, self->slot);
    self->ticks = 0;
    self->stage = 0;
    move = D_003BC7D0[combo * COMBO_ENTRY_WORDS];
    self->moveB = move;
    self->moveA = move;
    func_001269E0(self, combo, 0);
    self->slot++;
    return combo;
}

extern char D_005FEE00[];               /* cSnd */


#define BGM_REQ_A   0x25
#define BGM_REQ_B   0x24

/* End-of-game stage: on the first call fade out both BGM requests, hide layer 1, run the end hook and flag the game as over. */
__attribute__((section(".text.Slot2_endGameFade")))
void Slot2_endGameFade(Slot2 *self)
{
    switch (self->step) {
    case 0:
        cSnd_BgmEventFade(D_005FEE00, BGM_REQ_A, 15.0f, 0.0f, -1.0f);
        cSnd_BgmEventFade(D_005FEE00, BGM_REQ_B, 15.0f, 0.0f, -1.0f);
        displayScrollLayer(1, 0);
        func_00143A90(D_003BD6E8 + 0x1AE0);
        self->endFlag |= 1;
        self->step++;
        break;
    }
}
