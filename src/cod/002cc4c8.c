/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

/* Returns voice idx of the voice pool. */
__attribute__((section(".text.func_002CC4C8")))
cSndSeVoice *func_002CC4C8(cSnd *self, int idx) {
    return &self->voicePool[idx];
}

__attribute__((section(".text.func_002D2DB0")))
int func_002D2DB0(int a0, int a1) {
    int v0 = *(int*)((char*)a0 + 0x38);
    int t = a1 * 0xDC;
    return v0 + t;
}
