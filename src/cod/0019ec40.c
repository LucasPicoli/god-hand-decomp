/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void *D_00426608;
extern char D_00574380[];
extern void ClearAndResetFields_1FE278(void *heap, void *p);
extern void ResetField214FreeField180_1C2820(void *a0, int a1);
extern void *D_00785E98;
extern char D_004266D8[];
extern char D_00785798[];
extern void GetOrInitGlobal785798_1C3BE8(void);
extern void SetField_0_4_8_31EEA8(void *p, void *vtbl, void *name);
extern void *D_004266F0;
extern void InitVtable214_429C80_1C27E8(void *);
#include "godhand/objField.h"
extern int D_00785EA8;
extern int D_004267C0;
extern int D_004267F8;
extern void func_001C7D98(void *a0);
extern void func_001C7DE0(void *a0, void *a1);

__attribute__((section(".text.ResetObjVtableAndFree_19EC40")))
void ResetObjVtableAndFree_19EC40(void *a0, int a1) {
    void *p;
    *(void **)((char *)a0 + 0x214) = &D_00426608;
    p = *(void **)((char *)a0 + 0x600);
    if (p) {
        ClearAndResetFields_1FE278(&D_00574380, p);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetObjClassDesc_19EDE0")))
void *GetObjClassDesc_19EDE0(void) {
    if (!D_00785E98) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785E98, &D_004266D8, &D_00785798);
    }
    return &D_00785E98;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_19EE30")))
void *InitObjSlots_19EE30(void *a0) {
    char *p = (char *)a0 + 0x620;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(void **)((char *)a0 + 0x214) = &D_004266F0;
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

__attribute__((section(".text.ResetObjVtableAndFree_19EEB8")))
void ResetObjVtableAndFree_19EEB8(void *a0, int a1) {
    void *p;
    *(void **)((char *)a0 + 0x214) = &D_004266F0;
    p = *(void **)((char *)a0 + 0x600);
    if (p) {
        ClearAndResetFields_1FE278(&D_00574380, p);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetObjClassDesc_19F058")))
void *GetObjClassDesc_19F058(void) {
    if (D_00785EA8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785EA8, &D_004267C0, &D_00785798);
    }
    return &D_00785EA8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_19F0A8")))
void *InitObjSlots_19F0A8(void *a0) {
    char *p = (char *)a0 + 0x660;
    int i;
    func_001C7D98(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_004267F8;
    i = 12;
    do {
        VU0_SQC2_VF0(p, 0x00);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        i--;
        p += 0x60;
    } while (i != -1);
    return a0;
}

__attribute__((section(".text.ResetObjVtableAndFree_19F130")))
void ResetObjVtableAndFree_19F130(void *a0, void *a1) {
    void *p;
    *(int *)((char *)a0 + 0x214) = (int)&D_004267F8;
    p = *(void **)((char *)a0 + 0x650);
    if (p != 0) {
        ClearAndResetFields_1FE278(&D_00574380, p);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}
