/* ee-2.9-991111 matched TU. */

extern void func_003B63F0(void);
extern int func_003B1E40();
extern void _sceSnprintf();

__attribute__((section(".text.func_003B1F28")))
void func_003B1F28(char *fmt, ...) {
    int ctx;
    void *h;
    ctx = 0;
    h = func_003B63A0();
    _sceSnprintf(func_003B1E40, &ctx, 0xFFFFFFFFU, fmt, (char *)__builtin_next_arg(fmt) - 0x38);
    if (h) {
        func_003B63F0();
    }
}
