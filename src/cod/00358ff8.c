/* cygnus-2.96 matched TU. */

extern long long SFTMR_GetTmrUnit(void);
extern long long func_0031DE10(long long, long long);

/* cygnus-2.96 matched TU. */




__attribute__((section(".text.SFPLY_MeasureFps")))
void SFPLY_MeasureFps(void *a0) {
    char *s0 = (char *)a0;
    long long b, delta;
    int n;

    *(long long *)(s0 + 0x3788) = func_0035BA58();
    b = SFTMR_GetTmrUnit();
    n = *(int *)(s0 + 0x968);
    *(int *)(s0 + 0x3798) = n;
    delta = *(long long *)(s0 + 0x3788) - *(long long *)(s0 + 0x3780);
    *(long long *)(s0 + 0x3790) = b;
    if (delta != 0) {
        *(float *)(s0 + 0x379C) = (float)func_0031DE10(*(int *)(s0 + 0x968), b) / (float)delta;
    }
}
