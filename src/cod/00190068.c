#include "godhand/cDamageManage.h"
#include "godhand/globals.h"

extern int D_005CAE50;
extern int D_00423F58;
extern int D_00785798;

__attribute__((section(".text.SetStateDisabled_190068")))
void SetStateDisabled_190068(void *a0) {
    int v0;
    v0 = (*(int*)((char*)a0 + 0x5B0) & -9) | 4;
    *(int*)((char*)a0 + 0x5B0) = v0;
    if (*(int*)((char*)a0 + 0x654) != 0) {
        cDamageUnit_SetDamageCollActive(*(cDamageUnit **)((char*)a0 + 0x654), 0);
    }
    cCollisionScroll_SetCollEnableByName((int)&D_005CAE50, *(double*)((char*)a0 + 0x540), 0);
    ClearStateAndFlag_1C7E08(a0);
}

__attribute__((section(".text.FreeMultiSlotResources_190250")))
void FreeMultiSlotResources_190250(void *a0, void *a1) {
    int *p;
    int i;
    int v;
    cDamageGive *give;
    *(int *)((char *)a0 + 0x214) = (int)&D_00423F58;
    p = (int *)((char *)a0 + 0x600);
    for (i = 3; i >= 0; i--) {
        v = *p;
        if (v != 0) {
            ClearAndResetFields_1FE278(&D_00574380, (void *)v);
            *p = 0;
        }
        p++;
    }
    give = *(cDamageGive **)((char *)a0 + 0x610);
    if (give != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, give);
        *(int *)((char *)a0 + 0x610) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.UpdateSlotHitCounters_190BF0")))
void UpdateSlotHitCounters_190BF0(void *a0) {
    short *s2 = (short *)((char *)a0 + 0xF88);
    int *s1 = (int *)((char *)a0 + 0x600);
    int s3 = 0;
    do {
        int r = cOmBase_checkDamage(a0, *s1);
        if (r == 1) {
            int *obj = (int *)*s1;
            int v1 = (int)*(unsigned short *)s2 - *(int *)((char *)obj + 0x4C);
            *s2 = (short)v1;
            if ((short)v1 < 0) {
                *(int *)((char *)a0 + 0x5B0) |= 1;
                *(char *)((char *)a0 + 0xF90) = (char)s3;
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
        s3++;
        s2++;
        s1++;
    } while (s3 < 4);
}

__attribute__((section(".text.SetSlotEntryBitFlag_191860")))
void SetSlotEntryBitFlag_191860(void *a0, int a1) {
    cDamageUnit **ebase = (cDamageUnit **)((char *)a0 + 0x600);
    int *base;
    if (ebase[a1] != 0) cDamageUnit_SetDamageCollActive(ebase[a1], 0);
    base = (int *)((char *)a0 + 0xF80);
    base[(unsigned int)a1 >> 5] |= (unsigned int)0x80000000 >> (a1 & 0x1F);
}

__attribute__((section(".text.GetInstance_192F18")))
void *GetInstance_192F18(void) {
    if (D_00785C48[0] == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(D_00785C48, &D_004245A8, &D_00785798);
    }
    return D_00785C48;
}

__attribute__((section(".text.ResetField214FreeField600I_193278")))
int ResetField214FreeField600I_193278(char *a0, void *a1) {
    int v1;
    *(int *)(a0 + 0x214) = (int)&D_004246A8;
    v1 = *(int *)(a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)(a0 + 0x600) = 0;
    }
    return ResetField214FreeField180_1C2820(a0, a1);
}
