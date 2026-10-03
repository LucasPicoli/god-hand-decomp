/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern void func_00383438(void *, void *);
extern void func_0031C900(int);
extern void *InitFields_1B6E90(void *a0);
extern int D_00428C20;
extern int InitStructAndSubfields_1E8DA8(int a0);
extern int cSceAtManager_SetDisableById(int a0, int a1);
extern void cScenario_taskExec(void *a0, void *a1, void *a2, int a3);
extern char D_005FEA60[];
extern char *D_003C2F84;
extern void func_001DFDE0(void);

/* Run the sub-object update at +0x370, then free its sound handle at +0xFC. */



__attribute__((section(".text.UpdateChildAndFreeSoundHandle")))
void UpdateChildAndFreeSoundHandle(void *a0) {
    char *p = (char *)a0 + 0x370;
    func_00383438(a0, p);
    if (*(int *)(p + 0xFC) != 0) {
        func_0031C900(*(int *)(p + 0xFC));
        *(int *)(p + 0xFC) = 0;
    }
}

/* Init the base fields, set the vtable-like pointer at +0x214 and clear the VU0 and tail fields. */




__attribute__((section(".text.InitAndClearVuFieldsB")))
void *InitAndClearVuFieldsB(char *a0) {
    InitFields_1B6E90(a0);
    *(int **)(a0 + 0x214) = &D_00428C20;
    VU0_SQC2_VF0(a0, 0x600);
    VU0_SQC2_VF0(a0, 0x610);
    *(char *)(a0 + 0x630) = 0;
    *(int *)(a0 + 0x620) = 0;
    return a0;
}

/* Init the base record, then set the float at +0xBC and clear the fields at +0xC0, +4, +8 and +0xC. */


__attribute__((section(".text.InitStructSubfieldsAndFloatB")))
int InitStructSubfieldsAndFloatB(int a0)
{
    InitStructAndSubfields_1E8DA8(a0);
    *(int *)(a0 + 0xC0) = 0;
    *(float *)(a0 + 0xBC) = 0.13425609469413757f;
    *(int *)(a0 + 4) = 0;
    *(int *)(a0 + 8) = 0;
    *(int *)(a0 + 0xC) = 0;
    return a0;
}

/* Zero the head word and the two sub-blocks at +4 (0xC bytes) and +0x14 (0x80 bytes); return the record. */


__attribute__((section(".text.ClearHeadAndSubblocksReturnSelf")))
int *ClearHeadAndSubblocksReturnSelf(int *a0) {
    a0[0] = 0;
    func_003A52F0((int)((char *)a0 + 0x4), 0, 0xC);
    func_003A52F0((int)((char *)a0 + 0x14), 0, 0x80);
    return a0;
}

/* Disable the scenario object tied to this machine's slot id, then queue its step task. */






__attribute__((section(".text.ActBtnHandler_Variant1")))
void ActBtnHandler_Variant1(char *self) {
    cSceAtManager_SetDisableById((int)D_005FEA60, *(unsigned short *)(self + 0x48C));
    cScenario_taskExec(D_003C2F84, (void *)&func_001DFDE0, self, -1);
}
