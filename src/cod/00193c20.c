extern int D_00424A48;
#include "godhand/objField.h"
extern int D_00785CC8;
extern int D_00424D00;
extern int D_00785798;
extern int D_00785CD8;
extern int D_00424DC8;
extern int D_00785878;
extern int D_00424E18;
extern int D_00574380;
extern int D_00785CE8;
extern int D_00424EC8;

#include "godhand/vu0.h"



__attribute__((section(".text.InitSlotVu0DataC_193C20")))
void *InitSlotVu0DataC_193C20(void *a0) {
    void *s0;
    int i = 3;
    InitVtable214_429C80_1C27E8(a0);
    *(int **)((char*)a0 + 0x214) = &D_00424A48;
    s0 = (char *)a0 + 0x620;
    do {
        VU0_SQC2_VF0(s0, 0x0);
        VU0_SQC2_VF0(s0, 0x10);
        VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30);
        VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        s0 = (char *)s0 + 0x60;
    } while (--i != -1);
    return a0;
}

__attribute__((section(".text.GetBInstance_195E78")))
void *GetBInstance_195E78(void) {
    int *p = &D_00785CC8;
    if (*p == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(p, &D_00424D00, &D_00785798);
    }
    return p;
}

__attribute__((section(".text.GetInstance_196008")))
void *GetInstance_196008(void) {
    int *p = &D_00785CD8;
    if (*p == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(p, &D_00424DC8, &D_00785878);
    }
    return p;
}

#include "godhand/vu0.h"



__attribute__((section(".text.InitObjSlotArray_196058")))
void *InitObjSlotArray_196058(void *a0) {
    char *s0;
    int i;
    InitFields_1B6E90(a0);
    *(int **)((char*)a0 + 0x214) = &D_00424E18;
    s0 = (char*)a0 + 0x610;
    i = 9;
    do {
        VU0_SQC2_VF0(s0, 0x0);
        VU0_SQC2_VF0(s0, 0x10);
        VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30);
        VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        i -= 1;
        s0 += 0x60;
    } while (i != -1);
    *(int*)((char*)a0 + 0x9D0) = 0;
    return a0;
}

__attribute__((section(".text.FreeObjSlotArray_1960E0")))
void FreeObjSlotArray_1960E0(void *a0, int a1) {
    int *s0;
    int i;
    *(int **)((char*)a0 + 0x214) = &D_00424E18;
    s0 = (int *)((char*)a0 + 0x600);
    i = 0;
    do {
        int v = *s0;
        if (v != 0) {
            ClearAndResetFields_1FE278(&D_00574380, v);
            *s0 = 0;
        }
        i -= 1;
        s0 += 1;
    } while (i >= 0);
    {
        int w = *(int*)((char*)a0 + 0x604);
        if (w != 0) {
            cDamageManage_ReleaseDamageGive(&D_00574380, w);
            *(int*)((char*)a0 + 0x604) = 0;
        }
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.UpdateSlotTimerState_1968A0")))
void UpdateSlotTimerState_1968A0(void *a0) {
    unsigned short *p9D8;
    int *p600;
    int i;
    p9D8 = (unsigned short *)((char*)a0 + 0x9D8);
    p600 = (int *)((char*)a0 + 0x600);
    i = 0;
    do {
        int r = cOmBase_checkDamage(a0, *p600);
        if (r == 1) {
            int p = *p600;
            int diff = (int)*p9D8 - *(int*)((char*)p + 0x4C);
            *(short*)p9D8 = (short)diff;
            if ((short)diff < 0) {
                *(char*)((char*)a0 + 0x9DA) = (char)i;
                *(int*)((char*)a0 + 0x5B0) |= 1;
                *(char*)((char*)a0 + 0x2F4) = 2;
                *(char*)((char*)a0 + 0x2F5) = 0;
                *(char*)((char*)a0 + 0x2F6) = 0;
                *(char*)((char*)a0 + 0x2F7) = 0;
            } else {
                *(char*)((char*)a0 + 0x2F4) = (char)r;
                *(char*)((char*)a0 + 0x2F5) = 0;
                *(char*)((char*)a0 + 0x2F6) = 0;
                *(char*)((char*)a0 + 0x2F7) = 0;
            }
        }
        p9D8 += 1;
        i += 1;
        p600 += 1;
    } while (i <= 0);
}

__attribute__((section(".text.SetSlotDeadBit_197430")))
void SetSlotDeadBit_197430(int *a0, unsigned int a1) {
    int v = *(int *)((char *)a0 + (a1 << 2) + 0x600);
    int *p;
    if (v != 0) {
        cDamageUnit_SetDamageCollActive(v, 0);
    }
    v = a1 >> 5;
    p = a0 + 0x274;
    p[v] = p[v] | (0x80000000U >> (a1 & 0x1F));
}

__attribute__((section(".text.GetInstanceB_197630")))
void *GetInstanceB_197630(void) {
    if (D_00785CE8 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785CE8, &D_00424EC8, &D_00785878);
    }
    return &D_00785CE8;
}
