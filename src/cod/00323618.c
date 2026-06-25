/* cygnus-2.96 matched TU. */

extern int NoOp_33E6A8();
extern int ADXT_GetOutPan();
extern int NoOp_33E6B0();
extern int D_003D1E70[];
extern void func_00330180();
extern int Tramp_003356B0_00335610();
extern int Forward33B658_3389F8();
extern int Forward33B670_338A10();
extern int isEffectiveVer();
extern void func_003600E8();
extern void func_00360428();
extern void func_0036BFB0();
extern void func_0036D6B0();
extern int D_003F1AC8;
extern int *D_003F1ABC;

int Forward33E6A8_324880();
int func_00323660();
int Forward33E6B0_324898();

__attribute__((section(".text.func_00323618")))
int func_00323618(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    Forward33E6A8_324880();
    r = func_00323660(s0, s1);
    Forward33E6B0_324898();
    return r;
}

int Forward33E6A8_324880();
int func_00323960();
int Forward33E6B0_324898();

__attribute__((section(".text.func_00323918")))
int func_00323918(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    Forward33E6A8_324880();
    r = func_00323960(s0, s1);
    Forward33E6B0_324898();
    return r;
}

int Obj3290_Tramp_0033E6A8_9070();
int func_00327D48();
int Obj3290_Tramp_0033E6B0_9088();

