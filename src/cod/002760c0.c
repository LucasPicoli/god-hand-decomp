/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/globals.h"
#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.cEm00__offSunglass")))
void cEm00__offSunglass(void *a0) {
    cEm00 *s0 = a0;
    char *r;

    if ((s0->emNo ^ 0x256) != 0) {
        return;
    }
    r = (char *)cModel_getMeshPtr_14B730(a0, D_004479A0);
    if (r != 0) {
        *(int *)(r + 0x380) |= 1;
    }
    *(int *)((char *)s0 + 0x174C) = 0;
    s0->emFlags2 |= 0x4000000;
    *(float *)((char *)s0 + 0x1750) = 300.0f;
    switch (cCoreSave_getGameLevel(&D_00569B70)) {
    default:
    case 1:
        *(float *)((char *)s0 + 0x1750) = 300.0f;
        break;
    case 2:
        *(float *)((char *)s0 + 0x1750) = 450.0f;
        break;
    case 3:
        *(float *)((char *)s0 + 0x1750) = 600.0f;
        break;
    case 4:
        *(float *)((char *)s0 + 0x1750) = 600.0f;
        break;
    case 5:
        *(float *)((char *)s0 + 0x1750) = 600.0f;
        break;
    }
    s0->phase = 0x8D;
    s0->mode = 0;
    s0->step = 0;
    s0->stepArg = 0;
}
