/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_0035CAC8")))
int func_0035CAC8(char *a0) {
    int n = *(int *)(a0 + 0x10);
    int sum = 0;
    if (n > 0) {
        int *p = (int *)(a0 + 0x18);
        int i = n;
        do {
            sum += *p++;
        } while (--i);
    }
    return sum / n;
}
