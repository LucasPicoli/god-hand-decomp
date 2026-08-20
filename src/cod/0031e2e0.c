/* ee-2.9-991111 matched TU. */

extern void func_0031DFA8(double *a0, struct fp *a1);

struct fp { int a; int b; int c; int d; long long e; long long f; };




__attribute__((section(".text.dpsub")))
int dpsub(double a0, double a1) {
    struct fp bufA;
    struct fp bufB;
    struct fp bufC;
    func_0031DFA8(&a0, &bufA);
    func_0031DFA8(&a1, &bufB);
    bufB.b = bufB.b ^ 1;
    return func_0031DE78(func_0031E048(&bufA, &bufB, &bufC));
}
