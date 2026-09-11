/* cygnus-2.96 matched TU. */

extern int GetArrayElemA0C_35A1C8(int a0, int a1);
extern int Obj34D8_SetGlobalEE0B8_IfField48(int a0);
extern void func_00357350(int a0);
extern void Forward33E6A8_324880(void);
extern int ADXF_ReadNw(int a0, int a1, int a2);
extern int Forward33E6B0_324898(void);
extern void func_00328368(void);
extern void func_00328018(char *a0);
extern void func_003A52F0(char *a0, int a1, int a2);
extern void Obj3290_Tramp_0033E6A8_9070(void);
extern int Obj3290_Tramp_0033E6B0_9088(void);
extern void NoOp_33E6A8(void);
extern void NoOp_33E6B0(void);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);
extern void PushGlobalD8478History_331C78(int a0);
extern int D_003D90DC;
extern void func_00333048(void);
extern void Forward3A52F0_332BE0(void *a0);
extern void Forward33B658_3389F8(void);
extern void Forward33B670_338A10(void);
extern float func_0032AE50(void *a0);

__attribute__((section(".text.func_0033D378")))
int func_0033D378(int a0, int a1) {
    int *v1 = (int*)((char*)a0 + 0x48);
    int s0 = *(int*)((char*)a0 + 8);
    func_0033FAD0(s0, v1[0], a1, v1[5] + (v1[8] << 1), v1[5] + (v1[8] << 1) + (v1[7] << 1));
    return func_0033FB00(s0);
}

__attribute__((section(".text.func_003483A0")))
int func_003483A0(int a0, int a1, int a2) {
    int *p = func_00348938(a0);
    int (*fn)(int, int);
    int r = 0;
    if (p != 0) {
        fn = (int (*)(int, int))p[3];
        if (fn != 0)
            r = fn(a1, a2);
    }
    return r;
}

__attribute__((section(".text.func_0034B6D0")))
void func_0034B6D0(int a0, int a1) {
    if (GetArrayElemA0C_35A1C8(a0, 6) != 0) {
        int *p = *(int**)((char*)a0 + 0x2114);
        void (*fn)(int, int) = (void (*)(int, int))p[5];
        if (fn != 0)
            fn(a0, a1);
    }
}

__attribute__((section(".text.func_003572F8")))
int func_003572F8(int a0) {
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0) {
        return func_0034DD70(0, 0xFF000138);
    }
    func_00357350(a0);
    return 0;
}

__attribute__((section(".text.func_00323E80")))
int func_00323E80(int a0, int a1, int a2) {
    int r;
    Forward33E6A8_324880();
    r = ADXF_ReadNw(a0, a1, a2);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_00324258")))
int func_00324258(int a0, int a1, int a2) {
    int r;
    Forward33E6A8_324880();
    r = func_003242B0(a0, a1, a2);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_00327DC0")))
void func_00327DC0(char *a0) {
    if (a0 == 0) return;
    func_00328368();
    func_00328018(a0);
    *a0 = 0;
    func_003A52F0(a0, 0, 0x60);
}

__attribute__((section(".text.func_00328C80")))
int func_00328C80(int a0, int a1, int a2) {
    int r;
    Obj3290_Tramp_0033E6A8_9070();
    r = func_00328CD8(a0, a1, a2);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

__attribute__((section(".text.func_0032B830")))
int func_0032B830(int a0, int a1, int a2) {
    int r;
    NoOp_33E6A8();
    r = func_0032B888(a0, a1, a2);
    NoOp_33E6B0();
    return r;
}

__attribute__((section(".text.func_0032F2D8")))
int func_0032F2D8(int a0, int a1, int a2) {
    int r;
    Obj33F8_Tramp_0033B658_FC70();
    r = func_0032F330(a0, a1, a2);
    Obj33F8_Tramp_0033B670_FC88();
    return r;
}

__attribute__((section(".text.func_00332838")))
int func_00332838(int a0, int a1) {
    int r;
    PushGlobalD8478History_331C78(0x8000);
    r = sceCdLayerSearchFile(a0, a1, D_003D90DC);
    PushGlobalD8478History_331C78(0x8001);
    return r;
}

__attribute__((section(".text.func_00332D78")))
void func_00332D78(unsigned char *a0) {
    if (a0 == 0) {
        return;
    }
    if (a0[2] >= 2) {
        func_00333048();
    }
    a0[0] = 0;
    Forward3A52F0_332BE0(a0);
}

__attribute__((section(".text.func_003395A0")))
int func_003395A0(int a0, int a1, int a2) {
    int r;
    Forward33B658_3389F8();
    r = func_003395F8(a0, a1, a2);
    Forward33B670_338A10();
    return r;
}

__attribute__((section(".text.func_00304BB8")))
int func_00304BB8(char *a0) {
    char *a1 = *(char **)(a0 + 0x100);
    *(float *)(a0 + 0x240) = *(float *)(a1 + 0x248);
    *(float *)(a0 + 0x244) = *(float *)(a1 + 0x24C);
    *(float *)(a0 + 0x248) = *(float *)(a1 + 0x250);
    *(float *)(a0 + 0x24C) = 1.0f - *(float *)(a1 + 0x254);
    *(char *)(a0 + 0x254) = *(unsigned char *)(a1 + 0x27C);
    return 1;
}

__attribute__((section(".text.func_0032AE10")))
float func_0032AE10(void *a0) {
    float r;
    NoOp_33E6A8();
    r = func_0032AE50(a0);
    NoOp_33E6B0();
    return r;
}

__attribute__((section(".text.cScrSpriteDraw_drawInit")))
void cScrSpriteDraw_drawInit(char *a0) {
    int five = 5;
    int six = 6;
    unsigned int u = 0xFFFF;
    *(short *)(a0 + 0x30) = u;
    *(int *)(a0 + 0x2C) = five;
    *(int *)(a0 + 0x28) = six;
    *(float *)(a0 + 0x24) = 1.0f;
    *(float *)(a0 + 0x20) = 1.0f;
    *(float *)(a0 + 0x1C) = 1.0f;
    *(float *)(a0 + 0x18) = 1.0f;
    *(float *)(a0 + 0x14) = 1.0f;
    *(float *)(a0 + 0x10) = 1.0f;
    *(float *)(a0 + 0xC) = 1.0f;
    *(float *)(a0 + 0x8) = 1.0f;
}
