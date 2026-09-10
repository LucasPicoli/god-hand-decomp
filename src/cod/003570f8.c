/* cygnus-2.96 matched TU. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(void *h);
extern void func_0035BA48(void *h, int n);
extern void func_0034B6D0(void *h, int n);

__attribute__((section(".text.SFD_SetSpeed")))
int SFD_SetSpeed(void *h, int n)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(h) != 0) {
        return func_0034DD70(0, 0xFF000144);
    }
    func_0035BA48(h, n);
    func_0034B6D0(h, n);
    return 0;
}

__attribute__((section(".text.SFD_Standby")))
int SFD_Standby(void *h)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(h) != 0) {
        return func_0034DD70(0, 0xFF000143);
    }
    return func_00357140(h);
}
