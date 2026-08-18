/* sn-2.95.3-136 matched TU. */

extern int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_00274FE8(void *a0);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_0025A3E8")))
void func_0025A3E8(void *a0)
{
    char *s1 = (char *)a0;
    int s3;
    int s2;
    int s4;

    if (*(unsigned char *)(s1 + 0x2F6) == 0) {
        switch (*(int *)(s1 + 0x564)) {
        case 0x20F:
        case 0x210:
        case 0x211:
        case 0x226:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            *(unsigned char *)(s1 + 0x2F6) = 2;
            break;
        }
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        if (func_002740D8(s1) != 0) {
            if (Forward30F348_31CFE0() & 1) {
                *(char *)(s1 + 0x17C3) = 1;
            } else {
                *(char *)(s1 + 0x17C3) = 0;
            }
        }
        s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        ReleaseField6ECByTag564_26B1E8(s1);
        switch (*(int *)(s1 + 0x564)) {
        case 0x256:
        case 0x27E: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0x2A28) + b;
            s2 = *(int *)(b + 0x2A2C) + b;
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
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0xB5C) + b;
            s2 = *(int *)(b + 0xB60) + b;
        }
            break;
        case 0x250:
        case 0x251: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0xB5C) + b;
            s2 = *(int *)(b + 0xB60) + b;
            cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                               (short)(Obj0000_Get_Field_424_1595F0(s1) + 0x23),
                               s1, 0, 0, 0, 0);
        }
            break;
        case 0x260: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0xB5C) + b;
            s2 = *(int *)(b + 0xB60) + b;
        }
            break;
        case 0x264: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0x326C) + b;
            s2 = *(int *)(b + 0x3270) + b;
            *(char *)(s1 + 0x2F7) = 1;
        }
            break;
        case 0x265: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0x3818) + b;
            s2 = *(int *)(b + 0x381C) + b;
            *(char *)(s1 + 0x2F7) = 1;
        }
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
        case 0x241: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0x17D0) + b;
            s2 = *(int *)(b + 0x17D4) + b;
        }
            break;
        case 0x209:
        case 0x21F: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0x17D0) + b;
            s2 = *(int *)(b + 0x17D4) + b;
        }
            break;
        case 0x215:
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
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0x13B0) + b;
            s2 = *(int *)(b + 0x13B4) + b;
            *(char *)(s1 + 0x2F7) = 1;
        }
            break;
        default: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0x638) + b;
            s2 = *(int *)(b + 0x63C) + b;
        }
            break;
        case 0x223: {
            int b = *(int *)(s1 + 0x304);
            s3 = *(int *)(b + 0x2E34) + b;
            s2 = *(int *)(b + 0x2E38) + b;
            *(char *)(s1 + 0x2F7) = 1;
        }
            break;
        }
        func_002A8578(s1, s3, s2, 0.0f, 3, s4, 0);
        if (*(unsigned char *)(s1 + 0x2F7) == 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2D, s1, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x32, s1, 0, 0, 0, 0);
        }
        if (*(short *)(s1 + 0x54A) <= 0) {
            *(short *)(s1 + 0x54A) = 1;
        }
        *(int *)(s1 + 0x16EC) = 0;
        *(unsigned char *)(s1 + 0x2F6) += 1;
        /* fallthrough */
    case 1:
        if (*(unsigned char *)(s1 + 0x2F7) == 0) {
            *(int *)(s1 + 0x16D0) |= 0x40000;
        }
        if (moveMotion(s1) != 0) {
            if (*(unsigned char *)(s1 + 0x2F7) == 0) {
                func_002705D8(s1);
            } else {
                *(char *)(s1 + 0x2F4) = 0;
                *(char *)(s1 + 0x2F5) = 0x6B;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F7) = 1;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 2:
        if (func_002740D8(s1) != 0) {
            if (Forward30F348_31CFE0() & 1) {
                *(char *)(s1 + 0x17C3) = 1;
            } else {
                *(char *)(s1 + 0x17C3) = 0;
            }
        }
        s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        ReleaseField6ECByTag564_26B1E8(s1);
        {
            int b = *(int *)(s1 + 0x304);
            func_002A8578(s1, *(int *)(b + 0xF84) + b, *(int *)(b + 0xF88) + b,
                          0.0f, 0, s4, 0);
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2D, s1, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x32, s1, 0, 0, 0, 0);
        if (*(short *)(s1 + 0x54A) <= 0) {
            *(short *)(s1 + 0x54A) = 1;
        }
        *(int *)(s1 + 0x16EC) = 0;
        *(unsigned char *)(s1 + 0x2F6) += 1;
        /* fallthrough */
    case 3:
        *(int *)(s1 + 0x16D0) |= 0x40000;
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 4: {
        int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        int b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0xF8C) + b, *(int *)(b + 0xF90) + b,
                      0.0f, 0, nb, 0);
        *(float *)(s1 + 0x600) = 150.0f;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5:
        *(int *)(s1 + 0x16D0) |= 0x40000;
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        *(float *)(s1 + 0x600) -= *(float *)(s1 + 0x5A8);
        if (*(float *)(s1 + 0x600) <= 0.0f) {
            func_00274FE8(s1);
        }
        break;
    }
}
