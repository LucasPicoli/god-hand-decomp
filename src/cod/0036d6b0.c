/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_0036D6B0")))
void func_0036D6B0(int *d, int *s, unsigned int n)
{
    unsigned int r = n & 0xF;
    int a, b, c, e;

    if (r != 0) {
        do {
            *d++ = *s++;
        } while (--r);
    }
    n >>= 4;
    if (n == 0) return;
    do {
        a = *s++; b = *s++; c = *s++; e = *s++;
        d[0] = a; d[1] = b; d[2] = c; d[3] = e;
        a = *s++; b = *s++; c = *s++; e = *s++;
        d[4] = a; d[5] = b; d[6] = c; d[7] = e;
        a = *s++; b = *s++; c = *s++; e = *s++;
        d[8] = a; d[9] = b; d[10] = c; d[11] = e;
        a = *s++; b = *s++; c = *s++; e = *s++;
        d[12] = a; d[13] = b; d[14] = c; d[15] = e;
        d += 16;
    } while (--n);
}
