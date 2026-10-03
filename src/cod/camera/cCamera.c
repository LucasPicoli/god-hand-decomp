/* TU: cCamera [camera] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cCamera.h"

__attribute__((section(".text.cCamera_setMode")))
void cCamera_setMode(void) {}

/* Stop both screen-shake channels. */
__attribute__((section(".text.cCamera_resetVib")))
void cCamera_resetVib(struct cCamera *self) {
    self->vib[1].phase = 0;
    self->vib[1].amp = 0;
    self->vib[1].decay = 0;
    self->vib[1].speed = 0;
    self->vib[1].count = 0;
    self->vib[0].phase = 0;
    self->vib[0].amp = 0;
    self->vib[0].decay = 0;
    self->vib[0].speed = 0;
    self->vib[0].count = 0;
}
