#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int irand(void);
extern int moveMotion(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00270C78(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00260B30(void *a0);
extern void func_00262AA8(void *a0);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */


















/* Phase machine on the step byte, 65 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_0026F1D8, StoreMotionParamsBoth_2609A8, irand, cSnd_SeCall_2CBA48, GetSeqSEBase and 9 more.
 */
__attribute__((section(".text.func_00257948"))) void func_00257948(cEm00 *self)
{
    char *s3 = (char *)self;
    int s2;
    int s1;

    switch (*(unsigned char *)(s3 + 0x2F6)) {
        case 0: {
            int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;

            switch (*(int *)(s3 + 0x564)) {
                default:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        if (func_0026F1D8(s3) != 0) {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x358);
                            s1 = EM_RES_REC(b, 0x35C);
                        } else {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x368);
                            s1 = EM_RES_REC(b, 0x36C);
                        }
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x360);
                        s1 = EM_RES_REC(b, 0x364);
                    }
                    break;
                case 0x202:
                case 0x203:
                case 0x216:
                case 0x229:
                case 0x22A:
                case 0x24B:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x7A4);
                        s1 = EM_RES_REC(b, 0x7A8);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x7AC);
                        s1 = EM_RES_REC(b, 0x7B0);
                    }
                    break;
                case 0x256:
                case 0x27E:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        if (func_0026F1D8(s3) == 0) {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2BA0);
                            s1 = EM_RES_REC(b, 0x2BA4);
                            StoreMotionParamsBoth_2609A8(s3, 0x1E, 0x1B, 0x37, -1, 0);
                        } else {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2B98);
                            s1 = EM_RES_REC(b, 0x2B9C);
                        }
                    } else {
                        if (func_0026F1D8(s3) == 0) {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x262C);
                            s1 = EM_RES_REC(b, 0x2630);
                            StoreMotionParamsBoth_2609A8(s3, 0x1E, 0x1B, 0x37, -1, 0);
                        } else {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x360);
                            s1 = EM_RES_REC(b, 0x364);
                        }
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
                case 0x278:
                case 0x279:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        if (irand() & 1) {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xB04);
                            s1 = EM_RES_REC(b, 0xB08);
                        } else {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xB14);
                            s1 = EM_RES_REC(b, 0xB18);
                        }
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xB0C);
                        s1 = EM_RES_REC(b, 0xB10);
                    }
                    break;
                case 0x250:
                case 0x251:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        if (irand() & 1) {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xB04);
                            s1 = EM_RES_REC(b, 0xB08);
                        } else {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xB14);
                            s1 = EM_RES_REC(b, 0xB18);
                        }
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xB0C);
                        s1 = EM_RES_REC(b, 0xB10);
                    }
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(s3) + 0x23), s3, 0, 0,
                                       0, 0);
                    break;
                case 0x260:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xB04);
                        s1 = EM_RES_REC(b, 0xB08);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xB0C);
                        s1 = EM_RES_REC(b, 0xB10);
                    }
                    break;
                case 0x264:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x326C);
                        s1 = EM_RES_REC(b, 0x3270);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x326C);
                        s1 = EM_RES_REC(b, 0x3270);
                    }
                    break;
                case 0x265:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3724);
                        s1 = EM_RES_REC(b, 0x3728);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3724);
                        s1 = EM_RES_REC(b, 0x3728);
                    }
                    break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1788);
                        s1 = EM_RES_REC(b, 0x178C);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1790);
                        s1 = EM_RES_REC(b, 0x1794);
                    }
                    break;
                case 0x241:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3ADC);
                        s1 = EM_RES_REC(b, 0x3AE0);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3AE4);
                        s1 = EM_RES_REC(b, 0x3AE8);
                    }
                    break;
                case 0x209:
                case 0x21F:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1788);
                        s1 = EM_RES_REC(b, 0x178C);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1790);
                        s1 = EM_RES_REC(b, 0x1794);
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
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xF34);
                        s1 = EM_RES_REC(b, 0xF38);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xF3C);
                        s1 = EM_RES_REC(b, 0xF40);
                    }
                    break;
                case 0x220:
                case 0x221:
                case 0x222:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1D40);
                        s1 = EM_RES_REC(b, 0x1D44);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1D48);
                        s1 = EM_RES_REC(b, 0x1D4C);
                    }
                    break;
                case 0x223:
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x2E7C);
                        s1 = EM_RES_REC(b, 0x2E80);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x2E7C);
                        s1 = EM_RES_REC(b, 0x2E80);
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
                    if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1360);
                        s1 = EM_RES_REC(b, 0x1364);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1368);
                        s1 = EM_RES_REC(b, 0x136C);
                    }
                    break;
            }
            if (*(int *)(s3 + 0x6EC) != 0) {
                if (*(unsigned short *)(s3 + 0x3AC) & 0x200) {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x7A4);
                    s1 = EM_RES_REC(b, 0x7A8);
                } else {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x7AC);
                    s1 = EM_RES_REC(b, 0x7B0);
                }
            }
            func_002A8578(s3, s2, s1, 0.0f, 0xA, nb, 0);
            func_0026F120(s3);
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
            /* fallthrough */
        case 1:
            if (moveMotion(s3) != 0) {
                if (func_0026F1D8(s3) != 0) {
                    func_00270C78(s3);
                } else {
                    func_002705D8(s3);
                }
            }
            cObjBase_addNullSpeed_Rotation(s3, 1.0f);
            cObjBase_addNullSpeed(s3, 1.0f);
            break;
    }
    if (*(int *)(s3 + 0x564) == 0x256 || *(int *)(s3 + 0x564) == 0x27E) {
        func_00260B30(s3);
    }
    if (*(unsigned short *)(s3 + 0x3AC) & 8) {
        int t = *(int *)(s3 + 0x564);

        if (t == 0x250 || t == 0x251 || t == 0x260) {
            *(int *)(s3 + 0x16D0) |= 0x800000;
        }
    }
    if (*(unsigned short *)(s3 + 0x3AC) & 0x10) {
        func_00262AA8(s3);
    }
}
