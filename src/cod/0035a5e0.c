/* Byte-identical to RE4 PS2 (SLUS-21134) 0x002D2088 — shared engine code.
 * Stepped clamp: base = a0->0x294; returns base+a0->0x298 if a1 is below it,
 * else base+a0->0x29C if a1 is below that, else INT_MAX. The explicit result
 * variable keeps the value in $v1 and moves it to $v0 in the jr delay slot. */

__attribute__((section(".text.SFTIM_GetNextItime")))
int SFTIM_GetNextItime(void *a0, int a1) {
    int base = *(int *)((char *)a0 + 0x294);
    int hi = base + *(int *)((char *)a0 + 0x298);
    int sum = base + *(int *)((char *)a0 + 0x29C);
    int result;
    if (a1 < hi) result = hi;
    else if (a1 < sum) result = sum;
    else result = 0x7FFFFFFF;
    return result;
}
