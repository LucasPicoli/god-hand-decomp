/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

/* Finds the voice that holds this sound-driver handle. */
__attribute__((section(".text.cSnd_FindVoiceByHandle")))
cSndSeVoice *cSnd_FindVoiceByHandle(cSnd *self, int handle) {
    cSndSeVoice *v = self->voiceHead;
    if (v != 0) {
        do {
            if (v->handle == handle) return v;
            v = v->next;
        } while (v != 0);
    }
    return 0;
}

__attribute__((section(".text.func_002D5440")))
void func_002D5440(void *a0, int a1) {
    char *v1 = *(char**)((char*)a0 + 4);
    char *base;
    unsigned char val;
    if (v1 == 0) return;
    if (a1 == -1) return;
    base = *(char**)a0;
    val = *(unsigned char*)(v1 + 0x50);
    *(unsigned char*)(base + a1 * 0x58 + 0x50) = val;
}

__attribute__((section(".text.func_003057A0")))
void func_003057A0(void *a0) {
    unsigned int i;
    for (i = 0; i < 0x40; i++) {
        *(int*)a0 = 5;
        *(int*)((char*)a0 + 4) = 0;
        *(int*)((char*)a0 + 8) = 0;
        *(int*)((char*)a0 + 0xC) = 0;
        a0 = (char*)a0 + 0x10;
    }
}
