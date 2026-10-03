#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int GetSeqSEBase(void *a0);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern unsigned char D_005FEE00[];
extern int D_00462FC0;

/* Phase machine on the step byte, 6 case labels. Calls cCollisionSolidManage_SetActive,
 * func_002A8578, cSnd_SeCall_2CBA48, GetSeqSEBase, moveMotion, cObjBase_addNullSpeed_Rotation and 2
 * more. */
__attribute__((section(".text.func_0025A920"))) void func_0025A920(cEm00 *self)
{
    char *s1 = (char *)self;

    cCollisionSolidManage_SetActive(&D_00462FC0, s1, 0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0: {
            int b = *(int *)(s1 + 0x304);

            func_002A8578(s1, EM_RES_REC(b, 0x1084), EM_RES_REC(b, 0x1088), 0.0f, 3, 0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase(s1), s1, 0, 0, 0, 0);
            *(unsigned char *)(s1 + 0x1866) = *(unsigned char *)(s1 + 0x1866) + 1;
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        case 1:
            if (moveMotion(s1) != 0) {
                *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            break;
        case 2: {
            int b = *(int *)(s1 + 0x304);

            func_002A8578(s1, EM_RES_REC(b, 0x107C), EM_RES_REC(b, 0x1080), 0.0f, 3, 0, 0);
            *(float *)(s1 + 0x600) = 150.0f;
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        case 3:
            moveMotion(s1);
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            *(float *)(s1 + 0x600) = *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
            if (*(float *)(s1 + 0x600) <= 0.0f) {
                *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
            }
            break;
        case 4: {
            int b = *(int *)(s1 + 0x304);

            func_002A8578(s1, EM_RES_REC(b, 0x1094), EM_RES_REC(b, 0x1098), 0.0f, 3, 0, 0);
            *(float *)(s1 + 0x54C) = 5.0f;
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        case 5:
            if (moveMotion(s1) != 0) {
                func_002705D8(s1);
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            break;
    }
    *(short *)(s1 + 0x3AC) = *(short *)(s1 + 0x3AC) | 0x400;
}
