#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f, int t0, int t1);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(char *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern char D_005FEE00[];

/* Phase machine on the step byte, 6 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, Getplayer, cGameObj_SetTgtTurn, moveMotion, cObjBase_addNullSpeed_Rotation and 3
 * more. */
__attribute__((section(".text.func_0022B9E0"))) void func_0022B9E0(cEm00 *self)
{
    char *p = (char *)self;
    float d;

    *(char *)(p + 0x186A) = 2;
    *(int *)(p + 0x16D0) = *(int *)(p + 0x16D0) | 0x400;
    *(int *)(p + 0x16D4) = *(int *)(p + 0x16D4) | 0x400;
    switch (*(unsigned char *)(p + 0x2F6)) {
        case 0: {
            int gb;
            int b;

            *(char *)(p + 0x1864) = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF;
            b = *(int *)(p + 0x304);
            func_002A8578(p, EM_RES_REC(b, 0x2200), EM_RES_REC(b, 0x2204), 3, 0.0f, gb, 0);
            *(int *)(p + 0x5FC) = 0;
            *(short *)(p + 0x56A) = 0;
            *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
        }
        case 1:
            if (*(unsigned char *)(p + 0x2F7) == 0) {
                char *h = Getplayer();

                cGameObj_SetTgtTurn(p, *(int *)(h + 0xF0), *(float *)(p + 0x5A8) * 0.19634955f);
            }
            if (moveMotion(p) != 0) {
                *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
            }
            cObjBase_addNullSpeed_Rotation(p, 1.0f);
            cObjBase_addNullSpeed(p, 1.0f);
            break;
        case 2: {
            int gb;
            int b;
            float z = 0.0f;

            *(char *)(p + 0x1864) = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF;
            b = *(int *)(p + 0x304);
            func_002A8578(p, EM_RES_REC(b, 0x2208), EM_RES_REC(b, 0x220C), 3, z, gb, 0);
            *(float *)(p + 0x600) = z;
            *(int *)(p + 0x5F8) = 1;
            *(short *)(p + 0x568) = 1;
            *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
        }
        case 3:
            if (*(unsigned char *)(p + 0x2F7) == 0) {
                int t = *(int *)(p + 0x5F0);

                if (t != 0) {
                    char *h;

                    *(int *)(p + 0x5F0) = t - 1;
                    h = Getplayer();
                    cGameObj_SetTgtTurn(p, *(int *)(h + 0xF0),
                                        *(float *)(p + 0x5A8) * 0.049087387f);
                }
            }
            if (moveMotion(p) != 0) {
                int n = *(unsigned short *)(p + 0x568) - 1;

                *(short *)(p + 0x568) = n;
                if ((int)(n << 16) <= 0) {
                    *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
                }
            }
            cObjBase_addNullSpeed_Rotation(p, 1.0f);
            cObjBase_addNullSpeed(p, 1.0f);
            break;
        case 4: {
            int gb;
            int b;

            *(char *)(p + 0x1864) = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF;
            b = *(int *)(p + 0x304);
            func_002A8578(p, EM_RES_REC(b, 0x2210), EM_RES_REC(b, 0x2214), 3, 0.0f, gb, 0);
            *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
        }
        case 5:
            if (moveMotion(p) != 0) {
                unsigned char t = *(unsigned char *)(p + 0x2F7);

                *(char *)(p + 0x2F5) = 0x6B;
                *(char *)(p + 0x2F7) = t;
                *(char *)(p + 0x2F4) = 0;
                *(char *)(p + 0x2F6) = 0;
            }
            cObjBase_addNullSpeed_Rotation(p, 1.0f);
            cObjBase_addNullSpeed(p, 1.0f);
            break;
    }
    d = *(float *)(p + 0x600);
    if (0.0f < d) {
        *(float *)(p + 0x600) = d - *(float *)(p + 0x5A8);
    } else if ((*(unsigned short *)(p + 0x3AC) & 1) != 0) {
        func_0026BEF0(p, 6, 0);
        *(float *)(p + 0x600) = 3.0f;
        cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x22, p, 0, 0, 0, 0);
    }
    if ((*(unsigned short *)(p + 0x3AC) & 3) != 0) {
        *(int *)(p + 0x5FC) = 1;
    }
    if (*(int *)(p + 0x5FC) != 0) {
        *(int *)(p + 0x16D4) = *(int *)(p + 0x16D4) & 0xFFFFFBFFU;
    }
}
