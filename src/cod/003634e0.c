/* cygnus-2.96 matched TU. */

extern int Obj0000_Get_D_003EEA98_365EB0(void);

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.func_003634E0")))
int func_003634E0(int a0, int a1, int *a2)
{
    int v0 = *a2;
    if (v0 == 0)
        v0 = Obj0000_Get_D_003EEA98_365EB0();
    return func_00363528(a0, a1, v0);
}
