#include "godhand/cDamageManage.h"
#include "godhand/cSnd.h"
#include "godhand/globals.h"

extern int D_00420920;

__attribute__((section(".text.InitActorVU0Slots0A0C_170990")))
void InitActorVU0Slots0A0C_170990(void *a0) {
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xA, a0, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xC, a0, 0, 0, 0, 0);
}

__attribute__((section(".text.GetOrInitSingleton785818_170A08")))
int *GetOrInitSingleton785818_170A08(void) {
    if (D_00785818 == 0) {
        func_001C0018();
        SetField_0_4_8_31EEA8(&D_00785818, &D_00420768, &D_00785808);
    }
    return &D_00785818;
}

__attribute__((section(".text.InitActorSetVtable_170A58")))
void *InitActorSetVtable_170A58(char *a0) {
    func_001BFAC8(a0);
    *(int *)(a0 + 0x214) = (int)&D_00420780;
    return a0;
}

__attribute__((section(".text.FreeActorVtableState_170A90")))
int FreeActorVtableState_170A90(int a0, int a1) {
    cDamageTake *v1;
    *(int *)(a0 + 0x214) = (int)&D_00420780;
    v1 = *(cDamageTake **)(a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)(a0 + 0x600) = 0;
    }
    return func_001BFB00(a0, a1);
}

__attribute__((section(".text.InitActorVU0Slots0A0CB_170C20")))
void InitActorVU0Slots0A0CB_170C20(void *a0) {
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xA, a0, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xC, a0, 0, 0, 0, 0);
}

__attribute__((section(".text.GetOrInitSingleton785828_170C98")))
void *GetOrInitSingleton785828_170C98(void)
{
    if (D_00785828 == 0) {
        func_001C0018();
        SetField_0_4_8_31EEA8(&D_00785828, &D_00420838, &D_00785808);
    }
    return &D_00785828;
}

__attribute__((section(".text.InitActorSetVtable2_170CE8")))
void *InitActorSetVtable2_170CE8(void *a0)
{
    func_001BFAC8(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_00420850;
    return a0;
}

__attribute__((section(".text.FreeActorVtableState2_170D20")))
void FreeActorVtableState2_170D20(void *a0, void *a1)
{
    int v1;
    *(int *)((char *)a0 + 0x214) = (int)&D_00420850;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}

__attribute__((section(".text.GetOrInitSingleton785838_170EB0")))
void *GetOrInitSingleton785838_170EB0(void)
{
    if (D_00785838 == 0) {
        func_001C0018();
        SetField_0_4_8_31EEA8(&D_00785838, &D_00420908, &D_00785808);
    }
    return &D_00785838;
}

__attribute__((section(".text.InitActorBD580Vtable_170F00")))
void *InitActorBD580Vtable_170F00(void *a0)
{
    func_001BD580(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_00420920;
    return a0;
}
