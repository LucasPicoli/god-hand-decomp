/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cIDBase.h"
#include "godhand/cEm00.h"
#include "godhand/globals.h"

extern void displayScrollLayer(int layer, int show);
extern void Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(void *self);
extern void cIDManager_setIDData(void *mgr, int kind, int res);
extern void cIDBase_initialize(void *self, int kind, int arg);
extern void cIDBase_resetAnim(void *self);
extern void **D_003C2384;
extern void CustomIDWork_SetOffsetPosX(void *work, int x);
extern void CustomIDWork_SetMoveOffsetPosX(void *work, int from, int to, int frames);
extern void func_001DEE60(void *ui, int sub, int on);

/* Enemy constructor: base setup, method table, aim lock byte, zeroed vectors and the type name. */


#define EM_AIM_FREE       0xFF          /* aim.target: no target */

/* The aim block at 0x1530. */
typedef struct EnemyAim {
    char unk00[0x31];
    unsigned char target;               /* 0x31 */
} EnemyAim;

typedef struct EnemyRec {
    char unk000[0x214];
    const void *vt;                     /* 0x214 method table of the second base */
    char unk218[0x294];
    const char *name;                   /* 0x4AC type name string */
    char unk4B0[0x1080];
    EnemyAim aim;                       /* 0x1530 */
} EnemyRec;

extern const unsigned char D_00448E20[];    /* method table */
extern void *func_0028EB00(void *self);     /* enemy base constructor */

__attribute__((section(".text.EnemyBase_constructAimQuad")))
EnemyRec *EnemyBase_constructAimQuad(EnemyRec *self)
{
    EnemyAim *aim;
    func_0028EB00(self);
    self->vt = D_00448E20;
    aim = &self->aim;
    VU0_SQC2_VF0(self, 0x1540);
    aim->target = EM_AIM_FREE;
    VU0_SQC2_VF0(self, 0x1570);
    VU0_SQC2_VF0(self, 0x1580);
    VU0_SQC2_VF0(self, 0x1590);
    VU0_SQC2_VF0(self, 0x15E0);
    self->name = D_00448DB0;
    return self;
}

/* sn-2.95.3-136 */


/* The scroll-layer mark at 0x4C0 of the Slot2 object; the fields are not in Slot2.h yet. */
typedef struct Slot2Mark {
    char unk00[0x480];
    int markLayer;                      /* 0x480 layer shown for this mark */
    char unk484[0x4C0 - 0x484];
    unsigned short markFlag;            /* 0x4C0 bit 15 = start lit, bit 14 = on */
} Slot2Mark;

#define MARK_BLINK   0x8000     /* markFlag: start lit, counting */
#define MARK_ON      0x4000     /* markFlag: line shown */
#define MARK_COUNT   0x3FFF     /* markFlag: frames since the last flip */
#define MARK_PERIOD  8
#define MARK_KEEP    0x800      /* markFlag: bit kept across the flip */

/* Mark at 0x4C0, once a frame: while lit (bit 15), count 8 frames, then flip the shown bit (14) and update the layer. */
__attribute__((section(".text.Slot2_updateMarkAt4C0")))
void Slot2_updateMarkAt4C0(Slot2Mark *self) {
    unsigned int flag = self->markFlag;
    if (flag & MARK_BLINK) {
        unsigned short next;    /* short: the store keeps retail's andi 0xFFFF */
        flag = flag + 1;
        self->markFlag = flag;
        if ((flag & MARK_COUNT) >= MARK_PERIOD) {
            next = (~flag & MARK_ON) | (flag & MARK_KEEP) | MARK_BLINK;
            self->markFlag = next;
            if (next & MARK_ON) {
                displayScrollLayer(self->markLayer, 1);
            } else {
                displayScrollLayer(self->markLayer, 0);
            }
        }
    }
}

/* sn-2.95.3-136 */
extern void *func_003A52F0(void *d, int c, unsigned int n);   /* memset */
extern void *func_003A5148(void *d, const void *s, unsigned int n);   /* memcpy */

