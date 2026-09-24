/* sn-2.95.3-136 matched TU. */

extern int D_00741940[];
extern int D_00741960[];
extern int D_00741980[];
extern unsigned char D_0071B940[];
extern void func_00302918(void *p);
extern int IsEntryActive_1C2490(int a0);
extern void SetField_630_1C2370(int a0);
extern char D_00747470[];
extern char *D_003C2F84;
extern char *D_003C23A4;
extern unsigned int D_00747A8C[];
extern int D_00747A84;
extern int D_005FEE00;
extern void SetFieldsCESignalSemaSleep_2D5AA0(void *p, int a);
extern void cMessage_deleteAll(void *p);
extern void func_002CA6B0(void *p);
extern void func_00306140(void);
extern void cScenario_taskExec(void *a0, int a1, int a2, int a3);
extern void classFADE_start(void *p, int b, int c, int d, unsigned int e, int f, int g);
extern void cTaskWork_exit(void *a0);
extern void func_001D0C98(void *a0, int a1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void *cIDBase(void *a0);
extern void Obj0000_Store_D_00747A44_2BE968(void *a0);
extern char D_0041F190[];
extern char D_0041F6C8[];
extern char D_0041FF30[];
extern char D_0041F388[];
extern char D_0041F5E0[];
extern char D_0041FB20[];
extern char D_0041FBE8[];
extern char D_0041F200[];
extern char D_0041FC60[];
extern char D_0041FDF8[];
extern void func_0032EC78(int a0, int a1, int a2);
extern void func_0032A9F0(int a0, int a1);

/* sn-2.95.3-136 */







__attribute__((section(".text.func_00300C00")))
void func_00300C00(int a0, int a1)
{
    char *p;
    int i;
    unsigned int mask;
    int w;

    for (i = 0; i < 0x100; i++) {
        w = (unsigned int)i >> 5;
        mask = 0x80000000u >> (i & 0x1F);
        if ((D_00741940[w] & mask) == 0) goto next;
        if ((D_00741960[w] & mask) != 0) goto next;
        if ((D_00741980[w] & mask) != 0) goto next;
        p = (char *)D_0071B940 + i * 0x260;
        if (a1 == 1) {
            if ((*(int *)(p + 0x118) & a0) != 0) goto call;
        }
        if (a1 != 0) goto next;
        if ((*(int *)(p + 0x118) & a0) != 0) goto next;
call:
        func_00302918(p);
next: ;
    }
}

struct Entry_00288930 { short f0; short f2; short f4; short f6; };
typedef struct { char b[0x18]; } Blob18;
extern Blob18 D_00448C78;

__attribute__((section(".text.func_00288930")))
void func_00288930(char *s0)
{
    struct Entry_00288930 tbl[3];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(Blob18 *)tbl = D_00448C78;
    if (*(int *)(s0 + 0x15C4) != 0) {
        if (IsEntryActive_1C2490(*(int *)(s0 + 0x15C4)) != 0) {
            *(int *)(s0 + 0x15C4) = 0;
        } else {
            SetField_630_1C2370(*(int *)(s0 + 0x15C4));
        }
        *(int *)(s0 + 0x15C4) = 0;
    }
    if (*(unsigned char *)(s0 + 0x2F5) >= 3)
        *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[*(unsigned char *)(s0 + 0x2F5)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

__attribute__((section(".text.func_002C4EF0")))
void func_002C4EF0(void)
{
    int b;
    char *f;

    while (f = D_00747470, *(unsigned char *)(f + 0x1C) != 0)
        SetFieldsCESignalSemaSleep_2D5AA0(*(void **)(D_003C2F84 + 0x20), 1);
    b = *(signed char *)(D_003C2F84 + 0x109);
    if (b >= 0)
        if (b < 0x40)
            D_00747A8C[(unsigned int)b >> 5] |= 0x80000000u >> (b & 0x1F);
    cMessage_deleteAll(D_003C23A4);
    func_002CA6B0(&D_005FEE00);
    func_00306140();
    if (*(int *)(D_003C2F84 + 0xFC) != 0)
        cScenario_taskExec(D_003C2F84, *(int *)(D_003C2F84 + 0xFC), *(int *)(D_003C2F84 + 0x100), *(int *)(D_003C2F84 + 0x10C));
    if (*(unsigned char *)(D_003C2F84 + 0x110) != 0)
        classFADE_start(D_00747470, 0, 8, 0, 0xFF000000U, 0, 0xF);
    D_00747A84 &= ~0x10;
    cTaskWork_exit(*(void **)(D_003C2F84 + 0x20));
}

__attribute__((section(".text.func_001D32D8")))
void func_001D32D8(char *s1)
{
    int i;
    int j;
    int n;
    int ok;
    long v;
    int **arr;
    char **arr2;

    switch (*(unsigned int *)(s1 + 0x1808)) {
    case 0:
        *(int *)(s1 + 0x180C) = 0x14;
        *(int *)(s1 + 0x1808) += 1;
        break;
    case 1:
        if (*(int *)(s1 + 0x180C) == 0) {
            for (i = 0; i < *(unsigned short *)(s1 + 0x17FE); i++) {
                arr = (int **)(s1 + 0x17E8) + i;
                func_001D0C98(*arr, 1);
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, **arr, 0, 0, 0, 0);
            }
            *(int *)(s1 + 0x1808) += 1;
        } else {
            *(int *)(s1 + 0x180C) -= 1;
        }
        break;
    case 2:
        ok = 1;
        n = *(unsigned short *)(s1 + 0x17FE);
        for (j = 0; j < n; j++) {
            v = *(unsigned int *)(((char **)(s1 + 0x17E8))[j] + 4);
            if (((v >> 1) & 1) == 0)
                ok = 0;
        }
        if (ok)
            *(int *)(s1 + 0x1808) += 1;
        break;
    case 3:
        *(int *)(s1 + 0x1808) = 0;
        *(int *)(s1 + 0x1804) = 0xD;
        break;
    }
}

#include "godhand/vu0.h"














static __inline__ void Ctor_0041F6C8(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041F6C8;
}

static __inline__ void Ctor_0041FF30(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041FF30;
}

static __inline__ void Ctor_0041F388(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041F388;
}

static __inline__ void Ctor_0041F5E0(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041F5E0;
}

static __inline__ void Ctor_0041FB20(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041FB20;
}

static __inline__ void Ctor_0041FBE8(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041FBE8;
}

static __inline__ void Ctor_0041F200(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041F200;
}

static __inline__ void Ctor_0041FC60(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041FC60;
}

static __inline__ void Ctor_0041FDF8(char *o)
{
    *(char **)(o + 0x70) = D_0041F190;
    cIDBase(o);
    *(char **)(o + 0x70) = D_0041FDF8;
}

__attribute__((section(".text.func_001612C8")))
void *func_001612C8(char *p)
{
    Ctor_0041F6C8(p + 0x60);
    cIDBase(p + 0x160);
    cIDBase(p + 0x1E0);
    cIDBase(p + 0x290);
    Ctor_0041FF30(p + 0x310);
    cIDBase(p + 0x480);
    VU0_SQC2_VF0(p, 0x580);
    cIDBase(p + 0x5A0);
    Ctor_0041F388(p + 0x620);
    Ctor_0041F5E0(p + 0x730);
    VU0_SQC2_VF0(p, 0x830);
    VU0_SQC2_VF0(p, 0x840);
    Obj0000_Store_D_00747A44_2BE968(p + 0x868);
    Ctor_0041FB20(p + 0x880);
    cIDBase(p + 0x960);
    Ctor_0041FBE8(p + 0x9C0);
    cIDBase(p + 0xA80);
    Ctor_0041F200(p + 0xAE0);
    Ctor_0041FC60(p + 0xBA0);
    Ctor_0041FDF8(p + 0xC40);
    cIDBase(p + 0xD10);
    VU0_SQC2_VF0(p, 0xE30);
    cIDBase(p + 0xE50);
    return p;
}

/* sn-2.95.3-136 */




__attribute__((section(".text.func_00383A20")))
void func_00383A20(int a0, unsigned char *p)
{
    int i;
    int j;
    int k;
    int h;
    int n;
    unsigned char *q;
    unsigned char *r;
    unsigned char *s;
    unsigned char *t;
    unsigned char *u;
    unsigned char *v;
    unsigned short *d1;
    unsigned short *d2;

    if (p[4] == 0) {
        i = 0;
        d1 = (unsigned short *)(p + 0xA);
        d2 = (unsigned short *)(p + 0x14);
    copy:
        *d2++ = *(unsigned short *)(p + 0x12);
        *d1++ = *(unsigned short *)(p + 8);
        if (++i < 4)
            goto copy;
    }
    if ((p[3] & 1) != 0) {
        q = p + 0xA4;
        h = *(int *)(q + 0x20);
        if (h == 0) {
            return;
        }
        if (p[4] != 0) {
            n = p[4];
            t = p;
            t += n;
            if (t[0xBC] != 0) {
                return;
            }
            u = p;
            u += n * 2;
            func_0032EC78(h, n - 1, *(short *)(u + 8));
        } else {
            for (j = 0; j < *(int *)(q + 8); j++) {
                r = p + 0xBC;
                s = p + 8;
                k = j + 1;
                if (r[k] == 0) {
                    v = s;
                    v += p[4] * 2;
                    func_0032EC78(*(int *)(q + 0x20), j, *(short *)v);
                }
            }
        }
    } else {
        if (*(int *)(p + 0x64) != 0) {
            func_0032A9F0(*(int *)(p + 0x64), *(short *)(p + 8));
        }
    }
}
