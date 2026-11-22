/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/globals.h"

extern char D_0044BED0[];
extern char D_00747AC0;
extern char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void cOmBase_setMeshColorFromLayer(void *a0, int a1, float r, float g, float b);
extern void cHeap_free(void *heap, void *p);
extern void BlockOwner_dtor(void *self, int flags);
extern unsigned short D_003BD70C;
extern int cIDBase_initialize(void *self, int pack, int type);
extern void func_00144C90(void *self);

/* Constructor of a collision shape: set its vtable, zero the flags and the four
 * vector slots (0x50, 0x60, 0xD0, 0xF0), record the owner, mark the shape as
 * owned (bit 1) unless the owner is the global D_00747AC0, then set the offset
 * and the second position. Returns the shape. */


typedef struct ShapeObj {
    char unk00[4];
    unsigned char flags;                /* 0x04 bit 1: owner is not the global */
    char unk05[3];
    void *owner;                        /* 0x08 */
    char unk0C[0xF4];
    void *vt;                           /* 0x100 */
} ShapeObj;

#define SHAPE_NOT_GLOBAL_OWNER  0x2



extern void cCollisionShape_setOffsetPos(ShapeObj *self, void *offset);
extern void func_002BB298(ShapeObj *self, void *pos);

__attribute__((section(".text.cCollisionShape_construct")))
ShapeObj *cCollisionShape_construct(ShapeObj *self, void *owner, void *offset, void *pos) {
    self->vt = D_0044BED0;
    self->flags = 0;
    VU0_SQC2_VF0(self, 0x50);
    VU0_SQC2_VF0(self, 0x60);
    VU0_SQC2_VF0(self, 0xD0);
    VU0_SQC2_VF0(self, 0xF0);
    self->owner = owner;
    if (owner != &D_00747AC0)
        self->flags = self->flags | SHAPE_NOT_GLOBAL_OWNER;
    else
        self->flags = self->flags & ~SHAPE_NOT_GLOBAL_OWNER;
    cCollisionShape_setOffsetPos(self, offset);
    func_002BB298(self, pos);
    return self;
}

/* Reset an actor's motion state: flag it (bit 12 of 0x14), run func_002B22E0
 * with the animation id, store the mode byte and clear the work fields, set
 * the two ids to -1, run func_002B21F0 with the move number, then clear the
 * four phase bytes at 0xC to 0xF. */
#define ACT_FLAG_RESET  0x1000

typedef struct ActorMove {
    char unk00[0xC];
    unsigned char phase0;               /* 0x0C */
    unsigned char phase1;               /* 0x0D */
    unsigned char phase2;               /* 0x0E */
    unsigned char phase3;               /* 0x0F */
    char unk10[4];
    unsigned int flags;                 /* 0x14 */
    char unk18[4];
    int unk1C;                          /* 0x1C */
    int idB;                            /* 0x20 */
    char unk24[8];
    unsigned char mode;                 /* 0x2C */
    unsigned char unk2D;                /* 0x2D */
    short unk2E;                        /* 0x2E */
    signed char idA;                    /* 0x30 */
    char unk31[0x13];
    unsigned char unk44;                /* 0x44 */
    char unk45[7];
    unsigned char unk4C;                /* 0x4C */
    char unk4D[3];
    int unk50;                          /* 0x50 */
    char unk54[0x5E];
    unsigned char unkB2;                /* 0xB2 */
} ActorMove;

extern void func_002B22E0(ActorMove *self, int arg);
extern void func_002B21F0(ActorMove *self, int move);

__attribute__((section(".text.ActorMove_resetMotion")))
void ActorMove_resetMotion(ActorMove *self, unsigned short move, unsigned char mode, int arg) {
    self->flags |= ACT_FLAG_RESET;
    func_002B22E0(self, arg);
    self->mode = mode;
    self->unk1C = 0;
    self->unk2D = 0;
    self->unkB2 = 0;
    self->unk2E = 0;
    self->unk44 = 0;
    self->unk4C = 0;
    self->unk50 = 0;
    self->idA = self->idB = -1;
    func_002B21F0(self, move);
    self->phase0 = 0;
    self->phase1 = 0;
    self->phase2 = 0;
    self->phase3 = 0;
}

