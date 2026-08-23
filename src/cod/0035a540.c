/* cygnus-2.96 matched TU. */

/* compiler: cygnus-2.96 ; extra keys: c_flags_drop -freorder-blocks (--drop-freorder-blocks) */
__attribute__((section(".text.func_0035A540")))
void func_0035A540(char *o, int t) {
    int prev;
    int d;
    int lo;
    int hi;
    int avg;
    int q;

    prev = *(int *)(o + 0x294);
    if (prev == -5) {
        *(int *)(o + 0x294) = t;
        return;
    }
    d = t - prev;
    if (d == 0) {
        return;
    }
    lo = *(int *)(o + 0x29C);
    hi = *(int *)(o + 0x2A0);
    avg = *(int *)(o + 0x298);
    if (!(d < lo)) {
        lo = d;
    }
    if (!(hi < d)) {
        hi = d;
    }
    *(int *)(o + 0x294) = t;
    *(int *)(o + 0x29C) = lo;
    *(int *)(o + 0x2A0) = hi;
    if (avg == 0x7FFFFFFF) {
        *(int *)(o + 0x298) = d;
        return;
    }
    if (!(d < avg)) {
        *(int *)(o + 0x298) = d;
        return;
    }
    q = (avg - d) / 8;
    if (q != 0) {
        *(int *)(o + 0x298) = avg - q;
        return;
    }
    *(int *)(o + 0x298) = d;
}
