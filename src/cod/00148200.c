/* sn-2.95.3-136 matched TU. */

extern unsigned char D_007476B0;

__attribute__((section(".text.func_00148200")))
void func_00148200(void *a0, float x, float y) {
    char *p = (char *)a0;
    *(float *)(p + 0x0) = 1.0f;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0xC) = 0;
    *(int *)(p + 0x10) = 0;
    *(float *)(p + 0x14) = 1.0f;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1C) = 0;
    *(float *)(p + 0x20) = x;
    *(float *)(p + 0x24) = y;
    *(float *)(p + 0x28) = 1.0f;
    *(int *)(p + 0x2C) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
}

__attribute__((section(".text.func_001491D0")))
void func_001491D0(void *a0, void *a1) {
    int d = (D_007476B0 & 1) * 0xD0 + (int)a0;
    char *s = (char *)a1;
    *(float *)(d + 0x1B0) = *(float *)(s + 0x0);
    *(float *)(d + 0x1B4) = *(float *)(s + 0x4);
    *(float *)(d + 0x1C0) = *(float *)(s + 0x10);
    *(float *)(d + 0x1C4) = *(float *)(s + 0x14);
    *(float *)(d + 0x1D0) = *(float *)(s + 0x20);
    *(float *)(d + 0x1D4) = *(float *)(s + 0x24);
}
