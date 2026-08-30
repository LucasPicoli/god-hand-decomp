/* sn-2.95.3-136 matched TU. */

extern unsigned int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DAF0(int a0);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern void Obj2810_SetState_1_a1(int a0, int a1);
extern void SetBytes2F4Mode1_283188(int a0, int a1);
extern void Obj1D00_SetState_7_2(int a0);
extern void Obj1D00_SetState_7_4(int a0);
extern void Obj1D00_SetState_7_8(int a0);
extern void Obj1D00_ClearState_7(int a0);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_002744E0(void *a0);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */























__attribute__((section(".text.func_0023B968")))
void func_0023B968(void *a0)
{
    char *s3 = (char *)a0;
    int s2;
    int s1;

    *(int *)(s3 + 0x16D0) |= 0x400;
    switch (*(unsigned char *)(s3 + 0x2F6)) {
    case 0:
    {
        int nb;

        *(char *)(s3 + 0x1864) = 0;
        switch (*(int *)(s3 + 0x564)) {
        default:
        case 0x202:
            switch (Forward30F348_31CFE0() % 5) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3C4) + b;
                s1 = *(int *)(b + 0x3C8) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3CC) + b;
                s1 = *(int *)(b + 0x3D0) + b;
            }
                break;
            case 2:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3D4) + b;
                s1 = *(int *)(b + 0x3D8) + b;
            }
                break;
            case 3:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3DC) + b;
                s1 = *(int *)(b + 0x3E0) + b;
            }
                break;
            case 4:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3EC) + b;
                s1 = *(int *)(b + 0x3F0) + b;
            }
                break;
            }
            break;
        case 0x204:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                switch (Forward30F348_31CFE0() % 5) {
                case 0:
                default:
                {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x3C4) + b;
                    s1 = *(int *)(b + 0x3C8) + b;
                }
                    break;
                case 1:
                {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x3CC) + b;
                    s1 = *(int *)(b + 0x3D0) + b;
                }
                    break;
                case 2:
                {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x3D4) + b;
                    s1 = *(int *)(b + 0x3D8) + b;
                }
                    break;
                case 3:
                {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x3DC) + b;
                    s1 = *(int *)(b + 0x3E0) + b;
                }
                    break;
                case 4:
                {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x3EC) + b;
                    s1 = *(int *)(b + 0x3F0) + b;
                }
                    break;
                }
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2B4) + b;
                s1 = *(int *)(b + 0x2B8) + b;
            }
            break;
        case 0x213:
        case 0x217:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2FA4) + b;
                s1 = *(int *)(b + 0x2FA8) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2FAC) + b;
                s1 = *(int *)(b + 0x2FB0) + b;
            }
            break;
        case 0x275:
        case 0x276:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x23E8) + b;
            s1 = *(int *)(b + 0x23EC) + b;
        }
            break;
        case 0x242:
        case 0x243:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x36B8) + b;
            s1 = *(int *)(b + 0x36BC) + b;
        }
            break;
        case 0x244:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x36B8) + b;
            s1 = *(int *)(b + 0x36C0) + b;
        }
            break;
        case 0x214:
        case 0x215:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x1A98) + p;
            s1 = *(int *)(p + 0x1A9C) + p;
            if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                s2 = *(int *)(p + 0x13E8) + p;
                s1 = 0;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(Obj0000_Get_Field_424_1595F0(s3) + 0xB),
                                   s3, 0, 0, 0, 0);
            }
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
        case 0x25A:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x13E8) + b;
                s1 = *(int *)(b + 0x13EC) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x13F0) + b;
                s1 = *(int *)(b + 0x13F4) + b;
            }
            break;
        case 0x252:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x24F4) + b;
            s1 = *(int *)(b + 0x24F8) + b;
        }
            break;
        case 0x20A:
        case 0x20D:
        case 0x245:
        case 0x247:
            switch (Forward30F348_31CFE0() % 9) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB84) + b;
                s1 = *(int *)(b + 0xB88) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB8C) + b;
                s1 = *(int *)(b + 0xB90) + b;
            }
                break;
            case 2:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB94) + b;
                s1 = *(int *)(b + 0xB98) + b;
            }
                break;
            case 3:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB9C) + b;
                s1 = *(int *)(b + 0xBA0) + b;
            }
                break;
            case 4:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xBA4) + b;
                s1 = *(int *)(b + 0xBA8) + b;
            }
                break;
            case 5:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xBAC) + b;
                s1 = *(int *)(b + 0xBB0) + b;
            }
                break;
            case 6:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xBB4) + b;
                s1 = *(int *)(b + 0xBB8) + b;
            }
                break;
            case 7:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xBBC) + b;
                s1 = *(int *)(b + 0xBC0) + b;
            }
                break;
            case 8:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xBC4) + b;
                s1 = *(int *)(b + 0xBC8) + b;
            }
                break;
            }
            break;
        case 0x218:
        case 0x246:
            switch (Forward30F348_31CFE0() & 1) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3BBC) + b;
                s1 = *(int *)(b + 0x3BC0) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3BC4) + b;
                s1 = *(int *)(b + 0x3BC8) + b;
            }
                break;
            }
            break;
        case 0x278:
        case 0x279:
            switch (Forward30F348_31CFE0() & 3) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2084) + b;
                s1 = *(int *)(b + 0x2088) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x208C) + b;
                s1 = *(int *)(b + 0x2090) + b;
            }
                break;
            case 2:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2094) + b;
                s1 = *(int *)(b + 0x2098) + b;
            }
                break;
            case 3:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x209C) + b;
                s1 = *(int *)(b + 0x20A0) + b;
            }
                break;
            }
            break;
        case 0x20B:
            switch (Forward30F348_31CFE0() & 1) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1E4C) + b;
                s1 = *(int *)(b + 0x1E50) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1E54) + b;
                s1 = *(int *)(b + 0x1E58) + b;
            }
                break;
            }
            break;
        case 0x20C:
        case 0x24F:
            switch (Forward30F348_31CFE0() & 1) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1F98) + b;
                s1 = *(int *)(b + 0x1F9C) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1FA0) + b;
                s1 = *(int *)(b + 0x1FA4) + b;
            }
                break;
            }
            break;
        case 0x20E:
            switch (Forward30F348_31CFE0() % 3) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2FBC) + b;
                s1 = *(int *)(b + 0x2FC0) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2FC4) + b;
                s1 = *(int *)(b + 0x2FC8) + b;
            }
                break;
            case 2:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2FCC) + b;
                s1 = *(int *)(b + 0x2FD0) + b;
            }
                break;
            }
            break;
        case 0x205:
        case 0x207:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x17F8) + b;
            s1 = *(int *)(b + 0x17FC) + b;
        }
            break;
        case 0x224:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x18DC) + b;
                s1 = *(int *)(b + 0x18E0) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x18E4) + b;
                s1 = *(int *)(b + 0x18E8) + b;
            }
            break;
        case 0x241:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3B1C) + b;
                s1 = *(int *)(b + 0x3B20) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3B24) + b;
                s1 = *(int *)(b + 0x3B28) + b;
            }
            break;
        case 0x206:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x1890) + b;
            s1 = *(int *)(b + 0x1894) + b;
        }
            break;
        case 0x208:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x1EA0) + b;
            s1 = *(int *)(b + 0x1EA4) + b;
        }
            break;
        case 0x209:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x34F4) + b;
                s1 = *(int *)(b + 0x34F8) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x34FC) + b;
                s1 = *(int *)(b + 0x3500) + b;
            }
            break;
        case 0x21F:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x35C0) + b;
                s1 = *(int *)(b + 0x35C4) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x34FC) + b;
                s1 = *(int *)(b + 0x3500) + b;
            }
            break;
        case 0x250:
        case 0x251:
            switch (Forward30F348_31CFE0() % 3) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1A30) + b;
                s1 = *(int *)(b + 0x1A34) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1A38) + b;
                s1 = *(int *)(b + 0x1A3C) + b;
            }
                break;
            case 2:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1A40) + b;
                s1 = *(int *)(b + 0x1A44) + b;
            }
                break;
            }
            break;
        case 0x260:
            switch (Forward30F348_31CFE0() & 3) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x31C4) + b;
                s1 = *(int *)(b + 0x31C8) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x31CC) + b;
                s1 = *(int *)(b + 0x31D0) + b;
            }
                break;
            case 2:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x31D4) + b;
                s1 = *(int *)(b + 0x31D8) + b;
            }
                break;
            case 3:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x31DC) + b;
                s1 = *(int *)(b + 0x31E0) + b;
            }
                break;
            }
            break;
        case 0x264:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x33B8) + p;
            s1 = *(int *)(p + 0x33BC) + p;
            if (*(int *)(s3 + 0x740) != 0) {
                Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DAF0(*(int *)(s3 + 0x740));
            }
        }
            break;
        case 0x265:
            if ((*(int *)(s3 + 0x16D4) & 0x20000000) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3770) + b;
                s1 = *(int *)(b + 0x3774) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x372C) + b;
                s1 = *(int *)(b + 0x3730) + b;
                if (*(int *)(s3 + 0x744) != 0) {
                    ForwardAnimParamPairByIndex_27EA50(*(int *)(s3 + 0x744), 2);
                }
            }
            break;
        case 0x20F:
        case 0x210:
        case 0x226:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0xF94) + b;
            s1 = *(int *)(b + 0xF98) + b;
        }
            break;
        case 0x270:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x2224) + p;
            s1 = *(int *)(p + 0x2228) + p;
            if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                s1 = *(int *)(p + 0x222C) + p;
            }
        }
            break;
        case 0x271:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x2248) + p;
            s1 = *(int *)(p + 0x224C) + p;
            if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                s1 = *(int *)(p + 0x2250) + p;
            }
        }
            break;
        case 0x272:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x2230) + p;
            s1 = *(int *)(p + 0x2234) + p;
            if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                s1 = *(int *)(p + 0x2238) + p;
            }
        }
            break;
        case 0x273:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x2254) + p;
            s1 = *(int *)(p + 0x2258) + p;
            if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                s1 = *(int *)(p + 0x225C) + p;
            }
        }
            break;
        case 0x274:
        {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x223C) + p;
            s1 = *(int *)(p + 0x2240) + p;
            if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                s1 = *(int *)(p + 0x2244) + p;
            }
        }
            break;
        case 0x220:
        case 0x221:
        case 0x222:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1D68) + b;
                s1 = *(int *)(b + 0x1D6C) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1D70) + b;
                s1 = *(int *)(b + 0x1D74) + b;
            }
            break;
        case 0x223:
        {
            int b = *(int *)(s3 + 0x304);
            s2 = *(int *)(b + 0x2D38) + b;
            s1 = *(int *)(b + 0x2D3C) + b;
        }
            break;
        case 0x211:
            if ((*(int *)(s3 + 0x16D4) & 0x20) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x24AC) + b;
                s1 = *(int *)(b + 0x24B0) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xF94) + b;
                s1 = *(int *)(b + 0xF98) + b;
            }
            break;
        case 0x256:
            switch (Forward30F348_31CFE0() & 1) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2AFC) + b;
                s1 = *(int *)(b + 0x2B00) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2B04) + b;
                s1 = *(int *)(b + 0x2B08) + b;
            }
                break;
            }
            break;
        case 0x27E:
            switch (Forward30F348_31CFE0() & 1) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2C40) + b;
                s1 = *(int *)(b + 0x2C44) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x2C48) + b;
                s1 = *(int *)(b + 0x2C4C) + b;
            }
                break;
            }
            break;
        case 0x26A:
            switch (Forward30F348_31CFE0() & 1) {
            case 0:
            default:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3D54) + b;
                s1 = *(int *)(b + 0x3D58) + b;
            }
                if (*(int *)(s3 + 0x748) != 0) {
                    Obj2810_SetState_1_a1(*(int *)(s3 + 0x748), 0);
                }
                if (*(int *)(s3 + 0x74C) != 0) {
                    SetBytes2F4Mode1_283188(*(int *)(s3 + 0x74C), 0);
                }
                if (*(int *)(s3 + 0x750) != 0) {
                    SetBytes2F4Mode1_283188(*(int *)(s3 + 0x750), 0);
                }
                break;
            case 1:
            {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3D5C) + b;
                s1 = *(int *)(b + 0x3D60) + b;
            }
                if (*(int *)(s3 + 0x748) != 0) {
                    Obj2810_SetState_1_a1(*(int *)(s3 + 0x748), 1);
                }
                if (*(int *)(s3 + 0x74C) != 0) {
                    SetBytes2F4Mode1_283188(*(int *)(s3 + 0x74C), 1);
                }
                if (*(int *)(s3 + 0x750) != 0) {
                    SetBytes2F4Mode1_283188(*(int *)(s3 + 0x750), 1);
                }
                break;
            }
            break;
        }
        if (*(int *)(s3 + 0x6EC) != 0) {
            int p = *(int *)(s3 + 0x304);
            s2 = *(int *)(p + 0x3E4) + p;
            s1 = *(int *)(p + 0x3E8) + p;
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        func_002A8578(s3, s2, s1, 0.0f, 0xA, nb, 0);
        *(int *)(s3 + 0x5F0) = 1;
        *(unsigned char *)(s3 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
    {
        int t = *(int *)(s3 + 0x564);

        if (t < 0x264 || (t >= 0x266 && t != 0x26A)) {
            int r = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s3, *(int *)(r + 0xF0),
                                             *(float *)(s3 + 0x5A8) * 0.19634955f);
        }
        if (moveMotion(s3) != 0) {
            func_002705D8(s3);
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
    }
        break;
    case 2:
    {
        int nb;
        int p;

        *(char *)(s3 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        p = *(int *)(s3 + 0x304);
        func_002A8578(s3, *(int *)(p + 0x2F24) + p, *(int *)(p + 0x2F28) + p,
                      0.0f, 0xA, nb, 0);
        if (*(int *)(s3 + 0x708) != 0) {
            Obj1D00_SetState_7_2(*(int *)(s3 + 0x708));
        }
        *(int *)(s3 + 0x5F4) = 1;
        *(unsigned char *)(s3 + 0x2F6) += 1;
    }
        goto L26C;
    case 4:
    {
        int nb;
        int p;

        *(char *)(s3 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        p = *(int *)(s3 + 0x304);
        func_002A8578(s3, *(int *)(p + 0x2F9C) + p, *(int *)(p + 0x2FA0) + p,
                      0.0f, 3, nb, 0);
        if (*(int *)(s3 + 0x708) != 0) {
            Obj1D00_SetState_7_8(*(int *)(s3 + 0x708));
        }
        *(unsigned char *)(s3 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
    case 5:
    L26C:
    {
        int r = Obj0000_Get_D_00747A94_2DB6B0();

        AddScaledDeltaToField_104_2A7498(s3, *(int *)(r + 0xF0),
                                         *(float *)(s3 + 0x5A8) * 0.09817477f);
        if (moveMotion(s3) != 0) {
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
    }
        break;
    case 6:
    {
        int nb;
        int p;

        *(char *)(s3 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        p = *(int *)(s3 + 0x304);
        func_002A8578(s3, *(int *)(p + 0x2F2C) + p, *(int *)(p + 0x2F30) + p,
                      0.0f, 3, nb, 0);
        if (*(int *)(s3 + 0x708) != 0) {
            Obj1D00_SetState_7_4(*(int *)(s3 + 0x708));
        }
        *(unsigned char *)(s3 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 7:
    {
        int r = Obj0000_Get_D_00747A94_2DB6B0();

        AddScaledDeltaToField_104_2A7498(s3, *(int *)(r + 0xF0),
                                         *(float *)(s3 + 0x5A8) * 0.09817477f);
        if (moveMotion(s3) != 0) {
            AddScaledVecToField_100_14F9F0(s3, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
            func_002705D8(s3);
            if (*(int *)(s3 + 0x708) != 0) {
                Obj1D00_ClearState_7(*(int *)(s3 + 0x708));
            }
            return;
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
    }
        break;
    default:
        break;
    }
    if ((*(unsigned short *)(s3 + 0x3AC) & 3) != 0) {
        if (*(int *)(s3 + 0x5F0) != 0) {
            *(int *)(s3 + 0x5F0) = 0;
            func_002744E0(s3);
        }
    }
}
