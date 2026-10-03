/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cTaskManager.h"
#include "godhand/cTaskWork.h"
#include "godhand/cOmBase.h"

extern char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *snd, int bus, int no, void *obj, int a4, int a5, int a6, int a7);
extern char D_00586AA5;
extern void cEmWrap_StartAction(void *act);
extern float frand(float lo, float hi);

/* Start the 6 frame stagger: remember the enemy's scale height, then play the two start sounds. */


#define EM_STAGGER_FRAMES   6
#define EM_SE_STAGGER_A     0x2D        /* sound 2/0x2D */
#define EM_SE_STAGGER_B     0xA         /* sound 0/0xA */

/* The enemy record with the stagger fields at 0xDA0, past what cEm00.h names. */
typedef struct EmStagger {
    char unk000[0x214];
    cEm00Vt *vt;                        /* 0x214 */
    char unk218[0xB88];
    short staggerTime;                  /* 0xDA0 frames left */
    char unkDA2[2];
    float staggerHeight;                /* 0xDA4 scale y when the stagger began */
} EmStagger;




__attribute__((section(".text.cEm00_startStagger")))
void cEm00_startStagger(EmStagger *self) {
    self->staggerHeight = CEM00_VCALL0(self, getScale)->y;
    self->staggerTime = EM_STAGGER_FRAMES;
    cSnd_SeCall_2CBA48(D_005FEE00, 2, EM_SE_STAGGER_A, self, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(D_005FEE00, 0, EM_SE_STAGGER_B, self, 0, 0, 0, 0);
}

/* Run the handler for the unit's kind (flags bits 1-2: 0, 2 or 4). Mode 1 only runs for a unit with bit 0 set. */
#define HITNODE_ACTIVE     0x1      /* flags bit 0 */
#define HITNODE_KIND_MASK  0x6      /* flags bits 1-2 */
#define HITNODE_MODE_LIVE  1

typedef struct HitNode {
    char unk00[0x29];
    unsigned char flags;                /* 0x29 */
} HitNode;

extern int func_002C0B38(HitNode *node, void *arg);   /* kind 0 */
extern int func_002C0C28(HitNode *node, void *arg);   /* kind 2 */
extern int func_002C0CB0(HitNode *node, void *arg);   /* kind 4 */

__attribute__((section(".text.HitNode_dispatchByKind")))
int HitNode_dispatchByKind(HitNode *node, void *arg, int mode) {
    int kind;
    if (mode == HITNODE_MODE_LIVE) {
        if (((node->flags ^ HITNODE_ACTIVE) & 1) != 0) {
            return 0;
        }
    }
    kind = node->flags & HITNODE_KIND_MASK;
    switch (kind) {
    case 0:
        return func_002C0B38(node, arg);
    case 2:
        return func_002C0C28(node, arg);
    case 4:
        return func_002C0CB0(node, arg);
    }
    return 0;
}

/* Coliseum wave spawner: phase 0 starts the first two actions, phase 1 waits for the second enemy group and starts three more. */


#define COLI_ACT_SIZE  0x10             /* one action record: byte 0 is the action number */




__attribute__((section(".text.ColiseumBattle_spawnWave")))
void ColiseumBattle_spawnWave(ColiseumBattle *self) {
    char act[4][COLI_ACT_SIZE];
    switch (self->phase) {
    case 0:
        D_00586AA5 = 0;
        act[0][0] = 0;
        cEmWrap_StartAction(act[0]);
        act[1][0] = 1;
        cEmWrap_StartAction(act[1]);
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->unkB88 >= 2) {
            act[0][0] = 2;
            cEmWrap_StartAction(act[0]);
            act[2][0] = 3;
            cEmWrap_StartAction(act[2]);
            act[3][0] = 4;
            cEmWrap_StartAction(act[3]);
            self->phase = self->phase + 1;
        }
        break;
    }
}

/* Visit every task record: make it the current one and run the step for each whose attr bits cover the manager's flags. */



#define TASKMGR_NUM_OFFSET  0xC         /* an unsigned short the header leaves in unk0C */
#define TASKMGR_NUM(self)   (*(unsigned short *)((char *)(self) + TASKMGR_NUM_OFFSET))

extern void func_002D57C8(cTaskWork *work);     /* run one task's step */

__attribute__((section(".text.cTaskManager_runAllMatching")))
void cTaskManager_runAllMatching(cTaskManager *self) {
    unsigned int i;
    int off;
    if (TASKMGR_NUM(self) != 0) {
        i = 0;
        off = 0;
        do {
            cTaskWork *work = (cTaskWork *)(self->works + off);
            long flags = (unsigned int)self->flags;
            long need;
            long attr;
            self->curNo = i;
            need = flags & 1;
            self->cur = work;
            if (need != 0) {
                if ((work->attr & 1) == 0) goto next;
            }
            need = (flags >> 1) & 1;
            if (need != 0) {
                attr = work->attr;
                if (((attr >> 1) & 1) == 0) goto next;
            }
            func_002D57C8(work);
        next:
            i++;
            off += TASKMGR_WORK_SIZE;
        } while (i < TASKMGR_NUM(self));
    }
    self->cur = 0;
    self->curNo = TASKMGR_NONE;
}

/* Coliseum result confetti: throw 20 pieces (object 0x380) from random spots in a 20 by 20 square, each with a random spin. */


#define CONFETTI_NUM    20
#define CONFETTI_OBJ    0x380
#define CONFETTI_SPREAD 10.0f           /* half the square */
#define CONFETTI_SPIN   3.14f           /* spin range is plus or minus this */


extern char *func_001F0498(void *owner, int obj, cVec *pos, float angle);     /* create one piece */

__attribute__((section(".text.ColiseumBattle_throwConfetti")))
void ColiseumBattle_throwConfetti(void *self) {
    int i;
    for (i = CONFETTI_NUM - 1; i >= 0; i--) {
        cVec pos;
        float x = frand(-CONFETTI_SPREAD, CONFETTI_SPREAD);
        float z = frand(-CONFETTI_SPREAD, CONFETTI_SPREAD);
        pos.x = x;
        pos.y = 0.0f;
        pos.z = z;
        pos.w = 1.0f;
        func_001F0498(self, CONFETTI_OBJ, &pos, frand(-CONFETTI_SPIN, CONFETTI_SPIN));
    }
}

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
extern PhaseTbl D_004482B8;             /* the two entries */

__attribute__((section(".text.cEm00_tickPhaseTable")))
void cEm00_tickPhaseTable(cEm00 *self) {
    PhaseEnt tbl[PHASE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(PhaseTbl *)tbl = D_004482B8;
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
