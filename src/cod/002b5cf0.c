/* sn-2.95.3-136 matched TU. */

extern void func_002B5D58(void *a0, void *a1);
extern void func_002B5EC0(void *a0);

__attribute__((section(".text.func_002B5CF0")))
void func_002B5CF0(void *a0, void *a1) {
    char *s0 = (char *)a0;

    while (*(void **)(s0 + 8)) {
        func_002B5D58(*(void **)(s0 + 8), a1);
    }
    *(void **)(s0 + 8) = 0;
    func_002B5EC0(s0);
}
