/* cygnus-2.96 matched TU. */

extern void func_00324C50(void);
extern void func_0032AF88(void);
extern void func_0033F590(void);
extern long long Forward334310_334B20(void);
extern void func_0034DC98(void);
extern void *GetD003EC7E0_3452B0();
extern void func_00349328(void);
extern void func_003298C0(void);
extern void func_0034B3E0(int a, int b);
extern void func_00368DF0(void);
extern void func_0036C220(void);
extern void func_0035AE18(void);
extern int *GetD003EEA90_360D18(void);
extern long long func_00334310(void);
extern void func_00329EA8(int a);
extern void func_00355E88(int a);
extern void (*D_003D1418)(void);
extern void (*D_003D141C)(void);
extern void (*D_003D1424)(void);
extern int D_00456900;
extern int D_003EE078;
extern int D_003EE07C;
extern int D_003EE080;
extern int D_003EE084;
extern int GuardedCall_00329FD0_329F98(int a);
extern void func_0034C2B8(int a, int b, int *p);
extern void (*D_003F2000)(void);
extern void (*D_003F2008)(void);
extern void (*D_003F2010)(void);
extern void (*D_003F200C)(void);
extern void (*D_003F2024)(void);
extern void (*D_003F2028)(void);
extern void (*D_003F202C)(void);
extern void (*D_003F2034)(void);
extern void (*D_003F2038)(void);
extern void (*D_003F203C)(void);
extern void (*D_003F2040)(void);
extern void (*D_003F2044)(void);
extern void func_0033D230(int);
extern void (*D_003E9D20)(void);
extern void func_00335B88(int);
extern int (*D_003F2004)(void);
extern int (*D_003F2030)(void);
extern struct cb D_00755C20;
extern struct cb2 D_00755C28;

__attribute__((section(".text.func_003248F0")))
int func_003248F0(void) {
    func_00324C50();
    return 0;
}

__attribute__((section(".text.func_00324910")))
int func_00324910(void) {
    func_0032AF88();
    return 0;
}

__attribute__((section(".text.func_00324930")))
int func_00324930(void) {
    func_0033F590();
    return 0;
}

__attribute__((section(".text.func_00334B88")))
long long func_00334B88(void) {
    return Forward334310_334B20() >> 32;
}

__attribute__((section(".text.func_00336510")))
int func_00336510(int a0) {
    int x;
    func_003363F8(a0, &x);
    return x;
}

__attribute__((section(".text.func_00345828")))
int func_00345828(void) {
    func_0034DC98();
    return 0;
}

__attribute__((section(".text.func_003492E8")))
int func_003492E8(int a0) {
    int *p = GetD003EC7E0_3452B0(a0);
    return *(int *)((char *)p + 0x10);
}

__attribute__((section(".text.func_00349308")))
int func_00349308(void) {
    func_00349328();
    return 0;
}

__attribute__((section(".text.func_00349820")))
int func_00349820(int a0) {
    int *p = GetD003EC7E0_3452B0(a0);
    return *(int *)((char *)p + 0x188C);
}

__attribute__((section(".text.func_0034B270")))
int func_0034B270(void) {
    func_003298C0();
    return 0;
}

__attribute__((section(".text.func_0034B2A8")))
int func_0034B2A8(int a0) {
    func_0034B3E0(a0, 0);
    return 0;
}

__attribute__((section(".text.func_0034E1B8")))
int func_0034E1B8(void) {
    func_00368DF0();
    return 0;
}

__attribute__((section(".text.func_003506E0")))
int func_003506E0(void) {
    func_0036C220();
    return 0;
}

__attribute__((section(".text.func_0035AD00")))
int func_0035AD00(void) {
    func_0035AE18();
    return 0;
}

__attribute__((section(".text.func_00360D50")))
int func_00360D50(void) {
    return *GetD003EEA90_360D18();
}

__attribute__((section(".text.func_0031F4E0")))
int func_0031F4E0(int *a0, int *a1) {
    return (unsigned int)func_003A5678(*a0, *a1) >> 31;
}

__attribute__((section(".text.func_003342E8")))
int func_003342E8(void) {
    return func_00334310();
}

__attribute__((section(".text.func_00347DF8")))
int func_00347DF8(void) {
    return func_00335AA0() == 3;
}

__attribute__((section(".text.func_0034B2C8")))
int func_0034B2C8(char *a0) {
    func_00329EA8(**(int **)(a0 + 0x2004));
    return 0;
}

__attribute__((section(".text.func_00356790")))
int func_00356790(int a0, int a1, char *a2) {
    func_00355E88(*(int *)(a2 + 0x1FC0) + 0x1198);
    return 1;
}

__attribute__((section(".text.func_003567B8")))
int func_003567B8(int a0, int a1, char *a2) {
    func_00355F88((int *)(*(int *)(a2 + 0x1FC0) + 0x1198));
    return 1;
}

__attribute__((section(".text.func_00329848")))
void func_00329848(void)
{
    if (D_003D1418)
        D_003D1418();
}

