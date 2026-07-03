/* ee-2.9-991111 matched TU. */

__attribute__((section(".text.func_00389D70")))
void *func_00389D70(void *a0, void (*a1)()) {
    a1(*(int*)a0);
    return a0;
}

__attribute__((section(".text.func_0038A448")))
void *func_0038A448(void *a0, void (*a1)()) {
    a1(*(int*)a0);
    return a0;
}

__attribute__((section(".text.func_001FF6E0")))
int func_001FF6E0(void *a0, int a1) {
    int *p = (int*)((char*)a0 + 0x4C);
    unsigned int v1 = 0;
    do {
        if (*p == a1) {
            return 1;
        }
        v1++;
        p++;
    } while (v1 < 4);
    return 0;
}
