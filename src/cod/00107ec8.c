/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_0041D220[];
extern void cPlBase__dtor(void *a0, int flags);
extern float SetMotionStep(void *a0, float f);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"

__attribute__((section(".text.cCockMess_SetMessNo")))
void cCockMess_SetMessNo(char *a0, unsigned short a1, unsigned char a2, float f12, float f13) {
    if (*(int *)(a0 + 0x9C) == 0xFFFF) {
        *(int *)(a0 + 0x9C) = a1;
        *(float *)(*(char **)(a0 + 0x90) + 0x38) = f12;
        *(float *)(*(char **)(a0 + 0x90) + 0x3C) = f13;
        *(char *)(*(char **)(a0 + 0x98) + 0x4F) = a2;
    }
}

__attribute__((section(".text.ResetAnimSlotArray_13F510")))
void ResetAnimSlotArray_13F510(char *a0) {
    short i;
    for (i = 4; i >= 0; i--) {
        char *v1 = a0 + 0xB8 - (4 - i) * 4;
        *(int *)(v1 + 0x1A8) = 0;
        *(float *)(v1 + 0x218) = 1.0f;
        *(int *)(v1 + 0x0) = 0;
    }
    *(int *)(a0 + 0xA0) = 0;
    *(char *)(a0 + 0x358) = 0;
    *(char *)(a0 + 0x384) = 0;
}

__attribute__((section(".text.InitActorWithVtable_107EC8")))
void InitActorWithVtable_107EC8(void *a0, int flags) {
    *(int **)((char*)a0+0x214) = D_0041D220;
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, a0);
    cPlBase__dtor(a0, flags);
}

/* The player's mode-5 (sub-screen) handler, entry 5 of the mode table D_003BD0B8. */
__attribute__((section(".text.StepPlayerSubscreenMode_10B780")))
void StepPlayerSubscreenMode_10B780(cGameObj *a0) {
    int st;
    int base;
    a0->hitFlash = 5.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, a0, 0);
    *(int*)((char*)a0 + 0x15F4) = *(int*)((char*)a0 + 0x15F4) | 0x2000;
    a0->speedRate = 1.0f;
    SetMotionStep(a0, 1.0f);
    st = a0->step;
    switch (st) {
    case 0:
        base = *(int*)((char*)a0 + 0x304);
        func_002A8578(a0, *(int*)((char*)base + 0x28) + base, *(int*)((char*)base + 0x2C) + base, 0xA, 0.0f, 0, 0);
        a0->step = a0->step + 1;
        /* fallthrough */
    case 1:
        moveMotion(a0);
        break;
    case 2:
        a0->step = st + 1;
        /* fallthrough */
    case 3:
        if (moveMotion(a0) != 0) {
            a0->step = 0;
        }
        break;
    }
    a0->seqFlags = a0->seqFlags | 0x404;
}
