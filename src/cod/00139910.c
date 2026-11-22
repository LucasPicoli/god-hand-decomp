/* sn-2.95.3-136 matched TU. */

#include "godhand/cDvd.h"
#include "godhand/cOmBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/globals.h"

extern void *sceSifAllocIopHeap(int size);
extern int Tramp_sceSifFreeSysMemory_3B5A50(void *p);
extern int Forward2D2F78_2D3020(int a, int b, int c, int d);
extern int Obj3290_Tramp_003313E0_9298(void *self);
extern int Entry_releaseIfReady(void *self);
extern void SetCustomIDDispOneOrAll_1F29C0(void *self, int sel, int on);
extern int Rnd(void);
extern char D_00427CD8[];
extern void CustomIDWork_SetLocalPosY(CustomIDWork *work, int y);

/* Allocate size bytes on the IOP heap, hand them to Forward2D2F78_2D3020 and store the block in *out on success; free it on failure. */
__attribute__((section(".text.cSif_allocAndForward")))
int cSif_allocAndForward(int a, int b, void **out, int size) {
    void *mem;
    int r;
    *out = 0;
    mem = sceSifAllocIopHeap(size);
    if (mem != 0) {
        r = Forward2D2F78_2D3020(a, b, (int)mem, size);
        if (r != 0) {
            *out = mem;
            return r;
        }
        Tramp_sceSifFreeSysMemory_3B5A50(mem);
    }
    return 0;
}

/* The disc queue plus the state machine that follows it. */
typedef struct cDvdState {
    cDvd dvd;                           /* 0x0000 */
    unsigned char state;                /* 0x110C 0 idle, 1 counting down */
    char unk110D[3];
    int timer;                          /* 0x1110 */
} cDvdState;

#define DVD_STATE_COUNT   1
#define DVD_TIMER_START   0x5A          /* frames before the state drops back */

/* Step the disc state: a hit sets state 1 with a 90 frame timer; state 1 counts the timer down once the disc is ready
 * and drops to 0. Returns the state. */
__attribute__((section(".text.cDvd_stepState")))
unsigned char cDvd_stepState(cDvdState *self) {
    unsigned char st;
    if (Obj3290_Tramp_003313E0_9298(self) == 1) {
        self->state = DVD_STATE_COUNT;
        self->timer = DVD_TIMER_START;
    } else {
        st = self->state;
        if (st == DVD_STATE_COUNT) {
            if (func_00201A50(self) == st) {
                if (self->dvd.cur == 0) {
                    if (Entry_releaseIfReady(self) == 0) {
                        int n = self->timer;
                        if (n == 0) {
                            self->state = 0;
                        } else {
                            self->timer = n - 1;
                        }
                    }
                }
            }
        }
    }
    return self->state;
}

static __inline__ void vecSet(cVec *d, float x, float y, float z) {
    d->x = x;
    d->y = y;
    d->z = z;
    d->w = 1.0f;
}

/* An object whose position (+0xB0..+0xB8) another object exposes. */
typedef struct PosSource {
    char unk000[0xB0];
    float x, y, z;                      /* 0xB0 */
} PosSource;

/* An actor tracking two sources: the first at 0x364 and the second at 0x368, copied to the vectors at 0x210 and 0x200. */
typedef struct TrackObj {
    char unk000[0x200];
    cVec second;                        /* 0x200 */
    cVec first;                         /* 0x210 */
    char unk220[0x144];
    PosSource *srcFirst;                /* 0x364 */
    PosSource *srcSecond;               /* 0x368 */
} TrackObj;

/* Copy the position of each source into the matching vector, with w = 1. */
__attribute__((section(".text.cOmBase_copyTargetPositions")))
void cOmBase_copyTargetPositions(TrackObj *self) {
    PosSource *a = self->srcFirst;
    if (a != 0 && self->srcSecond != 0) {
        cVec v;
        PosSource *b;
        vecSet(&v, a->x, a->y, a->z);
        cVec_copy3(&self->first, &v);
        b = self->srcSecond;
        vecSet(&v, b->x, b->y, b->z);
        cVec_copy3(&self->second, &v);
    }
}

/* Hide display 0x12, show displays 5 and 6, and show 7..10 too when full is set. */
__attribute__((section(".text.CustomID_showDisplays")))
void CustomID_showDisplays(void *self, int full) {
    SetCustomIDDispOneOrAll_1F29C0(self, 0x12, 0);
    SetCustomIDDispOneOrAll_1F29C0(self, 5, 1);
    SetCustomIDDispOneOrAll_1F29C0(self, 6, 1);
    if (full != 0) {
        SetCustomIDDispOneOrAll_1F29C0(self, 7, 1);
        SetCustomIDDispOneOrAll_1F29C0(self, 8, 1);
        SetCustomIDDispOneOrAll_1F29C0(self, 9, 1);
        SetCustomIDDispOneOrAll_1F29C0(self, 0xA, 1);
    }
}

typedef struct { int w[6]; } DivTable;

/* A fighter with a flag word at 0x9D0 past cOmBase. */
typedef struct ChanceObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x3F0];
    unsigned int flags;                 /* 0x9D0 */
} ChanceObj;

#define CHANCE_OFF  0x20000000          /* ChanceObj.flags: no chance roll */

/* Chance roll for a level: 0 when disabled or level 1, else true one time in the level's divisor. */
__attribute__((section(".text.cOmBase_rollChance")))
int cOmBase_rollChance(ChanceObj *self, int level) {
    DivTable tbl;
    if ((self->flags & CHANCE_OFF) != 0) {
        return 0;
    }
    tbl = *(DivTable *)D_00427CD8;
    if (level == 1) {
        return 0;
    }
    return Rnd() % tbl.w[level] == 0;
}

typedef struct { int w[5]; } PosTbl;

/* An ID screen with two position elements, at 0x60 and 0x11D0. */
typedef struct IdPosScreen {
    char unk000[0x60];
    CustomIDWork first;                 /* 0x060 */
    char unk0DC[0x10F4];
    CustomIDWork second;                /* 0x11D0 */
} IdPosScreen;

/* Place both elements at the local Y of position idx (0..4). */
__attribute__((section(".text.CustomID_placeByIndexB")))
void CustomID_placeByIndexB(IdPosScreen *self, unsigned short idx) {
    PosTbl a;
    PosTbl b;
    if (idx < 5) {
        a = *(PosTbl *)D_0042BD40;
        CustomIDWork_SetLocalPosY(&self->first, a.w[idx]);
        b = *(PosTbl *)D_0042BD58;
        CustomIDWork_SetLocalPosY(&self->second, b.w[idx]);
    }
}
