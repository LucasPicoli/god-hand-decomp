/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"
#include "godhand/cActionButton.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"
#include "godhand/cNode.h"

extern void cIDBase_trans(void *p);
extern void displayScrollLayer(int id, int on);
extern int Rnd(void);
extern void func_001F7820(void *mgr, void *ent);
extern void cNode_clearActiveRecursive(void *self);
extern void func_002B60D0(void *dst, void *src);
extern void func_002B6230(void *self, void *v);
extern int func_001B8030(void *obj);

#define DRAW_FLAG_ENABLED  0x20000000   /* IdDrawObj.flags: the display is switched on */
#define SYS_HIDE_BIT       3            /* sysState.flags: bit 3 hides every display */

typedef struct IdOwner {
    char unk000[0x548];
    short hp;                           /* 0x548 */
} IdOwner;

typedef struct IdDrawObj {
    char unk00[0x94];
    void *child;                        /* 0x94 */
    char unk98[4];
    IdOwner *owner;                     /* 0x9C */
    unsigned int flags;                 /* 0xA0 */
} IdDrawObj;

typedef struct SysState {
    int flags;                          /* 0x00 */
    char unk04[4];
    int pause;                          /* 0x08 negative while the game is paused */
} SysState;

extern SysState D_00747A24;

/* Draw the display when its owner is alive and switched on, the game is not paused or hidden, and the save state allows it. */
__attribute__((section(".text.IdDrawObj_transIfShown")))
void IdDrawObj_transIfShown(IdDrawObj *self)
{
    unsigned long flags;
    unsigned long bit;

    if (self->child == 0) return;
    if (self->owner == 0) return;
    flags = D_00747A24.flags;
    bit = (flags >> SYS_HIDE_BIT) & 1;
    if (bit) return;
    if (D_00747A24.pause < 0) return;
    if (self->owner->hp == 0) return;
    if ((self->flags & DRAW_FLAG_ENABLED) == 0) return;
    if (cCoreSave_getStateBit0(&D_00569B70) != 0) return;
    cIDBase_trans(self);
}

#define LAYER_A  0x1E
#define LAYER_B  0x1F
#define MODE_START  0
#define MODE_END    0xD
#define SCALE_START 0.0f
#define SCALE_END   101.0f

/* Hide both scroll layers when the progress value reaches the end of mode 0 (0.0) or mode 13 (101.0). */
__attribute__((section(".text.ScrollLayer_hideAtEnd")))
void ScrollLayer_hideAtEnd(int mode, float value)
{
    switch (mode) {
    case MODE_START:
        if (value == SCALE_START) {
            displayScrollLayer(LAYER_A, 0);
            displayScrollLayer(LAYER_B, 0);
        }
        break;
    case MODE_END:
        if (value == SCALE_END) {
            displayScrollLayer(LAYER_A, 0);
            displayScrollLayer(LAYER_B, 0);
        }
        break;
    }
}

extern int D_00427CD8[6];               /* chance divisor per level */

typedef struct { int w[6]; } DivTable;

#define LEVEL_ALWAYS  3                 /* levels below this always succeed */

/* Chance roll: levels 0..2 always succeed, higher levels succeed one time in the level's divisor. */
__attribute__((section(".text.Level_rollChance")))
int Level_rollChance(int unused, int level)
{
    DivTable tbl = *(DivTable *)D_00427CD8;

    if (level < LEVEL_ALWAYS) {
        return 1;
    }
    return Rnd() % tbl.w[level] == 0;
}

extern char D_00568288[];               /* the cActionButton manager */

/* Offsets of entry words the header does not name yet. */
#define ACTBTN_ENT_UNK0C  0xC
#define ACTBTN_ENT_UNK2C  0x2C
#define ACTBTN_ENT_WORD(ent, off)  (*(int *)((char *)(ent) + (off)))

/* Reset an entry to an unused prompt: register it with the manager, drop the in-use bit and clear every field. */
__attribute__((section(".text.cActionButtonEnt_reset")))
void cActionButtonEnt_reset(cActionButtonEnt *self)
{
    func_001F7820(D_00568288, self);
    self->flags &= ~ACTBTN_ENT_USED;
    ACTBTN_ENT_WORD(self, ACTBTN_ENT_UNK0C) = 1;
    self->life = ACTBTN_DEFAULT_LIFE - 1;
    ACTBTN_ENT_WORD(self, ACTBTN_ENT_UNK2C) = 0x1F;
    self->unk10 = 0;
    self->unk14 = 0;
    self->priority = 0;
    self->kind = 0;
    self->unk20 = 0;
    self->matrix = 0;
    self->unk30 = 0;
    self->cmdNum = 0;
    self->unk35 = 0;
    self->unk32 = 0;
    self->unk36 = 0;
    self->cmdTbl = 0;
    self->idTbl = 0;
    self->argTbl = 0;
}

/* Set the node's translation to `pos` relative to its parent's position (zero when it has no parent). */
__attribute__((section(".text.cNode_setTranslationFromParent")))
void cNode_setTranslationFromParent(void *self, cVec *pos)
{
    cVec parentPos;
    CVEC_TEMPS;
    void *parent;

    cNode_clearActiveRecursive(self);
    CVEC_ZERO(parentPos);
    parent = func_002B5E50(self);
    if (parent != 0) {
        func_002B60D0(&ret_, parent);
        CVEC_FROM_RET(parentPos);
    }
    CVEC_SUB(pos, &parentPos);
    func_002B6230(self, &ret_);
}

typedef struct ObjList {
    char unk00[4];
    char **begin;                       /* 0x04 first object pointer */
    char **end;                         /* 0x08 one past the last */
} ObjList;

extern ObjList *D_00754C58;             /* the room's object list */

#define ACTOR_ITEM_FIRST  0x300         /* item actor ids are 0x300..0x4FF */
#define ACTOR_ITEM_END    0x500

/* 1 when lo <= k < hi. The long result is what splits the compare from its zero extension. */
/* 1 when lo <= k < hi. Testing k >= lo into its own int first is what gives retail's xori + beqz. */
static __inline__ long inrange(unsigned short k, int lo, int hi)
{
    long c;
    int t;
    c = 0;
    t = (k >= lo);
    if (t) {
        t = (k < hi);
        c = t;
    }
    return c;
}

/* Count the item objects in the room for which func_001B8030 answers 1. */
__attribute__((section(".text.getItemNumInRoom")))
int getItemNumInRoom(void)
{
    int n = 0;
    char **p;
    unsigned short k;

    for (p = D_00754C58->begin; p != D_00754C58->end; p++) {
        k = *(unsigned short *)(*p + 0x2FE);
        if (inrange(k, ACTOR_ITEM_FIRST, ACTOR_ITEM_END) & 0xFF) {
            if (func_001B8030(*p) == 1) {
                n++;
            }
        }
    }
    return n;
}
