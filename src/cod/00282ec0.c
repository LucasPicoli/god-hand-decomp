/* sn-2.95.3-136 matched TU. */

extern char D_00448778[];
extern char D_00448780[];
extern void Obj0000_Set_Field_424_1595E8(void *a, int b);
extern void *SearchData(void *a, void *b, int c);
extern int cModel_setupModel(void *a, void *b, void *c, int d, int e);
extern char D_005864F0[];
extern char D_00462FC0[];
extern char *Obj0000_Get_D_00747A94_2DB6B0();
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *p);
extern int Obj293_IsByteSet_53C(void *p);
extern void Forward_001346C8_00134608_1351D8(void *a, void *b, int c);
extern void func_00129718(void *a, void *b, int c);

__attribute__((section(".text.func_00282EC0")))
int func_00282EC0(char *a0) {
    void *m1;
    void *m2;
    Obj0000_Set_Field_424_1595E8(a0, 0);
    m1 = SearchData(*(void **)(a0 + 0x304), &D_00448778, 0);
    m2 = SearchData(*(void **)(a0 + 0x304), &D_00448780, 0);
    if (m2 != 0) {
        return cModel_setupModel(a0, m1, m2, 0, 0);
    }
    return 0;
}

__attribute__((section(".text.func_002DD7B0")))
void func_002DD7B0(char *a0) {
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
    *(char *)(a0 + 0x2F5) = 0x24;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x23);
}

__attribute__((section(".text.func_002DD870")))
void func_002DD870(char *a0) {
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
    *(char *)(a0 + 0x2F5) = 0x25;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x24);
}

__attribute__((section(".text.func_002DD930")))
void func_002DD930(char *a0) {
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
    *(char *)(a0 + 0x2F5) = 0x26;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x25);
}

__attribute__((section(".text.func_002DD9F0")))
void func_002DD9F0(char *a0) {
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
    *(char *)(a0 + 0x2F5) = 0x27;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x26);
}
