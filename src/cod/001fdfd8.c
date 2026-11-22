#include "godhand/cDamageManage.h"

extern void Trail_snapToSources(void *a0);
extern void FlashDriver_resetFlash(void *a0);
extern void func_001FCF20(void *a0);
extern void cDamageUnit_UpdateDamageCollFlash(void *a0);
extern void NoOp_1FD528(void *a0);

__attribute__((section(".text.func_001FDFD8")))
void func_001FDFD8(cDamageManage *self)
{
    cDamageGive *d;
    cDamageTake *f;
    unsigned int i;

    if (self->hitStop != 0) {
        self->hitStop--;
        return;
    }
    d = self->give;
    do {
        if (d->live) Trail_snapToSources(d);
        d++;
    } while (d < self->give + CDAMAGE_GIVE_MAX);
    i = 0;
    f = self->take;
    do {
        if (f->live) FlashDriver_resetFlash(f);
        i++;
        f++;
    } while (i < CDAMAGE_TAKE_MAX);
    d = self->give;
    do {
        if (d->live) {
            func_001FCF20(d);
            cDamageUnit_UpdateDamageCollFlash(d);
        }
        d++;
    } while (d < self->give + CDAMAGE_GIVE_MAX);
    f = self->take;
    i = 0;
    do {
        if (f->live) {
            NoOp_1FD528(f);
            cDamageUnit_UpdateDamageCollFlash(f);
        }
        i++;
        f++;
    } while (i < CDAMAGE_TAKE_MAX);
}
