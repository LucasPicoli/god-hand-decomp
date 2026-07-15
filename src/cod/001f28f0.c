/* sn-2.95.3-136 matched TU. */

extern void func_001F2D60(void *a0);
extern void func_001F3118(void *a0);
extern void func_001F32A0(void *a0);
extern void CustomIDWork_Main(void *a0);
extern void cIDBase_move(void *a0);

__attribute__((section(".text.func_001F28F0")))
void func_001F28F0(void *a0) {
    char *p = (char *)a0;
    char *q;
    char *r;
    int i;
    int j;

    func_001F2D60(p);
    func_001F3118(p);
    func_001F32A0(p);

    q = p + 0x60;
    /* call in body + closes with bgez -> i >= 0 (padded loop) */
    for (i = 0x11; i >= 0; i--) {
        CustomIDWork_Main(q);
        q += 0x7C;
    }

    cIDBase_move(p + 0x10);

    r = p + 0x930;
    q = p + 0x980;
    for (j = 2; j >= 0; j--) {
        CustomIDWork_Main(q);
        q += 0x7C;
    }

    cIDBase_move(r);
}
