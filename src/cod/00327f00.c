/* cygnus-2.96 matched TU. */

extern void func_0032E770(void *a0);
extern int D_003D147C;
extern void func_00347450(void *a0);
extern void Forward33B658_3389F8(void);
extern void func_00338FD8(int a0, int a1, int a2, int a3);
extern void Forward33B670_338A10(void);
extern void Obj3290_Tramp_0033E6A8_9070(void);
extern void func_00327F70(int a0, int a1, int a2, int a3, int t0);
extern void Obj3290_Tramp_0033E6B0_9088(void);
extern void Forward33B568_33B658(void);
extern void func_0033BA80(int a0, int a1, int a2, int a3, int t0);
extern int Forward33B5C8_33B670(void);

/* MATCH via cygnus-2.96. */




__attribute__((section(".text.func_0032E720")))
void func_0032E720(void *a0)
{
    if (func_0033BF18(&D_003D147C)) {
        func_0032E770(a0);
        D_003D147C = 0;
    }
}

/* MATCH via cygnus-2.96. */


__attribute__((section(".text.func_003448F8")))
void func_003448F8(int *a0, int *a1)
{
    if (a0[0x64] < a1[0xC]) {
        func_00347450(a0);
    }
    a0[0x64] = a1[0xC];
}

/* MATCH via cygnus-2.96. */




__attribute__((section(".text.func_00338F78")))
void func_00338F78(int a0, int a1, int a2, int a3)
{
    Forward33B658_3389F8();
    func_00338FD8(a0, a1, a2, a3);
    Forward33B670_338A10();
}

/* MATCH via cygnus-2.96. */




__attribute__((section(".text.func_00327F00")))
void func_00327F00(int a0, int a1, int a2, int a3, int t0)
{
    Obj3290_Tramp_0033E6A8_9070();
    func_00327F70(a0, a1, a2, a3, t0);
    Obj3290_Tramp_0033E6B0_9088();
}

/* MATCH via cygnus-2.96. */




__attribute__((section(".text.func_0033BA10")))
int func_0033BA10(int a0, int a1, int a2, int a3, int t0)
{
    Forward33B568_33B658();
    func_0033BA80(a0, a1, a2, a3, t0);
    return Forward33B5C8_33B670();
}
