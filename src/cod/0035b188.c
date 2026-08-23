/* cygnus-2.96 matched TU. */

/* compiler: cygnus-2.96 ; extra keys: none */
__attribute__((section(".text.func_0035B188")))
void func_0035B188(int a0, char *a1, int *a2, int *a3) {
    int h;
    int m;
    int s;
    int t;
    int f;
    int acc;
    int r;
    h = *(int *)(a1 + 0x8) * a0;
    m = *(int *)(a1 + 0xC) * a0;
    s = *(int *)(a1 + 0x14) + *(int *)(a1 + 0x18);
    t = *(short *)(a1 + 0x1E);
    f = *(int *)(a1 + 0x10) * a0;
    r = f + t * 500;
    acc = h * 3600 + m * 60;
    acc = acc + s * 1000;
    *a2 = r + acc;
    *a3 = a0;
}
