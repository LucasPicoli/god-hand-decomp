/* cygnus-2.96 matched TU. */

extern int Obj0000_Get_D_003F1FF0_36CCA8(void);

/* MATCH via cygnus-2.96. */



__attribute__((section(".text.func_0036C8D0")))
int func_0036C8D0(int *a0)
{
    int v0 = Obj0000_Get_D_003F1FF0_36CCA8();
    if (v0 != 0) {
        v0 = a0[0xED];
        if (v0 != 0)
            return func_0036CF08(v0);
    }
    return v0;
}

/* MATCH via cygnus-2.96. */
__attribute__((section(".text.func_0036CBC0")))
void func_0036CBC0(int *a0, int a1, int a2)
{
    int *p = a0 + 2;
    void (*fn)(int, int, int, int) = (void (*)(int, int, int, int))a0[6];
    int x = p[0], y = p[1], z = p[2];
    if (fn != 0)
        fn(x, y, z, a2);
    a0[1] = 0;
}
