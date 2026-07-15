/* sn-2.95.3-136 matched TU. */

extern void InitObjectA_1FCE20(void *a0);
extern void InitObjectB_1FD3B8(void *a0);

/* sn-2.95.3-136 matched TU. Two call-loops → --call-loop-pad. */




__attribute__((section(".text.func_001FDE00")))
void *func_001FDE00(void *a0) {
    char *this = (char *)a0;
    char *p;
    int i;

    p = this;
    /* `i != -1`: retail materialises -1 in $s3 and closes with `bne`. */
    for (i = 0x9F; i != -1; i--) {
        InitObjectA_1FCE20(p);
        p += 0x60;
    }

    p = this + 0x3C00;
    for (i = 0xFF; i != -1; i--) {
        InitObjectB_1FD3B8(p);
        p += 0x70;
    }

    InitObjectA_1FCE20(this + 0xAC00);
    InitObjectB_1FD3B8(this + 0xAC60);
    return this;
}
