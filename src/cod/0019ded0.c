/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_00426180;
extern void InitVtable214_429C80_1C27E8(void *a);
#include "godhand/objField.h"
extern int D_00574380;
extern void ClearAndResetFields_1FE278(void *a, void *b);
extern void ResetField214FreeField180_1C2820(void *a, int b);
extern int D_00785E48;
extern int D_00426250;
extern int D_00785798;
extern void GetOrInitGlobal785798_1C3BE8(void);
extern int D_00426268;
extern int D_00785E58;
extern int D_00426338;
extern int D_00426350;

#include "godhand/vu0.h"





__attribute__((section(".text.InitVu0ObjData_19DED0")))
void *InitVu0ObjData_19DED0(void *a0) {
    char *s0;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    s0 = (char*)a0 + 0x620;
    *(int*)((char*)a0 + 0x214) = (int)&D_00426180;
    for (i = 5; i != -1; i--) {
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

__attribute__((section(".text.ClearObjVu0Resource_19DF58")))
void ClearObjVu0Resource_19DF58(void *a0, int a1) {
    int v1;
    *(int*)((char*)a0 + 0x214) = (int)&D_00426180;
    v1 = *(int*)((char*)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void*)v1);
        *(int*)((char*)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetTypeRegistry_19E170")))
int *GetTypeRegistry_19E170(void) {
    if (D_00785E48 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785E48, &D_00426250, &D_00785798);
    }
    return &D_00785E48;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjVu0Array_19E1C0")))
void *InitObjVu0Array_19E1C0(void *a0) {
    char *s0;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char *)a0 + 0x214) = &D_00426268;
    i = 3;
    s0 = (char *)a0 + 0x620;
    do {
        VU0_SQC2_VF0(s0, 0x0);
        VU0_SQC2_VF0(s0, 0x10);
        VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30);
        VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        i--;
        s0 += 0x60;
    } while (i != -1);
    return a0;
}

__attribute__((section(".text.ResetObjVtableAndFree_19E248")))
void ResetObjVtableAndFree_19E248(void *a0, int a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00426268;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetObjClassDesc_19E3F8")))
int *GetObjClassDesc_19E3F8(void) {
    if (D_00785E58 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785E58, &D_00426338, &D_00785798);
    }
    return &D_00785E58;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_19E448")))
void *InitObjSlots_19E448(void *a0) {
    char *s0;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char *)a0 + 0x214) = &D_00426350;
    i = 9;
    s0 = (char *)a0 + 0x620;
    do {
        VU0_SQC2_VF0(s0, 0x0);
        VU0_SQC2_VF0(s0, 0x10);
        VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30);
        VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        i--;
        s0 += 0x60;
    } while (i != -1);
    return a0;
}
