/* cygnus-2.96 matched TU. */

extern char D_0045A230[];
extern char D_0045A218[];

__attribute__((section(".text.SUD_AnalyTypeCcs")))
int SUD_AnalyTypeCcs(char *p, int n)
{
    if ((p == 0) || (n < 0)) return 0;
    return func_003A5BD8(p + 0x13, D_0045A230, 1) == 0;
}

__attribute__((section(".text.SUD_AnalyTypeDivField")))
int SUD_AnalyTypeDivField(char *p, int n)
{
    if ((p == 0) || (n < 0)) return 0;
    return func_003A5BD8(p + 0x12, D_0045A218, 1) == 0;
}
