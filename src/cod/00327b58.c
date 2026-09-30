/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

extern int D_003D04B8;
extern int D_003D04B4;
extern char D_003D04D0[];
extern void func_00327A50(char *e, int a0, int a1, int a2, int a3);

__attribute__((section(".text.func_00327B58")))
int func_00327B58(int a0, int a1, int a2, int a3) {
    int i;
    char *e = 0;
    for (i = 0; i < D_003D04B8; i++) {
        e = &D_003D04D0[(D_003D04B4 + i) * 0x60];
        if (e[0] == 0) break;
    }
    if (i == D_003D04B8) return 0;
    func_00327A50(e, a0, a1, a2, a3);
    e[3] = 1;
    return (int)e;
}
