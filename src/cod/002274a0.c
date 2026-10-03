/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_0026EE40(void *a0, int a1, int a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);
extern void func_0026BEF0(void *a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */














/* Phase machine on the step byte, 7 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * StoreMotionParamsBoth_2609A8, func_002A8578, cCoreSave_getGameLevel, func_0026EE40, moveMotion
 * and 5 more. */
__attribute__((section(".text.func_002274A0"))) void func_002274A0(cEm00 *self)
{
    char *s1 = (char *)self;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0: {
            int gb;
            char *v0;
            int a1v, a2v;
            *(char *)(s1 + 0x1864) = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(s1, 0x32, 0x21, 0x3E, -1, 0);
            v0 = *(char **)(s1 + 0x304);
            a1v = EM_RES_REC((int)v0, 0x2E0C);
            a2v = EM_RES_REC((int)v0, 0x2E10);
            *(int *)(s1 + 0x5F0) = 0;
            func_002A8578(s1, a1v, a2v, 0.0f, 0xA, gb, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    *(int *)(s1 + 0x5F0) = 0x46;
                    break;
                case 2:
                    *(int *)(s1 + 0x5F0) = 0x50;
                    break;
                case 3:
                case 4:
                    *(int *)(s1 + 0x5F0) = 0x5A;
                    break;
                case 5:
                    break;
            }
            *(int *)(s1 + 0x5FC) = 0;
            *(unsigned short *)(s1 + 0x568) = 0;
            *(int *)(s1 + 0x5F4) = 0x64;
            *(int *)(s1 + 0x5F8) = 1;
            func_0026EE40(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
            /* fallthrough */
        case 1:
            *(int *)(s1 + 0x16D0) |= 0x800000;
            if (moveMotion(s1) != 0) {
                func_002705D8(s1);
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            break;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 1) {
        if (*(int *)(s1 + 0x5F4) != 0) {
            *(int *)(s1 + 0x5F4) = 0;
            func_0026BEF0(s1, 0x15, *(short *)(s1 + 0x568));
            *(unsigned short *)(s1 + 0x568) += 1;
        }
    } else {
        *(int *)(s1 + 0x5F4) = 1;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 2) {
        func_00260B30(s1);
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 3) {
        *(int *)(s1 + 0x5FC) = 1;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) &= 0xFFFFFBFF;
    }
}
