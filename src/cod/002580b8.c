/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0027DBF8(int a0, int a1);
extern void func_00281500(int a0, int a1);
extern void func_002833D8(int a0, int a1);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void KillEffect(void *a0, int a1, int a2);

/* sn-2.95.3-136 candidate. */

















__attribute__((section(".text.func_002580B8")))
void func_002580B8(void *a0)
{
    char *s0 = (char *)a0;
    int s2;
    int s1;
    int s3;

    if (*(unsigned char *)(s0 + 0x2F6) == 0) {
        switch (*(int *)(s0 + 0x564)) {
        case 0x223:
        case 0x241:
        case 0x260:
        case 0x26A:
        case 0x275:
        case 0x276:
            *(unsigned char *)(s0 + 0x2F6) = 2;
            break;
        case 0x265:
            if ((*(int *)(s0 + 0x16D4) & 0x20000000) != 0) {
                *(unsigned char *)(s0 + 0x2F6) = 0xA;
            }
            break;
        case 0x264:
            *(unsigned char *)(s0 + 0x2F6) = 2;
            if ((*(int *)(s0 + 0x16D4) & 0x10000000) != 0) {
                *(unsigned char *)(s0 + 0x2F6) = 4;
            }
            break;
        }
    }

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int nb;

        switch (*(int *)(s0 + 0x564)) {
        default:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x5F0) + b;
            s1 = *(int *)(b + 0x5F4) + b;
        }
            break;
        case 0x256:
        case 0x27E:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2908) + b;
            s1 = *(int *)(b + 0x290C) + b;
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
        case 0x250:
        case 0x251:
        case 0x278:
        case 0x279:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0xADC) + b;
            s1 = *(int *)(b + 0xAE0) + b;
        }
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
        case 0x241:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x1770) + b;
            s1 = *(int *)(b + 0x1774) + b;
        }
            break;
        case 0x209:
        case 0x21F:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x1770) + b;
            s1 = *(int *)(b + 0x1774) + b;
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
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0xF1C) + b;
            s1 = *(int *)(b + 0xF20) + b;
        }
            break;
        case 0x220:
        case 0x221:
        case 0x222:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x5F0) + b;
            s1 = *(int *)(b + 0x5F4) + b;
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
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x1348) + b;
            s1 = *(int *)(b + 0x134C) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x38A8) + b;
            s1 = *(int *)(b + 0x38AC) + b;
        }
            break;
        }
        ReleaseField6ECByTag564_26B1E8(s0);
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 0.0f, 3, nb, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(int *)(s0 + 0x16EC) = 0;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (func_0026F1D8(s0) == 0) {
            *(unsigned char *)(s0 + 0x2F6) = 8;
        }
        break;
    case 2:
    {
        int nb;

        *(float *)(s0 + 0x600) = 0.0f;
        switch (*(int *)(s0 + 0x564)) {
        default:
        case 0x270:
        case 0x271:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2390) + b;
            s1 = *(int *)(b + 0x2394) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2E54) + b;
            s1 = *(int *)(b + 0x2E58) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x31AC) + b;
            s1 = *(int *)(b + 0x31B0) + b;
            *(float *)(s0 + 0x600) = 30.0f;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3380) + b;
            s1 = *(int *)(b + 0x3384) + b;
            if (*(int *)(s0 + 0x740) != 0) {
                func_0027DBF8(*(int *)(s0 + 0x740), 0);
            }
            *(float *)(s0 + 0x600) = 30.0f;
        }
            break;
        case 0x241:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3AB4) + b;
            s1 = *(int *)(b + 0x3AB8) + b;
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3DFC) + b;
            s1 = *(int *)(b + 0x3E00) + b;
            if (*(int *)(s0 + 0x748) != 0) {
                func_00281500(*(int *)(s0 + 0x748), 0);
            }
            if (*(int *)(s0 + 0x74C) != 0) {
                func_002833D8(*(int *)(s0 + 0x74C), 0);
            }
            if (*(int *)(s0 + 0x750) != 0) {
                func_002833D8(*(int *)(s0 + 0x750), 0);
            }
            *(float *)(s0 + 0x600) = 60.0f;
        }
            break;
        }
        ReleaseField6ECByTag564_26B1E8(s0);
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 0.0f, 3, nb, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(int *)(s0 + 0x16D4) |= 0x10000000;
        *(unsigned char *)(s0 + 0x2F6) += 1;
        *(int *)(s0 + 0x16EC) = 0;
    }
        /* fallthrough */
    case 3:
    {
        float d = *(float *)(s0 + 0x600);

        if (0.0f < d) {
            *(int *)(s0 + 0x16D0) |= 0x800000;
            *(float *)(s0 + 0x600) = d - *(float *)(s0 + 0x5A8);
        }
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
    }
        break;
    case 4:
    {
        int nb;

        switch (*(int *)(s0 + 0x564)) {
        default:
        case 0x270:
        case 0x271:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2398) + b;
            s1 = *(int *)(b + 0x239C) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2E5C) + b;
            s1 = *(int *)(b + 0x2E60) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x31B4) + b;
            s1 = *(int *)(b + 0x31B8) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3388) + b;
            s1 = *(int *)(b + 0x338C) + b;
            if (*(int *)(s0 + 0x740) != 0) {
                func_0027DBF8(*(int *)(s0 + 0x740), 1);
            }
        }
            break;
        case 0x241:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3ABC) + b;
            s1 = *(int *)(b + 0x3AC0) + b;
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3E04) + b;
            s1 = *(int *)(b + 0x3E08) + b;
            if (*(int *)(s0 + 0x748) != 0) {
                func_00281500(*(int *)(s0 + 0x748), 1);
            }
            if (*(int *)(s0 + 0x74C) != 0) {
                func_002833D8(*(int *)(s0 + 0x74C), 1);
            }
            if (*(int *)(s0 + 0x750) != 0) {
                func_002833D8(*(int *)(s0 + 0x750), 1);
            }
        }
            break;
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 0.0f, 3, nb, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5:
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (func_0026F1D8(s0) == 0) {
            *(unsigned char *)(s0 + 0x2F6) += 1;
        }
        break;
    case 6:
    {
        int nb;

        switch (*(int *)(s0 + 0x564)) {
        default:
        case 0x270:
        case 0x271:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x23A0) + b;
            s1 = *(int *)(b + 0x23A4) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2E64) + b;
            s1 = *(int *)(b + 0x2E68) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x31BC) + b;
            s1 = *(int *)(b + 0x31C0) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3390) + b;
            s1 = *(int *)(b + 0x3394) + b;
            if (*(int *)(s0 + 0x740) != 0) {
                func_0027DBF8(*(int *)(s0 + 0x740), 2);
            }
        }
            break;
        case 0x241:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3AC4) + b;
            s1 = *(int *)(b + 0x3AC8) + b;
        }
            break;
        case 0x26A:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3E0C) + b;
            s1 = *(int *)(b + 0x3E10) + b;
            if (*(int *)(s0 + 0x748) != 0) {
                func_00281500(*(int *)(s0 + 0x748), 1);
            }
            if (*(int *)(s0 + 0x74C) != 0) {
                func_002833D8(*(int *)(s0 + 0x74C), 1);
            }
            if (*(int *)(s0 + 0x750) != 0) {
                func_002833D8(*(int *)(s0 + 0x750), 1);
            }
        }
            break;
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 0.0f, 3, nb, 0);
        *(float *)(s0 + 0x600) = 30.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 7:
    {
        float d = *(float *)(s0 + 0x600);

        if (0.0f < d) {
            *(int *)(s0 + 0x16D0) |= 0x800000;
            *(float *)(s0 + 0x600) = d - *(float *)(s0 + 0x5A8);
        }
        if (moveMotion(s0) != 0) {
            if (*(int *)(s0 + 0x564) == 0x26A) {
                func_002705D8(s0);
                break;
            }
            *(unsigned char *)(s0 + 0x2F6) = 8;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
    }
        break;
    case 8:
        s3 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        switch (*(int *)(s0 + 0x564)) {
        default:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x98) + b;
            s1 = *(int *)(b + 0x9C) + b;
        }
            break;
        case 0x202:
        case 0x203:
        case 0x213:
        case 0x216:
        case 0x217:
        case 0x229:
        case 0x22A:
        case 0x24B:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x648) + b;
            s1 = *(int *)(b + 0x64C) + b;
        }
            break;
        case 0x242:
        case 0x243:
        case 0x244:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x35CC) + b;
            s1 = *(int *)(b + 0x35D0) + b;
        }
            break;
        case 0x256:
        case 0x27E:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x25AC) + b;
            s1 = *(int *)(b + 0x25B0) + b;
        }
            break;
        case 0x214:
        case 0x215:
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24E:
        case 0x25A:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x10A8) + b;
            s1 = *(int *)(b + 0x10AC) + b;
        }
            break;
        case 0x225:
        case 0x24D:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3C88) + b;
            s1 = *(int *)(b + 0x3C8C) + b;
        }
            break;
        case 0x252:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x24EC) + b;
            s1 = *(int *)(b + 0x24F0) + b;
        }
            break;
        case 0x20A:
        case 0x20B:
        case 0x20D:
        case 0x20E:
        case 0x218:
        case 0x245:
        case 0x246:
        case 0x247:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x828) + b;
            s1 = *(int *)(b + 0x82C) + b;
        }
            break;
        case 0x278:
        case 0x279:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x1FB0) + b;
            s1 = *(int *)(b + 0x1FB4) + b;
        }
            break;
        case 0x20C:
        case 0x24F:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x1EAC) + b;
            s1 = *(int *)(b + 0x1EB0) + b;
        }
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x1560) + b;
            s1 = *(int *)(b + 0x1564) + b;
        }
            break;
        case 0x241:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3A00) + b;
            s1 = *(int *)(b + 0x3A04) + b;
        }
            break;
        case 0x209:
        case 0x21F:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3418) + b;
            s1 = *(int *)(b + 0x341C) + b;
        }
            break;
        case 0x250:
        case 0x251:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x18F0) + b;
            s1 = *(int *)(b + 0x18F4) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3038) + b;
            s1 = *(int *)(b + 0x303C) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x326C) + b;
            s1 = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x3724) + b;
            s1 = *(int *)(b + 0x3728) + b;
            if (*(int *)(s0 + 0x744) != 0) {
                ForwardAnimParamPairByIndex_27EA50(*(int *)(s0 + 0x744), 0);
            }
        }
            break;
        case 0x20F:
        case 0x210:
        case 0x226:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0xCF8) + b;
            s1 = *(int *)(b + 0xCFC) + b;
        }
            break;
        case 0x211:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x244C) + b;
            s1 = *(int *)(b + 0x2450) + b;
        }
            break;
        case 0x220:
        case 0x221:
        case 0x222:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x1BC0) + b;
            s1 = *(int *)(b + 0x1BC4) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2D38) + b;
            s1 = *(int *)(b + 0x2D3C) + b;
        }
            break;
        case 0x275:
        case 0x276:
        {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2274) + b;
            s1 = *(int *)(b + 0x2278) + b;
        }
            break;
        }
        if (*(int *)(s0 + 0x6EC) != 0) {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x44C) + b;
            s1 = *(int *)(b + 0x450) + b;
        }
        func_002A8578(s0, s2, s1, 0.0f, 0xA, s3, 0);
        *(float *)(s0 + 0x600) = 15.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
        /* fallthrough */
    case 9:
    {
        float d;

        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        d = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        *(float *)(s0 + 0x600) = d;
        if (d <= 0.0f) {
            func_0026EE40(s0, 0, 0);
            func_002705D8(s0);
        }
    }
        break;
    case 10:
    {
        int nb;
        int b = *(int *)(s0 + 0x304);

        s2 = *(int *)(b + 0x3978) + b;
        s1 = *(int *)(b + 0x397C) + b;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 0.0f, 3, nb, 0);
        *(int *)(s0 + 0x16D4) &= ~0x20000000;
        KillEffect(s0, 1, 2);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 11:
        *(int *)(s0 + 0x16D0) |= 0x800000;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 0xC;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 12:
    {
        int nb;
        int b = *(int *)(s0 + 0x304);

        s2 = *(int *)(b + 0x3980) + b;
        s1 = *(int *)(b + 0x3984) + b;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 0.0f, 3, nb, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 13:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    if (func_00274150(s0) != 0 || 0.0f < *(float *)(s0 + 0x1734)) {
        *(unsigned char *)(s0 + 0x2F4) = 0;
        *(unsigned char *)(s0 + 0x2F5) = 0x89;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
    }
}
