/* sn-2.95.3-136 matched TU. */

#include "godhand/Slot2.h"
#include "godhand/cOmBase.h"
#include "godhand/cMessDrawFont.h"
#include "godhand/cMessCommon.h"

extern void displayScrollLayer(int id, int on);
extern void CustomIDWork_SetOffsetPosX(void *work, int x);
extern void CustomIDWork_SetMoveOffsetPosX(void *work, int from, int to, int frames);
extern void func_001DEE60(void *ui, int sub, int on);
extern int cOmBase_checkDamage(cOmBase *self, cDamageTake *take);
extern void func_002B0480(cMessDrawFont *self, float *frame);
extern unsigned short *func_002B0700(cMessDrawFont *self, unsigned short *text, float *frame, float *w, float *h);
extern int cMessCommon_getCodeSize(unsigned int code);
extern int cMessCommon_isPageEndCode(unsigned short code);

/* Blink counter of the mark lights: once armed (bit 15), count frames; after 8 frames flip the on/off bit (bit 14) every frame and show the layer set that matches. */


#define SLOT2_OFFSET_BLINK    0x4A4     /* blink word, not named in Slot2.h */
#define SLOT2_OFFSET_LAYER_A  0x430     /* layer ids, not named in Slot2.h */
#define SLOT2_OFFSET_LAYER_B  0x47C
#define SLOT2_OFFSET_LAYER_C  0x46C
#define SLOT2_OFFSET_LAYER_D  0x470
#define SLOT2_LAYER(self, off) (*(int *)((char *)(self) + (off)))
#define BLINK_ARMED    0x8000
#define BLINK_ON       0x4000
#define BLINK_COUNT    0x3FFF
#define BLINK_DELAY    8



__attribute__((section(".text.func_001E3B40")))
void func_001E3B40(Slot2 *self)
{
    unsigned short *blink = (unsigned short *)((char *)self + SLOT2_OFFSET_BLINK);
    unsigned int v = *blink;
    unsigned short w;
    if (v & BLINK_ARMED) {
        v = v + 1;
        *blink = v;
        if ((v & BLINK_COUNT) >= BLINK_DELAY) {
            w = (~v & BLINK_ON) | BLINK_ARMED;
            *blink = w;
            if (w & BLINK_ON) {
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_A), 1);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_B), 1);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_C), 1);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_D), 0);
            } else {
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_A), 0);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_B), 0);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_C), 0);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_D), 1);
            }
        }
    }
}

/* Phase tick: pick the handler for the phase byte (0 or 1) from a table of two pointer-to-member records and call it on the object. A phase of 2 or more is reset to 0 first. */
#define OM_OFFSET_PHASE  0x2F5          /* phase byte, read through the raw offset as retail does */
#define OM_PHASE(s)      (*(unsigned char *)((s) + OM_OFFSET_PHASE))

/* One pointer-to-member record, g++ 2.x layout: this adjust, vtable index (-1 for a plain function) and the function or the vtable offset. */
typedef struct PhaseMemFn {
    short delta;                        /* 0x0 added to the object pointer */
    short index;                        /* 0x2 vtable slot, -1 when 0x4 holds a plain function */
    short vtOfs;                        /* 0x4 offset of the vtable pointer in the object */
    short pad6;
} PhaseMemFn;

typedef struct { char b[0x10]; } PhaseTbl;

extern PhaseTbl D_00448768;

