extern int D_00785C58;
extern char D_00424690[];
extern char D_00785798[];
#include "godhand/objField.h"
extern int D_004246A8;
extern int D_00785C68;
extern int D_00424778[];
extern int D_00424790[];
extern int D_00574380[];
extern int D_00785C78;
extern int D_00424860;
extern int D_00424878;

__attribute__((section(".text.GetObjSingleton_1931A0")))
void *GetObjSingleton_1931A0(void) {
    if (D_00785C58 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785C58, D_00424690, D_00785798);
    }
    return &D_00785C58;
}

#include "godhand/vu0.h"





__attribute__((section(".text.Obj1930_Setup_1931F0")))
void *Obj1930_Setup_1931F0(void *a0) {
    char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char *)a0 + 0x214) = &D_004246A8;
    p = (char *)a0 + 0x620;
    for (i = 3; i != -1; i--) {
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

__attribute__((section(".text.GetOrInit_785C68_193418")))
void *GetOrInit_785C68_193418(void) {
    if (D_00785C68 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785C68, D_00424778, D_00785798);
    }
    return &D_00785C68;
}

#include "godhand/vu0.h"





__attribute__((section(".text.Setup_Ptr_214_VU0Array_620_193468")))
void *Setup_Ptr_214_VU0Array_620_193468(void *a0) {
    char *s0;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int**)((char*)a0 + 0x214) = D_00424790;
    s0 = (char*)a0 + 0x620;
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

__attribute__((section(".text.ResetField214FreeField600E_1934F0")))
void ResetField214FreeField600E_1934F0(void *a0, int a1) {
    int v1;
    *(int**)((char*)a0 + 0x214) = D_00424790;
    v1 = *(int*)((char*)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(D_00574380, v1);
        *(int*)((char*)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetInstance_1936C8")))
void *GetInstance_1936C8(void) {
    if (D_00785C78 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785C78, &D_00424860, &D_00785798);
    }
    return &D_00785C78;
}

#include "godhand/vu0.h"





__attribute__((section(".text.Setup_Field_214_Obj0000Array_620_193718")))
void *Setup_Field_214_Obj0000Array_620_193718(void *a0) {
    char *p = (char *)a0 + 0x620;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_00424878;
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

__attribute__((section(".text.ClearSlotResources_1937A0")))
void ClearSlotResources_1937A0(void *a0, void *a1) {
    int v1;
    *(int *)((char *)a0 + 0x214) = (int)&D_00424878;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}
