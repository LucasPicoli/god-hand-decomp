/* cygnus-2.96 matched TU. */

extern int D_003EEA6C;

__attribute__((section(".text.func_0036CC80")))
void func_0036CC80(int *p, int a, int b, int c) {
    int *q = p + 2;
    int one = 1;
    q[2] = b;
    do { } while (0);
    q[0] = c;
    do { } while (0);
    q[1] = a;
    do { } while (0);
    p[1] = one;
}

__attribute__((section(".text.setf__3iosUlUl")))
unsigned long setf__3iosUlUl(unsigned long *p, unsigned long f, unsigned long m) {
    unsigned long old = p[2];
    p[2] = (old & ~m) | (f & m);
    return old;
}

__attribute__((section(".text.func_003607A0")))
void func_003607A0(void) {
    if (D_003EEA6C > 0) {
        D_003EEA6C = D_003EEA6C - 1;
    }
}

__attribute__((section(".text.func_003897A8")))
void *func_003897A8(unsigned long *p) {
    p[2] = (p[2] & ~0x70) | 0x20;
    return p;
}

__attribute__((section(".text.func_003897C8")))
void *func_003897C8(unsigned long *p) {
    p[2] = (p[2] & ~0x70) | 0x40;
    return p;
}

__attribute__((section(".text.func_003897E8")))
void *func_003897E8(unsigned long *p) {
    p[2] = (p[2] & ~0x70) | 0x10;
    return p;
}
