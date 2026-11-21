/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/cDamageManage.h"

extern void func_001B6FB8(void *self);
extern void cOmDoor_setObjCollision(void *self);

/* Set up a door-like object: 1 life, a 2.13 by 3.78 by 0.2 hit box through the damage manager, the box size kept at 0x610, its collision object and the second body at 0x650. */
#define DOORBOX_RING_OFFSET  0x650      /* second body inside the object */

typedef struct DoorBoxObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damage;                       /* 0x600 */
    char unk604[0xC];
    float size[3];                      /* 0x610 */
    char unk61C[8];
    unsigned char hasBody;              /* 0x624 */
    char unk625[3];
    void *body;                         /* 0x628 */
} DoorBoxObj;

#define COMBASE_F2_BIT1  0x2            /* flags2 bit 1 */

__attribute__((section(".text.DoorBoxObj_constructWide")))
int DoorBoxObj_constructWide(DoorBoxObj *self)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;
    int hp;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 2.13f;
    cb = 3.78f;
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
    f[8] = f[0] * -0.5f;
    *(int *)&f[9] = 0;
    *(int *)&f[10] = 0;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damage = slot;
    if (slot != 0) {
        nv = &f[12];
        *(int *)&f[12] = 0;
        *(int *)&f[13] = 0;
        *(int *)&f[14] = 0;
        nv[3] = one;
        func_001FD9D8(slot, (const struct cMatrix *)((char *)self + 0x80), (const cVec *)m, (const cVec *)nv, (const cVec *)t);
    }
    hp = 1;
    self->base.hpMax = hp;
    self->base.hp = hp;
    cVec_copy3((cVec *)self->size, (cVec *)f);
    cOmDoor_setObjCollision(self);
    self->hasBody = hp;
    self->body = (char *)self + DOORBOX_RING_OFFSET;
    func_001BBF68(self);
    self->base.flags2 |= COMBASE_F2_BIT1;
    return 1;
}
