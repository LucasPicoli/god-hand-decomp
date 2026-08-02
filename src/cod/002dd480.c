/* sn-2.95.3-136 matched TU. */

extern char D_005864F0[];
extern char D_00462FC0[];
extern char *Obj0000_Get_D_00747A94_2DB6B0();
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *p);
extern int Obj293_IsByteSet_53C(void *p);
extern void Forward_001346C8_00134608_1351D8(void *a, void *b, int c);
extern void func_00129718(void *a, void *b, int c);
extern void *D_003C3CF0;
extern int EnsureInitThenForward_2A9538_30EE08(void *, int, void *);
extern int D_00747A34;
extern char D_00754220[];
extern void func_003A52F0(void *, int, int);

__attribute__((section(".text.func_002DD480")))
void func_002DD480(char *a0) {
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
    *(char *)(a0 + 0x2F5) = 0x1F;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x1F);
}

__attribute__((section(".text.func_002DD540")))
void func_002DD540(char *a0) {
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
    *(char *)(a0 + 0x2F5) = 0x20;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x20);
}

__attribute__((section(".text.func_002DD600")))
void func_002DD600(char *a0) {
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
    *(char *)(a0 + 0x2F5) = 0x21;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, a0, 0);
    func_00129718(o, a0, 0x21);
}

/* clone */



__attribute__((section(".text.func_0030F578")))
int func_0030F578(void *a0) {
    return EnsureInitThenForward_2A9538_30EE08(a0, 0x10, D_003C3CF0);
}

/* clone */






__attribute__((section(".text.func_00318138")))
void *func_00318138(void)
{
    void *p;
    if (!(D_00747A34 & 0x100000))
    {
        p = EnsureInitThenForward_2A9538_30EE08(0x790, 0x10, D_00754220);
        if (p != 0)
        {
            func_003A52F0(p, 0, 0x790);
            return func_001C9140(p);
        }
    }
    return 0;
}

/* clone */



__attribute__((section(".text.func_0031C890")))
int func_0031C890(void *a0) {
    return EnsureInitThenForward_2A9538_30EE08(a0, 0x10, D_003C3CF0);
}
