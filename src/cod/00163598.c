/* sn-2.95.3-136 matched TU. */

extern float D_003BD880[];

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_00163598")))
void func_00163598(char *s)
{
    float *d;
    float *e;
    char *b;
    char **m;

    switch (s[0x5C]) {
    case 0:
        d = (float *)(s + 0x100);
        e = (float *)(s + 0x110);
        b = s + 0x80;
        d[0] = D_003BD880[0];
        d[1] = D_003BD880[1];
        d[2] = D_003BD880[2];
        e[0] = D_003BD880[0];
        e[1] = D_003BD880[1];
        e[2] = D_003BD880[2];
        m = (char **)(b + (s[0xF0] + 8) * 4);
        *(float *)(s + 0x100) = *(float *)(*m + 0x38) + *(float *)(*m + 0x68) * *(float *)(*m + 0x40);
        *(float *)(s + 0x104) = *(float *)(*m + 0x3C);
        *(float *)(s + 0x110) = *(float *)(*m + 0x38);
        *(float *)(s + 0x114) = *(float *)(*m + 0x3C);
        *(unsigned char *)(s + 0x5C) += 1;
        /* fallthrough */
    case 1:
        *(float *)(s + 0x108) += 0.1f;
        if (*(float *)(s + 0x108) > 1.0f) {
            *(float *)(s + 0x108) = 1.0f;
            *(unsigned char *)(s + 0x5C) += 1;
        }
        break;
    case 2:
        *(float *)(s + 0x118) += 0.1f;
        if (*(float *)(s + 0x118) > 1.0f) {
            *(float *)(s + 0x118) = 1.0f;
            *(unsigned char *)(s + 0x5C) += 1;
        }
        break;
    case 3:
        switch ((signed char)(*(unsigned char *)(s + 0xF0) - 1)) {
        case 0:
            *(int *)(*(int *)(s + 0x84) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s + 0xA4) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 1:
            *(int *)(*(int *)(s + 0x88) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s + 0xA8) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 2:
            *(int *)(*(int *)(s + 0x8C) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s + 0xAC) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 3:
            *(int *)(*(int *)(s + 0x90) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s + 0xB0) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 4:
            *(int *)(*(int *)(s + 0x94) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s + 0xB4) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s + 0x98) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 5:
            *(int *)(*(int *)(s + 0x9C) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s + 0xB8) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 6:
            *(int *)(*(int *)(s + 0xA0) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s + 0xBC) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 7:
            *(int *)(*(int *)(s + 0xC0) + 0x2C) &= 0xF7FFFFFF;
            break;
        }
        /* fallthrough */
    case 4:
        s[0x5C] = 0;
        *(unsigned char *)(s + 0x5B) += 1;
        break;
    }
}
