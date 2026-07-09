/* cygnus-2.96 matched TU. */

extern void func_003BA878(int a0, int a1, int *out);
extern void func_003BA8C0(int a0, int a1, int a2);

/* MATCH via cygnus-2.96. */



__attribute__((section(".text.func_003B9CE8")))
void func_003B9CE8(int a0, int a1)
{
    int v;
    func_003BA878(a0, 0, &v);
    func_003BA8C0(a0, a1, v);
}
