#include "godhand/cModel.h"
#include "godhand/cEm00.h"
typedef void (*Pfn)(void *self);

extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void ClearField630_SetField2F6_1C2318(void *a0);
extern void func_001D0108(void *a0);
extern void cEm_breakHeldWeapons(void *a0);
extern void func_001D0408(void *a0);
extern void Obj1D00_ClearState_6(void *a0);
extern void Obj1D00_ClearState_7(void *a0);
extern void KillEffect(void *a0, int a1, int a2);
extern cPmf D_003BF878[];

__attribute__((section(".text.func_0025E600")))
void func_0025E600(char *self)
{
    short idx;
    Pfn fn;
    cVtEnt8 e;

    EmThrower_throwHeld((cEm00 *)self, 0, 0);
    EmThrower_throwHeld((cEm00 *)self, 1, 0);
    ReleaseField6ECByTag564_26B1E8(self);
    if (*(void **)(self + 0x70C) != 0) {
        ClearField630_SetField2F6_1C2318(*(void **)(self + 0x70C));
        *(void **)(self + 0x70C) = 0;
    }
    if (*(void **)(self + 0x730) != 0) {
        func_001D0108(*(void **)(self + 0x730));
        *(void **)(self + 0x730) = 0;
    }
    cEm_breakHeldWeapons(self);
    if (*(void **)(self + 0x738) != 0) {
        func_001D0408(*(void **)(self + 0x738));
        *(void **)(self + 0x738) = 0;
    }
    if (*(void **)(self + 0x6F0) != 0) {
        Obj1D00_ClearState_6(*(void **)(self + 0x6F0));
    }
    if (*(void **)(self + 0x708) != 0) {
        Obj1D00_ClearState_7(*(void **)(self + 0x708));
    }
    if (*(int *)(self + 0x16D4) & 0x20) {
        KillEffect(self, 1, 2);
        *(unsigned int *)(self + 0x16D4) &= ~0x20;
    }
    *(unsigned char *)(self + 0x1864) = 0;
    if (*(unsigned char *)(self + 0x2F5) >= 5) {
        *(unsigned char *)(self + 0x2F5) = 0;
    }
    idx = D_003BF878[*(unsigned char *)(self + 0x2F5)].index;
    if (idx >= 0) {
        e = (*(cVtEnt8 **)(self + D_003BF878[*(unsigned char *)(self + 0x2F5)].u.delta2))[idx - 1];
        fn = e.pfn;
    } else {
        fn = D_003BF878[*(unsigned char *)(self + 0x2F5)].u.pfn;
    }
    {
        short d = D_003BF878[*(unsigned char *)(self + 0x2F5)].delta;
        int off = idx >= 0 ? e.delta + d : d;

        fn(self + off);
    }
}