/* Read a 12 byte effect record: zeroed unless `valid` is 1, in which case it is copied from `src`. Returned by value. */
typedef struct MotionEffectData {
    int w[3];
} MotionEffectData;

__attribute__((section(".text.Motion_seq_readEffectData")))
MotionEffectData Motion_seq_readEffectData(const void *src, unsigned char valid)
{
    MotionEffectData r;
    func_003A52F0(&r, 0, sizeof(r));
    if (valid == 1)
        func_003A5148(&r, src, sizeof(r));
    return r;
}

/* sn-2.95.3-136 */











/* Constructor of the 9-part display object: base setup, then (when its data table matches) the ID data and initial animation, and the 15 display works. */
#define IDOBJ_WORK_NUM  0xF
#define IDOBJ_KIND      9

typedef struct IdDispObj {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[8];
    int resHandle;                      /* 0x50 */
    char unk54[6];
    unsigned char b5A;                  /* 0x5A */
    unsigned char b5B;                  /* 0x5B */
    unsigned char b5C;                  /* 0x5C */
    unsigned char b5D;                  /* 0x5D */
    char unk5E[2];
    int state;                          /* 0x60 */
    char unk64[0x1C];
    void *work[IDOBJ_WORK_NUM];         /* 0x80 */
    unsigned char bBC;                  /* 0xBC */
} IdDispObj;

__attribute__((section(".text.IdDispObj_constructKind9")))
void IdDispObj_constructKind9(IdDispObj *self)
{
    unsigned short i;
    Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(self);
    if (func_00161500(self, D_0041F1F0) != 0) {
        cIDManager_setIDData(*D_003C2384, IDOBJ_KIND, self->resHandle);
        cIDBase_initialize(self, IDOBJ_KIND, 0);
        cIDBase_resetAnim(self);
        self->base.playing = 1;
        self->state = 6;
        self->b5A = 0;
        self->b5B = 0;
        self->b5C = 0;
        self->b5D = 0;
    }
    for (i = 0; i < IDOBJ_WORK_NUM; i++) {
        self->work[i] = cIDBase_getIDWork(&self->base, i);
    }
    self->bBC = 0;
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
extern PhaseTbl D_00448578;             /* the two entries */

__attribute__((section(".text.cEm00_tickPhaseDispatchC")))
void cEm00_tickPhaseDispatchC(cEm00 *self) {
    PhaseEnt tbl[PHASE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(PhaseTbl *)tbl = D_00448578;
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




/* Slide a side panel: 0 snaps it off screen, 1 snaps it on, 2 slides it off, 3 slides it on (10 frames); the two arrow sub panels are shown for modes 1 and 2. */

#define PANEL_OFFSET_WORK   0x250   /* CustomIDWork of the panel, offset in the ui object */
#define PANEL_OFF_X         0x12C   /* x offset of the panel when off screen */
#define PANEL_SLIDE_FRAMES  10
#define PANEL_SUB_A         4
#define PANEL_SUB_B         5

__attribute__((section(".text.Panel_slideSidePanelArrows")))
void Panel_slideSidePanelArrows(void *ui, int mode)
{
    char *s0 = (char *)ui;
    switch (mode & 0xFF) {
    default:
    case 0:
        CustomIDWork_SetOffsetPosX(s0 + PANEL_OFFSET_WORK, PANEL_OFF_X);
        func_001DEE60(s0, PANEL_SUB_A, 0);
        func_001DEE60(s0, PANEL_SUB_B, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosX(s0 + PANEL_OFFSET_WORK, 0);
        func_001DEE60(s0, PANEL_SUB_A, 0);
        func_001DEE60(s0, PANEL_SUB_B, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosX(s0 + PANEL_OFFSET_WORK, PANEL_OFF_X, 0, PANEL_SLIDE_FRAMES);
        func_001DEE60(s0, PANEL_SUB_A, 0);
        func_001DEE60(s0, PANEL_SUB_B, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosX(s0 + PANEL_OFFSET_WORK, 0, PANEL_OFF_X, PANEL_SLIDE_FRAMES);
        break;
    }
}
