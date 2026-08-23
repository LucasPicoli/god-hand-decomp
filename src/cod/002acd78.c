/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002ACD78")))
void *func_002ACD78(char *a0, int idx, unsigned int n) {
    char *p;
    int off;
    int sc;
    if (idx == 0x21) return 0;
    if (n == 0) return 0;
    sc = idx * 8;
    p = *(char **)(a0 + sc);
    if (p == 0) return 0;
    if (*(unsigned int *)p < n) return 0;
    off = *(int *)(p + n * 4);
    return off ? (void *)(off + (int)p) : 0;
}

__attribute__((section(".text.func_002BDD90")))
int func_002BDD90(char *a0) {
    unsigned char *q = *(unsigned char **)(a0 + 4);
    int r = 0;
    int n;
    n = q[0];
    if (n) {
        char *t = *(char **)(a0 + 8);
        n--;
        r = *(unsigned short *)(t + n * 4 + 2);
    }
    do { n = q[1]; } while (0);
    if (n) {
        char *t;
        int x;
        n--;
        t = *(char **)(a0 + 0xC);
        x = *(unsigned short *)(t + n * 4 + 2);
        if (r < x) r = x;
    }
    return r;
}
