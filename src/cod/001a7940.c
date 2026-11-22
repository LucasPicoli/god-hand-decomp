/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/cPlCamera.h"
#include "godhand/cEm00.h"
#include "godhand/globals.h"

extern void StoreVecFromFieldB0_2B6160(cVec *dst, void *obj);
extern void func_002E28F0(void *obj, float y);
extern void func_002A87E8(void *obj, int arg);
extern void CustomIDWork_SetOffsetPosX(void *work, int x);
extern void CustomIDWork_SetMoveOffsetPosX(void *work, int from, int to, int frames);
extern void SetFlagOnEntries7C_1D51B8(void *self, int entry, int on);
extern void UpdateObjByIndexedOp_2FBE50(void *slot);

/* sn-2.95.3-136 */






/* Drop test below the object: cast a line from 1 unit above its position to 11 units below it, and when it hits, hand the hit height to func_002E28F0. */
#define DROP_UP     1.0f
#define DROP_DOWN   11.0f

/* The frame holds ChkLine's 0x30 bytes of outgoing arguments first; the vectors sit above them. */
#define FRAME ((char *)&pos - 0x30)

extern int ChkLine(void *a0, void *a1, void *a2, void *a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

__attribute__((section(".text.cOmBase_dropTestB")))
void cOmBase_dropTestB(cOmBase *self)
{
    cVec pos;                           /* sp+0x30 object position */
    cVec from;                          /* sp+0x40 */
    cVec to;                            /* sp+0x50 */
    cVec hit;                           /* sp+0x60 */
    cVec normal;                        /* sp+0x70 */

    StoreVecFromFieldB0_2B6160(&pos, self);
    VU0_LQC2(4, &pos, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_LQC2(4, &pos, 0);
    VU0_SQC2(4, FRAME, 0x50);
    VU0_SQC2_VF0(FRAME, 0x60);
    VU0_SQC2_VF0(FRAME, 0x70);
    from.y += DROP_UP;
    to.y -= DROP_DOWN;
    if (ChkLine(&from, &to, &hit, &normal, 2, 0, 0, 0, 0, 0, 0, 0, 1) != 0)
        func_002E28F0(self, hit.y);
}

/* sn-2.95.3-136 */



/* Tick: dispatch the current action: pick the table entry for state byte +0x2F5 (reset to 0 when out of range) and call its handler, then sync. */
__attribute__((section(".text.ActionTable_tickDispatch")))
void ActionTable_tickDispatch(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 0xD) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003C03F8 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003C03F8 + i8 + 4);
    }
    f0 = *(short *)(D_003C03F8 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
}

/* sn-2.95.3-136 */




/* Slide a side panel: mode 1 shows it in place, 2 scrolls it out, 3 scrolls it in, anything else hides it; then flag the display entries. The gotos reproduce retail's block order. */
#define PANEL_WORK            0x3C4     /* CustomIDWork of the panel inside the display entries */
#define PANEL_X_HIDDEN        (-0x140)
#define PANEL_SLIDE_FRAMES    0xA

typedef struct PanelHost {
    char unk00[4];
} PanelHost;

__attribute__((section(".text.PanelHost_slideSidePanel")))
void PanelHost_slideSidePanel(PanelHost *self, unsigned short mode)
{
    int m = mode;
    if (m == 1) {
        goto slideIn;
    }
    if (m < 2) {
        goto hidden;
    }
    if (m == 2) {
        goto scrollOut;
    }
    if (m == 3) {
        goto scrollIn;
    }
hidden:
    CustomIDWork_SetOffsetPosX((char *)self + PANEL_WORK, PANEL_X_HIDDEN);
    goto done;
slideIn:
    CustomIDWork_SetOffsetPosX((char *)self + PANEL_WORK, 0);
    goto done;
scrollOut:
    CustomIDWork_SetMoveOffsetPosX((char *)self + PANEL_WORK, PANEL_X_HIDDEN, 0, PANEL_SLIDE_FRAMES);
    goto done;
scrollIn:
    CustomIDWork_SetMoveOffsetPosX((char *)self + PANEL_WORK, 0, PANEL_X_HIDDEN, PANEL_SLIDE_FRAMES);
done:
    SetFlagOnEntries7C_1D51B8(self, 7, 0);
    SetFlagOnEntries7C_1D51B8(self, 8, m != 0);
}

