/* cygnus-2.96 matched TU. */

/* printf-style error report: format into the 0x80-byte message buffer, then hand it to the error callback if one is set. */
struct cb_0033b790 { int (*fn)(int, char *); int arg; };
extern struct cb_0033b790 D_007588B0;
extern char D_003E9990[];
extern void func_003A52F0(void *buf, int a1, int a2);
extern void func_003A7AE8(void *buf, void *s, void *args);

__attribute__((section(".text.func_0033B6E8")))
void func_0033B6E8(void *a0, ...) {
    func_003A52F0(D_003E9990, 0, 0x80);
    func_003A7AE8(D_003E9990, a0, (char *)__builtin_next_arg(a0) - 0x38);
    if (D_007588B0.fn != 0)
        D_007588B0.fn(D_007588B0.arg, D_003E9990);
}
