/* cygnus-2.96 matched TU. */

extern void func_0035B188(int rate, int a1, int a2, int *out);

__attribute__((section(".text.sftim_Tc2Time23N")))
void sftim_Tc2Time23N(int tc, int a1, int a2, int *out)
{
    func_0035B188(24000, a1, a2, out);
    *out = tc;
}

__attribute__((section(".text.sftim_Tc2Time29N")))
void sftim_Tc2Time29N(int tc, int a1, int a2, int *out)
{
    func_0035B188(30000, a1, a2, out);
    *out = tc;
}

__attribute__((section(".text.sftim_Tc2Time59N")))
void sftim_Tc2Time59N(int tc, int a1, int a2, int *out)
{
    func_0035B188(60000, a1, a2, out);
    *out = tc;
}
