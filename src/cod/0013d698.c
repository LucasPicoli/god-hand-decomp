/* sn-2.95.3-136 matched TU. */

#include "godhand/cIDBase.h"
#include "godhand/cOmBase.h"
#include "godhand/Slot2.h"
#include "godhand/cEmSetParam.h"
#include "godhand/cEmManage.h"

extern void cIDBase_move(void *self);
extern int ClearField5B4IfFlagUnset_1B76B0(void *self);
extern void func_002A87E8(void *self, int arg);
extern void func_001B76D8(void *self);
extern void func_001E4520(Slot2 *self, int a1);
extern void func_001E4200(Slot2 *self, int a1, int a2, int a3);
extern void func_001E3E40(Slot2 *self, unsigned short a1, int a2, int a3);
extern void func_001E3928(Slot2 *self, int a1, int a2);
extern void func_001E3A98(Slot2 *self, int a1, int a2);
extern void func_001E3C08(Slot2 *self, int a1, int a2);
extern float func_002AC650(cIDBaseObj *obj, int frame, int recNo, int a3);
extern int func_002AC6E0(cIDBaseObj *obj, float t, float *x, float *y, cIDBaseEnt *ent);
extern int func_002AC878(cIDBaseObj *obj, float t, float *x, float *y, cIDBaseEnt *ent);

/* Step 0 of the icon screen: grow the main entry's scale and spin each frame; when the scale reaches 1.0, snap both to
 * the source record's values, show the three child entries again, go to step 1 and move the display. */


#define ICON_SCALE_STEP  0.03f
#define ICON_SPIN_STEP   0.0207f
#define ICON_SCALE_DONE  1.0f
#define ICON_ENT_MAIN    4              /* ent[] slot of the animated entry */
#define ICON_ENT_A       1
#define ICON_ENT_B       2
#define ICON_ENT_C       7

typedef struct IconScreen {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x4A];
    unsigned short step;                /* 0x92 */
    cIDBaseEnt *ent[11];                /* 0x94 entries from getIDWork */
} IconScreen;

extern void func_002AC9B8(IconScreen *self, cIDBaseEnt *ent, int arg);   /* refresh one entry */


__attribute__((section(".text.func_0013D698")))
void func_0013D698(IconScreen *self) {
    self->ent[ICON_ENT_MAIN]->sclX += ICON_SCALE_STEP;
    self->ent[ICON_ENT_MAIN]->f70[2] += ICON_SPIN_STEP;
    if (self->ent[ICON_ENT_MAIN]->sclX >= ICON_SCALE_DONE) {
        self->ent[ICON_ENT_MAIN]->sclX = self->ent[ICON_ENT_MAIN]->src->sclX;
        self->ent[ICON_ENT_MAIN]->f70[2] = self->ent[ICON_ENT_MAIN]->src->f40[2];
        self->base.playing = 1;
        self->ent[ICON_ENT_C]->flags &= ~IDENT_FLAG_NO_DRAW;
        func_002AC9B8(self, self->ent[ICON_ENT_C], 0);
        self->ent[ICON_ENT_A]->flags &= ~IDENT_FLAG_NO_DRAW;
        func_002AC9B8(self, self->ent[ICON_ENT_A], 0);
        self->ent[ICON_ENT_B]->flags &= ~IDENT_FLAG_NO_DRAW;
        func_002AC9B8(self, self->ent[ICON_ENT_B], 0);
        self->step = self->step + 1;
        cIDBase_move(self);
    }
}

/* Mode tick: if the object is active, count the 0x602 timer down, call the handler the current mode's table entry names
 * (a method table entry, or an inline handler for a negative index), then run the two shared post steps. */


#define MODE_NUM  4

/* One mode entry: this-adjust, method index (or negative: handler is inline), table offset in the object. */
typedef struct ModeEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler inline at +4 */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} ModeEnt;

