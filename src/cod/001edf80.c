/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_Main(void *a0);
extern void cIDBase_move(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001EDF80")))
void func_001EDF80(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    q = p + 0x60;
    /* `i >= 0`: retail closes this loop with `bgez` (not `bne`). The loop
       body carries a call, so ee-as omits the R5900 short-loop pad (one nop
       before the closing branch) → needs --call-loop-pad. */
    for (i = 0x1C; i >= 0; i--) {
        CustomIDWork_Main(q);
        q += 0x7C;
    }
    cIDBase_move(p + 0x10);
}
