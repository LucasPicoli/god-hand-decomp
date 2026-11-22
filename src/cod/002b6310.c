/* cygnus-2.96 matched TU. */

extern void (*D_003FC7AC)(int, int);
extern int D_003FC7B0;
extern void NoOp_33E6A8(int a0);
extern void func_00329ED8(int a0);
extern int NoOp_33E6B0(void);
extern int *GetD003EC7E0_3452B0(int a0);
extern void Obj3290_Tramp_0033E6A8_9070(int a0);
extern int Obj3290_Tramp_0033E6B0_9088(void);

__attribute__((section(".text.func_003B9DE0")))
void func_003B9DE0(int a0) {
    void (*f)(int, int) = D_003FC7AC;
    if (f) {
        f(D_003FC7B0, a0);
    }
}

__attribute__((section(".text.func_00335CD8")))
void func_00335CD8(void) {}

__attribute__((section(".text.func_00335CE0")))
void func_00335CE0(void) {}

__attribute__((section(".text.ADXT_Stop")))
void ADXT_Stop(int a0) {
    NoOp_33E6A8(a0);
    func_00329ED8(a0);
    NoOp_33E6B0();
}

__attribute__((section(".text.MWSFLIB_SetErrCode")))
int MWSFLIB_SetErrCode(int a0) {
    int *p = GetD003EC7E0_3452B0(a0);
    *(int *)((char *)p + 0x68) = a0;
    return a0;
}

#include "godhand/vu0.h"

__attribute__((section(".text.func_002B6310")))
int func_002B6310(int a0, int a1) {
    int v0 = a0;
    a1 = a1 + 0x40;
    VU0_LQC2(4, a1, 0x0);
    VU0_SQC2(4, v0, 0x0);
    return v0;
}

__attribute__((section(".text.func_00328098")))
int func_00328098(int a0)
{
    int r;
    Obj3290_Tramp_0033E6A8_9070(a0);
    r = func_003280D0(a0);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}
