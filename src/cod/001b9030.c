/* sn-2.95.3-136 matched TU. */

#include "godhand/cEmSetParam.h"
#include "godhand/cScenario.h"
#include "godhand/Slot2.h"
#include "godhand/cOmBase.h"
#include "godhand/cMessage.h"

extern int D_00747A24;
extern void func_001E6820(Slot2 *self);
extern void displayScrollLayer(int id, int on);
extern int cDvd_ReadAlloc(void *dvd, const char *name, void *outBuf, void *heap, int a4, int a5, int a6, int a7);
extern void cDvd_CheckWaitFrame(void *dvd, int id);
extern void cHeap_free(int heap, int *node);
extern int cDamageManage_ReleaseDamageGive(void *mgr, void *give);
extern void KillEffect(void *obj, int a, int b);
extern void SetField214PtrThenInit_1B6F38(void *obj, void *arg);
extern char D_005FEE00[];
extern void cSndSeVoice_CheckEnd(void *snd, int handle);
extern void func_002AEF98(void *pool);

/* Room init of the placement list: unless the scenario is in its fixed mode, clear the 0x30 byte scratch area and reset the room number. */



#define SCENARIO_OFFSET_MODE   0x14     /* cScenario byte not yet named in the header */
#define SYSFLAG_NO_ROOM_RESET  0x1000000

/* The part of the placement object past cEmSetParam: a 0x30 byte scratch area. */
typedef struct cEmSetParamRoom {
    cEmSetParam head;
    char scratch[0x30];                 /* 0x10 */
} cEmSetParamRoom;




__attribute__((section(".text.cEmSetParam_resetRoom")))
void cEmSetParam_resetRoom(cEmSetParamRoom *self)
{
    if ((D_00747A24 & SYSFLAG_NO_ROOM_RESET) == 0) {
        if (*((unsigned char *)D_003C2F84 + SCENARIO_OFFSET_MODE) != 1) {
            func_003A52F0(self->scratch, 0, sizeof(self->scratch));
            self->head.unk04 = 0xFFFF;
        }
    }
}

/* Show or hide the payline mark layers: refresh the marks, then switch four of the five layer ids on, or only the middle one when `all` is 0. */


/* Five layer ids at 0x3A0, not named in Slot2.h. Retail re-reads each from self, so no pointer local. */
#define SLOT2_OFFSET_MARK_LAYER  0x3A0
#define SLOT2_MARK_LAYER(self, n) (*(int *)((char *)(self) + SLOT2_OFFSET_MARK_LAYER + 4 * (n)))




__attribute__((section(".text.Slot2_showMarkLayers")))
void Slot2_showMarkLayers(Slot2 *self, int all)
{
    func_001E6820(self);
    if (all) {
        displayScrollLayer(SLOT2_MARK_LAYER(self, 0), 1);
        displayScrollLayer(SLOT2_MARK_LAYER(self, 2), 1);
        displayScrollLayer(SLOT2_MARK_LAYER(self, 3), 1);
        displayScrollLayer(SLOT2_MARK_LAYER(self, 4), 1);
    } else {
        displayScrollLayer(SLOT2_MARK_LAYER(self, 1), 1);
    }
}

/* Read a 12 byte sound effect record: zeroed unless `valid` is 1, in which case it is copied from `src`. Returned by value. */
typedef struct MotionSeData {
    char b[12];
} MotionSeData;




__attribute__((section(".text.Motion_seq_readSeData")))
MotionSeData Motion_seq_readSeData(const void *src, unsigned char valid)
{
    MotionSeData r;
    func_003A52F0(&r, 0, sizeof(r));
    if (valid == 1)
        func_003A5148(&r, src, sizeof(r));
    return r;
}

/* Load a resource file into slot->data, wait for the read, then run the link step; on failure free the data again. Returns the link result. */
typedef struct cRelSlot {
    void *data;                         /* 0x00 file contents, 0 when none */
    unsigned char ok;                   /* 0x04 link result */
    char pad05[3];
} cRelSlot;                             /* 0x08 */

