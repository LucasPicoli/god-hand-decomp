/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f12, int t0, int t1);
extern void func_0026F120(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern unsigned int Forward30F348_31CFE0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void func_00270C78(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_00274238(void *a0, int a1);
extern void func_00262AA8(void *a0);
extern char D_005FEE00[];
extern char D_00569B70[];
extern unsigned char D_005CB010;

__attribute__((section(".text.func_0024F050")))
void func_0024F050(void *a0)
{
    char *s2 = (char *)a0;
    int s3;
    int s1;
    int s4;

    switch (*(unsigned char *)(s2 + 0x2F6)) {
    case 0:
        s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        if (*(unsigned char *)(s2 + 0x17C3) != 0) {
            if (*(unsigned char *)(s2 + 0x2F7) != 0)
                *(unsigned char *)(s2 + 0x2F7) = 0;
            else
                *(unsigned char *)(s2 + 0x2F7) = 1;
        }
        switch (*(int *)(s2 + 0x564)) {
        case 0x200: case 0x201: case 0x204: case 0x213: case 0x217:
        case 0x227: case 0x228: case 0x22B: case 0x23A: case 0x23B:
        case 0x240: case 0x242: case 0x243: case 0x244: case 0x24A:
        case 0x256: case 0x25B: case 0x27E: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa1 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa1 + 0x300) + wa1;
                s1 = *(int *)(wa1 + 0x304) + wa1;
            } else {
                int wb1 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb1 + 0x2F8) + wb1;
                s1 = *(int *)(wb1 + 0x2FC) + wb1;
            }
            break;
        }
        default: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa2 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa2 + 0x820) + wa2;
                s1 = *(int *)(wa2 + 0x824) + wa2;
            } else {
                int wb2 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb2 + 0x818) + wb2;
                s1 = *(int *)(wb2 + 0x81C) + wb2;
            }
            break;
        }
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x278: case 0x279: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa3 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa3 + 0x9E8) + wa3;
                s1 = *(int *)(wa3 + 0x9EC) + wa3;
            } else {
                int wb3 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb3 + 0x9E0) + wb3;
                s1 = *(int *)(wb3 + 0x9E4) + wb3;
            }
            break;
        }
        case 0x250: case 0x251: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int we = *(int *)(s2 + 0x304);
                s3 = *(int *)(we + 0x9E8) + we;
                s1 = *(int *)(we + 0x9EC) + we;
            } else {
                int wf = *(int *)(s2 + 0x304);
                s3 = *(int *)(wf + 0x9E0) + wf;
                s1 = *(int *)(wf + 0x9E4) + wf;
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 1,
                               (short)(Obj0000_Get_Field_424_1595F0(s2) + 0x23),
                               s2, 0, 0, 0, 0);
            break;
        }
        case 0x260: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa5 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa5 + 0x3144) + wa5;
                s1 = *(int *)(wa5 + 0x3148) + wa5;
            } else {
                int wb5 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb5 + 0x3144) + wb5;
                s1 = *(int *)(wb5 + 0x3148) + wb5;
                s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
            }
            break;
        }
        case 0x264: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa6 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa6 + 0x3310) + wa6;
                s1 = *(int *)(wa6 + 0x3314) + wa6;
            } else {
                int wb6 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb6 + 0x3308) + wb6;
                s1 = *(int *)(wb6 + 0x330C) + wb6;
            }
            break;
        }
        case 0x265: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa7 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa7 + 0x3888) + wa7;
                s1 = *(int *)(wa7 + 0x388C) + wa7;
            } else {
                int wb7 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb7 + 0x3880) + wb7;
                s1 = *(int *)(wb7 + 0x3884) + wb7;
            }
            break;
        }
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa8 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa8 + 0x16A0) + wa8;
                s1 = *(int *)(wa8 + 0x16A4) + wa8;
            } else {
                int wb8 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb8 + 0x1698) + wb8;
                s1 = *(int *)(wb8 + 0x169C) + wb8;
            }
            break;
        }
        case 0x241: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa9 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa9 + 0x3AA4) + wa9;
                s1 = *(int *)(wa9 + 0x3AA8) + wa9;
            } else {
                int wb9 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb9 + 0x3A9C) + wb9;
                s1 = *(int *)(wb9 + 0x3AA0) + wb9;
            }
            break;
        }
        case 0x209: case 0x21F: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa10 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa10 + 0x16A0) + wa10;
                s1 = *(int *)(wa10 + 0x16A4) + wa10;
            } else {
                int wb10 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb10 + 0x1698) + wb10;
                s1 = *(int *)(wb10 + 0x169C) + wb10;
            }
            break;
        }
        case 0x220: case 0x221: case 0x222: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa11 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa11 + 0x820) + wa11;
                s1 = *(int *)(wa11 + 0x824) + wa11;
            } else {
                int wb11 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb11 + 0x818) + wb11;
                s1 = *(int *)(wb11 + 0x81C) + wb11;
            }
            break;
        }
        case 0x223: {
            int w = *(int *)(s2 + 0x304);
            s3 = *(int *)(w + 0x2E4C) + w;
            s1 = *(int *)(w + 0x2E50) + w;
            break;
        }
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C:
        case 0x21D: case 0x21E: case 0x225: case 0x22C: case 0x22D:
        case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C:
        case 0x24D: case 0x24E: case 0x252: case 0x25A: {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wa12 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wa12 + 0x1260) + wa12;
                s1 = *(int *)(wa12 + 0x1264) + wa12;
            } else {
                int wb12 = *(int *)(s2 + 0x304);
                s3 = *(int *)(wb12 + 0x1258) + wb12;
                s1 = *(int *)(wb12 + 0x125C) + wb12;
            }
            break;
        }
        }
        if (*(int *)(s2 + 0x6EC) != 0) {
            if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                int wc = *(int *)(s2 + 0x304);
                s3 = *(int *)(wc + 0x820) + wc;
                s1 = *(int *)(wc + 0x824) + wc;
            } else {
                int wd = *(int *)(s2 + 0x304);
                s3 = *(int *)(wd + 0x818) + wd;
                s1 = *(int *)(wd + 0x81C) + wd;
            }
        }
        func_002A8578(s2, s3, s1, 2, 0.0f, s4, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1,
                           (short)Obj0000_Get_Field_424_1595F0(s2),
                           s2, 0, 0, 0, 0);
        func_0026F120(s2);
        *(int *)(s2 + 0x5F0) = 0;
        {
            int h = *(int *)(s2 + 0x698);
            if (h != 0) {
                int k = *(int *)(h + 0x34);
                if (k != 0) {
                    char *d = s2 + 0x5D0;
                    int src;
                    *(int *)(s2 + 0x5F0) = 0xA;
                    src = *(int *)(k + 0xF0);
                    if (d != (char *)src) {
                        *(float *)(s2 + 0x5D0) = *(float *)(src + 0x0);
                        *(float *)(d + 0x4) = *(float *)(src + 0x4);
                        *(float *)(d + 0x8) = *(float *)(src + 0x8);
                    }
                }
            }
        }
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(int *)(s2 + 0x5F4) = 0x3E7;
            break;
        case 2:
            *(int *)(s2 + 0x5F4) = Forward30F348_31CFE0() % 15U + 0x14;
            break;
        case 3:
            *(int *)(s2 + 0x5F4) = Forward30F348_31CFE0() % 15U + 0xF;
            break;
        case 4:
            *(int *)(s2 + 0x5F4) = Forward30F348_31CFE0() % 15U + 0xF;
            break;
        case 5:
            *(int *)(s2 + 0x5F4) = Forward30F348_31CFE0() % 15U + 0xA;
            break;
        }
        *(unsigned char *)(s2 + 0x2F6) = *(unsigned char *)(s2 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        if (*(int *)(s2 + 0x564) != 0x264) {
            int t = *(int *)(s2 + 0x5F0);
            if (t != 0) {
                *(int *)(s2 + 0x5F0) = t - 1;
                AddScaledDeltaToField_104_2A7498(s2, (int)(s2 + 0x5D0),
                                                 *(float *)(s2 + 0x5A8) * 0.3926991f);
            }
        }
        if (moveMotion(s2)) {
            if (func_0026F1D8(s2))
                func_00270C78(s2);
            else
                func_002705D8(s2);
        }
        AddScaledVecToField_100_14F9F0(s2, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s2, 1.0f);
        if (*(unsigned short *)(s2 + 0x3AC) & 0x10)
            *(int *)(s2 + 0x5F4) = 0;
        {
            int u = *(int *)(s2 + 0x5F4);
            if (u != 0) {
                *(int *)(s2 + 0x5F4) = u - 1;
            } else if (!func_0026F1D8(s2)) {
                if (Forward30F348_31CFE0() % 12U == 0 &&
                    *(float *)(s2 + 0x618) < 9.0f &&
                    D_005CB010 == 0 &&
                    *(unsigned char *)(s2 + 0x17BB) != 0 &&
                    *(float *)(s2 + 0x1740) <= 0.0f)
                    func_00274238(s2, 0);
                else
                    func_00262AA8(s2);
            }
        }
        break;
    default:
        break;
    }
}
