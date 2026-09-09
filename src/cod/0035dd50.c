/* cygnus-2.96 matched TU. */

extern char D_00459C48[];



__attribute__((section(".text.getToolVer")))
int getToolVer(char *str, int *maj, int *min)
{
    char *p;

    p = func_003A93F8(str, D_00459C48);
    if (p == 0) return 0;
    func_0035DDB0(func_0035DDB0(p + 4, maj) + 1, min);
    return 1;
}
