/* sn-2.95.3-136 matched TU. */

extern void cIDBase(void *a0);
extern void CustomIDWork(void *a0);

__attribute__((section(".text.func_001E7118")))
void *func_001E7118(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    cIDBase(p);
    q = p + 0x50;
    /* closes with bne against a -1 register -> i != -1 */
    for (i = 9; i != -1; i--) {
        CustomIDWork(q);
        q += 0x7C;
    }

    cIDBase(p + 0x530);
    q = p + 0x580;
    for (i = 1; i != -1; i--) {
        CustomIDWork(q);
        q += 0x7C;
    }

    return p;
}