/* Start the stun effect: play sound 10 from the global sound object, set the
 * mesh colour to (1, 0, 0), set the state half to 4. For an object with no
 * timer (byte 0x2F4 == 0) raise the blink level by 0.04, capped at 0.3.
 * Finally set flag bit 4 in 0x600. */
typedef struct StunObj {
    char unk000[0x2F4];
    unsigned char timer;                /* 0x2F4 */
    char unk2F5[0x30B];
    unsigned int flags;                 /* 0x600 */
    char unk604[0x40];
    short state;                        /* 0x644 */
    char unk646[0x31E];
    float blink;                        /* 0x964 */
} StunObj;

#define STUN_STATE        4
#define STUN_BLINK_STEP   0.04f
#define STUN_BLINK_MAX    0.3f
#define STUN_FLAG_ACTIVE  0x10





__attribute__((section(".text.StunObj_startStun")))
void StunObj_startStun(StunObj *self) {
    float v;
    cSnd_SeCall_2CBA48(D_005FEE00, 0, 10, self, 0, 0, 0, 0);
    cOmBase_setMeshColorFromLayer(self, 0, 1.0f, 0.0f, 0.0f);
    self->state = STUN_STATE;
    if (self->timer == 0) {
        v = self->blink + STUN_BLINK_STEP;
        self->blink = v;
        if (STUN_BLINK_MAX <= v)
            self->blink = STUN_BLINK_MAX;
    }
    self->flags |= STUN_FLAG_ACTIVE;
}

/* Deleting destructor: reset the vtable, free the six buffers held at 0x330,
 * 0x334, 0x338, 0x33C, 0x324 and 0x30C, then run the base destructor. */




typedef struct BufOwner {
    char unk000[0xF0];
    void *vt;                           /* 0xF0 */
    char unkF4[0x218];
    void *buf30C;                       /* 0x30C */
    char unk310[0x14];
    void *buf324;                       /* 0x324 */
    char unk328[8];
    void *buf330;                       /* 0x330 */
    void *buf334;                       /* 0x334 */
    void *buf338;                       /* 0x338 */
    void *buf33C;                       /* 0x33C */
} BufOwner;

#define FREE_BUF(p) if ((p) != 0) cHeap_free(*(void **)((char *)(p) - 0x20), (p))

__attribute__((section(".text.BufOwner_deletingDtor")))
void BufOwner_deletingDtor(BufOwner *self, int flags) {
    self->vt = D_0044E300;
    FREE_BUF(self->buf330);
    FREE_BUF(self->buf334);
    FREE_BUF(self->buf338);
    FREE_BUF(self->buf33C);
    FREE_BUF(self->buf324);
    FREE_BUF(self->buf30C);
    BlockOwner_dtor(self, flags);
}

/* Init the display: five entries of 0x50 bytes from 0x100 (pack 1, type 5),
 * two more at 0x430 (type 0x19) and 0x480 (type 0x1A), set both colour words
 * to 0x80808080, run func_00144C90, clear the three counters and take the
 * default value from D_003BD70C. */
#define ENTRY_SIZE   0x50
#define ENTRY_COUNT  5






__attribute__((section(".text.cIDBaseScreen_init")))
void cIDBaseScreen_init(char *self) {
    unsigned short i = 0;
    do {
        cIDBase_initialize(self + 0x100 + i * ENTRY_SIZE, 1, 5);
        i = i + 1;
    } while (i < ENTRY_COUNT);
    cIDBase_initialize(self + 0x430, 1, 0x19);
    cIDBase_initialize(self + 0x480, 1, 0x1A);
    *(int *)(self + 0x364) = 0x80808080;
    *(int *)(self + 0x368) = 0x80808080;
    func_00144C90(self);
    *(short *)(self + 0x41E) = 0;
    *(short *)(self + 0x420) = 0;
    *(int *)(self + 0x90) = 0;
    *(unsigned short *)(self + 0x4D0) = D_003BD70C;
}
