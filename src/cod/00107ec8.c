/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_0041D220[];
extern int D_00462FC0[];
extern void cCollisionSolidManage_ReleaseUnit(void *a0, void *a1);
extern void InitObjectVtableAndRegister_1002C0(void *a0, void *a1);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern float SetMotionStep(void *a0, float f);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);

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
void InitActorWithVtable_107EC8(void *a0, void *a1) {
    *(int **)((char*)a0+0x214) = D_0041D220;
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, a0);
    InitObjectVtableAndRegister_1002C0(a0, a1);
}

__attribute__((section(".text.UpdateBossPhase_10B780")))
void UpdateBossPhase_10B780(void *a0) {
    int st;
    int base;
    *(float*)((char*)a0 + 0x54C) = 5.0f;
    cCollisionSolidManage_SetActive(D_00462FC0, a0, 0);
    *(int*)((char*)a0 + 0x15F4) = *(int*)((char*)a0 + 0x15F4) | 0x2000;
    *(float*)((char*)a0 + 0x5A8) = 1.0f;
    SetMotionStep(a0, 1.0f);
    st = *(unsigned char*)((char*)a0 + 0x2F6);
    switch (st) {
    case 0:
        base = *(int*)((char*)a0 + 0x304);
        func_002A8578(a0, *(int*)((char*)base + 0x28) + base, *(int*)((char*)base + 0x2C) + base, 0.0f, 0xA, 0, 0);
        *(unsigned char*)((char*)a0 + 0x2F6) = *(unsigned char*)((char*)a0 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        moveMotion(a0);
        break;
    case 2:
        *(unsigned char*)((char*)a0 + 0x2F6) = st + 1;
        /* fallthrough */
    case 3:
        if (moveMotion(a0) != 0) {
            *(unsigned char*)((char*)a0 + 0x2F6) = 0;
        }
        break;
    }
    *(unsigned short*)((char*)a0 + 0x3AC) = *(unsigned short*)((char*)a0 + 0x3AC) | 0x404;
}
