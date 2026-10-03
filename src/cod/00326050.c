/* cygnus-2.96 matched TU. */

/* printf-style logger: unless logging is off, format the variadic args into a stack buffer and print it. */
extern void func_003A7AE8(void *a0, void *a1, void *a2);
extern void func_003B1F28();
extern int D_003CF9E0;

__attribute__((section(".text.func_00326050")))
void func_00326050(void *a0, ...)
{
    char buf[0x80];
    if (D_003CF9E0 == 0) {
        func_003A7AE8(buf, a0, (char *)__builtin_next_arg(a0) - 0x38);
        func_003B1F28(buf);
    }
}
