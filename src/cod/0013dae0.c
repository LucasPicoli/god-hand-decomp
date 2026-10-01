#include "godhand/cCoreSave.h"
extern int D_00747A84;
extern int D_00420070;
extern char D_00574380[];
extern char D_007419A0[];
extern int D_00420158;
extern int D_00420240;

__attribute__((section(".text.UpdateStateAndClearFlag_3734F0")))
void UpdateStateAndClearFlag_3734F0(void *a0)
{
	if (func_00373A50(a0) != 0) {
		if (func_00373B20(a0) == 1) {
			func_00374598(a0);
		} else {
			func_00373FC8(a0);
		}
		*(int *)((char *)a0 + 0x4C) &= 0xFFFFFFFD;
	}
}

__attribute__((section(".text.func_0013DAE0")))
void func_0013DAE0(void *a0)
{
	int v1;

	v1 = D_00747A84;
	if ((v1 & 0x08000000) != 0) {
		return;
	}
	if ((v1 & 0x02000000) != 0) {
		return;
	}
	if ((D_00569B70.data->flags & 0x04000000) != 0) {
		cIDBase_trans((char *)a0 + 0xD0);
	}
	cIDBase_trans(a0);
}

__attribute__((section(".text.SetStateEntry0x258_16F438")))
void SetStateEntry0x258_16F438(int *a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)&D_00420070;
    if (*(int *)((char *)a0 + 0x600) != 0) {
        ClearAndResetFields_1FE278(D_00574380, *(int *)((char *)a0 + 0x600));
        *(int *)((char *)a0 + 0x600) = 0;
    }
    espSys_effDataRelease(D_007419A0, 0x258);
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.SetStateEntry0x259_16F720")))
void SetStateEntry0x259_16F720(int *a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)&D_00420158;
    if (*(int *)((char *)a0 + 0x600) != 0) {
        ClearAndResetFields_1FE278(D_00574380, *(int *)((char *)a0 + 0x600));
        *(int *)((char *)a0 + 0x600) = 0;
    }
    espSys_effDataRelease(D_007419A0, 0x259);
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.SetStateEntry0x25A_16FA10")))
void SetStateEntry0x25A_16FA10(int *a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)&D_00420240;
    if (*(int *)((char *)a0 + 0x600) != 0) {
        ClearAndResetFields_1FE278(D_00574380, *(int *)((char *)a0 + 0x600));
        *(int *)((char *)a0 + 0x600) = 0;
    }
    espSys_effDataRelease(D_007419A0, 0x25A);
    ResetField214FreeField180_1C2820(a0, a1);
}