__attribute__((section(".text.func_00282D70")))
void func_00282D70(char *s0)
{
    PhaseMemFn tbl[2];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(PhaseTbl *)tbl = D_00448768;
    if (OM_PHASE(s0) >= 2)
        OM_PHASE(s0) = 0;
    i8 = OM_PHASE(s0) * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[OM_PHASE(s0)].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

/* Slide the poker table's side panel: 0 snaps it off screen, 1 snaps it on, 2 slides it off, 3 slides it on (10 frames); the two sub panels are shown for modes 1 and 2. */

#define POKERUI_OFFSET_PANEL   0x158    /* CustomIDWork of the panel, offset in the ui object */
#define POKERUI_PANEL_OFF_X    (-0x12C) /* x offset of the panel when off screen */
#define POKERUI_SLIDE_FRAMES   10
#define POKERUI_SUB_A          2
#define POKERUI_SUB_B          3





__attribute__((section(".text.func_001DF198")))
void func_001DF198(void *ui, int mode)
{
    char *s0 = (char *)ui;
    switch (mode & 0xFF) {
    default:
    case 0:
        CustomIDWork_SetOffsetPosX(s0 + POKERUI_OFFSET_PANEL, POKERUI_PANEL_OFF_X);
        func_001DEE60(s0, POKERUI_SUB_A, 0);
        func_001DEE60(s0, POKERUI_SUB_B, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosX(s0 + POKERUI_OFFSET_PANEL, 0);
        func_001DEE60(s0, POKERUI_SUB_A, 0);
        func_001DEE60(s0, POKERUI_SUB_B, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosX(s0 + POKERUI_OFFSET_PANEL, POKERUI_PANEL_OFF_X, 0, POKERUI_SLIDE_FRAMES);
        func_001DEE60(s0, POKERUI_SUB_A, 0);
        func_001DEE60(s0, POKERUI_SUB_B, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosX(s0 + POKERUI_OFFSET_PANEL, 0, POKERUI_PANEL_OFF_X, POKERUI_SLIDE_FRAMES);
        break;
    }
}

/* Per-frame hit check of an object with a hit record and a life counter: when a hit lands, take its power off the counter and go to state 2 once the counter drops below zero (remembering which record it was), otherwise run the hurt reaction. Then update and finish the frame. */


#define OMHIT_REC_NUM     1
#define OMHIT_STATE_DEAD  2
#define OMHIT_SHAKE       2.5f

typedef struct cOmLifeCounter {
    cOmBase base;
    char unk5E0[0x20];
    cDamageTake *take[OMHIT_REC_NUM];   /* 0x600 hit records */
    char unk604[0xD98 - 0x604];
    unsigned short life[OMHIT_REC_NUM]; /* 0xD98 life left per record */
    unsigned char lastHit;              /* 0xD9A record that killed it */
} cOmLifeCounter;


extern void func_001731B8(cOmLifeCounter *self);
extern void func_001B7EE0(cOmLifeCounter *self, float amount);
extern void func_00173258(cOmLifeCounter *self);

__attribute__((section(".text.func_00172490")))
void func_00172490(cOmLifeCounter *self)
{
    int i;
    for (i = 0; i < OMHIT_REC_NUM; i++) {
        if (cOmBase_checkDamage(&self->base, self->take[i]) == 1) {
            int life = self->life[i] - self->take[i]->power;
            self->life[i] = life;
            if ((short)life < 0) {
                self->base.mode = OMHIT_STATE_DEAD;
                self->base.phase = 0;
                self->base.flags0 = self->base.flags0 | COMBASE_F0_ACTIVE;
                self->base.step = 0;
                self->base.stepArg = 0;
                self->lastHit = i;
            } else {
                func_001731B8(self);
            }
        }
    }
    func_001B7EE0(self, OMHIT_SHAKE);
    func_00173258(self);
}

/* Measure one page of a message: lay out each code with func_002B0700, keep the widest line in *maxW and add every line height (plus the line spacing between lines) to *sumH, until a page end code. */








__attribute__((section(".text.func_002B0610")))
void func_002B0610(cMessDrawFont *self, unsigned short *text, float *maxW, float *sumH)
{
    float frame[4];                     /* sp+0x00 layout state */
    float w;                            /* sp+0x10 */
    float h;                            /* sp+0x14 */

    *maxW = 0;
    *sumH = 0;
    func_002B0480(self, frame);
    while (text = func_002B0700(self, text, frame, &w, &h),
           (*maxW < w ? (*maxW = w, 0) : 0),
           *sumH += h,
           cMessCommon_isPageEndCode(*text) == 0) {
        *sumH += self->unk2C[1] * self->zoomY;
        text += cMessCommon_getCodeSize(*text);
    }
}
