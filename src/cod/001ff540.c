/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_005FEE00;
extern int D_00580D80;
extern int D_00754200;
extern int D_00580D40;
extern int D_00747A78[];

__attribute__((section(".text.IsSlotArrayValid_1FF540")))
int IsSlotArrayValid_1FF540(int *a0) {
    int *p;
    int i;
    p = a0 + 9;
    for (i = 0; i < 10; i++) {
        if (cSnd_SeIsLoaded(&D_005FEE00, p[0]) == 0) return 0;
        p++;
    }
    return 1;
}

__attribute__((section(".text.ClearSlotArray_1FF5B8")))
void ClearSlotArray_1FF5B8(int *a0) {
    int *p;
    int i;
    p = a0 + 9;
    for (i = 9; i >= 0; i--) {
        if (p[0] >= 0) {
            a0[2] |= 4;
            func_002CB340(&D_005FEE00, p[0]);
            p[0] = -1;
        }
        p++;
    }
}

__attribute__((section(".text.InitSlotTable_1FF800")))
int *InitSlotTable_1FF800(int *a0) {
    a0[3] = 0xC00;
    a0[0] = 0;
    a0[2] = 0;
    a0[4] = 0;
    a0[5] = 0;
    func_003A52F0(&D_00580D80, 0, 0x3000);
    return a0;
}

__attribute__((section(".text.AllocSlotEntry_1FFC60")))
int AllocSlotEntry_1FFC60(int a0, int a1) {
    int s1 = func_00323618(a1, 0);
    int s0 = func_003243C8(s1);
    int s2 = EnsureInitThenForward_2A9538_30EE08(s0 << 11, 0x40, &D_00754200);
    func_00323E80(s1, s0, s2);
    while (func_003244C8(s1) != 3) {
        sceGsSyncV(0);
    }
    return s2;
}

__attribute__((section(".text.LoadEntryByValue_1FFD00")))
int LoadEntryByValue_1FFD00(int a0, int a1, int a2) {
    int sp0;
    int v0;
    int s0;
    v0 = FindEntryValue_1FF9C0(&D_00580D40, a1, &sp0, 0);
    if (v0 < 0)
        return v0;
    s0 = func_00323918(0, v0);
    func_00323E80(s0, sp0, a2);
    while (func_003244C8(s0) != 3) {
        sceGsSyncV(0);
    }
    return func_00323A70(s0);
}

__attribute__((section(".text.SetColorRgba_1FFE60")))
void SetColorRgba_1FFE60(int a0, int a1, int a2, int a3, int t0) {
    if (cDoor_getJumpData(a0, a1 & 0xFF, a2 & 0xFF, a3 & 0xFF, 0, t0 & 0xFF) == 1)
        cDoor_setDoorJump(a0);
}

__attribute__((section(".text.InitSlotParams_200658")))
void InitSlotParams_200658(void) {
    func_003A52F0(&D_00747A78, 0, 8);
    D_00747A78[2] = D_00747A78[2] & ~0x100000;
    *(float*)((char*)Getplayer() + 0x54C) = 30.0f;
}
