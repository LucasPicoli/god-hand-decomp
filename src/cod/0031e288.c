/* ee-2.9-991111 matched TU. */

extern void func_0031DFA8(void *a0, void *a1);

struct s20 { char b[0x20]; };

__attribute__((section(".text.dpadd")))
int dpadd(long long a0, long long a1) {
    struct s20 b00;
    struct s20 b20;
    struct s20 b40;
    func_0031DFA8(&a0, &b00);
    func_0031DFA8(&a1, &b20);
    return func_0031DE78(func_0031E048(&b00, &b20, &b40));
}
