/* sn-2.95.3-136 matched TU. */

extern char D_0044BAB0[];
extern int D_00747A88;
extern char D_003C26C0[];

__attribute__((section(".text.func_002919C0")))
int func_002919C0(char *self, int unused, int key) {
    char *node = *(char **)(self + 0x500);
    int count = 0;

    while (node != 0) {
        char *q = *(char **)(node + 0x8);
        if (q != 0) {
            if (*(int *)(q + 0x564) == key) {
                count = count + 1;
            }
        }
        node = *(char **)(node + 0x4);
    }
    return count;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_00291FE8")))
void func_00291FE8(char *p, float *s, int n)
{
    float *d = (float *)(p + 0x520);

    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
    *(int *)(p + 0x530) = n;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_00292F18")))
int func_00292F18(char *p)
{
    if (*(signed char *)(p + 0x539) != 0) {
        return 0;
    }
    *(unsigned char *)(p + 0x539) = 0xF;
    return 1;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_002949C8")))
void func_002949C8(char *p)
{
    if (*(signed char *)(p + 0x53E) != 0) {
        *(unsigned char *)(p + 0x53E) = *(unsigned char *)(p + 0x53E) - 1;
    }
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_00299348")))
void func_00299348(char *p)
{
    *(long *)(p + 0x140C8) = 0;
    *(int *)(p + 0x140A8) = 0;
    *(int *)(p + 0x140AC) = 0;
    *(int *)(p + 0x140B0) = 0;
    *(int *)(p + 0x140A4) = 0;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_002A4C00")))
unsigned char func_002A4C00(char *p, unsigned short i)
{
    char *q = p + (i >> 12) * 16;
    char *r = (char *)((i & 0xFFF) * 4 + *(int *)(q + 0x4));

    return *(unsigned char *)(r + 0x8);
}

__attribute__((section(".text.func_002A4FA0")))
void func_002A4FA0(char *base) {
    char *p = base + 0x28000;
    int v;

    *(int *)(p + 0x205C) = 5;
    v = (*(int *)(p + 0x2054) + 0xF) & 0xFFFFFFF0;
    *(int *)(p + 0x2054) = v;
    *(int *)(p + 0x2050) = v;
}

__attribute__((section(".text.func_002A94F0")))
void func_002A94F0(char *self) {
    *(int *)(*(char **)self + 0x8) = 0;
    *(int *)(*(char **)self + 0x4) = 0;
    *(int *)(*(char **)self + 0x10) = 0x20;
    *(int *)(*(char **)self + 0xC) = *(int *)(self + 0x4) - 0x20;
    *(char **)(*(char **)self + 0x0) = self;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_002A9620")))
void func_002A9620(int a, char *n, char *h)
{
    *(char **)(n + 0x8) = *(char **)(h + 0x8);
    *(int *)(n + 0x0) = a;
    *(char **)(n + 0x4) = h;
    if (*(char **)(h + 0x8) != 0) {
        *(char **)(*(char **)(h + 0x8) + 0x4) = n;
    }
    *(char **)(h + 0x8) = n;
}

__attribute__((section(".text.func_002A9860")))
int func_002A9860(int a0,int a1){if(a1!=0){int b=*(int*)(a0+4);int v=*(int*)(a1+b+4);if(v==0)return 0;return v-b;}{int t=*(int*)(a0+0x14);if(t==0)return 0;return t-*(int*)(a0+4);}}

__attribute__((section(".text.func_002B2400")))
void func_002B2400(char *p) {
    unsigned char s = *(unsigned char *)(p + 0xC);

    *(int *)(p + 0x14) |= 0x40;
    if ((unsigned int)(s - 6) < 2) {
        return;
    }
    /* SWEEP-BEGIN */
    *(unsigned char *)(p + 0xF) = 0;
    *(unsigned char *)(p + 0xD) = 0;
    *(unsigned char *)(p + 0xE) = 0;
    *(unsigned char *)(p + 0xC) = 6;
/* SWEEP-END */
}

__attribute__((section(".text.func_002B3BE0")))
int func_002B3BE0(char *p) {
    int f = *(int *)(p + 0x14) | 0x800;
    int g;

    *(int *)(p + 0x14) = f;
    if ((f & 0x100) != 0) {
        g = f & ~0x800;
        g = g & ~0x100;
        *(int *)(p + 0x14) = g;
        return 0;
    }
    return 1;
}

__attribute__((section(".text.func_002BA178")))
char *func_002BA178(char *p, int sz, int flag) {
    *(int *)(p + 0x8) = (sz + 0xF) & 0xFFFFFFF0U;
    *(char **)(p + 0x18) = D_0044BAB0;
    *(char *)(p + 0xC) = flag;
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x10) = 0;
    return p;
}

/* sn-2.95.3-136 */


__attribute__((section(".text.func_002BF518")))
void func_002BF518(char *p)
{
    if (D_00747A88 >= 0) {
        *(unsigned char *)(p + 0x0) = 5;
        *(unsigned char *)(p + 0x1) = 0;
        *(unsigned char *)(p + 0x2) = 0;
        *(unsigned char *)(p + 0x3) = 0;
    }
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_002BF540")))
void func_002BF540(char *p)
{
    if (*(signed char *)(p + 0x1) == 0) {
        *(unsigned char *)(p + 0x0) = 5;
        *(unsigned char *)(p + 0x1) = 0;
        *(unsigned char *)(p + 0x2) = 0;
        *(unsigned char *)(p + 0x3) = 0;
    }
}

__attribute__((section(".text.func_002C3190")))
int func_002C3190(char *p, unsigned char bit) {
    int *m = *(int **)(p + 0x68);
    int r = 1;

    if (m != 0) {
        if ((m[bit >> 5] & (0x80000000U >> (bit & 0x1F))) != 0) {
            r = 0;
        }
    }
    return r;
}

__attribute__((section(".text.func_002C5028")))
void *func_002C5028(int a0,unsigned short k){unsigned short *p=(unsigned short*)D_003C26C0;while(*p!=0xFFFF){if(*p==k)return p;p=(unsigned short*)((char*)p+0x14);}return 0;}
