/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, output.o :: _dispRefImage */

extern long long func_0031DE10(long long a, long long b);
extern void func_003B1EE0(char *buf, int size, char *fmt, int a, int b);
extern void func_0039C390(char *c, char *msg);
extern void func_0039BB20(char *c, char *pic);
extern void func_0039AEA0(char *c, char *pic);
extern char D_0045E5A8[];
extern unsigned int D_003FA1F8[];

__attribute__((section(".text._dispRefImage")))
void _dispRefImage(char *c, char *pic, int n)
{
    char buf[0x100];
    char *g;
    long long *p10;
    long long *p18;
    long long *p20;
    int ok;
    int ok2;
    int f;

    g = *(char **)(c + 0x868);
    p10 = (long long *)(g + 0x10);
    p18 = (long long *)(g + 0x18);
    p20 = (long long *)(g + 0x20);
    if (*(int *)(c + 0x8C) != 0 && *(long long *)(pic + 0x18) < 0
        && *(int *)(c + 0x98) >= 0) {
        int b = (int)*(long long *)(c + 0xA0);
        long long a = *(long long *)(c + 0x90);
        int b1 = b & 1;
        int s = (b & 1) & ((*(int *)(c + 0x9C) & 1) & (a & 1));
        int r = (int)(func_0031DE10(a, (long long)b) >> 1);
        *(long long *)(g + 0x10) = *(int *)(c + 0x98) + (r + s);
        if ((b1 & *(long long *)(c + 0x90)) != 0)
            *(int *)(c + 0x9C) = *(int *)(c + 0x9C) + 1;
    } else {
        *p10 = *(long long *)(pic + 0x18);
    }
    if (*(int *)(c + 0x108) == 2 && *(long long *)(c + 0x100) >= 0) {
        *p10 = *(long long *)(c + 0x100);
        *(int *)(c + 0x108) = 0;
        *(long long *)(c + 0x100) = -1;
    }
    *p18 = *(long long *)(pic + 0x20);
    *p20 = ((long long)*(int *)(pic + 0x34) << 8)
         | ((long long)*(int *)(pic + 0x38) << 7)
         | ((long long)*(int *)(pic + 0x3C) << 6)
         | ((long long)*(int *)(pic + 0x40) << 5)
         | ((long long)*(int *)(pic + 0x30) << 3)
         | (long long)*(int *)(pic + 0x2C);
    *(int *)(c + 0x98) = (int)*(long long *)(*(char **)(c + 0x868) + 0x10);
    *(long long *)(c + 0xA0) =
        D_003FA1F8[(int)(*(long long *)(*(char **)(c + 0x868) + 0x20) >> 5) & 0xF];
    *(int *)(c + 0xE0) = *(int *)(pic + 0x5C);
    *(int *)(c + 0xE4) = *(int *)(pic + 0x60);
    *(int *)(c + 0xC8) = *(int *)(pic + 0x44);
    *(int *)(c + 0xCC) = *(int *)(pic + 0x48);
    *(int *)(c + 0xD0) = *(int *)(pic + 0x4C);
    *(int *)(c + 0xD4) = *(int *)(pic + 0x50);
    *(int *)(c + 0xD8) = *(int *)(pic + 0x54);
    *(int *)(c + 0xDC) = *(int *)(pic + 0x58);
    f = *(int *)(c + 0xF4);
    if (f != 0)
        ok = *(int *)(c + 0xF0) >= *(int *)(pic + 0x4)
          && f >= *(int *)(pic + 0x8);
    else
        ok = *(int *)(c + 0xF8) >= *(int *)(pic + 0xC) * *(int *)(pic + 0x10);
    if (ok == 0) {
        func_003B1EE0(buf, 0x100, D_0045E5A8, *(int *)(pic + 0x4),
                      *(int *)(pic + 0x8));
        func_0039C390(c, buf);
    }
    ok2 = ok;
    if (ok2 != 0) {
        if (*(int *)(pic + 0x28) == 1) {
            if (*(int *)(c + 0xC4) != 0)
                func_0039BB20(c, pic);
            else
                func_0039AEA0(c, pic);
            if (*(int *)(c + 0x8) != 2) {
                *(int *)(c + 0x8) = 2;
                *(int *)(c + 0xC0) = *(int *)(c + 0x128);
            }
            *(int *)(c + 0x834) = 1;
        }
    }
}
