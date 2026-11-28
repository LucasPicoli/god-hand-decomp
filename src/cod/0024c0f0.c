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
extern int cEm00_stepFadeIn(void *a0);
extern void func_00276478(void *a0);
extern void func_002A87E8(void *a0, int a1);

__attribute__((section(".text.func_0024C0F0")))
void func_0024C0F0(cEm00 *self)
{
    short idx;
    Pfn fn;
    cVtEnt8 e;

    self->unk1864 = 0;
    if (self->step == 0) {
        self->emFlags = (self->emFlags | 2) & ~0x8000;
        EmThrower_throwHeld((cEm00 *)self, 0, 0);
        EmThrower_throwHeld((cEm00 *)self, 1, 0);
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
        if (self->emFlags2 & 0x20) {
            KillEffect(self, 1, 2);
            self->emFlags2 &= ~0x20;
        }
        if (self->gotoEffect != 0) {
            func_001D0408(self->gotoEffect);
            self->gotoEffect = 0;
        }
        if (self->phase != 8) {
            self->hitCount = 0;
        }
        if (self->weapon366 != 0) {
            Obj1D00_ClearState_6(&self->weapon366->base);
        }
        if (self->fx6 != 0) {
            Obj1D00_ClearState_7((cOmBase *)self->fx6);
        }
        if (self->emNo == 0x279) {
            ReleaseField6ECByTag564_26B1E8(self);
        }
        if (self->phase == 2) {
            switch (self->emNo) {
            case 0x260:
            case 0x264:
            case 0x265:
            case 0x26A:
                self->step = 0;
                self->mode = 1;
                self->phase = 1;
                self->stepArg = 0;
                break;
            }
        }
        switch (self->emNo) {
        case 0x260:
        case 0x264:
        case 0x265:
            if (self->phase == 8 && self->hp <= 0) {
                self->mode = 1;
                self->phase = 3;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
        }
    }
    if (self->phase >= 0x28) {
        self->phase = 0;
    }
    idx = D_003BF738[self->phase].index;
    if (idx >= 0) {
        e = (*(cVtEnt8 **)((char *)self + D_003BF738[self->phase].u.delta2))[idx - 1];
        fn = e.pfn;
    } else {
        fn = D_003BF738[self->phase].u.pfn;
    }
    {
        short d = D_003BF738[self->phase].delta;
        int off = idx >= 0 ? e.delta + d : d;

        fn((char *)self + off);
    }
    if (cEm00_stepFadeIn(self) == 0) {
        if (self->emNo == 0x26A) {
            func_00276478(self);
        } else {
            func_002A87E8(self, 0);
        }
    }
}