extern char D_00583F20[];               /* the disc reader */
extern char D_00754220[];               /* heap the file is read into */





__attribute__((section(".text.cRelSys_loadSlot")))
unsigned char cRelSys_loadSlot(cRelSlot *slot, const char *name)
{
    int id = cDvd_ReadAlloc(D_00583F20, name, slot, D_00754220, 0, 0, 0, 0);
    cDvd_CheckWaitFrame(D_00583F20, id);
    slot->ok = func_002BE6A0(slot);
    if (slot->ok == 0) {
        int *node = (int *)slot->data;
        if (node != 0)
            cHeap_free(node[-8], node);
        slot->data = 0;
    }
    return slot->ok;
}

/* Tear down an object with two damage-give records: install the class vtable, release both records, kill its effects and run the common init. */


#define OM_OFFSET_VTABLE  0x214         /* vtable pointer, not named in cOmBase.h */

typedef struct cOmGiveRef {
    void *give;                         /* damage-give record, 0 when none */
    int id;                             /* -1 when none */
} cOmGiveRef;

typedef struct cOmTwoGive {
    cOmBase base;
    char unk5E0[0x20];
    cOmGiveRef ref[2];                  /* 0x600 */
} cOmTwoGive;

extern char D_004290C8[];               /* this class's vtable */
extern char D_00574380[];               /* damage manager */




__attribute__((section(".text.cOmTwoGive_destroy")))
void cOmTwoGive_destroy(cOmTwoGive *self, void *arg)
{
    *(void **)((char *)self + OM_OFFSET_VTABLE) = D_004290C8;
    if (cDamageManage_ReleaseDamageGive(D_00574380, self->ref[0].give) != 0) {
        self->ref[0].give = 0;
        self->ref[0].id = -1;
    }
    if (cDamageManage_ReleaseDamageGive(D_00574380, self->ref[1].give) != 0) {
        self->ref[1].give = 0;
        self->ref[1].id = -1;
    }
    KillEffect(self, 0, 2);
    SetField214PtrThenInit_1B6F38(self, arg);
}

/* Close a message window that is open: stop its voice, give the window's slot back, reset it to state 7 and clear the open flag. Does nothing when the window is not open. */


#define MWIN_FLAG_OPEN   0x1000         /* flags bit 12: window is open */
#define MWIN_STATE_IDLE  7

/* The window past its link: four state bytes, flags and the voice. */
typedef struct MessWin {
    cMessageWin base;                   /* 0x00 */
    unsigned char state;                /* 0x0C */
    unsigned char stateB;               /* 0x0D */
    unsigned char stateC;               /* 0x0E */
    unsigned char stateD;               /* 0x0F */
    char unk10[4];
    int flags;                          /* 0x14 */
    char unk18[4];
    int voice;                          /* 0x1C sound voice, 0 when none */
    int voiceId;                        /* 0x20 handle of that voice, -1 when none */
} MessWin;


extern char *D_003C23A4;                /* window slot pool */



extern void func_002B4428(MessWin *self, int a1, int a2);
extern void func_002B45E8(MessWin *self);

__attribute__((section(".text.cMessageWin_close")))
void cMessageWin_close(MessWin *self)
{
    if ((self->flags & MWIN_FLAG_OPEN) == 0)
        return;
    if (self->voice != 0)
        cSndSeVoice_CheckEnd(D_005FEE00, self->voiceId);
    /* int views of the two voice words: a struct member store would let the D_003C23A4 load schedule above them. */
    *(int *)&self->voice = 0;
    *(int *)&self->voiceId = -1;
    if (func_002AEF90(D_003C23A4) == 0)
        func_002B4428(self, 0, 0);
    else
        func_002AEF98(D_003C23A4);
    func_002B45E8(self);
    self->flags &= ~MWIN_FLAG_OPEN;
    self->state = MWIN_STATE_IDLE;
    self->stateB = 0;
    self->stateC = 0;
    self->stateD = 0;
}
