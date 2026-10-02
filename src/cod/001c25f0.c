extern int D_00460D40;
extern int D_0042C348;
extern int D_00460D48;
extern int D_0042C4F8;
extern char D_00462FC0[];
extern int D_00460D50;
extern char D_0044AF10[];
extern int D_00460D58;
extern char D_0044B330[];
extern int D_00460D60;
extern char D_0044BE98[];
extern int D_00460D68;
extern int D_0044BF60;
extern int D_00460D78;
extern int D_0044D200;
extern int D_00460D80;
extern int D_0044D210;
extern int D_00460D88;
extern int D_0044D3A0;
extern int D_00460D90;
extern int D_0044D3D8;
extern int D_0044EE38;
extern int D_00460D98;
extern int D_00450098;
extern int D_00460D70;
extern int D_0045A5F8;

__attribute__((section(".text.InitStructZeroedFields_1E7960")))
void *InitStructZeroedFields_1E7960(void *a0) {
    func_003A52F0(a0, 0, 0x54);
    *(int *)((char *)a0 + 0x54) = 0;
    *(int *)((char *)a0 + 0x4) = 0;
    *(int *)((char *)a0 + 0x8) = 0;
    *(int *)((char *)a0 + 0xC) = 0;
    return a0;
}

__attribute__((section(".text.InitStructAndSubfields_1E8DA8")))
void *InitStructAndSubfields_1E8DA8(void *a0) {
    func_003A52F0(a0, 0, 0x54);
    func_001E8E88(a0);
    func_001E8EB8(a0);
    return a0;
}

__attribute__((section(".text.GetOrInit_460D40_1F7C88")))
int *GetOrInit_460D40_1F7C88(void) {
    if (D_00460D40 == 0) {
        func_0031EEC8(&D_00460D40, &D_0042C348);
    }
    return &D_00460D40;
}

__attribute__((section(".text.ClearAndResetFields_1FE278")))
int ClearAndResetFields_1FE278(int a0, int a1) {
    if (a1 == 0) {
        return 0;
    }
    func_001FD580(a1);
    ResetObjectFields_1FCDE8(a1);
    return 1;
}

__attribute__((section(".text.GetOrInit_460D48_1FE4C0")))
int *GetOrInit_460D48_1FE4C0(void) {
    if (D_00460D48 == 0) {
        func_0031EEC8(&D_00460D48, &D_0042C4F8);
    }
    return &D_00460D48;
}

__attribute__((section(".text.GetBuiltPackedAddr_1FFA28")))
int GetBuiltPackedAddr_1FFA28(int a0) {
    int v = func_001FFA68(a0);
    if (v == 0) {
        return 0;
    }
    return BuildPackedAddr_1FFD98(a0, v);
}

__attribute__((section(".text.ForwardDispatchByMode_27F170")))
void ForwardDispatchByMode_27F170(void *a0) {
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, a0);
    KillEffect(a0, 1, 2);
}

__attribute__((section(".text.GetOrInit_460D50_2A9D60")))
void *GetOrInit_460D50_2A9D60(void) {
    if (D_00460D50 == 0) {
        func_0031EEC8(&D_00460D50, D_0044AF10);
    }
    return &D_00460D50;
}

__attribute__((section(".text.GetOrInit_460D58_2B6528")))
void *GetOrInit_460D58_2B6528(void) {
    if (D_00460D58 == 0) {
        func_0031EEC8(&D_00460D58, D_0044B330);
    }
    return &D_00460D58;
}

__attribute__((section(".text.GetOrInit_460D60_2BAD40")))
void *GetOrInit_460D60_2BAD40(void) {
    if (D_00460D60 == 0) {
        func_0031EEC8(&D_00460D60, D_0044BE98);
    }
    return &D_00460D60;
}

__attribute__((section(".text.GetOrInit_460D68_2BAFA0")))
void *GetOrInit_460D68_2BAFA0(void) {
    if (D_00460D68 == 0) {
        func_0031EEC8(&D_00460D68, &D_0044BF60);
    }
    return &D_00460D68;
}

__attribute__((section(".text.cSnd_SeLoadNo")))
int cSnd_SeLoadNo(int a0, int a1, int a2) {
    return cSeData_LoadNumbered(cSnd_GetSeData(a0), a1, a2);
}

__attribute__((section(".text.GetOrInit_460D78_2D5BB8")))
void *GetOrInit_460D78_2D5BB8(void) {
    if (D_00460D78 == 0) {
        func_0031EEC8(&D_00460D78, &D_0044D200);
    }
    return &D_00460D78;
}

__attribute__((section(".text.GetOrInit_460D80_2D5BF8")))
void *GetOrInit_460D80_2D5BF8(void) {
    if (D_00460D80 == 0) {
        func_0031EEC8(&D_00460D80, &D_0044D210);
    }
    return &D_00460D80;
}

__attribute__((section(".text.GetOrInit_D00460D88_2D9EC8")))
void *GetOrInit_D00460D88_2D9EC8(void) {
    if (D_00460D88 == 0) {
        func_0031EEC8(&D_00460D88, &D_0044D3A0);
    }
    return &D_00460D88;
}

__attribute__((section(".text.GetOrInit_460D90_2D9FF8")))
void *GetOrInit_460D90_2D9FF8(void) {
    if (D_00460D90 == 0) {
        func_0031EEC8(&D_00460D90, &D_0044D3D8);
    }
    return &D_00460D90;
}

__attribute__((section(".text.InitVtablePtrAndClearField_2FFD88")))
int InitVtablePtrAndClearField_2FFD88(int a0) {
    if (a0) {
        InitObject_2FBCC8();
        *(int*)((char*)a0 + 0x2B0) = 0;
        *(int*)((char*)a0 + 0xF0) = (int)&D_0044EE38;
    }
    return a0;
}

__attribute__((section(".text.GetOrInit_460D98_3071A0")))
int GetOrInit_460D98_3071A0(void) {
    if (D_00460D98 == 0) {
        func_0031EEC8(&D_00460D98, &D_00450098);
    }
    return (int)&D_00460D98;
}

__attribute__((section(".text.Get_460D70_3BAFF8")))
int Get_460D70_3BAFF8(void) {
    if (D_00460D70 == 0) {
        func_0031EEC8(&D_00460D70, &D_0045A5F8);
    }
    return (int)&D_00460D70;
}

__attribute__((section(".text.ResetChannelPairFields_37B5E0")))
void ResetChannelPairFields_37B5E0(int a0) {
    func_00374980(0, (void*)((char*)a0 + 0x16C));
    func_00374980(1, (void*)((char*)a0 + 0x18C));
    *(char*)((char*)a0 + 0x28) = 0;
    *(char*)((char*)a0 + 0x29) = 0;
}
