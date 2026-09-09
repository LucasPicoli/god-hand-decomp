/* cygnus-2.96 matched TU. */

extern int D_004598E0;
extern void func_0034DD70(void *p, unsigned int err);

__attribute__((section(".text.sfply_ChkCondDfl")))
void sfply_ChkCondDfl(void)
{
    if (D_004598E0 == 0x5A5A5A5A) return;
    func_0034DD70(0, 0xFF000201);
}

__attribute__((section(".text.sftim_GetTimeNone")))
int sftim_GetTimeNone(void *p, int *tim, int *tunit)
{
    if (func_0035AE18(p) == 0) return 0;
    *tim = -2;
    *tunit = 1;
    return 0;
}
