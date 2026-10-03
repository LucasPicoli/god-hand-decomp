#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned int irand(void);
extern unsigned int Rnd(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int Getplayer(void);
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
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_002744E0(void *a0);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */
























/* Phase machine on the step byte, 126 case labels. Calls irand, cSnd_SeCall_2CBA48, GetSeqSEBase,
 * Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DAF0, Rnd, ForwardAnimParamPairByIndex_27EA50 and 15 more. */
__attribute__((section(".text.func_0023C620"))) void func_0023C620(cEm00 *self)
{
    char *s3 = (char *)self;
    int s2;
    int s1;

    *(int *)(s3 + 0x16D0) |= 0x400;
    switch (*(unsigned char *)(s3 + 0x2F6)) {
        case 0: {
            int nb;

            *(char *)(s3 + 0x1864) = 0;
            switch (*(int *)(s3 + 0x564)) {
                default:
                case 0x202:
                    switch (irand() % 6) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3C4);
                            s1 = EM_RES_REC(b, 0x3C8);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3CC);
                            s1 = EM_RES_REC(b, 0x3D0);
                        } break;
                        case 2: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3D4);
                            s1 = EM_RES_REC(b, 0x3D8);
                        } break;
                        case 3: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3DC);
                            s1 = EM_RES_REC(b, 0x3E0);
                        } break;
                        case 4: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3E4);
                            s1 = EM_RES_REC(b, 0x3E8);
                        } break;
                        case 5: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3EC);
                            s1 = EM_RES_REC(b, 0x3F0);
                        } break;
                    }
                    if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3E4);
                        s1 = EM_RES_REC(b, 0x3E8);
                    }
                    break;
                case 0x204:
                    if ((irand() & 1) != 0) {
                        switch (irand() % 6) {
                            case 0:
                            default: {
                                int b = *(int *)(s3 + 0x304);
                                s2 = EM_RES_REC(b, 0x3C4);
                                s1 = EM_RES_REC(b, 0x3C8);
                            } break;
                            case 1: {
                                int b = *(int *)(s3 + 0x304);
                                s2 = EM_RES_REC(b, 0x3CC);
                                s1 = EM_RES_REC(b, 0x3D0);
                            } break;
                            case 2: {
                                int b = *(int *)(s3 + 0x304);
                                s2 = EM_RES_REC(b, 0x3D4);
                                s1 = EM_RES_REC(b, 0x3D8);
                            } break;
                            case 3: {
                                int b = *(int *)(s3 + 0x304);
                                s2 = EM_RES_REC(b, 0x3DC);
                                s1 = EM_RES_REC(b, 0x3E0);
                            } break;
                            case 4: {
                                int b = *(int *)(s3 + 0x304);
                                s2 = EM_RES_REC(b, 0x3E4);
                                s1 = EM_RES_REC(b, 0x3E8);
                            } break;
                            case 5: {
                                int b = *(int *)(s3 + 0x304);
                                s2 = EM_RES_REC(b, 0x3EC);
                                s1 = EM_RES_REC(b, 0x3F0);
                            } break;
                        }
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x2B4);
                        s1 = EM_RES_REC(b, 0x2B8);
                    }
                    break;
                case 0x213:
                case 0x217:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x2FA4);
                        s1 = EM_RES_REC(b, 0x2FA8);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x2FAC);
                        s1 = EM_RES_REC(b, 0x2FB0);
                    }
                    break;
                case 0x275:
                case 0x276: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x23E8);
                    s1 = EM_RES_REC(b, 0x23EC);
                } break;
                case 0x242:
                case 0x243: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x36B8);
                    s1 = EM_RES_REC(b, 0x36BC);
                } break;
                case 0x244: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x36B8);
                    s1 = EM_RES_REC(b, 0x36C0);
                } break;
                case 0x256:
                    switch (irand() % 3) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2AFC);
                            s1 = EM_RES_REC(b, 0x2B00);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2B04);
                            s1 = EM_RES_REC(b, 0x2B08);
                        } break;
                        case 2: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2BE4);
                            s1 = EM_RES_REC(b, 0x2BE8);
                        } break;
                    }
                    break;
                case 0x27E:
                    switch (irand() & 1) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2C40);
                            s1 = EM_RES_REC(b, 0x2C44);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2C48);
                            s1 = EM_RES_REC(b, 0x2C4C);
                        } break;
                    }
                    break;
                case 0x214:
                case 0x215: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1A98);
                    s1 = EM_RES_REC(p, 0x1A9C);
                    if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                        s2 = EM_RES_REC(p, 0x13E8);
                        s1 = 0;
                        cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(s3) + 0xB), s3, 0,
                                           0, 0, 0);
                    }
                } break;
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
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x13E8);
                        s1 = EM_RES_REC(b, 0x13EC);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x13F0);
                        s1 = EM_RES_REC(b, 0x13F4);
                    }
                    if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x13F0);
                        s1 = EM_RES_REC(b, 0x13F4);
                    }
                    break;
                case 0x252: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x24F4);
                    s1 = EM_RES_REC(b, 0x24F8);
                } break;
                case 0x20A:
                case 0x20D:
                case 0x245:
                case 0x247:
                    switch (irand() % 6) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xB84);
                            s1 = EM_RES_REC(b, 0xB88);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xB8C);
                            s1 = EM_RES_REC(b, 0xB90);
                        } break;
                        case 2: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xB94);
                            s1 = EM_RES_REC(b, 0xB98);
                        } break;
                        case 3: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xB9C);
                            s1 = EM_RES_REC(b, 0xBA0);
                        } break;
                        case 4: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xBA4);
                            s1 = EM_RES_REC(b, 0xBA8);
                        } break;
                        case 5: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0xBAC);
                            s1 = EM_RES_REC(b, 0xBB0);
                        } break;
                    }
                    if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xB8C);
                        s1 = EM_RES_REC(b, 0xB90);
                    }
                    break;
                case 0x218:
                case 0x246:
                    switch (irand() & 1) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3BBC);
                            s1 = EM_RES_REC(b, 0x3BC0);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3BC4);
                            s1 = EM_RES_REC(b, 0x3BC8);
                        } break;
                    }
                    break;
                case 0x278:
                    switch (irand() & 3) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2084);
                            s1 = EM_RES_REC(b, 0x2088);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x208C);
                            s1 = EM_RES_REC(b, 0x2090);
                        } break;
                        case 2: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2094);
                            s1 = EM_RES_REC(b, 0x2098);
                        } break;
                        case 3: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x209C);
                            s1 = EM_RES_REC(b, 0x20A0);
                        } break;
                    }
                    if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x2084);
                        s1 = EM_RES_REC(b, 0x2088);
                    }
                    break;
                case 0x279:
                    switch (irand() & 3) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2084);
                            s1 = EM_RES_REC(b, 0x2088);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x208C);
                            s1 = EM_RES_REC(b, 0x2090);
                        } break;
                        case 2: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2094);
                            s1 = EM_RES_REC(b, 0x2098);
                        } break;
                        case 3: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x209C);
                            s1 = EM_RES_REC(b, 0x20A0);
                        } break;
                    }
                    break;
                case 0x20B:
                    switch (irand() & 1) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x1E4C);
                            s1 = EM_RES_REC(b, 0x1E50);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x1E54);
                            s1 = EM_RES_REC(b, 0x1E58);
                        } break;
                    }
                    break;
                case 0x20C:
                case 0x24F:
                    switch (irand() & 1) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x1F98);
                            s1 = EM_RES_REC(b, 0x1F9C);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x1FA0);
                            s1 = EM_RES_REC(b, 0x1FA4);
                        } break;
                    }
                    break;
                case 0x20E:
                    switch (irand() % 3) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2FBC);
                            s1 = EM_RES_REC(b, 0x2FC0);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2FC4);
                            s1 = EM_RES_REC(b, 0x2FC8);
                        } break;
                        case 2: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x2FCC);
                            s1 = EM_RES_REC(b, 0x2FD0);
                        } break;
                    }
                    break;
                case 0x205:
                case 0x207: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x17F8);
                    s1 = EM_RES_REC(b, 0x17FC);
                } break;
                case 0x224:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x18DC);
                        s1 = EM_RES_REC(b, 0x18E0);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x18E4);
                        s1 = EM_RES_REC(b, 0x18E8);
                    }
                    break;
                case 0x241:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3B1C);
                        s1 = EM_RES_REC(b, 0x3B20);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3B24);
                        s1 = EM_RES_REC(b, 0x3B28);
                    }
                    break;
                case 0x206: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x1890);
                    s1 = EM_RES_REC(b, 0x1894);
                } break;
                case 0x208: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x1EA0);
                    s1 = EM_RES_REC(b, 0x1EA4);
                } break;
                case 0x209:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x34F4);
                        s1 = EM_RES_REC(b, 0x34F8);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x34FC);
                        s1 = EM_RES_REC(b, 0x3500);
                    }
                    break;
                case 0x21F:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x35C0);
                        s1 = EM_RES_REC(b, 0x35C4);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x34FC);
                        s1 = EM_RES_REC(b, 0x3500);
                    }
                    break;
                case 0x250:
                case 0x251:
                    switch (irand() % 3) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x1A30);
                            s1 = EM_RES_REC(b, 0x1A34);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x1A38);
                            s1 = EM_RES_REC(b, 0x1A3C);
                        } break;
                        case 2: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x1A40);
                            s1 = EM_RES_REC(b, 0x1A44);
                        } break;
                    }
                    if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1A38);
                        s1 = EM_RES_REC(b, 0x1A3C);
                    }
                    break;
                case 0x260:
                    switch (irand() & 3) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x31C4);
                            s1 = EM_RES_REC(b, 0x31C8);
                        } break;
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x31CC);
                            s1 = EM_RES_REC(b, 0x31D0);
                        } break;
                        case 2: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x31D4);
                            s1 = EM_RES_REC(b, 0x31D8);
                        } break;
                        case 3: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x31DC);
                            s1 = EM_RES_REC(b, 0x31E0);
                        } break;
                    }
                    if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x31CC);
                        s1 = EM_RES_REC(b, 0x31D0);
                    }
                    break;
                case 0x264: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x33B8);
                    s1 = EM_RES_REC(p, 0x33BC);
                    if (*(int *)(s3 + 0x740) != 0) {
                        Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DAF0(*(int *)(s3 + 0x740));
                    }
                } break;
                case 0x265:
                    if ((*(int *)(s3 + 0x16D4) & 0x20000000) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3770);
                        s1 = EM_RES_REC(b, 0x3774);
                    } else if ((Rnd() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x372C);
                        s1 = EM_RES_REC(b, 0x3730);
                        if (*(int *)(s3 + 0x744) != 0) {
                            ForwardAnimParamPairByIndex_27EA50(*(int *)(s3 + 0x744), 2);
                        }
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x3768);
                        s1 = EM_RES_REC(b, 0x376C);
                        if (*(int *)(s3 + 0x744) != 0) {
                            ForwardAnimParamPairByIndex_27EA50(*(int *)(s3 + 0x744), 3);
                        }
                    }
                    break;
                case 0x20F:
                case 0x210:
                case 0x211:
                case 0x226: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0xF94);
                    s1 = EM_RES_REC(b, 0xF98);
                } break;
                case 0x270: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x2224);
                    s1 = EM_RES_REC(b, 0x2228);
                } break;
                case 0x271: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x2248);
                    s1 = EM_RES_REC(b, 0x224C);
                } break;
                case 0x272: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x2230);
                    s1 = EM_RES_REC(b, 0x2234);
                } break;
                case 0x273: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x2254);
                    s1 = EM_RES_REC(b, 0x2258);
                } break;
                case 0x274: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x223C);
                    s1 = EM_RES_REC(b, 0x2240);
                } break;
                case 0x220:
                case 0x221:
                case 0x222:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1D68);
                        s1 = EM_RES_REC(b, 0x1D6C);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1D70);
                        s1 = EM_RES_REC(b, 0x1D74);
                    }
                    break;
                case 0x223: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x2D38);
                    s1 = EM_RES_REC(b, 0x2D3C);
                } break;
                case 0x26A:
                    switch (irand() & 1) {
                        case 0:
                        default: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3D54);
                            s1 = EM_RES_REC(b, 0x3D58);
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
                        case 1: {
                            int b = *(int *)(s3 + 0x304);
                            s2 = EM_RES_REC(b, 0x3D5C);
                            s1 = EM_RES_REC(b, 0x3D60);
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
                s2 = EM_RES_REC(p, 0x3E4);
                s1 = EM_RES_REC(p, 0x3E8);
            }
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
            func_002A8578(s3, s2, s1, 0.0f, 0xA, nb, 0);
            *(int *)(s3 + 0x5F0) = 1;
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
            /* fallthrough */
        case 1: {
            int t = *(int *)(s3 + 0x564);

            if (t < 0x264 || (t >= 0x266 && t != 0x26A)) {
                int r = Getplayer();
                cGameObj_SetTgtTurn(s3, *(int *)(r + 0xF0), *(float *)(s3 + 0x5A8) * 0.19634955f);
            }
            if (moveMotion(s3) != 0) {
                func_002705D8(s3);
            }
            cObjBase_addNullSpeed_Rotation(s3, 1.0f);
            cObjBase_addNullSpeed(s3, 1.0f);
        } break;
        case 2: {
            int nb;
            int p;

            *(char *)(s3 + 0x1864) = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
            p = *(int *)(s3 + 0x304);
            func_002A8578(s3, EM_RES_REC(p, 0x2F24), EM_RES_REC(p, 0x2F28), 0.0f, 0xA, nb, 0);
            if (*(int *)(s3 + 0x708) != 0) {
                Obj1D00_SetState_7_2(*(int *)(s3 + 0x708));
            }
            *(int *)(s3 + 0x5F4) = 1;
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
            goto L26C;
        case 4: {
            int nb;
            int p;

            *(char *)(s3 + 0x1864) = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
            p = *(int *)(s3 + 0x304);
            func_002A8578(s3, EM_RES_REC(p, 0x2F9C), EM_RES_REC(p, 0x2FA0), 0.0f, 3, nb, 0);
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
                int r = Getplayer();

                cGameObj_SetTgtTurn(s3, *(int *)(r + 0xF0), *(float *)(s3 + 0x5A8) * 0.09817477f);
                if (moveMotion(s3) != 0) {
                    *(unsigned char *)(s3 + 0x2F6) += 1;
                }
                cObjBase_addNullSpeed_Rotation(s3, 1.0f);
                cObjBase_addNullSpeed(s3, 1.0f);
            }
            break;
        case 6: {
            int nb;
            int p;

            *(char *)(s3 + 0x1864) = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
            p = *(int *)(s3 + 0x304);
            func_002A8578(s3, EM_RES_REC(p, 0x2F2C), EM_RES_REC(p, 0x2F30), 0.0f, 3, nb, 0);
            if (*(int *)(s3 + 0x708) != 0) {
                Obj1D00_SetState_7_4(*(int *)(s3 + 0x708));
            }
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
            /* fallthrough */
        case 7: {
            int r = Getplayer();

            cGameObj_SetTgtTurn(s3, *(int *)(r + 0xF0), *(float *)(s3 + 0x5A8) * 0.09817477f);
            if (moveMotion(s3) != 0) {
                cObjBase_addNullSpeed_Rotation(s3, 1.0f);
                cObjBase_addNullSpeed(s3, 1.0f);
                func_002705D8(s3);
                if (*(int *)(s3 + 0x708) != 0) {
                    Obj1D00_ClearState_7(*(int *)(s3 + 0x708));
                }
                return;
            }
            cObjBase_addNullSpeed_Rotation(s3, 1.0f);
            cObjBase_addNullSpeed(s3, 1.0f);
        } break;
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