typedef struct { char b[0x20]; } ModeTbl;
extern ModeTbl D_00423318;              /* the four entries */





__attribute__((section(".text.func_00187FE8")))
void func_00187FE8(cOmBase *self) {
    ModeEnt tbl[MODE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    if (*(short *)((char *)self + 0x602) != 0) {
        *(short *)((char *)self + 0x602) = *(unsigned short *)((char *)self + 0x602) - 1;
    }
    *(ModeTbl *)tbl = D_00423318;
    i8 = self->mode * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)self + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[self->mode].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)self + arg));
    func_002A87E8(self, 0);
    func_001B76D8(self);
}

/* Slot2 intro stage: phase 0 resets the lamp state, phase 1 shows the panels and starts a 60 frame wait, phase 2 hides
 * them when the wait is over, phase 3 returns to the first state. */


#define SLOT2_INTRO_WAIT  0x3C
#define SLOT2_END_NOLAMP  0x100         /* endFlag bit cleared by phase 0 */
#define SLOT2_LAMP_STATE_OFFSET   0x490 /* int the header leaves in customId */
#define SLOT2_LAMP_SEL_OFFSET     0x494 /* unsigned short, same */
#define SLOT2_LAMP_FRAME_OFFSET   0x4C2 /* short */
#define SLOT2_FIELD(self, type, off)  (*(type *)((char *)(self) + (off)))








__attribute__((section(".text.func_001E2FD0")))
void func_001E2FD0(Slot2 *self)
{
    int done;

    switch (self->phase) {
    case 0:
        SLOT2_FIELD(self, int, SLOT2_LAMP_STATE_OFFSET) = 9;
        SLOT2_FIELD(self, short, SLOT2_LAMP_FRAME_OFFSET) = 0;
        self->endFlag = (int)self->endFlag & ~SLOT2_END_NOLAMP;
        func_001E4520(self, 0);
        self->phase = self->phase + 1;
        break;
    case 1:
        func_001E4200(self, SLOT2_FIELD(self, unsigned short, SLOT2_LAMP_SEL_OFFSET), 1, 1);
        func_001E3E40(self, SLOT2_FIELD(self, unsigned short, SLOT2_LAMP_SEL_OFFSET), 1, 1);
        self->timer = SLOT2_INTRO_WAIT;
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->timer != 0) {
            self->timer = self->timer - 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            func_001E3928(self, 0, 0);
            func_001E3A98(self, 0, 0);
            func_001E3C08(self, 0, 0);
            func_001E4200(self, SLOT2_FIELD(self, unsigned short, SLOT2_LAMP_SEL_OFFSET), 0, 0);
            func_001E3E40(self, SLOT2_FIELD(self, unsigned short, SLOT2_LAMP_SEL_OFFSET), 0, 0);
            self->phase = self->phase + 1;
        }
        break;
    case 3:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}

/* One frame of an entry's position animation: step the frame counter (looping or stopping at the record's last frame),
 * ask the path kind for the point at that time, and put the entry at the source position plus the point (centred on
 * the 512 by 448 screen). */


#define IDSRC_F_MOVE      0x1000000     /* source flag: the entry has a position animation */
#define IDSRC_F_LOOP      0x80000       /* source flag: the animation loops */
#define ENT_F_MOVE_DONE   0x2000        /* entry flag: the animation finished */
#define ENT_F_PAUSED      0x20          /* entry flag: hold the frame counter */
#define SCREEN_HALF_W     256.0f
#define SCREEN_HALF_H     224.0f

/* The source record seen as the position animation reads it. */
typedef struct IdMoveRec {
    short lastFrame;                    /* 0x0 last frame of this key span */
    char unk02[10];
} IdMoveRec;

