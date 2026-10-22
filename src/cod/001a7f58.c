/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/cEmSetParam.h"
#include "godhand/cEmWrap.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"

#define EMSPAWN_QUEUE_NUM 16
#define EMSPAWN_EMPTY     0xFF
#define EMSPAWN_SE        0x33
#define EMSPAWN_MUTEKI    30.0f

/* The enemy spawner: a ring of room-table entry numbers to set at its position. */
typedef struct cOmEmSpawner {
    cOmBase base;
    char unk5E0[0x600 - 0x5E0];
    unsigned char queue[EMSPAWN_QUEUE_NUM]; /* 0x600 entry numbers, EMSPAWN_EMPTY when free */
    unsigned char unk610;
    unsigned char cursor;                   /* 0x611 last slot it set from */
    unsigned char slots;                    /* 0x612 enemies it may still set */
    unsigned char unk613[2];
    unsigned char waiting;                  /* 0x615 queued entries */
    char unk616[0x61C - 0x616];
    float baseY;                            /* 0x61C height the enemies stand at */
} cOmEmSpawner;

/* A cEmWrap handle seen through its first byte, the entry number it resolves. */
typedef struct cEmHandle {
    unsigned char entryNo;
    char unk01[3];
    cEmActor *actor;
} cEmHandle;

extern cSnd D_005FEE00;
extern int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6);
extern cEmActor *cEmSetParam_setEm(cEmSetParam *self, unsigned char no);
extern int cEmWrap_setPos_2959B0(int *a0, int a1);
extern void cEmWrap_StartAction(cEmWrap *self);
extern void cEmWrap_SetKeepPos(void *a0, int a1);
extern void cEmWrap_setMutekiTimer(void *a0, float f);
extern void cEmSetParam_updateSetDataPos(cEmSetParam *self, unsigned int no, float *pos);
extern void cEmSetParam_updateSetDataAppPattern(cEmSetParam *self, unsigned int no, unsigned char pattern);

/* Sets queued enemies at the spawner until its slots run out; returns how many it set. */
__attribute__((section(".text.func_001A7F58")))
int func_001A7F58(cOmEmSpawner *self)
{
    cEmHandle em;
    cVec pos;
    unsigned int start;
    unsigned int i;
    int before;

    if (self->slots == 0) {
        return 0;
    }
    if (self->waiting == 0) {
        return 0;
    }
    cSnd_SeCall_2CB8A0(&D_005FEE00, 2, EMSPAWN_SE, -1, -1, 0, 0);
    start = self->cursor;
    before = self->waiting;
    i = start;
    while (self->waiting != 0) {
        if (self->queue[i] != EMSPAWN_EMPTY) {
            em.entryNo = self->queue[i];
            cEmSetParam_setEm(&D_00586AB0, em.entryNo);
            cEmWrap_setPos_2959B0((int *)&em, (int)self->base.pos);
            cEmWrap_StartAction((cEmWrap *)&em);
            VU0_LQC2(4, self->base.pos, 0);
            VU0_SQC2_MEM(4, &pos, 0);
            pos.y = self->baseY;
            cEmWrap_SetKeepPos(&em, (int)&pos);
            cEmWrap_setMutekiTimer(&em, EMSPAWN_MUTEKI);
            cEmSetParam_updateSetDataPos(&D_00586AB0, self->queue[i], &pos.x);
            cEmSetParam_updateSetDataAppPattern(&D_00586AB0, self->queue[i], 0);
            self->queue[i] = EMSPAWN_EMPTY;
            self->cursor = i;
            self->waiting--;
            if (--self->slots == 0) {
                break;
            }
        }
        if (++i >= EMSPAWN_QUEUE_NUM) {
            i = 0;
        }
        if (start == i) {
            break;
        }
    }
    return before - self->waiting;
}
