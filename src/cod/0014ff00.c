/* sn-2.95.3-136 matched TU. */

extern long cOmBase_canItemDrop(int a0);
extern unsigned char D_005864F0[];
extern void cEmManage__CreateItem(void *a0, int a1, int a2, int a3);
extern int D_00569B70;
extern int D_005E8658;
extern void func_001FB2D8();
extern void func_002BECB0();
extern unsigned char D_005FEE00[];
extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern int D_00747470;
extern void classFADE_kill(void *p);
extern void func_002A9098();
extern char D_003BE548[];
extern short D_005CAE40;

__attribute__((section(".text.func_0014FF00")))
void func_0014FF00(int a0, unsigned int a1, int a2, int a3)
{
    unsigned int count;
    unsigned int n;
    int entry;
    long next;
    long v;

    count = *(unsigned int *)((char *)a0 + 0x20);
    n = (count < a1) ? count : a1;
    entry = *(int *)a0 + ((count - n) << 4);
    next = *(unsigned int *)((char *)entry + 4);
    *(long *)entry = ((long)a2 << 32) | 0x20000000;
    v = *(long *)a3;
    v = v & 0xFFFFFFF;
    v = v | 0x20000000;
    v = v | (next << 32);
    *(long *)a3 = v;
}

__attribute__((section(".text.func_001889C8")))
void func_001889C8(unsigned char *a0)
{
    long v0 = *(unsigned int *)(a0 + 0x5B0);

    if (((v0 >> 1) & 1) == 0) {
        *(int *)(a0 + 0x5B0) |= 1;
        *(unsigned char *)(a0 + 0x2F4) = 2;
        *(unsigned char *)(a0 + 0x2F6) = 0;
        *(unsigned char *)(a0 + 0x2F7) = 0;
        *(unsigned char *)(a0 + 0x2F5) = 0;
    }
}

__attribute__((section(".text.func_001B79E0")))
long func_001B79E0(int a0)
{
    long v;
    long b;
    int h;

    v = *(unsigned int *)(a0 + 0x5B0);
    b = v >> 1 & 1;
    if (b == 1) {
        return 0;
    }
    v = *(unsigned int *)(a0 + 0x5B8);
    b = v >> 13 & 1;
    if (b == 1) {
        return 0;
    }
    if (cOmBase_canItemDrop(a0) == 1) {
        h = *(unsigned short *)(a0 + 0x2FE);
        if (h < 0x3DA) {
            return 1;
        }
        if (h >= 0x3DE) {
            if (h != 0x3EA) {
                return 1;
            }
        }
    }
    v = *(unsigned int *)(a0 + 0x5B8);
    return v >> 8 & 1;
}

__attribute__((section(".text.func_001B7BB8")))
void func_001B7BB8(int a0)
{
    long v;
    long b;

    v = *(unsigned int *)(a0 + 0x5B0);
    b = v >> 4 & 1;
    if (b == 1) {
        return;
    }
    *(int *)(a0 + 0x5B0) |= 0x10;
    if (cOmBase_canItemDrop(a0) == 1) {
        if (*(int *)(a0 + 0x560) != 0xFFFF) {
            cEmManage__CreateItem(&D_005864F0, *(int *)(a0 + 0xF0), *(int *)(a0 + 0x560), 0);
        } else {
            cEmManage__CreateItem(&D_005864F0, *(int *)(a0 + 0xF0), 0xFFFF, 0);
        }
    }
}

__attribute__((section(".text.func_001BFFE0")))
void func_001BFFE0(unsigned char *a0)
{
    long v0 = *(unsigned int *)(a0 + 0x5B0);

    if (((v0 >> 1) & 1) == 0) {
        *(int *)(a0 + 0x5B0) |= 1;
        *(unsigned char *)(a0 + 0x2F4) = 2;
        *(unsigned char *)(a0 + 0x2F6) = 0;
        *(unsigned char *)(a0 + 0x2F7) = 0;
        *(unsigned char *)(a0 + 0x2F5) = 0;
    }
}

__attribute__((section(".text.func_001C24E8")))
void func_001C24E8(char *a0) {
    long v;

    *(char *)(a0 + 0x2F6) = 4;
    *(char *)(a0 + 0x660) = 1;
    *(char *)(a0 + 0x2F4) = 0;
    *(char *)(a0 + 0x2F5) = 0;
    *(int *)(a0 + 0x630) = 0;
    v = *(unsigned int *)(a0 + 0x5B0);
    if (((v >> 5) & 1) == 0) {
        func_001FB2D8(&D_00569B70, *(unsigned short *)(a0 + 0x662));
    } else {
        func_002BECB0(&D_005E8658, *(long *)(a0 + 0x538));
    }
}

__attribute__((section(".text.func_001C3B98")))
void func_001C3B98(unsigned char *a0)
{
    long v0 = *(unsigned int *)(a0 + 0x5B0);

    if (((v0 >> 1) & 1) == 0) {
        *(int *)(a0 + 0x5B0) |= 1;
        *(unsigned char *)(a0 + 0x2F4) = 2;
        *(unsigned char *)(a0 + 0x2F6) = 0;
        *(unsigned char *)(a0 + 0x2F7) = 0;
        *(unsigned char *)(a0 + 0x2F5) = 0;
    }
}

__attribute__((section(".text.func_001D0C98")))
void func_001D0C98(unsigned char *a0, int a1)
{
    long v0 = *(unsigned int *)(a0 + 0x4);

    if (((v0 >> 1) & 1) == 0 && ((v0 >> 2) & 1) == 0) {
        if (a1 != 0) {
            *(int *)(a0 + 0x4) |= 4;
        } else {
            *(int *)(*(int *)a0 + 0x104) = 0;
            *(int *)(a0 + 0x4) |= 2;
        }
    }
}

