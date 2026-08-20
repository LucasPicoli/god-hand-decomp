/* sn-2.95.3-136 matched TU. */

extern float Tramp_001F7DF8_00101E28(void *a0);
extern void func_001B7568(void *a0, void *a1);
extern unsigned char D_005CB010;

#include "godhand/vu0.h"





__attribute__((section(".text.cOmBase_checkDamage")))
int cOmBase_checkDamage(void *a0, void *a1) {
    char buf[0x30] __attribute__((aligned(16)));
    char *self = (char *)a0;
    char *other = (char *)a1;
    float *s;
    float len;
    int dmg;
    int hp;

    {
        long v = *(unsigned int *)(self + 0x5B8);
        long b = v >> 1 & 1;

        if (b == 1) {
            return 0;
        }
    }
    if (other == 0) {
        return 0;
    }
    {
        long v = *(unsigned int *)(other + 0x60);
        long b = v & 1;

        if (b == 0) {
            return 0;
        }
    }
    func_001B7568(self, other);
    {
        long v = *(unsigned int *)(self + 0x5B8);
        long b = v >> 11 & 1;

        if (b == 1) {
            long w = *(unsigned int *)(self + 0x5B4);

            if ((w >> 1 & 1) == 0) {
                if ((w & 1) == 0) {
                    goto ret0;
                }
            }
        }
    }
    dmg = *(int *)(other + 0x4C);
    hp = *(short *)(self + 0x54A);
    if (D_005CB010 != 0) {
        dmg = dmg * 2;
    }
    hp = hp - dmg;
    if (hp >= *(short *)(self + 0x548)) {
        *(short *)(self + 0x54A) = *(unsigned short *)(self + 0x548);
    } else {
        *(short *)(self + 0x54A) = hp;
    }
    *(float *)(self + 0x54C) = 3.0f;
    VU0_LQC2(4, other + 0x10, 0x0);
    VU0_SQC2(4, buf, 0x0);
    s = (float *)(buf + 0x10);
    VU0_SQC2_VF0(buf, 0x20);
    len = Tramp_001F7DF8_00101E28(buf);
    if (len > 0.0f) {
        float inv = 1.0f / len;

        *(float *)(buf + 0x2C) = *(float *)(buf + 0xC);
        *(float *)(buf + 0x20) = *(float *)(buf + 0x0) * inv;
        *(float *)(buf + 0x24) = *(float *)(buf + 0x4) * inv;
        *(float *)(buf + 0x28) = *(float *)(buf + 0x8) * inv;
    }
    VU0_LQC2(4, buf + 0x20, 0x0);
    VU0_SQC2(4, buf, 0x10);
    {
        float *d = (float *)(buf + 0x0);

        if (d != s) {
            float x = *(float *)(buf + 0x10);
            float y = *(float *)(buf + 0x14);
            float z = *(float *)(buf + 0x18);

            *(float *)(buf + 0x0) = x;
            *(float *)(buf + 0x4) = y;
            *(float *)(buf + 0x8) = z;
        }
    }
    if (dmg > 0x3C) {
        dmg = 0x3C;
    }
    {
        float k = (float)dmg;

        VU0_LQC2(4, buf, 0x0);
        VU0_SQC2(4, buf, 0x20);
        VU0_LQC2(4, buf, 0x20);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x20);
    }
    VU0_LQC2(4, buf + 0x20, 0x0);
    VU0_SQC2(4, buf, 0x10);
    {
        float *d = (float *)(self + 0x5C0);

        if (d != s) {
            float t0 = *(float *)(buf + 0x10);
            float t1 = *(float *)(buf + 0x14);
            float t2;

            *(float *)(self + 0x5C0) = t0;
            *(volatile float *)&d[1] = t1;
            t2 = *(volatile float *)(buf + 0x18);
            d[2] = t2;
        }
    }
    return 1;
ret0:
    return 0;
}
