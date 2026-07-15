/* sn-2.95.3-136 matched TU. */

extern void func_002CE488(void *a0, void *a1);

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_002CBE18")))
void func_002CBE18(void *a0, void *a1) {
    void *p = *(void **)((char *)a0 + 0x1C);
    while (p) {
        func_002CE488(p, a1);
        p = *(void **)((char *)p + 0x4);
    }
}
