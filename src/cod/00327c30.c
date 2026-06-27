/* cygnus-2.96 matched TU. */

extern int D_003D04C0;
extern int D_003D04BC;
extern char D_003D04D0[];
extern void SFTIM_Tc2Time(int, int *, int *);

__attribute__((section(".text.func_00327C30")))
int func_00327C30(int a0, int a1, int a2, int a3) {
    int i;
    char *e = 0;
    for (i = 0; i < D_003D04C0; i++) {
        e = &D_003D04D0[(D_003D04BC + i) * 0x60];
        if (e[0] == 0) break;
    }
    if (i == D_003D04C0) return 0;
    func_00327A50(e, a0, a1, a2, a3);
    e[3] = 0;
    return (int)e;
}

struct blk44 { int w[11]; };

__attribute__((section(".text.func_00352520")))
void func_00352520(int a0, int a1)
{
    int tmp[2];
    int *s1 = (int *)a1;
    int *s0 = (int *)(a0 + 0xD30);
    int diff, t1v;

    SFTIM_Tc2Time(a1 + 0x10, &tmp[0], &tmp[1]);
    diff = tmp[0] - s0[0x18];
    t1v = tmp[1];
    s1[3] = 1;
    s1[12] = diff;
    s1[13] = t1v;
    if (diff >= s0[0x23]) {
        *(struct blk44 *)(a0 + 0xD98) = *(struct blk44 *)(a1 + 0xC);
    }
}
