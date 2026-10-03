/* sn-2.95.3-136 matched TU. */

#include "godhand/cModel.h"
#include "godhand/Slot2.h"

extern char D_0044AC48[];
extern char D_0044AC50[];
extern char D_0044AC58[];
extern char D_0044AC60[];
extern char D_0044AC68[];
extern int cModel_setMeshDisplay(void *model, char *name, int on);
extern void displayScrollLayer(int id, int on);

/* Start the next read of a streaming buffer into slot `slot`: size it as what is left (or the smaller of the chunk limit and what is left when double buffered), point the slot's record at the next bytes, start the transfer and move the cursor. With nothing left the slot is marked done (3). */
typedef struct StreamRec {
    int src;                            /* 0x00 address of the next bytes */
    int dst;                            /* 0x04 where they go */
    int len;                            /* 0x08 length of this read */
    int zero;                           /* 0x0C */
} StreamRec;

typedef struct StreamBuf {
    unsigned int flags;                 /* 0x00 bit 1: a read has started */
    int dual;                           /* 0x04 nonzero: two buffers, dst from bufDst[] */
    int srcBase;                        /* 0x08 start of the source data */
    int dstBase;                        /* 0x0C start of the single destination */
    int state[4];                       /* 0x10 per slot, 3 = nothing left */
    char unk20[0x20];
    StreamRec rec[2];                   /* 0x40 */
    int handle[2];                      /* 0x60 transfer id per slot */
    unsigned int limit;                 /* 0x68 largest read */
    char unk6C[4];
    int pos;                            /* 0x70 bytes already read */
    unsigned int left;                  /* 0x74 bytes still to read */
    char unk78[0xC];
    int bufDst[2];                      /* 0x84 destination per slot when dual */
} StreamBuf;



__attribute__((section(".text.StreamBuf_startRead")))
void StreamBuf_startRead(StreamBuf *self, int slot)
{
    unsigned int n;
    unsigned int left;

    if (self->dual == 0) {
        n = self->left;
    } else {
        left = self->left;
        n = self->limit;
        if (left < n)
            n = left;
    }
    if (n == 0) {
        self->state[slot] = 3;
        return;
    }
    self->rec[slot].src = self->srcBase + self->pos;
    if (self->dual == 0) {
        self->rec[slot].dst = self->dstBase + self->pos;
    } else {
        self->rec[slot].dst = self->bufDst[slot];
    }
    self->rec[slot].len = n;
    self->rec[slot].zero = 0;
    self->handle[slot] = func_003B2148(&self->rec[slot], 1);
    self->pos += n;
    self->left -= n;
    self->flags |= 2;
}

/* parked, 6 variants: 79/81 words (97.5%), insn delta 0, REG 2, VERDICT register-colouring-only. Residue: the level < 3 test lands in v0, retail uses v1 (the actor id register). Wrapper block, unsigned copy of level, inverted rate test and swapped arm order left it at 79/81 or worse. Signature is (model, unused int, level, float rate): level rides a2 because the float takes f12. */
/* Show the right meshes of a boss model for its damage level: actors 0x625 and 0x627 hide their base mesh and from level 3 swap two meshes (by `rate` at level 3 exactly, always above); actor 0x626 swaps two meshes from level 2. */


#define ACTOR_BOSS_A   0x625
#define ACTOR_BOSS_B   0x626
#define ACTOR_BOSS_C   0x627
#define RATE_SWAP      10.0f








__attribute__((section(".text.cModel_setBossMeshes")))
void cModel_setBossMeshes(char *model, int unused, int level, float rate)
{
    if (model == 0)
        return;
    switch (*(unsigned short *)(model + 0x2FE)) {
    case ACTOR_BOSS_A:
    case ACTOR_BOSS_C:
        cModel_setMeshDisplay(model, D_0044AC48, 0);
        if (level < 3)
            return;
        if (level == 3 && !(RATE_SWAP <= rate)) {
            cModel_setMeshDisplay(model, D_0044AC50, 1);
            cModel_setMeshDisplay(model, D_0044AC58, 0);
        } else {
            cModel_setMeshDisplay(model, D_0044AC50, 0);
            cModel_setMeshDisplay(model, D_0044AC58, 1);
        }
        break;
    case ACTOR_BOSS_B:
        if (level < 2)
            return;
        cModel_setMeshDisplay(model, D_0044AC60, 1);
        cModel_setMeshDisplay(model, D_0044AC68, 0);
        break;
    }
}

/* Blink counters of the three prize marks: for each armed mark (bit 15) count frames, and from the 11th frame flip its on/off bit (bit 14) every frame and show or hide its layer. */


#define SLOT2_OFFSET_MARK     0x49C     /* three blink words, not named in Slot2.h */
#define SLOT2_OFFSET_LAYERS   0x400     /* layer id array, Slot2.h names it `layer` */
#define BLINK_ARMED    0x8000
#define BLINK_ON       0x4000
#define BLINK_COUNT    0x3FFF
#define BLINK_DELAY    0xB
#define MARK_NUM       3

extern int D_003BE130[MARK_NUM];        /* layer index of each mark */


__attribute__((section(".text.Slot2_blinkMarkTick")))
void Slot2_blinkMarkTick(Slot2 *self)
{
    unsigned short *blink = (unsigned short *)((char *)self + SLOT2_OFFSET_MARK);
    int *index = D_003BE130;
    char *layers = (char *)self + SLOT2_OFFSET_LAYERS;
    int i;
    for (i = MARK_NUM - 1; i >= 0; i--) {
        unsigned int v = *blink;
        unsigned short w;
        if (v & BLINK_ARMED) {
            unsigned int next = v + 1;
            *blink = next;
            if ((next & BLINK_COUNT) >= BLINK_DELAY) {
                w = (~next & BLINK_ON) | BLINK_ARMED;
                *blink = w;
                if (w & BLINK_ON)
                    displayScrollLayer(*(int *)(layers + (*index << 2)), 1);
                else
                    displayScrollLayer(*(int *)(layers + (*index << 2)), 0);
            }
        }
        index++;
        blink++;
    }
}
