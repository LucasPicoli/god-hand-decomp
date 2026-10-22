extern char D_005CAE50[];
extern int D_00785EB8;
extern int D_004268B0;
extern int D_007858B8;
extern int D_004268C8;
#include "godhand/objField.h"
extern int D_00574380;
extern int D_00785EC8;
extern char D_00426998[];
extern char D_00785798[];
extern int D_004269B0;
extern int D_00785ED8;
extern char D_00426A80[];
extern int D_00426A98;

__attribute__((section(".text.ClearDamageCollAndState_19FD50")))
void ClearDamageCollAndState_19FD50(void *a0) {
    int v0 = *(int*)((char*)a0 + 0x5B0);
    int x = *(int*)((char*)a0 + 0x650);
    *(int*)((char*)a0 + 0x5B0) = (v0 & -9) | 4;
    if (x != 0) cDamageUnit_SetDamageCollActive(x, 0);
    func_001331B8(D_005CAE50, *(double*)((char*)a0 + 0x540), 0);
    ClearStateAndFlag_1C7E08(a0);
}

__attribute__((section(".text.GetTypeDescriptor_19FE58")))
void *GetTypeDescriptor_19FE58(void) {
    if (D_00785EB8 == 0) {
        func_001C8F30();
        SetField_0_4_8_31EEA8(&D_00785EB8, &D_004268B0, &D_007858B8);
    }
    return &D_00785EB8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.Setup_Field_214_Field_620_19FEA8")))
void *Setup_Field_214_Field_620_19FEA8(void *a0) {
    char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char*)a0 + 0x214) = &D_004268C8;
    p = (char*)a0 + 0x620;
    for (i = 5; i != -1; i--) {
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

__attribute__((section(".text.FreeActorResources_19FF30")))
void FreeActorResources_19FF30(void *a0, int a1) {
    int v1;
    *(int **)((char*)a0 + 0x214) = &D_004268C8;
    v1 = *(int*)((char*)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int*)((char*)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetTypeDescriptorB_1A00D0")))
void *GetTypeDescriptorB_1A00D0(void) {
    if (D_00785EC8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785EC8, D_00426998, D_00785798);
    }
    return &D_00785EC8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitVu0SlotArray4_1A0120")))
void *InitVu0SlotArray4_1A0120(void *obj)
{
    char *p;
    int i;

    InitVtable214_429C80_1C27E8(obj);
    p = (char *)obj + 0x620;
    *(int **)((char *)obj + 0x214) = &D_004269B0;
    for (i = 4; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x00);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }
    return obj;
}

__attribute__((section(".text.FreeActorResourcesC_1A01A8")))
void FreeActorResourcesC_1A01A8(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004269B0;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetTypeDescriptorC_1A0340")))
void *GetTypeDescriptorC_1A0340(void) {
    if (D_00785ED8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785ED8, D_00426A80, D_00785798);
    }
    return &D_00785ED8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitVu0SlotArray5_1A0390")))
void *InitVu0SlotArray5_1A0390(void *obj)
{
    char *p;
    int i;

    InitVtable214_429C80_1C27E8(obj);
    p = (char *)obj + 0x620;
    *(int **)((char *)obj + 0x214) = &D_00426A98;
    for (i = 5; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x00);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }
    return obj;
}

__attribute__((section(".text.FreeActorResourcesD_1A0418")))
void FreeActorResourcesD_1A0418(void *a0, void *a1)
{
    *(int *)((char *)a0 + 0x214) = (int)&D_00426A98;
    if (*(int *)((char *)a0 + 0x600) != 0) {
        ClearAndResetFields_1FE278(&D_00574380, *(int *)((char *)a0 + 0x600));
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}
