/* sn-2.95.3-136 matched TU. */

extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int Getplayer(void);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern char D_00462FC0[];

#include "godhand/vu0.h"

__attribute__((section(".text.func_0023A010")))
void func_0023A010(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        *(unsigned char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x1054) + p, *(int *)(p + 0x1058) + p,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *p;
            char *q;

            (*(short *)(s0 + 0x56E))--;
            p = *(char **)(s0 + 0xF0);
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}

#include "godhand/vu0.h"

__attribute__((section(".text.func_00236D98")))
void func_00236D98(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        *(unsigned char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x2EF8) + p, *(int *)(p + 0x2EFC) + p,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        *(int *)(s0 + 0x250) |= 0x40000;
        if (*(short *)(s0 + 0x56E) != 0) {
            char *p;
            char *q;

            (*(short *)(s0 + 0x56E))--;
            p = *(char **)(s0 + 0xF0);
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}
