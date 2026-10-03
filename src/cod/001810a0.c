/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cEvent.h"
#include "godhand/cDataManager.h"
#include "godhand/cDvd.h"

extern int cOmBase_checkDamage(cOmBase *self, int take);
extern unsigned char D_005E8640[];
extern void cRelSys_unlinkNoFree(void *a0, int a1);
extern void cHeap_free(int heap, int *node);
extern void func_00297660(cEvent *self);
extern void func_001FF3A0(cDataSlot *slot);
extern float fRand1_1(void);

/* Hit reaction: when the damage check reports a hit, go to state 2 and mark the object active. */


typedef struct cOmHitReact {
    cOmBase base;
    char unk5E0[0x20];
    int damageTake;                     /* 0x600 hit record handed to cOmBase_checkDamage */
} cOmHitReact;



__attribute__((section(".text.func_001BFC88")))
void func_001BFC88(cOmHitReact *self)
{
    if (cOmBase_checkDamage(&self->base, self->damageTake) == 1) {
        int flags = self->base.flags0;
        self->base.mode = 2;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
        self->base.flags0 = flags | COMBASE_F0_ACTIVE;
    }
}

/* Close the cutscene record: unlink the display text if linked, free the cutscene data, return to idle. */







__attribute__((section(".text.func_002962F0")))
void func_002962F0(cEvent *self)
{
    unsigned long b = *(unsigned char *)&self->flags;
    int *node;
    if (b >> 7)
        cRelSys_unlinkNoFree(D_005E8640, 2);
    node = (int *)self->resData;
    if (node != 0)
        cHeap_free(node[-8], node);
    self->resData = 0;
    func_00297660(self);
}

/* Try to retire an unused slot. Returns 1 when the slot is in use or was retired, 0 when it is pinned, flagged to stay, or not retirable yet. */


#define CDATA_FLAG_KEEP_BIT  1          /* bit number in flags: the slot may not be retired */




__attribute__((section(".text.func_001FF338")))
int func_001FF338(cDataSlot *slot)
{
    unsigned long f;
    unsigned long bit;
    if (slot->useCount < 0)
        return 0;
    if (slot->useCount > 0)
        return 1;
    f = slot->flags;
    bit = (f >> CDATA_FLAG_KEEP_BIT) & 1;
    if (bit)
        return 0;
    if (func_001FF638(slot) == 0)
        return 0;
    func_001FF3A0(slot);
    return 1;
}

/* Call virtual method 16 (the lock-on hook) of an object that has a linked partner, unless it is hidden. */
typedef struct LinkVtEnt {
    short delta;                        /* this adjust */
    short index;
    void *pfn;
} LinkVtEnt;

typedef struct LinkPartner {
    char unk00[0x250];
    unsigned int objFlags;              /* 0x250 */
} LinkPartner;

typedef struct LinkObj {
    char unk00[0xF0];
    LinkVtEnt *vt;                      /* 0xF0 */
    char unkF4[0x20];
    LinkPartner *partner;               /* 0x114 */
    char unk118[4];
    int flags;                          /* 0x11C */
} LinkObj;

#define LINKOBJ_F_SKIP      0x800000    /* flags bit 23: no hook call */
#define LINKOBJ_F_VISIBLE_BIT 7         /* flags bit 7 */
#define LINKPARTNER_F_HIDE  0x2         /* objFlags bit 1 */
#define LINKVT_HOOK         16          /* vtable entry 16, byte offset 0x80 */

__attribute__((section(".text.func_002FEB18")))
void func_002FEB18(LinkObj *self)
{
    unsigned long f = self->flags;
    unsigned long bit;
    LinkVtEnt *vt;
    if (f & LINKOBJ_F_SKIP)
        return;
    if (self->partner != 0) {
        if (self->partner->objFlags & LINKPARTNER_F_HIDE) {
            bit = (f >> LINKOBJ_F_VISIBLE_BIT) & 1;
            if (bit == 0)
                return;
        }
    }
    vt = self->vt;
    ((void (*)(void *))vt[LINKVT_HOOK].pfn)((char *)self + vt[LINKVT_HOOK].delta);
}

/* Poll the running read: status 1 or 3 means it ended, so free its slot and start the next job; status 2 means keep waiting. */




__attribute__((section(".text.func_00201718")))
void func_00201718(cDvd *self)
{
    switch (func_002018D0(self)) {
    case 1:
    case 3:
        FreeObjectSlot_2018F0(self);
        self->queueNum = 1;
        func_00201290(self);
        break;
    case 2:
        break;
    }
}

/* Shake the object's height: count the timer down and jitter its y by a small random amount, then restore the rest height when it runs out. */


#define OMSHAKE_JITTER  0.015f

typedef struct cOmShake {
    cOmBase base;
    char unk5E0[0x20];
    short timer;                        /* 0x600 frames of shake left */
    char unk602[2];
    float restY;                        /* 0x604 height to return to */
} cOmShake;



__attribute__((section(".text.func_001810A0")))
void func_001810A0(cOmShake *self)
{
    if (self->timer > 0) {
        self->timer--;
        if (self->timer != 0)
            self->base.pos->y = self->restY + fRand1_1() * OMSHAKE_JITTER;
        else
            self->base.pos->y = self->restY;
    }
}
