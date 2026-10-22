extern int D_007857B8;
extern unsigned char D_00420310[];
extern unsigned char D_00785798[];
extern int D_00420328;
#include "godhand/objField.h"
extern unsigned char D_005FEE00[];
extern int D_007857C8;
extern unsigned char D_004203F8[];
extern int D_00420410;
extern int D_00574380;
extern int D_007857D8;
extern int D_004204E0;

__attribute__((section(".text.GetOrInit_007857B8_16FC30")))
void *GetOrInit_007857B8_16FC30(void)
{
    if (D_007857B8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_007857B8, D_00420310, D_00785798);
    }
    return &D_007857B8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjVU0Fields_16FC80")))
void *InitObjVU0Fields_16FC80(void *obj)
{
    char *p;
    int i;

    InitVtable214_429C80_1C27E8(obj);
    p = (char *)obj + 0x620;
    *(int **)((char *)obj + 0x214) = &D_00420328;
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

__attribute__((section(".text.func_0016FEA0")))
void func_0016FEA0(void *obj)
{
    cSnd_SeCall_2CBA48(D_005FEE00, 2, 0, obj, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(D_005FEE00, 2, 2, obj, 0, 0, 0, 0);
}

__attribute__((section(".text.GetOrInitSingleton7857C8_16FF18")))
void *GetOrInitSingleton7857C8_16FF18(void)
{
    if (D_007857C8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_007857C8, D_004203F8, D_00785798);
    }
    return &D_007857C8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.Obj16FF_Setup_Field_620_16FF68")))
void *Obj16FF_Setup_Field_620_16FF68(void *a0) {
    unsigned char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char *)a0 + 0x214) = &D_00420410;
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

__attribute__((section(".text.FreeObjResourceAndDestroy_16FFF0")))
void FreeObjResourceAndDestroy_16FFF0(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00420410;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.func_00170188")))
void func_00170188(void *a0) {
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, a0, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 2, a0, 0, 0, 0, 0);
}

__attribute__((section(".text.GetOrInitSingleton7857D8_170200")))
void *GetOrInitSingleton7857D8_170200(void) {
    if (D_007857D8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_007857D8, &D_004204E0, &D_00785798);
    }
    return &D_007857D8;
}
