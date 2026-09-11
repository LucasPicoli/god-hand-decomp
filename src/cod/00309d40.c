/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libhip 3.0.2, tim2.o :: getLog2 (static) */

__attribute__((section(".text.func_00309D40")))
int func_00309D40(int n)
{
    int i;

    i = 31;
    if (n >= 0) {
        while (--i > 0) {
            if ((n >> i) & 1)
                break;
        }
    }
    return i + ((1 << i) < n);
}
