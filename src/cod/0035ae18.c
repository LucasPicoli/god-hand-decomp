/* cygnus-2.96 matched TU. */

__attribute__((section(".text.SFTIM_ChkRegularTime")))
int SFTIM_ChkRegularTime(void *a0, int *a1, int *a2) {
    int v = *(int *)((char *)a0 + 0x48);
    if (v == 4 || v == -4 || v == 6 || v == -6) return 1;
    *a1 = -1;
    *a2 = 1;
    return 0;
}
