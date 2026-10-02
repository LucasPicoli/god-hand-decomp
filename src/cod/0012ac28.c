/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_00428A20;
extern int D_004289F0;
extern void cOmWeapon_setFall(int arg);
extern void ReleaseObj(void);
extern int D_00785878;
extern int D_00428AD0;
extern int D_007854D8;
extern void func_002A9300(void);
extern void SetField_0_4_8_31EEA8(void *a0, void *a1, void *a2);

#include "godhand/vu0.h"






__attribute__((section(".text.InitFields_1B6E90")))
char *InitFields_1B6E90(char *a0) {
    char *p490;
    char *p5D0;
    cGameObj(a0);
    *(int*)(a0 + 0x5B0) = 0;
    *(int*)(a0 + 0x5B4) = 0;
    *(int*)(a0 + 0x214) = (int)&D_00428A20;
    *(int*)(a0 + 0x5B8) = 0;
    VU0_SQC2_VF0(a0, 0x5C0);
    p5D0 = a0 + 0x5D0;
    VU0_SQC2_VF0(a0, 0x5D0);
    *(int*)(a0 + 0x560) = 0xFFFF;
    *(int*)(a0 + 0x4AC) = (int)&D_004289F0;
    p490 = a0 + 0x490;
    *(int*)(a0 + 0x5E0) = 0;
    *(int*)(a0 + 0x5E8) = 0;
    *(int*)(a0 + 0x5E4) = 0;
    *(int*)(a0 + 0x5F0) = 0;
    *(int*)(a0 + 0x5EC) = 0;
    *(short*)(a0 + 0x5F4) = 0;
    *(short*)(a0 + 0x5F6) = 0;
    *(int*)(a0 + 0x490) = 0;
    *(int*)(p490 + 4) = 0;
    *(int*)(p490 + 8) = 0;
    *(int*)(a0 + 0x5D0) = 0;
    *(int*)(p5D0 + 4) = 0;
    *(int*)(p5D0 + 8) = 0;
    *(int*)(a0 + 0x5B8) |= 0x10;
    return a0;
}

__attribute__((section(".text.CallWithAndClearField698_12AC28")))
void CallWithAndClearField698_12AC28(char *a0) {
    int v = *(int*)(a0 + 0x698);
    if (v) {
        cOmWeapon_setFall(v);
        *(int*)(a0 + 0x698) = 0;
    }
}

__attribute__((section(".text.cOmBase_dieCommon")))
void cOmBase_dieCommon(void) { ReleaseObj(); }

__attribute__((section(".text.GetOrInitGlobal785878_1B8058")))
void *GetOrInitGlobal785878_1B8058(void) {
    if (D_00785878 == 0) {
        func_002A9300();
        SetField_0_4_8_31EEA8(&D_00785878, &D_00428AD0, &D_007854D8);
    }
    return &D_00785878;
}
