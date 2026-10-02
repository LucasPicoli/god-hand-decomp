/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cEmManage.h"

extern volatile int D_003D847C;
extern volatile int D_003D8478;
extern void NoOp_33E6A8(int);
extern void NoOp_33E6B0(void);

/* Raises the big-hit effect wait to at least wait. */
__attribute__((section(".text.cEmManage_SetBigHitEffWait")))
void cEmManage_SetBigHitEffWait(cEmManage *self, int wait) {
    if (self->bigHitEffWait < wait)
        self->bigHitEffWait = wait;
}

__attribute__((section(".text.PushGlobalD8478History_331C78")))
void PushGlobalD8478History_331C78(int a0) {
    D_003D8478 = D_003D847C;
    D_003D847C = a0;
}

__attribute__((section(".text.GuardedCall_00329FD0_329F98")))
int GuardedCall_00329FD0_329F98(int a0) {
    int r;
    NoOp_33E6A8(a0);
    r = func_00329FD0(a0);
    NoOp_33E6B0();
    return r;
}
