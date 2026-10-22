#include "godhand/objField.h"
extern char D_00423F58[];
extern int D_00785BE8;
extern int D_00424008;
extern int D_00785878;
extern int D_00424040;
extern int D_00574380;
extern int D_00785BF8;
extern int D_00424110;
extern int D_00785798;
extern int D_00424128;
extern int D_00785C08;
extern char D_004241D8[];
extern char D_007859B8[];
extern char D_004241F0[];
extern int D_00785C18;
extern char D_004242A0[];

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_1901C8")))
void *InitObjSlots_1901C8(char *a0) {
    char *p;
    int i;
    InitFields_1B6E90(a0);
    *(void **)(a0 + 0x214) = (void*)D_00423F58;
    p = a0 + 0x620;
    i = 0x18;
    do {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        i--;
        p += 0x60;
    } while (i != -1);
    *(int*)(a0 + 0xF80) = 0;
    return a0;
}

__attribute__((section(".text.GetObjSingleton_191A60")))
void *GetObjSingleton_191A60(void) {
    if (D_00785BE8 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785BE8, &D_00424008, &D_00785878);
    }
    return &D_00785BE8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_191AB0")))
void *InitObjSlots_191AB0(void *a0) {
    void *p;
    int i;
    InitVtable214_429C80_1C27E8(a0);
    *(int*)((char*)a0+0x214) = (int)&D_00424040;
    p = (char*)a0 + 0x620;
    for (i = 5; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p = (char*)p + 0x60;
    }
    return a0;
}

__attribute__((section(".text.ResetField214FreeField600_191B38")))
void ResetField214FreeField600_191B38(void *a0, int a1) {
    int v1;
    *(int*)((char*)a0+0x214) = (int)&D_00424040;
    v1 = *(int*)((char*)a0+0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int*)((char*)a0+0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetObjSingleton_191CE8")))
void *GetObjSingleton_191CE8(void) {
    if (D_00785BF8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785BF8, &D_00424110, &D_00785798);
    }
    return &D_00785BF8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_191D38")))
void *InitObjSlots_191D38(void *a0) {
    void *p;
    int i;
    func_001BBEB8(a0);
    *(int*)((char*)a0+0x214) = (int)&D_00424128;
    p = (char*)a0 + 0x650;
    for (i = 6; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p = (char*)p + 0x60;
    }
    return a0;
}

__attribute__((section(".text.GetObjSingleton_191F50")))
void *GetObjSingleton_191F50(void) {
    if (D_00785C08 == 0) {
        func_001BD528();
        SetField_0_4_8_31EEA8(&D_00785C08, D_004241D8, D_007859B8);
    }
    return &D_00785C08;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_191FA0")))
void *InitObjSlots_191FA0(void *a0) {
    void *s0 = (char *)a0 + 0x650;
    int s2 = 0;
    func_001BBEB8(a0);
    *(void **)((char *)a0 + 0x214) = D_004241F0;
    do {
        VU0_SQC2_VF0(s0, 0x0);
        VU0_SQC2_VF0(s0, 0x10);
        VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30);
        VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        s2--;
        s0 = (char *)s0 + 0x60;
    } while (s2 != -1);
    return a0;
}

__attribute__((section(".text.GetOrInit_D785C18_1921B8")))
void *GetOrInit_D785C18_1921B8(void) {
    if (D_00785C18 == 0) {
        func_001BD528();
        SetField_0_4_8_31EEA8(&D_00785C18, D_004242A0, D_007859B8);
    }
    return &D_00785C18;
}
