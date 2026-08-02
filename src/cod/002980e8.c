/* sn-2.95.3-136 matched TU. */

extern int D_00586AF0;
extern void func_00298110(void);
extern void func_00297B40(void *a, void *b);
extern void func_002981D8(void);
extern void SetCostumeFlagIfMatch_2982A0(void);
extern void func_00298338(void);
extern void func_00297B20(void *a, void *b);
extern void func_00298A78(void);
extern void func_00298C18(void);
extern void func_00298EF8(void);
extern void func_002991D8(void);
extern char D_005864F0[];
extern char D_00462FC0[];
extern char *Obj0000_Get_D_00747A94_2DB6B0();
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *p);
extern int Obj293_IsByteSet_53C(void *p);
extern void Forward_001346C8_00134608_1351D8(void *a, void *b, int c);
extern void func_00129718(void *a, void *b, int c);

/* clone */




__attribute__((section(".text.Forward297B40_2980E8")))
void Forward297B40_2980E8(void) {
    func_00297B40(&D_00586AF0, (void *)&func_00298110);
}

/* clone */




__attribute__((section(".text.Forward297B40_2981B0")))
void Forward297B40_2981B0(void) {
    func_00297B40(&D_00586AF0, (void *)&func_002981D8);
}

/* clone */




__attribute__((section(".text.Forward297B40_298278")))
void Forward297B40_298278(void) {
    func_00297B40(&D_00586AF0, (void *)&SetCostumeFlagIfMatch_2982A0);
}

/* clone */




__attribute__((section(".text.Forward297B20_298310")))
void Forward297B20_298310(void) {
    func_00297B20(&D_00586AF0, (void *)&func_00298338);
}

/* clone */




__attribute__((section(".text.Forward297B40_298A50")))
void Forward297B40_298A50(void) {
    func_00297B40(&D_00586AF0, (void *)&func_00298A78);
}

/* clone */




__attribute__((section(".text.Forward297B20_298BF0")))
void Forward297B20_298BF0(void) {
    func_00297B20(&D_00586AF0, (void *)&func_00298C18);
}

/* clone */




__attribute__((section(".text.Forward297B40_298ED0")))
void Forward297B40_298ED0(void) {
    func_00297B40(&D_00586AF0, (void *)&func_00298EF8);
}

/* clone */




__attribute__((section(".text.Forward297B40_2991B0")))
void Forward297B40_2991B0(void) {
    func_00297B40(&D_00586AF0, (void *)&func_002991D8);
}

__attribute__((section(".text.func_002DD300")))
void func_002DD300(char *a0) {
    char *o;
    char *g;
    o = Obj0000_Get_D_00747A94_2DB6B0();
    if (a0 == 0) return;
    if (*(short *)(o + 0x54A) <= 0) return;
    if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(o) != 0) return;
    g = D_005864F0;
    if (*(int *)(g + 0x514) > 0) return;
    if (Obj293_IsByteSet_53C(g) != 0) return;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F7) = 0;
    *(float *)(a0 + 0x54C) = 30.0f;
    *(char *)(a0 + 0x2F4) = 1;
    *(char *)(a0 + 0x2F5) = 0x1D;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x1D);
}

__attribute__((section(".text.func_002DD3C0")))
void func_002DD3C0(char *a0) {
    char *o;
    char *g;
    o = Obj0000_Get_D_00747A94_2DB6B0();
    if (a0 == 0) return;
    if (*(short *)(o + 0x54A) <= 0) return;
    if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(o) != 0) return;
    g = D_005864F0;
    if (*(int *)(g + 0x514) > 0) return;
    if (Obj293_IsByteSet_53C(g) != 0) return;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F7) = 0;
    *(float *)(a0 + 0x54C) = 30.0f;
    *(char *)(a0 + 0x2F4) = 1;
    *(char *)(a0 + 0x2F5) = 0x1E;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x1E);
}
