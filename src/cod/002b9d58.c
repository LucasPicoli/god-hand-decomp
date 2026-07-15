/* sn-2.95.3-136 matched TU. */

extern void func_002BA250(void *a0);
extern void func_002B8AA8(void *a0);
extern void func_002B8F48(void *a0);

/* FAILED (flag-coverage gap, NOT a C error).
 * This body is byte-correct: WITHOUT --call-loop-pad it compiles to 88B vs
 * retail 92B (delta -4), diverging only at the guard-branch offset that the
 * missing pad shifts. But WITH --call-loop-pad it is STILL 88B: the pad is not
 * inserted.
 * Root cause: this loop's closing `bne` sits in a `.set reorder` region with a
 * NOP delay slot (cc1 does not wrap it in .set noreorder because there is no
 * real delay-slot filler -- the pointer-chase `p = p->next` is a single load).
 * The flag inserts `nop` immediately before the branch, but ee-as DROPS a nop
 * placed before a branch inside a `.set reorder` region (verified directly:
 * reorder -> jal/move/lw/bne/nop, pad gone; the SAME lines wrapped in
 * `.set noreorder` -> jal/move/lw/nop/bne/nop, i.e. retail's exact shape).
 * All 5 sibling matches in this batch have a REAL instruction in the loop
 * branch delay slot (pointer/counter increment or arg reload), which makes cc1
 * emit the branch in `.set noreorder` and lets the pad survive. This one does
 * not. Landing it needs the flag to also wrap a reorder-region call-loop branch
 * in `.set noreorder` (out of scope here: no tooling edits). */




__attribute__((section(".text.func_002B9D58")))
void func_002B9D58(void *a0) {
    char *p;
    func_002BA250(a0);
    p = *(char **)((char *)a0 + 0x10);
    if (p != 0) {
        do {
            func_002B8AA8(p);
            p = *(char **)(p + 4);
        } while (p != 0);
    }
    func_002B8F48(a0);
}
