extern int D_00426E78;
#include "godhand/objField.h"
extern int D_005CAE50;

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_1A0D68")))
void *InitObjSlots_1A0D68(void *a0)
{
    char *s0 = (char *)a0 + 0x610;
    int i;
    InitFields_1B6E90(a0);
    *(int **)((char *)a0 + 0x214) = &D_00426E78;
    for (i = 0x13; i != -1; i--) {
        VU0_SQC2_VF0(s0, 0x0);
        VU0_SQC2_VF0(s0, 0x10);
        VU0_SQC2_VF0(s0, 0x20);
        VU0_SQC2_VF0(s0, 0x30);
        VU0_SQC2_VF0(s0, 0x40);
        Obj0000_Set_Byte_54(s0, 0);
        s0 += 0x60;
    }
    *(int *)((char *)a0 + 0xD90) = 0;
    return a0;
}

__attribute__((section(".text.ClearObjActiveFlag_199C68")))
void ClearObjActiveFlag_199C68(void *a0)
{
    int v0;
    v0 = (*(int*)((char*)a0 + 0x5B0) & -9) | 4;
    *(int*)((char*)a0 + 0x5B0) = v0;
    if (*(int*)((char*)a0 + 0x650) != 0) {
        cDamageUnit_SetDamageCollActive(*(int*)((char*)a0 + 0x650), 0);
    }
    func_001331B8((int)&D_005CAE50, *(double*)((char*)a0 + 0x540), 0);
    ClearStateAndFlag_1C7E08(a0);
}
