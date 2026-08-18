/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Forward30F348_31CFE0(void);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_0026F328(void *a0);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A74E0(void *a0, void *a1, int a2);
extern int func_002919F8(void *a0, void *a1, float f12);
extern int func_00291AC8(void *a0, void *a1, void *a2, float f12);
extern void func_002736F8(int a0);
extern char D_00462FC0[];
extern unsigned short D_00747A50;
extern char D_007474A0[];
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */























__attribute__((section(".text.func_0020FBB8")))
void func_0020FBB8(void *a0)
{
    char *s1 = (char *)a0;
    int s2v, s0v;
    int gb;
    float fv;
    int p2, p1;
    int flag6;
    int old, nw;

    fv = 0.0f;
    p2 = 1;
    p1 = 0x4E2;
    flag6 = 0;
    old = *(int *)(s1 + 0x16D0);
    nw = old | 0x400;
    *(int *)(s1 + 0x16D0) = nw;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x8000;
    switch (*(unsigned char *)(s1 + 0x1650)) {
    default:
    case 0x0:
        switch (*(int *)(s1 + 0x564)) {
        default:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x98) + b;
            s0v = *(int *)(b + 0x9C) + b;
        }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x229:
        case 0x22A: case 0x24B:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x648) + b;
            s0v = *(int *)(b + 0x9C) + b;
        }
            break;
        case 0x242: case 0x243: case 0x244:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x35CC) + b;
            s0v = *(int *)(b + 0x35D0) + b;
        }
            break;
        case 0x256: case 0x27E:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x25AC) + b;
            s0v = *(int *)(b + 0x25B0) + b;
        }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C: case 0x21D:
        case 0x21E: case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248:
        case 0x249: case 0x24C: case 0x24E: case 0x25A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x10A8) + b;
            s0v = *(int *)(b + 0x10AC) + b;
        }
            break;
        case 0x225: case 0x24D:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3C88) + b;
            s0v = *(int *)(b + 0x3C8C) + b;
        }
            break;
        case 0x252:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x24EC) + b;
            s0v = *(int *)(b + 0x24F0) + b;
        }
            break;
        case 0x20A: case 0x20B: case 0x20D: case 0x20E: case 0x245: case 0x246:
        case 0x247:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x828) + b;
            s0v = *(int *)(b + 0x82C) + b;
        }
            break;
        case 0x278: case 0x279:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1FB0) + b;
            s0v = *(int *)(b + 0x1FB4) + b;
        }
            break;
        case 0x218:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3BB4) + b;
            s0v = *(int *)(b + 0x3BB8) + b;
        }
            break;
        case 0x250: case 0x251:
        {
            if (D_00747A50 == 0x504) {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1A48) + b;
                s0v = *(int *)(b + 0x1A4C) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18F0) + b;
                s0v = *(int *)(b + 0x18F4) + b;
            }
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3038) + b;
            s0v = *(int *)(b + 0x303C) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x326C) + b;
            s0v = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s1 + 0x304);
            int h = *(int *)(s1 + 0x744);
            s2v = *(int *)(b + 0x3724) + b;
            s0v = *(int *)(b + 0x3728) + b;
            if (h != 0) {
                ForwardAnimParamPairByIndex_27EA50(h, 0);
            }
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3D34) + b;
            s0v = *(int *)(b + 0x3D38) + b;
        }
            break;
        case 0x20C: case 0x24F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1EAC) + b;
            s0v = *(int *)(b + 0x1EB0) + b;
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1560) + b;
            s0v = *(int *)(b + 0x1564) + b;
        }
            break;
        case 0x241:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3A00) + b;
            s0v = *(int *)(b + 0x3A04) + b;
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3418) + b;
            s0v = *(int *)(b + 0x341C) + b;
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
        {
            if (*(int *)(s1 + 0x1644) & 0x200000) {
                int b = *(int *)(s1 + 0x304);
                s0v = *(int *)(b + 0xFBC) + b;
                s2v = s0v;
            } else {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xCF8) + b;
                s0v = *(int *)(b + 0xCFC) + b;
            }
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1BC0) + b;
            s0v = *(int *)(b + 0x1BC4) + b;
        }
            break;
        case 0x275: case 0x276:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x2274) + b;
            s0v = *(int *)(b + 0x2278) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x2D38) + b;
            s0v = *(int *)(b + 0x2D3C) + b;
        }
            break;
        }
        break;
    case 0x18:
        switch (*(unsigned short *)(s1 + 0x640) & 7) {
        default:
        case 0:
            fv = 7.0f;
            break;
        case 1:
            fv = 6.0f;
            break;
        case 2:
            fv = 5.0f;
            break;
        case 3:
            fv = 4.0f;
            break;
        case 4:
            fv = 3.0f;
            break;
        case 5:
            fv = 2.0f;
            break;
        case 6:
            fv = 1.0f;
            break;
        case 7:
            fv = 0.0f;
            break;
        }
        switch (*(int *)(s1 + 0x564)) {
        default:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3F4) + b;
            s0v = *(int *)(b + 0x3F8) + b;
        }
            break;
        case 0x202: case 0x203: case 0x213: case 0x214: case 0x215: case 0x216:
        case 0x217: case 0x229: case 0x22A: case 0x242: case 0x243: case 0x244:
        case 0x24B:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3F4) + b;
            s0v = *(int *)(b + 0x3F8) + b;
        }
            break;
        case 0x256: case 0x27E:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3F4) + b;
            s0v = *(int *)(b + 0x3F8) + b;
        }
            break;
        case 0x21A: case 0x21C: case 0x21D: case 0x21E: case 0x22C: case 0x22E:
        case 0x22F: case 0x248: case 0x249: case 0x24C: case 0x24E: case 0x252:
        case 0x25A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x13F8) + b;
            s0v = *(int *)(b + 0x13FC) + b;
        }
            break;
        case 0x21B: case 0x22D:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1448) + b;
            s0v = *(int *)(b + 0x144C) + b;
        }
            break;
        case 0x225: case 0x24D:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1450) + b;
            s0v = *(int *)(b + 0x1454) + b;
        }
            break;
        case 0x20A: case 0x20B: case 0x20D: case 0x20E: case 0x218: case 0x245:
        case 0x246: case 0x247:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xBCC) + b;
            s0v = *(int *)(b + 0xBD0) + b;
        }
            break;
        case 0x278: case 0x279:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xBCC) + b;
            s0v = *(int *)(b + 0xBD4) + b;
        }
            break;
        case 0x250: case 0x251:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xBCC) + b;
            s0v = *(int *)(b + 0xBD0) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3038) + b;
            s0v = *(int *)(b + 0x303C) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x326C) + b;
            s0v = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s1 + 0x304);
            int h = *(int *)(s1 + 0x744);
            s2v = *(int *)(b + 0x3724) + b;
            s0v = *(int *)(b + 0x3728) + b;
            if (h != 0) {
                ForwardAnimParamPairByIndex_27EA50(h, 0);
            }
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3D34) + b;
            s0v = *(int *)(b + 0x3D38) + b;
        }
            break;
        case 0x20C: case 0x24F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xBCC) + b;
            s0v = *(int *)(b + 0xBD0) + b;
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1560) + b;
            s0v = *(int *)(b + 0x1564) + b;
        }
            break;
        case 0x241:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3A00) + b;
            s0v = *(int *)(b + 0x3A04) + b;
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3418) + b;
            s0v = *(int *)(b + 0x341C) + b;
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
        {
            if (*(int *)(s1 + 0x1644) & 0x200000) {
                int b = *(int *)(s1 + 0x304);
                s0v = *(int *)(b + 0xFBC) + b;
                s2v = s0v;
            } else {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xCF8) + b;
                s0v = *(int *)(b + 0xCFC) + b;
            }
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1BC0) + b;
            s0v = *(int *)(b + 0x1BC4) + b;
        }
            break;
        case 0x275: case 0x276:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3F4) + b;
            s0v = *(int *)(b + 0x3F8) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x2D38) + b;
            s0v = *(int *)(b + 0x2D3C) + b;
        }
            break;
        }
        break;
    case 0x19:
        switch (*(unsigned short *)(s1 + 0x640) & 7) {
        default:
        case 0:
            fv = 0.0f;
            break;
        case 1:
            fv = 30.0f;
            break;
        case 2:
            fv = 15.0f;
            break;
        case 3:
            fv = 45.0f;
            break;
        case 4:
            fv = 10.0f;
            break;
        case 5:
            fv = 40.0f;
            break;
        case 6:
            fv = 5.0f;
            break;
        case 7:
            fv = 25.0f;
            break;
        }
        switch (*(int *)(s1 + 0x564)) {
        default:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x43C) + b;
            s0v = *(int *)(b + 0x440) + b;
        }
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1458) + b;
            s0v = *(int *)(b + 0x145C) + b;
        }
            break;
        case 0x20A: case 0x20B: case 0x20D: case 0x20E: case 0x218: case 0x245:
        case 0x246: case 0x247: case 0x278: case 0x279:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xBF8) + b;
            s0v = *(int *)(b + 0xBFC) + b;
        }
            break;
        case 0x250: case 0x251:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xB84) + b;
            s0v = *(int *)(b + 0xB88) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3038) + b;
            s0v = *(int *)(b + 0x303C) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x326C) + b;
            s0v = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s1 + 0x304);
            int h = *(int *)(s1 + 0x744);
            s2v = *(int *)(b + 0x3724) + b;
            s0v = *(int *)(b + 0x3728) + b;
            if (h != 0) {
                ForwardAnimParamPairByIndex_27EA50(h, 0);
            }
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3D34) + b;
            s0v = *(int *)(b + 0x3D38) + b;
        }
            break;
        case 0x20C: case 0x24F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xB84) + b;
            s0v = *(int *)(b + 0xB88) + b;
        }
            break;
        case 0x205: case 0x207:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x17F8) + b;
            s0v = *(int *)(b + 0x17FC) + b;
        }
            break;
        case 0x224:
        {
            int t = Forward30F348_31CFE0();
            if (t & 1) {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18DC) + b;
                s0v = *(int *)(b + 0x18E0) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18E4) + b;
                s0v = *(int *)(b + 0x18E8) + b;
            }
        }
            break;
        case 0x241:
        {
            int t = Forward30F348_31CFE0();
            if (t & 1) {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3B1C) + b;
                s0v = *(int *)(b + 0x3B20) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3B24) + b;
                s0v = *(int *)(b + 0x3B28) + b;
            }
        }
            break;
        case 0x206:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1890) + b;
            s0v = *(int *)(b + 0x1894) + b;
        }
            break;
        case 0x208:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1EA0) + b;
            s0v = *(int *)(b + 0x1EA4) + b;
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3418) + b;
            s0v = *(int *)(b + 0x341C) + b;
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xF94) + b;
            s0v = *(int *)(b + 0xF98) + b;
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1BC0) + b;
            s0v = *(int *)(b + 0x1BC4) + b;
        }
            break;
        case 0x275: case 0x276:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3F4) + b;
            s0v = *(int *)(b + 0x3F8) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x2D38) + b;
            s0v = *(int *)(b + 0x2D3C) + b;
        }
            break;
        }
        break;
    case 0x4:
        switch (*(int *)(s1 + 0x564)) {
        default:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x40C) + b;
            s0v = *(int *)(b + 0x410) + b;
        }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x229:
        case 0x22A: case 0x242: case 0x243: case 0x244: case 0x24B: case 0x256:
        case 0x27E:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x40C) + b;
            s0v = *(int *)(b + 0x410) + b;
        }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C: case 0x21D:
        case 0x21E: case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x22F:
        case 0x248: case 0x249: case 0x24C: case 0x24D: case 0x24E: case 0x252:
        case 0x25A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1418) + b;
            s0v = *(int *)(b + 0x141C) + b;
        }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x40C) + b;
            s0v = *(int *)(b + 0x410) + b;
        }
            break;
        case 0x250: case 0x251:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x18F0) + b;
            s0v = *(int *)(b + 0x18F4) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3038) + b;
            s0v = *(int *)(b + 0x303C) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x326C) + b;
            s0v = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s1 + 0x304);
            int h = *(int *)(s1 + 0x744);
            s2v = *(int *)(b + 0x3724) + b;
            s0v = *(int *)(b + 0x3728) + b;
            if (h != 0) {
                ForwardAnimParamPairByIndex_27EA50(h, 0);
            }
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3D34) + b;
            s0v = *(int *)(b + 0x3D38) + b;
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1800) + b;
            s0v = *(int *)(b + 0x1804) + b;
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3418) + b;
            s0v = *(int *)(b + 0x341C) + b;
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
        {
            int b = *(int *)(s1 + 0x304);
            p1 = 0x58;
            p2 = 0x47;
            s2v = *(int *)(b + 0xFC4) + b;
            s0v = *(int *)(b + 0xFC8) + b;
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1BC0) + b;
            s0v = *(int *)(b + 0x1BC4) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x2D38) + b;
            s0v = *(int *)(b + 0x2D3C) + b;
        }
            break;
        }
        break;
    case 0x1:
        switch (*(int *)(s1 + 0x564)) {
        default:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3FC) + b;
            s0v = *(int *)(b + 0x400) + b;
        }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x229:
        case 0x22A: case 0x242: case 0x243: case 0x24B: case 0x256: case 0x27E:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3FC) + b;
            s0v = *(int *)(b + 0x400) + b;
        }
            break;
        case 0x244:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x36F8) + b;
            s0v = *(int *)(b + 0x36FC) + b;
        }
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1438) + b;
            s0v = *(int *)(b + 0x143C) + b;
        }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xBD8) + b;
            s0v = *(int *)(b + 0xBDC) + b;
        }
            break;
        case 0x250: case 0x251:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x18F0) + b;
            s0v = *(int *)(b + 0x18F4) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3038) + b;
            s0v = *(int *)(b + 0x303C) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x326C) + b;
            s0v = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s1 + 0x304);
            int h = *(int *)(s1 + 0x744);
            s2v = *(int *)(b + 0x3724) + b;
            s0v = *(int *)(b + 0x3728) + b;
            if (h != 0) {
                ForwardAnimParamPairByIndex_27EA50(h, 0);
            }
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3D34) + b;
            s0v = *(int *)(b + 0x3D38) + b;
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1810) + b;
            s0v = *(int *)(b + 0x1814) + b;
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1810) + b;
            s0v = *(int *)(b + 0x1814) + b;
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xFAC) + b;
            s0v = *(int *)(b + 0xFB0) + b;
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1BC0) + b;
            s0v = *(int *)(b + 0x1BC4) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x2D38) + b;
            s0v = *(int *)(b + 0x2D3C) + b;
        }
            break;
        }
        break;
    case 0x5:
        switch (*(int *)(s1 + 0x564)) {
        default:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x424) + b;
            s0v = *(int *)(b + 0x428) + b;
        }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x229:
        case 0x22A: case 0x242: case 0x243: case 0x24B: case 0x256: case 0x27E:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x424) + b;
            s0v = *(int *)(b + 0x428) + b;
        }
            break;
        case 0x244:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x36F8) + b;
            s0v = *(int *)(b + 0x36FC) + b;
        }
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1438) + b;
            s0v = *(int *)(b + 0x143C) + b;
        }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xBD8) + b;
            s0v = *(int *)(b + 0xBDC) + b;
        }
            break;
        case 0x250: case 0x251:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x18F0) + b;
            s0v = *(int *)(b + 0x18F4) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3038) + b;
            s0v = *(int *)(b + 0x303C) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x326C) + b;
            s0v = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s1 + 0x304);
            int h = *(int *)(s1 + 0x744);
            s2v = *(int *)(b + 0x3724) + b;
            s0v = *(int *)(b + 0x3728) + b;
            if (h != 0) {
                ForwardAnimParamPairByIndex_27EA50(h, 0);
            }
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x3D34) + b;
            s0v = *(int *)(b + 0x3D38) + b;
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1810) + b;
            s0v = *(int *)(b + 0x1814) + b;
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1810) + b;
            s0v = *(int *)(b + 0x1814) + b;
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0xFD4) + b;
            s0v = *(int *)(b + 0xFD8) + b;
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x1BC0) + b;
            s0v = *(int *)(b + 0x1BC4) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s1 + 0x304);
            s2v = *(int *)(b + 0x2D38) + b;
            s0v = *(int *)(b + 0x2D3C) + b;
        }
            break;
        }
        break;
    }
        if (*(int *)(s1 + 0x6EC) != 0) {
            if (*(unsigned char *)(s1 + 0x1650) == 9) {
                int b = *(int *)(s1 + 0x304);
                *(char *)(s1 + 0x2F7) = 0;
                s2v = *(int *)(b + 0x490) + b;
                s0v = *(int *)(b + 0x494) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                *(char *)(s1 + 0x2F7) = 0;
                s2v = *(int *)(b + 0x44C) + b;
                s0v = *(int *)(b + 0x450) + b;
            }
        }
        func_002A8578(s1, s2v, s0v, fv, 0, gb, 0);
        if ((p1 ^ 0x4E2) != 0) {
            InitRenderStruct_2A8608(s1, p1, p2, 0, 2, 0);
        }
        {
            float *dst = (float *)(s1 + 0x5C0);
            float *src = *(float **)(s1 + 0xF0);
            if (dst != src) {
                *(float *)(s1 + 0x5C0) = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
        }
        *(int *)(s1 + 0x5F0) = 0x1E;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        if (*(unsigned char *)(s1 + 0x1650) == 5) {
            *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x20000;
        }
        if (*(int *)(s1 + 0x1644) & 0x100000) {
            *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x10000;
        }
        if (0.0f < *(float *)(s1 + 0x24C)) {
            float *fp1;
            float *fp2;
            fv = 1.0f;
            moveMotion(s1);
            AddScaledVecToField_100_14F9F0(s1, fv);
            AddScaledXfmVecToField_F0_14F928(s1, fv);
            fp1 = *(float **)(s1 + 0xF0);
            fp1[0] = fp1[0] * 0.99500002f + *(float *)(s1 + 0x5C0) * 0.0049999999f;
            fp2 = *(float **)(s1 + 0xF0);
            fp2[2] = fp2[2] * 0.99500002f + *(float *)(s1 + 0x5C8) * 0.0049999999f;
        }
        {
            char *g = D_007474A0;
            if ((*(int *)(g + 0x210) & 7) == (*(int *)(s1 + 0x17D0) & 7)) {
                if (*(float *)(s1 + 0x618) < 64.0f) {
                    func_0026F328(s1);
                }
            }
        }
        if (*(int *)(s1 + 0x1644) & 0x10008000) {
            if (*(int *)(s1 + 0x1644) & 0x10000000) {
                Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
                *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x1000;
            }
            if (*(int *)(s1 + 0x16EC) != 0) {
                if (*(unsigned char *)(s1 + 0x1650) == 9) {
                    *(unsigned char *)(s1 + 0x2F6) = 2;
                }
                if (*(int *)(s1 + 0x1644) & 0x8000) {
                    *(unsigned char *)(s1 + 0x2F6) = 2;
                }
            }
        } else {
            if (*(int *)(s1 + 0x5F0) != 0) {
                *(int *)(s1 + 0x5F0) = *(int *)(s1 + 0x5F0) - 1;
            } else if (*(int *)(s1 + 0x16D0) & 0x200000) {
                if (*(float *)(s1 + 0x618) < 64.0f) {
                    char *g = D_007474A0;
                    if ((*(int *)(g + 0x210) & 7) == (*(int *)(s1 + 0x17D0) & 7)) {
                        void *h;
                        *(int *)(s1 + 0x16D4) = *(int *)(s1 + 0x16D4) & 0xF7FFFFFF;
                        h = Obj0000_Get_D_00747A94_2DB6B0();
                        func_002A74E0(s1, *(void **)((char *)h + 0xF0), 1);
                        if (func_002A7CA0(s1, s1 + 0x16A0) != 0) {
                            *(int *)(s1 + 0x16D4) = *(int *)(s1 + 0x16D4) | 0x8000000;
                        }
                        if (*(float *)(s1 + 0x510) < 8.0f) {
                            *(unsigned char *)(s1 + 0x2F6) = 2;
                        }
                    }
                }
                if (*(float *)(s1 + 0x618) < 9.0f) {
                    *(unsigned char *)(s1 + 0x2F6) = 2;
                }
            }
            if (*(int *)(s1 + 0x16D0) & 0x200000) {
                char *g = D_007474A0;
                if ((*(int *)(g + 0x210) & 7) == (*(int *)(s1 + 0x17D0) & 7)) {
                    if (func_002919F8(D_005864F0, *(void **)(s1 + 0xF0), 4.0f) != 0) {
                        *(unsigned char *)(s1 + 0x2F6) = 2;
                    }
                    if (func_00291AC8(D_005864F0, *(void **)(s1 + 0xF0), s1, 3.0f) != 0) {
                        *(unsigned char *)(s1 + 0x2F6) = 2;
                    }
                }
            }
            if (*(int *)(s1 + 0x16EC) != 0) {
                *(unsigned char *)(s1 + 0x2F6) = 2;
            }
        }
        if (*(int *)(s1 + 0x16D0) & 0x20000000) {
            flag6 = 1;
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        if (0.0f < *(float *)(s1 + 0x16C0)) {
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        if (*(unsigned char *)(s1 + 0x2F6) != 2) {
            break;
        }
        func_002736F8((int)s1);
        switch (*(unsigned char *)(s1 + 0x1650)) {
        default:
        case 0x0:
        case 0x19:
            if ((Forward30F348_31CFE0() & 1) != 0
                && *(float *)(s1 + 0x16C0) <= 0.0f
                && *(int *)(s1 + 0x16EC) <= 0) {
                *(char *)(s1 + 0x2F4) = 0;
                *(char *)(s1 + 0x2F5) = 0x6B;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F7) = 0;
                break;
            }
            func_002705D8(s1);
            break;
        case 0x9:
            if (flag6 != 0) {
                if (*(int *)(s1 + 0x6EC) != 0) {
                    int t = 0x47;
                    *(char *)(s1 + 0x2F7) = 1;
                    *(char *)(s1 + 0x2F5) = t;
                } else {
                    *(char *)(s1 + 0x2F7) = 0;
                    *(char *)(s1 + 0x2F5) = 0x15;
                }
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F4) = 0;
                break;
            }
            func_002705D8(s1);
            break;
        case 0x1:
        case 0x4:
        case 0x5:
            break;
        }
        break;
    case 2:
        if (!(nw & 0x20000000) && !(fv < *(float *)(s1 + 0x16C0))) {
            *(int *)(s1 + 0x16D0) = old | 0x402;
        }
        *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) & 0xFFFF7FFF;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        switch (*(unsigned char *)(s1 + 0x1650)) {
        default:
        case 0x4:
            switch (*(int *)(s1 + 0x564)) {
            default:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x414) + b;
                s0v = *(int *)(b + 0x418) + b;
            }
                break;
            case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x229:
            case 0x22A: case 0x242: case 0x243: case 0x244: case 0x24B: case 0x256:
            case 0x27E:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x7B4) + b;
                s0v = *(int *)(b + 0x7B8) + b;
            }
                break;
            case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C: case 0x21D:
            case 0x21E: case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x22F:
            case 0x248: case 0x249: case 0x24C: case 0x24D: case 0x24E: case 0x252:
            case 0x25A:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1420) + b;
                s0v = *(int *)(b + 0x1424) + b;
            }
                break;
            case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
            case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x414) + b;
                s0v = *(int *)(b + 0x418) + b;
            }
                break;
            case 0x250: case 0x251:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18F0) + b;
                s0v = *(int *)(b + 0x18F4) + b;
            }
                break;
            case 0x260:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3038) + b;
                s0v = *(int *)(b + 0x303C) + b;
            }
                break;
            case 0x264:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x326C) + b;
                s0v = *(int *)(b + 0x3270) + b;
            }
                break;
            case 0x265:
            {
                int b = *(int *)(s1 + 0x304);
                int h = *(int *)(s1 + 0x744);
                s2v = *(int *)(b + 0x3724) + b;
                s0v = *(int *)(b + 0x3728) + b;
                if (h != 0) {
                    ForwardAnimParamPairByIndex_27EA50(h, 0);
                }
            }
                break;
            case 0x26A:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3D34) + b;
                s0v = *(int *)(b + 0x3D38) + b;
            }
                break;
            case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1808) + b;
                s0v = *(int *)(b + 0x180C) + b;
            }
                break;
            case 0x209: case 0x21F:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3418) + b;
                s0v = *(int *)(b + 0x341C) + b;
            }
                break;
            case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
            case 0x272: case 0x273: case 0x274:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xFCC) + b;
                s0v = *(int *)(b + 0xFD0) + b;
            }
                break;
            case 0x220: case 0x221: case 0x222:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1BC0) + b;
                s0v = *(int *)(b + 0x1BC4) + b;
            }
                break;
            case 0x223:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x2D38) + b;
                s0v = *(int *)(b + 0x2D3C) + b;
            }
                break;
            }
            break;
        case 0x1:
            switch (*(int *)(s1 + 0x564)) {
            default:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x404) + b;
                s0v = *(int *)(b + 0x408) + b;
            }
                break;
            case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x21A:
            case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225: case 0x229:
            case 0x22A: case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x242:
            case 0x243: case 0x248: case 0x249: case 0x24B: case 0x24C: case 0x24D:
            case 0x24E: case 0x252: case 0x256: case 0x25A: case 0x27E:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x404) + b;
                s0v = *(int *)(b + 0x408) + b;
            }
                break;
            case 0x244:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3700) + b;
                s0v = *(int *)(b + 0x3704) + b;
            }
                break;
            case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
            case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xBE0) + b;
                s0v = *(int *)(b + 0xBE4) + b;
            }
                break;
            case 0x250: case 0x251:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18F0) + b;
                s0v = *(int *)(b + 0x18F4) + b;
            }
                break;
            case 0x260:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3038) + b;
                s0v = *(int *)(b + 0x303C) + b;
            }
                break;
            case 0x264:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x326C) + b;
                s0v = *(int *)(b + 0x3270) + b;
            }
                break;
            case 0x265:
            {
                int b = *(int *)(s1 + 0x304);
                int h = *(int *)(s1 + 0x744);
                s2v = *(int *)(b + 0x3724) + b;
                s0v = *(int *)(b + 0x3728) + b;
                if (h != 0) {
                    ForwardAnimParamPairByIndex_27EA50(h, 0);
                }
            }
                break;
            case 0x26A:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3D34) + b;
                s0v = *(int *)(b + 0x3D38) + b;
            }
                break;
            case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1818) + b;
                s0v = *(int *)(b + 0x181C) + b;
            }
                break;
            case 0x209: case 0x21F:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1818) + b;
                s0v = *(int *)(b + 0x181C) + b;
            }
                break;
            case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
            case 0x272: case 0x273: case 0x274:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xFB4) + b;
                s0v = *(int *)(b + 0xFB8) + b;
            }
                break;
            case 0x220: case 0x221: case 0x222:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1BC0) + b;
                s0v = *(int *)(b + 0x1BC4) + b;
            }
                break;
            case 0x223:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x2D38) + b;
                s0v = *(int *)(b + 0x2D3C) + b;
            }
                break;
            }
            break;
        case 0x5:
            switch (*(int *)(s1 + 0x564)) {
            default:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x42C) + b;
                s0v = *(int *)(b + 0x430) + b;
            }
                break;
            case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x229:
            case 0x22A: case 0x242: case 0x243: case 0x24B: case 0x256: case 0x27E:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x7BC) + b;
                s0v = *(int *)(b + 0x7C0) + b;
            }
                break;
            case 0x244:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3700) + b;
                s0v = *(int *)(b + 0x3704) + b;
            }
                break;
            case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
            case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
            case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1440) + b;
                s0v = *(int *)(b + 0x1444) + b;
            }
                break;
            case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
            case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xBE0) + b;
                s0v = *(int *)(b + 0xBE4) + b;
            }
                break;
            case 0x250: case 0x251:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18F0) + b;
                s0v = *(int *)(b + 0x18F4) + b;
            }
                break;
            case 0x260:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3038) + b;
                s0v = *(int *)(b + 0x303C) + b;
            }
                break;
            case 0x264:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x326C) + b;
                s0v = *(int *)(b + 0x3270) + b;
            }
                break;
            case 0x265:
            {
                int b = *(int *)(s1 + 0x304);
                int h = *(int *)(s1 + 0x744);
                s2v = *(int *)(b + 0x3724) + b;
                s0v = *(int *)(b + 0x3728) + b;
                if (h != 0) {
                    ForwardAnimParamPairByIndex_27EA50(h, 0);
                }
            }
                break;
            case 0x26A:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x3D34) + b;
                s0v = *(int *)(b + 0x3D38) + b;
            }
                break;
            case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1818) + b;
                s0v = *(int *)(b + 0x181C) + b;
            }
                break;
            case 0x209: case 0x21F:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1818) + b;
                s0v = *(int *)(b + 0x181C) + b;
            }
                break;
            case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
            case 0x272: case 0x273: case 0x274:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xFDC) + b;
                s0v = *(int *)(b + 0xFE0) + b;
            }
                break;
            case 0x220: case 0x221: case 0x222:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x1BC0) + b;
                s0v = *(int *)(b + 0x1BC4) + b;
            }
                break;
            case 0x223:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x2D38) + b;
                s0v = *(int *)(b + 0x2D3C) + b;
            }
                break;
            }
            break;
        }
        func_002A8578(s1, s2v, s0v, 0.0f, 10, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 3:
        if (*(unsigned char *)(s1 + 0x1650) == 5) {
            *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x20000;
        }
        if (moveMotion(s1) != 0) {
            if ((Forward30F348_31CFE0() & 1) != 0
                && *(float *)(s1 + 0x16C0) <= 0.0f
                && *(int *)(s1 + 0x16EC) <= 0) {
                *(char *)(s1 + 0x2F4) = 0;
                *(char *)(s1 + 0x2F5) = 0x6B;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F7) = 0;
            } else {
                func_002705D8(s1);
            }
        }
        fv = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, fv);
        AddScaledXfmVecToField_F0_14F928(s1, fv);
        break;
    }
}
