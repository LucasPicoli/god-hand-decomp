/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/CustomIDWork.h"

extern void cModel_setTextureExchange(void *model, int set, int rec, int flag);
extern void SetCustomIDDispOneOrAll_1F4778(void *self, int sel, int on);
extern void CustomIDWork_SetNumber(CustomIDWork *self, int number);
extern void CustomIDWork_SetOffsetPosX(CustomIDWork *self, int x);

/* A message window as a node of the used and free lists. */
typedef struct MsgNode {
    unsigned short id;          /* 0x00 */
    short val;                  /* 0x02 */
    struct MsgNode *prev;       /* 0x04 */
    struct MsgNode *next;       /* 0x08 */
} MsgNode;

/* The window manager: list heads at 0x10 (used) and 0x14 (free). */
typedef struct MsgMgr {
    char unk00[0x10];
    MsgNode *used;              /* 0x10 */
    MsgNode *freeList;          /* 0x14 */
} MsgMgr;

extern void cMessageWin_close(MsgNode *win);

extern void func_002B22E8(MsgNode *node, MsgNode *prev, MsgNode *next, short val, unsigned short id);

/* cMessage_releaseWin: take a window off the used list (advancing the head when it is first), close it and
 * push it on the free list. Returns the window that followed it. */
__attribute__((section(".text.cMessage_releaseWin")))
MsgNode *cMessage_releaseWin(MsgMgr *self, MsgNode *win)
{
    MsgNode *next;
    if (win->prev == 0) {
        self->used = win->next;
    }
    cMessageWin_close(win);
    next = func_002B2318(win);
    func_002B22E8(win, 0, self->freeList, 0, 0);
    self->freeList = win;
    return next;
}

/* The flag word at 0x254 and the texture set at 0x284 are inside cEm00's unnamed gap. */
#define EM_FLAGS254(self)  (*(unsigned int *)((char *)(self) + 0x254))
#define EM_TEXSET(self)    (*(int *)((char *)(self) + 0x284))
#define EM_FLAG254_TEXHIDE 0x10000000


/* cEm00_stepTextureHide: for enemy 0x265, count down the texture-hide counter (unk186A) clearing the hide flag
 * while it runs and setting it when it is out, then swap in the resource texture record 0x8C. */
__attribute__((section(".text.cEm00_stepTextureHide")))
void cEm00_stepTextureHide(cEm00 *self)
{
    if ((self->emNo ^ 0x265) == 0) {
        if ((signed char)self->unk186A != 0) {
            EM_FLAGS254(self) &= ~EM_FLAG254_TEXHIDE;
            self->unk186A = self->unk186A - 1;
        } else {
            EM_FLAGS254(self) |= EM_FLAG254_TEXHIDE;
        }
        cModel_setTextureExchange(self, EM_TEXSET(self), EM_RES_REC(EM_RES(self), 0x8C), 0);
    }
}

/* CustomIDOwner_setAllShown: show or hide the seven ID elements 0x61 to 0x67 of the owner. */
__attribute__((section(".text.CustomIDOwner_setAllShown")))
void CustomIDOwner_setAllShown(void *self, int on)
{
    SetCustomIDDispOneOrAll_1F4778(self, 0x61, on);
    SetCustomIDDispOneOrAll_1F4778(self, 0x62, on);
    SetCustomIDDispOneOrAll_1F4778(self, 0x63, on);
    SetCustomIDDispOneOrAll_1F4778(self, 0x64, on);
    SetCustomIDDispOneOrAll_1F4778(self, 0x65, on);
    SetCustomIDDispOneOrAll_1F4778(self, 0x66, on);
    SetCustomIDDispOneOrAll_1F4778(self, 0x67, on);
}

/* The score element sits at 0x22C4 of the owner. */
#define OWNER_SCORE_IDW(self) ((CustomIDWork *)((char *)(self) + 0x22C4))

/* CustomIDOwner_setScoreNumber: show a number and shift the element left by its digit count so it stays right-aligned
 * (1 to 3 digits: -41, 4 digits: -28, 5 digits: -13, more: 0). */
__attribute__((section(".text.CustomIDOwner_setScoreNumber")))
void CustomIDOwner_setScoreNumber(void *self, int number)
{
    CustomIDWork *w = OWNER_SCORE_IDW(self);
    CustomIDWork_SetNumber(w, number);
    if (number < 1000) {
        CustomIDWork_SetOffsetPosX(w, -41);
    } else if (number < 10000) {
        CustomIDWork_SetOffsetPosX(w, -28);
    } else if (number <= 99999) {
        CustomIDWork_SetOffsetPosX(w, -13);
    } else {
        CustomIDWork_SetOffsetPosX(w, 0);
    }
}

/* The counter at 0x60E and two method-table entries (this delta at 0xA8 and 0xB8, pfn after each)
 * that cEm00Vt does not name yet. */
#define EM_COUNT60E(self)   (*(unsigned short *)((char *)(self) + 0x60E))
#define EM_VT_CALL(self, ofs) \
    ((*(void (**)(void *))((char *)(self)->vtable + (ofs) + 4))((char *)(self) + *(short *)((char *)(self)->vtable + (ofs))))

/* cEm00_stepHitStun: phase machine. Phase 0 calls two methods, loads the counter with 3 and falls into
 * phase 1, which counts it down and clears the state bytes when it runs out. */
__attribute__((section(".text.cEm00_stepHitStun")))
void cEm00_stepHitStun(cEm00 *self)
{
    switch (self->phase) {
    case 0:
        EM_VT_CALL(self, 0xA8);
        EM_VT_CALL(self, 0xB8);
        EM_COUNT60E(self) = 3;
        self->phase = 1;
        self->step = 0;
        self->stepArg = 0;
    case 1:
        EM_COUNT60E(self) = EM_COUNT60E(self) - 1;
        if ((short)EM_COUNT60E(self) <= 0) {
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
        break;
    }
}

/* The seven digit-column elements are 0x7C bytes apart from 0x60 + 0x26 * 0x7C. */
#define OWNER_COLUMN_IDW(self, i) \
    ((CustomIDWork *)((char *)(self) + 0x60 + (i) * 0x7C))

/* CustomIDOwner_setColumnNumber: set column idx (0 to 6) to a number, nudging it left by -17 for one digit, -10 for
 * two and 0 for three or more, and show or hide it. */
__attribute__((section(".text.CustomIDOwner_setColumnNumber")))
void CustomIDOwner_setColumnNumber(void *self, unsigned short idx, int number, int on)
{
    int x;
    CustomIDWork *w;
    int sel;
    if (idx < 7) {
        if (number < 10) {
            x = -17;
        } else {
            x = (number > 99) ? 0 : -10;
        }
        sel = idx + 0x26;
        w = OWNER_COLUMN_IDW(self, sel);
        CustomIDWork_SetOffsetPosX(w, x);
        CustomIDWork_SetNumber(w, number);
        SetCustomIDDispOneOrAll_1F4778(self, sel, on);
    }
}