/* sn-2.95.3-136 */



typedef struct { char b[0x10]; } PmfTbl;

/* Call the routine for the current phase. The table is copied to the
 * stack and the pointer to member is decoded by hand, as retail does. */
__attribute__((section(".text.cOmBase_callPhaseRoutine")))
void cOmBase_callPhaseRoutine(cOmBase *self) {
    char frame[0x10];
    char *s2 = (char *)self;
    cPlCamPmf *pm;
    cPlCamVtEnt *vt;
    void *fn;
    long ve;
    int ix, off8;
    char *q4;
    int dl;
    int *new_var;
    cPlCamPmf *pm3;

    *(PmfTbl *)frame = *(PmfTbl *)D_004275A0;
    pm = (cPlCamPmf *)frame + self->phase;
    ix = pm->index;
    if (ix >= 0) {
        vt = *(cPlCamVtEnt **)(s2 + pm->u.vo);
        ve = *(long *)((char *)vt + (ix - 1) * 8);
        fn = (void *)(int)(ve >> 32);
    } else {
        q4 = frame + 4;
        off8 = self->phase * 8;
        fn = *(void **)(q4 + off8);
    }
    dl = (pm3 = (cPlCamPmf *)frame + self->phase)->delta;
    new_var = &dl;
    dl = (ix >= 0) ? (short)ve + (*new_var) : dl;
    ((void (*)(void *))fn)(s2 + dl);
}

/* sn-2.95.3-136 */


/* Phase tick: wrap the phase byte to 0..1, then call the handler the phase's table entry names. An entry with a
 * non-negative index takes the handler from a method table found through the object; a negative one holds it inline. */

#define PHASE_NUM  2

/* One phase entry: this-adjust, method index (or -1), table offset in the object, or the inline handler. */
typedef struct PhaseEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler is inline */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} PhaseEnt;

typedef struct { char b[0x10]; } PhaseTbl;
extern PhaseTbl D_00447D28;             /* the two entries */

__attribute__((section(".text.cEm00_tickPhaseDispatchB")))
void cEm00_tickPhaseDispatchB(cEm00 *self) {
    PhaseEnt tbl[PHASE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(PhaseTbl *)tbl = D_00447D28;
    if (self->phase >= PHASE_NUM)
        self->phase = 0;
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
}

/* sn-2.95.3-136 */

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: slot paused */
extern int D_0071B8C0[];                /* bit set: slot hidden */
extern unsigned char D_0061B7C0[];      /* the 0x400 effect slots, 0x400 bytes each */

#define ESP_SLOT_NUM     0x400
#define ESP_SLOT_SIZE    0x400
#define ESP_SLOT_FLAGS   0x104          /* offset of the slot's flag word */
#define ESP_SLOT_GROUP   0x23A          /* offset of the slot's group number (short) */
#define ESP_SLOT_SUBGRP  0x23C          /* offset of the slot's sub group number (unsigned short) */

/* Run the kill handler of every effect slot that is in use, neither paused nor hidden, and whose group number is group. */
__attribute__((section(".text.Esp_killByGroupNumber")))
void Esp_killByGroupNumber(int group) {
    unsigned char *p;
    int i;
    unsigned int bit;
    int w;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0) goto next;
        if ((D_0071B840[w] & bit) != 0) goto next;
        if ((D_0071B8C0[w] & bit) != 0) goto next;
        p = D_0061B7C0 + i * ESP_SLOT_SIZE;
        if (*(short *)(p + ESP_SLOT_GROUP) != group) goto next;
        UpdateObjByIndexedOp_2FBE50(p);
next: ;
    }
}