__attribute__((section(".text.func_00327D00")))
int func_00327D00(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    Obj3290_Tramp_0033E6A8_9070();
    r = func_00327D48(s0, s1);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

int Obj3290_Tramp_0033E6A8_9070();
int func_00328288();
int Obj3290_Tramp_0033E6B0_9088();

__attribute__((section(".text.func_00328240")))
int func_00328240(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    Obj3290_Tramp_0033E6A8_9070();
    r = func_00328288(s0, s1);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

int Obj3290_Tramp_0033E6A8_9070();
int func_00328D30();
int Obj3290_Tramp_0033E6B0_9088();

__attribute__((section(".text.func_00328CE8")))
int func_00328CE8(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    Obj3290_Tramp_0033E6A8_9070();
    r = func_00328D30(s0, s1);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

__attribute__((section(".text.func_0032A838")))
int func_0032A838(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    NoOp_33E6A8();
    r = ADXT_GetOutPan(s0, s1);
    NoOp_33E6B0();
    return r;
}

__attribute__((section(".text.func_0032B4E8")))
int func_0032B4E8(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    NoOp_33E6A8();
    r = func_0032B530(s0, s1);
    NoOp_33E6B0();
    return r;
}

__attribute__((section(".text.func_00330268")))
void func_00330268(void) {
    int s0, s1;
    s0 = (int)D_003D1E70;
    s1 = s0 + 0x6590;
    do {
        func_00330180((void *)s0);
        s0 = s0 + 0x1964;
    } while (s0 < s1);
}

__attribute__((section(".text.func_003355C8")))
int func_003355C8(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    func_00335CD8();
    r = Tramp_003356B0_00335610(s0, s1);
    func_00335CE0();
    return r;
}

__attribute__((section(".text.func_00338B90")))
int func_00338B90(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    Forward33B658_3389F8();
    r = func_00338BD8(s0, s1);
    Forward33B670_338A10();
    return r;
}

__attribute__((section(".text.func_0033A5D0")))
int func_0033A5D0(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    Forward33B658_3389F8();
    r = func_0033A618(s0, s1);
    Forward33B670_338A10();
    return r;
}

int Forward33B658_3403C8();
int func_00340580();
int Forward33B670_3403E0();

__attribute__((section(".text.func_00340538")))
int func_00340538(int a0, int a1) {
    int s0, s1, r;
    s0 = a0;
    s1 = a1;
    Forward33B658_3403C8();
    r = func_00340580(s0, s1);
    Forward33B670_3403E0();
    return r;
}

typedef struct { int w0; int w1; int w2; int w3; } Vec128_0034C208;

__attribute__((section(".text.func_0034C208")))
void func_0034C208(int a0, int a1, int a2, Vec128_0034C208 *a3) {
    int v0;
    Vec128_0034C208 *dst;
    a2 = a2 << 4;
    v0 = a1 << 3;
    v0 = v0 - a1;
    v0 = v0 << 2;
    v0 = v0 + a1;
    v0 = v0 << 2;
    a0 = a0 + v0;
    a0 = a0 + 0x1320;
    a0 = a0 + a2;
    dst = (Vec128_0034C208 *)a0;
    *dst = *a3;
}

typedef struct { int w0; int w1; int w2; int w3; } Vec128_0034C250;

__attribute__((section(".text.func_0034C250")))
void func_0034C250(int a0, int a1, int a2, Vec128_0034C250 *a3) {
    int v0;
    Vec128_0034C250 *src;
    a2 = a2 << 4;
    v0 = a1 << 3;
    v0 = v0 - a1;
    v0 = v0 << 2;
    v0 = v0 + a1;
    v0 = v0 << 2;
    a0 = a0 + v0;
    a0 = a0 + 0x1320;
    a0 = a0 + a2;
    src = (Vec128_0034C250 *)a0;
    *a3 = *src;
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035DE38;

typedef struct {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    int dummy2;
    int dummy3;
    int field8;
    int fieldC;
} CVerData_t_0035DE38;

__attribute__((section(".text.func_0035DE38")))
int func_0035DE38(CGObj_t_0035DE38 *a0, int *a1)
{
    CVerData_t_0035DE38 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035DE38 *)((char *)a0->pVer + 0xB0);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->byte0;
    return 1;
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035DE88;

typedef struct {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    int dummy2;
    int dummy3;
    int field8;
    int fieldC;
} CVerData_t_0035DE88;

__attribute__((section(".text.func_0035DE88")))
int func_0035DE88(CGObj_t_0035DE88 *a0, int *a1)
{
    CVerData_t_0035DE88 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035DE88 *)((char *)a0->pVer + 0xB0);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->byte1;
    return 1;
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035DED8;

typedef struct {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    int dummy2;
    int dummy3;
    int field8;
    int fieldC;
} CVerData_t_0035DED8;

__attribute__((section(".text.func_0035DED8")))
int func_0035DED8(CGObj_t_0035DED8 *a0, int *a1)
{
    CVerData_t_0035DED8 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035DED8 *)((char *)a0->pVer + 0xB0);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->byte2;
    return 1;
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035DF28;

typedef struct {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    int dummy2;
    int dummy3;
    int field8;
    int fieldC;
} CVerData_t_0035DF28;

__attribute__((section(".text.func_0035DF28")))
int func_0035DF28(CGObj_t_0035DF28 *a0, int *a1)
{
    CVerData_t_0035DF28 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035DF28 *)((char *)a0->pVer + 0xB0);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->byte3;
    return 1;
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035DFE0;

typedef struct {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    int field4;
    int field8;
    int fieldC;
} CVerData_t_0035DFE0;

__attribute__((section(".text.func_0035DFE0")))
int func_0035DFE0(CGObj_t_0035DFE0 *a0, int *a1)
{
    CVerData_t_0035DFE0 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035DFE0 *)((char *)a0->pVer + 0xB0);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->field8;
    return 1;
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035E030;

typedef struct {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    int field4;
    int field8;
    int fieldC;
} CVerData_t_0035E030;

__attribute__((section(".text.func_0035E030")))
int func_0035E030(CGObj_t_0035E030 *a0, int *a1)
{
    CVerData_t_0035E030 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035E030 *)((char *)a0->pVer + 0xB0);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->fieldC;
    return 1;
}

__attribute__((section(".text.func_003603D8")))
void func_003603D8(int a0, int a1, int a2) {
    int sp0;
    int sp4;
    int s0;
    int s1;

    s1 = a2;
    func_003600E8(a0, a1, &sp0, &sp4);
    s0 = a0;
    func_00360428(s0, sp0, sp4, s1);
}

__attribute__((section(".text.func_0036BF60")))
void func_0036BF60(int a0) {
    int s0;

    func_0036BFB0(a0);
    s0 = a0;
    if (s0) {
        func_0036D6B0(s0, &D_003F1AC8, 0x100);
        D_003F1ABC = (int *)(s0 + 0x180);
    }
}
