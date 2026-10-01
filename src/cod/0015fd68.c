/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_0015FD68")))
int func_0015FD68(void *a0) {
    char *p = (char*)a0 + 4;
    int i;
    for (i = 0; i < 9; i++) {
        if (*(int*)p == 0) return i;
        p += 8;
    }
    return -1;
}

__attribute__((section(".text.func_001FC198")))
/* God reel in slot `slot`; 0x1F (empty) when out of range. */
int func_001FC198(cCoreSave *self, int slot) {
    cCoreSaveData *data = self->data;
    unsigned char idx;
    if (data == 0) {
        return 0x1F;
    }
    idx = slot & 0xFF;
    if (idx >= 0xA) {
        return 0x1F;
    }
    return data->reelSlot[idx];
}

__attribute__((section(".text.func_001FD8D8")))
int func_001FD8D8(void *a0, int a1) {
    void *v1 = *(void**)((char*)a0 + 0x3C);
    while (v1 != 0) {
        short v0 = *(short*)((char*)v1 + 0x2C);
        if (v0 == a1) {
            return *(int*)((char*)v1 + 0x28);
        }
        v1 = *(void**)((char*)v1 + 0x24);
    }
    return 0;
}
