/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_003B2DE8")))
void *func_003B2DE8(int key, char *a1) {
    char *outer = *(char **)(a1 + 0x28);
    while (outer != 0) {
        char *inner = *(char **)(outer + 8);
        while (inner != 0) {
            if (*(int *)inner == key) return inner;
            inner = *(char **)(inner + 0x38);
        }
        outer = *(char **)(outer + 0x14);
    }
    return 0;
}
