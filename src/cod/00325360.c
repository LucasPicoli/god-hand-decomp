/* cygnus-2.96 matched TU. */

extern int sfset_IsCondValid();
extern int isEffectiveVer();
extern void func_0036CB98(int a0);
extern int D_003EE338;
extern void Forward33B658_3389F8(void);
extern void Forward33B670_338A10(void);
extern void Forward33BC48_33BD18(void);
extern void Forward33BC48_33BD30(void);
extern void Forward33BC48_33BD48(void);
extern void Forward33BC48_33BD60(void);
extern void Forward33BC48_33BD78(void);
extern void Forward33BC48_33BD90(void);
extern void Forward33BC48_33BDA8(void);
extern void Forward33BC48_33BDC0(void);
extern void func_0034C890(int, int, int *);
extern void func_0034CAF8(int, int *, int *);
extern long long func_0034CCB0(long long, int);
extern void func_00344680(int *a0, int a1);
extern void func_00352AA0(int *a0, int *a1);
extern void SFTIM_Tc2Time(int *a0, int *a1, int *a2);
extern int D_003EE278;
extern int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(int *a0);
extern int ReferThreadStatus(int threadId, int *status);
extern int SuspendThread(int threadId);
extern int Obj34D8_SetGlobalEE0B8_IfField48();
extern void (*D_003E9D28)(int);
extern void func_0036C688(void *a0);
extern void func_0036C440(void *a0, int a1);
extern void func_0035AB98(void *a, void *b, void *c);
extern void *getElemInfPtr(int a0, int a1);
extern int isEnableVidFtr(int a0, void *a1);
extern int D_003D84B4;
extern int D_004541C0;
extern void func_00329EA8(void);
extern void Forward33B658_325C60(void);
extern void func_00340680(void *);
extern void func_003404F0(void *);
extern void Forward33B670_325C78(void);
extern int Thunk_func_0033B658(int *);
extern int Thunk_func_0033B670(int *);
extern void func_00359DF0(int a0);
extern void func_003298C0(void *);
extern int D_00459920[];
extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(int *a0);
extern void M2VERR_SetCode(int a0, unsigned int a1);

__attribute__((section(".text.func_00359DA8")))
int func_00359DA8(char *a0) {
    char *a1;
    int a2;
    int v1;
    int v0;

    a1 = a0 + 0x1F30;
    a2 = -1;
    v1 = *(int *)(a1 + 0x14);
    v0 = ((v1 * 8 - v1) * 4 + v1) * 4;
    a0 = a0 + v0;
    v1 = *(int *)(a0 + 0x1360);
    v0 = (v1 * 16 + v1) * 4;
    a1 = a1 + v0;
    v0 = *(int *)(a1 + 0x20);
    if (v0 < 0) {
        return a2;
    }
    return v0;
}

__attribute__((section(".text.func_0035A050")))
void func_0035A050(void *a0, int a1, int a2) {
    if (sfset_IsCondValid()) {
        ((int *)a0)[a1 + 0xB9C/4] = a2;
    }
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035DCB0;

typedef struct {
    int field0;
    int field4;
    short field8;
    short fieldA;
    int fieldC;
} CVerData_t_0035DCB0;

__attribute__((section(".text.func_0035DCB0")))
int func_0035DCB0(CGObj_t_0035DCB0 *a0, int *a1)
{
    CVerData_t_0035DCB0 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035DCB0 *)((char *)a0->pVer + 0x80);
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
} CGObj_t_0035DD00;

typedef struct {
    int field0;
    int field4;
    int field8;
    int fieldC;
} CVerData_t_0035DD00;

__attribute__((section(".text.func_0035DD00")))
int func_0035DD00(CGObj_t_0035DD00 *a0, int *a1)
{
    CVerData_t_0035DD00 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035DD00 *)((char *)a0->pVer + 0x80);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->fieldC;
    return 1;
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_0035E080;

typedef struct {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    int field4;
    int field8;
    int fieldC;
    int field10;
} CVerData_t_0035E080;

__attribute__((section(".text.func_0035E080")))
int func_0035E080(CGObj_t_0035E080 *a0, int *a1)
{
    CVerData_t_0035E080 *s0;
    int v0;

    *a1 = 0;
    s0 = (CVerData_t_0035E080 *)((char *)a0->pVer + 0xB0);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->field10;
    return 1;
}

