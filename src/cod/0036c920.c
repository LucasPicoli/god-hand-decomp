/* cygnus-2.96 matched TU. */

__attribute__((section(".text.UTY_MulDiv")))
int UTY_MulDiv(int a, int b, int c) {
    if (c == 0)
        return ((a ^ b) < 0) ? (int)0x80000000 : 0x7FFFFFFF;
    return (int)((long long)a * b / c);
}
