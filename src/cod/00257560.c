/* sn-2.95.3-136 matched TU. */

extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Forward30F348_31CFE0(void);
extern void Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0(int a0, int a1);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002726F8(void *a0);
extern int cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern int moveMotion(void *a0);
extern void func_00274FE8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */

















__attribute__((section(".text.func_00257560")))
void func_00257560(void *a0)
{
    char *s2 = (char *)a0;
    void *s4;
    int p;
    int s1v;
    int s0v;
    int c17c1;
    int lim548;

    p = *(int *)(s2 + 0x214);
    s4 = (*(void *(**)(void *))(p + 0xB4))(s2 + *(short *)(p + 0xB0));
    *(float *)(s2 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s2 + 0x2F6)) {
    case 0: {
        int s3;

        ReleaseField6ECByTag564_26B1E8(s2);
        s3 = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        switch (*(int *)(s2 + 0x564)) {
        default:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x340) + b;
                s0v = *(int *)(b + 0x344) + b;
            } else {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x338) + b;
                s0v = *(int *)(b + 0x33C) + b;
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x250: case 0x251: case 0x278: case 0x279:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0xACC) + b;
                s0v = *(int *)(b + 0xAD0) + b;
            } else {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0xAD4) + b;
                s0v = *(int *)(b + 0xAD8) + b;
            }
            break;
        case 0x260:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x31A4) + b;
                s0v = *(int *)(b + 0x31A8) + b;
            } else {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x31A4) + b;
                s0v = *(int *)(b + 0x31A8) + b;
            }
            break;
        case 0x264: {
            int b = *(int *)(s2 + 0x304);
            int t = *(int *)(s2 + 0x740);

            s1v = *(int *)(b + 0x33B0) + b;
            s0v = *(int *)(b + 0x33B4) + b;
            if (t != 0) {
                Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0(t, 0);
            }
            break;
        }
        case 0x265: {
            int b = *(int *)(s2 + 0x304);

            s1v = *(int *)(b + 0x3988) + b;
            s0v = *(int *)(b + 0x398C) + b;
            break;
        }
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        case 0x241:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x1768) + b;
                s0v = *(int *)(b + 0x176C) + b;
            } else {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x1760) + b;
                s0v = *(int *)(b + 0x1764) + b;
            }
            break;
        case 0x209: case 0x21F:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x1768) + b;
                s0v = *(int *)(b + 0x176C) + b;
            } else {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x1760) + b;
                s0v = *(int *)(b + 0x1764) + b;
            }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270:
        case 0x271: case 0x272: case 0x273: case 0x274:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0xF0C) + b;
                s0v = *(int *)(b + 0xF10) + b;
            } else {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0xF14) + b;
                s0v = *(int *)(b + 0xF18) + b;
            }
            break;
        case 0x220: case 0x221: case 0x222: {
            int b = *(int *)(s2 + 0x304);

            s1v = *(int *)(b + 0x1D08) + b;
            s0v = *(int *)(b + 0x1D0C) + b;
            break;
        }
        case 0x223: {
            int b = *(int *)(s2 + 0x304);

            s1v = *(int *)(b + 0x2E4C) + b;
            s0v = *(int *)(b + 0x2E50) + b;
            break;
        }
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x22F:
        case 0x248: case 0x249: case 0x24C: case 0x24D: case 0x24E:
        case 0x252: case 0x25A:
            if (Forward30F348_31CFE0() & 1) {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x1340) + b;
                s0v = *(int *)(b + 0x1344) + b;
            } else {
                int b = *(int *)(s2 + 0x304);
                s1v = *(int *)(b + 0x1338) + b;
                s0v = *(int *)(b + 0x133C) + b;
            }
            break;
        }
        func_002A8578(s2, s1v, s0v, 0.0f, 5, s3, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                           (short)Obj0000_Get_Field_424_1595F0(s2),
                           s2, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x112, s2, 0, 0, 0, 0);
        c17c1 = *(unsigned char *)(s2 + 0x17C1);
        if (c17c1 == 0) {
            lim548 = *(short *)(s2 + 0x548);
            if (c17c1 >= lim548) {
                *(short *)(s2 + 0x54A) = *(unsigned short *)(s2 + 0x548);
            } else {
                *(short *)(s2 + 0x54A) = 0;
            }
        }
        if (*(short *)(s2 + 0x54A) <= 0) {
            func_002726F8(s2);
            if (*(short *)(s2 + 0x54A) <= 0) {
                cDamageUnit_SetDamageCollActive(s4, 0);
            }
        }
        *(unsigned char *)(s2 + 0x2F6) = *(unsigned char *)(s2 + 0x2F6) + 1;
    }
    case 1: {
        float one;

        *(float *)(s2 + 0x54C) = 3.0f;
        *(unsigned short *)(s2 + 0x434) = *(unsigned short *)(s2 + 0x434) | 8;
        if (moveMotion(s2) != 0) {
            if (*(short *)(s2 + 0x54A) <= 0) {
                if (*(int *)(s2 + 0x1644) & 0x800000) {
                    *(unsigned char *)(s2 + 0x2F4) = 2;
                    *(unsigned char *)(s2 + 0x2F5) = 3;
                    *(unsigned char *)(s2 + 0x2F6) = 0;
                    *(unsigned char *)(s2 + 0x2F7) = 0;
                } else {
                    func_0025FE30(s2, 0x1000000, 0);
                    *(unsigned char *)(s2 + 0x2F4) = 2;
                    *(unsigned char *)(s2 + 0x2F5) = 2;
                    *(unsigned char *)(s2 + 0x2F6) = 0;
                    *(unsigned char *)(s2 + 0x2F7) = 0;
                }
            } else {
                func_00274FE8(s2);
            }
        } else {
            one = 1.0f;
            AddScaledVecToField_100_14F9F0(s2, one);
            AddScaledXfmVecToField_F0_14F928(s2, one);
        }
        break;
    }
    }
}
