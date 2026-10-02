/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern char D_00429C80[];
extern char D_00574380[];
extern void ClearAndResetFields_1FE278(char *, int);
extern void SetField214PtrThenInit_1B6F38(int *, int);
extern int D_00785798;
extern int D_00429D50;
extern int D_00785878;
extern void GetOrInitGlobal785878_1B8058(void);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern int D_007863C8;
extern int D_00786598;
extern int D_0044FBA8;
extern int D_00460D58;
extern int D_0044FBB8;
extern void GetOrInit_460D58_2B6528(void);
extern int SignalSema(int sema);
extern int SleepThread(void);
extern void cGameObj_SetTgtTurn(char *a0, int a1, float f12);

__attribute__((section(".text.ResetField214FreeField180_1C2820")))
void ResetField214FreeField180_1C2820(int *a0, int a1) {
    *(char **)((char *)a0 + 0x214) = D_00429C80;
    if (a0[0x180] != 0) {
        ClearAndResetFields_1FE278(D_00574380, a0[0x180]);
        a0[0x180] = 0;
    }
    if (a0[0x181] != 0) {
        ClearAndResetFields_1FE278(D_00574380, a0[0x180]);
        a0[0x180] = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.GetOrInitGlobal785798_1C3BE8")))
void *GetOrInitGlobal785798_1C3BE8(void)
{
    if (D_00785798 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785798, &D_00429D50, &D_00785878);
    }
    return &D_00785798;
}

__attribute__((section(".text.GetOrInitGlobal7863C8_300148")))
void *GetOrInitGlobal7863C8_300148(void)
{
    if (D_007863C8 == 0) {
        if (D_00786598 == 0) {
            GetOrInit_460D58_2B6528();
            SetField_0_4_8_31EEA8(&D_00786598, &D_0044FBA8, &D_00460D58);
        }
        SetField_0_4_8_31EEA8(&D_007863C8, &D_0044FBB8, &D_00786598);
    }
    return &D_007863C8;
}

__attribute__((section(".text.cTaskWork_sleep")))
void cTaskWork_sleep(char *a0, int a1)
{
    *(short *)(a0 + 0xC) = 1;
    *(short *)(a0 + 0xE) = (short)a1;
    SignalSema(*(int *)(*(int *)(a0 + 0x0) + 0x28));
    SleepThread();
}

__attribute__((section(".text.InvokeVirtualAtField214AndForward_124E68")))
void InvokeVirtualAtField214AndForward_124E68(char *a0, float f12)
{
    char *a1 = *(char **)(a0 + 0x640);
    if (a1 != 0) {
        char *v1 = *(char **)(a1 + 0x214);
        short off = *(short *)(v1 + 0x68);
        int (*fn)(char *) = *(int (**)(char *))(v1 + 0x6C);
        int r = fn(a1 + off);
        cGameObj_SetTgtTurn(a0, r, f12);
    }
}
