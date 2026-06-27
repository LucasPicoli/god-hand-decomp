/* cygnus-2.96 matched TU. */

extern void func_0034CE80(void *a0, int x, int y);
extern int D_004551E8;
extern void func_00336330(void *, void *);

__attribute__((section(".text.func_00349DA0")))
void func_00349DA0(char *a0) {
    int *region; int id; int x; int y;
    region = (int *)(a0 + 0xD30);
    id = **(int **)(a0 + 0x2004);
    if (region[0x7D] != region[0x7E]) return;
    x = func_0032A4A8(id);
    y = func_0032A530(id);
    if (x <= 0) return;
    if (y <= 0) return;
    func_0034CE80(a0, x, y);
}

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
} P;




__attribute__((section(".text.func_00336A40")))
void func_00336A40(P *p, int n) {
    int a, u, t;
    if (p == 0) {
        func_00336330(p, &D_004551E8);
        return;
    }
    a = p->f8;
    u = p->f10;
    t = p->f4;
    p->f4 = n;
    p->fC = (a + n - 1) / n;
    p->f10 = (u * t) / n;
    p->f14 = p->f18 * n;
}

__attribute__((section(".text.func_003593F0")))
int func_003593F0(char *base, int idx, long long *pval, int *out) {
    int *entry;
    *out = 0;
    if (*pval < 0) return 0;
    entry = (int *)(base + idx * 116 + 0x1348);
    if (*entry == 0) return 0;
    if (func_00359480(entry, pval, out) == -1) {
        return func_0034DD70(base, 0xFF000421);
    }
    return 0;
}

__attribute__((section(".text.func_0034F718")))
int func_0034F718(void *a0) {
    int s0, r;
    r = func_0034F7A0(a0);
    if (r == 1) return r;
    s0 = *(int *)((char *)a0 + 0x1F84);
    r = func_0034CA30(a0, s0);
    if (r != 1) return r;
    r = func_0034F8D0(a0, s0);
    if (r == 0) return r;
    return func_0034F830(a0, 1);
}