__attribute__((section(".text.func_00329870")))
void func_00329870(void)
{
    if (D_003D141C)
        D_003D141C();
}

__attribute__((section(".text.func_00329898")))
void func_00329898(void)
{
    if (D_003D1424)
        D_003D1424();
}

__attribute__((section(".text.func_00336CE0")))
void func_00336CE0(void)
{
    if (D_003D1424)
        D_003D1424();
}

__attribute__((section(".text.func_0033DD50")))
int func_0033DD50(int a0) {
    return func_003A50B4(a0, &D_00456900, 4) == 0;
}

__attribute__((section(".text.func_00346450")))
void func_00346450(void) {
    D_003EE078 = 1;
    D_003EE07C = 0;
    D_003EE080 = 0;
    D_003EE084 = 0;
}

__attribute__((section(".text.func_003497F8")))
void func_003497F8(int a0) {
    char *p = GetD003EC7E0_3452B0();
    *(int *)(p + 0x188C) = a0;
}

__attribute__((section(".text.func_0034A7F0")))
int func_0034A7F0(char *a0) {
    int *p = *(int **)(a0 + 0x2004);
    return GuardedCall_00329FD0_329F98(*p) == 3;
}

__attribute__((section(".text.func_0034CAD0")))
int func_0034CAD0(int a0, int a1) {
    int buf[8];
    func_0034C2B8(a0, a1, buf);
    return buf[1] + buf[3];
}

__attribute__((section(".text.func_00360D28")))
void func_00360D28(int a0) {
    int *p = GetD003EEA90_360D18();
    *p = a0;
}

__attribute__((section(".text.func_0036CCF0")))
void func_0036CCF0(void) {
    if (D_003F2000) {
        D_003F2000();
    }
}

__attribute__((section(".text.func_0036CD48")))
void func_0036CD48(void) {
    if (D_003F2008) {
        D_003F2008();
    }
}

__attribute__((section(".text.func_0036CD70")))
void func_0036CD70(void) {
    if (D_003F2010) {
        D_003F2010();
    }
}

__attribute__((section(".text.func_0036CD98")))
void func_0036CD98(void) {
    if (D_003F200C) {
        D_003F200C();
    }
}

__attribute__((section(".text.func_0036CDC0")))
void func_0036CDC0(void) {
    if (D_003F2024) {
        D_003F2024();
    }
}

__attribute__((section(".text.func_0036CDE8")))
void func_0036CDE8(void) {
    if (D_003F2028) {
        D_003F2028();
    }
}

__attribute__((section(".text.func_0036CE10")))
void func_0036CE10(void) {
    if (D_003F202C) {
        D_003F202C();
    }
}

__attribute__((section(".text.func_0036CE68")))
void func_0036CE68(void) {
    if (D_003F2034) {
        D_003F2034();
    }
}

__attribute__((section(".text.func_0036CE90")))
void func_0036CE90(void) {
    if (D_003F2038) {
        D_003F2038();
    }
}

__attribute__((section(".text.func_0036CEB8")))
void func_0036CEB8(void) {
    if (D_003F203C) {
        D_003F203C();
    }
}

__attribute__((section(".text.func_0036CEE0")))
void func_0036CEE0(void) {
    if (D_003F2040) {
        D_003F2040();
    }
}

__attribute__((section(".text.func_0036CF08")))
void func_0036CF08(void) {
    if (D_003F2044) {
        D_003F2044();
    }
}

long long func_003AD0C0(int a0, int b, int c);
__attribute__((section(".text.func_003A7C48")))
int func_003A7C48(int a0) {
	return func_003AD0C0(a0, 0, 0xA);
}

__attribute__((section(".text.func_003B9AF8")))
void func_003B9AF8(void) {
    if (D_003D141C) {
        D_003D141C();
    }
}

__attribute__((section(".text.func_00326860")))
void func_00326860(int *a0) {
    func_0033D230(a0[1]);
    *((char *)a0 + 1) = 0;
}

__attribute__((section(".text.func_0033C2C0")))
void func_0033C2C0(int *a0) {
    if (a0[0x30]) {
        D_003E9D20();
    }
}

__attribute__((section(".text.func_00347E20")))
void func_00347E20(int *a0) {
    int v0 = a0[0x12];
    if (v0) {
        func_00335B88(v0);
    }
}

__attribute__((section(".text.func_0036CD18")))
int func_0036CD18(void) {
    if (D_003F2004) {
        return D_003F2004();
    }
    return 0;
}

__attribute__((section(".text.func_0036CE38")))
int func_0036CE38(void) {
    if (D_003F2030) {
        return D_003F2030();
    }
    return 0;
}

struct cb { void (*fn)(int); int arg; };


__attribute__((section(".text.func_00325FA8")))
void func_00325FA8(void) {
    if (D_00755C20.fn != 0) {
        D_00755C20.fn(D_00755C20.arg);
    }
}

struct cb2 { void (*fn)(int); int arg; };


__attribute__((section(".text.func_00325FD8")))
void func_00325FD8(void) {
    if (D_00755C28.fn != 0) {
        D_00755C28.fn(D_00755C28.arg);
    }
}
