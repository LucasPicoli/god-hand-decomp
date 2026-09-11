/* cygnus-2.96 matched TU. */

typedef struct Obj {
    void *f0;
    char pad4[0x30];
    int f34;
    int f38;
    void (*f3C)(void);
} Obj;

typedef struct Hd {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Hd;


extern void func_003B9D60(void *ax, int a1, int a2, int a3);
extern void func_0032B618(void *ax, int sw);
extern void func_0034A5E0(void);

__attribute__((section(".text.func_0034B588")))
int func_0034B588(void *hn)
{
    Hd *hd;
    Obj *p;
    void *ax;

    hd = func_0034B618(hn);
    if (hd == 0) return 0;
    p = *(Obj **)((char *)hn + 0x2004);
    ax = p->f0;
    if (p->f34 != 0) return 0;
    if (hd->f0 == 0) return 0;
    func_003B9D60(ax, hd->fC, hd->f10, hd->f14);
    func_0032B618(ax, 0);
    p->f34 = 1;
    p->f3C = func_0034A5E0;
    return 0;
}
