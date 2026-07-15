/* sn-2.95.3-136 matched TU. */

extern void func_00150100(void *a0);

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_00149E60")))
void func_00149E60(void *a0) {
    char *self = (char *)a0;
    void *p = *(void **)(self + 0x144);
    /* Linked-list sweep: each node links to the next via field +0x144.
       The advance MUST be written before the call (with a lagging `cur`
       copy) so cc1 schedules the pointer-advance load into the jal delay
       slot and the arg copy into the closing-branch delay slot — retail's
       exact schedule. Writing `func(p); p = p->next;` instead flips both
       delay slots and shifts the loop body, breaking the match.
       The loop body carries a call, so ee-as omits BOTH R5900 short-loop
       pads (two nops before the closing `bnez`) → needs --call-loop-pad. */
    while (p != 0) {
        void *cur = p;
        p = *(void **)((char *)p + 0x144);
        func_00150100(cur);
    }
    *(void **)(self + 0x144) = 0;
}
