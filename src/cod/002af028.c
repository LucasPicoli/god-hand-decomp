/* sn-2.95.3-136 matched TU. */

extern void func_002B16F0(void *a0);

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_002AF028")))
void func_002AF028(void *a0) {
    void *p = *(void **)((char *)a0 + 0x10);
    while (p) {
        func_002B16F0(p);
        p = *(void **)((char *)p + 0x8);
    }
}
