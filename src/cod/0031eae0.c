/* ee-2.9-991111 matched TU. */

extern void func_0031DFA8(void *a0, void *a1);
extern float func_0031EDA0(int class, unsigned int sign, int exp, unsigned int frac);
extern void WaitDma(void *);

struct fp32 { int a; int b; int c; int d; long long e; long long f; };

__attribute__((section(".text.func_0031EAE0")))
float func_0031EAE0(double a0)
{
    struct fp32 buf;
    long long frac;
    unsigned int sffrac;
    func_0031DFA8(&a0, &buf);
    frac = buf.e;
    sffrac = (unsigned int)(frac >> 30);
    if (frac & 0x3FFFFFFF)
        sffrac |= 1;
    return func_0031EDA0(buf.a, buf.b, buf.c, sffrac);
}

__attribute__((section(".text.func_00397450")))
void func_00397450(void *a0, int a1, void *a2)
{
    void *s0;
    int s1;
    void *s2;
    int v0;
    int v1;

    s0 = a0;
    s2 = a2;
    s1 = func_003970A0(a1);
    WaitDma(s0);
    v1 = *(int *)((char *)s0 + 0x10);
    if ((unsigned int)v1 != 0xFFFFFFFFu)
        *(int *)((char *)s0 + 0x10) = s1;
    *(void **)((char *)s0 + 0x20) = s2;
    v0 = *(int *)s0;
    v0 = v0 & -13;
    v0 = v0 | 0x101;
    *(int *)s0 = v0;
}
