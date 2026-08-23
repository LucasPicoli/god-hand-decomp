/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00378020")))
void func_00378020(void *arg) {
    unsigned short *p = (unsigned short *)arg;
    int a = p[0];
    int b = p[1];
    short n = *(short *)(p + 3);
    int d = (short)(b - a);
    int q = d / n;
    *(short *)(p + 2) = (short)q;
    if ((short)q == 0) {
        *(short *)(p + 2) = (d > 0) ? 1 : -1;
    }
    *(short *)(p + 3) = 0;
}