__attribute__((section(".text.func_0035FB88")))
void func_0035FB88(int a0)
{
    int s0;
    int arg;
    if (!a0) return;
    arg = *(int *)(a0 + 0x24);
    s0 = *(int *)(a0 + 0x30);
    *(int *)a0 = 0;
    func_0035FFB0(arg);
    func_0036CB98(s0);
    D_003EE338 = D_003EE338 - 1;
}

__attribute__((section(".text.func_0033A190")))
int func_0033A190(int a0, int a1, int a2) {
    int r;
    Forward33B658_3389F8();
    r = func_0033A1E8(a0, a1, a2);
    Forward33B670_338A10();
    return r;
}

__attribute__((section(".text.func_0033F7B8")))
int func_0033F7B8(void) {
    Forward33BC48_33BD18();
    Forward33BC48_33BD30();
    Forward33BC48_33BD48();
    Forward33BC48_33BD60();
    Forward33BC48_33BD78();
    Forward33BC48_33BD90();
    Forward33BC48_33BDA8();
    Forward33BC48_33BDC0();
    return 0;
}

__attribute__((section(".text.func_00342F40")))
int func_00342F40(int *a0) {
    int s1;
    int v0;
    s1 = func_00346C10(*(int *)((char *)a0 + 0x8), *(int *)((char *)a0 + 0xC));
    v0 = func_003472E8((int)a0);
    if (v0 == 1) {
        s1 = 0x20000 + s1;
    }
    return s1;
}

__attribute__((section(".text.func_003545F8")))
void func_003545F8(int *a0) {
    int buf[3];
    int v0;
    func_0034C890((int)a0, *(int *)((char *)a0 + 0x1FC8), buf);
    v0 = buf[0];
    if (v0 != 0) {
        func_0034CAF8(v0, &buf[1], &buf[2]);
        *(long long *)((char *)a0 + 0x9A0) = func_0034CCB0(*(long long *)((char *)a0 + 0x9A0), buf[1]);
    }
}

__attribute__((section(".text.func_00344710")))
void func_00344710(int *a0) {
    int i;
    int *p;
    i = 0x1F;
    p = (int*)((char*)a0 + 0x280);
    do {
        int v;
        v = *p;
        if (v != 0) {
            func_00344680(a0, v);
            *p = 0;
        }
        i--;
        p--;
    } while (i >= 0);
}

__attribute__((section(".text.func_003519A8")))
int func_003519A8(int *a0) {
    int buf[12];
    int *s0;
    s0 = (int*)((char*)a0 + 0xD6C);
    if (*(int*)((char*)a0 + 0xD98) == 0) {
        return 0;
    }
    func_00352AA0((int*)((char*)a0 + 0xD9C), buf);
    buf[6] = 0;
    SFTIM_Tc2Time(buf, (int*)((char*)buf + 0x20), (int*)((char*)buf + 0x24));
    return *(int*)((char*)buf + 0x20) - *(int*)((char*)s0 + 0x24);
}

__attribute__((section(".text.func_0035ACA0")))
int func_0035ACA0(int *a0, int *a1, int *a2) {
    int *s0;
    int r;
    r = func_0035AE18(a0, a1, a2);
    s0 = (int*)((char*)a0 + 0xD30);
    if (r == 0) {
        return 0;
    }
    *a1 = *(int*)((char*)s0 + 0x2A8);
    *a2 = D_003EE278;
    return 0;
}

__attribute__((section(".text.func_0036A1D8")))
int func_0036A1D8(int *a0, int *a1)
{
    int r;
    int *s0;
    s0 = a0;
    r = Obj0000_Set_D_00766D44_Check_Field_188_NE_2(a0);
    if (r != 0) {
        return func_00369F20(0, 0xFF03020Du);
    }
    *a1 = *(int *)((char *)s0 + 0x2A8);
    return 0;
}

__attribute__((section(".text.func_0035CA68")))
void func_0035CA68(int *a0, int a1)
{
    int *s0;
    int i;
    int *v1;
    s0 = a0;
    i = 0;
    if (*(int *)((char *)s0 + 0x10) > 0) {
        v1 = (int *)((char *)s0 + 0x18);
        do {
            *v1 -= a1;
            v1++;
            i++;
        } while (i < *(int *)((char *)s0 + 0x10));
    }
    *(int *)((char *)s0 + 0x1A8) = func_0035CAC8(s0);
}

