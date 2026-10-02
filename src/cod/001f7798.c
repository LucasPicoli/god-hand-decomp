/* ee-2.9-991111 matched TU. */
#include "godhand/cScenario.h"

extern int D_00463964;

__attribute__((section(".text.cScenario_isCamEnd")))
/* 1 once the setCam camera move has finished (the camera sets bit 1). */
int cScenario_isCamEnd(cScenario *self) {
    if (self->camOn == 0) {
        return 1;
    }
    if ((D_00463964 & 2) == 0) {
        return 0;
    }
    self->camOn = 0;
    return 1;
}

__attribute__((section(".text.func_001F7798")))
char *func_001F7798(char *p) {
    unsigned int i = 0;
    p = p + 0x104;
    for (;;) {
        if (((*(int *)p & 0x201) ^ 1) != 0) {
            return p;
        }
        i++;
        if (i >= 8) {
            break;
        }
        p = p + 0x44;
    }
    return 0;
}
