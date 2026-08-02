/* sn-2.95.3-136 matched TU. */

extern char D_00428090[];
extern char D_00574380[];
extern void ClearAndResetFields_1FE278(void *a, void *b);
extern void cDamageManage_ReleaseDamageGive(void *a, void *b);
extern void SetField214PtrThenInit_1B6F38(void *a, void *b);
extern char D_00428160[];
extern int D_004283D8;
extern int D_00462FC0;
extern void cCollisionSolidManage_ReleaseUnit(void *, void *);
extern void cOm71_SetMotionWait(int a0);
extern char D_00428928[];
extern char D_00428C20[];
extern int D_00747A80;
extern int cGameObj_isClip();
extern int IsTargetVisible_14B470();

__attribute__((section(".text.func_001AE8B0")))
void func_001AE8B0(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00428090;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x604);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x604) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.func_001B02C8")))
void func_001B02C8(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00428160;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x604);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x604) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */





__attribute__((section(".text.func_001B1B78")))
void func_001B1B78(void *a0, void *a1) {
    *(int **)((char*)a0 + 0x214) = &D_004283D8;
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, a0);
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */


__attribute__((section(".text.func_001B1E00")))
void func_001B1E00(void *a0) {
    cOm71_SetMotionWait(a0);
    *(char *)((char *)a0 + 0x2F4) = 1;
}

__attribute__((section(".text.func_001B6758")))
void func_001B6758(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00428928;
    v1 = *(int *)((char *)a0 + 0x624);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x624) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x620);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x620) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.func_001B87F0")))
void func_001B87F0(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00428C20;
    v1 = *(int *)((char *)a0 + 0x624);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x624) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x620);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x620) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.func_002684A0")))
int func_002684A0(void *a0) {
    char *s0 = (char *)&D_00747A80;
    int v;
    if (D_00747A80 & 0x40000000) return 1;
    if (cGameObj_isClip(a0) != 0) return 1;
    v = *(int *)(s0 - 0x54) & 0x400000;
    return v != 0;
}

/* clone */



__attribute__((section(".text.func_00276940")))
int func_00276940(int a0) {
    if (D_00747A80 & 0x40000000) {
        return 1;
    }
    return IsTargetVisible_14B470(a0) != 0;
}

__attribute__((section(".text.func_00277F18")))
int func_00277F18(void *a0) {
    char *s0 = (char *)&D_00747A80;
    int v;
    if (D_00747A80 & 0x40000000) return 1;
    if (cGameObj_isClip(a0) != 0) return 1;
    v = *(int *)(s0 - 0x54) & 0x400000;
    return v != 0;
}

__attribute__((section(".text.func_002798D0")))
int func_002798D0(void *a0) {
    char *s0 = (char *)&D_00747A80;
    int v;
    if (D_00747A80 & 0x40000000) return 1;
    if (cGameObj_isClip(a0) != 0) return 1;
    v = *(int *)(s0 - 0x54) & 0x400000;
    return v != 0;
}
