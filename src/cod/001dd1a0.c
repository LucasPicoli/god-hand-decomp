/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_Main(void *a0);
extern void cIDBase_move(void *a0);

__attribute__((section(".text.func_001DD1A0")))
void func_001DD1A0(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    q = p + 0x60;
    for (i = 0x4C; i >= 0; i--) {
        CustomIDWork_Main(q);
        q += 0x7C;
    }
    cIDBase_move(p + 0x10);
}
