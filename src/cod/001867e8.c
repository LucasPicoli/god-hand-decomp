/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"

extern int ClearField5B4IfFlagUnset_1B76B0(void *obj);
extern void func_002A87E8(void *obj, int arg);
extern void func_001B76D8(void *obj);
extern int cOmWeapon_setParent();
extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *unit, void *mtx, float *pos, float *dir, float *box);
extern void cOmDoor_setObjCollision(void *self);
extern int D_00574380;

/* sn-2.95.3-136 */






/* Mode tick: dispatch the handler named by the object's mode, then sync. An entry with a non-negative index takes the handler from a method table found through the object; a negative one holds it inline. */
#define MODE_NUM  4

typedef struct ModeEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler inline at +4 */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} ModeEnt;

typedef struct { char b[0x20]; } ModeTbl;
extern ModeTbl D_004236E0;              /* the four entries */

__attribute__((section(".text.cOmBase_tickModeTableB")))
void cOmBase_tickModeTableB(cOmBase *self) {
    ModeEnt tbl[MODE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    *(ModeTbl *)tbl = D_004236E0;
    i8 = self->mode * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)self + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[self->mode].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)self + arg));
    func_002A87E8(self, 0);
    func_001B76D8(self);
}

/* sn-2.95.3-136 */
/* Hand a weapon to its holder: pick the grip offset (x, y, z) and rotation (x, y, z) for this enemy kind (two kinds hold it differently) and for the left or right hand, then attach it. Does nothing without a weapon. */



#define EM_KIND_LEFTY_A    0x225
#define EM_KIND_LEFTY_B    0x24D
#define GRIP_RIGHT         0xA
#define GRIP_LEFT          0x10

typedef struct GripBuf {
    float ofs[3];                       /* 0x00 grip offset */
    float pad0C;
    float rot[3];                       /* 0x10 grip rotation */
    float pad1C;
} GripBuf;



__attribute__((section(".text.cOmBase_attachWeaponGripB")))
void cOmBase_attachWeaponGripB(cOmBase *self, void *weapon, int left)
{
    GripBuf grip;
    int idx;
    float mirror, turn;

    if (weapon == 0)
        return;
    VU0_SQC2_VF0(&grip, 0x0);
    VU0_SQC2_VF0(&grip, 0x10);
    if (self->actionId != EM_KIND_LEFTY_A && self->actionId != EM_KIND_LEFTY_B) {
        idx = GRIP_RIGHT;
        grip.ofs[0] = -0.28f;
        grip.ofs[1] = -0.035f;
        grip.ofs[2] = 0.185f;
        grip.rot[1] = -0.78539819f;
        *(int *)&grip.rot[0] = 0;
        *(int *)&grip.rot[2] = 0;
        if (left) {
            mirror = 0.28f;
            idx = GRIP_LEFT;
            turn = 0.78539819f;
            grip.ofs[0] = mirror;
            grip.rot[1] = turn;
        }
    } else {
        mirror = -0.08f;
        idx = GRIP_RIGHT;
        turn = -0.03f;
        grip.ofs[0] = mirror;
        grip.ofs[1] = turn;
        *(int *)&grip.ofs[2] = 0;
        *(int *)&grip.rot[0] = 0;
        *(int *)&grip.rot[1] = 0;
        *(int *)&grip.rot[2] = 0;
        if (left) {
            mirror = 0.08f;
            idx = GRIP_LEFT;
            turn = 3.1415927f;
            grip.ofs[0] = mirror;
            grip.rot[2] = turn;
        }
    }
    cOmWeapon_setParent(weapon, self, idx, &grip, &grip.rot[0]);
}

/* sn-2.95.3-136 */









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

__attribute__((section(".text.DoorBox_initWithBoxA")))
int DoorBox_initWithBoxA(DoorLikeObj *self) {
    float f[16];
    float *t;
    float *m;
    float *nv;
    void *slot;
    char *rec;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.5f;
    cb = 2.4f;
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

/* sn-2.95.3-136 */



extern char D_005CAE50[];           /* collision list */
extern char D_004293C0[];           /* six unit vectors of the door box */

/* A door-like object past cOmBase with its box size at 0x600 and the collision handle at 0x77C. */
typedef struct DoorBoxHost {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    float size[3];                      /* 0x600 */
    char unk60C[0x77C - 0x60C];
    int collision;                      /* 0x77C collision handle */
} DoorBoxHost;

typedef struct { char b[0x60]; } cDoorBoxAxes;
typedef struct { cVec v[6]; } cDoorBoxVecs;

static __inline__ void door_vec(cVec *v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

/* Register the door's solid box with the collision list: the box centre
 * is the door size plus a margin, the half extents are half the height,
 * and the axes are copied from the shared table. */
__attribute__((section(".text.cOmDoor_setObjCollisionCenterOnly")))
void cOmDoor_setObjCollisionCenterOnly(DoorBoxHost *self) {
    cVec center;
    cVec half;
    cVec zero;
    float *mtx;
    cDoorBoxVecs ax;
    float sx = self->size[0];
    float sy = self->size[1];

    door_vec(&center, sx, sy, self->size[2], 1.0f);
    VU0_VADDX_XYZ_MEM(&center, 0, 0.1f);
    door_vec(&half, 0, sy * 0.5f, 0, 1.0f);
    door_vec(&zero, 0, 0, 0, 1.0f);
    *(cDoorBoxAxes *)&ax = *(cDoorBoxAxes *)D_004293C0;
    mtx = self->base.mtx;
    self->collision = func_0012EAD8(D_005CAE50, self, mtx, &half, &zero,
                                    &center, &ax.v[0], &ax.v[1], &ax.v[2], &ax.v[3],
                                    &ax.v[4], &ax.v[5]);
}

/* sn-2.95.3-136 */




#define EM_HIT_FLASH_FULL  3.0f
#define EM_FADE_STEP       0.1f

/* Phase 0: flash the body and enter phase 1. Phase 1: slow the animation to a stop, then release the enemy. */
__attribute__((section(".text.cEm00_stepFadeOutAndReleaseNoStart")))
void cEm00_stepFadeOutAndReleaseNoStart(cEm00 *self) {
    cEm00 *em;
    unsigned char one = 1;
    self->hitFlash = EM_HIT_FLASH_FULL;
    switch (self->step) {
    case 0:
        /* the empty loop wrapper moves the step byte's register: retail keeps the compare constant in $v0 */
        do { self->step = one; } while (0);
    case 1:
        self->tint.w = self->tint.w - EM_FADE_STEP;
        em = self;
        if (em->tint.w <= 0.0f) {
            em->tint.w = 0.0f;
            cEmManage_ReleaseEm(&D_005864F0, (cEmActor *)self);
            self->step = self->step + 1;
        }
        break;
    }
}
