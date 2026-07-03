/* ee-2.9-991111 matched TU. */

__attribute__((section(".text.func_002BB068")))
void *func_002BB068(void *a0, int a1) {
    unsigned int i = 0;
    do {
        if (*(int*)a0 == a1) return a0;
        a0 = (char*)a0 + 8;
    } while (++i < 4);
    return 0;
}

__attribute__((section(".text.func_002BB098")))
void *func_002BB098(void *a0) {
    unsigned int i = 0;
    do {
        if (*(int*)a0 == 0) return a0;
        a0 = (char*)a0 + 8;
    } while (++i < 4);
    return 0;
}
