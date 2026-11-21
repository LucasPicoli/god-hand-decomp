/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/cDamageManage.h"

extern int ClearField5B4IfFlagUnset_1B76B0(void *obj);
extern void func_002A87E8(void *obj, int arg);
extern void func_001B76D8(void *obj);
extern void func_001B6FB8(void *self);
extern void cOmDoor_setObjCollision(void *self);

/* sn-2.95.3-136 */






/* Mode tick: dispatch the handler named by the object's mode, counting down the short timer at 0x602 first, then sync. An entry with a non-negative index takes the handler from a method table found through the object; a negative one holds it inline. */
#define MODE_NUM  4

typedef struct ModeEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler inline at +4 */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} ModeEnt;

typedef struct { char b[0x20]; } ModeTbl;
extern ModeTbl D_00424308;              /* the four entries */

__attribute__((section(".text.cOmBase_tickModeTableC")))
void cOmBase_tickModeTableC(cOmBase *self) {
    ModeEnt tbl[MODE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    if (*(short *)((char *)self + 0x602) != 0) {
        *(short *)((char *)self + 0x602) = *(unsigned short *)((char *)self + 0x602) - 1;
    }
    *(ModeTbl *)tbl = D_00424308;
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

__attribute__((section(".text.DoorBox_initWithBoxB")))
int DoorBox_initWithBoxB(DoorLikeObj *self) {
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
    f[8] = -f[0] * 0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damage = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, (const struct cMatrix *)self->base.mtx, (const cVec *)m, (const cVec *)nv, (const cVec *)t);
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
