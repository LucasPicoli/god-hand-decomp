#include "godhand/vu0.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"
extern int D_00747A30;
extern int D_0044F448;

/* Plays the big-hit effect unless its wait runs or flag 0x800 of
 * D_00747A30 is set, then starts the wait. */
__attribute__((section(".text.cEmManage_setBigHitEff")))
void cEmManage_setBigHitEff(cEmManage *self)
{
    if ((D_00747A30 & 0x800) == 0) {
        if (cEmManage_CkBigHitEffWait(self) == 0) {
            SetEffect(0, 0xF, 0, 0, -1, 0xFFFFFFFFu);
            cEmManage_SetBigHitEffWait(self, EM_BIG_HIT_EFF_TIME);
        }
    }
}

__attribute__((section(".text.SetCostumeFlagIfMatch_2982A0")))
void SetCostumeFlagIfMatch_2982A0(int a0)
{
    int *s1 = (int *)a0;
    unsigned short s0;
    int v1;

    if (s1 != 0) {
        s0 = *(unsigned short *)((char *)s1 + 0x2FE);
        v1 = cCoreSave_getCostumeNo(&D_00569B70);
        if (s0 == 0x603) {
            if ((unsigned int)((v1 - 4) & 0xFF) < 2) {
                *(int *)((char *)s1 + 0x250) = *(int *)((char *)s1 + 0x250) | 2;
            }
        }
    }
}

/* A slot is usable when its entry is not loaded yet, or is idle. */
__attribute__((section(".text.cSnd_SeIsLoadOk")))
int cSnd_SeIsLoadOk(cSnd *self, int slot)
{
	int usable;

	usable = 1;
	if (cSeData_IsFree(cSnd_GetSeData(self, slot)) == 1) {
		return 1;
	}
	if (cSeData_IsFailed(cSnd_GetSeData(self, slot)) != 0) {
		usable = 0;
	}
	return usable;
}

/* Finds the first slot in 0x14..0x33 whose entry is idle, or -1. */
__attribute__((section(".text.cSnd_FindFreeSeSlot")))
int cSnd_FindFreeSeSlot(cSnd *self)
{
	int slot;

	for (slot = 0x14; slot < 0x34; slot++) {
		if (cSeData_IsFree(&self->seEntry[slot]) == 1) {
			return slot;
		}
	}
	return -1;
}





__attribute__((section(".text.Setup_Fields_2B0_2F56C0")))
void *Setup_Fields_2B0_2F56C0(void *a0)
{
	InitObject_2FBCC8(a0);

	*(int *)((char *)a0 + 0x2B0) = 0;
	*(float *)((char *)a0 + 0x2D4) = 1.0f;
	*(int **)((char *)a0 + 0xF0) = &D_0044F448;
	*(int *)((char *)a0 + 0x2B4) = 0;
	*(int *)((char *)a0 + 0x2B8) = 0;
	*(int *)((char *)a0 + 0x2BC) = 0;
	*(int *)((char *)a0 + 0x2C0) = 0;
	*(int *)((char *)a0 + 0x2C4) = 0;
	*(int *)((char *)a0 + 0x2C8) = 0;
	*(int *)((char *)a0 + 0x2D8) = 0;
	*(int *)((char *)a0 + 0x2DC) = 0;
	VU0_SQC2_VF0(a0, 0x300);
	*(int *)((char *)a0 + 0x2F0) = 0;
	return a0;
}
