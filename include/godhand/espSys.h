/* include/godhand/espSys.h - effect system resource tables and memory pool (0x305858..0x307140).
 *
 * func_003058D8 finds the resource entry for an effect kind. entry[1] points
 * at a 1-based offset table, entry[2] at the 0-based T32 table; both start
 * with a count and hold offsets from the table start (0 = no resource).
 * The pool keeps a free list of MemNode blocks with its head node at
 * self + 0x4200; adjacent blocks are merged on free.
 */
#ifndef GODHAND_ESPSYS_H
#define GODHAND_ESPSYS_H

#include "godhand/cModel.h"           /* cVtEnt */

typedef struct espMemNode {
    struct espMemNode *prev;    /* 0x00 */
    struct espMemNode *next;    /* 0x04 */
    char unk08[4];
    char *base;                 /* 0x0C */
    unsigned short size;        /* 0x10 in 16-byte units */
} espMemNode;

#define ESP_MEM_HEAD_OFS 0x4200

extern int func_00305858(int *entry, int force);
extern int *func_003058D8(void *sys, int kind);
extern int FindAndForwardEntry_3059A8(void *sys, int kind, int force);
extern void *func_00305FB0(void *sys, int idx);
extern void func_00306FC0(char *self, espMemNode *node);

/* A frame-driven effect steps its frame timer each tick, by one or through
 * the clock function func_002FA350, and runs its indexed update when the
 * frame index reaches the end. */
#define ESP_DATA_PAUSE   0x2000         /* EspData.flags: advance through the clock function */
#define SYSFLAG_SLOWMO   0x20000        /* bit of GameWork.flags5E4 */

typedef struct EspData {
    int unk00;
    unsigned int flags;                 /* 0x04 ESP_DATA_PAUSE */
} EspData;

typedef struct EspAnim {
    char unk000[0xF0];
    cVtEnt *vtable;                     /* 0x0F0 */
    char unk0F4[0x110 - 0xF4];
    EspData *data;                      /* 0x110 */
    char unk114[0x11D - 0x114];
    unsigned char lockFlags;            /* 0x11D bit 0: advance by the clock function */
    char unk11E[0x124 - 0x11E];
    float pos[3];                       /* 0x124 */
    float unk130;
    float vel[3];                       /* 0x134 */
    char unk140[0x224 - 0x140];
    unsigned short frameIdx;            /* 0x224 */
    char unk226[2];
    float frameT;                       /* 0x228 */
    unsigned short frameEnd;            /* 0x22C 0: no end */
    short key;                          /* 0x22E */
    short keyPrev;                      /* 0x230 */
    char unk232[0x24C - 0x232];
    unsigned char frameNum;             /* 0x24C */
    unsigned char frameNo;              /* 0x24D */
    char unk24E[2];
    float frame;                        /* 0x250 */
} EspAnim;

void func_002FA350(float *frame);
int EspAnim_step(EspAnim *self);

#endif
