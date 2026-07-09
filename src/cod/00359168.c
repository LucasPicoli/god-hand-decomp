/* cygnus-2.96 matched TU. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(int *a0);
extern int SetFieldIfUnset_359218(int *a0, int a1);

/* MATCH via cygnus-2.96 +drop-freorder. */





__attribute__((section(".text.func_00359168")))
int func_00359168(int *a0, int a1)
{
    int r;
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0)
        return func_0034DD70(0, 0xFF00013B);
    r = SetFieldIfUnset_359218(a0, 2);
    if (r == 0) {
        a0[0x25B]++;
        return func_0035C2D0((int)a0, 6, 0xC, 0, a1);
    }
    return r;
}
