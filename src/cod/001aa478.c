/* sn-2.95.3-136 matched TU. */

#include "godhand/cObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cDvd.h"
#include "godhand/globals.h"

extern void func_001C2378(void *self);
extern void cModel_calcParts(void *self);
extern void cOmBase_setMeshColorFromLayer(void *self, int layer, float r, float g, float b);
extern cOmBase *Getplayer(void);
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *obj);
extern void func_001C24E8(void *self);
extern void func_002011B0(cDvd *self);

/* An actor with an aim record past cObj: two ints at 0x630/0x634 and two vectors at 0x640/0x650. */
typedef struct AimObj {
    COBJ_FIELDS
    char unk310[0x320];
    int aimA;                           /* 0x630 */
    int aimB;                           /* 0x634 */
    char unk638[8];
    cVec from;                          /* 0x640 */
    cVec to;                            /* 0x650 */
} AimObj;

/* Store the aim record, enter step 2 and rebuild the parts. */
__attribute__((section(".text.cObj_setupAimStep2")))
void cObj_setupAimStep2(AimObj *self, int a, int b, cVec *from, cVec *to) {
    self->aimA = a;
    self->aimB = b;
    cVec_copy3(&self->from, from);
    cVec_copy3(&self->to, to);
    self->step = 2;
    func_001C2378(self);
    cModel_calcParts(self);
}

/* A node of a list of sequences. */
typedef struct SeqNode {
    char unk00[0x88];
    struct SeqNode *next;               /* 0x88 */
    char unk8C[0xC];
    unsigned int flags;                 /* 0x98 */
} SeqNode;

/* A sequence set: a list head at 0x18 and a stop count at 0x1C. */
typedef struct SeqSet {
    char unk00[0x18];
    SeqNode *head;                      /* 0x18 */
    int stopCount;                      /* 0x1C */
} SeqSet;

#define SEQ_LOOPING   0x100
#define SEQ_HELD      0x180000

/* True when nothing is stopped and no live sequence has the looping flag without a held flag. */
__attribute__((section(".text.cSnd_isNoLoopVoice")))
int cSnd_isNoLoopVoice(SeqSet *self) {
    int ok = self->stopCount == 0;
    SeqNode *node = self->head;
    while (node != 0) {
        if (func_00373A50(node) != 0 && func_00373A58(node) == 0) {
            unsigned int flags = node->flags;
            if ((flags & SEQ_LOOPING) != 0) {
                if ((flags & SEQ_HELD) == 0) {
                    ok = 0;
                }
            }
        }
        node = node->next;
    }
    return ok;
}

/* A fighter with a blink countdown at 0x9E0 past cOmBase. */
typedef struct BlinkObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x400];
    int blinkLeft;                      /* 0x9E0 ticks left; odd ticks show white, even ticks red */
} BlinkObj;

#define BLINK_LAYER  1

/* Count the blink timer down one tick: the last tick and odd ticks show white, even ticks red. */
__attribute__((section(".text.cOmBase_blinkTick")))
void cOmBase_blinkTick(BlinkObj *self) {
    int n = self->blinkLeft;
    if (n == 0) {
        return;
    }
    n -= 1;
    self->blinkLeft = n;
    if (n != 0) {
        if ((n & 1) != 0) {
            cOmBase_setMeshColorFromLayer(self, BLINK_LAYER, 1.0f, 1.0f, 1.0f);
        } else {
            cOmBase_setMeshColorFromLayer(self, BLINK_LAYER, 1.0f, 0.0f, 0.0f);
        }
        return;
    }
    cOmBase_setMeshColorFromLayer(self, BLINK_LAYER, 1.0f, 1.0f, 1.0f);
}

#define COMBASE_UNK4AC(o)  (*(int *)((char *)(o) + 0x4AC))

/* When the player is alive, free and not caught, and self is not flagged off, run func_001C24E8 unless the table lookup hits. */
__attribute__((section(".text.cPlayer_tryTrigger")))
void cPlayer_tryTrigger(cOmBase *self) {
    cOmBase *player = Getplayer();
    if (player->hp > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(player) == 0) {
            if (D_00586A04 <= 0) {
                if (self != 0) {
                    if (self->objFlags >= 0) {
                        if (func_003A5678(D_0044D420, COMBASE_UNK4AC(self)) == 0) {
                            func_001C24E8(self);
                        }
                    }
                }
            }
        }
    }
}

/* Find a free job slot (state 0). If all 32 are taken, run func_002011B0 to free some and look again. Returns 0 if none. */
__attribute__((section(".text.cDvd_takeFreeJob")))
cDvdJob *cDvd_takeFreeJob(cDvd *self) {
    int i;
    for (i = 0; i < CDVD_JOB_NUM; i++) {
        if (self->job[i].state == 0) {
            return &self->job[i];
        }
    }
    func_002011B0(self);
    for (i = 0; i < CDVD_JOB_NUM; i++) {
        if (self->job[i].state == 0) {
            return &self->job[i];
        }
    }
    return 0;
}

/* Allocate the heap block for a job from its file number. On failure wipe the running job and start the next one;
 * otherwise apply the job's args to the new block. */
__attribute__((section(".text.cDvd_startJobHeap")))
void cDvd_startJobHeap(cDvd *self, cDvdJob *job) {
    void *heap = func_00323918(0, job->fileNo);
    job->heap = heap;
    if (heap == 0) {
        func_003A52F0(self->cur, 0, sizeof(cDvdJob));
        self->cur = 0;
        self->queueNum = 1;
        func_00201290(self);
        return;
    }
    if (job->arg70 != 0) {
        func_00324258((int)heap, job->arg70, 0);
    }
    func_00323E80((int)job->heap, job->blockNum, (int)job->buf);
}
