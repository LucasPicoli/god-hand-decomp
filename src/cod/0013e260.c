/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"

extern float fRand1_1(void);
extern void func_001DEE60(void *ui, int sub, int on);
extern int D_00428840;
extern char D_00574380[];
extern void ClearAndResetFields_1FE278(void *pool, void *handle);
extern void SetField214PtrThenInit_1B6F38(void *self, int flag);
extern char D_00754C80[];
extern void func_0031A600(void *queue, int kind, int id, void *packet);
extern void cIDBase_trans(void *rec);
extern char D_003BDE50[];

#define OMSHAKE_JITTER  0.015f

typedef struct cOmShakeHigh {
    cOmBase base;
    char unk5E0[0x30];
    short timer;                        /* 0x610 frames of shake left */
    char unk612[2];
    float restY;                        /* 0x614 height to return to */
} cOmShakeHigh;

/* Shake the object's height: count the timer down and jitter its y by a small random amount, then restore the rest height when it runs out. */
__attribute__((section(".text.cOmShake_updateHeight")))
void cOmShake_updateHeight(cOmShakeHigh *self)
{
    if (self->timer > 0) {
        self->timer--;
        if (self->timer != 0)
            self->base.pos->y = self->restY + fRand1_1() * OMSHAKE_JITTER;
        else
            self->base.pos->y = self->restY;
    }
}

/* Show or hide sub-elements 6 to 10 of a UI record. */
__attribute__((section(".text.UiRecord_setDispSubs6to10")))
void UiRecord_setDispSubs6to10(void *ui, int on) {
    func_001DEE60(ui, 6, on);
    func_001DEE60(ui, 7, on);
    func_001DEE60(ui, 8, on);
    func_001DEE60(ui, 9, on);
    func_001DEE60(ui, 10, on);
}

/* A game object that owns one resource handle and two child objects. */
typedef struct cKidOwner {
    cGameObj base;
    char unk5AC[0x600 - sizeof(cGameObj)];
    void *handle;                       /* 0x600 resource released with the object */
    cGameObj *kidA;                     /* 0x604 child object, told to end (mode 1) */
    cGameObj *kidB;                     /* 0x608 second child object */
} cKidOwner;






#define KID_MODE_END 1

/* Destructor: release the handle, send both children to mode 1, run the base destructor. */
__attribute__((section(".text.cKidOwner_destruct")))
void cKidOwner_destruct(cKidOwner *self, int flag) {
    self->base.vt = (cGameObjVt *)&D_00428840;
    if (self->handle != 0) {
        ClearAndResetFields_1FE278(D_00574380, self->handle);
        self->handle = 0;
    }
    if (self->kidA != 0) {
        self->kidA->mode = KID_MODE_END;
    }
    if (self->kidB != 0) {
        self->kidB->mode = KID_MODE_END;
    }
    SetField214PtrThenInit_1B6F38(self, flag);
}

#define DMA_TAG_ID_END   0x70000000     /* DMA tag id 7 (end), the low 16 bits hold the quadword count */
#define VIF_FLUSH        0x11000000     /* VIF command FLUSH */
#define VIF_DIRECT       0x50000000     /* VIF command DIRECT, low 16 bits hold the quadword count */
#define DMA_ADDR_MASK    0x0FFFFFFF

/* Close a GIF packet: its end pointer lives at +0x10000. Fill the DMA tag and VIF words at the head with the payload size, then queue the packet. */
__attribute__((section(".text.GifPacket_closeAndQueue")))
void GifPacket_closeAndQueue(char *pkt) {
    unsigned int end = *(unsigned int *)(pkt + 0x10000) & DMA_ADDR_MASK;
    unsigned int qwc = ((end - (unsigned int)pkt) >> 4) - 1;
    char *vif = pkt + 8;

    *(unsigned long *)pkt = (unsigned int)(qwc | DMA_TAG_ID_END);
    *(int *)vif = VIF_FLUSH;
    *(int *)(vif + 4) = 0;
    if (qwc != 0) {
        *(int *)(vif + 4) = qwc | VIF_DIRECT;
    }
    func_0031A600(D_00754C80, 4, 4, pkt);
}

#define MARKER_NUM   8
#define MARKER_NONE  (-1)               /* slot unused */
#define MARKER_LIFE  0x24               /* ids from here on are released after one draw */

/* Eight draw slots: a display record (0x50 bytes each) and a marker id per slot. */
typedef struct MarkerSet {
    char unk00[0x90];
    char rec[MARKER_NUM][0x50];         /* 0x90 display records */
    char unk310[0x33C - 0x310];
    signed char id[MARKER_NUM];         /* 0x33C marker id per slot, MARKER_NONE if unused */
} MarkerSet;



/* Draw every used slot; a slot whose id is MARKER_LIFE or more is freed after drawing. */
__attribute__((section(".text.func_0013E260")))
void func_0013E260(MarkerSet *self) {
    unsigned short i;
    for (i = 0; i < MARKER_NUM; i++) {
        if (self->id[i] != MARKER_NONE) {
            cIDBase_trans(self->rec[i]);
            if (self->id[i] >= MARKER_LIFE) {
                self->id[i] = MARKER_NONE;
            }
        }
    }
}

/* Phase dispatch table rows are 8 bytes: this adjust (short), slot (short), then either the
 * offset of a function table in the object (short) or a function address (int, slot < 0).
 * A typed PhaseRow struct costs 9 words, so the raw offsets stay (same as the sibling rows). */
#define PHASE_OFFSET      0x2F5         /* row number, a byte of the object */
#define ROW_ADJUST        0
#define ROW_SLOT          2
#define ROW_TBL_OFS       4
#define ROW_FN            4

/* Call the function of the dispatch row selected by the phase byte, with this adjusted by the row and by the table entry. */
__attribute__((section(".text.PhaseDispatch_callRow")))
void PhaseDispatch_callRow(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    i8 = *(unsigned char *)(s0 + PHASE_OFFSET) * 8;
    e = D_003BDE50 + i8;
    type = *(short *)(e + ROW_SLOT);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + ROW_TBL_OFS));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BDE50 + i8 + ROW_FN);
    }
    f0 = *(short *)(D_003BDE50 + *(unsigned char *)(s0 + PHASE_OFFSET) * 8 + ROW_ADJUST);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}
