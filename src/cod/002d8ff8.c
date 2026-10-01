/* Trivial accessor. */
#include "godhand/cWorldLight.h"

/* Returns how many lights are in use. */
__attribute__((section(".text.cWorldLight_Get_LightNum")))
int cWorldLight_Get_LightNum(cWorldLight *self) { return self->lightNum; }
