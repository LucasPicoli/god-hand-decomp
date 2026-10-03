/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/Slot2.h"
#include "godhand/vu0.h"

extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *unit, void *mtx, float *pos, float *dir, float *box);
extern void cOmDoor_setObjCollision(void *self);
extern int D_00574380;
extern void cSnd_SeCall_2CB8A0(char *snd, int a1, int a2, int a3, int t0, int t1, int t2);
extern void func_001F6A80(void *self);
extern void func_001F6AF8(void *self);
extern char D_005FEE00[];
extern char D_007474A0[];
extern char D_00585040[];
extern char D_005850B0[];
extern void displayScrollLayer(int id, int on);
extern float sceVu0Normalize(void *dst, void *src);
extern float sceVu0InnerProduct(void *a, void *b);
extern float capVu0Acos(float x);

/* Set up the door-like object: 1 life, a hit cylinder through the damage manager, the collision box copied from the
 * stack record, solid collision and the hit sub-record. */


#define OBJ_LIFE      1
#define OBJ_SOLID_ID  7                 /* value of the solid-collision byte */








/* The object past cOmBase: damage unit, collision box, solid byte and hit record. */
typedef struct DoorLikeObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damage;                       /* 0x600 */
    char unk604[0xC];
    cVec box;                           /* 0x610 collision box size, xyz */
    char unk620[4];
    unsigned char solid;                /* 0x624 */
    char unk625[3];
    void *hitRec;                       /* 0x628 */
    char unk62C[0x24];
    char hitRecData[0x20];              /* 0x650 */
} DoorLikeObj;

__attribute__((section(".text.func_00191DE8")))
int func_00191DE8(DoorLikeObj *self) {
    float f[16];
    float *t;
    float *m;
    float *nv;
    void *slot;
    char *rec;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.449f;
    cb = 2.4318f;
    cc = 0.2f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[4] = ca;
    f[1] = cb;
    f[2] = cc;
    f[6] = cc;
    f[5] = cb;
    f[3] = one;
    t[3] = one;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[8] = f[0] * -0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damage = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
    }
    self->base.hpMax = OBJ_LIFE;
    self->base.hp = OBJ_LIFE;
    cVec_copy3(&self->box, (cVec *)f);
    cOmDoor_setObjCollision(self);
    self->hitRec = self->hitRecData;
    self->solid = OBJ_SOLID_ID;
    func_001BBF68(self);
    return 1;
}

/* Menu input step: read the pad's pressed buttons and move the menu. A back button leaves for state 2 (sound 0x160); the two 0x2000000 / 0x1000000 buttons enter state 1 at entry 0 or 5; the two shoulder buttons page with func_001F6A80 / func_001F6AF8. Every move plays sound 0x15F. */

/* The menu object: four state bytes, then the selected entry. */
typedef struct MenuInput {
    unsigned char state;                /* 0x00 */
    unsigned char mode;                 /* 0x01 */
    unsigned char step;                 /* 0x02 */
    unsigned char stepArg;              /* 0x03 */
    char unk04[0x1C];
    int entry;                          /* 0x20 */
} MenuInput;






#define PAD_OFFSET_HOLD   0x1A0
#define PAD_OFFSET_PRESS  0x1B0
#define PAD_BACK          0x30000000
#define PAD_FIRST         0x2000000
#define PAD_LAST          0x1000000
#define PAD_PAGE_PREV     0x1000000000
#define PAD_PAGE_NEXT     0x10000000000
#define MENU_SE_MOVE      0x15F
#define MENU_SE_BACK      0x160

__attribute__((section(".text.func_001F6520")))
void func_001F6520(void *a0)
{
    MenuInput *s0 = (MenuInput *)a0;
    char *pad = D_007474A0;
    long b;

    if (*(long *)(pad + PAD_OFFSET_HOLD) & PAD_BACK) {
        s0->mode = 0;
        s0->step = 0;
        s0->state = 2;
        s0->stepArg = 0;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
        return;
    }
    b = *(long *)(pad + PAD_OFFSET_PRESS);
    if (b & PAD_FIRST) {
        s0->mode = 1;
        s0->entry = 0;
        s0->step = 0;
        s0->stepArg = 0;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    } else if (b & PAD_LAST) {
        s0->entry = 5;
        s0->mode = 1;
        s0->step = 0;
        s0->stepArg = 0;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    } else if (b & PAD_PAGE_PREV) {
        func_001F6A80(s0);
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    } else if (b & PAD_PAGE_NEXT) {
        func_001F6AF8(s0);
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    }
}

