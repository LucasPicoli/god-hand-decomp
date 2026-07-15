/* sn-2.95.3-136 matched TU. */

extern void func_002B5AE8(void *a0);
extern char D_005E7E30[];

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002B48F0")))
void *func_002B48F0(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    *(int *)p = (int)D_005E7E30;

    q = p + 0x1C;
    /* `!= -1`, not `>= 0`: retail materialises -1 and closes with `bne`. */
    for (i = 0x3F; i != -1; i--) {
        func_002B5AE8(q);
        q += 0x8;
    }
    return p;
}
