/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_001D4670")))
void func_001D4670(void *arg) {
    char *base = (char *)arg;
    char *q;
    char *e;
    int *a;
    int *b;
    register int v;
    int i;
    int j;
    int k;

    i = 0x33;
    q = base + 0x1638;
    for (; i >= 0; i--) {
        v = 3;
        *(int *)(q + 0) = v;
        *(int *)(*(char **)(*(char **)(q - 4) + 0xF0) + 0x0) = 0;
        *(int *)(*(char **)(*(char **)(q - 4) + 0xF0) + 0x4) = 0;
        *(int *)(*(char **)(*(char **)(q - 4) + 0xF0) + 0x8) = 0;
        *(int *)(*(char **)(q - 4) + 0x104) = 0;
        e = *(char **)(q - 4);
        v = *(int *)(e + 0x250);
        *(int *)(e + 0x250) = v | 2;
        q += 8;
    }

    a = (int *)(base + 0x17D4);
    b = (int *)(base + 0x17E8);
    for (j = 4; j >= 0; j--) {
        a[j] = 0;
    }
    for (k = 4; k >= 0; k--) {
        b[k] = 0;
    }
}
