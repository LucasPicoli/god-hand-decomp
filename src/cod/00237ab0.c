/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

/* sn-2.95.3-136 matched TU. */

extern int Getplayer(void);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern unsigned int irand(void);
extern int moveMotion(void *a0);
extern void func_00274FE8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002376C0(void);
extern char D_00462FC0[];
extern char D_00568288[];
extern int D_007474A8;

extern void cActionButton_set(void *a0, int a1, int a2,
                                                       int a3, void *t0, void *t1,
                                                       int t2);






__attribute__((section(".text.func_00237AB0")))
void func_00237AB0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
    *(int *)(s0 + 0x16D0) |= 0x21000;
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x2118) + w, *(int *)(w + 0x211C) + w,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x568) = 0;
        *(short *)(s0 + 0x56E) = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            *(short *)(s0 + 0x56A) = 0x39;
            break;
        case 2:
            *(short *)(s0 + 0x56A) = 0x3E;
            break;
        case 3:
            *(short *)(s0 + 0x56A) = 0x43;
            break;
        case 4:
            *(short *)(s0 + 0x56A) = 0x43;
            break;
        case 5:
            *(short *)(s0 + 0x56A) = 0x48;
            break;
        }
        *(short *)(s0 + 0x56C) = irand() & 3;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        if (moveMotion(s0)) {
            func_00274FE8(s0);
            return;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (*(short *)(s0 + 0x56A) != 0) {
            *(short *)(s0 + 0x56A) = *(unsigned short *)(s0 + 0x56A) - 1;
        } else if (*(short *)(s1 + 0x54A) > 0 && *(short *)(s0 + 0x568) == 0) {
            switch (*(short *)(s0 + 0x56C)) {
            default:
            case 0:
                if ((D_007474A8 & 0xD0) != 0)
                    *(short *)(s0 + 0x56A) = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           0, func_002376C0, s0, 0);
                break;
            case 1:
                if ((D_007474A8 & 0xE0) != 0)
                    *(short *)(s0 + 0x56A) = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           1, func_002376C0, s0, 0);
                break;
            case 2:
                if ((D_007474A8 & 0xB0) != 0)
                    *(short *)(s0 + 0x56A) = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           2, func_002376C0, s0, 0);
                break;
            case 3:
                if ((D_007474A8 & 0x70) != 0)
                    *(short *)(s0 + 0x56A) = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           3, func_002376C0, s0, 0);
                break;
            }
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 0x10) {
            *(short *)(s0 + 0x56A) = 0x3E7;
            if (*(short *)(s0 + 0x568) == 0 || *(short *)(s1 + 0x54A) <= 0) {
                *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
                *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
            }
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            int vt = *(int *)(s0 + 0x214);
            short off = *(short *)(vt + 0xA8);
            int (*fp)() = *(int (**)())(vt + 0xAC);
            fp(s0 + off, 0x32, 0, 0, 0);
            if (*(short *)(s0 + 0x54A) <= 0)
                *(short *)(s0 + 0x54A) = 1;
        }
        break;
    case 2: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x2120) + w, *(int *)(w + 0x2124) + w,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0x3C;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(s0)) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}