typedef struct IdMoveSrc {
    char unk00[4];
    unsigned int flags;                 /* 0x04 */
    float posX;                         /* 0x08 */
    float posY;                         /* 0x0C */
    char unk10[0x4D];
    signed char noMove;                 /* 0x5D nonzero: no position animation */
    char unk5E[9];
    unsigned char pathKind;             /* 0x67 0: func_002AC6E0, 1: func_002AC878 */
    char unk68[4];
    short recNum;                       /* 0x6C */
    char unk6E[0xA];
    IdMoveRec rec[1];                   /* 0x78 */
} IdMoveSrc;

/* The entry past what cIDBase.h names: the animation frame counter. */
#define ENT_MOVE_FRAME(ent)  (*(unsigned short *)((char *)(ent) + 0xA2))





__attribute__((section(".text.func_002AC048")))
void func_002AC048(cIDBaseObj *obj, cIDBaseEnt *ent)
{
    IdMoveSrc *src;
    unsigned int flags;
    int m;
    int n;
    int lim;
    float t;
    int got;
    float out[2];
    unsigned long bits;

    src = (IdMoveSrc *)ent->src;
    flags = src->flags;
    if ((flags & IDSRC_F_MOVE) == 0) {
        return;
    }
    m = ent->flags;
    if (m & ENT_F_MOVE_DONE) {
        return;
    }
    if (src->noMove != 0) {
        return;
    }
    n = src->recNum;
    lim = src->rec[n - 1].lastFrame;
    if ((flags & IDSRC_F_LOOP) != 0) {
        if (lim < ENT_MOVE_FRAME(ent)) {
            *(short *)&ENT_MOVE_FRAME(ent) = 0;
        }
    } else {
        if (lim < ENT_MOVE_FRAME(ent)) {
            ent->flags = m | ENT_F_MOVE_DONE;
            return;
        }
    }
    t = func_002AC650(obj, *(short *)&ENT_MOVE_FRAME(ent), n, (int)ent->part[1]);
    got = 0;
    switch (src->pathKind) {
    case 0:
        got = func_002AC6E0(obj, t, &out[0], &out[1], ent);
        break;
    case 1:
        got = func_002AC878(obj, t, &out[0], &out[1], ent);
        break;
    }
    if (got != 0) {
        float dx = out[0] - SCREEN_HALF_W;
        float dy = out[1] - SCREEN_HALF_H;
        ent->posX = ((IdMoveSrc *)ent->src)->posX + dx;
        ent->posY = ((IdMoveSrc *)ent->src)->posY + dy;
    }
    bits = ent->flags;
    if (((bits >> 5) & 1) == 0) {
        ENT_MOVE_FRAME(ent) = ENT_MOVE_FRAME(ent) + 1;
    }
}

/* State 0 of the screen-corner panel: set three screen points, then rebuild the layout. */
typedef struct CornerPanel {
    char unk00[0xA4];
    unsigned char state;                /* 0xA4 switch index of func_002B16F0 */
    char unkA5;
    short x0;                           /* 0xA6 */
    short y0;                           /* 0xA8 */
    short x1;                           /* 0xAA */
    short y1;                           /* 0xAC */
    short x2;                           /* 0xAE */
    short y2;                           /* 0xB0 */
} CornerPanel;

extern void func_002B1C80(CornerPanel *self);

__attribute__((section(".text.func_002B17A8")))
void func_002B17A8(CornerPanel *self)
{
    self->x0 = 0x100;
    self->y0 = 0x182;
    self->x1 = 0x1E0;
    self->y1 = 0x88;
    self->x2 = 0x100;
    self->y2 = 0x182;
    func_002B1C80(self);
}

/* Give an enemy's current health to its room table entry as the entry's start health (1 if it is dead or negative). */



__attribute__((section(".text.func_002956A0")))
void func_002956A0(cEmSetParam *setParam, cEmActor *em)
{
    unsigned int no = em->entryNo;
    int vital;
    if (no < EM_SLOT_NUM) {
        vital = em->vital;
        if (vital > 0)
            func_002954D0(setParam, no, vital);
        else
            func_002954D0(setParam, no, 1);
    }
}
