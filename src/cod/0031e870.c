/* ee-2.9-991111 matched TU. */

extern void func_0031DFA8(void *a0, void *a1);
extern void func_0031E758(void *a0, void *a1);

__attribute__((section(".text.dpcmp")))
void dpcmp(double a0, double a1) {
    char buf0[0x20];
    char buf1[0x20];
    void *s0;

    func_0031DFA8(&a0, (void *)buf0);
    s0 = (void *)buf1;
    func_0031DFA8(&a1, s0);
    func_0031E758((void *)buf0, s0);
}
