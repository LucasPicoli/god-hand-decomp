/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cOmBase.h"

extern char D_005FEE00[];
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float f12);
extern int cSnd_SeCall(void *a0, int a1, int a2, void *a3, int a4, int a5);
extern int ClearField5B4IfFlagUnset_1B76B0(int self);
extern void func_001B76D8(void *self);
extern char D_0044AD60[];
extern char D_00754C30[];
extern char D_00754C38[];
extern char D_00754C50[];
extern char D_00754C58[];
extern char D_00754C20[];
extern char D_00754240[];
extern char D_00754C10[];
extern int D_003C3CF0;
extern void *SearchData(void *a, void *b, int c);
extern void func_003127B0(void *counter, int value);
extern void *_MemoryAlloc(int size, int align, int heap);
extern void Arena_init(void *arena, void *mem, int size, int flags);
extern void func_00150098(int step);
extern void Forward149400_1492E8(int step);
extern char D_005E7E30[];
extern void func_003A52F0(void *dst, int val, int n);
extern void func_00346B78(int arg);
extern void mwPlySetMallocFn(void *alloc, void *free, void *obj);
extern void func_002B48A0(void);
extern void func_002B48C8(void);
extern void FreeResourceNode_2D3710(void *node);
extern void func_002D34A8(char *rec);
extern int func_002D3210(char *rec);
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern void func_002F5588(void *dst, void *self);
extern void cNode_setTranslationFromWorld(void *self, void *v);
extern void LinkObj_callLockOn(void *self);

/* Once per object (flag byte 0x688): cast a line from the object's position
 * (0x490) along a zeroed direction; when the hit surface (flags at hit+4)
 * has bit 0x400 (water), spawn effect 0x55 at the hit point and play sound
 * 0x50 on the owner, then set the flag. */


typedef struct LineObj {
    char unk000[0xF0];
    void *owner;                        /* 0xF0 */
    char unk0F4[0x39C];
    char pos[0x1F8];                    /* 0x490 */
    unsigned char done;                 /* 0x688 */
} LineObj;

typedef struct HitRec {
    int unk0;
    unsigned int surface;               /* 0x4 */
} HitRec;

#define SURFACE_WATER  0x400
#define FRAME ((char *)buf - 0x30)


extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);



__attribute__((section(".text.LineObj_checkWaterHit")))
void LineObj_checkWaterHit(LineObj *self) {
    float buf[8];
    if (self->done == 0) {
        float *v = buf;
        int one;
        VU0_SQC2_VF0(FRAME, 0x30);
        one = 1;
        if (ChkLine(self->pos, self->owner, v, 0, 7, 0, &buf[4], 1, 0, 0, 0, 0, one) != 0
            && (((HitRec *)*(void **)&buf[4])->surface & SURFACE_WATER) != 0) {
            SetEffectPos(0, 0x55, 0, v, -1, 1.0f);
            cSnd_SeCall(D_005FEE00, 2, 0x50, self->owner, 0, 0);
            self->done = one;
        }
    }
}

/* Run the state handler of the object: the state byte (0x2F4) indexes a copy
 * of the 4-entry table D_004297B8. An entry holds a this-adjustment (0), a
 * selector (2) and a table offset (4). A selector >= 0 reads the handler from
 * the object's own table (entry selector - 1 of the table at self + offset,
 * pointer in the high word, adjustment in the low half), otherwise the
 * handler is the pointer stored at entry + 4. Then run func_001B76D8. */



typedef struct StateEntry {
    short adjust;                       /* 0x0 */
    short selector;                     /* 0x2 */
    short tableOff;                     /* 0x4 */
    short pad6;
} StateEntry;

typedef struct StateTable {
    StateEntry e[4];
} StateTable;

extern StateTable D_004297B8;

__attribute__((section(".text.StateObj_runHandler")))
void StateObj_runHandler(void *a0)
{
    char *s0 = (char *)a0;
    StateTable tbl;
    char *e;
    int i8;
    int f0;
    int type;
    int arg;
    int (*fp)(int);
    long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    tbl = D_004297B8;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&tbl + i8 + 4);
    }
    f0 = tbl.e[*(unsigned char *)(s0 + 0x2F4)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001B76D8(s0);
}

/* Set up the pools of the game from the data record found in D_00747A4C with
 * the name table D_0044AD60: four counters (sums and sizes of the first two
 * halfwords, 0x80 and the second halfword), three arenas (sized by
 * count * 0x380 + 0x20, by the word at 0xC and by the word at 0x4, each
 * taken from the heap D_003C3CF0), then the two follow-up steps with the
 * halfwords at 0x10 and 0x12. */
typedef struct PoolInfo {
    short count;                        /* 0x00 */
    short extra;                        /* 0x02 */
    int sizeB;                          /* 0x04 */
    int unk08;                          /* 0x08 */
    int sizeA;                          /* 0x0C */
    short stepA;                        /* 0x10 */
    short stepB;                        /* 0x12 */
} PoolInfo;

#define ENTRY_SIZE    0x380
#define ENTRY_HEADER  0x20
#define POOL_ALIGN    0x10
#define SIZE_BUF      0x80

extern PoolInfo *D_00747A4C;
















