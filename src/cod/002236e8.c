#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern int cEmManage_CkPlSorry(void *a0);
extern int cEmManage_CkPlCatched(void *a0);
extern int func_00275888(void *a0, float f);
extern void func_00262750(void *a0, int a1);
extern void func_00274FE8(void *a0);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);
extern int GetSeqSEBase(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern unsigned char D_005864F0[];
extern unsigned char D_005FEE00[];
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#define FRAME ((char *)va)
static __inline__ void vcopy(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}
/* Phase machine on the step byte, 50 case labels. Calls CheckSlotsShort2FEAndSetByte1864_262A10,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, cCoreSave_getGameLevel, StoreMotionParamsBoth_2609A8,
 * func_002A8578, cGameObj_SetTgtTurn and 18 more. */
__attribute__((section(".text.func_002236E8"))) void func_002236E8(cEm00 *self)
{
    float va[8];
    char *s1 = (char *)self;
    int gb;
    int s2, self;
    float one;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10();
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0:
            *(char *)(s1 + 0x1864) = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            switch (*(int *)(s1 + 0x564)) {
                default: {
                    char *v = *(char **)(s1 + 0x304);
                    s2 = EM_RES_REC((int)v, 0x98C);
                    self = EM_RES_REC((int)v, 0x990);
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
                        char *w = *(char **)(s1 + 0x304);
                        self = EM_RES_REC((int)w, 0x994);
                    }
                    StoreMotionParamsBoth_2609A8(s1, 0x28, 0xA, 0x41, 0, 0xF5);
                    *(int *)(s1 + 0x5C0) = 0;
                    *(int *)(s1 + 0x5C4) = 0;
                    *(float *)(s1 + 0x5C8) = 0.5f;
                    *(float *)(s1 + 0x5CC) = 1.0f;
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        case 1:
                        default:
                            *(float *)(s1 + 0x5C8) = 0.5f;
                            break;
                        case 2:
                            *(float *)(s1 + 0x5C8) = 0.75f;
                            break;
                        case 3:
                            *(float *)(s1 + 0x5C8) = 0.75f;
                            break;
                        case 4:
                            *(float *)(s1 + 0x5C8) = 0.75f;
                            break;
                        case 5:
                            *(float *)(s1 + 0x5C8) = 1.0f;
                            break;
                    }
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        case 1:
                        default:
                            *(int *)(s1 + 0x5F0) = 0x1E;
                            break;
                        case 2:
                            *(int *)(s1 + 0x5F0) = 0x23;
                            break;
                        case 3:
                            *(int *)(s1 + 0x5F0) = 0x28;
                            break;
                        case 4:
                            *(int *)(s1 + 0x5F0) = 0x28;
                            break;
                        case 5:
                            *(int *)(s1 + 0x5F0) = 0x3E7;
                            break;
                    }
                } break;
                case 0x250:
                case 0x251: {
                    char *v = *(char **)(s1 + 0x304);
                    s2 = EM_RES_REC((int)v, 0x19F4);
                    self = EM_RES_REC((int)v, 0x19F8);
                    *(float *)(s1 + 0x5C8) = 0.400000006f;
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 5) {
                        char *w = *(char **)(s1 + 0x304);
                        self = EM_RES_REC((int)w, 0x19FC);
                        *(float *)(s1 + 0x5C8) = 0.75f;
                    }
                    StoreMotionParamsBoth_2609A8(s1, 0x3C, 0xA, 0x44, 0, 0xF5);
                    *(int *)(s1 + 0x5C0) = 0;
                    *(int *)(s1 + 0x5C4) = 0;
                    *(float *)(s1 + 0x5C8) = 0.5f;
                    *(float *)(s1 + 0x5CC) = 1.0f;
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        case 1:
                        default:
                            *(float *)(s1 + 0x5C8) = 0.800000012f;
                            break;
                        case 2:
                            *(float *)(s1 + 0x5C8) = 1.20000005f;
                            break;
                        case 3:
                            *(float *)(s1 + 0x5C8) = 1.20000005f;
                            break;
                        case 4:
                            *(float *)(s1 + 0x5C8) = 1.20000005f;
                            break;
                        case 5:
                            *(float *)(s1 + 0x5C8) = 1.60000002f;
                            break;
                    }
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        case 1:
                        default:
                            *(int *)(s1 + 0x5F0) = 0x14;
                            break;
                        case 2:
                            *(int *)(s1 + 0x5F0) = 0x19;
                            break;
                        case 3:
                            *(int *)(s1 + 0x5F0) = 0x1E;
                            break;
                        case 4:
                            *(int *)(s1 + 0x5F0) = 0x1E;
                            break;
                        case 5:
                            *(int *)(s1 + 0x5F0) = 0x19;
                            break;
                    }
                } break;
            }
            func_002A8578(s1, s2, self, 0.0f, 10, gb, 0);
            *(int *)(s1 + 0x5FC) = 0;
            *(unsigned char *)(s1 + 0x2F6) += 1;
            /* fallthrough */
        case 1:
            if (*(int *)(s1 + 0x5F0) != 0) {
                *(int *)(s1 + 0x5F0) -= 1;
                cGameObj_SetTgtTurn(s1, *(int *)(Getplayer() + 0xF0),
                                    *(float *)(s1 + 0x5A8) * 0.19634955f);
            }
            if (moveMotion(s1) != 0)
                *(unsigned char *)(s1 + 0x2F6) += 1;
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            break;
        case 2:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            switch (*(int *)(s1 + 0x564)) {
                default: {
                    char *v = *(char **)(s1 + 0x304);
                    s2 = EM_RES_REC((int)v, 0x998);
                    self = EM_RES_REC((int)v, 0x99C);
                } break;
                case 0x250:
                case 0x251: {
                    char *v = *(char **)(s1 + 0x304);
                    s2 = EM_RES_REC((int)v, 0x1A00);
                    self = EM_RES_REC((int)v, 0x1A04);
                } break;
                case 0x24F:
                case 0x20C: {
                    char *v = *(char **)(s1 + 0x304);
                    s2 = EM_RES_REC((int)v, 0x1F68);
                    self = EM_RES_REC((int)v, 0x1F6C);
                } break;
            }
            func_002A8578(s1, s2, self, 0.0f, 2, gb, 0);
            *(int *)(s1 + 0x5F0) = 4;
            *(float *)(s1 + 0x5D0) = 99999.9f;
            *(float *)(s1 + 0x5D4) = 99999.9f;
            *(float *)(s1 + 0x5D8) = 99999.9f;
            *(unsigned char *)(s1 + 0x2F6) += 1;
            *(int *)(s1 + 0x5F4) = 0;
            /* fallthrough */
        case 3:
            if (moveMotion(s1) != 0) {
                *(int *)(s1 + 0x5F0) -= 1;
                if (*(int *)(s1 + 0x5F0) <= 0) {
                    switch (*(int *)(s1 + 0x564)) {
                        case 0x20C:
                        case 0x24F:
                        case 0x250:
                        case 0x251:
                            *(unsigned char *)(s1 + 0x2F6) = 6;
                            break;
                        default:
                            *(unsigned char *)(s1 + 0x2F6) = 4;
                            break;
                    }
                }
            }
            {
                float k = *(float *)(s1 + 0x5A8);
                char *cp = FRAME + 0x10;
                VU0_LQC2(4, s1 + 0x5C0, 0);
                VU0_SQC2(4, FRAME, 0x10);
                VU0_LQC2(4, FRAME, 0x10);
                VU0_LOAD_SCALAR(5, k);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, FRAME, 0x10);
                VU0_LQC2(4, cp, 0);
                VU0_SQC2(4, FRAME, 0);
                vcopy((float *)(s1 + 0x330), va);
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            if (*(int *)(*(int *)(s1 + 0x670) + 0x34) != 0) {
                switch (*(int *)(s1 + 0x564)) {
                    case 0x250:
                    case 0x251:
                        break;
                    default:
                        *(unsigned char *)(s1 + 0x2F6) = 6;
                        break;
                }
            }
            if (*(unsigned char *)(s1 + 0x1864) != 0)
                *(unsigned char *)(s1 + 0x2F6) = 6;
            if (cEmManage_CkPlSorry(D_005864F0) != 0 || cEmManage_CkPlCatched(D_005864F0) != 0)
                *(unsigned char *)(s1 + 0x2F6) = 6;
            if (func_00275888(s1, 2.0f) != 0) {
                *(unsigned char *)(s1 + 0x2F6) = 6;
                if (*(int *)(s1 + 0x564) >= 0x250 && *(int *)(s1 + 0x564) < 0x252) {
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5 &&
                        *(float *)(s1 + 0x618) > 64.0f && *(unsigned char *)(s1 + 0x2F7) == 0) {
                        *(unsigned char *)(s1 + 0x2F7) = 1;
                        *(unsigned char *)(s1 + 0x2F6) = 8;
                    }
                }
            }
            func_00262750(s1, 1);
            break;
        case 4:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            {
                char *v = *(char **)(s1 + 0x304);
                func_002A8578(s1, EM_RES_REC((int)v, 0x9A0), EM_RES_REC((int)v, 0x9A4), 0.0f, 2, gb,
                              0);
            }
            *(int *)(s1 + 0x5F0) = 5;
            *(unsigned char *)(s1 + 0x2F6) += 1;
            /* fallthrough */
        case 5:
            if (moveMotion(s1) != 0) {
                func_00274FE8(s1);
                return;
            }
            if (*(int *)(*(int *)(s1 + 0x670) + 0x34) != 0)
                *(unsigned char *)(s1 + 0x2F6) = 6;
            *(float *)(s1 + 0x5C8) = *(float *)(s1 + 0x5C8) * 0.949999988f;
            vcopy((float *)(s1 + 0x330), (float *)(s1 + 0x5C0));
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            break;
        case 6:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            switch (*(int *)(s1 + 0x564)) {
                case 0x20C:
                case 0x24F:
                case 0x250:
                case 0x251: {
                    char *v = *(char **)(s1 + 0x304);
                    s2 = EM_RES_REC((int)v, 0xCF0);
                    self = EM_RES_REC((int)v, 0xCF4);
                } break;
                default: {
                    char *v = *(char **)(s1 + 0x304);
                    s2 = EM_RES_REC((int)v, 0x9A8);
                    self = EM_RES_REC((int)v, 0x9AC);
                } break;
            }
            func_002A8578(s1, s2, self, 0.0f, 2, gb, 0);
            *(unsigned char *)(s1 + 0x2F6) += 1;
            *(int *)(s1 + 0x5F0) = 5;
            /* fallthrough */
        case 7:
            if (moveMotion(s1) != 0 || ((*(unsigned short *)(s1 + 0x3AC) & 0x10) &&
                                        cCoreSave_getGameLevel(&D_00569B70) >= 2)) {
                switch (*(int *)(s1 + 0x564)) {
                    case 0x20C:
                    case 0x24F:
                    case 0x250:
                    case 0x251:
                        func_002705D8(s1);
                        break;
                    default:
                        func_00274FE8(s1);
                        break;
                }
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            break;
        case 8:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)(GetSeqSEBase(s1) + 6), s1, 0, 0, 0, 0);
            {
                char *v = *(char **)(s1 + 0x304);
                func_002A8578(s1, EM_RES_REC((int)v, 0x1A08), EM_RES_REC((int)v, 0x1A0C), 0.0f, 2,
                              gb, 0);
            }
            *(int *)(s1 + 0x5F0) = 5;
            *(unsigned char *)(s1 + 0x2F6) += 1;
            /* fallthrough */
        case 9:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x10) {
                cGameObj_SetTgtTurn(s1, *(int *)(Getplayer() + 0xF0),
                                    *(float *)(s1 + 0x5A8) * 0.392699093f);
            }
            if (moveMotion(s1) != 0)
                *(unsigned char *)(s1 + 0x2F6) = 2;
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            break;
    }
    func_00260B30(s1);
    if (*(unsigned short *)(s1 + 0x3AC) & 3) {
        *(int *)(s1 + 0x16F8) = 10;
        *(int *)(s1 + 0x5FC) = 1;
        *(int *)(s1 + 0x16D0) |= 0x1000;
    }
    if (*(int *)(s1 + 0x5FC) != 0)
        *(int *)(s1 + 0x16D4) &= 0xFFFFFBFF;
}
