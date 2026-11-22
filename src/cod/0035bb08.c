/* cygnus-2.96 */

extern long long D_00766C80;
extern int func_0035BA58(void);

__attribute__((section(".text.SFTMR_GetTmrUnit")))
long long SFTMR_GetTmrUnit(void)
{
    if (D_00766C80 == 0)
        func_0035BA58();
    return D_00766C80;
}
