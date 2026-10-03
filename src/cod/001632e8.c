/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cDataManager.h"
#include "godhand/cIDBase.h"
#include "godhand/cCoreSave.h"

extern void func_0028FB08(void *em);
extern int D_005FEE00;
extern int cSnd_SeIsLoadOk(void *snd, int handle);
extern char D_00462FC0[];
extern void cCollisionSolidManage_SetActive(void *mgr, void *obj, int on);
extern void cIDBase_move(void *self);
extern unsigned int D_00747A84;
extern char D_00586AF0[];
extern unsigned int cEvent_getCutNo();
extern void UpdateObjByIndexedOp_2FBE50(void *slot);

#define EM_HIT_FLASH_FULL  3.0f
#define EM_FADE_STEP       0.1f

/* Phase 0: start the death and flash the body. Phase 1: slow the animation to a stop, then release the enemy. */
__attribute__((section(".text.cEm00_stepFadeOutAndRelease")))
void cEm00_stepFadeOutAndRelease(cEm00 *self) {
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

/* Sound handles a data slot owns (10 ints at 0x24, -1 for none). */
#define SLOT_SE_NUM        10
#define SLOT_SE(slot)      ((int *)((char *)(slot) + 0x24))
#define SLOT_SE_NONE       (-1)

/* Try to drop every sound handle of the slot whose sound has finished loading; 1 if the last one tried was dropped (or none was held). */
__attribute__((section(".text.cDataSlot_releaseLoadedSe")))
int cDataSlot_releaseLoadedSe(cDataSlot *slot) {
    int *p = SLOT_SE(slot);
    int ok = 1;
    int i;
    for (i = SLOT_SE_NUM - 1; i >= 0; i--) {
        if (*p >= 0) {
            if (cSnd_SeIsLoadOk(&D_005FEE00, *p) != 0) {
                *p = SLOT_SE_NONE;
                ok = 1;
                slot->flags &= ~CDATA_FLAG_BUSY;
            } else if (ok != 0) {
                ok = 0;
            }
        }
        p++;
    }
    return ok;
}

/* cEm00.fadeTimer, see cEm00_fields.h in the lane directory (field not in cEm00.h yet). */
#define EM_FADETIMER(self) (*(float *)((char *)(self) + 0x1704))

#define EM_FADE_STEP       0.02f        /* timer decrease per call */
#define EM_FLAG_FADING     0x10         /* objFlags: the fade is still running */

/* Advance the fade-in: deactivate the collision, count the timer down and ramp the animation rate up to 1.0. Returns 0 once the timer has run out. */
__attribute__((section(".text.cEm00_stepFadeIn")))
int cEm00_stepFadeIn(cEm00 *self) {
    float t;
    float rate;
    if (EM_FADETIMER(self) <= 0.0f) {
        return 0;
    }
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    t = EM_FADETIMER(self) - EM_FADE_STEP;
    rate = 1.0f - t;
    EM_FADETIMER(self) = t;
    self->animRate = rate;
    if (rate >= 1.0f) {
        self->animRate = 1.0f;
        self->objFlags &= 0xFFFFFFEF;     /* ~EM_FLAG_FADING; the unsigned constant is what retail builds with lui+ori */
    } else {
        self->objFlags |= EM_FLAG_FADING;
    }
    return 1;
}

/* The number display that shows the player's gold. */
typedef struct GoldDisp {
    char unk00[0x84];
    int value;                          /* 0x84 number shown */
} GoldDisp;

/* A display object with a gold counter and a three-way state at 0x64. */
typedef struct GoldPanel {
    cIDBaseObj base;
    char unk48[0x64 - sizeof(cIDBaseObj)];
    unsigned char state;                /* 0x64 */
    char unk65[0xE0 - 0x65];
    GoldDisp *goldDisp;                 /* 0xE0 */
    cIDBaseEnt *frameEnt;               /* 0xE4 entry whose flag bit 27 is cleared every frame */
} GoldPanel;

extern void func_001633A0(GoldPanel *self);
extern void func_001634E0(GoldPanel *self);
extern void func_00163F00(GoldPanel *self);


#define GOLDPANEL_ENT_FLAG_27  0x08000000

/* Per-frame update: refresh the gold number, clear the frame entry's flag, run the state handler, advance the animation. */
__attribute__((section(".text.GoldPanel_update")))
void GoldPanel_update(GoldPanel *self) {
    self->goldDisp->value = cCoreSave_getGold(&D_00569B70);
    self->frameEnt->flags &= ~GOLDPANEL_ENT_FLAG_27;
    switch (self->state) {
    case 0:
        func_001633A0(self);
        break;
    case 1:
        func_001634E0(self);
        break;
    case 2:
    case 3:
        func_00163F00(self);
        break;
    }
    cIDBase_move(self);
}

#define SYSFLAG_EVENT_RUNNING  0x20000000       /* D_00747A84: a cutscene is running */
#define CUT_CURRENT            0xFF             /* cut number meaning "the cut that is playing" */

/* A cut number of a command record, as the game stores it: a halfword that the player also reads as a byte. */
typedef union CutNo {
    unsigned short w;
    unsigned char b;
} CutNo;

typedef struct CutCmdRec {
    char unk00[2];
    CutNo first;                        /* 0x2 first cut of the command */
    CutNo last;                         /* 0x4 last cut of the command */
} CutCmdRec;

/* A cutscene command object. */
typedef struct CutCmd {
    char unk00[0x44];
    unsigned char cutFirst;             /* 0x44 resolved first cut */
    char unk45[7];
    unsigned char cutLast;              /* 0x4C resolved last cut */
    char unk4D[0x8C - 0x4D];
    CutCmdRec *rec;                     /* 0x8C */
} CutCmd;

/* Resolve the first and last cut of the command (0xFF means the current cut). Returns nonzero if the current cut is before the first one. Does nothing, returning 0, while no cutscene runs. */
__attribute__((section(".text.CutCmd_resolveCuts")))
int CutCmd_resolveCuts(CutCmd *self) {
    if ((D_00747A84 & SYSFLAG_EVENT_RUNNING) == 0) {
        return 0;
    }
    self->cutFirst = (self->rec->first.w == CUT_CURRENT) ? cEvent_getCutNo(D_00586AF0) : self->rec->first.b;
    self->cutLast = (self->rec->last.w == CUT_CURRENT) ? cEvent_getCutNo(D_00586AF0) : self->rec->last.b;
    func_00297BA8(D_00586AF0, self->cutLast);
    return cEvent_getCutNo(D_00586AF0) < self->cutFirst;
}

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: slot paused */
extern int D_0071B8C0[];                /* bit set: slot hidden */
extern unsigned char D_0061B7C0[];      /* the 0x400 effect slots, 0x400 bytes each */


#define ESP_SLOT_NUM   0x400
#define ESP_SLOT_SIZE  0x400

/* Run the kill handler of every effect slot that is in use and neither paused nor hidden. */
__attribute__((section(".text.EspAllKill")))
void EspAllKill(void) {
    unsigned char *p;
    int i;
    unsigned int mask;
    int w;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        mask = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & mask) == 0) goto next;
        if ((D_0071B840[w] & mask) != 0) goto next;
        if ((D_0071B8C0[w] & mask) != 0) goto next;
        p = D_0061B7C0 + i * ESP_SLOT_SIZE;
        UpdateObjByIndexedOp_2FBE50(p);
next: ;
    }
}
