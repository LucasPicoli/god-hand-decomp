/* Trivial accessor. */
#include "godhand/cWorldLight.h"

/* Returns how many lights are in use. */
__attribute__((section(".text.func_002D8FF8")))
int func_002D8FF8(cWorldLight *self) { return self->lightNum; }
