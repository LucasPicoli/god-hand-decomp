/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"

extern void func_002FBED0(void *self);
extern void Pos_followGround(void *self);
extern void cOmBase_dropTestB(void *self);
extern void func_002E2E00(void *self);
extern void UpdateObjByIndexedOp_2FBE50(void *self);
extern void *_MemoryAlloc(int size, int align, void *region);
extern void func_002D5768(void *entry, int src, int id, void *owner);
extern int CreateSema(void *param);
extern char D_00754200[];
extern void cEm00_swapTextureAndShowMesh(void *self);
extern void cModel_setTextureExchange(void *model, int texSet, int tex, int arg);
extern void func_00194558(void *self);
extern unsigned int cEvent_getCutNo();
extern float cEvent_getCutFrame(void *ev);
extern void CustomIDWork_SetDisp(char *work, int on);

#define MODE_FLAG_PAUSED   0x1          /* modeFlags: the state machine is held */
#define MODE_FLAG_SET_RATE 0x4          /* modeFlags: copy rateByte into animRate once */
#define RATE_DEFAULT       0x1E

typedef struct ModeObj {
    char unk000[0x24C];
    char animRate;             /* 0x24C */
    char unk24D[0x77];
    int mode;                           /* 0x2C4 which step function runs */
    char unk2C8[4];
    unsigned int modeFlags;             /* 0x2CC MODE_FLAG_* */
    char unk2D0[5];
    unsigned char rateByte;             /* 0x2D5 */
} ModeObj;

/* Per-frame update: run the step function for the current mode unless the machine is held, else apply a pending rate change. */
__attribute__((section(".text.ModeObj_update")))
void ModeObj_update(ModeObj *self)
{
    func_002FBED0(self);
    /* retail reads the held bit as a byte and flips it with xori; a plain mask gives a different branch layout */
    if ((*(unsigned char *)&self->modeFlags ^ 1) & 1) {
        switch ((unsigned int)self->mode) {
        case 0:
            Pos_followGround(self);
            return;
        case 1:
            cOmBase_dropTestB(self);
            return;
        case 2:
            func_002E2E00(self);
            return;
        default:
            UpdateObjByIndexedOp_2FBE50(self);
            return;
        }
    } else if (self->modeFlags & MODE_FLAG_SET_RATE) {
        if (self->rateByte == 0) {
            self->animRate = RATE_DEFAULT;
        } else {
            self->animRate = self->rateByte;
        }
        self->modeFlags &= ~MODE_FLAG_SET_RATE;
    }
}

#define ENTRY_SIZE  0x58

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    int attr;
    int option;
};

typedef struct EntTable {
    char *entry;                        /* 0x00 array of ENTRY_SIZE byte entries */
    char unk04[8];
    unsigned short num;                 /* 0x0C */
    unsigned short firstId;             /* 0x0E */
    struct SemaParam sema;              /* 0x10 */
    int semaId;                         /* 0x28 */
} EntTable;

/* Allocate and clear num entries, initialise each from src with consecutive ids starting at firstId, and create the table's semaphore. */
__attribute__((section(".text.EntTable_init")))
void EntTable_init(EntTable *self, int num, int src, int firstId)
{
    unsigned int i;

    self->firstId = firstId;
    self->num = num;
    self->entry = _MemoryAlloc(num * ENTRY_SIZE, 0x10, D_00754200);
    func_003A52F0(self->entry, 0, num * ENTRY_SIZE);
    for (i = 0; i < self->num; i++) {
        func_002D5768(self->entry + i * ENTRY_SIZE, src, (unsigned short)(self->firstId + i), self);
    }
    self->sema.maxCount = 1;
    self->sema.initCount = 0;
    self->semaId = CreateSema(&self->sema);
}

#define ACTION_TEX_SWAP     0x251       /* action id this check applies to */
#define OBJ_STATE_HELD      0x10        /* stateFlags bit: do nothing */
#define TEX_EXCHANGE_ON     0x10000000  /* texFlags bit */
#define TEX_MODE_ODD        1
#define TEX_MODE_SMALL_MAX  8           /* modes 2..7 turn the exchange off */

typedef struct TexObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x10F4];
    unsigned int stateFlags;            /* 0x16D4 */
    char unk16D8[0xD8];
    unsigned char texMode;              /* 0x17B0 */
} TexObj;

/* While in action 0x251: with half the max health below the current health apply the texture exchange and switch it on or off by texMode; otherwise run the recovery routine. */
__attribute__((section(".text.TexObj_updateTexExchange")))
void TexObj_updateTexExchange(TexObj *self)
{
    int half;

    if ((self->base.actionId ^ ACTION_TEX_SWAP) != 0) {
        return;
    }
    if (self->stateFlags & OBJ_STATE_HELD) {
        return;
    }
    half = self->base.hpMax / 2;
    if (!(half < self->base.hp)) {
        cEm00_swapTextureAndShowMesh(self);
        return;
    }
    cModel_setTextureExchange(self, self->base.texSet,
        *(int *)(self->base.texKey + 0x60) + self->base.texKey, 0);
    if (self->texMode != 0 && ((self->texMode & TEX_MODE_ODD) || self->texMode >= TEX_MODE_SMALL_MAX)) {
        self->base.texFlags |= TEX_EXCHANGE_ON;
    } else {
        self->base.texFlags &= ~TEX_EXCHANGE_ON;
    }
}

