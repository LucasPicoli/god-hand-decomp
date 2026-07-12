/* cygnus-2.96 matched TU. */

extern void func_0035A518(void *a0);

__attribute__((section(".text.func_0035A4D0")))
void func_0035A4D0(int *a0, int a1)
{
    a0[0] = 0;
    func_0035A518(a0 + 1);
    a0[9] = a1;
    a0[10] = 1;
}

__attribute__((section(".text.func_0035CA08")))
int func_0035CA08(int *a0, int a1)
{
    int *sp = a0 + 5;
    int slot = *sp;
    int r;
    a0[(slot % a0[4]) + 6] = a1;
    *sp = slot + 1;
    r = func_0035CAC8(a0);
    a0[0x1A4 / 4] = r;
    a0[0x1A8 / 4] = r;
    return r;
}
