/* cygnus-2.96 matched TU. */

extern int *GetD003EC7E0_3452B0(int a0);
extern void func_0034C8F0(int a0, int a1, int a2);
extern int GetD003EE078_3463F8(void);
extern void (*D_003EE07C)(int, int);
extern void func_0033BA10(int a0, int a1, int a2, int a3, int a4);
extern int D_00760D84;
extern void func_0034D318(struct S *a, struct S *b);
extern int WaitSema(int sema);
extern int SignalSema(int sema);

/* MATCH via cygnus-2.96. */

__attribute__((section(".text.func_00349738")))
void func_00349738(int a0, int a1) {
    int *p = GetD003EC7E0_3452B0(a0);
    if (a0 != 0) {
        *(int *)(a0 + 0x5C) = a1;
    }
    *(int *)((char *)p + 0x24) = a1;
}

/* MATCH via cygnus-2.96. */

__attribute__((section(".text.func_00351B70")))
void func_00351B70(int a0, int a1) {
    func_0034C8F0(a0, *(int *)(a0 + 0x1FC8), a1);
    *(long *)(a0 + 0x9A8) += a1;
}

/* MATCH via cygnus-2.96. */


__attribute__((section(".text.func_00346410")))
void func_00346410(int a0) {
    int v0 = GetD003EE078_3463F8();
    void (*f)(int, int) = D_003EE07C;
    if (f) {
        f(a0, v0);
    }
}

/* MATCH via cygnus-2.96. */


__attribute__((section(".text.func_00348A08")))
void func_00348A08(int a0, int a1, int a2, int a3) {
    func_0033BA10(2, a0, a1, a2, a3);
    D_00760D84 = a0;
}

/* MATCH via cygnus-2.96. */
struct S { int x[549]; };


__attribute__((section(".text.func_0034D2D8")))
void func_0034D2D8(void *a0) {
    struct S *p = (struct S *)func_0034D450(a0);
    if (p != 0) {
        func_0034D318(p, (struct S *)((char *)a0 + 0x78));
    }
}

/* MATCH via cygnus-2.96. */


__attribute__((section(".text.func_003562F8")))
void func_003562F8(int *a0) {
    WaitSema(a0[16]);
    a0[5] = ((a0[5] + 0x803) / 0x800) * 0x800;
    SignalSema(a0[16]);
}
