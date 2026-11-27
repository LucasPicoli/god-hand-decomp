#include "godhand/cModel.h"
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
typedef void (*Pfn)(void *self);

extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void ClearField630_SetField2F6_1C2318(void *a0);
extern void func_001D0108(void *a0);
extern void cEm_breakHeldWeapons(void *a0);
extern void func_001D0408(void *a0);
extern void KillEffect(void *a0, int a1, int a2);

__attribute__((section(".text.func_0025E600")))
void func_0025E600(cEm00 *self)
{
    short idx;
    Pfn fn;
    cVtEnt8 e;

    EmThrower_throwHeld((cEm00 *)self, 0, 0);
    EmThrower_throwHeld((cEm00 *)self, 1, 0);
    ReleaseField6ECByTag564_26B1E8(self);
    if (self->unk70C != 0) {
        ClearField630_SetField2F6_1C2318((void *)self->unk70C);
        self->unk70C = 0;
    }
    if (self->unk730 != 0) {
        func_001D0108((void *)self->unk730);
        self->unk730 = 0;
    }
    cEm_breakHeldWeapons(self);
    if (self->gotoEffect != 0) {
        func_001D0408(self->gotoEffect);
        self->gotoEffect = 0;
    }
    if (self->weapon366 != 0) {
        Obj1D00_ClearState_6(&self->weapon366->base);
    }
    if (self->fx6 != 0) {
        Obj1D00_ClearState_7((cOmBase *)self->fx6);
    }
    if (self->emFlags2 & 0x20) {
        KillEffect(self, 1, 2);
        self->emFlags2 &= ~0x20;
    }
    self->unk1864 = 0;
    if (self->phase >= 5) {
        self->phase = 0;
    }
    idx = D_003BF878[self->phase].index;
    if (idx >= 0) {
        e = (*(cVtEnt8 **)((char *)self + D_003BF878[self->phase].u.delta2))[idx - 1];
        fn = e.pfn;
    } else {
        fn = D_003BF878[self->phase].u.pfn;
    }
    {
        short d = D_003BF878[self->phase].delta;
        int off = idx >= 0 ? e.delta + d : d;

        fn((char *)self + off);
    }
}
