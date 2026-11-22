/* cygnus-2.96 matched TU. */

extern void SFTIM_InitTcode(void *a0);

__attribute__((section(".text.SFTIM_InitTtu")))
void SFTIM_InitTtu(int *a0, int a1)
{
    a0[0] = 0;
    SFTIM_InitTcode(a0 + 1);
    a0[9] = a1;
    a0[10] = 1;
}

__attribute__((section(".text.func_0035CA08")))
int func_0035CA08(int *a0, int a1)
{
    int *sp = a0 + 5;
    int slot = *sp;
    int r;
    a0[(slot % a0[4]) + 6] = a1;
    *sp = slot + 1;
    r = sftst_CalcMovAve(a0);
    a0[0x1A4 / 4] = r;
    a0[0x1A8 / 4] = r;
    return r;
}
