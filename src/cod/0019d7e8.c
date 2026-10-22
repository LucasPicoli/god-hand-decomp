/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern unsigned char D_00574380[];
extern int D_00425EE0;
extern void ClearAndResetFields_1FE278(void *a, int b);
extern void func_001BFB00(void *a0, void *a1);
extern int D_00785E18;
extern int D_00425F98;
extern int D_00785808;
extern void func_001C0018(void);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern int D_00425FB0;
extern void InitVtable214_429C80_1C27E8(void *a0);
#include "godhand/objField.h"
extern void ResetField214FreeField180_1C2820(void *a, void *b);
extern int D_00785E28;
extern int D_00426080;
extern int D_00785798;
extern void GetOrInitGlobal785798_1C3BE8(void);
extern int D_00426098;
extern int D_00785E38;
extern int D_00426168;

__attribute__((section(".text.ClearObjResource_19D7E8")))
void ClearObjResource_19D7E8(void *a0, void *a1) {
    int v1;
    *(unsigned int *)((char *)a0 + 0x214) = (unsigned int)&D_00425EE0;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(unsigned int *)((char *)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}

__attribute__((section(".text.GetTypeInstance_19D970")))
int *GetTypeInstance_19D970(void) {
    if (D_00785E18 == 0) {
        func_001C0018();
        SetField_0_4_8_31EEA8(&D_00785E18, &D_00425F98, &D_00785808);
    }
    return &D_00785E18;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjVu0Block_19D9C0")))
void *InitObjVu0Block_19D9C0(void *a0)
{
    char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    p = (char *)a0 + 0x620;
    *(int **)((char *)a0 + 0x214) = &D_00425FB0;
    for (i = 4; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x00);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }
    return a0;
}

__attribute__((section(".text.ClearObjSlot_19DA48")))
void ClearObjSlot_19DA48(void *a0, void *a1)
{
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425FB0;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetClassDescriptor_19DBF8")))
int *GetClassDescriptor_19DBF8(void) {
    if (D_00785E28 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785E28, &D_00426080, &D_00785798);
    }
    return &D_00785E28;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitVu0ObjBlock_19DC48")))
void *InitVu0ObjBlock_19DC48(void *a0)
{
    char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    p = (char *)a0 + 0x620;
    *(int **)((char *)a0 + 0x214) = &D_00426098;
    for (i = 5; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x00);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }
    return a0;
}

__attribute__((section(".text.ResetObjSlotResource_19DCD0")))
void ResetObjSlotResource_19DCD0(void *a0, int a1) {
    int v1;
    *(int*)((char*)a0 + 0x214) = (int)&D_00426098;
    v1 = *(int*)((char*)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void*)v1);
        *(int*)((char*)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetSubclassDescriptor_19DE80")))
int *GetSubclassDescriptor_19DE80(void) {
    if (D_00785E38 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785E38, &D_00426168, &D_00785798);
    }
    return &D_00785E38;
}
