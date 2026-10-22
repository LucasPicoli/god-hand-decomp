/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_00785E68;
extern unsigned char D_00426420[];
extern unsigned char D_00785798[];
extern void GetOrInitGlobal785798_1C3BE8(void);
extern void SetField_0_4_8_31EEA8(void *, unsigned char *, unsigned char *);
extern int D_00426438;
extern void InitVtable214_429C80_1C27E8(void *);
#include "godhand/objField.h"
extern char D_00574380[];
extern void ClearAndResetFields_1FE278(void *, int);
extern void ResetField214FreeField180_1C2820(void *, int);
extern int D_00785E78;
extern int D_00426508;
extern int D_00426520;
extern int D_00785E88;
extern int D_004265F0;
extern int D_00426608;

__attribute__((section(".text.GetObjClassDesc_19E670")))
void *GetObjClassDesc_19E670(void) {
    if (D_00785E68 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785E68, D_00426420, D_00785798);
    }
    return &D_00785E68;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_19E6C0")))
void *InitObjSlots_19E6C0(void *a0) {
    char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    p = (char *)a0 + 0x620;
    *(int **)((char *)a0 + 0x214) = &D_00426438;
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

__attribute__((section(".text.ResetObjVtableAndFree_19E748")))
void ResetObjVtableAndFree_19E748(void *a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)&D_00426438;
    if (*(int *)((char *)a0 + 0x600) != 0) {
        ClearAndResetFields_1FE278(D_00574380, *(int *)((char *)a0 + 0x600));
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetObjClassDesc_19E8E8")))
int *GetObjClassDesc_19E8E8(void) {
    if (D_00785E78 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785E78, &D_00426508, &D_00785798);
    }
    return &D_00785E78;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_19E938")))
void *InitObjSlots_19E938(void *a0) {
    char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_00426520;
    p = (char *)a0 + 0x620;
    for (i = 5; i != -1; i--) {
        VU0_SQC2_VF0(p, 0);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }
    return a0;
}

__attribute__((section(".text.ResetObjVtableAndFree_19E9C0")))
void ResetObjVtableAndFree_19E9C0(void *a0, int a1) {
    int v;
    *(int *)((char *)a0 + 0x214) = (int)&D_00426520;
    v = *(int *)((char *)a0 + 0x600);
    if (v != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetObjClassDesc_19EB68")))
int *GetObjClassDesc_19EB68(void) {
    if (D_00785E88 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785E88, &D_004265F0, &D_00785798);
    }
    return &D_00785E88;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_19EBB8")))
void *InitObjSlots_19EBB8(void *a0) {
    char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_00426608;
    p = (char *)a0 + 0x620;
    for (i = 3; i != -1; i--) {
        VU0_SQC2_VF0(p, 0);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }
    return a0;
}
