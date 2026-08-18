/* sn-2.95.3-136 matched TU. */

extern unsigned int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void Obj1D00_ClearState_6(int a0);
extern void Obj1D00_ClearState_7(int a0);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */




















__attribute__((section(".text.func_0023AFD8")))
void func_0023AFD8(void *a0)
{
    char *s3 = (char *)a0;
    int s2;
    int s1;

    *(int *)(s3 + 0x16D0) |= 0x400;
    switch (*(unsigned char *)(s3 + 0x2F6)) {
    case 0:
    {
        int w;
        int nb;
        float fz;

        *(char *)(s3 + 0x1864) = 0;
        w = *(int *)(s3 + 0x564);
        w -= 0x202;
        switch (w) {
        default:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x39C) + p;
            s1 = *(int *)(p + 0x3A0) + p;
        }
            break;
        case 18: case 19:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1B80) + p;
            s1 = *(int *)(p + 0x1B84) + p;
        }
            break;
        case 0: case 1:
        case 17:
        case 20: case 21:
        case 39: case 40:
        case 73:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x7C4) + p;
            s1 = *(int *)(p + 0x7C8) + p;
        }
            break;
        case 84:
        case 124:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x2BA8) + p;
            s1 = *(int *)(p + 0x2BAC) + p;
        }
            break;
        case 64: case 65: case 66:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3698) + p;
            s1 = *(int *)(p + 0x369C) + p;
        }
            break;
        case 8:
        case 11: case 12:
        case 67:
        case 69:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0xB74) + p;
            s1 = *(int *)(p + 0xB78) + p;
        }
            break;
        case 118:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3C0C) + p;
            s1 = *(int *)(p + 0x3C10) + p;
        }
            break;
        case 22:
        case 68:
        case 119:
        {
            int p;
            ReleaseField6ECByTag564_26B1E8(s3);
            p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3C1C) + p;
            s1 = *(int *)(p + 0x3C20) + p;
        }
            break;
        case 9:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1E34) + p;
            s1 = *(int *)(p + 0x1E38) + p;
        }
            break;
        case 10:
        case 77:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1F80) + p;
            s1 = *(int *)(p + 0x1F84) + p;
        }
            break;
        case 3: case 4: case 5: case 6:
        case 34:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x17D8) + p;
            s1 = *(int *)(p + 0x17DC) + p;
        }
            break;
        case 63:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3AFC) + p;
            s1 = *(int *)(p + 0x3B00) + p;
        }
            break;
        case 7:
        case 29:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x345C) + p;
            s1 = *(int *)(p + 0x3460) + p;
        }
            break;
        case 78: case 79:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1A18) + p;
            s1 = *(int *)(p + 0x1A1C) + p;
            cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                               (short)(Obj0000_Get_Field_424_1595F0(s3) + 0x23),
                               s3, 0, 0, 0, 0);
        }
            break;
        case 94:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1A18) + p;
            s1 = *(int *)(p + 0x1A1C) + p;
        }
            break;
        case 98:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x326C) + p;
            s1 = *(int *)(p + 0x3270) + p;
        }
            break;
        case 99:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3724) + p;
            s1 = *(int *)(p + 0x3728) + p;
        }
            break;
        case 30: case 31: case 32:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1D50) + p;
            s1 = *(int *)(p + 0x1D54) + p;
        }
            break;
        case 33:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x2ECC) + p;
            s1 = *(int *)(p + 0x2ED0) + p;
        }
            break;
        case 115: case 116:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x23A8) + p;
            s1 = *(int *)(p + 0x23AC) + p;
        }
            break;
        case 24: case 25: case 26: case 27: case 28:
        case 35:
        case 42: case 43: case 44: case 45:
        case 70: case 71:
        case 74: case 75: case 76:
        case 80:
        case 88:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x13B8) + p;
            s1 = *(int *)(p + 0x13BC) + p;
        }
            break;
        }
        fz = 0.0f;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        func_002A8578(s3, s2, s1, 3, fz, nb, 0);
        *(int *)(s3 + 0x5F0) = Forward30F348_31CFE0() % 0x1E + 0x1E;
        {
            int t = *(int *)(s3 + 0x564);
            if (t == 0x250 || t == 0x251) {
                *(int *)(s3 + 0x5F0) = 0x3C;
            }
        }
        if ((Forward30F348_31CFE0() & 3) != 0) {
            *(int *)(s3 + 0x5F0) = 0x14;
        }
        *(float *)(s3 + 0x604) = fz;
        if (*(unsigned char *)(s3 + 0x2F7) != 0) {
            *(float *)(s3 + 0x604) = -0.3f;
        }
        if (*(int *)(s3 + 0x6F0) != 0) {
            Obj1D00_ClearState_6(*(int *)(s3 + 0x6F0));
        }
        if (*(int *)(s3 + 0x708) != 0) {
            Obj1D00_ClearState_7(*(int *)(s3 + 0x708));
        }
        *(int *)(s3 + 0x5F0) = 5;
        *(float *)(s3 + 0x600) = 15.0f;
        *(unsigned char *)(s3 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
    {
        int c;

        *(int *)(s3 + 0x16D0) |= 0x2000;
        c = *(int *)(s3 + 0x5F0);
        if (c != 0) {
            int r;
            *(int *)(s3 + 0x5F0) = c - 1;
            r = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s3, *(int *)(r + 0xF0),
                                             *(float *)(s3 + 0x5A8) * 0.39269909f);
        }
        moveMotion(s3);
        {
            float d = *(float *)(s3 + 0x5A8);
            float e = *(float *)(s3 + 0x604);
            *(float *)(s3 + 0x338) = *(float *)(s3 + 0x338) + e * d;
            *(float *)(s3 + 0x604) = e * (1.0f - d * 0.3f);
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        if (*(float *)(s3 + 0x173C) <= 0.0f) {
            float t = *(float *)(s3 + 0x600) - *(float *)(s3 + 0x5A8);
            *(float *)(s3 + 0x600) = t;
            if (t <= 0.0f) {
                if (func_00262AA8(s3) != 0) {
                    break;
                }
                *(unsigned char *)(s3 + 0x2F6) = 2;
            }
        }
        if (func_00274150(s3) == 0) {
            if (!(*(float *)(s3 + 0x1734) > 0.0f)) {
                break;
            }
        }
        *(unsigned char *)(s3 + 0x2F7) = 0;
        *(unsigned char *)(s3 + 0x2F4) = 0;
        *(unsigned char *)(s3 + 0x2F6) = 0;
        *(unsigned char *)(s3 + 0x2F5) = 0x89;
    }
        break;
    case 2:
    {
        int nb;

        switch (*(int *)(s3 + 0x564)) {
        default:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3A4) + p;
            s1 = *(int *)(p + 0x3A8) + p;
        }
            break;
        case 0x214: case 0x215:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1B88) + p;
            s1 = *(int *)(p + 0x1B8C) + p;
        }
            break;
        case 0x256:
        case 0x27E:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x2BB8) + p;
            s1 = *(int *)(p + 0x2BBC) + p;
        }
            break;
        case 0x242: case 0x243: case 0x244:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x36A0) + p;
            s1 = *(int *)(p + 0x36A4) + p;
        }
            break;
        case 0x20A:
        case 0x20D: case 0x20E:
        case 0x245:
        case 0x247:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0xB7C) + p;
            s1 = *(int *)(p + 0xB80) + p;
        }
            break;
        case 0x278:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3C14) + p;
            s1 = *(int *)(p + 0x3C18) + p;
        }
            break;
        case 0x218:
        case 0x246:
        case 0x279:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3C24) + p;
            s1 = *(int *)(p + 0x3C28) + p;
        }
            break;
        case 0x250: case 0x251:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1A20) + p;
            s1 = *(int *)(p + 0x1A24) + p;
        }
            break;
        case 0x260:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1A20) + p;
            s1 = *(int *)(p + 0x1A24) + p;
        }
            break;
        case 0x264:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x326C) + p;
            s1 = *(int *)(p + 0x3270) + p;
        }
            break;
        case 0x265:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3724) + p;
            s1 = *(int *)(p + 0x3728) + p;
        }
            break;
        case 0x20B:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1E3C) + p;
            s1 = *(int *)(p + 0x1E40) + p;
        }
            break;
        case 0x20C:
        case 0x24F:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1F88) + p;
            s1 = *(int *)(p + 0x1F8C) + p;
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208:
        case 0x224:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x17E8) + p;
            s1 = *(int *)(p + 0x17EC) + p;
        }
            break;
        case 0x241:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3B0C) + p;
            s1 = *(int *)(p + 0x3B10) + p;
        }
            break;
        case 0x209:
        case 0x21F:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x346C) + p;
            s1 = *(int *)(p + 0x3470) + p;
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1D58) + p;
            s1 = *(int *)(p + 0x1D5C) + p;
        }
            break;
        case 0x223:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x2ED4) + p;
            s1 = *(int *)(p + 0x2ED8) + p;
        }
            break;
        case 0x275: case 0x276:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x23B0) + p;
            s1 = *(int *)(p + 0x23B4) + p;
        }
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F:
        case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E:
        case 0x252:
        case 0x25A:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x13C0) + p;
            s1 = *(int *)(p + 0x13C4) + p;
        }
            break;
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        func_002A8578(s3, s2, s1, 0xA, 0.0f, nb, 0);
        *(float *)(s3 + 0x600) = 10.0f;
        *(unsigned char *)(s3 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
    {
        float v = *(float *)(s3 + 0x600);

        if (v > 0.0f) {
            *(int *)(s3 + 0x16D0) |= 0x2000;
            *(float *)(s3 + 0x600) = v - *(float *)(s3 + 0x5A8);
        }
        if (moveMotion(s3) != 0) {
            func_0026EE40(s3, 0, 0);
            func_002705D8(s3);
        } else {
            AddScaledVecToField_100_14F9F0(s3, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        }
    }
        break;
    }
}
