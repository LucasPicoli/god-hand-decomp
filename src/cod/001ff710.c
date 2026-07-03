/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_001FF710")))
int func_001FF710(void *a0, int a1) {
    int a3 = 0;
    int t0 = 0;
    int a2 = 0;
    a0 = (char *)a0 + 0x4C;
    do {
        int v1 = *(int *)a0;
        if (v1 == a1) {
            *(int *)a0 = 0xFFFF;
            t0 = 1;
        } else {
            v1 = v1 ^ 0xFFFF;
            if (v1 == 0) a3 = a3 + 1;
        }
        a2++;
        a0 = (char *)a0 + 4;
    } while ((unsigned int)a2 < 4);
    if (a3 == 3) {
        if (t0 != 0) goto ret1;
        goto ret0;
    }
    goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}
