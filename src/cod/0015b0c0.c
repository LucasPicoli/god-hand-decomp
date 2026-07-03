/* sn-2.95.3-136 matched TU. */

extern int D_007476B0;
extern int D_004A6E10;
extern int D_00566E10;
extern unsigned char D_005E85F8;
extern int D_00747A2C;

__attribute__((section(".text.func_0015B0C0")))
void func_0015B0C0(void) {
    int base = (int)&D_004A6E10;
    int flag = D_007476B0 & 1;
    D_00566E10 = base + flag * 0x60000;
}

__attribute__((section(".text.func_001F9DD0")))
void func_001F9DD0(void **a0) {
    void *p = *a0;
    if (p == 0) return;
    if (D_005E85F8 != 0) {
        *(int *)((char *)p + 0x174) = 1;
        return;
    }
    *(int *)((char *)p + 0x174) = 0;
}

__attribute__((section(".text.func_003186D0")))
int func_003186D0(char *a0) {
    int mask;
    if ((*(int *)(a0 + 0x250) & 2) != 0) return 1;
    mask = D_00747A2C & 0x400000;
    return mask != 0;
}

__attribute__((section(".text.func_0031A088")))
void func_0031A088(char *a0, unsigned int a1) {
    unsigned int *p = (unsigned int *)(a0 + 0x350);
    p[a1 >> 5] |= 0x80000000u >> (a1 & 0x1F);
}

__attribute__((section(".text.func_0031CA58")))
unsigned int func_0031CA58(unsigned int a0) {
    unsigned int v1, v0, a1;
    v1 = a0 >> 16;
    v0 = a0 & 0xFF000000;
    a1 = a0 & 0xFF;
    v1 = v1 & 0xFF;
    a0 = a0 & 0xFF00;
    v0 = v0 | v1;
    a1 = a1 << 16;
    v0 = v0 | a0;
    v0 = v0 | a1;
    return v0;
}
