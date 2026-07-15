/* sn-2.95.3-136 matched TU. */

extern void func_002D3200(void *a0);

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_002D2DC8")))
void *func_002D2DC8(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    *(int *)p = 0;

    q = p + 0x40;
    /* `!= -1`, not `>= 0`: retail materialises -1 and closes with `bne`. */
    for (i = 0xF; i != -1; i--) {
        func_002D3200(q);
        q += 0xC0;
    }

    *(int *)(p + 0xC40) = 1;
    return p;
}
