/* cygnus-2.96 matched TU. */

extern void func_003446D0(void *a0, void *a1);
extern void mwsfcre_UsrFree(void *a0);

/* MATCH via cygnus-2.96 +drop-freorder. */




__attribute__((section(".text.func_00344680")))
int func_00344680(int *a0, void *a1)
{
    if (a0[0x7B] != 0) {
        func_003446D0(a0, a1);
    } else {
        mwsfcre_UsrFree(a1);
    }
    return func_00344780(a0);
}
