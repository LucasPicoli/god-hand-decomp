/* ee-2.9-991111 matched TU. */

extern int _sceSnprintf(void *cb, void *state, int a, int b, void *ap);
extern int func_003B1DE8();

typedef void *va_list;
#define va_start(ap, last) (ap = (void *)((char *)__builtin_next_arg(last) - 0x28))
#define va_end(ap)




__attribute__((section(".text.func_003B1EE0")))
int func_003B1EE0(int a0, int a1, int a2, ...) {
    int state;
    va_list ap;
    state = a0;
    va_start(ap, a2);
    return _sceSnprintf((void *)func_003B1DE8, &state, a1, a2, ap);
}
