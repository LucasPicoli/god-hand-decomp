/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/globals.h"

extern char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *snd, int bus, int no, void *obj, int a4, int a5, int a6, int a7);
extern int irand(void);
extern int func_002D3210(char *rec);
extern int func_00135EC8(void *a0, void *a1, void *a2, void *a3, void *hit);
extern int func_001361A0(void *a0, void *hit);

#define SE_BUS_VOICE 2
#define SE_NO_GRUNT  0x13

/* A fighter record with the hit voice number at 0x5F6 (negative = none). */
typedef struct VoiceFighter {
    char unk000[0x5F6];
    short voiceNo;                      /* 0x5F6 */
} VoiceFighter;




/* Play the fighter's own voice when it has one, then the shared grunt. */
__attribute__((section(".text.VoiceFighter_playHitVoice")))
void VoiceFighter_playHitVoice(VoiceFighter *self)
{
    if (self->voiceNo >= 0)
        cSnd_SeCall_2CBA48(D_005FEE00, SE_BUS_VOICE, self->voiceNo, self, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(D_005FEE00, SE_BUS_VOICE, SE_NO_GRUNT, self, 0, 0, 0, 0);
}

#define KEYREC_SIZE 0xC

/* One step of a key table: the threshold at +8, 0xC bytes per record. */
typedef struct KeyRec {
    char unk00[8];
    short key;                          /* 0x08 */
    char unk0A[2];
} KeyRec;

/* Index of the last record whose key is below `key`: -1 when even the first
 * is not, n when all of them are. The owner argument is not used. */
__attribute__((section(".text.KeyRec_findSegment")))
int KeyRec_findSegment(void *owner, short key, int n, KeyRec *rec)
{
    int i;

    if (n == 0)
        return -1;
    if (!(rec[0].key < key))
        return -1;
    for (i = 1; i < n; i++) {
        if (!(rec[i].key < key)) {
            i--;
            break;
        }
    }
    return i;
}

/* An object with a signed tick counter at 0x53F. */
typedef struct TickObj {
    char unk000[0x53F];
    signed char tick;                   /* 0x53F */
} TickObj;



/* Draw a limit in 0..maxVal-1. One call in four resets the tick first. Once
 * the tick has reached the limit, reset it and return 1; otherwise count it
 * up and return 0. */
__attribute__((section(".text.TickObj_stepToLimit")))
int TickObj_stepToLimit(TickObj *self, unsigned int maxVal)
{
    unsigned char limit = irand() % maxVal;

    if ((irand() & 3) == 0)
        self->tick = 0;
    if (self->tick >= limit) {
        self->tick = 0;
        return 1;
    }
    self->tick++;
    return 0;
}

/* A ring of 16 records (0xC0 bytes each, from 0x40 to 0xC40) with a cursor. */
typedef struct Ring {
    char *cur;                          /* 0x00 current record, 0 when none */
} Ring;

#define REC_SIZE    0xC0
#define RING_START  0x40
#define RING_END    0xC40
#define RING_TRIES  16



/* Starting after the cursor, walk the ring (wrapping at the end) to the first
 * record func_002D3210 rejects; give up after 15 records and return the last
 * one. With no cursor, return the first record. */
__attribute__((section(".text.Ring_findRejectedRecord")))
char *Ring_findRejectedRecord(Ring *self)
{
    char *p = (char *)self + RING_START;
    char *end;
    char *start;
    int tries;

    if (self->cur != 0) {
        p = self->cur;
        tries = 1;
        end = (char *)self + RING_END;
        start = (char *)self + RING_START;
        for (; tries < RING_TRIES; tries++) {
            p += REC_SIZE;
            if (!(p < end))
                p = start;
            if (func_002D3210(p) == 0)
                break;
        }
    }
    return p;
}

/* The record func_001F00E8 acts on: the name key at 0x4AC, the hit count at
 * 0x54A and a float at 0x16CC. */
typedef struct NamedHit {
    char unk0000[0x4AC];
    int nameKey;                        /* 0x4AC */
    char unk4B0[0x9A];
    short hits;                         /* 0x54A */
    char unk54C[0x1180];
    float level;                        /* 0x16CC */
} NamedHit;



extern void func_001F00E8(void *owner, NamedHit *rec, float level);

#define LEVEL_BASE_STEP  0.1f
#define LEVEL_LISTED     0.5f

/* For a record that has been hit: a listed name gets the fixed level, any
 * other name gets its own level plus a small step. */
__attribute__((section(".text.NamedHit_applyLevel")))
void NamedHit_applyLevel(void *owner, NamedHit *rec)
{
    if (rec != 0 && rec->hits > 0) {
        if (func_003A5678(D_0042BE90, rec->nameKey) == 0)
            func_001F00E8(owner, rec, rec->level + LEVEL_BASE_STEP);
        else
            func_001F00E8(owner, rec, LEVEL_LISTED);
    }
}

/* Probe for a hit point: zero a local vector, let func_00135EC8 fill it and
 * func_001361A0 confirm it. On success copy the point to out (when given)
 * and return 1; otherwise return 0. */
__attribute__((section(".text.HitProbe_probeHitPoint")))
int HitProbe_probeHitPoint(void *a0, void *a1, void *shape, void *a3, float *out)
{
    float hit[4] __attribute__((aligned(16)));

    VU0_SQC2_VF0(hit, 0);
    if (func_00135EC8(a0, a1, a3, shape, hit) == 0)
        return 0;
    if (func_001361A0(shape, hit) == 0)
        return 0;
    if (out != 0 && out != hit) {
        out[0] = hit[0];
        out[1] = hit[1];
        out[2] = hit[2];
    }
    return 1;
}
