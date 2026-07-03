/* ee-2.9-991111 matched TU. */

__attribute__((section(".text.func_003058D8")))
void *func_003058D8(void *a0, int a1) {
    unsigned int i = 0;
    do {
        if (*(int*)a0 == a1) return a0;
        a0 = (char*)a0 + 0x10;
    } while (++i < 0x40);
    return 0;
}
