/* sn-2.95.3-136 matched TU. */

extern void func_001FCCC0(void *a0);

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001FD770")))
void func_001FD770(void *a0) {
    void *p = *(void **)((char *)a0 + 0x3C);
    while (p) {
        func_001FCCC0(p);
        p = *(void **)((char *)p + 0x24);
    }
}