__attribute__((section(".text.func_00325360")))
int func_00325360(int a0) {
    int status[12];
    int s0;
    int s1;
    int v1;
    s0 = a0;
    s1 = 0;
    if (s0 != 0) {
        ReferThreadStatus(s0, status);
        v1 = status[0];
        if (v1 != 8) {
            if (v1 != 12) {
                s1 = SuspendThread(s0);
            }
        }
    }
    return s1;
}

__attribute__((section(".text.func_00359C58")))
void func_00359C58(int a0, int a1) {
    int s0;
    int s1;
    int p;

    s0 = a0;
    s1 = a1;
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0, a1) != 0) {
        func_0034DD70(0, (int)0xFF00015C);
        return;
    }
    p = *(int *)((char *)s0 + 0x36B0);
    if (p != 0) {
        *(int *)((char *)p + 0xDD4) = s1;
    }
}

__attribute__((section(".text.func_0033C458")))
void func_0033C458(int a0, int a1) {
    int s0;
    int s1;
    int v0;

    s0 = a1;
    s1 = a0;
    v0 = *(int *)(s1 + 0xB4);
    if (v0 != 0) {
        D_003E9D28(v0);
    }
    *(int *)(s1 + 0xB8) = s0;
    *(int *)(s1 + 0xBC) = s0 / 0x60;
}

__attribute__((section(".text.func_0035DF78")))
int func_0035DF78(void *a0, int *a1)
{
    char *s0 = (char *)a0;
    int *s2 = a1;
    char *s1;
    int v0;
    int v1;
    *s2 = 0;
    s1 = *(char **)(s0 + 4) + 0xB0;
    v0 = isEffectiveVer();
    if (v0 == 0) return v0;
    v0 = *(int *)(s0 + 0xC);
    v1 = v0 < 0x6E;
    if (v1) return 0;
    *s2 = *(int *)(s1 + 4);
    return 1;
}

__attribute__((section(".text.func_0036C3D0")))
int func_0036C3D0(void *a0)
{
    char *s0 = (char *)a0;
    int r;
    r = Obj0000_Set_D_00766D44_Check_Field_188_NE_2(s0);
    if (r != 0) {
        return func_00369F20(0, 0xFF030201);
    }
    func_0036C688(s0);
    func_0036C440(s0, 0x40C);
    *(int *)(s0 + 0x188) = 1;
    return 0;
}

__attribute__((section(".text.func_00357F58")))
int func_00357F58(void *a0)
{
    int local0;
    int local4;
    char *v1;
    int s0;
    int s1;
    int v0;
    int v1i;

    v1 = (char *)a0 + 0xA0C;
    s0 = *(int *)(v1 + 0x50);
    s1 = *(int *)(v1 + 0x54);
    if (s0 == -4)
        return 0;
    func_0035AB98(a0, &local0, &local4);
    v0 = 0;
    v1i = local0;
    if (v1i < 0)
        return 0;
    v0 = func_00366918(v1i, local4, s0, s1);
    return (unsigned)v0 < 1u;
}

__attribute__((section(".text.func_0035E6E8")))
int func_0035E6E8(int a0, int a1, int *a2) {
    void *s1;
    int s0;
    s0 = a1 & 0xFF;
    *a2 = 0;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (isEnableVidFtr(s0, s1) == 0) {
        return 0;
    }
    *a2 = *(unsigned char *)((char *)s1 + 0x24);
    return 1;
}

__attribute__((section(".text.func_003320F8")))
void func_003320F8(int a0, char *a1, int a2) {
    int i;
    for (i = 0; i < a2; i++) {
        a1[i] = (char)-0x56;
    }
    func_003A6C58(a1, &D_004541C0, D_003D84B4);
    D_003D84B4 = D_003D84B4 + 1;
}

__attribute__((section(".text.func_00336DB0")))
void func_00336DB0(void *a0) {
    void *v0;
    void *s1;
    void *s0;
    v0 = *(void **)((char *)a0 + 0x4);
    s1 = *(void **)((char *)v0 + 0x4);
    s0 = *(void **)((char *)s1 + 0xE8);
    if (s0 == 0) {
        return;
    }
    func_00329EA8();
    Forward33B658_325C60();
    func_00340680(s0);
    *(void **)((char *)s1 + 0xE8) = 0;
    func_003404F0(0);
    Forward33B670_325C78();
}

