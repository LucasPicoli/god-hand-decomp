/* sn-2.95.3-136 matched TU. */

#include "godhand/menuCtl.h"
#include "godhand/cObjPtrArrayWrapper.h"
#include "godhand/SndSlotInit.h"
#include "godhand/sync.h"

extern volatile int D_00753D88;
extern int D_00747A18;
extern char D_005FEE00[];
extern void func_002CA690(char *a0);

/* Once the current slot's stream header is in, read its format into the slot info and rebuild the page. */
__attribute__((section(".text.MenuCtl_readSlotStreamInfo")))
void MenuCtl_readSlotStreamInfo(MenuCtl *ctl)
{
    MenuSlot *slot = &ctl->slot[ctl->slotNo];
    MenuInfo *info = &slot->info;

    if (GuardedCall_00329FD0_329F98(info->handle) < 2) {
        return;
    }
    info->f00 = func_0032A4A8(info->handle);
    info->f04 = func_0032A530(info->handle);
    info->f08 = func_0032A5B8(info->handle);
    info->f0C = func_0032A648(info->handle);
    func_00380EB0(ctl, info, (MenuList *)slot);
    ctl->state = 1;
}

/* Append value when the wrapper's length is still below its capacity; return the new element, or 0 when full. */
__attribute__((section(".text.cObjPtrArrayWrapper_pushBack")))
int *cObjPtrArrayWrapper_pushBack(cObjPtrArrayWrapperObj *self, int value)
{
    int local;
    unsigned int size;
    unsigned int cap;
    cPtrVec *v;
    cPtrVec *capVec;
    int *vp;

    local = value;
    size = self->vec ? (self->vec->finish - self->vec->begin) : 0;
    capVec = self->vec;
    if (capVec) {
        int *b = capVec->begin;
        cap = capVec->capEnd - b;
    } else {
        cap = 0;
    }
    if (!(size < cap))
        return 0;
    vp = &local;
    v = self->vec;
    if (v->finish != v->capEnd) {
        if (v->finish != 0)
            *v->finish = local;
        v->finish = v->finish + 1;
    } else {
        func_00317FF0(v, v->finish, vp);
    }
    return self->vec->finish - 1;
}

/* Start a sound slot from a descriptor: claim a slot, copy the descriptor, derive the two channel gains and load the script cursor from the bank; -1 when no slot is free. */
__attribute__((section(".text.SndSlot_startFromDesc")))
int SndSlot_startFromDesc(SndDesc *d)
{
    SndSlotHead *s;
    char *base;
    int *tbl;
    unsigned short pitch;
    unsigned short volL;
    char *p;

    s = FindSlotEntry_376A10((SndDesc *)&d->bank);
    if (s == 0)
        return SNDSLOT_ERR_FULL;
    s->state = SNDSLOT_LIVE;
    s->id = d->id;
    s->bank = d->bank;
    s->prog = d->prog;
    s->idx = d->idx;
    s->vol = d->vol;
    s->pan = d->pan;
    s->prio = d->prio;
    s->unk12 = 0;
    s->flagsA = d->flagsA;
    s->flagsB = d->flagsB;
    pitch = d->pitch;
    s->pitch = pitch;
    s->unk1A = 0;
    s->unk1C = 0;
    s->unk1E = 0;
    volL = d->volL;
    s->volL = volL;
    s->volR = d->volR;
    s->gainL = func_003780B0(volL, pitch);
    s->gainR = func_003780B0(s->volR, s->pitch);
    s->fadeIn = d->fadeIn;
    s->fadeOut = d->fadeOut;
    base = D_0076EA50[s->bank].tbl3;
    /* int arithmetic: with a pointer operand gcc normalises the addu operand order, retail has index first */
    tbl = (int *)(((int)s->idx << 2) + (int)base);
    p = base + *tbl;
    s->seq = p;
    s->pc = p;
    s->seqEnd = p;
    s->wait = *(int *)p;
    s->kind = p[4];
    s->sub = p[5];
    func_003761D0(s);
    return 0;
}

#define EE_INTC_MASK  ((volatile unsigned int *)0x10000010)
#define INTC_VBLANK_START_MASK  0x400   /* VBLANK start enable bit of the INTC mask */

/* Count the call, flush the sound state when the mode word is 1, then unmask the INTC bit and enable interrupts; returns 0. */
__attribute__((section(".text.IntrCtl_enableVblankStart")))
int IntrCtl_enableVblankStart(void)
{
    D_00753D88++;
    if ((D_00747A18 ^ 1) == 0)
        func_002CA690(D_005FEE00);
    *EE_INTC_MASK |= INTC_VBLANK_START_MASK;
    GH_SYNC();
    GH_EI();
    return 0;
}
