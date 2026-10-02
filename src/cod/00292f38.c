/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cEmManage.h"

extern void PushEsp(void *a0);
extern int D_003FA62C;
extern void __malloc_lock(int a0);
extern void func_003ACA28(int a0, int a1);
extern void __malloc_unlock(int a0);
extern float D_00741DC0;
extern float D_00754C48;

__attribute__((section(".text.UpdateObjByIndexedOp_2FBE50")))
void UpdateObjByIndexedOp_2FBE50(void *a0) {
    int r;
    r = func_002B5E50(a0);
    func_002B5CF0(a0, r);
    PushEsp(a0);
}

__attribute__((section(".text.UpdateGlobalPtrWithParam_3A7CC0")))
void UpdateGlobalPtrWithParam_3A7CC0(int a0) {
    __malloc_lock(D_003FA62C);
    func_003ACA28(D_003FA62C, a0);
    __malloc_unlock(D_003FA62C);
}

/* Sets the enemies' speed rate for this frame and copies it to the two
 * globals that hold it; Main puts it back to 1.0 at the end of the frame. */
__attribute__((section(".text.cEmManage_SetSpeedRate")))
void cEmManage_SetSpeedRate(cEmManage *self, float rate) {
    self->speedRate = rate;
    D_00741DC0 = rate;
    D_00754C48 = rate;
}
