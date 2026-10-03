/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f12, int t0, int t1);
extern void func_0026F120(void *a0);
extern unsigned int irand(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void func_00270C78(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_00274238(void *a0, int a1);
extern void func_00262AA8(void *a0);
extern char D_005FEE00[];
extern unsigned char D_005CB010;

/* Phase machine on the step byte, 73 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cSnd_SeCall_2CBA48, GetSeqSEBase, func_002A8578, func_0026F120, cCoreSave_getGameLevel and 10
 * more. */
__attribute__((section(".text.func_0024F050"))) void func_0024F050(cEm00 *self)
{
    char *s2 = (char *)self;
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
                case 0x200:
                case 0x201:
                case 0x204:
                case 0x213:
                case 0x217:
                case 0x227:
                case 0x228:
                case 0x22B:
                case 0x23A:
                case 0x23B:
                case 0x240:
                case 0x242:
                case 0x243:
                case 0x244:
                case 0x24A:
                case 0x256:
                case 0x25B:
                case 0x27E: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa1 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa1, 0x300);
                        s1 = EM_RES_REC(wa1, 0x304);
                    } else {
                        int wb1 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb1, 0x2F8);
                        s1 = EM_RES_REC(wb1, 0x2FC);
                    }
                    break;
                }
                default: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa2 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa2, 0x820);
                        s1 = EM_RES_REC(wa2, 0x824);
                    } else {
                        int wb2 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb2, 0x818);
                        s1 = EM_RES_REC(wb2, 0x81C);
                    }
                    break;
                }
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
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa3 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa3, 0x9E8);
                        s1 = EM_RES_REC(wa3, 0x9EC);
                    } else {
                        int wb3 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb3, 0x9E0);
                        s1 = EM_RES_REC(wb3, 0x9E4);
                    }
                    break;
                }
                case 0x250:
                case 0x251: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int we = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(we, 0x9E8);
                        s1 = EM_RES_REC(we, 0x9EC);
                    } else {
                        int wf = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wf, 0x9E0);
                        s1 = EM_RES_REC(wf, 0x9E4);
                    }
                    cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)(GetSeqSEBase(s2) + 0x23), s2, 0, 0, 0,
                                       0);
                    break;
                }
                case 0x260: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa5 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa5, 0x3144);
                        s1 = EM_RES_REC(wa5, 0x3148);
                    } else {
                        int wb5 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb5, 0x3144);
                        s1 = EM_RES_REC(wb5, 0x3148);
                        s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
                    }
                    break;
                }
                case 0x264: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa6 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa6, 0x3310);
                        s1 = EM_RES_REC(wa6, 0x3314);
                    } else {
                        int wb6 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb6, 0x3308);
                        s1 = EM_RES_REC(wb6, 0x330C);
                    }
                    break;
                }
                case 0x265: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa7 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa7, 0x3888);
                        s1 = EM_RES_REC(wa7, 0x388C);
                    } else {
                        int wb7 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb7, 0x3880);
                        s1 = EM_RES_REC(wb7, 0x3884);
                    }
                    break;
                }
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa8 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa8, 0x16A0);
                        s1 = EM_RES_REC(wa8, 0x16A4);
                    } else {
                        int wb8 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb8, 0x1698);
                        s1 = EM_RES_REC(wb8, 0x169C);
                    }
                    break;
                }
                case 0x241: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa9 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa9, 0x3AA4);
                        s1 = EM_RES_REC(wa9, 0x3AA8);
                    } else {
                        int wb9 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb9, 0x3A9C);
                        s1 = EM_RES_REC(wb9, 0x3AA0);
                    }
                    break;
                }
                case 0x209:
                case 0x21F: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa10 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa10, 0x16A0);
                        s1 = EM_RES_REC(wa10, 0x16A4);
                    } else {
                        int wb10 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb10, 0x1698);
                        s1 = EM_RES_REC(wb10, 0x169C);
                    }
                    break;
                }
                case 0x220:
                case 0x221:
                case 0x222: {
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa11 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa11, 0x820);
                        s1 = EM_RES_REC(wa11, 0x824);
                    } else {
                        int wb11 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb11, 0x818);
                        s1 = EM_RES_REC(wb11, 0x81C);
                    }
                    break;
                }
                case 0x223: {
                    int w = *(int *)(s2 + 0x304);
                    s3 = EM_RES_REC(w, 0x2E4C);
                    s1 = EM_RES_REC(w, 0x2E50);
                    break;
                }
                case 0x214:
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
                    if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                        int wa12 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wa12, 0x1260);
                        s1 = EM_RES_REC(wa12, 0x1264);
                    } else {
                        int wb12 = *(int *)(s2 + 0x304);
                        s3 = EM_RES_REC(wb12, 0x1258);
                        s1 = EM_RES_REC(wb12, 0x125C);
                    }
                    break;
                }
            }
            if (*(int *)(s2 + 0x6EC) != 0) {
                if (*(unsigned char *)(s2 + 0x2F7) != 0) {
                    int wc = *(int *)(s2 + 0x304);
                    s3 = EM_RES_REC(wc, 0x820);
                    s1 = EM_RES_REC(wc, 0x824);
                } else {
                    int wd = *(int *)(s2 + 0x304);
                    s3 = EM_RES_REC(wd, 0x818);
                    s1 = EM_RES_REC(wd, 0x81C);
                }
            }
            func_002A8578(s2, s3, s1, 2, 0.0f, s4, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(s2), s2, 0, 0, 0, 0);
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
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    *(int *)(s2 + 0x5F4) = 0x3E7;
                    break;
                case 2:
                    *(int *)(s2 + 0x5F4) = irand() % 15U + 0x14;
                    break;
                case 3:
                    *(int *)(s2 + 0x5F4) = irand() % 15U + 0xF;
                    break;
                case 4:
                    *(int *)(s2 + 0x5F4) = irand() % 15U + 0xF;
                    break;
                case 5:
                    *(int *)(s2 + 0x5F4) = irand() % 15U + 0xA;
                    break;
            }
            *(unsigned char *)(s2 + 0x2F6) = *(unsigned char *)(s2 + 0x2F6) + 1;
            /* fallthrough */
        case 1:
            if (*(int *)(s2 + 0x564) != 0x264) {
                int t = *(int *)(s2 + 0x5F0);
                if (t != 0) {
                    *(int *)(s2 + 0x5F0) = t - 1;
                    cGameObj_SetTgtTurn(s2, (int)(s2 + 0x5D0), *(float *)(s2 + 0x5A8) * 0.3926991f);
                }
            }
            if (moveMotion(s2)) {
                if (func_0026F1D8(s2))
                    func_00270C78(s2);
                else
                    func_002705D8(s2);
            }
            cObjBase_addNullSpeed_Rotation(s2, 1.0f);
            cObjBase_addNullSpeed(s2, 1.0f);
            if (*(unsigned short *)(s2 + 0x3AC) & 0x10)
                *(int *)(s2 + 0x5F4) = 0;
            {
                int u = *(int *)(s2 + 0x5F4);
                if (u != 0) {
                    *(int *)(s2 + 0x5F4) = u - 1;
                } else if (!func_0026F1D8(s2)) {
                    if (irand() % 12U == 0 && *(float *)(s2 + 0x618) < 9.0f && D_005CB010 == 0 &&
                        *(unsigned char *)(s2 + 0x17BB) != 0 && *(float *)(s2 + 0x1740) <= 0.0f)
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
