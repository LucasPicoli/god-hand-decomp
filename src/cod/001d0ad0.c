/* func_001D0AD0 — set the float field at 0x66C to 450.0. */
#include "godhand/cOmWeapon.h"

/* Set the 0x66C float to 450.0. */
__attribute__((section(".text.func_001D0AD0")))
void func_001D0AD0(cOmWeapon *self) {
    self->unk66C = 450.0f;
}