__attribute__((section(".text.func_001D0D90")))
void func_001D0D90(int a0, int a1)
{
    char *p = (char *)a0;
    long v = *(unsigned int *)(p + 4);
    if (((v >> 1) & 1) == 0) {
        return;
    }
    if (((v >> 2) & 1) == 0) {
        if (a1 != 0) {
            *(int *)(p + 4) |= 4;
        } else {
            *(float *)(*(int *)p + 0x104) = 3.1415927f;
            *(int *)(p + 4) &= ~2;
        }
    }
}

__attribute__((section(".text.func_001D6DD0")))
void func_001D6DD0(unsigned char *a0, int a1)
{
    long v0 = *(unsigned int *)(a0 + 0x4);

    if (((v0 >> 3) & 1) == 0 && ((v0 >> 4) & 1) == 0) {
        if (a1 != 0) {
            *(int *)(a0 + 0x4) |= 0x10;
        } else {
            *(int *)(*(int *)a0 + 0x104) = 0;
            *(int *)(a0 + 0x4) |= 8;
        }
    }
}

__attribute__((section(".text.func_001D6EC8")))
void func_001D6EC8(char *a0, int a1) {
    long v;

    v = *(unsigned int *)(a0 + 4);
    if (((v >> 3) & 1) == 0) {
        return;
    }
    if (((v >> 4) & 1) == 0) {
        if (a1 != 0) {
            *(int *)(a0 + 4) = *(int *)(a0 + 4) | 0x10;
        } else {
            *(float *)(*(int *)(a0 + 0) + 0x104) = 3.14159265358979f;
            *(int *)(a0 + 4) = *(int *)(a0 + 4) & ~8;
        }
    }
}

__attribute__((section(".text.func_001DBE18")))
void func_001DBE18(int a0, int a1)
{
    int list[0x34];
    int n;
    int i;
    int p;
    int q;
    int *c;
    long v;
    int r;

    n = 0;
    i = 0;
    p = a0 + 0x2E64;
    q = a0 + 0x2E68;
    c = list;
    for (; i < 0x34; i += 2, i -= 1, p += 8, q += 8) {
        v = *(unsigned int *)q;
        if ((v & 1) == 0) {
            continue;
        }
        *c = p;
        n++;
        c++;
    }
    if (n != 0) {
        r = list[func_001DCE68(a0, 0, n - 1)];
        *(int *)a1 = r;
        *(int *)(r + 4) &= ~1;
    }
}

__attribute__((section(".text.func_001EC820")))
void func_001EC820(int a0)
{
    long v;
    int p;

    v = *(unsigned int *)(a0 + 0x54);
    if ((v >> 11 & 1) == 0) {
        p = func_001EC388(a0, 0);
        if (p != 0) {
            v = *(unsigned int *)(p + 0x30);
            if ((v >> 2 & 1) == 0) {
                return;
            }
            *(int *)(a0 + 0x2A08) = cSnd_SeCall(&D_005FEE00, 2, 3, *(int *)(a0 + 0x200) + 0x210, 0, 0);
            *(int *)(a0 + 0x54) |= 0x800;
        }
    }
}

__attribute__((section(".text.func_001EFD00")))
void func_001EFD00(unsigned char *a0)
{
    long v0 = *(unsigned int *)(a0 + 0x54);

    if (((v0 >> 1) & 1) == 0) {
        return;
    }
    classFADE_kill(&D_00747470);
    *(int *)(a0 + 0x54) &= ~2;
}

__attribute__((section(".text.func_001F44E0")))
void func_001F44E0(int a0)
{
    long v0 = *(unsigned int *)((char *)a0 + 0x54);
    if (((v0 >> 1) & 1) == 0) {
        return;
    }
    classFADE_kill(&D_00747470);
    *(int *)((char *)a0 + 0x54) &= ~2;
}

typedef struct {
    unsigned int lo;
    int hi;
} Elem;



__attribute__((section(".text.func_002A9210")))
void func_002A9210(Elem *a0, Elem *a1, int a2, int a3) {
    Elem tmp;

    while (a0 != a1) {
        tmp = *a0;
        func_002A9098(a0, ((long)tmp.hi << 32) | tmp.lo, a3);
        a0 = a0 + 1;
    }
}

__attribute__((section(".text.cScenario_isOmBreak")))
int cScenario_isOmBreak(int a0, int a1)
{
    long v;
    int r;
    if (a1 == 0) {
        return 1;
    }
    if (func_002BED08(&D_005E8658, *(long *)((char *)a1 + 0x538)) == 1) {
        return 1;
    }
    r = 0;
    v = *(unsigned int *)((char *)a1 + 0x5B0);
    if ((v >> 1) & 1) {
        r = 1;
    }
    return r;
}

__attribute__((section(".text.ColiseumBattle_Main")))
void ColiseumBattle_Main(char *a0) {
    int i;
    short off;
    void (*fn)();
    long v;

    i = *(int *)(a0 + 4);
    off = *(short *)(D_003BE548 + i * 8);
    fn = *(void (**)())(D_003BE548 + i * 8 + 4);
    fn(a0 + off);
    v = *(unsigned int *)(a0 + 0x54);
    if (((v >> 2) & 1) == 0) {
        return;
    }
    D_005CAE40 = 0xF;
}
