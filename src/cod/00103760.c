/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cOmBase.h"

extern void CustomIDWork_SetLocalPosY(char *work, int y);
extern void SetCustomIDDispOneOrAll_1F4778(char *self, int id, int on);
extern void StoreVecFromFieldB0_2B6160(float *out, void *obj);
extern void cNode_setTranslationFromWorld(void *self, float *pos);
extern void func_002FBED0(void *self);
extern int cOmBase_checkDamage(void *self, void *damage);
extern int cSnd_SeCall_2CBA48(void *snd, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);
extern void func_001B0540(void *self);
extern void func_001B7EE0(void *self, float f);
extern float capVu0LengthSq(void *v);
extern cOmBase *Getplayer(void);
extern void cModel_calcParts(void *model);

#define POS_NUM  7                      /* positions per table */

typedef struct { int w[POS_NUM]; } PosTbl;

extern PosTbl D_0042BFB0;               /* local Y of the first work entry per index */
extern PosTbl D_0042BFD0;               /* local Y of the second work entry per index */

/* Place the two work entries at the Y values of position `idx` (0..6) and set the visibility of ids 8 and 9. */
__attribute__((section(".text.CustomIDWork_placeByIndex")))
void CustomIDWork_placeByIndex(char *self, unsigned short idx, int on)
{
    PosTbl a;
    PosTbl b;

    if (idx < POS_NUM) {
        a = D_0042BFB0;
        CustomIDWork_SetLocalPosY(self + 0x440, a.w[idx]);
        b = D_0042BFD0;
        CustomIDWork_SetLocalPosY(self + 0x4BC, b.w[idx]);
        SetCustomIDDispOneOrAll_1F4778(self, 8, on);
        SetCustomIDDispOneOrAll_1F4778(self, 9, on);
    }
}

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

extern Vec4 D_00462F40[8];              /* corners of the unit cube, centred on the origin */
extern Vec4 D_00462F00[4];              /* corners of the unit square in the z = 0 plane */

#define NO_CUT  0xFFFF

/* When the cut is unset and enable is nonzero, fill the corner tables of the unit cube and the unit square. */
__attribute__((section(".text.CornerTables_init")))
void CornerTables_init(int enable, int cut)
{
    if (cut == NO_CUT && enable != 0) {
        Vec4 *cube = D_00462F40;
        Vec4 *square = D_00462F00;
        cube->x = -0.5f;
        cube->y = 0.5f;
        cube->z = -0.5f;
        cube->w = 1.0f;
        cube++;
        square->x = -0.5f;
        square->y = 0.5f;
        square->z = 0.0f;
        square->w = 1.0f;
        square++;
        cube->x = 0.5f;
        cube->y = 0.5f;
        cube->z = -0.5f;
        cube->w = 1.0f;
        cube++;
        square->x = 0.5f;
        square->y = 0.5f;
        square->z = 0.0f;
        square->w = 1.0f;
        square++;
        cube->x = 0.5f;
        cube->y = 0.5f;
        cube->z = 0.5f;
        cube->w = 1.0f;
        cube++;
        square->x = 0.5f;
        square->y = -0.5f;
        square->z = 0.0f;
        square->w = 1.0f;
        square++;
        cube->x = -0.5f;
        cube->y = 0.5f;
        cube->z = 0.5f;
        cube->w = 1.0f;
        cube++;
        square->x = -0.5f;
        square->y = -0.5f;
        square->z = 0.0f;
        square->w = 1.0f;
        square++;
        cube->x = -0.5f;
        cube->y = -0.5f;
        cube->z = -0.5f;
        cube->w = 1.0f;
        cube++;
        cube->x = 0.5f;
        cube->y = -0.5f;
        cube->z = -0.5f;
        cube->w = 1.0f;
        cube++;
        cube->x = 0.5f;
        cube->y = -0.5f;
        cube->z = 0.5f;
        cube->w = 1.0f;
        cube++;
        cube->x = -0.5f;
        cube->y = -0.5f;
        cube->z = 0.5f;
        cube->w = 1.0f;
        cube++;
    }
}

extern char *D_005CAFF0;                /* the player object */

typedef struct WrapObj {
    char unk000[0x2B8];
    float radius;                       /* 0x2B8 half extent of the wrap box */
} WrapObj;

#define PLAYER_POS_OFFSET  0x210

/* Place the object at its own position wrapped into a box of half extent `radius` around the player: a coordinate below the box jumps to the far side and one above it to the near side. Then run the base update. */
__attribute__((section(".text.WrapObj_wrapIntoBox")))
void WrapObj_wrapIntoBox(WrapObj *self)
{
    float center[4] __attribute__((aligned(16)));
    float pos[4] __attribute__((aligned(16)));
    float out[4] __attribute__((aligned(16)));
    float *src;
    float *dst;

    VU0_SQC2_VF0(center, 0);
    src = (float *)(D_005CAFF0 + PLAYER_POS_OFFSET);
    if (center != src) {
        center[0] = src[0];
        center[1] = src[1];
        center[2] = src[2];
    }
    StoreVecFromFieldB0_2B6160(pos, self);
    if (pos[0] < center[0] - self->radius) pos[0] = center[0] + self->radius;
    else if (center[0] + self->radius < pos[0]) pos[0] = center[0] - self->radius;
    if (pos[1] < center[1] - self->radius) pos[1] = center[1] + self->radius;
    else if (center[1] + self->radius < pos[1]) pos[1] = center[1] - self->radius;
    if (pos[2] < center[2] - self->radius) pos[2] = center[2] + self->radius;
    else if (center[2] + self->radius < pos[2]) pos[2] = center[2] - self->radius;
    dst = out;
    VU0_LQC2(4, pos, 0);
    VU0_SQC2(4, center, 0x20);
    cNode_setTranslationFromWorld(self, dst);
    func_002FBED0(self);
}

