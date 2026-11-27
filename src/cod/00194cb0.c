#include "godhand/cObj.h"
/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00194CB0")))
void func_00194CB0(cObj *o) {
    int t;
    unsigned char s = o->step;
    unsigned char u;
    if (s == 0) goto init;
    if (s == 1) goto dec;
    return;
init:
    *(short *)((char *)o + 0xAF0) = 0;
    o->step = 1;
    o->stepArg = 0;
dec:
    t = *(unsigned short *)((char *)o + 0xAF0) - 1;
    *(short *)((char *)o + 0xAF0) = t;
    if ((short)t >= 0) return;
    u = o->phase;
    o->phase = 2;
    *(unsigned char *)((char *)o + 0xAF2) = u;
    o->step = 0;
    o->stepArg = 0;
}
