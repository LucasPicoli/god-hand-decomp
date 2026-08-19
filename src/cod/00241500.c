/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern char *D_00586A58;
extern char *D_00586A5C;

/* sn-2.95.3-136 matched TU. */










__attribute__((section(".text.func_00241500")))
void func_00241500(void *a0)
{
    char *p = (char *)a0;
    char *q = 0;
    int s1v, s0v;

    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0: {
        int gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF;

        switch (*(int *)(p + 0x564)) {
        default:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x98) + b;
                s0v = *(int *)(b + 0x9C) + b;
            }
            break;

        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217:
        case 0x229: case 0x22A: case 0x24B:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x648) + b;
                s0v = *(int *)(b + 0x64C) + b;
            }
            break;

        case 0x242: case 0x243: case 0x244:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x35CC) + b;
                s0v = *(int *)(b + 0x35D0) + b;
            }
            break;

        case 0x256: case 0x27E:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x25AC) + b;
                s0v = *(int *)(b + 0x25B0) + b;
            }
            break;

        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C: case 0x21D:
        case 0x21E: case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248:
        case 0x249: case 0x24C: case 0x24E: case 0x25A:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x10A8) + b;
                s0v = *(int *)(b + 0x10AC) + b;
            }
            break;

        case 0x225: case 0x24D:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x3C88) + b;
                s0v = *(int *)(b + 0x3C8C) + b;
            }
            break;

        case 0x252:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x24EC) + b;
                s0v = *(int *)(b + 0x24F0) + b;
            }
            break;

        case 0x20A: case 0x20B: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x828) + b;
                s0v = *(int *)(b + 0x82C) + b;
            }
            break;

        case 0x278: case 0x279:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1FB0) + b;
                s0v = *(int *)(b + 0x1FB4) + b;
            }
            break;

        case 0x20C: case 0x24F:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1EAC) + b;
                s0v = *(int *)(b + 0x1EB0) + b;
            }
            break;

        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1560) + b;
                s0v = *(int *)(b + 0x1564) + b;
            }
            break;

        case 0x241:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x3A00) + b;
                s0v = *(int *)(b + 0x3A04) + b;
            }
            break;

        case 0x209: case 0x21F:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x3418) + b;
                s0v = *(int *)(b + 0x341C) + b;
            }
            break;

        case 0x250: case 0x251:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x18F0) + b;
                s0v = *(int *)(b + 0x18F4) + b;
            }
            break;

        case 0x260:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x3038) + b;
                s0v = *(int *)(b + 0x303C) + b;
            }
            break;

        case 0x264:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x326C) + b;
                s0v = *(int *)(b + 0x3270) + b;
            }
            break;

        case 0x265:
            {
                int b = *(int *)(p + 0x304);
                int h = *(int *)(p + 0x744);
                s1v = *(int *)(b + 0x3724) + b;
                s0v = *(int *)(b + 0x3728) + b;
                if (h != 0) {
                    ForwardAnimParamPairByIndex_27EA50(h, 0);
                }
            }
            break;

        case 0x20F: case 0x210: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0xCF8) + b;
                s0v = *(int *)(b + 0xCFC) + b;
            }
            break;

        case 0x211:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x244C) + b;
                s0v = *(int *)(b + 0x2450) + b;
            }
            break;

        case 0x220: case 0x221: case 0x222:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1BC0) + b;
                s0v = *(int *)(b + 0x1BC4) + b;
            }
            break;

        case 0x223:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x2D38) + b;
                s0v = *(int *)(b + 0x2D3C) + b;
            }
            break;

        case 0x275: case 0x276:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x2274) + b;
                s0v = *(int *)(b + 0x2278) + b;
            }
            break;
        }
        func_002A8578(p, s1v, s0v, 0.0f, 0xA, gb, 0);
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    }
    case 1:
        *(int *)(p + 0x16D0) = *(int *)(p + 0x16D0) | 0x10000;
        *(int *)(p + 0x16D0) = *(int *)(p + 0x16D0) | 0x20000;
        *(char *)(p + 0x617) = 1;
        *(float *)(p + 0x54C) = 3.0f;
        moveMotion(p);
        AddScaledVecToField_100_14F9F0(p, 1.0f);
        AddScaledXfmVecToField_F0_14F928(p, 1.0f);
        {
            int bit = *(int *)(p + 0x16D0) & 0x20000000;
            int flg = bit != 0;

            switch (*(int *)(p + 0x564)) {
            default:
                break;
            case 0x208:
                q = D_00586A5C;
                break;
            case 0x21C:
                q = D_00586A58;
                break;
            }
            if (q != 0) {
                if (*(short *)(q + 0x54A) <= 0) {
                    flg = 1;
                }
            } else {
                flg = 1;
            }
            if (flg != 0) {
                *(unsigned char *)(p + 0x2F6) = 2;
            }
        }
        break;

    case 2:
        *(float *)(p + 0x600) = 60.0f;
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    case 3:
        *(int *)(p + 0x16D0) = *(int *)(p + 0x16D0) | 0x10000;
        *(int *)(p + 0x16D0) = *(int *)(p + 0x16D0) | 0x20000;
        *(char *)(p + 0x617) = 1;
        *(float *)(p + 0x54C) = 3.0f;
        moveMotion(p);
        AddScaledVecToField_100_14F9F0(p, 1.0f);
        AddScaledXfmVecToField_F0_14F928(p, 1.0f);
        {
            float d = *(float *)(p + 0x600) - *(float *)(p + 0x5A8);

            *(float *)(p + 0x600) = d;
            if (d <= 0.0f) {
                float *src = *(float **)(p + 0xF0);
                float *dst = (float *)(p + 0x6D0);

                if (dst != src) {
                    dst[0] = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                }
                *(char *)(p + 0x2F5) = 0x75;
                *(float *)(p + 0x6E0) = *(float *)(p + 0x104);
                *(char *)(p + 0x2F4) = 0;
                *(char *)(p + 0x2F6) = 0;
                *(char *)(p + 0x2F7) = 0;
            }
        }
        break;
    }
}
