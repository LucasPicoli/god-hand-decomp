/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cDamageManage.h"
#include "godhand/globals.h"

extern void ResetField214FreeField180_1C2820(void *, int);

__attribute__((section(".text.ResetObjVtableAndFree_19E4D0")))
void ResetObjVtableAndFree_19E4D0(void *a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)&D_00426350;
    if (*(int *)((char *)a0 + 0x600) != 0) {
        ClearAndResetFields_1FE278(&D_00574380, *(cDamageTake **)((char *)a0 + 0x600));
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}
