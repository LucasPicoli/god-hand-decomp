#include "godhand/cDamageGive.h"

__attribute__((section(".text.SetObjTargetAndActivate_1FD2C0")))
int SetObjTargetAndActivate_1FD2C0(cDamageGive *self, int kind, struct cGameObj *owner)
{
    if (self->type == 0)
        return 1;
    self->attacker = 0;
    self->owner = owner;
    func_001FD988((cDamageUnit *)self, kind);
    self->live = 1;
    return 1;
}
