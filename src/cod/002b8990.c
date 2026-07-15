/* sn-2.95.3-136 matched TU. */

extern void func_002BAC88(void *);
extern void func_002BB040(void *);
extern char D_0044BAF8;

/* sn-2.95.3-136 matched TU. One CALL-loop -> one errata pad nop
   (needs --call-loop-pad). */





__attribute__((section(".text.func_002B8990")))
void *func_002B8990(void *a0) {
    char *this = (char *)a0;
    char *p;
    char *base;
    int i;

    *(int *)this = 3;
    *(void **)(this + 0x8) = &D_0044BAF8;
    *(char *)(this + 0xD) = 0;

    /* `base` (this+0x14) stays live across the loop in $s4: it is the loop's
       starting pointer AND the arg to the first post-loop call. The second
       call recomputes this+0x14 from `this`. */
    base = this + 0x14;
    p = base;
    /* `i != -1`, not `i >= 0`: retail materialises -1 and closes with bne. */
    for (i = 3; i != -1; i--) {
        func_002BAC88(p);
        p += 0x8;
    }

    func_002BB040(base);
    func_002BB040(this + 0x14);

    *(int *)this |= 3;

    return this;
}
