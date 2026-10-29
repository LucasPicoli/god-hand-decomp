extern void func_002E0B78(
    int, int, int, int, int, int, int, char *, void *);

__attribute__((section(".text.printf_2E0D60")))
void printf_2E0D60(
    int a, int b, int c, int d, int e, int f, char *format, ...)
{
    func_002E0B78(
        a, b, c, d, e, f, 0, format,
        (char *)__builtin_next_arg(format) - 8);
}
