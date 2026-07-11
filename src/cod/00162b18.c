/* sn-2.95.3-136 matched TU. */

extern int PTR_DAT_003c2f84;
extern unsigned char D_007474A0[];

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00162B18")))
void func_00162B18(void *a0) {
    unsigned char v1val, t0;
    unsigned int a2;
    if (*(unsigned char *)(PTR_DAT_003c2f84 + 0x14) != 0) {
        t0    = D_007474A0[0x5B7];
        v1val = D_007474A0[0x5B6];
    } else {
        t0    = D_007474A0[0x5B1];
        v1val = D_007474A0[0x5B0];
    }
    if (t0 != 0) {
        unsigned int hi = (t0 << 4) + 0x2013;
        a2 = hi + v1val;
    } else
        a2 = 0x20A3;
    a2 = (a2 < 0x20A4) ? a2 : 0x20A3;
    *(unsigned short *)(*(int *)((char *)a0 + 0xE4) + 0x90) = a2;
    *(unsigned short *)(*(int *)((char *)a0 + 0xE8) + 0x90) = a2;
    switch (t0) {
    case 0:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 254.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 289.0f;
        break;
    case 1:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 102.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 266.0f;
        break;
    case 2:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 167.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 195.0f;
        break;
    case 3:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 134.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 92.0f;
        break;
    case 4:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 235.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 126.0f;
        break;
    case 5:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 320.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 190.0f;
        break;
    case 6:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 320.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 88.0f;
        break;
    case 7:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 408.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 88.0f;
        break;
    case 8:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 455.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 47.0f;
        break;
    }
}
