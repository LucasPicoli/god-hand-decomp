/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/cEm00.h"
#include "godhand/Poker.h"
#include "godhand/CustomIDWork.h"

extern int ClearField5B4IfFlagUnset_1B76B0(void *self);
extern void sceVu0ApplyMatrix(void *dst, void *mtx, void *src);
extern void func_002A87E8(void *self, int arg);
extern void func_001B76D8(void *self);
extern void func_001DF528(void *p, int a1, int a2);
extern void cSnd_SetBgmState(void *snd, int state);
extern long D_00747640;
extern void CustomIDWork_ResetColorAnim(CustomIDWork *work);
extern void CustomIDWork_SetColorAnimNormal_2D68D8(CustomIDWork *work, int from, int to, int frames);
extern void CustomIDWork_SetColorAnimNormal_2D6898(CustomIDWork *work, int color, int frames);
extern void func_001E7470(void *self, int entry, int on);

#define OM_OFFSET_MODE  0x2F4           /* mode byte, read through the raw offset as retail does */
#define OM_MODE(s)      (*(unsigned char *)((s) + OM_OFFSET_MODE))

/* One pointer-to-member record, g++ 2.x layout: this adjust, vtable index (-1 for a plain function) and the vtable offset or function. */
typedef struct PhaseMemFn {
    short delta;
    short index;
    short vtOfs;
    short pad6;
} PhaseMemFn;

/* A cOmBase with a local-space offset and a world-space vector after the base record. */
typedef struct cOmOffsetObj {
    cOmBase base;
    char unk5E0[0x190];
    cVec localOffset;                   /* 0x770 offset in the object's own space */
    cVec worldOffset;                   /* 0x780 the same offset rotated into world space; [1] drops by 1 per tick */
} cOmOffsetObj;

extern PhaseMemFn D_003BDB78[];

/* Per-frame update: run the handler picked by the mode byte, rotate the
 * local offset by the orientation matrix into the world offset, lower its
 * height by 1 and run the shared post-update steps. */
__attribute__((section(".text.cOmOffsetObj_updateWorldOffset")))
void cOmOffsetObj_updateWorldOffset(cOmOffsetObj *self)
{
    char frame[0x20];
    char *s0 = (char *)self;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0)
        return;
    i8 = OM_MODE(s0) * 8;
    e = (char *)D_003BDB78 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)D_003BDB78 + i8 + 4);
    }
    f0 = D_003BDB78[OM_MODE(s0)].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    {
        float *m = self->base.mtx;
        float *v = (float *)(frame + 0x10);
        VU0_LQC2(4, &self->localOffset, 0);
        VU0_SQC2(4, frame, 0x10);
        sceVu0ApplyMatrix(v, m, v);
        VU0_LQC2(4, v, 0);
    }
    VU0_SQC2(4, frame, 0);
    cVec_copy3(&self->worldOffset, (cVec *)frame);
    self->worldOffset.y = self->worldOffset.y - 1.0f;
    func_002A87E8(self, 0);
    func_001B76D8(self);
}

#define POKER_OFFSET_UI     0x25B0    /* the table's UI record is not typed yet */
#define POKER_UI(self)      ((char *)(self) + POKER_OFFSET_UI)
#define POKER_WAIT_A        0x3C      /* frames before the first UI animation */
#define POKER_WAIT_B        0x78
#define POKER_WAIT_C        0x1E
#define POKER_PAD_SKIP      0x30000000  /* pad bits that skip the wait */
#define POKER_STATE_NEXT    0xB

/* Counts the timer down; nonzero once it has reached 0. */
static __inline__ unsigned char Poker_timerDone(Poker *self)
{
    if (self->timer == 0)
        return 1;
    self->timer--;
    return 0;
}

/* Intro of the table: phase 0 waits 60 frames, phase 1 starts the UI
 * animation and waits 120, phase 2 waits (or a pad press skips) and starts
 * the second animation, phase 3 waits then sets the BGM state and moves to
 * state 11. */
__attribute__((section(".text.Poker_updateIntro")))
void Poker_updateIntro(Poker *self)
{
    switch (self->phase) {
    case 0:
        self->timer = POKER_WAIT_A;
        self->phase = self->phase + 1;
        break;
    case 1:
        if (!Poker_timerDone(self))
            return;
        func_001DF528(POKER_UI(self), 1, 4);
        self->timer = POKER_WAIT_B;
        self->phase = self->phase + 1;
        break;
    case 2:
        if ((D_00747640 & POKER_PAD_SKIP) == 0) {
            if (!Poker_timerDone(self))
                return;
        }
        func_001DF528(POKER_UI(self), 1, 3);
        self->timer = POKER_WAIT_C;
        self->phase = self->phase + 1;
        break;
    case 3:
        if (Poker_timerDone(self)) {
            cSnd_SetBgmState(&D_005FEE00, 0);
            self->phase = 0;
            self->state = POKER_STATE_NEXT;
        }
        break;
    }
}

#define SCREEN_WORK(self)   ((CustomIDWork *)((char *)(self) + 0xCC))   /* the owner is not typed yet */
#define SCREEN_FADE_FRAMES  2
#define SCREEN_ENTRY        1

/* Sets the colour of the screen's element: mode 0 clears it, mode 1 fades
 * between two grey tints, mode 2 sets one tint. The colour words are built
 * byte by byte from uninitialised ints, as retail does. */
__attribute__((section(".text.CustomIDOwner_setColorMode")))
void CustomIDOwner_setColorMode(void *self, unsigned char mode)
{
    switch (mode) {
    case 0:
        CustomIDWork_ResetColorAnim(SCREEN_WORK(self));
        func_001E7470(self, SCREEN_ENTRY, 0);
        break;
    case 1: {
        int b;
        int c;
        int from = ((((((c & ~0xFF0000) | 0x800000) & ~0xFF00) | 0x8000) & ~0xFF) | 0x80) & 0xFFFFFF;
        int to = (((((((b & ~0xFF0000) | 0x800000) & ~0xFF00) | 0x8000) & ~0xFF) | 0x80) & 0xFFFFFF) | 0x48000000;
        CustomIDWork_SetColorAnimNormal_2D68D8(SCREEN_WORK(self), from, to, SCREEN_FADE_FRAMES);
        func_001E7470(self, SCREEN_ENTRY, 1);
        break;
    }
    case 2: {
        int d;
        int color = ((((((d & ~0xFF0000) | 0x800000) & ~0xFF00) | 0x8000) & ~0xFF) | 0x80) & 0xFFFFFF;
        CustomIDWork_SetColorAnimNormal_2D6898(SCREEN_WORK(self), color, SCREEN_FADE_FRAMES);
        func_001E7470(self, SCREEN_ENTRY, 1);
        break;
    }
    }
}