/* Fill the seven-entry vector table D_00585040 with (x, 0, z, 1) points and reset the vector D_005850B0 to (0, 0, 0, 1). Runs only for the init code 0xFFFF and a non-null owner. */



typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

__attribute__((section(".text.func_00276618")))
void func_00276618(void *a0, int a1)
{
    Vec4 *pa;
    Vec4 *org;

    if (a1 != 0xFFFF) return;
    if (a0 == 0) return;

    pa = (Vec4 *)D_00585040;
    org = (Vec4 *)D_005850B0;

    pa->x = -1.157f;
    pa->y = 0.0f;
    pa->z = -21.0f;
    pa->w = 1.0f;
    pa++;
    pa->x = -0.121f;
    pa->y = 0.0f;
    pa->z = -3.74f;
    pa->w = 1.0f;
    pa++;
    pa->x = -4.199f;
    pa->y = 0.0f;
    pa->z = -10.703f;
    pa->w = 1.0f;
    pa++;
    pa->x = -4.834f;
    pa->y = 0.0f;
    pa->z = -10.53f;
    pa->w = 1.0f;
    pa++;
    pa->x = -0.943f;
    pa->y = 0.0f;
    pa->z = -37.747f;
    pa->w = 1.0f;
    pa++;
    pa->x = -5.98f;
    pa->y = 0.0f;
    pa->z = -32.094f;
    pa->w = 1.0f;
    pa++;
    pa->x = -4.968f;
    pa->y = 0.0f;
    pa->z = -31.884f;
    pa->w = 1.0f;
    org->x = 0.0f;
    org->y = 0.0f;
    org->z = 0.0f;
    org->w = 1.0f;
}

/* Blink counter of the five mark layers: once armed (bit 15), count frames; after 8 frames rewrite the blink word (flip bit 14, keep the select bits 11 to 13) and show the select-th layer on or off with the on bit, or hide all five. */


#define SLOT2_OFFSET_BLINK2   0x3E8     /* blink word, not named in Slot2.h */
#define SLOT2_OFFSET_MARKS    0x3A0     /* layer ids, not named in Slot2.h */
#define BLINK_ARMED    0x8000
#define BLINK_ON       0x4000
#define BLINK_SELECT   0x3800
#define BLINK_COUNT    0x3FF
#define BLINK_DELAY    8
#define MARK_NUM       5

typedef struct { int w[MARK_NUM]; } MarkTbl;

extern MarkTbl D_0042BAF0;              /* layer index of each mark */


__attribute__((section(".text.func_001E6FE8")))
void func_001E6FE8(Slot2 *self)
{
    unsigned short *blink = (unsigned short *)((char *)self + SLOT2_OFFSET_BLINK2);
    unsigned int v = *blink;
    MarkTbl tbl;
    unsigned short w;
    int sel;
    int i;
    int *p;
    char *layers;

    if (v & BLINK_ARMED) {
        v = v + 1;
        *blink = v;
        if ((v & BLINK_COUNT) >= BLINK_DELAY) {
            w = (~v & BLINK_ON) | (v & BLINK_SELECT) | BLINK_ARMED;
            tbl = D_0042BAF0;
            sel = (w >> 11) & 7;
            *blink = w;
            if (w & BLINK_ON) {
                layers = (char *)self + SLOT2_OFFSET_MARKS;
                i = 0;
                p = tbl.w;
                for (; i < MARK_NUM; i++) {
                    displayScrollLayer(*(int *)(layers + (*p << 2)), i == sel);
                    p++;
                }
            } else {
                layers = (char *)self + SLOT2_OFFSET_MARKS;
                p = tbl.w;
                for (i = MARK_NUM - 1; i >= 0; i--) {
                    displayScrollLayer(*(int *)(layers + (*p << 2)), 0);
                    p++;
                }
            }
        }
    }
}

/* Hit test of a point against the shapes of the object's hit set: 0 when there is no set (or it has the wrong version, which drops it), else the first live shape that contains the point decides (1 when its 0x2C word is set), else the set's default answer. */
#define HITSET_VERSION  1.1f
#define HITSET_OFFSET_NODE  0x20        /* first shape; the last one is node[num - 1] */

typedef struct HitNode {
    char unk00[0x28];
    unsigned char unk28;
    unsigned char flags;                /* 0x29 */
    char unk2A[2];
    int result;                         /* 0x2C answer when the point is inside */
    char unk30[4];
    int disabled;                       /* 0x34 nonzero: skip this shape */
} HitNode;                              /* 0x38 */

