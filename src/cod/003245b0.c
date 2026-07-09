/* cygnus-2.96 matched TU. */

extern void Forward33E6A8_324880(void);
extern int Forward33E6B0_324898(void);
extern void func_00348950(void *a0, int a1);
extern void Forward345EE0_345EC8(int a0);
extern int D_003EC668;

/* MATCH via cygnus-2.96. */




__attribute__((section(".text.func_003245B0")))
int func_003245B0(int a0, int a1, int a2, int a3, int t0, int t1)
{
    int local[4];
    int r;
    Forward33E6A8_324880();
    r = func_00324640(a0, a1, a2, a3, t0, t1, local);
    Forward33E6B0_324898();
    return r;
}

/* MATCH via cygnus-2.96. */





__attribute__((section(".text.func_003428A0")))
int func_003428A0(int a0, int a1, int a2, int a3)
{
    func_00348950(&D_003EC668, 0);
    Forward345EE0_345EC8(a0);
    return func_00348670(a0, 0, a1, a2, a3);
}
