/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern int cCoreSave_getGameLevel(void *a0);
extern int Obj0000_Get_Byte_2F4_EQ_1_10B5B8(void *a0);
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_002147D0")))
void func_002147D0(void *a0)
{
    char *p = (char *)a0;
    void *g;
    int s1v;
    int a1v, a2v;
    int bs;
    int gb;

    g = Obj0000_Get_D_00747A94_2DB6B0();
    *(int *)(p + 0x16D0) = *(int *)(p + 0x16D0) | 0x400;
    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0:
        s1v = *(unsigned char *)(p + 0x2F7);
        if (s1v == 2) {
            s1v = Forward30F348_31CFE0() & 1;
        }
        if (*(unsigned char *)(p + 0x17C3) != 0) {
            s1v = s1v ^ 1;
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF;
        switch (*(int *)(p + 0x564)) {
        default:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0xD4) + b;
                a2v = *(int *)(b + 0xD8) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0xCC) + b;
                a2v = *(int *)(b + 0xD0) + b;
                bs = b;
            }
        }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x229:
        case 0x22A: case 0x24B: case 0x256: case 0x27E:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x674) + b;
                a2v = *(int *)(b + 0x678) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x66C) + b;
                a2v = *(int *)(b + 0x670) + b;
                bs = b;
            }
        }
            break;
        case 0x242: case 0x243: case 0x244:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x35F4) + b;
                a2v = *(int *)(b + 0x35F8) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x35EC) + b;
                a2v = *(int *)(b + 0x35F0) + b;
                bs = b;
            }
        }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C: case 0x21D:
        case 0x21E: case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248:
        case 0x249: case 0x24C: case 0x24E: case 0x252: case 0x25A:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x10EC) + b;
                a2v = *(int *)(b + 0x10F0) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x10E4) + b;
                a2v = *(int *)(b + 0x10E8) + b;
                bs = b;
            }
        }
            break;
        case 0x225: case 0x24D:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3CB0) + b;
                a2v = *(int *)(b + 0x3CB4) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3CA8) + b;
                a2v = *(int *)(b + 0x3CAC) + b;
                bs = b;
            }
        }
            break;
        case 0x20A: case 0x20B: case 0x20D: case 0x20E: case 0x218: case 0x245:
        case 0x246: case 0x247:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x854) + b;
                a2v = *(int *)(b + 0x858) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x84C) + b;
                a2v = *(int *)(b + 0x850) + b;
                bs = b;
            }
        }
            break;
        case 0x20C: case 0x24F:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1ED8) + b;
                a2v = *(int *)(b + 0x1EDC) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1ED0) + b;
                a2v = *(int *)(b + 0x1ED4) + b;
                bs = b;
            }
        }
            break;
        case 0x278:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1FDC) + b;
                a2v = *(int *)(b + 0x1FE0) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1FD4) + b;
                a2v = *(int *)(b + 0x1FD8) + b;
                bs = b;
            }
        }
            break;
        case 0x279:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1FFC) + b;
                a2v = *(int *)(b + 0x2000) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1FF4) + b;
                a2v = *(int *)(b + 0x1FF8) + b;
                bs = b;
            }
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x158C) + b;
                a2v = *(int *)(b + 0x1590) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1584) + b;
                a2v = *(int *)(b + 0x1588) + b;
                bs = b;
            }
        }
            break;
        case 0x241:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3A28) + b;
                a2v = *(int *)(b + 0x3A2C) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3A20) + b;
                a2v = *(int *)(b + 0x3A24) + b;
                bs = b;
            }
        }
            break;
        case 0x209: case 0x21F:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x343C) + b;
                a2v = *(int *)(b + 0x3440) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3444) + b;
                a2v = *(int *)(b + 0x3448) + b;
                bs = b;
            }
        }
            break;
        case 0x250: case 0x251:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x191C) + b;
                a2v = *(int *)(b + 0x1920) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1914) + b;
                a2v = *(int *)(b + 0x1918) + b;
                bs = b;
            }
        }
            break;
        case 0x260:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3060) + b;
                a2v = *(int *)(b + 0x3064) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3058) + b;
                a2v = *(int *)(b + 0x305C) + b;
                bs = b;
            }
        }
            break;
        case 0x264:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x326C) + b;
                a2v = *(int *)(b + 0x3270) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x326C) + b;
                a2v = *(int *)(b + 0x3270) + b;
                bs = b;
            }
        }
            break;
        case 0x265:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3724) + b;
                a2v = *(int *)(b + 0x3728) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x3724) + b;
                a2v = *(int *)(b + 0x3728) + b;
                bs = b;
            }
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0xD20) + b;
                a2v = *(int *)(b + 0xD24) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0xD18) + b;
                a2v = *(int *)(b + 0xD1C) + b;
                bs = b;
            }
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1BE0) + b;
                a2v = *(int *)(b + 0x1BE4) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x1BD8) + b;
                a2v = *(int *)(b + 0x1BDC) + b;
                bs = b;
            }
        }
            break;
        case 0x223:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x2D38) + b;
                a2v = *(int *)(b + 0x2D3C) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x2D38) + b;
                a2v = *(int *)(b + 0x2D3C) + b;
                bs = b;
            }
        }
            break;
        case 0x275: case 0x276:
        {
            if (s1v != 0) {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x229C) + b;
                a2v = *(int *)(b + 0x22A0) + b;
                bs = b;
            } else {
                int b = *(int *)(p + 0x304);
                a1v = *(int *)(b + 0x2294) + b;
                a2v = *(int *)(b + 0x2298) + b;
                bs = b;
            }
        }
            break;
        }
        if (*(int *)(p + 0x6EC) != 0) {
            if (s1v != 0) {
                a1v = *(int *)(bs + 0x46C) + bs;
                a2v = *(int *)(bs + 0x470) + bs;
            } else {
                a1v = *(int *)(bs + 0x464) + bs;
                a2v = *(int *)(bs + 0x468) + bs;
            }
        }
        func_002A8578(p, a1v, a2v, 0.0f, 0xA, gb, 0);
        *(float *)(p + 0x600) = 90.0f;
        *(float *)(p + 0x604) = 90.0f;
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    case 1:
        {
            char *q = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(p, *(int *)(q + 0xF0),
                                            *(float *)(p + 0x5A8) * 0.0981747732f);
        }
        if (moveMotion(p) != 0 && *(unsigned char *)(p + 0x2F7) != 2) {
            func_002705D8(p);
        }
        AddScaledVecToField_100_14F9F0(p, 1.0f);
        AddScaledXfmVecToField_F0_14F928(p, 1.0f);
    }
    switch (*(int *)(p + 0x564)) {
    default:
    {
        int fl = 1;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            if (*(unsigned int *)(p + 0x16D8) != 0) {
                fl = 0;
            }
            break;
        case 2:
            if (*(unsigned int *)(p + 0x16D8) >= 2) {
                fl = 0;
            }
            break;
        case 3:
            if (*(unsigned int *)(p + 0x16D8) >= 3) {
                fl = 0;
            }
            break;
        case 4:
            if (*(unsigned int *)(p + 0x16D8) >= 3) {
                fl = 0;
            }
            break;
        case 5:
            if (*(unsigned int *)(p + 0x16D8) >= 0x64) {
                fl = 0;
            }
            break;
        }
        if (fl != 0) {
            func_00262AA8(p);
        }
    }
        break;
    case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C: case 0x21D:
    case 0x21E: case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x22F:
    case 0x248: case 0x249: case 0x24C: case 0x24D: case 0x24E: case 0x252:
    case 0x25A:
        break;
    case 0x279:
        if (36.0f < *(float *)(p + 0x618)) {
            *(int *)(p + 0x600) = 0;
            *(int *)(p + 0x604) = 0;
        }
        if (0.0f < *(float *)(p + 0x600)) {
            *(float *)(p + 0x600) = *(float *)(p + 0x600) - *(float *)(p + 0x5A8);
        } else if (Obj0000_Get_Byte_2F4_EQ_1_10B5B8(g) != 0 || func_00262AA8(p) == 0) {
            if (0.0f < *(float *)(p + 0x604)) {
                *(float *)(p + 0x604) = *(float *)(p + 0x604) - *(float *)(p + 0x5A8);
            } else {
                func_002705D8(p);
            }
        }
        break;
    }
}
