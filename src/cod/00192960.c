extern int D_00785C28;
extern char D_004243D8[];
extern char D_00785878[];
extern char D_004243F0[];
#include "godhand/objField.h"
extern int D_00574380;
extern int D_00785C38;
extern int D_004244C0;
extern int D_00785798;
extern int D_004244D8;
extern int D_004245C0;

__attribute__((section(".text.GetOrInit_D_00785C28_192960")))
void *GetOrInit_D_00785C28_192960(void) {
    if (D_00785C28 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785C28, D_004243D8, D_00785878);
    }
    return &D_00785C28;
}

#include "godhand/vu0.h"





__attribute__((section(".text.Obj1929_Setup_1929B0")))
void *Obj1929_Setup_1929B0(void *a0) {
    char *p;
    int i = 5;
    int end;
    InitVtable214_429C80_1C27E8(a0);
    p = (char*)a0 + 0x620;
    end = -1;
    *(void**)((char*)a0 + 0x214) = D_004243F0;
    for (; i != end; i--) {
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

__attribute__((section(".text.ResetField214FreeField600B_192A38")))
void *ResetField214FreeField600B_192A38(void *a0, void *a1) {
    *(int **)((char *)a0 + 0x214) = &D_004243F0;
    {
        void *v1 = *(void **)((char *)a0 + 0x600);
        if (v1) {
            ClearAndResetFields_1FE278(&D_00574380, v1);
            *(int *)((char *)a0 + 0x600) = 0;
        }
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetObjSingleton_192BE8")))
void *GetObjSingleton_192BE8(void) {
    if (D_00785C38 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785C38, &D_004244C0, &D_00785798);
    }
    return &D_00785C38;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_192C38")))
void *InitObjSlots_192C38(void *a0) {
    char *s0 = (char *)a0 + 0x620;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char *)a0 + 0x214) = &D_004244D8;
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

__attribute__((section(".text.ResetField214FreeField600C_192CC0")))
void *ResetField214FreeField600C_192CC0(void *a0, void *a1) {
    *(int **)((char *)a0 + 0x214) = &D_004244D8;
    {
        void *v1 = *(void **)((char *)a0 + 0x600);
        if (v1) {
            ClearAndResetFields_1FE278(&D_00574380, v1);
            *(int *)((char *)a0 + 0x600) = 0;
        }
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_192F68")))
void *InitObjSlots_192F68(void *a0) {
    char *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char *)a0 + 0x214) = &D_004245C0;
    p = (char *)a0 + 0x620;
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

__attribute__((section(".text.ResetField214FreeField600D_192FF0")))
void *ResetField214FreeField600D_192FF0(void *a0, int a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004245C0;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    return ResetField214FreeField180_1C2820(a0, a1);
}
