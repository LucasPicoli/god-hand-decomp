/* cygnus-2.96 matched TU. */

extern long long func_0035BB08(void);
extern long long func_0031DE10(long long, long long);

/* cygnus-2.96 matched TU. */




__attribute__((section(".text.func_00358FF8")))
void func_00358FF8(void *a0) {
    char *s0 = (char *)a0;
    long long b, delta;
    int n;

    *(long long *)(s0 + 0x3788) = func_0035BA58();
    b = func_0035BB08();
    n = *(int *)(s0 + 0x968);
    *(int *)(s0 + 0x3798) = n;
    delta = *(long long *)(s0 + 0x3788) - *(long long *)(s0 + 0x3780);
    *(long long *)(s0 + 0x3790) = b;
    if (delta != 0) {
        *(float *)(s0 + 0x379C) = (float)func_0031DE10(*(int *)(s0 + 0x968), b) / (float)delta;
    }
}
