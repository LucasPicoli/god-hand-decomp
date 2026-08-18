/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int moveMotion(void *a0);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */












__attribute__((section(".text.func_002591F8")))
void func_002591F8(void *a0)
{
    char *s3 = (char *)a0;
    int s2;
    int s1;

    switch (*(unsigned char *)(s3 + 0x2F6)) {
    case 0: {
        int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;

        if (*(short *)(s3 + 0x54A) <= 0) {
            *(short *)(s3 + 0x54A) = 1;
        }
        switch (*(int *)(s3 + 0x564)) {
        default: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x640) + b;
            s1 = *(int *)(b + 0x644) + b;
        }
            break;
        case 0x214:
        case 0x215: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x1B98) + b;
            s1 = *(int *)(b + 0x1B9C) + b;
        }
            break;
        case 0x242:
        case 0x243:
        case 0x244: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x36B0) + b;
            s1 = *(int *)(b + 0x36B4) + b;
        }
            break;
        case 0x256:
        case 0x27E: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x2BC0) + b;
            s1 = *(int *)(b + 0x2BC4) + b;
        }
            break;
        case 0x20A:
        case 0x20B:
        case 0x20C:
        case 0x20D:
        case 0x20E:
        case 0x218:
        case 0x245:
        case 0x246:
        case 0x247:
        case 0x24F:
        case 0x278:
        case 0x279: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0xB6C) + b;
            s1 = *(int *)(b + 0xB70) + b;
        }
            break;
        case 0x250:
        case 0x251: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0xB6C) + b;
            s1 = *(int *)(b + 0xB70) + b;
            cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                               (short)(Obj0000_Get_Field_424_1595F0(s3) + 0x23),
                               s3, 0, 0, 0, 0);
        }
            break;
        case 0x260: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0xB6C) + b;
            s1 = *(int *)(b + 0xB70) + b;
        }
            break;
        case 0x264: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x326C) + b;
            s1 = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x3724) + b;
            s1 = *(int *)(b + 0x3728) + b;
        }
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x17F0) + b;
            s1 = *(int *)(b + 0x17F4) + b;
        }
            break;
        case 0x241: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x3B14) + b;
            s1 = *(int *)(b + 0x3B18) + b;
        }
            break;
        case 0x209:
        case 0x21F: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x3474) + b;
            s1 = *(int *)(b + 0x3478) + b;
        }
            break;
        case 0x20F:
        case 0x210:
        case 0x211:
        case 0x226:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0xF24) + b;
            s1 = *(int *)(b + 0xF28) + b;
        }
            break;
        case 0x220:
        case 0x221:
        case 0x222: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x640) + b;
            s1 = *(int *)(b + 0x644) + b;
        }
            break;
        case 0x223: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x2EDC) + b;
            s1 = *(int *)(b + 0x2EE0) + b;
        }
            break;
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24D:
        case 0x24E:
        case 0x252:
        case 0x25A: {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x13D0) + b;
            s1 = *(int *)(b + 0x13D4) + b;
        }
            break;
        }
        func_002A8578(s3, s2, s1, 0.0f, 5, nb, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                           (short)Obj0000_Get_Field_424_1595F0(s3),
                           s3, 0, 0, 0, 0);
        *(int *)(s3 + 0x5F0) = 0;
        {
            char *p = *(char **)(s3 + 0x698);

            if (p != 0) {
                char *q = *(char **)(p + 0x34);

                if (q != 0) {
                    float *d = (float *)(s3 + 0x5D0);
                    float *sv;

                    *(int *)(s3 + 0x5F0) = 0xA;
                    sv = *(float **)(q + 0xF0);
                    if (d != sv) {
                        d[0] = sv[0];
                        d[1] = sv[1];
                        d[2] = sv[2];
                    }
                }
            }
        }
        *(unsigned char *)(s3 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        int t = *(int *)(s3 + 0x5F0);

        if (t != 0) {
            *(int *)(s3 + 0x5F0) = t - 1;
            AddScaledDeltaToField_104_2A7498(s3, (int)(s3 + 0x5D0),
                                             *(float *)(s3 + 0x5A8) * 0.39269909f);
        }
        if (moveMotion(s3) != 0) {
            func_002705D8(s3);
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        break;
    }
    }
}
