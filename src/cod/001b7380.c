/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"

extern float Tramp_001F7DF8_00101E28(void *a0);
extern void func_001B7568(void *a0, void *a1);
extern unsigned char D_005CB010;






/* Apply one incoming hit: classify it, take the damage off hp (doubled while D_005CB010 is set, capped at hpMax), start the hit flash and store a knock-back vector scaled by the damage. Returns 0 when the hit is ignored. */
__attribute__((section(".text.cOmBase_checkDamage")))
int cOmBase_checkDamage(cOmBase *self, cDamageTake *hit) {
    cVec v[3] __attribute__((aligned(16)));
    cVec *s;
    float len;
    int dmg;
    int hp;

    {
        long f2 = (unsigned int)self->flags2;
        long gone = f2 >> 1 & 1;

        if (gone == 1) {
            return 0;
        }
    }
    if (hit == 0) {
        return 0;
    }
    {
        long hf = hit->flags;
        long live = hf & 1;

        if (live == 0) {
            return 0;
        }
    }
    func_001B7568(self, hit);
    {
        long f2 = (unsigned int)self->flags2;
        long b = f2 >> 11 & 1;

        if (b == 1) {
            long w = (unsigned int)self->hitFlags;

            if ((w >> 1 & 1) == 0) {
                if ((w & 1) == 0) {
                    goto ret0;
                }
            }
        }
    }
    dmg = hit->power;
    hp = self->hp;
    if (D_005CB010 != 0) {
        dmg = dmg * 2;
    }
    hp = hp - dmg;
    if (hp >= self->hpMax) {
        self->hp = (unsigned short)self->hpMax;
    } else {
        self->hp = hp;
    }
    self->hitFlash = 3.0f;
    VU0_LQC2(4, &hit->dir, 0x0);
    VU0_SQC2(4, v, 0x0);
    s = &v[1];
    VU0_SQC2_VF0(v, 0x20);
    len = Tramp_001F7DF8_00101E28(v);
    if (len > 0.0f) {
        float inv = 1.0f / len;

        v[2].w = v[0].w;
        v[2].x = v[0].x * inv;
        v[2].y = v[0].y * inv;
        v[2].z = v[0].z * inv;
    }
    VU0_LQC2(4, &v[2], 0x0);
    VU0_SQC2(4, v, 0x10);
    {
        cVec *d = &v[0];

        if (d != s) {
            float x = v[1].x;
            float y = v[1].y;
            float z = v[1].z;

            v[0].x = x;
            v[0].y = y;
            v[0].z = z;
        }
    }
    if (dmg > 0x3C) {
        dmg = 0x3C;
    }
    {
        float k = (float)dmg;

        VU0_LQC2(4, &v[0], 0x0);
        VU0_SQC2(4, v, 0x20);
        VU0_LQC2(4, v, 0x20);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, v, 0x20);
    }
    VU0_LQC2(4, &v[2], 0x0);
    VU0_SQC2(4, v, 0x10);
    {
        cVec *d = &self->knock;

        if (d != s) {
            float t0 = v[1].x;
            float t1 = v[1].y;
            float t2;

            self->knock.x = t0;
            *(volatile float *)&d->y = t1;
            t2 = *(volatile float *)&v[1].z;
            d->z = t2;
        }
    }
    return 1;
ret0:
    return 0;
}
