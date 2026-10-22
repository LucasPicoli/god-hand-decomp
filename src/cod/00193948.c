extern int D_00785C88;
extern int D_00424948;
extern int D_00785798;
#include "godhand/objField.h"
extern int D_00424960;
extern int D_00574380;
extern int D_00785C98;
extern int D_00424A30;
extern int D_00424A48;
extern int D_00785CA8;
extern int D_00424B18;
extern int D_00424B68;
extern int D_005CAE50;
extern int D_007419A0;
extern int D_00785CB8;
extern int D_00424C18;
extern int D_00785878;
extern int D_00424C30;

__attribute__((section(".text.GetBInstance_193948")))
void *GetBInstance_193948(void) {
    if (D_00785C88 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785C88, &D_00424948, &D_00785798);
    }
    return &D_00785C88;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitSlotVu0Data_193998")))
void *InitSlotVu0Data_193998(void *a0) {
    char *p = (char *)a0 + 0x620;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_00424960;
    for (i = 4; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }
    return a0;
}

__attribute__((section(".text.ResetField214FreeField600F_193A20")))
int ResetField214FreeField600F_193A20(void *a0, int a1) {
    int v1;
    *(int **)((char*)a0 + 0x214) = &D_00424960;
    v1 = *(int *)((char*)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)((char*)a0 + 0x600) = 0;
    }
    return ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetCInstance_193BD0")))
void *GetCInstance_193BD0(void) {
    if (D_00785C98 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785C98, &D_00424A30, &D_00785798);
    }
    return &D_00785C98;
}

__attribute__((section(".text.ResetField214FreeField600G_193CA8")))
int ResetField214FreeField600G_193CA8(void *a0, int a1) {
    int v1;
    *(int **)((char*)a0 + 0x214) = &D_00424A48;
    v1 = *(int *)((char*)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)((char*)a0 + 0x600) = 0;
    }
    return ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetDInstance_193E58")))
void *GetDInstance_193E58(void) {
    if (D_00785CA8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785CA8, &D_00424B18, &D_00785798);
    }
    return &D_00785CA8;
}

__attribute__((section(".text.FreeMultiResource_193FD8")))
void FreeMultiResource_193FD8(void *a0, int a1) {
    int v1;
    int v5;
    *(int *)((char *)a0 + 0x214) = (int)&D_00424B68;
    v1 = *(int *)((char *)a0 + 0x604);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)((char *)a0 + 0x604) = 0;
    }
    v5 = *(int *)((char *)a0 + 0x608);
    if (v5 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, v5);
        *(int *)((char *)a0 + 0x608) = 0;
    }
    v5 = *(int *)((char *)a0 + 0x614);
    if (v5 != 0) {
        func_0012EC58(&D_005CAE50, v5);
        *(int *)((char *)a0 + 0x614) = 0;
    }
    espSys_effDataRelease(&D_007419A0, 0x177);
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.GetEInstance_195BD0")))
void *GetEInstance_195BD0(void) {
    void *p = &D_00785CB8;
    if (D_00785CB8 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(p, &D_00424C18, &D_00785878);
    }
    return p;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitSlotVu0DataB_195C20")))
void *InitSlotVu0DataB_195C20(void *a0) {
    char *s0 = (char *)a0 + 0x620;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_00424C30;
    for (i = 4; i != -1; i--) {
        VU0_SQC2_VF0(s0, 0x0);
        VU0_SQC2_VF0(s0, 0x10);
        VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30);
        VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        s0 += 0x60;
    }
    return a0;
}
