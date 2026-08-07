/* cygnus-2.96 matched TU. */

extern int SFXLIB_Error(void *a0, void *a1, char *msg);
extern char D_00459CA0[];

/* cygnus-2.96 matched TU (compiled with -freorder-blocks dropped). */












__attribute__((section(".text.func_0035EBB0")))
int func_0035EBB0(void *a0, void *a1, int a2)
{
    int r;

    r = func_0035ED08(a0, a2);
    if (r != 1) {
        return r;
    }
    *(int *)((char *)a0 + 0x34) = a2;
    switch (a2) {
    case 11:
    case 13:
        return func_0035EDA8(a0, a1);
    case 2:
        return func_0035EE98(a0, a1);
    case 4:
        return func_0035EEB8(a0, a1);
    case 5:
        return func_0035EED8(a0, a1);
    case 21:
        return func_0035EEF8(a0, a1);
    case 1:
        return func_0035EDC8(a0, a1);
    case 0:
    case 3:
    case 6:
    case 7:
    case 100:
    default:
        return SFXLIB_Error(a0, a1, D_00459CA0);
    }
}
