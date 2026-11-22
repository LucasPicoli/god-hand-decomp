/* sn-2.95.3-136 matched TU. */

#include "godhand/SlotUi.h"
#include "godhand/CustomIDWork.h"
#include "godhand/DispMgr.h"
#include "godhand/globals.h"

extern void func_001E7470(SlotUi *self, int mark, int show);
extern void func_001E7538(SlotUi *self, int mark, int show);
extern void cHeap_free(int heap, int *node);
extern void __builtin_delete(void *p);
extern void CustomIDWork_SetDisp(CustomIDWork *self, int show);
extern int FindFreeSlotIndex_140C58(DispMgr *mgr);
extern void cIDBase_trans(void *idBase);

/* Show or hide marks: index SLOTUI_MARK_NUM (or SLOTUI_BET_NUM for the bet
 * group) means every entry of the group. */



/* Hides every mark and bet mark, then shows the first and last mark. */
__attribute__((section(".text.SlotUi_showEndMarks")))
void SlotUi_showEndMarks(SlotUi *self)
{
    func_001E7470(self, SLOTUI_MARK_NUM, 0);
    func_001E7538(self, SLOTUI_BET_NUM, 0);
    func_001E7470(self, 0, 1);
    func_001E7470(self, SLOTUI_MARK_NUM - 1, 1);
}

/* A part's size is the sum of two measurements asked of its child object
 * through the child's method table. */
typedef struct ChildVtEnt { short delta; short pad; float (*fn)(void *self); } ChildVtEnt;
typedef struct ChildVt {
    char unk00[0x10];
    ChildVtEnt first;                   /* 0x10 */
    char unk18[8];
    ChildVtEnt second;                  /* 0x20 */
} ChildVt;

typedef struct Part2BA7B8 {
    char unk000[0xE4];
    float size;                         /* 0x0E4 */
    char unk0E8[0x100 - 0xE8];
    ChildVt *child;                     /* 0x100 method table of the child */
} Part2BA7B8;

__attribute__((section(".text.func_002BA7B8")))
void func_002BA7B8(Part2BA7B8 *self)
{
    float a = self->child->second.fn((char *)self + self->child->second.delta);
    float b = self->child->first.fn((char *)self + self->child->first.delta);
    self->size = a + b;
}

typedef struct Obj2D5708 {
    char unk00[0x10];
    int *node;                          /* 0x10 heap node, 0 when none; word -8 is its heap */
    char unk14[0x54 - 0x14];
    void *vt;                           /* 0x54 */
} Obj2D5708;

/* Destructor: resets the method table, frees the heap node and, when the
 * low bit of `flags` is set, frees the object itself. */
__attribute__((section(".text.func_002D5708")))
void func_002D5708(Obj2D5708 *self, int flags)
{
    self->vt = D_0044D1E8;
    if (self->node != 0) {
        cHeap_free(self->node[-8], self->node);
    }
    if (flags & 1) {
        __builtin_delete(self);
    }
}

#define PANEL_ICON_NUM 4

typedef struct Panel1ED7E0 {
    int flags;                          /* 0x000 bit 0 = the icons are shown */
    char unk004[0x60 - 4];
    CustomIDWork icon[PANEL_ICON_NUM];  /* 0x060 */
    char unk250[0x348 - 0x250];
    int selected;                       /* 0x348 */
} Panel1ED7E0;

/* Hides the four icons and clears the shown bit and the selection. */
__attribute__((section(".text.Panel_hideIcons")))
void Panel_hideIcons(Panel1ED7E0 *self)
{
    CustomIDWork_SetDisp(&self->icon[0], 0);
    CustomIDWork_SetDisp(&self->icon[1], 0);
    CustomIDWork_SetDisp(&self->icon[2], 0);
    CustomIDWork_SetDisp(&self->icon[3], 0);
    self->selected = 0;
    self->flags &= ~1;
}

/* Registers `sub` of the given kind in the first free slot. 1 if there was
 * one, 0 if the table is full. */
__attribute__((section(".text.DispMgr_registerSub")))
int DispMgr_registerSub(DispMgr *mgr, void *sub, int kind)
{
    int no = FindFreeSlotIndex_140C58(mgr);
    if (no < 0) {
        return 0;
    }
    mgr->slot[no].obj = sub;
    mgr->slot[no].kind = kind;
    return 1;
}

#define GAMESTATE_HIDE_UI  0x8          /* flags: the screen draws no ui */

/* The global play state; only the fields the ui draw reads are named. */
typedef struct GameState {
    int flags;                          /* 0x00 GAMESTATE_* */
    char unk04[4];
    int stage;                          /* 0x08 negative while no stage is loaded */
    char unk0C[0x2D - 0xC];
    unsigned char showMain;             /* 0x2D draw the main id base */
} GameState;
extern GameState D_00747A24;

typedef struct Ui13E6E0 {
    char unk00[0x90];
    int hasSub;                         /* 0x90 nonzero when the sub id base at 0xB0 is in use */
    char unk94[0xB0 - 0x94];
    char subBase[0x10];                 /* 0xB0 */
} Ui13E6E0;

/* Draws the ui's id bases unless the play state hides the ui. */
__attribute__((section(".text.Ui_transIdBases")))
void Ui_transIdBases(Ui13E6E0 *self)
{
    /* 64-bit locals: retail tests the bit with dsrl, not sra. */
    unsigned long word = D_00747A24.flags;
    unsigned long bit = (word >> 3) & 1;
    if (bit != 0) {
        return;
    }
    if (D_00747A24.stage < 0) {
        return;
    }
    if (D_00747A24.showMain) {
        cIDBase_trans(self);
    }
    if (self->hasSub) {
        cIDBase_trans(self->subBase);
    }
}
