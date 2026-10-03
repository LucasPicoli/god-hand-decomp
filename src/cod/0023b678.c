#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int Getplayer(void);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void Obj1D00_ClearState_6(int a0);
extern void Obj1D00_ClearState_7(int a0);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0026ECD0(void *a0, int a1);
extern void func_002705D8(void *a0);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */

















/* Phase machine on the step byte, 63 case labels. Calls cSnd_SeCall_2CBA48, GetSeqSEBase,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, Obj1D00_ClearState_6, Obj1D00_ClearState_7 and
 * 8 more. */
__attribute__((section(".text.func_0023B678"))) void func_0023B678(cEm00 *self)
{
    char *s3 = (char *)self;
    int s2;
    int s1;

    *(int *)(s3 + 0x16D0) |= 0x400;
    switch (*(unsigned char *)(s3 + 0x2F6)) {
        case 0: {
            int w;
            int nb;

            *(char *)(s3 + 0x1864) = 0;
            w = *(int *)(s3 + 0x564);
            w -= 0x202;
            switch (w) {
                default: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x39C);
                    s1 = EM_RES_REC(p, 0x3A0);
                } break;
                case 0:
                case 1:
                case 17:
                case 20:
                case 21:
                case 39:
                case 40:
                case 73:
                case 84:
                case 124: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0x7C4);
                    s1 = EM_RES_REC(p, 0x7C8);
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
                case 22:
                case 67:
                case 68:
                case 69:
                case 118:
                case 119: {
                    int p = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(p, 0xB74);
                    s1 = EM_RES_REC(p, 0xB78);
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
                    s1 = EM_RES_REC(p, 0x2D74);
                    s2 = s1;
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
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
            func_002A8578(s3, s2, s1, 3, 0.0f, nb, 0);
            if (*(int *)(s3 + 0x6F0) != 0) {
                Obj1D00_ClearState_6(*(int *)(s3 + 0x6F0));
            }
            if (*(int *)(s3 + 0x708) != 0) {
                Obj1D00_ClearState_7(*(int *)(s3 + 0x708));
            }
            *(int *)(s3 + 0x16E8) += 0x3E7;
            func_0026ECD0(s3, 0);
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
            /* fallthrough */
        case 1: {
            int r = Getplayer();

            cGameObj_SetTgtTurn(s3, *(int *)(r + 0xF0), *(float *)(s3 + 0x5A8) * 0.19634955f);
            if (moveMotion(s3) != 0 || (*(unsigned short *)(s3 + 0x3AC) & 0x10) != 0) {
                if (func_00262AA8(s3) == 0) {
                    func_002705D8(s3);
                }
            }
            cObjBase_addNullSpeed_Rotation(s3, 1.0f);
            cObjBase_addNullSpeed(s3, 1.0f);
        } break;
    }
}