__attribute__((section(".text.System_initPools")))
void System_initPools(void) {
    PoolInfo *info;
    int n;
    info = (PoolInfo *)SearchData(D_00747A4C, D_0044AD60, 0);
    func_003127B0(D_00754C30, info->count + info->extra);
    func_003127B0(D_00754C38, info->count);
    func_003127B0(D_00754C50, SIZE_BUF);
    func_003127B0(D_00754C58, info->extra);
    n = info->count * ENTRY_SIZE + ENTRY_HEADER;
    Arena_init(D_00754C20, _MemoryAlloc(n, POOL_ALIGN, D_003C3CF0), n, 0);
    Arena_init(D_00754240, _MemoryAlloc(info->sizeA, POOL_ALIGN, D_003C3CF0), info->sizeA, 0);
    Arena_init(D_00754C10, _MemoryAlloc(info->sizeB, POOL_ALIGN, D_003C3CF0), info->sizeB, 0);
    func_00150098(info->stepA);
    Forward149400_1492E8(info->stepB);
}

/* Init the movie player pool: set the table pointer D_005E7E30, clear the
 * counters, hand the movie library a 59.94 fps setup record, set it up with
 * the allocator hooks func_002B48A0 and func_002B48C8, then free the three
 * resource nodes (0xAC bytes each) and clear the three slot pointers. */
typedef struct MoviePool {
    char *nodes;                        /* 0x00 first resource node */
    int slot[3];                        /* 0x04 */
    int count;                          /* 0x10 */
    unsigned char flag;                 /* 0x14 */
    char pad15[3];
    int unk18;                          /* 0x18 */
} MoviePool;

typedef struct MovieSetup {
    float fps;                          /* 0x00 */
    int a;                              /* 0x04 */
    int b;                              /* 0x08 */
    int c;                              /* 0x0C */
    int rest[4];                        /* 0x10 cleared by the memset */
} MovieSetup;

#define NODE_SIZE   0xAC
#define NODE_COUNT  3
#define MOVIE_FPS   59.94f



extern void func_003452D8(MovieSetup *setup);






__attribute__((section(".text.MoviePool_init")))
void MoviePool_init(MoviePool *self) {
    MovieSetup setup;
    int *slot;
    char *node;
    int i;
    self->count = 0;
    self->flag = 0;
    self->unk18 = 0;
    slot = self->slot;
    i = NODE_COUNT - 1;
    self->nodes = D_005E7E30;
    func_003A52F0(&setup, 0, 0x20);
    setup.fps = MOVIE_FPS;
    setup.a = 1;
    setup.b = 1;
    setup.c = 0;
    func_003452D8(&setup);
    func_00346B78(-1);
    mwPlySetMallocFn((void *)func_002B48A0, (void *)func_002B48C8, 0);
    node = self->nodes;
    do {
        FreeResourceNode_2D3710(node);
        i--;
        node += NODE_SIZE;
        *slot++ = 0;
    } while (i >= 0);
}

/* Step the cursor of a ring of 16 records (0xC0 bytes each, from 0x40 to
 * 0xC40) to the next record that func_002D3210 accepts (returns 1). Tries
 * at most 15 records; if none is accepted the cursor is cleared. Does nothing
 * when there is no cursor or the current record is already accepted; a record
 * that is accepted is announced again with func_002D34A8 and re-tested. */
typedef struct Ring {
    char *cur;                          /* 0x00 current record, 0 when none */
} Ring;

#define REC_SIZE    0xC0
#define RING_START  0x40
#define RING_END    0xC40
#define RING_TRIES  16
#define ACCEPTED    1




__attribute__((section(".text.Ring_stepToAccepted")))
void Ring_stepToAccepted(Ring *self) {
    int tries;
    char *end;
    char *start;
    int accepted;
    if (self->cur == 0)
        return;
again:
    func_002D34A8(self->cur);
    if (func_002D3210(self->cur) != 0)
        return;
    tries = 1;
    end = (char *)self + RING_END;
    start = (char *)self + RING_START;
    accepted = ACCEPTED;
    do {
        self->cur = self->cur + REC_SIZE;
        if (!(self->cur < end))
            self->cur = start;
        if (func_002D3210(self->cur) == accepted)
            goto again;
        tries++;
    } while (tries < RING_TRIES);
    self->cur = 0;
}

/* Aim at the lock-on target: read three vectors of the object (base, offset
 * from func_002F5588, field B0), add the offset and the third into one
 * point, pass the point to cNode_setTranslationFromWorld, run the lock-on call, then pass
 * the base vector to cNode_setTranslationFromWorld. */



typedef struct AimFrame {
    cVec base;                          /* sp+0x00 */
    cVec point;                         /* sp+0x10 */
    cVec offset;                        /* sp+0x20 */
    cVec third;                         /* sp+0x30 */
    cVec sum;                           /* sp+0x40 */
} AimFrame;






__attribute__((section(".text.LockOn_aimAtTarget")))
void LockOn_aimAtTarget(void *self)
{
    AimFrame fr;
    cVec *sum;
    StoreVecFromFieldB0_2B6160(&fr.base, self);
    func_002F5588(&fr.offset, self);
    StoreVecFromFieldB0_2B6160(&fr.third, self);
    sum = &fr.sum;
    VU0_LQC2(4, &fr.offset, 0);
    VU0_SQC2(4, &fr, 0x40);
    VU0_VADD_XYZ_IP(&fr.sum, 0, &fr.third);
    VU0_LQC2(4, sum, 0);
    VU0_SQC2(4, &fr, 0x10);
    cNode_setTranslationFromWorld(self, &fr.point);
    LinkObj_callLockOn(self);
    cNode_setTranslationFromWorld(self, &fr.base);
}
