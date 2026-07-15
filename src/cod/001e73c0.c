/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_Main(void *a0);
extern void cIDBase_move(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001E73C0")))
void func_001E73C0(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    q = p + 0x580;
    for (i = 1; i >= 0; i--) {
        CustomIDWork_Main(q);
        q += 0x7C;
    }

    cIDBase_move(p + 0x530);

    q = p + 0x50;
    for (i = 9; i >= 0; i--) {
        CustomIDWork_Main(q);
        q += 0x7C;
    }

    cIDBase_move(p);
}
