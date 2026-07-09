/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_00324400")))
int func_00324400(void *a0) {
    int t = (func_00324440(a0) + 0x7FF) / 0x800;
    *(int *)((char *)a0 + 0xC) = t;
    return t;
}
