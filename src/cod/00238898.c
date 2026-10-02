/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_002DB770(void);
extern char D_00462FC0[];
extern char D_007474A0[];

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"














__attribute__((section(".text.func_00238898")))
void func_00238898(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Getplayer();

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        *(char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3224) + p, *(int *)(p + 0x3228) + p,
                      0.0f, 0, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(short *)(s0 + 0x568) = 0x1E; break;
        case 2: *(short *)(s0 + 0x568) = 0x23; break;
        case 3: case 4: *(short *)(s0 + 0x568) = 0x28; break;
        case 5: *(short *)(s0 + 0x568) = 0x2D; break;
        }
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q;
            int p0;

            (*(short *)(s0 + 0x56E))--;
            q = s1 + 0x550;
            p0 = *(int *)(s0 + 0xF0);
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 2:
    {
        int p;

        *(char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x322C) + p, *(int *)(p + 0x3230) + p,
                      0.0f, 0, 0, 0);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
        cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 4;
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (*(short *)(s1 + 0x54A) > 0) {
            char *g;

            func_002DB770();
            g = D_007474A0;
            if ((*(int *)(g + 8) & 0xF0) != 0) {
                (*(short *)(s0 + 0x568))--;
            }
            if ((*(int *)(g + 8) & 0xF00000) != 0) {
                *(short *)(s0 + 0x568) -= 4;
            }
            if (*(short *)(s0 + 0x568) <= 0) {
                *(unsigned char *)(s0 + 0x2F6) = 6;
                *(unsigned char *)(s1 + 0x2F6) = 6;
            }
        }
        break;
    case 4:
    {
        int p;

        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3234) + p, *(int *)(p + 0x3238) + p,
                      0.0f, 3, 0, 0);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 5:
        cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
        *(short *)(s0 + 0x434) |= 8;
        *(float *)(s0 + 0x54C) = 3.0f;
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 6:
    {
        int p;

        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x323C) + p, *(int *)(p + 0x3240) + p,
                      0.0f, 3, 0, 0);
        *(short *)(s0 + 0x568) = 0x1E;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 7:
        if (*(short *)(s0 + 0x568) != 0) {
            (*(short *)(s0 + 0x568))--;
            cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
            *(float *)(s0 + 0x54C) = 3.0f;
        }
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
            return;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}
