/* cygnus-2.96 matched TU. */

extern void sfply_TrStart(int a0);

__attribute__((section(".text.func_0034C990")))
int func_0034C990(void *a0, int a1, int a2, int a3) {
    char *base = (char *)a0 + 0x1310;
    int *t1 = (int *)(base + a1 * 0x74);
    int r = 0;
    if (t1[1] == 0)
        r = func_0035C2D0(a0, t1[0x13], 0xC, a2, a3);
    *(int *)((char *)a0 + 0x44) = 1;
    return r;
}

__attribute__((section(".text.func_00357870")))
int func_00357870(int o) {
    int r = *(int*)(o + 0x48);
    switch (*(int*)(o + 0x4C)) {
    case 2: r = 2; break;
    case 3: r = 3; break;
    case 4:
    case 6:
        if (func_00357988(o)) {
            sfply_TrStart(o);
            r = 4;
        }
        break;
    }
    return r;
}
