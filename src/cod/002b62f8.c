/* cygnus-2.96 matched TU. */

extern void NoOp_33E6A8(void);
extern int NoOp_33E6B0(void);
extern void func_00335CD8(int a0);
extern void func_00335980(int a0);
extern int Obj34D8_SetGlobalEE0B8_IfField48(int a0);
extern void func_0034DD70(int a0, int a1);
extern void Forward33E6A8_324880(int a0);
extern int Forward323050_323038(int a0);
extern void Forward33E6B0_324898(void);
extern void Obj3290_Tramp_0033E6A8_9070(void);
extern void Obj3290_Tramp_0033E6B0_9088(void);
extern void Obj33F8_NoOp_FCA0(void);
extern int Obj33F8_NoOp_FCA8(void);
extern int Forward33B790_340AE8(void *p);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);

__attribute__((section(".text.ADXT_SetLnkSw")))
void ADXT_SetLnkSw(int a0, int a1) {
    NoOp_33E6A8();
    func_0032B6A0(a0, a1);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_00335950")))
int func_00335950(int a0) {
    func_00335CD8(a0);
    func_00335980(a0);
    return func_00335CE0();
}

__attribute__((section(".text.SFD_GetHnStat")))
int SFD_GetHnStat(int a0) {
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0)) {
        func_0034DD70(0, 0xFF000111);
    }
    return *(int*)((char*)a0 + 0x48);
}

__attribute__((section(".text.func_00323000")))
int func_00323000(int a0) {
    int r;
    Forward33E6A8_324880(a0);
    r = Forward323050_323038(a0);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_003280D8")))
int func_003280D8(int a0, int a1) {
    int r;
    Obj3290_Tramp_0033E6A8_9070();
    r = func_00328120(a0, a1);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

__attribute__((section(".text.func_0032A530")))
int func_0032A530(int a0) {
    int r;
    NoOp_33E6A8();
    r = func_0032A568(a0);
    NoOp_33E6B0();
    return r;
}

__attribute__((section(".text.func_0032A5B8")))
int func_0032A5B8(int a0) {
    int r;
    NoOp_33E6A8();
    r = func_0032A5F0(a0);
    NoOp_33E6B0();
    return r;
}

__attribute__((section(".text.func_0032B0B0")))
int func_0032B0B0(int a0) {
    int r;
    NoOp_33E6A8();
    r = func_0032B0E8(a0);
    NoOp_33E6B0();
    return r;
}

__attribute__((section(".text.func_0032DC58")))
int func_0032DC58(int a0) {
    int r;
    Obj33F8_NoOp_FCA0();
    r = func_0032DC90(a0);
    Obj33F8_NoOp_FCA8();
    return r;
}

__attribute__((section(".text.func_0032DCD0")))
int func_0032DCD0(int a0, int a1) {
    int r;
    Obj33F8_NoOp_FCA0();
    r = func_0032DD18(a0, a1);
    Obj33F8_NoOp_FCA8();
    return r;
}

__attribute__((section(".text.func_00338A48")))
int func_00338A48(int a0, int a1) {
    int sp[16];
    func_003A57C4(sp, a0);
    func_003A53A8(sp, a1);
    return Forward33B790_340AE8(sp);
}

__attribute__((section(".text.func_00339458")))
int func_00339458(int a0, int a1) {
    int sp[16];
    func_003A57C4(sp, a0);
    func_003A53A8(sp, a1);
    return Forward33B790_340AE8(sp);
}

__attribute__((section(".text.func_0032E040")))
int func_0032E040(int a0, int a1) {
    Obj33F8_NoOp_FCA0();
    Obj33F8_Tramp_0033B658_FC70();
    func_0032E090(a0, a1);
    Obj33F8_Tramp_0033B670_FC88();
    return Obj33F8_NoOp_FCA8();
}

__attribute__((section(".text.AIXP_SetTrackVol")))
void AIXP_SetTrackVol(int a0, int a1, int a2) {
    Obj33F8_NoOp_FCA0();
    Obj33F8_Tramp_0033B658_FC70();
    CriTrackSet_setTrackLevel(a0, a1, a2);
    Obj33F8_Tramp_0033B670_FC88();
    Obj33F8_NoOp_FCA8();
}

#include "godhand/vu0.h"
__attribute__((section(".text.func_002B62F8")))
void *func_002B62F8(void *a0, char *a1) {
    VU0_LQC2(4, a1 + 0x30, 0);
    VU0_SQC2(4, a0, 0);
    return a0;
}
