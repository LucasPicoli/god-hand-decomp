/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int Forward30F348_31CFE0(void);
extern int moveMotion(void *a0);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void func_0026ECD0(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */














/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00258D80")))
void func_00258D80(void *a0)
{
    char *s3 = (char *)a0;
    int s2;
    int s1;

    switch (*(unsigned char *)(s3 + 0x2F6)) {
    case 0: {
        int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;

        switch (*(int *)(s3 + 0x564)) {
        default:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x5F8) + b;
                s1 = *(int *)(b + 0x5FC) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x600) + b;
                s1 = *(int *)(b + 0x604) + b;
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
        case 0x279:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xAF4) + b;
                s1 = *(int *)(b + 0xAF8) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xAFC) + b;
                s1 = *(int *)(b + 0xB00) + b;
            }
            break;
        case 0x250:
        case 0x251:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xAF4) + b;
                s1 = *(int *)(b + 0xAF8) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xAFC) + b;
                s1 = *(int *)(b + 0xB00) + b;
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                               (short)(Obj0000_Get_Field_424_1595F0(s3) + 0x23),
                               s3, 0, 0, 0, 0);
            break;
        case 0x260:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xAF4) + b;
                s1 = *(int *)(b + 0xAF8) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xAFC) + b;
                s1 = *(int *)(b + 0xB00) + b;
            }
            break;
        case 0x264:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3300) + b;
                s1 = *(int *)(b + 0x3304) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3300) + b;
                s1 = *(int *)(b + 0x3304) + b;
            }
            break;
        case 0x265:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3818) + b;
                s1 = *(int *)(b + 0x381C) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3818) + b;
                s1 = *(int *)(b + 0x381C) + b;
            }
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1778) + b;
                s1 = *(int *)(b + 0x177C) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1780) + b;
                s1 = *(int *)(b + 0x1784) + b;
            }
            break;
        case 0x241:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3ACC) + b;
                s1 = *(int *)(b + 0x3AD0) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3AD4) + b;
                s1 = *(int *)(b + 0x3AD8) + b;
            }
            break;
        case 0x209:
        case 0x21F:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1778) + b;
                s1 = *(int *)(b + 0x177C) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1780) + b;
                s1 = *(int *)(b + 0x1784) + b;
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
        case 0x274:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xF24) + b;
                s1 = *(int *)(b + 0xF28) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xF2C) + b;
                s1 = *(int *)(b + 0xF30) + b;
            }
            break;
        case 0x220:
        case 0x221:
        case 0x222:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x5F8) + b;
                s1 = *(int *)(b + 0x5FC) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x600) + b;
                s1 = *(int *)(b + 0x604) + b;
            }
            break;
        case 0x223:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2E34) + b;
                s1 = *(int *)(b + 0x2E38) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2E3C) + b;
                s1 = *(int *)(b + 0x2E40) + b;
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
        case 0x25A:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1350) + b;
                s1 = *(int *)(b + 0x1354) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1358) + b;
                s1 = *(int *)(b + 0x135C) + b;
            }
            break;
        }
        func_002A8578(s3, s2, s1, 0.0f, 3, nb, 0);
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
            switch (*(int *)(s3 + 0x564)) {
            case 0x20E:
            case 0x213:
            case 0x217:
                *(int *)(s3 + 0x16E8) = *(int *)(s3 + 0x16E8) + 0x3E7;
                func_0026ECD0(s3, 0);
                break;
            }
            func_002705D8(s3);
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        break;
    }
    }
}
