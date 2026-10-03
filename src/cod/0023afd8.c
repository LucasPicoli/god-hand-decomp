#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int Getplayer(void);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void Obj1D00_ClearState_6(int a0);
extern void Obj1D00_ClearState_7(int a0);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */




















/* Phase machine on the step byte, 122 case labels. Calls ReleaseField6ECByTag564_26B1E8,
 * cSnd_SeCall_2CBA48, GetSeqSEBase, Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, irand and 11
 * more. */
__attribute__((section(".text.func_0023AFD8"))) void func_0023AFD8(cEm00 *self)
{
    char *s3 = (char *)self;
    int s2;
    int s1;

    *(int *)(s3 + 0x16D0) |= 0x400;
    switch (*(unsigned char *)(s3 + 0x2F6)) {
        case 0: {
            int w;
            int nb;
            float fz;

            *(char *)(s3 + 0x1864) = 0;
            w = *(int *)(s3 + 0x564);
            w -= 0x202;
            switch (w) {
                default: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x39C);
                    s1 = EM_RES_REC(p, 0x3A0);
                } break;
                case 18:
                case 19: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1B80);
                    s1 = EM_RES_REC(p, 0x1B84);
                } break;
                case 0:
                case 1:
                case 17:
                case 20:
                case 21:
                case 39:
                case 40:
                case 73: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x7C4);
                    s1 = EM_RES_REC(p, 0x7C8);
                } break;
                case 84:
                case 124: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x2BA8);
                    s1 = EM_RES_REC(p, 0x2BAC);
                } break;
                case 64:
                case 65:
                case 66: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3698);
                    s1 = EM_RES_REC(p, 0x369C);
                } break;
                case 8:
                case 11:
                case 12:
                case 67:
                case 69: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0xB74);
                    s1 = EM_RES_REC(p, 0xB78);
                } break;
                case 118: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3C0C);
                    s1 = EM_RES_REC(p, 0x3C10);
                } break;
                case 22:
                case 68:
                case 119: {
                    int p;
                    ReleaseField6ECByTag564_26B1E8(s3);
                    p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3C1C);
                    s1 = EM_RES_REC(p, 0x3C20);
                } break;
                case 9: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1E34);
                    s1 = EM_RES_REC(p, 0x1E38);
                } break;
                case 10:
                case 77: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1F80);
                    s1 = EM_RES_REC(p, 0x1F84);
                } break;
                case 3:
                case 4:
                case 5:
                case 6:
                case 34: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x17D8);
                    s1 = EM_RES_REC(p, 0x17DC);
                } break;
                case 63: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3AFC);
                    s1 = EM_RES_REC(p, 0x3B00);
                } break;
                case 7:
                case 29: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x345C);
                    s1 = EM_RES_REC(p, 0x3460);
                } break;
                case 78:
                case 79: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1A18);
                    s1 = EM_RES_REC(p, 0x1A1C);
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(s3) + 0x23), s3, 0, 0,
                                       0, 0);
                } break;
                case 94: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1A18);
                    s1 = EM_RES_REC(p, 0x1A1C);
                } break;
                case 98: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x326C);
                    s1 = EM_RES_REC(p, 0x3270);
                } break;
                case 99: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3724);
                    s1 = EM_RES_REC(p, 0x3728);
                } break;
                case 30:
                case 31:
                case 32: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1D50);
                    s1 = EM_RES_REC(p, 0x1D54);
                } break;
                case 33: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x2ECC);
                    s1 = EM_RES_REC(p, 0x2ED0);
                } break;
                case 115:
                case 116: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x23A8);
                    s1 = EM_RES_REC(p, 0x23AC);
                } break;
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 35:
                case 42:
                case 43:
                case 44:
                case 45:
                case 70:
                case 71:
                case 74:
                case 75:
                case 76:
                case 80:
                case 88: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x13B8);
                    s1 = EM_RES_REC(p, 0x13BC);
                } break;
            }
            fz = 0.0f;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
            func_002A8578(s3, s2, s1, 3, fz, nb, 0);
            *(int *)(s3 + 0x5F0) = irand() % 0x1E + 0x1E;
            {
                int t = *(int *)(s3 + 0x564);
                if (t == 0x250 || t == 0x251) {
                    *(int *)(s3 + 0x5F0) = 0x3C;
                }
            }
            if ((irand() & 3) != 0) {
                *(int *)(s3 + 0x5F0) = 0x14;
            }
            *(float *)(s3 + 0x604) = fz;
            if (*(unsigned char *)(s3 + 0x2F7) != 0) {
                *(float *)(s3 + 0x604) = -0.3f;
            }
            if (*(int *)(s3 + 0x6F0) != 0) {
                Obj1D00_ClearState_6(*(int *)(s3 + 0x6F0));
            }
            if (*(int *)(s3 + 0x708) != 0) {
                Obj1D00_ClearState_7(*(int *)(s3 + 0x708));
            }
            *(int *)(s3 + 0x5F0) = 5;
            *(float *)(s3 + 0x600) = 15.0f;
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
            /* fallthrough */
        case 1: {
            int c;

            *(int *)(s3 + 0x16D0) |= 0x2000;
            c = *(int *)(s3 + 0x5F0);
            if (c != 0) {
                int r;
                *(int *)(s3 + 0x5F0) = c - 1;
                r = Getplayer();
                cGameObj_SetTgtTurn(s3, *(int *)(r + 0xF0), *(float *)(s3 + 0x5A8) * 0.39269909f);
            }
            moveMotion(s3);
            {
                float d = *(float *)(s3 + 0x5A8);
                float e = *(float *)(s3 + 0x604);
                *(float *)(s3 + 0x338) = *(float *)(s3 + 0x338) + e * d;
                *(float *)(s3 + 0x604) = e * (1.0f - d * 0.3f);
            }
            cObjBase_addNullSpeed_Rotation(s3, 1.0f);
            cObjBase_addNullSpeed(s3, 1.0f);
            if (*(float *)(s3 + 0x173C) <= 0.0f) {
                float t = *(float *)(s3 + 0x600) - *(float *)(s3 + 0x5A8);
                *(float *)(s3 + 0x600) = t;
                if (t <= 0.0f) {
                    if (func_00262AA8(s3) != 0) {
                        break;
                    }
                    *(unsigned char *)(s3 + 0x2F6) = 2;
                }
            }
            if (func_00274150(s3) == 0) {
                if (!(*(float *)(s3 + 0x1734) > 0.0f)) {
                    break;
                }
            }
            *(unsigned char *)(s3 + 0x2F7) = 0;
            *(unsigned char *)(s3 + 0x2F4) = 0;
            *(unsigned char *)(s3 + 0x2F6) = 0;
            *(unsigned char *)(s3 + 0x2F5) = 0x89;
        } break;
        case 2: {
            int nb;

            switch (*(int *)(s3 + 0x564)) {
                default: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3A4);
                    s1 = EM_RES_REC(p, 0x3A8);
                } break;
                case 0x214:
                case 0x215: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1B88);
                    s1 = EM_RES_REC(p, 0x1B8C);
                } break;
                case 0x256:
                case 0x27E: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x2BB8);
                    s1 = EM_RES_REC(p, 0x2BBC);
                } break;
                case 0x242:
                case 0x243:
                case 0x244: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x36A0);
                    s1 = EM_RES_REC(p, 0x36A4);
                } break;
                case 0x20A:
                case 0x20D:
                case 0x20E:
                case 0x245:
                case 0x247: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0xB7C);
                    s1 = EM_RES_REC(p, 0xB80);
                } break;
                case 0x278: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3C14);
                    s1 = EM_RES_REC(p, 0x3C18);
                } break;
                case 0x218:
                case 0x246:
                case 0x279: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3C24);
                    s1 = EM_RES_REC(p, 0x3C28);
                } break;
                case 0x250:
                case 0x251: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1A20);
                    s1 = EM_RES_REC(p, 0x1A24);
                } break;
                case 0x260: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1A20);
                    s1 = EM_RES_REC(p, 0x1A24);
                } break;
                case 0x264: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x326C);
                    s1 = EM_RES_REC(p, 0x3270);
                } break;
                case 0x265: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3724);
                    s1 = EM_RES_REC(p, 0x3728);
                } break;
                case 0x20B: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1E3C);
                    s1 = EM_RES_REC(p, 0x1E40);
                } break;
                case 0x20C:
                case 0x24F: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1F88);
                    s1 = EM_RES_REC(p, 0x1F8C);
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x17E8);
                    s1 = EM_RES_REC(p, 0x17EC);
                } break;
                case 0x241: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x3B0C);
                    s1 = EM_RES_REC(p, 0x3B10);
                } break;
                case 0x209:
                case 0x21F: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x346C);
                    s1 = EM_RES_REC(p, 0x3470);
                } break;
                case 0x220:
                case 0x221:
                case 0x222: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x1D58);
                    s1 = EM_RES_REC(p, 0x1D5C);
                } break;
                case 0x223: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x2ED4);
                    s1 = EM_RES_REC(p, 0x2ED8);
                } break;
                case 0x275:
                case 0x276: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x23B0);
                    s1 = EM_RES_REC(p, 0x23B4);
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
                case 0x252:
                case 0x25A: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x13C0);
                    s1 = EM_RES_REC(p, 0x13C4);
                } break;
            }
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
            func_002A8578(s3, s2, s1, 0xA, 0.0f, nb, 0);
            *(float *)(s3 + 0x600) = 10.0f;
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
            /* fallthrough */
        case 3: {
            float v = *(float *)(s3 + 0x600);

            if (v > 0.0f) {
                *(int *)(s3 + 0x16D0) |= 0x2000;
                *(float *)(s3 + 0x600) = v - *(float *)(s3 + 0x5A8);
            }
            if (moveMotion(s3) != 0) {
                func_0026EE40(s3, 0, 0);
                func_002705D8(s3);
            } else {
                cObjBase_addNullSpeed_Rotation(s3, 1.0f);
                cObjBase_addNullSpeed(s3, 1.0f);
            }
        } break;
    }
}
