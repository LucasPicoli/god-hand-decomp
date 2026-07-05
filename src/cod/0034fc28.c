/* cygnus-2.96 matched TU. */

extern void func_00366960(int a0, int a1, int a2);

__attribute__((section(".text.func_0034FC28")))
void func_0034FC28(int a0, int a1, int a2, int a3) {
    int buf[8];
    char *s0;
    char *p;
    char *q;
    int n;

    s0 = (char *)func_003500E8(a0);
    if (s0 == 0) {
        return;
    }
    if (*(int *)s0 != 0) {
        return;
    }
    func_00368BC8(a1, (int)buf);
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
    func_00366960((int)q, a2, n);
}
