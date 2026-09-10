/* cygnus-2.96 matched TU. */

extern int MPSLIB_CheckHn(char *h);
extern int MPSLIB_SetErr(int a, int b);
extern void func_00368FB0(void *p, void *fn, void *arg);
extern void *D_003F1A98;

__attribute__((section(".text.MPS_SetErrFn")))
int MPS_SetErrFn(char *h, void *fn, void *arg)
{
    if (h == 0) {
        func_00368FB0(D_003F1A98, fn, arg);
    } else {
        if (MPSLIB_CheckHn(h) != 0) {
            return MPSLIB_SetErr(0, 0xFF020101);
        }
        func_00368FB0(h + 4, fn, arg);
    }
    return 0;
}
