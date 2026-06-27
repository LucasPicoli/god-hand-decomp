/* ee-2.9-991111 matched TU. */

__attribute__((section(".text.func_003209D0")))
int func_003209D0(int a0, int a1, int a2)
{
    int s2 = func_00320948(a0, a1, 0);
    int r2 = func_00320948(a0, a2, 0);
    int n = (a0 < 0x1F) ? 0x10 : ((a0 <= 0x3F) ? 4 : 8);
    return func_003A5148(r2, s2, n);
}
