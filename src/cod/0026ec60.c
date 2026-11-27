#include "godhand/cGameObj.h"
/* func_0026EC60 — if the linked object at +0x17A0 shares our +0x2FE id, is not
 * already in phase +0x2F4, and its +0x54C timer has run out (<= 0), re-arm its
 * phase block to 0x2F5=0x65.  sn-2.95.3-136. */
__attribute__((section(".text.func_0026EC60")))
void func_0026EC60(void *a0){
    char *s0 = (char *)a0;
    cGameObj *a1 = *(char **)(s0 + 0x17A0);
    if (a1 == 0) return;
    if (a1->actorId != *(unsigned short *)(s0 + 0x2FE)) return;
    if (a1->mode != 0) return;
    if (0.0f < a1->hitFlash) return;
    a1->mode = 0;
    a1->phase = 0x65;
    a1->step = 0;
    a1->stepArg = 0;
}
