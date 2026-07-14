/* sn-2.95.3-136 matched TU. */

extern const float D_003BD880[4];

__attribute__((section(".text.func_002A9DF8")))
void func_002A9DF8(void *arg) {
    char *p = (char *)arg;
    const float *src1;
    const float *src2;
    float *d1;
    float *d2;
    int i;
    int j;

    *(int *)(p + 0x00) = 0;
    *(int *)(p + 0x04) = 0;
    *(int *)(p + 0x08) = 0;
    *(int *)(p + 0x0C) = 0;
    *(char *)(p + 0x18) = 0;
    *(char *)(p + 0x19) = 0;
    *(short *)(p + 0x1A) = 0;
    *(char *)(p + 0x1C) = 0;
    *(char *)(p + 0x1D) = 0;
    *(char *)(p + 0x1E) = 0;

    d1 = (float *)(p + 0x20);
    i = 3;
    src1 = D_003BD880;
    for (; i != -1; i--) {
        *d1++ = *src1++;
    }

    src2 = D_003BD880;
    d2 = (float *)(p + 0x30);
    j = 3;
    for (; j != -1; j--) {
        *d2++ = *src2++;
    }

    *(float *)(p + 0x40) = 0.01f;
    *(short *)(p + 0x44) = 0x80;
    *(char *)(p + 0x46) = 6;
}
