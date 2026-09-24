/* sn-2.95.3-136 matched TU. */

extern unsigned char D_007474A0[];
extern int D_007559A8[];
extern char D_00450EF0[];
extern char D_00450EF8[];
extern char D_00450F00[];
extern char D_00450F08[];
extern int SearchData(int a0, void *a1, int a2);
extern void func_0031D658(int a0, int a1);
extern char D_0061B7C0[];
extern char D_0071B7C0[];
extern char D_0071B840[];
extern char D_0071B8C0[];
extern void func_003A52F0(void *a0, int a1, int a2);
extern int D_00741940[];
extern int D_00741960[];
extern int D_00741980[];
extern unsigned char D_0071B940[];
extern void func_00302918(void *p);

typedef struct { int a; int b; } Pair;

extern Pair D_007558A8[];








__attribute__((section(".text.func_0031D1B0")))
void func_0031D1B0(void)
{
    int n;
    int i;
    int base;
    int r;
    int flag;
    unsigned char *w;

    D_007474A0[0x600] = 0;
    for (n = 32; n != 0; n--) {
        D_007558A8[n - 1].a = 0;
        D_007558A8[n - 1].b = 0;
        D_007559A8[n - 1] = 0;
    }
    w = D_007474A0;
    base = SearchData(*(int *)(w + 0x5AC), D_00450EF0, 0);
    flag = 1;
    r = SearchData(base, D_00450EF8, 0);
    *(int *)(w + 0x5FC) = r;
    if (r == 0) {
        *(int *)(w + 0x5FC) = SearchData(base, D_00450F00, 0);
        flag = 0;
    }
    i = 0;
loop:
    r = SearchData(base, D_00450F08, i);
    if (r == 0)
        return;
    func_0031D658(r, flag);
    i++;
    goto loop;
}

__attribute__((section(".text.func_002FAB88")))
void *func_002FAB88(int a0)
{
    int i;
    unsigned int w;
    unsigned int bit;
    void *r;

    for (i = 0x3FF; i >= 0; i--) {
        w = ((unsigned int)i >> 5) * 4;
        bit = 0x80000000 >> (i & 0x1F);
        if ((*(unsigned int *)(w + (int)D_0071B7C0) & bit) == 0) {
            func_003A52F0(D_0061B7C0 + i * 0x400, 0, 0x400);
            r = func_002FACA8(i, a0);
            if (r != 0) {
                *(unsigned int *)(w + (int)D_0071B7C0) |= bit;
                *(unsigned int *)(w + (int)D_0071B840) &= ~bit;
                *(unsigned int *)(w + (int)D_0071B8C0) &= ~bit;
                return r;
            }
        }
    }
    return 0;
}

__attribute__((section(".text.func_00300AE8")))
void func_00300AE8(int a0, int a1)
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
        if (a1 == 0) {
            if (*(short *)(p + 0x18C) == a0) goto call;
        }
        if (a1 != 1) goto next;
        if (*(short *)(p + 0x18C) == a0) goto next;
call:
        func_00302918(p);
next: ;
    }
}
