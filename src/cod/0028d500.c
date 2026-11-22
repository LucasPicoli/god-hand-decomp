/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/cOmWeapon.h"


/* Weapon-effect parameter loader, same shape as SetOrientByType_26AF20: a type (a2) picks six or fewer
 * floats, a count and zeroed slots in a 7 word stack vector, then cOmWeapon_setParent runs. No-op when a1 is 0.
 * The floats are block-local per case, which is what gives retail's $f0 to $f5 order. */
__attribute__((section(".text.cOmWeapon_loadEffectParamsByType")))
void cOmWeapon_loadEffectParamsByType(void *a0, int a1, unsigned int a2) {
    void *a3 = a0;
    cVec buf[2];   /* sp[0..0x1F] */
    int count;
    if (a1 == 0) {
        return;
    }
    VU0_SQC2_VF0(buf, 0x0);
    VU0_SQC2_VF0(buf, 0x10);
    switch (a2) {
    case 0:
    default:
        {
            float f0, f1, f2, f3, f4;
            f4 = -0.36f;
            f0 = 0.43f;
            f1 = -0.17f;
            f2 = 1.5707964f;
            f3 = 0.69813168f;
            count = 2;
            buf[0].x = f4; buf[0].y = f0; buf[0].z = f1; buf[1].x = f2; buf[1].z = f3;
            *(int *)((char *)buf + 0x14) = 0;
            break;
        }
    case 1:
        {
            float f0, f1, f2, f3;
            f3 = 0.71f;
            f0 = -0.044f;
            f1 = -0.054f;
            f2 = -0.52359879f;
            count = 0x10;
            buf[0].x = f3; buf[0].y = f0; buf[0].z = f1; buf[1].y = f2;
            *(int *)((char *)buf + 0x10) = 0;
            *(int *)((char *)buf + 0x18) = 0;
            break;
        }
    case 2:
        {
            float f0, f1;
            f1 = 0.0974999964f;
            f0 = 0.0189999994f;
            buf[0].y = f1; buf[0].z = f0;
            *(int *)((char *)buf + 0x0) = 0;
            count = 4;
            *(int *)((char *)buf + 0x10) = 0;
            *(int *)((char *)buf + 0x14) = 0;
            *(int *)((char *)buf + 0x18) = 0;
            break;
        }
    case 3:
        {
            float f0, f1, f2, f3, f4, f5;
            f5 = 0.18f;
            count = 0x10;
            f0 = -0.05f;
            f1 = 0.12f;
            f2 = -2.87979317f;
            f3 = -0.942477763f;
            f4 = 2.33874106f;
            buf[0].x = f5; buf[0].y = f0; buf[0].z = f1; buf[1].x = f2; buf[1].y = f3; buf[1].z = f4;
            break;
        }
    case 4:
        *(int *)((char *)buf + 0x0) = 0;
        count = 4;
        *(int *)((char *)buf + 0x4) = 0;
        *(int *)((char *)buf + 0x8) = 0;
        *(int *)((char *)buf + 0x10) = 0;
        *(int *)((char *)buf + 0x14) = 0;
        *(int *)((char *)buf + 0x18) = 0;
        break;
    case 5:
        *(int *)((char *)buf + 0x0) = 0;
        count = 2;
        *(int *)((char *)buf + 0x4) = 0;
        *(int *)((char *)buf + 0x8) = 0;
        *(int *)((char *)buf + 0x10) = 0;
        *(int *)((char *)buf + 0x14) = 0;
        *(int *)((char *)buf + 0x18) = 0;
        break;
    case 6:
        *(int *)((char *)buf + 0x0) = 0;
        count = 4;
        *(int *)((char *)buf + 0x4) = 0;
        *(int *)((char *)buf + 0x8) = 0;
        *(int *)((char *)buf + 0x10) = 0;
        *(int *)((char *)buf + 0x14) = 0;
        *(int *)((char *)buf + 0x18) = 0;
        break;
    case 7:
        *(int *)((char *)buf + 0x0) = 0;
        count = 2;
        *(int *)((char *)buf + 0x4) = 0;
        *(int *)((char *)buf + 0x8) = 0;
        *(int *)((char *)buf + 0x10) = 0;
        *(int *)((char *)buf + 0x14) = 0;
        *(int *)((char *)buf + 0x18) = 0;
        break;
    case 8:
        {
            float f0, f1, f2, f3, f4;
            f4 = 0.01f;
            count = 2;
            f0 = 0.15f;
            f1 = -0.17f;
            f2 = 1.5707964f;
            f3 = 0.610865235f;
            buf[0].x = f4; buf[0].y = f0; buf[0].z = f1; buf[1].x = f2; buf[1].z = f3;
            *(int *)((char *)buf + 0x14) = 0;
            break;
        }
    case 9:
        {
            float f0, f1, f2, f3, f4;
            f4 = 0.435f;
            count = 0x10;
            f0 = -0.037f;
            f1 = 0.296999991f;
            f2 = -0.785398185f;
            f3 = -3.14159274f;
            buf[0].x = f4; buf[0].y = f0; buf[0].z = f1; buf[1].y = f2; buf[1].z = f3;
            *(int *)((char *)buf + 0x10) = 0;
            break;
        }
    case 10:
        {
            float f0, f1, f2, f3;
            f3 = 0.1f;
            count = 0x10;
            f0 = -0.027f;
            f1 = 0.01f;
            f2 = 1.5707964f;
            buf[0].x = f3; buf[0].y = f0; buf[0].z = f1; buf[1].y = f2;
            *(int *)((char *)buf + 0x10) = 0;
            *(int *)((char *)buf + 0x18) = 0;
            break;
        }
    }
    cOmWeapon_setParent((cOmWeapon *)a1, a3, count, &buf[0], &buf[1]);
}