#define MODE_NUM  3

/* One mode entry: this-adjust, method index (or negative: handler is inline), table offset in the object. */
typedef struct ModeEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler inline at +4 */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} ModeEnt;

typedef struct { char b[0x18]; } ModeTbl;
extern ModeTbl D_00424B30;              /* the three entries */

/* Phase tick: call the handler the current phase's table entry names (a method table entry, or an inline handler for a negative index), then run the shared post step. */
__attribute__((section(".text.cOmBase_tickPhaseTable194558")))
void cOmBase_tickPhaseTable194558(cOmBase *self)
{
    ModeEnt tbl[MODE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(ModeTbl *)tbl = D_00424B30;
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
    func_00194558(self);
}

extern char D_00586AF0[];               /* cEvent */
extern unsigned int D_00747A84;         /* system flags */

#define SYSFLAG_EVENT_RUNNING  0x20000000       /* D_00747A84: a cutscene is running */
#define CUT_CURRENT            0xFF             /* cut number meaning "the cut that is playing" */

/* A cut number of a command record, as the game stores it: a halfword that the player also reads as a byte. */
typedef union CutNo {
    unsigned short w;
    unsigned char b;
} CutNo;

typedef struct CutFrameRec {
    char unk00[2];
    CutNo firstCut;                     /* 0x02 */
    unsigned short firstFrame;          /* 0x04 */
    CutNo lastCut;                      /* 0x06 */
    unsigned short lastFrame;           /* 0x08 */
} CutFrameRec;

typedef struct CutFrameCmd {
    char unk00[0x44];
    unsigned char cutFirst;             /* 0x44 resolved first cut */
    char unk45[3];
    int frameFirst;                     /* 0x48 */
    unsigned char cutLast;              /* 0x4C resolved last cut */
    char unk4D[3];
    int frameLast;                      /* 0x50 */
    char unk54[0x38];
    CutFrameRec *rec;                   /* 0x8C */
} CutFrameCmd;

/* Resolve the first and last cut and frame of the command (0xFF means the current cut). Returns 1 while the playing position is before the first cut and frame; 0 when no cutscene runs. */
__attribute__((section(".text.CutFrameCmd_resolveBefore")))
int CutFrameCmd_resolveBefore(CutFrameCmd *self)
{
    if ((D_00747A84 & SYSFLAG_EVENT_RUNNING) == 0) {
        return 0;
    }
    self->cutFirst = (self->rec->firstCut.w == CUT_CURRENT) ? cEvent_getCutNo(D_00586AF0) : self->rec->firstCut.b;
    self->frameFirst = self->rec->firstFrame;
    self->cutLast = (self->rec->lastCut.w == CUT_CURRENT) ? cEvent_getCutNo(D_00586AF0) : self->rec->lastCut.b;
    self->frameLast = self->rec->lastFrame;
    if (cEvent_getCutNo(D_00586AF0) < self->cutFirst) {
        return 1;
    }
    {
        float now = cEvent_getCutFrame(D_00586AF0);
        if ((float)self->frameFirst <= now) {
            return 0;
        }
        return 1;
    }
}

#define IDWORK_ALL    0x2D              /* id meaning every work entry */
#define IDWORK_SKIP   8                 /* the entry that "all" leaves out */
#define IDWORK_FIRST  0x60              /* offset of entry 0 */
#define IDWORK_SIZE   0x7C

/* Show or hide one entry of the work table, or all of them except entry 8 when id is 0x2D. Entry 8 alone is never touched. */
__attribute__((section(".text.CustomIDWork_setDispAllButEight")))
void CustomIDWork_setDispAllButEight(char *self, int id, int on)
{
    int i;

    if (on != 0) {
        if (id == IDWORK_ALL) {
            for (i = 0; i < IDWORK_ALL; i++) {
                if (i != IDWORK_SKIP)
                    CustomIDWork_SetDisp(self + IDWORK_FIRST + i * IDWORK_SIZE, 1);
            }
        } else if (id != IDWORK_SKIP) {
            CustomIDWork_SetDisp(self + (id * IDWORK_SIZE + IDWORK_FIRST), 1);
        }
    } else {
        if (id == IDWORK_ALL) {
            for (i = 0; i < IDWORK_ALL; i++) {
                if (i != IDWORK_SKIP)
                    CustomIDWork_SetDisp(self + IDWORK_FIRST + i * IDWORK_SIZE, 0);
            }
        } else if (id != IDWORK_SKIP) {
            CustomIDWork_SetDisp(self + (id * IDWORK_SIZE + IDWORK_FIRST), 0);
        }
    }
}
