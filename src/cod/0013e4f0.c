/* sn-2.95.3-136 matched TU. */

extern void func_00326020(int a0);
extern void func_003A6A20(const char *s);
extern void func_003292D8(void *p);
extern void func_003290B8(void *p);
extern int ADXPS2_LoadFcacheDvd(void *p);
extern void func_00325638(void *p);
extern void Obj3260_Tramp_00336E88_D148(int a0, int a1);
extern void func_00324950(void);
extern void func_0032D1A0(void);
extern void Obj3290_SetGlobal_D003D1400(int a0);
extern void func_0032BAF0(const char *s);
extern void Obj3290_Tramp_003313F0_9278(int a0);
extern int Obj0000_Get_D_0076A7A4_3756F0(void);
extern void func_0032BA30(int a0);
extern char D_0044CDE0[];
extern char D_0044CE00[];
extern char D_0044CE10[];
extern char D_0044CE20[];
extern char D_00601F80[];
extern char D_00747A24[];
extern char D_00569B70[];
extern int cCoreSave_getKeyCardNum(void *p);
extern int cCoreSave_getKeyNum(void *p);
extern void cIDBase_move(void *p);
extern char *cIDBase_getIDWork(void *this, int idx);
extern int D_0071B7C0[];
extern int D_0071B840[];
extern int D_0071B8C0[];
extern unsigned char D_0061B7C0[];

struct SA { void *f0; int f4; int f8; int fC; };
struct SB { int f0; int f4; int f8; int fC; int f10; };
struct SC { void *f0; int f4; void *f8; int fC; };
struct SD { int f0; int f4; int f8; int fC; int f10; int f14; };

__attribute__((section(".text.func_002CA220")))
void func_002CA220(void)
{
    struct SA a;
    struct SB b;
    struct SC c;
    struct SD d;

    func_00326020(2);
    func_003A6A20(D_0044CDE0);
    func_003A52F0(&a, 0, sizeof(a));
    a.f0 = D_0044CE00;
    a.f4 = 0;
    func_003292D8(&a);
    func_003A52F0(&b, 0, sizeof(b));
    b.f0 = 0;
    b.f4 = 0;
    b.f8 = 0;
    b.fC = 0;
    b.f10 = 0;
    func_003290B8(&b);
    func_003A52F0(&c, 0, sizeof(c));
    c.f0 = D_0044CE10;
    c.f4 = 0x20;
    c.f8 = D_00601F80;
    c.fC = 0x668;
    ADXPS2_LoadFcacheDvd(&c);
    func_003A52F0(&d, 0, sizeof(d));
    d.f0 = 1;
    d.f4 = 8;
    d.f8 = 0x10;
    d.fC = 0x12;
    d.f10 = 0x18;
    d.f14 = 0x60;
    func_00325638(&d);
    Obj3260_Tramp_00336E88_D148(0xA, 0);
    func_00324950();
    func_0032D1A0();
    Obj3290_SetGlobal_D003D1400(1);
    func_0032BAF0(D_0044CE20);
    Obj3290_Tramp_003313F0_9278(1);
    if (Obj0000_Get_D_0076A7A4_3756F0() == 0)
        func_0032BA30(1);
}

__attribute__((section(".text.func_0013E4F0")))
void func_0013E4F0(char *p)
{
    char *g;
    unsigned long fl;
    unsigned long bit;

    fl = *(int *)D_00747A24;
    bit = (fl >> 3) & 1;
    if (bit) return;
    g = D_00747A24;
    if (*(int *)(g + 0x8) < 0) return;
    if (*(int *)(p + 0x9C) == 0) return;
    if (cCoreSave_getKeyCardNum(D_00569B70) > 0) {
        *(int *)(*(char **)(p + 0x9C) + 0x2C) &= ~0x08000000;
        *(int *)(*(char **)(p + 0x9C) + 0x84) = cCoreSave_getKeyCardNum(D_00569B70);
    } else {
        *(int *)(*(char **)(p + 0x9C) + 0x2C) |= 0x08000000;
    }
    if (cCoreSave_getKeyNum(D_00569B70) > 0) {
        *(int *)(*(char **)(p + 0xA0) + 0x2C) &= ~0x08000000;
        *(int *)(*(char **)(p + 0xA0) + 0x84) = cCoreSave_getKeyNum(D_00569B70);
    } else {
        *(int *)(*(char **)(p + 0xA0) + 0x2C) |= 0x08000000;
    }
    cIDBase_move(p);
    if (*(int *)(p + 0x90) == 0) return;
    if (*(int *)(p + 0x100) != 0) {
        *(int *)(cIDBase_getIDWork(p + 0xB0, 0) + 0x2C) &= ~0x08000000;
        *(int *)(cIDBase_getIDWork(p + 0xB0, 0) + 0x84) = *(int *)(p + 0x100);
    } else {
        *(int *)(cIDBase_getIDWork(p + 0xB0, 0) + 0x2C) |= 0x08000000;
    }
    cIDBase_move(p + 0xB0);
    if (*(unsigned char *)(p + 0x104) == 1) {
        *(int *)(cIDBase_getIDWork(p + 0xB0, 1) + 0x2C) &= ~0x08000000;
        *(int *)(cIDBase_getIDWork(p + 0xB0, 1) + 0x84) = *(int *)(p + 0x100);
    } else {
        *(int *)(cIDBase_getIDWork(p + 0xB0, 1) + 0x2C) |= 0x08000000;
    }
    cIDBase_move(p + 0xB0);
}

__attribute__((section(".text.func_002FBA60")))
void func_002FBA60(int a0, int a1, unsigned char a2)
{
    char *p;
    char *q;
    int i;
    unsigned int mask;
    int w;

    for (i = 0; i < 0x400; i++) {
        w = (unsigned int)i >> 5;
        mask = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & mask) == 0) goto next;
        if ((D_0071B840[w] & mask) != 0) goto next;
        if ((D_0071B8C0[w] & mask) != 0) goto next;
        p = (char *)D_0061B7C0 + i * 0x400;
        if (*(int *)(p + 0x10C) != a1) goto next;
        if (*(int *)(p + 0x108) != a0) goto next;
        q = *(char **)(p + 0xF0);
        (*(void (**)(char *, int))(q + 0x34))(p + *(short *)(q + 0x30), a2);
next: ;
    }
}
