#include "godhand/cDamageGive.h"

__attribute__((section(".text.func_001FCDB8")))
void func_001FCDB8(cDamageGive *self)
{
    ActorRec_reset((cDamageUnit *)self);
    self->attacker = 0;
    self->type = 1;
}