__attribute__((section(".text.func_0034C6D8")))
void func_0034C6D8(char *a0, int a1, int *a2, int *a3) {
    int local[4];
    char *entry;
    entry = a0 + 0x1338 + a1 * 116;
    Thunk_func_0033B658(local);
    *a2 = *(int *)entry;
    *a3 = *(int *)(entry + 4);
    Thunk_func_0033B670(local);
}

__attribute__((section(".text.func_00359AF0")))
int func_00359AF0(int a0, int a1) {
    int s0;
    int s1;
    int v0;
    int v1;

    s0 = a0;
    s1 = a1;
    if (Obj34D8_SetGlobalEE0B8_IfField48(s0)) {
        return func_0034DD70(0, 0xFF000159U);
    }
    v0 = 0;
    v1 = *(int *)((char *)s0 + 0x36B0);
    if (!v1) {
        return v0;
    }
    *(int *)((char *)v1 + 0xDC4) = s1;
    func_00359DF0(s0);
    return v0;
}

__attribute__((section(".text.func_00359BE8")))
int func_00359BE8(int a0, int a1) {
    int s0;
    int s1;
    int v0;
    int v1;

    s0 = a0;
    s1 = a1;
    if (Obj34D8_SetGlobalEE0B8_IfField48(s0)) {
        return func_0034DD70(0, 0xFF00015BU);
    }
    v0 = 0;
    v1 = *(int *)((char *)s0 + 0x36B0);
    if (!v1) {
        return v0;
    }
    *(int *)((char *)v1 + 0xDD0) = s1;
    func_00359DF0(s0);
    return v0;
}

__attribute__((section(".text.func_0035E520")))
int func_0035E520(int a0, int a1, int *a2) {
    int s0;
    int s1;

    *a2 = -1;
    s0 = a1 & 0xFF;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (isEnableVidFtr(s0, s1) == 0) {
        return 0;
    }
    *a2 = *(unsigned char *)((char *)s1 + 0x21);
    return 1;
}

__attribute__((section(".text.func_0035E590")))
int func_0035E590(int a0, int a1, int *a2) {
    int s0;
    int s1;

    *a2 = -1;
    s0 = a1 & 0xFF;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (isEnableVidFtr(s0, s1) == 0) {
        return 0;
    }
    *a2 = *(unsigned char *)((char *)s1 + 0x22);
    return 1;
}

__attribute__((section(".text.func_0035E600")))
int func_0035E600(int a0, int a1, int *a2) {
    int s0;
    int s1;

    *a2 = 0;
    s0 = a1 & 0xFF;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (isEnableVidFtr(s0, s1) == 0) {
        return 0;
    }
    *a2 = *(unsigned char *)((char *)s1 + 0x23) & 1;
    return 1;
}

__attribute__((section(".text.func_0032EE88")))
void func_0032EE88(char *a0)
{
    char *s1;
    int s2;
    int *s0;
    int tmp;

    s1 = a0;
    s2 = 0;
    if ((signed char)s1[3] <= 0)
        return;
    s0 = (int *)(s1 + 0xC);
    do {
        tmp = *s0;
        if (tmp != 0) {
            *s0 = 0;
            func_003298C0((void *)tmp);
        }
        s2++;
        s0++;
    } while (s2 < (signed char)s1[3]);
}

__attribute__((section(".text.func_0035B5F8")))
int func_0035B5F8(int a0, int *a1) {
    int v1;
    *a1 = -1;
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0, (int)a1)) {
        return func_0034DD70(0, 0xFF00011Bu);
    }
    v1 = *(int *)((char *)a0 + 0x920);
    if (v1 != 0) {
        *a1 = D_00459920[v1];
    }
    return 0;
}

__attribute__((section(".text.func_0036A300")))
int func_0036A300(int *a0, int *a1, int *a2) {
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(a0)) {
        return func_00369F20(0, 0xFF03020Eu);
    }
    *a1 = *(int *)((char *)a0 + 0x2B4);
    *a2 = *(int *)((char *)a0 + 0x2B8);
    return 0;
}

__attribute__((section(".text.func_0036DC70")))
void func_0036DC70(int *a0, int *a1, int *a2) {
    char *s0 = (char *)a0 + 0x160;
    if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(a0)) {
        M2VERR_SetCode(0, 0xFF03020Eu);
        return;
    }
    *a1 = *(int *)(s0 + 0xD0);
    *a2 = *(int *)(s0 + 0xD4);
}
