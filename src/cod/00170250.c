#include "godhand/objField.h"
extern int D_004204F8;
extern unsigned char D_00574380[];
extern unsigned char D_005FEE00[];
extern int D_007857E8;
extern unsigned char D_004205C8[];
extern unsigned char D_00785798[];
extern unsigned char D_004205E0[];
extern int D_007857F8;
extern int D_00420698;
extern int D_00785808;
extern int D_004206B0;

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjVU0Fields8Slots_170250")))
void *InitObjVU0Fields8Slots_170250(void *a0) {
    unsigned char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char *)a0 + 0x214) = &D_004204F8;
    p = (unsigned char *)a0 + 0x620;
    for (i = 7; i != -1; i--) {
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

__attribute__((section(".text.FreeObjResourceAndDestroyB_1702D8")))
void FreeObjResourceAndDestroyB_1702D8(void *a0, void *a1) {
    void *v1;
    *(unsigned int *)((char *)a0 + 0x214) = (unsigned int)&D_004204F8;
    v1 = *(void **)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(unsigned int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.func_00170470")))
void func_00170470(void *a0) {
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, a0, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 2, a0, 0, 0, 0, 0);
}

__attribute__((section(".text.GetOrInitSingleton7857E8_1704E8")))
void *GetOrInitSingleton7857E8_1704E8(void) {
    if (D_007857E8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_007857E8, &D_004205C8, &D_00785798);
    }
    return &D_007857E8;
}

__attribute__((section(".text.InitObjSetVtable4205E0_170538")))
void *InitObjSetVtable4205E0_170538(void *a0) {
    func_001BFAC8(a0);
    *(unsigned int *)((char *)a0 + 0x214) = (unsigned int)&D_004205E0;
    return a0;
}

__attribute__((section(".text.FreeObjResourceAndDestroyD_170570")))
void FreeObjResourceAndDestroyD_170570(void *a0, void *a1) {
    void *v1;
    *(unsigned int *)((char *)a0 + 0x214) = (unsigned int)&D_004205E0;
    v1 = *(void **)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(unsigned int *)((char *)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}

__attribute__((section(".text.InitObjVU0Slots0A0C_170700")))
void InitObjVU0Slots0A0C_170700(int a0) {
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xA, a0, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xC, a0, 0, 0, 0, 0);
}

__attribute__((section(".text.GetOrInit_D_007857F8_170778")))
int GetOrInit_D_007857F8_170778(void) {
    if (D_007857F8 == 0) {
        func_001C0018();
        SetField_0_4_8_31EEA8(&D_007857F8, &D_00420698, &D_00785808);
    }
    return (int)&D_007857F8;
}

__attribute__((section(".text.InitObjSetVtable4206B0_1707C8")))
int InitObjSetVtable4206B0_1707C8(int a0) {
    func_001BFAC8(a0);
    *(int*)((char*)a0 + 0x214) = (int)&D_004206B0;
    return a0;
}

__attribute__((section(".text.FreeObjResourceAndDestroyE_170800")))
void FreeObjResourceAndDestroyE_170800(int a0, int a1) {
    int v1;
    *(int*)((char*)a0 + 0x214) = (int)&D_004206B0;
    v1 = *(int*)((char*)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int*)((char*)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}
