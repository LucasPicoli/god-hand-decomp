/* sn-2.95.3-136 matched TU. */

extern int cOmWeapon_setParent();

/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/vu0.h"




__attribute__((section(".text.func_0012A8D8")))
void func_0012A8D8(void *a0) {
    char *s0 = (char *)a0;
    float buf[8]; /* sp[0..0x1C] */

    if (*(int *)(s0 + 0x698) == 0) {
        int r = func_0012A610();
        *(int *)(s0 + 0x698) = r;
        if (r == 0) {
            return;
        }
    }
    VU0_SQC2_VF0(buf, 0x0);
    VU0_SQC2_VF0(buf, 0x10);
    switch (*(unsigned short *)(*(int *)(s0 + 0x698) + 0x2FE)) {
    default:
    case 0x361:
    case 0x3B7:
        {
            float f0, f1, f2;
            f0 = -0.2f;
            f1 = -0.03f;
            f2 = 0.3f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x368:
    case 0x379:
        {
            float f0, f1, f2;
            f0 = -0.24f;
            f1 = -0.03f;
            f2 = 0.42f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x3AF:
        {
            float f0, f1, f2;
            f0 = -0.13f;
            f1 = -0.03f;
            f2 = 0.15f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x375:
        {
            float f0, f1, f2;
            f0 = -0.25f;
            f1 = -0.03f;
            f2 = 0.45f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x377:
    case 0x378:
        {
            float f0, f1, f2;
            f0 = -0.24f;
            f1 = -0.02f;
            f2 = 0.46f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x3AD:
    case 0x3B4:
        {
            float f0, f1, f2;
            f0 = -0.31f;
            f1 = -0.05f;
            f2 = 0.6f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x3A9:
        {
            float f0, f1, f2;
            f0 = -0.37f;
            f1 = -0.05f;
            f2 = 0.8f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x3AA:
    case 0x3AB:
        {
            float f0, f1, f2;
            f0 = -0.38f;
            f1 = -0.03f;
            f2 = 0.83f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x36D:
    case 0x3AE:
        {
            float f0, f1, f2;
            f0 = -0.23f;
            f1 = -0.03f;
            f2 = 0.4f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x363:
        {
            float f0, f1, f2;
            f0 = -0.3f;
            f1 = -0.07f;
            f2 = 0.4f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x3A8:
        {
            float f0, f1, f2;
            f0 = -0.37f;
            f1 = -0.04f;
            f2 = 0.81f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    case 0x37B:
    case 0x390:
        {
            float f0, f1, f2;
            f0 = -0.11f;
            f1 = -0.05f;
            f2 = 0.04f;
            buf[0] = f0; buf[1] = f1; buf[2] = f2;
        }
        break;
    }
    switch (*(unsigned short *)(*(int *)(s0 + 0x698) + 0x2FE)) {
    default:
        {
            float f0;
            f0 = -0.34906584f;
            buf[4] = 0.0f; buf[5] = f0; buf[6] = 0.0f;
        }
        break;
    case 0x377:
    case 0x378:
        {
            float f0, f1;
            f0 = 0.34906584f;
            f1 = 3.1415927f;
            buf[5] = f0; buf[6] = f1; buf[4] = 0.0f;
        }
        break;
    case 0x37B:
    case 0x390:
        {
            float f0, f1, f2;
            f0 = 0.3f;
            f1 = 3.1415927f;
            f2 = 1.5f;
            buf[4] = f0; buf[5] = f1; buf[6] = f2;
        }
        break;
    }
    cOmWeapon_setParent(*(int *)(s0 + 0x698), s0, 0xA, buf, (char *)buf + 0x10);
}
