/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_002B8820")))
int func_002B8820(char *a0) {
    *(int *)(a0 + 0x254) |= 0x8000000;
    *(int *)(a0 + 0x4A8) |= 0x10000000;
    *(char *)(a0 + 0x4D4) = 0;
    return 1;
}