extern char D_005FEE00[];               /* cSnd */

#define HP_DISPLAY_MAX  1000

struct Entry_func_001B0838 { short f0; short f2; short f4; short f6; };
struct Table_func_001B0838 { struct Entry_func_001B0838 e[1]; };
extern struct Table_func_001B0838 D_003BDCB0;

typedef struct HitPhaseObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damage;                       /* 0x600 */
} HitPhaseObj;

/* Phase tick: on a damage hit cap the displayed health at 1000, flash and play sound 0x2D and enter phase 1; then run the handler the phase picks from the table and the two shared post steps. */
__attribute__((section(".text.HitPhaseObj_tickPhase")))
void HitPhaseObj_tickPhase(HitPhaseObj *self)
{
    char *s0 = (char *)self;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    if (cOmBase_checkDamage(self, self->damage) == 1) {
        int cap = HP_DISPLAY_MAX;
        if (self->base.hpMax <= cap) {
            self->base.hp = self->base.hpMax;
        } else {
            self->base.hp = cap;
        }
        self->base.hitFlash = 5.0f;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x2D, self, 0, 0, 0, 0);
        self->base.step = 0;
        self->base.phase = 1;
        self->base.stepArg = 0;
    }
    i8 = self->base.phase * 8;
    e = (char *)&D_003BDCB0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDCB0 + i8 + 4);
    }
    f0 = D_003BDCB0.e[self->base.phase].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001B0540(self);
    func_001B7EE0(self, 2.5f);
}

#define COLL_NODE_FLAGS_MASK  0x203
#define COLL_NODE_FLAGS_LIVE  0x3

typedef struct CollOwner {
    char unk00[0xC0];
    float *pos;                         /* 0xC0 */
} CollOwner;

typedef struct CollNode {
    unsigned int flags;                 /* 0x00 */
    struct CollNode *next;              /* 0x04 */
    char unk08[4];
    unsigned char kind;                 /* 0x0C */
    char unk0D[3];
    int bit;                            /* 0x10 layer bit number */
    char unk14[0x20];
    CollOwner *owner;                   /* 0x34 */
} CollNode;

typedef struct cCollisionManager {
    char unk00[0x10];
    CollNode *head;                     /* 0x10 */
    char unk14[8];
    unsigned int mask[16];              /* 0x1C per layer bit set of nodes that count */
} cCollisionManager;

/* First live node of the layer's kind-opposite group whose owner lies within `radius` of pos, or 0. */
__attribute__((section(".text.cCollisionManager_checkNearCollision")))
CollNode *cCollisionManager_checkNearCollision(cCollisionManager *self, int layer, float *pos, float radius)
{
    float v[4] __attribute__((aligned(16)));
    float d[4] __attribute__((aligned(16)));
    float e[4] __attribute__((aligned(16)));
    float r2;
    int want;
    CollNode *node;
    int ok;
    float *ownerPos;
    float *copyDst;

    r2 = radius * radius;
    want = func_002B8A30(self, layer);
    VU0_SQC2_VF0(v, 0);
    for (node = self->head; node != 0; node = node->next) {
        ok = ((node->flags & COLL_NODE_FLAGS_MASK) == COLL_NODE_FLAGS_LIVE);
        if (ok != 1) continue;
        if (node->kind == want) continue;
        if ((self->mask[layer] & (1 << node->bit)) == 0) continue;
        ownerPos = node->owner->pos;
        VU0_SQC2_VF0(v, 0x20);
        VU0_LQC2(4, ownerPos, 0);
        copyDst = d;
        VU0_LQC2(5, pos, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, v, 0x20);
        do { VU0_LQC2(4, e, 0); } while (0);
        VU0_SQC2(4, v, 0x10);
        if (v != copyDst) {
            v[0] = d[0];
            v[1] = d[1];
            v[2] = d[2];
        }
        if (capVu0LengthSq(v) < r2) return node;
    }
    return 0;
}

#define OBJ_FLAG_HOLD    0x2            /* objFlags bit 1 */
#define STATE_FLAG_ON    0x1            /* stateFlags bit 0 */
#define PHASE_RELEASED   6
#define PHASE_HELD       7
#define HELD_TIMER       0x12C

typedef struct FollowObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0xED0];
    int stateFlags;                     /* 0x14B0 */
    int timer;                          /* 0x14B4 */
} FollowObj;

/* Snap the object to the player's position, then enter phase 7 (held, with a timer) when mode is 1 and phase 6 (released) otherwise. */
__attribute__((section(".text.FollowObj_snapToPlayer")))
void FollowObj_snapToPlayer(FollowObj *self, int mode)
{
    cVec_copy3(self->base.pos, Getplayer()->pos);
    cVec_copy3(&self->base.posA, self->base.pos);
    cVec_copy3(&self->base.rot, &Getplayer()->rot);
    cModel_calcParts(self);
    switch (mode) {
    default:
    case 0:
        self->timer = 0;
        self->base.phase = PHASE_RELEASED;
        self->stateFlags &= ~STATE_FLAG_ON;
        break;
    case 1:
        self->base.phase = PHASE_HELD;
        self->timer = HELD_TIMER;
        self->base.objFlags &= 0xFFFFFFFD;
        self->stateFlags |= STATE_FLAG_ON;
        /* phase is stored a second time: this order is what matches (found by the permuter) */
        self->base.phase = PHASE_HELD;
        break;
    }
    self->base.step = 0;
    self->base.stepArg = 0;
    self->base.mode = 0;
}
