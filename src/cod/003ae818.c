/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_003AE818")))
void *func_003AE818(void *a0, int a1)
{
    void *s0;
    int s1;
    void *v1;
    void *v0;
    void **a0p;

    s0 = a0;
    s1 = a1;
    v0 = *(void **)((char *)s0 + 0x4C);
    if (v0 == 0) {
        v0 = func_003AF7B8(s0, 4, 16);
        *(void **)((char *)s0 + 0x4C) = v0;
        if (v0 == 0) {
            return 0;
        }
    }
    v1 = *(void **)((char *)s0 + 0x4C);
    a0p = (void **)((int)(s1 << 2) + (int)v1);
    v1 = *a0p;
    if (v1 != 0) {
        *a0p = *(void **)v1;
    } else {
        int sz = 1 << s1;
        v1 = func_003AF7B8(s0, 1, sz * 4 + 0x14);
        if (v1 == 0) {
            return 0;
        }
        ((int *)v1)[1] = s1;
        ((int *)v1)[2] = sz;
    }
    ((int *)v1)[4] = 0;
    ((int *)v1)[3] = 0;
    return v1;
}
