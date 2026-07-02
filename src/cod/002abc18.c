/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_002ABC18")))
void func_002ABC18(int a0, char *a1) {
    int v0 = *(int *)(a1 + 0x2C);
    *(short *)(a1 + 0xA0) = 0;
    *(int *)(a1 + 0x2C) = v0 & ~0x4000;
}

__attribute__((section(".text.func_002AE3D0")))
void *func_002AE3D0(char *a0) {
    a0[0x0] = 0;
    *(int *)(a0 + 0x4) = 0;
    *(int *)(a0 + 0x8) = -1;
    return a0;
}

__attribute__((section(".text.func_002AEB50")))
int func_002AEB50(char *a0, char *a1, int a2) {
    char *v1 = *(char **)(a0 + 0x4);
    unsigned short v0 = *(unsigned short *)(v1 + 0x2);
    return ((v0 + a2) & 0xFFFF) | 0x1000;
}

__attribute__((section(".text.func_002C3040")))
void func_002C3040(char *a0, int *a1, int *a2) {
    int v1 = *a1;
    int v0 = (int)a2 | 0x80000000;
    *a2 = v1;
    *a1 = v0;
}
