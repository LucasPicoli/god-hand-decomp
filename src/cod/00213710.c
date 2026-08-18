/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int Forward30F348_31CFE0(void);
extern int moveMotion(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_002705D8(void *a0);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj293_IsByteSet_53C(void *a0);
extern unsigned char D_005FEE00[];
extern int D_00569B70;
extern unsigned char D_005864F0[];

/* sn-2.95.3-136 matched TU. */






















/* sn-2.95.3-136 matched TU. */

















__attribute__((section(".text.func_00213710")))
void func_00213710(void *a0)
{
    char *p = (char *)a0;
    int s2v, s0v;

    *(int *)(p + 0x16D0) = *(int *)(p + 0x16D0) | 0x400;
    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0: {
        int gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF;
        char *q;

        switch (*(int *)(p + 0x564)) {
        default:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xC0) + b;
                s0v = *(int *)(b + 0xC4) + b;
            }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217:
        case 0x229: case 0x22A: case 0x24B:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x660) + b;
                s0v = *(int *)(b + 0x664) + b;
            }
            break;
        case 0x242: case 0x243: case 0x244:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x35E4) + b;
                s0v = *(int *)(b + 0x35E8) + b;
            }
            break;
        case 0x256: case 0x27E:
            if ((*(int *)(p + 0x16D4) & 0x4000000) != 0) {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x25F4) + b;
                s0v = *(int *)(b + 0x25F8) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x25EC) + b;
                s0v = *(int *)(b + 0x25F0) + b;
            }
            break;
        case 0x214: case 0x215:
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24E: case 0x252: case 0x25A:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x10C0) + b;
                s0v = *(int *)(b + 0x10C4) + b;
            }
            break;
        case 0x225: case 0x24D:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3CA0) + b;
                s0v = *(int *)(b + 0x3CA4) + b;
            }
            break;
        case 0x20A: case 0x20B: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x840) + b;
                s0v = *(int *)(b + 0x844) + b;
            }
            break;
        case 0x278: case 0x279:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1FC8) + b;
                s0v = *(int *)(b + 0x1FCC) + b;
            }
            break;
        case 0x20C: case 0x24F:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1EC4) + b;
                s0v = *(int *)(b + 0x1EC8) + b;
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1578) + b;
                s0v = *(int *)(b + 0x157C) + b;
            }
            break;
        case 0x241:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3A18) + b;
                s0v = *(int *)(b + 0x3A1C) + b;
            }
            break;
        case 0x209: case 0x21F:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3430) + b;
                s0v = *(int *)(b + 0x3434) + b;
            }
            break;
        case 0x250: case 0x251:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1908) + b;
                s0v = *(int *)(b + 0x190C) + b;
            }
            break;
        case 0x260:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3050) + b;
                s0v = *(int *)(b + 0x3054) + b;
            }
            break;
        case 0x264:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3274) + b;
                s0v = *(int *)(b + 0x3278) + b;
            }
            break;
        case 0x265:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3734) + b;
                if (64.0f < *(float *)(p + 0x618) && (Forward30F348_31CFE0() & 1) != 0) {
                    int c = *(int *)(p + 0x304);
                    int t = *(int *)(p + 0x744);
                    s0v = *(int *)(c + 0x373C) + c;
                    if (t != 0) {
                        ForwardAnimParamPairByIndex_27EA50(t, 5);
                    }
                } else {
                    int c = *(int *)(p + 0x304);
                    int t = *(int *)(p + 0x744);
                    s0v = *(int *)(c + 0x3738) + c;
                    if (t != 0) {
                        ForwardAnimParamPairByIndex_27EA50(t, 4);
                    }
                }
            }
            break;
        case 0x26A:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3D34) + b;
                s0v = *(int *)(b + 0x3D38) + b;
            }
            break;
        case 0x20F:
            {
                int b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(Obj0000_Get_Field_424_1595F0(p) + 6),
                                   p, 0, 0, 0, 0);
                b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xD10) + b;
                s0v = *(int *)(b + 0xD14) + b;
            }
            break;
        case 0x210: case 0x226:
            {
                int b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(Obj0000_Get_Field_424_1595F0(p) + 6),
                                   p, 0, 0, 0, 0);
                b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xD38) + b;
                s0v = *(int *)(b + 0xD3C) + b;
            }
            break;
        case 0x211:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x2454) + b;
                s0v = *(int *)(b + 0x2458) + b;
            }
            break;
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x2154) + b;
                s0v = *(int *)(b + 0x2158) + b;
            }
            break;
        case 0x220: case 0x221: case 0x222:
            {
                int b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(Obj0000_Get_Field_424_1595F0(p) + 0xA),
                                   p, 0, 0, 0, 0);
                b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1BD0) + b;
                s0v = *(int *)(b + 0x1BD4) + b;
            }
            break;
        case 0x223:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x2D54) + b;
                s0v = *(int *)(b + 0x2D58) + b;
            }
            break;
        case 0x275: case 0x276:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x228C) + b;
                s0v = *(int *)(b + 0x2290) + b;
            }
            break;
        }
        q = *(char **)(p + 0x6EC);
        if (q != 0) {
            int b = *(int *)(p + 0x304);
            s2v = *(int *)(b + 0x4B8) + b;
            s0v = *(int *)(b + 0x4BC) + b;
            if (*(unsigned short *)(q + 0x2FE) == 0x3B7) {
                s2v = *(int *)(b + 0x4F4) + b;
                s0v = *(int *)(b + 0x4F8) + b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x64, p, 0, 0, 0, 0);
            }
        }
        func_002A8578(p, s2v, s0v, 0.0f, 10, gb, 0);
        *(int *)(p + 0x5F0) = 0x5A;
        *(int *)(p + 0x5F4) = (int)((unsigned int)Forward30F348_31CFE0() % 60) + 0x78;
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    }
    case 1: {
        float one = 1.0f;
        float lim = 16.0f;
        int w;

        AddScaledDeltaToField_104_2A7498(p, (int)(p + 0x16A0),
                                         *(float *)(p + 0x5A8) * 0.2617994f);
        moveMotion(p);
        AddScaledVecToField_100_14F9F0(p, one);
        AddScaledXfmVecToField_F0_14F928(p, one);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            if (*(unsigned int *)(p + 0x16D8) == 0) {
                lim = 2.25f;
            }
            break;
        case 2:
            if (*(unsigned int *)(p + 0x16D8) < 2) {
                lim = 2.25f;
            }
            break;
        case 3:
            if (*(unsigned int *)(p + 0x16D8) < 3) {
                lim = 2.25f;
            }
            break;
        case 4:
            if (*(unsigned int *)(p + 0x16D8) < 3) {
                lim = 2.25f;
            }
            break;
        case 5:
            if (*(unsigned int *)(p + 0x16D8) < 3) {
                lim = 2.25f;
            }
            break;
        }
        if (*(unsigned int *)(p + 0x16D8) >= 3) {
            lim = 49.0f;
        }
        if (*(unsigned int *)(p + 0x16D8) >= 6) {
            lim = 121.0f;
        }
        w = *(int *)(p + 0x564);
        switch (w) {
        case 0x264:
            lim = 1.0f;
            if (*(float *)(p + 0x75C) < 0.34906584f) {
                lim = 9.0f;
            }
            break;
        case 0x265:
            lim = 1.0f;
            break;
        }
        if (*(float *)(p + 0x618) < lim) {
            func_002705D8(p);
        }
        if (*(int *)(p + 0x5F0) != 0) {
            *(int *)(p + 0x5F0) = *(int *)(p + 0x5F0) - 1;
        } else {
            switch (*(int *)(p + 0x564)) {
            case 0x20A: case 0x245: case 0x250: case 0x278: case 0x279:
                *(char *)(p + 0x2F4) = 0;
                *(char *)(p + 0x2F5) = 0x66;
                *(char *)(p + 0x2F6) = 0;
                *(char *)(p + 0x2F7) = 0;
                break;
            default:
                break;
            }
        }
        switch (*(int *)(p + 0x564)) {
        case 0x20F: case 0x210: case 0x211:
        case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            if (*(int *)(p + 0x5F4) != 0) {
                *(int *)(p + 0x5F4) = *(int *)(p + 0x5F4) - 1;
            } else {
                *(int *)(p + 0x5F4) =
                    (int)((unsigned int)Forward30F348_31CFE0() % 60) + 0x78;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(Obj0000_Get_Field_424_1595F0(p) + 6),
                                   p, 0, 0, 0, 0);
            }
        case 0x220: case 0x221: case 0x222:
            if (*(int *)(p + 0x5F4) != 0) {
                *(int *)(p + 0x5F4) = *(int *)(p + 0x5F4) - 1;
            } else {
                *(int *)(p + 0x5F4) =
                    (int)((unsigned int)Forward30F348_31CFE0() % 60) + 0x78;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(Obj0000_Get_Field_424_1595F0(p) + 0xA),
                                   p, 0, 0, 0, 0);
            }
            break;
        default:
            break;
        }
        break;
    }
    }
    if (*(short *)(Obj0000_Get_D_00747A94_2DB6B0() + 0x54A) <= 0
        || D_005864F0[0x5B5] != 0
        || Obj293_IsByteSet_53C(D_005864F0) != 0) {
        func_002705D8(p);
    } else if (func_00262AA8(p) == 0 && func_0024BB68(p) == 0) {
        func_0024BDA0(p);
    }
}
