#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);
extern float SetMotionStep(void *a0, float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int irand(void);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* sn-2.95.3-136 matched TU. */















/* Phase machine on the step byte, 80 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, Turn_dest, Adjust_theta and 6 more.
 */
__attribute__((section(".text.func_00244FC8"))) void func_00244FC8(cEm00 *self)
{
    char *s1 = (char *)self;
    int s2v, s0v;

    cCollisionSolidManage_SetActive(&D_00462FC0, s1, 0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0: {
            int gb;
            switch (*(int *)(s1 + 0x564)) {
                default:
                    if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                        int b = *(int *)(s1 + 0x304);
                        s2v = EM_RES_REC(b, 0xD80);
                        s0v = EM_RES_REC(b, 0xD84);
                    } else {
                        int b = *(int *)(s1 + 0x304);
                        s2v = EM_RES_REC(b, 0xD88);
                        s0v = EM_RES_REC(b, 0xD8C);
                    }
                    break;
                case 522:
                case 523:
                case 524:
                case 525:
                case 526:
                case 536:
                case 581:
                case 582:
                case 583:
                case 591:
                case 632:
                case 633:
                    if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                        int b = *(int *)(s1 + 0x304);
                        s2v = EM_RES_REC(b, 0x8A4);
                        s0v = EM_RES_REC(b, 0x8A8);
                    } else {
                        int b = *(int *)(s1 + 0x304);
                        s2v = EM_RES_REC(b, 0x8AC);
                        s0v = EM_RES_REC(b, 0x8B0);
                    }
                    break;
                case 517:
                case 518:
                case 519:
                case 521:
                case 543:
                case 548:
                    if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                        int b = *(int *)(s1 + 0x304);
                        s2v = EM_RES_REC(b, 0x189C);
                        s0v = EM_RES_REC(b, 0x18A0);
                    } else {
                        int b = *(int *)(s1 + 0x304);
                        s2v = EM_RES_REC(b, 0x18A4);
                        s0v = EM_RES_REC(b, 0x18A8);
                    }
                    break;
            }
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1);
            func_002A8578(s1, s2v, s0v, 0.0f, 5, gb & 0xFFFF, 0);
            moveMotion(s1);
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        case 1: {
            float r = Turn_dest(s1 + 0x580, *(float *)(s1 + 0x104),
                                *(float *)(s1 + 0x5A8) * 0.39269909f, *(void **)(s1 + 0xF0));
            *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + r;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
            if (moveMotion(s1) != 0) {
                *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            break;
        }
        case 2: {
            int gb, w;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            w = *(int *)(s1 + 0x564);
            w -= 0x205;
            switch (w) {
                default: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0xD90);
                    s0v = EM_RES_REC(b, 0xD94);
                } break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 19:
                case 64:
                case 65:
                case 66:
                case 74:
                case 115:
                case 116: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0x8B4);
                    s0v = EM_RES_REC(b, 0x8B8);
                } break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 26:
                case 31: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0x18AC);
                    s0v = EM_RES_REC(b, 0x18B0);
                } break;
            }
            func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
            if ((irand() & 1) != 0) {
                *(float *)(s1 + 0x600) = 0.0099999998f;
            } else {
                *(float *)(s1 + 0x600) = -0.019999999f;
            }
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        case 3: {
            char *v580 = s1 + 0x580;
            float r;
            float mag;
            r = Turn_dest(v580, *(float *)(s1 + 0x104), *(float *)(s1 + 0x5A8) * 0.39269909f,
                          *(void **)(s1 + 0xF0));
            *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + r;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
            SetMotionStep(s1, *(float *)(s1 + 0x5A8) * 1.5f);
            moveMotion(s1);
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            *(float *)(s1 + 0x338) = *(float *)(s1 + 0x600) * *(float *)(s1 + 0x5A8);
            cObjBase_addNullSpeed(s1, 1.0f);
            mag = capVu0MagnitudeSqXZ(*(void **)(s1 + 0xF0), v580);
            if (mag < 4.0f) {
                *(unsigned char *)(s1 + 0x2F6) = 4;
            } else if (*(float *)(s1 + 0x598) * *(float *)(s1 + 0x598) < mag) {
                *(unsigned char *)(s1 + 0x2F6) = 6;
            }
            break;
        }
        case 4: {
            int gb, w;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            w = *(int *)(s1 + 0x564);
            w -= 0x205;
            switch (w) {
                default: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0xDA0);
                    s0v = EM_RES_REC(b, 0xDA4);
                } break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 19:
                case 64:
                case 65:
                case 66:
                case 74:
                case 115:
                case 116: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0x8C4);
                    s0v = EM_RES_REC(b, 0x8C8);
                } break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 26:
                case 31: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0x18BC);
                    s0v = EM_RES_REC(b, 0x18C0);
                } break;
            }
            func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        case 5:
            *(unsigned short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
            if (moveMotion(s1) != 0) {
                int fp = *(int *)(s1 + 0xF0);
                *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x10000;
                *(float *)(fp + 4) = *(float *)(fp + 4) - 10.0f;
                *(char *)(s1 + 0x2F4) = 2;
                *(char *)(s1 + 0x2F5) = 2;
                *(char *)(s1 + 0x2F7) = 1;
                *(char *)(s1 + 0x2F6) = 0;
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            *(unsigned short *)(s1 + 0x3AC) = *(unsigned short *)(s1 + 0x3AC) | 0x400;
            break;
        case 6: {
            int gb, w;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            w = *(int *)(s1 + 0x564);
            w -= 0x205;
            switch (w) {
                default: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0xD98);
                    s0v = EM_RES_REC(b, 0xD9C);
                } break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 19:
                case 64:
                case 65:
                case 66:
                case 74:
                case 115:
                case 116: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0x8BC);
                    s0v = EM_RES_REC(b, 0x8C0);
                } break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 26:
                case 31: {
                    int b = *(int *)(s1 + 0x304);
                    s2v = EM_RES_REC(b, 0x18B4);
                    s0v = EM_RES_REC(b, 0x18B8);
                } break;
            }
            func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        case 7:
            if (moveMotion(s1) != 0) {
                func_002705D8(s1);
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            break;
    }
}
