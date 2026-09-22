/* sn-2.95.3-136 matched TU. */

extern void cIDBase_trans(void *p);
extern int Obj0000_Get_Short_BBA_Bit0_Via_Ptr_1FC708(void *p);
extern char D_00747A24[];
extern char D_00569B70[];
extern int cDamageManage_ReleaseDamageGive(void *m, void *d);
extern void KillEffect(void *p, int a, int b);
extern void espSys_effDataRelease(void *a, int b);
extern void Tramp_00312708_1B79B0(void *p);
extern void SetField214PtrThenInit_1B6F38(void *a, void *b);
extern char D_0042AA98[];
extern char D_00574380[];
extern char D_007419A0[];
extern int cSnd_GetBgmData(int a0, int a1);
extern int D_005FEE00;
extern int cSaveLoad_openLoad(void *p);
extern char D_00747A2C[];
extern char D_00747A88[];
extern char D_003C2648[];
extern int GuardedCall_00329FD0_329F98(void *h);
extern void func_00381D60(void *a, void *b, void *c);

__attribute__((section(".text.func_0013EBA0")))
void func_0013EBA0(char *p)
{
    char *w;
    char *g;
    unsigned long fl;
    unsigned long bit;

    if (*(int *)(p + 0x94) == 0) return;
    w = *(char **)(p + 0x9C);
    if (w == 0) return;
    fl = *(int *)D_00747A24;
    bit = (fl >> 3) & 1;
    if (bit) return;
    g = D_00747A24;
    if (*(int *)(g + 0x8) < 0) return;
    if (*(short *)(w + 0x548) == 0) return;
    if ((*(int *)(p + 0xA0) & 0x20000000) == 0) return;
    if (Obj0000_Get_Short_BBA_Bit0_Via_Ptr_1FC708((void *)D_00569B70) != 0) return;
    if ((*(int *)(g + 0x60) & 0x80000) != 0) return;
    cIDBase_trans(p);
}

typedef void (*Fn)(void *, int);
typedef struct { short delta; short index; void *pfn; } VtEnt;

__attribute__((section(".text.func_002BA250")))
int func_002BA250(char *p)
{
    unsigned int i;
    char *e;
    int f;
    VtEnt *vt;

    for (i = 0; i < (unsigned int)*(int *)(p + 0x4); i++) {
        e = *(char **)(p + 0x0) + *(int *)(p + 0x8) * i;
        f = *(int *)e;
        if ((f & 0x603) != 0) {
            if ((f & 0x400) != 0) {
                if (e != 0) {
                    vt = *(VtEnt **)(e + 0x8);
                    ((Fn)vt[1].pfn)(e + vt[1].delta, 3);
                }
                *(int *)e = 0;
            } else if ((f & 0x200) != 0) {
                *(int *)e = f | 0x400;
            }
        }
    }
    return 1;
}

__attribute__((section(".text.func_001C91B0")))
void func_001C91B0(char *p, void *arg)
{
    void *d;

    *(void **)(p + 0x214) = (void *)D_0042AA98;

    d = *(void **)(p + 0x650);
    if (d != 0) {
        if (cDamageManage_ReleaseDamageGive((void *)D_00574380, d) != 0) {
            *(int *)(p + 0x650) = 0;
            *(int *)(p + 0x654) = -1;
        }
    }

    KillEffect(p, 8, 2);

    if (*(unsigned short *)(p + 0x2FE) == 0x3AE) {
        espSys_effDataRelease((void *)D_007419A0, 0x206);
    }

    if (*(void **)(p + 0x68C) != 0) {
        Tramp_00312708_1B79B0(*(void **)(p + 0x68C));
        *(int *)(p + 0x68C) = 0;
    }

    SetField214PtrThenInit_1B6F38(p, arg);
}

typedef struct { int f0; int f4; int f8; unsigned short fC; unsigned short fE; } Arg;

__attribute__((section(".text.func_002CC9C0")))
int func_002CC9C0(char *p, int a1, int a2, int a3, int t0, int t1, int t2)
{
    Arg q;

    if (func_002CFF68(cSnd_GetBgmData((int)&D_005FEE00, a1)) == 0) return 0;
    q.f0 = a2;
    q.f4 = a3;
    q.f8 = t0;
    q.fC = t1;
    q.fE = t2;
    return func_002CC728(p, a1, &q, 1);
}

__attribute__((section(".text.func_00160F38")))
int func_00160F38(char *p)
{
    char *g;
    unsigned long fx;
    unsigned long bit;
    int st;

    g = D_00747A2C;
    if ((*(int *)(g + 0x8) & 0x800) != 0) return 1;
    fx = *(int *)(g + 0xC);
    if ((long)fx < 0) return 1;
    bit = (fx >> 6) & 1;
    if (bit) return 1;

    st = *(short *)(p + 0x52);
    if (st == 0) goto zero;
    if (st == 1) goto chk;
    goto clr;
zero:
    cSaveLoad_openLoad(*(void **)D_003C2648);
    *(unsigned short *)(p + 0x52) = *(unsigned short *)(p + 0x52) + 1;
chk:
    if ((*(int *)D_00747A88 & 0x40000000) != 0) return 0;
clr:
    *(int *)D_00747A24 = *(int *)D_00747A24 & -3;
    *(short *)(p + 0x52) = 0;
    return 1;
}

__attribute__((section(".text.func_0037FB70")))
void func_0037FB70(char *p)
{
    char *e = p + 0x348;
    char *g = p + 0x318;
    void *h;

    h = func_0032DCD0(*(int *)(e + 0x20), 0);
    if (GuardedCall_00329FD0_329F98(h) != 2) return;

    *(int *)(e + 0x0)  = func_0032E118(*(int *)(e + 0x20));
    *(int *)(e + 0x4)  = func_0032A530(h);
    *(int *)(e + 0x8)  = func_0032E1F0(*(int *)(e + 0x20));
    *(int *)(e + 0xC)  = func_0032E280(*(int *)(e + 0x20));
    *(int *)(e + 0x10) = func_0032E310(*(int *)(e + 0x20));

    func_00381D60(p, e, g);
    *(char *)(p + 0x2) = 1;
}
