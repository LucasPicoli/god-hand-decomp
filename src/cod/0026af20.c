/* SN ProDG ee-gcc 2.95.3 matched TU. */
/* src/cod/0026af.c — SetOrientByType_26AF20: 11-way effect-parameter loader.
 *
 * switch(a2) over a small set (0..10, case 0 == default) fills a 7-word stack
 * buffer (2x sqc2 $vf0 zero at 0x0/0x10) with per-case float literals (decoded
 * inline) + a count, then calls cOmWeapon_setParent(a1, a0, count, buf, buf+0x10).
 * Early-out when a1 == 0.
 *
 * Byte-exact under sn-2.95.3-136 (per-case float locals + complete per-case
 * stores → cc1 tail-merge reproduces the shared .L tails).  The switch
 * jump-table lives in the carved rodata blob (31B580.rodata.o, table
 * D_004455F0): compile_units[].extern_jtbl deletes the TU-emitted table and
 * redirects %hi/%lo to the blob symbol; the blob's one labeled entry
 * (.L0026AF5C) is kept as a raw word via config/jtbl_extern_words.txt. */
#include "godhand/vu0.h"

extern int cOmWeapon_setParent();

__attribute__((section(".text.SetOrientByType_26AF20")))
void SetOrientByType_26AF20(void *a0, int a1, unsigned int a2) {
    void *a3 = a0;
    float buf[7];   /* sp[0..0x18] */
    int count;
    float f0, f1, f2, f3, f4;
    if (a1 == 0) {
        return;
    }
    VU0_SQC2_VF0(buf, 0x0);
    VU0_SQC2_VF0(buf, 0x10);
    switch (a2) {
    case 0:
    default:
        f4 = -0.36f;
        f0 = 0.43f;
        f1 = -0.17f;
        f2 = 1.5707964f;
        f3 = 0.69813168f;
        count = 2;
        buf[0] = f4; buf[1] = f0; buf[2] = f1; buf[4] = f2; buf[6] = f3;
        *(int *)((char *)buf + 0x14) = 0;
        break;
    case 1:
        f3 = 0.71f;
        f0 = -0.044f;
        f1 = -0.054f;
        f2 = -0.52359879f;
        count = 0x10;
        buf[0] = f3; buf[1] = f0; buf[2] = f1; buf[5] = f2;
        *(int *)((char *)buf + 0x10) = 0;
        *(int *)((char *)buf + 0x18) = 0;
        break;
    case 2:
        f1 = 0.0974999964f;
        f0 = 0.0189999994f;
        buf[1] = f1; buf[2] = f0;
        *(int *)((char *)buf + 0x0) = 0;
        count = 4;
        *(int *)((char *)buf + 0x10) = 0;
        *(int *)((char *)buf + 0x14) = 0;
        *(int *)((char *)buf + 0x18) = 0;
        break;
    case 3:
        f4 = -0.2f;
        f0 = -0.1f;
        f1 = 0.08f;
        f2 = 2.70526028f;
        f3 = 0.69813168f;
        count = 0xA;
        buf[0] = f4; buf[1] = f0; buf[2] = f1; buf[5] = f2; buf[6] = f3;
        *(int *)((char *)buf + 0x10) = 0;
        break;
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
        f4 = 0.01f;
        count = 2;
        f0 = 0.15f;
        f1 = -0.17f;
        f2 = 1.5707964f;
        f3 = 0.610865235f;
        buf[0] = f4; buf[1] = f0; buf[2] = f1; buf[4] = f2; buf[6] = f3;
        *(int *)((char *)buf + 0x14) = 0;
        break;
    case 9:
        f4 = 0.435f;
        count = 0x10;
        f0 = -0.037f;
        f1 = 0.296999991f;
        f2 = -0.785398185f;
        f3 = -3.14159274f;
        buf[0] = f4; buf[1] = f0; buf[2] = f1; buf[5] = f2; buf[6] = f3;
        *(int *)((char *)buf + 0x10) = 0;
        break;
    case 10:
        f3 = 0.1f;
        count = 0x10;
        f0 = -0.027f;
        f1 = 0.01f;
        f2 = 1.5707964f;
        buf[0] = f3; buf[1] = f0; buf[2] = f1; buf[5] = f2;
        *(int *)((char *)buf + 0x10) = 0;
        *(int *)((char *)buf + 0x18) = 0;
        break;
    }
    cOmWeapon_setParent(a1, a3, count, buf, (char *)buf + 0x10);
}
