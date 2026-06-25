/* cygnus-2.96 matched TU. */

extern int D_003D04B0;
extern char D_003D04D0[];
extern int Obj3270_GetVia4_Obj33C8_18_77E8(void *a0);
extern char D_004520D8[];
extern int Obj3270_GetVia4_Obj33C8_14_7788(void *a0);
extern char D_00452108[];
extern int Obj3270_GetVia4_0033CE98_77A0(void *a0);
extern char D_00452138[];
extern void func_0033F130(void *a);
extern int GetVia4_Obj33C8_GetByte_D_327950(char *a0);
extern char D_00452198[];
extern void func_00332808(char *a, char *b);
extern char D_00454458[];
extern void func_00334008(char *a, char *b);
extern char D_00454960[];
extern int D_003E3AC8;
extern char D_003E3AD0[];
extern int D_003E3FB0;
extern char D_003E3FB8[];
extern int D_003E7FE8;
extern char D_003E7FF0[];

__attribute__((section(".text.func_00327A00")))
void func_00327A00(void) {
    int *p;
    int v0;

    p = &D_003D04B0;
    v0 = *p - 1;
    *p = v0;
    if (v0) return;
    func_003A52F0(D_003D04D0, 0, 0xF00);
}

__attribute__((section(".text.func_0032A4E0")))
int func_0032A4E0(char *a0) {
    int v0;

    if (a0) goto nonnull;
    func_0033F130(D_004520D8);
    return -1;
nonnull:
    v0 = a0[1];
    if (v0 >= 2) {
        return Obj3270_GetVia4_Obj33C8_18_77E8(*(void **)(a0 + 4));
    }
    return 0;
}

__attribute__((section(".text.func_0032A568")))
int func_0032A568(char *a0) {
    int v0;

    if (a0) goto nonnull;
    func_0033F130(D_00452108);
    return -1;
nonnull:
    v0 = a0[1];
    if (v0 >= 2) {
        return Obj3270_GetVia4_Obj33C8_14_7788(*(void **)(a0 + 4));
    }
    return 0;
}

__attribute__((section(".text.func_0032A5F0")))
int func_0032A5F0(char *a0) {
    int v0;

    if (a0) goto nonnull;
    func_0033F130(D_00452138);
    return -1;
nonnull:
    v0 = a0[1];
    if (v0 >= 2) {
        return Obj3270_GetVia4_0033CE98_77A0(*(void **)(a0 + 4));
    }
    return 0;
}

__attribute__((section(".text.func_0032A680")))
int func_0032A680(char *a0)
{
    if (!a0) {
        func_0033F130(D_00452198);
        return -1;
    }
    return (*(signed char *)(a0 + 1) >= 2) ? GetVia4_Obj33C8_GetByte_D_327950(*(char **)(a0 + 4)) : 0;
}

__attribute__((section(".text.func_00333170")))
int func_00333170(char *a0)
{
    char *a1 = a0;
    if (!a1) {
        func_00332808(a0, D_00454458);
        return 0;
    }
    return (a1[2] == 1) ? (*(int *)(a1 + 0x14) << 11) : 0;
}

__attribute__((section(".text.func_00334AD0")))
int func_00334AD0(char *a0)
{
    char *a1 = a0;
    if (!a1) {
        func_00334008(a0, D_00454960);
        return 0;
    }
    return (a1[2] == 1) ? (*(int *)(a1 + 0x28) << 11) : 0;
}

__attribute__((section(".text.func_00338B40")))
void func_00338B40(void)
{
    if (--D_003E3AC8 != 0) {
        return;
    }
    func_003A52F0(D_003E3AD0, 0, 0x480);
}

__attribute__((section(".text.func_00339550")))
void func_00339550(void)
{
    if (--D_003E3FB0 != 0) {
        return;
    }
    func_003A52F0(D_003E3FB8, 0, 0x4000);
}

__attribute__((section(".text.func_0033A140")))
void func_0033A140(void)
{
    if (--D_003E7FE8 != 0) {
        return;
    }
    func_003A52F0(D_003E7FF0, 0, 0xC00);
}

__attribute__((section(".text.func_0034D450")))
int func_0034D450(void *a0) {
    void *s0;
    s0 = a0;
    if (*(int *)((char *)s0 + 0x36B0) == 0)
        return 0;
    if (func_00350138(s0) > 0)
        return 0;
    return *(int *)((char *)s0 + 0x36B0) + 0xC;
}

__attribute__((section(".text.func_003500E8")))
int func_003500E8(void *a0) {
    void *s0;
    s0 = a0;
    if (*(int *)((char *)s0 + 0x36B0) == 0)
        return 0;
    if (func_00350138(s0) > 0)
        return 0;
    return *(int *)((char *)s0 + 0x36B0) + 0x8A0;
}

__attribute__((section(".text.func_00351780")))
void func_00351780(void *a0, int *a1) {
    int *s0;
    int buf[8];
    s0 = a1;
    if (func_0034C2B8(a0, *(int *)((char *)a0 + 0x1FC8), buf) != 0) {
        s0[0] = 0;
        s0[1] = 0;
    } else {
        s0[0] = buf[0];
        s0[1] = buf[1];
    }
}
