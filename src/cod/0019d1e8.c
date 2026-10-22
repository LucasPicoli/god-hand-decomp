/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern char D_005CAE50[];
extern int D_00785DE8;
extern char D_00425D30[];
extern char D_007858B8[];
#include "godhand/objField.h"
extern int D_00425D48;
extern int D_00785DF8;
extern char D_00425DF8[];
extern char D_007859B8[];
extern char D_00425E10[];
extern unsigned char D_00574380[];
extern void ClearAndResetFields_1FE278(void *a, int b);
extern void func_001BFB00(void *a0, void *a1);
extern int D_00785E08;
extern int D_00425EC8;
extern int D_00785808;
extern void func_001C0018(void);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern int D_00425EE0;
extern void func_001BFAC8(void *a0);

__attribute__((section(".text.ResetObjState_19D1E8")))
void ResetObjState_19D1E8(void *a0) {
    int tmp;
    int sub;
    tmp = (*(int *)((char *)a0 + 0x5B0) & -9) | 4;
    sub = *(int *)((char *)a0 + 0x650);
    *(int *)((char *)a0 + 0x5B0) = tmp;
    if (sub != 0) {
        cDamageUnit_SetDamageCollActive(sub, 0);
    }
    func_001331B8(D_005CAE50, *(long *)((char *)a0 + 0x540), 0);
    ClearStateAndFlag_1C7E08(a0);
}

__attribute__((section(".text.GetTypeDesc_19D2F0")))
void *GetTypeDesc_19D2F0(void) {
    if (D_00785DE8 == 0) {
        func_001C8F30();
        SetField_0_4_8_31EEA8(&D_00785DE8, D_00425D30, D_007858B8);
    }
    return &D_00785DE8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjVu0Fields_19D340")))
void *InitObjVu0Fields_19D340(void *a0) {
    char *p;
    int i;
    func_001BBEB8(a0);
    *(int **)((char *)a0 + 0x214) = &D_00425D48;
    p = (char *)a0 + 0x650;
    for (i = 6; i != -1; i--) {
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

__attribute__((section(".text.GetObjTypeDesc_19D558")))
void *GetObjTypeDesc_19D558(void) {
    if (D_00785DF8 == 0) {
        func_001BD528();
        SetField_0_4_8_31EEA8(&D_00785DF8, D_00425DF8, D_007859B8);
    }
    return &D_00785DF8;
}

__attribute__((section(".text.InitObjVtable_19D5A8")))
void *InitObjVtable_19D5A8(void *a0) {
    func_001BFAC8(a0);
    *(char **)((char *)a0 + 0x214) = D_00425E10;
    return a0;
}

__attribute__((section(".text.FreeObjResource_19D5E0")))
void FreeObjResource_19D5E0(void *a0, void *a1) {
    int v1;
    *(unsigned int *)((char *)a0 + 0x214) = (unsigned int)&D_00425E10;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(unsigned int *)((char *)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}

__attribute__((section(".text.GetClassTypeInfo_19D760")))
int GetClassTypeInfo_19D760(void) {
    if (D_00785E08 == 0) {
        func_001C0018();
        SetField_0_4_8_31EEA8(&D_00785E08, &D_00425EC8, &D_00785808);
    }
    return (int)&D_00785E08;
}

__attribute__((section(".text.SetObjVtable_19D7B0")))
void *SetObjVtable_19D7B0(void *a0) {
    func_001BFAC8(a0);
    *(unsigned int *)((char *)a0 + 0x214) = (unsigned int)&D_00425EE0;
    return a0;
}
