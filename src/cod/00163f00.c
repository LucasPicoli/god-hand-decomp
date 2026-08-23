/* sn-2.95.3-136 matched TU. */

extern int D_00747A0C;
extern int D_00747A24;
extern float D_0041F630[][4];

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_00163F00")))
void func_00163F00(char *s)
{
    unsigned long t;

    *(int *)(*(int *)(s + 0xC4) + 0x2C) &= 0xF7FFFFFF;
    *(int *)(*(int *)(s + 0xCC) + 0x2C) |= 0x8000000;
    *(int *)(*(int *)(s + 0xD8) + 0x2C) |= 0x8000000;
    *(int *)(*(int *)(s + 0xD4) + 0x2C) |= 0x8000000;
    *(int *)(*(int *)(s + 0xD0) + 0x2C) |= 0x8000000;

    switch (*(short *)(s + 0x130)) {
    case 0:
        *(float *)(*(int *)(s + 0xC8) + 0x3C) = D_0041F630[D_00747A0C][0];
        *(int *)(*(int *)(s + 0xCC) + 0x2C) &= 0xF7FFFFFF;
        s[0x132] = 0;
        break;
    case 1:
        *(float *)(*(int *)(s + 0xC8) + 0x3C) = D_0041F630[D_00747A0C][1];
        *(int *)(*(int *)(s + 0xD0) + 0x2C) &= 0xF7FFFFFF;
        s[0x132] = 0;
        break;
    case 2:
        *(float *)(*(int *)(s + 0xC8) + 0x3C) = D_0041F630[D_00747A0C][2];
        *(int *)(*(int *)(s + 0xD4) + 0x2C) &= 0xF7FFFFFF;
        s[0x132] = 1;
        break;
    case 3:
        *(float *)(*(int *)(s + 0xC8) + 0x3C) = D_0041F630[D_00747A0C][3];
        *(int *)(*(int *)(s + 0xD8) + 0x2C) &= 0xF7FFFFFF;
        s[0x132] = 1;
        break;
    }

    if (*(unsigned char *)(s + 0x132) == 0) {
        *(float *)(*(int *)(s + 0x80) + 0x38) = *(float *)(s + 0x128);
        *(float *)(*(int *)(s + 0x80) + 0x3C) = *(float *)(s + 0x12C);
    } else if (*(unsigned char *)(s + 0x132) == 1) {
        *(float *)(*(int *)(s + 0x80) + 0x38) = 255.0f;
        *(float *)(*(int *)(s + 0x80) + 0x3C) = 283.0f;
    }

    t = D_00747A24;
    if (((t >> 6) & 1) == 1) {
        *(int *)(*(int *)(s + 0xEC) + 0x2C) |= 0x8000000;
    }
}
