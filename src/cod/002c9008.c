/* ee-2.9-991111 matched TU. */

/* compiler: ee-2.9-991111 ; extra keys: none */
__attribute__((section(".text.func_002C9008")))
void *func_002C9008(char *a0, int i) {
    char *base;
    char *e;
    int m;
    unsigned int n;
    base = *(char **)a0;
    if (base == 0) return 0;
    m = *(int *)(a0 + 0x10);
    if (m == 0) return 0;
    if (m < i) return 0;
    n = *(unsigned int *)(a0 + 0xC);
    if (n == 0) return 0;
    if ((unsigned int)i < n) {
        e = a0 + i;
        return base + e[0x14] * 0x24;
    }
    return 0;
}