typedef struct HitSet {
    char unk00[4];
    float version;                      /* 0x04 */
    unsigned char num;                  /* 0x08 shapes */
    signed char deflt;                  /* 0x09 default answer */
    char unk0A[0x16];
    HitNode node[1];                    /* 0x20 */
} HitSet;

typedef struct HitHost {
    char unk00[0x20];
    HitSet *set;                        /* 0x20 */
} HitHost;



__attribute__((section(".text.func_002CAE10")))
int func_002CAE10(HitHost *self, float *pos)
{
    float vec[4];
    HitSet *set = self->set;
    HitNode *node;
    char *end;
    int dflt;
    int i;

    if (set == 0)
        return 0;
    if (set->version != HITSET_VERSION) {
        self->set = 0;
        return 0;
    }
    dflt = set->deflt != 0;
    if (set->num == 0)
        return dflt;
    vec[0] = pos[0];
    vec[1] = pos[1];
    vec[2] = pos[2];
    vec[3] = 1.0f;
    i = 0;
    end = (char *)set + set->num * sizeof(HitNode);
    node = (HitNode *)(end - (sizeof(HitNode) - HITSET_OFFSET_NODE));
    if (i < set->num) {
        do {
            if (node->disabled == 0) {
                if (func_002C0A98(node, vec, 1) != 0)
                    return node->result != 0;
            }
            i++;
            node--;
        } while (i < self->set->num);
    }
    return dflt;
}

/* Turn angle toward a target on a path piece: when the piece (record at +0x30, kind byte 0x3F) is kind 1, take its direction vector (0x50), subtract the reference point, flatten it, and measure the angle between it and the flattened target direction. Writes the signed angle times the path blend to *turn and the interpolated height to *height. */



typedef struct PathRec {
    char unk00[0x38];
    float endY;                         /* 0x38 */
    char unk3C[3];
    unsigned char kind;                 /* 0x3F */
    char unk40[0x10];
    char dir[0x10];                     /* 0x50 direction vector, copied as a blob */
} PathRec;

typedef struct PathHost {
    char unk00[0x10];
    float startY;                       /* 0x10 */
    char unk14[0x1C];
    PathRec *rec;                       /* 0x30 */
} PathHost;

typedef struct Blob16 {
    char b[0x10];
} Blob16;

#define PATH_KIND_CURVE  1




extern float func_00137E70(PathHost *self, void *a, void *b);

#define FR(off) ((cVec *)(fr + (off)))

__attribute__((section(".text.func_00137CB8")))
void func_00137CB8(PathHost *self, float *turn, float *height, cVec *ref, cVec *target)
{
    char fr[0x40] __attribute__((aligned(16)));
    PathRec *rec = self->rec;
    unsigned char kind = rec->kind;
    cVec *dirB;
    cVec *tmp;
    cVec *delta;
    int left;
    float ang;
    float blend;

    if (kind != PATH_KIND_CURVE)
        return;
    VU0_SQC2_VF0(fr, 0x0);
    VU0_SQC2_VF0(fr, 0x10);
    *(Blob16 *)fr = *(Blob16 *)rec->dir;
    tmp = FR(0x20);
    left = 0;
    VU0_SQC2_VF0(fr, 0x30);
    VU0_LQC2(4, fr, 0x0);
    VU0_LQC2(5, ref, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, fr, 0x30);
    delta = FR(0x30);
    VU0_LQC2(4, delta, 0);
    VU0_SQC2(4, fr, 0x20);
    cVec_copy3(FR(0x0), FR(0x20));
    dirB = FR(0x10);
    cVec_copy3(FR(0x10), FR(0x0));
    if (0.0f < FR(0x10)->y)
        left = 1;
    FR(0x10)->y = 0.0f;
    sceVu0Normalize(FR(0x0), FR(0x0));
    sceVu0Normalize(dirB, dirB);
    ang = capVu0Acos(sceVu0InnerProduct(FR(0x0), dirB));
    VU0_LQC2(4, dirB, 0);
    VU0_SQC2(4, fr, 0x20);
    VU0_LQC2(4, target, 0);
    VU0_SQC2(4, fr, 0x30);
    blend = func_00137E70(self, tmp, delta);
    if (left == kind)
        *turn = -ang * blend;
    else
        *turn = ang * blend;
    *height = (rec->endY - self->startY) * blend + self->startY;
}
