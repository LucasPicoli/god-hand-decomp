#include "godhand/cObjBase.h"

__attribute__((section(".text.func_0012C708")))
void func_0012C708(char *self)
{
    *(int *)(self + 0x5FC) = 0x258;
    SetEffect(0, 0x4E, (cObj *)self, 0, 5, EFFECT_FOLLOW_OWNER);
}
