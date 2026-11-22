/* cygnus-2.96 matched TU. */

extern void MEM_Copy(int a0, int a1, int a2);

__attribute__((section(".text.sfmps_SetMpsRaw")))
void sfmps_SetMpsRaw(int a0, int a1, int a2, int a3) {
    int buf[8];
    char *s0;
    char *p;
    char *q;
    int n;

    s0 = (char *)sfmps_GetHd(a0);
    if (s0 == 0) {
        return;
    }
    if (*(int *)s0 != 0) {
        return;
    }
    MPS_GetLastSysHd(a1, (int)buf);
    n = (a3 < 0xB1) ? a3 : 0xB0;
    p = s0 + 0x30;
    if (buf[3] > 0) {
        *(int *)(p + 0x160) = n;
        q = p;
    } else if (buf[2] > 0) {
        *(int *)(p + 0x164) = n;
        q = s0 + 0xE0;
    } else {
        return;
    }
    MEM_Copy((int)q, a2, n);
}
