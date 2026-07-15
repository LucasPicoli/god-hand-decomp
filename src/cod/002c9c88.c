/* sn-2.95.3-136 matched TU. */

extern void func_002CC4A0(void *);
extern char D_005FFD80;
extern char D_00601180;
extern char D_005FEFF0;
extern char D_005FFCF0;

/* sn-2.95.3-136 matched TU. One CALL-loop -> one errata pad nop
   (needs --call-loop-pad). */







__attribute__((section(".text.func_002C9C88")))
void *func_002C9C88(void *a0) {
    char *this = (char *)a0;
    char *p;
    int i;

    *(void **)(this + 0x34) = &D_005FFD80;
    *(void **)(this + 0x38) = &D_00601180;
    *(void **)(this + 0x3C) = &D_005FEFF0;
    *(void **)(this + 0x40) = &D_005FFCF0;
    *(int *)(this + 0x18) = 0;
    *(int *)(this + 0x1C) = 0;

    p = this + 0x160;
    /* `i != -1`, not `i >= 0`: retail materialises -1 and closes with bne. */
    for (i = 0xF; i != -1; i--) {
        func_002CC4A0(p);
        p += 0x8;
    }

    return this;
}
