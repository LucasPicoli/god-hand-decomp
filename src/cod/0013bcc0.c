/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/globals.h"

extern void cIDBase_move(void *);
extern void cIDBase_trans(void *);
extern void CustomIDWork_SetMessNo(void *work, int messNo);
extern void func_001415E8(void *self, int arg);
extern void displayScrollLayer(int layer, int on);
extern long D_007474A0[];
extern void cIDBase_restartAnim(void *self);
extern void *cIDBase_getIDWork(void *self, int idx);

/* Run an entry's update hook from the type table D_003BF0E0 (g++ 2.x
 * delta/index/pfn entries, indexed by the type byte at +0), set the screen
 * state to 10, then move and draw the inner display at +0x30. */
typedef struct HookEnt {
    short delta;                        /* added to the object before the call */
    short index;
    void (*pfn)(void *self);
} HookEnt;

extern HookEnt D_003BF0E0[];




#define SCREEN_STATE_ENTRY_RUN 10

__attribute__((section(".text.Entry_runHookAndDraw")))
void Entry_runHookAndDraw(unsigned char *self) {
    int type = self[0];
    int delta = D_003BF0E0[type].delta;
    D_003BF0E0[type].pfn(self + delta);
    D_005CAE40 = SCREEN_STATE_ENTRY_RUN;
    cIDBase_move(self + 0x30);
    cIDBase_trans(self + 0x30);
}

/* Set message `messNo` on the two work records of display slot `slot`
 * (slot < 5): one in the first bank at 0x4BC, one in the second at 0x12C8,
 * both banks with a stride of one CustomIDWork (0x7C). */
#define SLOT_COUNT      5
#define WORK_SIZE       0x7C            /* sizeof(CustomIDWork) */
#define BANK_A_OFFSET   0x4BC
#define BANK_B_OFFSET   0x12C8



__attribute__((section(".text.CustomIDWork_setSlotMessNo")))
void CustomIDWork_setSlotMessNo(char *self, unsigned short slot, int messNo) {
    if (slot < SLOT_COUNT) {
        int off = slot * WORK_SIZE;
        CustomIDWork_SetMessNo(self + (off + BANK_A_OFFSET), messNo);
        CustomIDWork_SetMessNo(self + (off + BANK_B_OFFSET), messNo);
    }
}

/* Call the virtual hook (vt entry 3) of each of the 17 listed objects
 * (12-byte records from 0x22F4, object pointer first), clear the busy byte
 * at 0x23BC and run func_001415E8. */
typedef struct HookVt {
    char unk00[0x18];
    short delta;                        /* 0x18 */
    short index;
    void (*pfn)(void *self);            /* 0x1C */
} HookVt;

typedef struct HookObj {
    char unk00[0x80];
    HookVt *vt;                         /* 0x80 */
} HookObj;

typedef struct ListRec {
    HookObj *obj;
    int unk4, unk8;
} ListRec;                              /* 0xC */



__attribute__((section(".text.cHookList_callAll")))
void cHookList_callAll(char *self) {
    ListRec *rec = (ListRec *)(self + 0x22F4);
    int i;
    for (i = 16; i >= 0; i--, rec++) {
        HookObj *obj = rec->obj;
        if (obj != 0)
            obj->vt->pfn((char *)obj + obj->vt->delta);
    }
    *(unsigned char *)(self + 0x23BC) = 0;
    func_001415E8(self, 0);
}

/* Set the mark flag word of scroll mark `mark` (0 to 2): `lit` writes the
 * mark number into bits 11 up and sets bit 15; otherwise clear it and, for
 * marks 0 and 1, hide the line layer. */
typedef struct MarkObj {
    char unk000[0x480];
    int lineLayer;                      /* 0x480 */
    char unk484[0x3C];
    unsigned short markFlag;            /* 0x4C0 */
} MarkObj;



__attribute__((section(".text.MarkObj_setMarkFlag")))
void MarkObj_setMarkFlag(MarkObj *self, unsigned short mark, int lit) {
    if (mark < 3) {
        if (lit) {
            self->markFlag = (mark << 11) | 0x8000;
        } else {
            self->markFlag = 0;
            switch (mark) {
            case 0:
                displayScrollLayer(self->lineLayer, 0);
                break;
            case 1:
                displayScrollLayer(self->lineLayer, 0);
                break;
            }
        }
    }
}

/* Per-frame check of the 64-bit input word D_007474A0[0x34]: bit 29 puts the
 * object's mode (0x60) to 10; bit 21 plays sound 0x161 and resets the mode to -1. */
typedef struct ModeObj {
    char unk00[0x60];
    int mode;                           /* 0x60 */
} ModeObj;





#define INPUT_WORD(base)   (((long *)((char *)(base) + 0x1A0))[0])
#define INPUT_BIT_MODE     0x20000000
#define INPUT_BIT_SOUND    0x200000

__attribute__((section(".text.ModeObj_pollInputBits")))
void ModeObj_pollInputBits(ModeObj *self) {
    char *in = (char *)D_007474A0;
    if (INPUT_WORD(in) & INPUT_BIT_MODE)
        self->mode = 10;
    if (INPUT_WORD(in) & INPUT_BIT_SOUND) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x161, -1, -1, 0, 0);
        self->mode = -1;
    }
}

/* Restart the animation and refill the 13 entry pointers at 0xB0 from
 * cIDBase_getIDWork, then clear the two state bytes at 0x94/0x95. */
#define ENTRY_COUNT 13

typedef struct IdScreen {
    char unk00[0x1C];
    unsigned char started;              /* 0x1C */
    char unk1D[0x73];
    int unk90;                          /* 0x90 */
    unsigned char sel0;                 /* 0x94 */
    unsigned char sel1;                 /* 0x95 */
    char unk96[0x1A];
    void *ent[ENTRY_COUNT];             /* 0xB0 */
} IdScreen;




__attribute__((section(".text.IdScreen_refillEntries")))
void IdScreen_refillEntries(IdScreen *self) {
    unsigned short i = 0;
    self->unk90 = 0;
    cIDBase_restartAnim(self);
    self->started = 1;
    do {
        self->ent[i] = cIDBase_getIDWork(self, i);
        i = i + 1;
    } while (i < ENTRY_COUNT);
    self->sel0 = 0;
    self->sel1 = 0;
}
