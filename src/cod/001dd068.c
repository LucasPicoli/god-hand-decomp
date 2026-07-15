/* sn-2.95.3-136 matched TU. */

extern void cIDBase(void *a0);
extern void CustomIDWork(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DD068")))
void *func_001DD068(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    *(int *)p = 0;
    cIDBase(p + 0x10);

    q = p + 0x60;
    /* `i != -1`, not `i >= 0`: retail materialises -1 in a register and closes
       this call-loop with `bne`. The idiom picks the branch instruction. */
    for (i = 0x4C; i != -1; i--) {
        CustomIDWork(q);
        q += 0x7C;
    }
    return p;
}
