/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_0015FD18")))
int func_0015FD18(void *a0, int key) {
    int i = 0;
    int *p;
    int off;
    if (key == -1) return 0;
    p = (int *)a0;
    for (; i < 9; i++) {
        off = i * 8;
        if (*p == key) return *(int *)((char *)a0 + off + 4);
        p += 2;
    }
    return 0;
}

__attribute__((section(".text.func_0028ED28")))
void func_0028ED28(void *a0, int d) {
    char *p = (char *)a0;
    *(int *)(p + 0x5B4) += d;
    if (*(int *)(p + 0x5B4) < 0) *(int *)(p + 0x5B4) = 0;
    if (*(int *)(p + 0x5B4) > 100000) *(int *)(p + 0x5B4) = 100000;
    if (d > 0) *(float *)(p + 0x5B8) = 90.0f;
}
