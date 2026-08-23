/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_0035A298")))
void func_0035A298(int *p, int a) {
    p[0] = 0;
    do { } while (0);
    p[2] = a;
    do { } while (0);
    p[1] = 0;
}

__attribute__((section(".text.func_0038C068")))
unsigned long func_0038C068(unsigned long *p, unsigned long f) {
    unsigned long old = p[2];
    p[2] = old | f;
    return old;
}

__attribute__((section(".text.func_0038C030")))
unsigned long func_0038C030(unsigned long *p, unsigned long m) {
    unsigned long old = p[2];
    p[2] = old & ~m;
    return old;
}
