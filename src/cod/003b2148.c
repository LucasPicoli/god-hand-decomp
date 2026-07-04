/* ee-2.9-991111 matched TU. */

extern int D_003FAE50;
extern void func_003B63F0();
extern int SifSetDma(int, int);

__attribute__((section(".text.func_003B2148")))
int func_003B2148(int a, int b) {
    int res = func_003B63A0(a, b);
    if (D_003FAE50 != 0) {
        if (res != 0) {
            func_003B63F0();
        }
        return func_003B2080(a, b, 0);
    }
    if (res != 0) {
        func_003B63F0();
    }
    return SifSetDma(a, b);
}
