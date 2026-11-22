#include "godhand/cDamageManage.h"

extern int D_00424C30;

__attribute__((section(".text.ResetField214FreeField600H_195CA8")))
void *ResetField214FreeField600H_195CA8(void *a0, int a1) {
    cDamageTake *v1;
    *(int *)((char *)a0 + 0x214) = (int)&D_00424C30;
    v1 = *(cDamageTake **)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    return ResetField214FreeField180_1C2820(a0, a1);
}
