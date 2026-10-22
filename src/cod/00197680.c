extern int D_00424F28;
#include "godhand/objField.h"
extern int D_00574380;
extern int D_00785CF8;
extern int D_00424FD8;
extern int D_00785878;
extern int D_00425000;
extern int D_00785D08;
extern int D_004250B8;
extern int D_00785808;
extern int D_004250F0;
extern int D_00785D18;
extern int D_004251A8;
extern int D_007858B8;
extern int D_004251C0;

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlotArrayB_197680")))
void *InitObjSlotArrayB_197680(void *a0) {
    char *s0 = (char *)a0 + 0x610;
    int i = 9;
    InitFields_1B6E90(a0);
    *(int **)((char *)a0 + 0x214) = &D_00424F28;
    do {
        VU0_SQC2_VF0(s0, 0x0);
        VU0_SQC2_VF0(s0, 0x10);
        VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30);
        VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        s0 += 0x60;
        i--;
    } while (i != -1);
    *(int *)((char *)a0 + 0x9D0) = 0;
    return a0;
}

__attribute__((section(".text.FreeObjSlotArrayB_197708")))
void *FreeObjSlotArrayB_197708(void *a0, void *a1) {
    int *p = (int *)((char *)a0 + 0x600);
    int i = 0;
    *(int **)((char *)a0 + 0x214) = &D_00424F28;
    do {
        if (*p != 0) {
            ClearAndResetFields_1FE278(&D_00574380, *p);
            *p = 0;
        }
        p++;
        i--;
    } while (i >= 0);
    if (*(int *)((char *)a0 + 0x604) != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, *(int *)((char *)a0 + 0x604));
        *(int *)((char *)a0 + 0x604) = 0;
    }
    return SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.UpdateSlotTimerStateB_197EC8")))
void UpdateSlotTimerStateB_197EC8(void *a0) {
    short *q = (short *)((char *)a0 + 0x9D8);
    int *p = (int *)((char *)a0 + 0x600);
    int i = 0;
    do {
        int r = cOmBase_checkDamage(a0, *p);
        if (r == 1) {
            void *obj = (void *)*p;
            int diff = (int)*(unsigned short *)q - *(int *)((char *)obj + 0x4C);
            *q = (short)diff;
            if ((short)diff < 0) {
                *(char *)((char *)a0 + 0x9DA) = (char)i;
                *(int *)((char *)a0 + 0x5B0) |= 1;
                *(char *)((char *)a0 + 0x2F4) = 2;
                *(char *)((char *)a0 + 0x2F5) = 0;
                *(char *)((char *)a0 + 0x2F6) = 0;
                *(char *)((char *)a0 + 0x2F7) = 0;
            } else {
                *(char *)((char *)a0 + 0x2F4) = (char)r;
                *(char *)((char *)a0 + 0x2F5) = 0;
                *(char *)((char *)a0 + 0x2F6) = 0;
                *(char *)((char *)a0 + 0x2F7) = 0;
            }
        }
        q += 1;
        p++;
    } while (++i <= 0);
}

__attribute__((section(".text.SetSlotDeadBitB_198A58")))
void SetSlotDeadBitB_198A58(int a0, unsigned int a1) {
    int *p = (int *)(a0 + a1 * 4 + 0x600);
    if (*p != 0) {
        cDamageUnit_SetDamageCollActive(*p, 0);
    }
    {
        unsigned int *base = (unsigned int *)(a0 + 0x9D0);
        base[a1 >> 5] |= (0x80000000U >> (a1 & 0x1F));
    }
}

__attribute__((section(".text.GetInstanceC_198C58")))
void *GetInstanceC_198C58(void) {
    if (D_00785CF8 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785CF8, &D_00424FD8, &D_00785878);
    }
    return &D_00785CF8;
}

__attribute__((section(".text.InitObjVtableC_198CA8")))
void *InitObjVtableC_198CA8(void *a0) {
    func_001BFAC8(a0);
    *(int **)((char *)a0 + 0x214) = &D_00425000;
    return a0;
}

__attribute__((section(".text.FreeObjSlotC_198CE0")))
void *FreeObjSlotC_198CE0(void *a0, int a1) {
    *(int **)((char *)a0 + 0x214) = &D_00425000;
    if (*(int *)((char *)a0 + 0x600) != 0) {
        ClearAndResetFields_1FE278(&D_00574380, *(int *)((char *)a0 + 0x600));
        *(int *)((char *)a0 + 0x600) = 0;
    }
    return func_001BFB00(a0, a1);
}

__attribute__((section(".text.GetInstanceD_198F68")))
int *GetInstanceD_198F68(void) {
    if (D_00785D08 == 0) {
        func_001C0018();
        SetField_0_4_8_31EEA8(&D_00785D08, &D_004250B8, &D_00785808);
    }
    return &D_00785D08;
}

#include "godhand/vu0.h"



__attribute__((section(".text.InitObjSlotArrayD_198FB8")))
void *InitObjSlotArrayD_198FB8(void *a0) {
    char *s0;
    int i;
    func_001C7D98(a0);
    *(int **)((char *)a0 + 0x214) = &D_004250F0;
    i = 8;
    s0 = (char *)a0 + 0x660;
    do {
        VU0_SQC2_VF0(s0, 0x0); VU0_SQC2_VF0(s0, 0x10); VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30); VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        i--; s0 += 0x60;
    } while (i != -1);
    return a0;
}

__attribute__((section(".text.FreeObjSlotD_199040")))
void FreeObjSlotD_199040(void *a0, int a1) {
    int v1;
    *(int **)((char*)a0 + 0x214) = &D_004250F0;
    v1 = *(int *)((char*)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, v1);
        *(int *)((char*)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

__attribute__((section(".text.UpdateSlotHpState_1993C8")))
void UpdateSlotHpState_1993C8(void *a0) {
    int v1;
    v1 = cOmBase_checkDamage(a0, *(int *)((char*)a0 + 0x650));
    if (v1 == 1) {
        if (*(short *)((char*)a0 + 0x54A) <= 0) {
            int v3 = *(int *)((char*)a0 + 0x5B0);
            *(char *)((char*)a0 + 0x2F4) = 2;
            *(char *)((char*)a0 + 0x2F5) = 0;
            *(char *)((char*)a0 + 0x2F6) = 0;
            *(char *)((char*)a0 + 0x2F7) = 0;
            *(int *)((char*)a0 + 0x5B0) = v3 | 1;
        } else {
            *(char *)((char*)a0 + 0x2F4) = (char)v1;
            *(char *)((char*)a0 + 0x2F5) = 0;
            *(char *)((char*)a0 + 0x2F6) = 0;
            *(char *)((char*)a0 + 0x2F7) = 0;
        }
    }
}

__attribute__((section(".text.GetInstanceE_199D70")))
void *GetInstanceE_199D70(void) {
    if (D_00785D18 == 0) {
        func_001C8F30();
        SetField_0_4_8_31EEA8(&D_00785D18, &D_004251A8, &D_007858B8);
    }
    return &D_00785D18;
}

__attribute__((section(".text.InitObjVtableE_199DC0")))
void *InitObjVtableE_199DC0(void *a0) {
    func_001BFAC8(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_004251C0;
    return a0;
}

__attribute__((section(".text.FreeObjSlotE_199DF8")))
void FreeObjSlotE_199DF8(void *a0, void *a1) {
    int v1;
    *(int *)((char *)a0 + 0x214) = (int)&D_004251C0;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}
