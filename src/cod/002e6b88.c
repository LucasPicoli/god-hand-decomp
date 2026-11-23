/* sn-2.95.3-136 matched TU. */

extern float capVu0LengthSq(void *a0);
extern float capVu0Atan2(float y, float x);
extern float sqrtf(float x);
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern void *CopyVec16From20_B62E0(void *dst, char *self);
extern void UpdateObjByIndexedOp_2FBE50(void *self);
extern void cNode_setTranslationFromWorld(void *self, void *v);

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cObjBase.h"










typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;


typedef struct Frame {
    Vec4 a;               /* 0x00 */
    Vec4 b;               /* 0x10 */
    Vec4 c;               /* 0x20 */
    cEffectParam s;       /* 0x30 */
    Vec4 d;               /* 0xB0 */
} Frame;

__attribute__((section(".text.func_002E6B88")))
void func_002E6B88(void *arg, float thr) {
    Frame fr;
    char *self = (char *)arg;
    cEffectParam *e;
    float h;
    float t;
    int st;

    VU0_SQC2_VF0(&fr, 0x00);
    VU0_SQC2_VF0(&fr, 0x10);
    StoreVecFromFieldB0_2B6160(&fr.c, self);
    if ((void *)&fr.a != (void *)&fr.c) {
        fr.a.x = fr.c.x;
        fr.a.y = fr.c.y;
        fr.a.z = fr.c.z;
    }
    CopyVec16From20_B62E0(&fr.c, self);
    h = fr.c.y * 0.5f;
    fr.b.x = fr.c.x;
    fr.b.z = fr.c.z;
    fr.b.y = fr.c.y;
    if (fr.a.y - h < thr) {
        st = *(int *)(self + 0x2D8);
        fr.a.y = thr + h;
        if (st == 1 || st == 2) {
            e = &fr.s;
            e->color.x = 1.0f;
            e->color.y = 1.0f;
            e->color.z = 1.0f;
            e->color.w = 1.0f;
            VU0_SQC2_VF0(&fr, 0x40);
            VU0_SQC2_VF0(&fr, 0x50);
            {
                float *q = &e->scale.x;
                q[0] = 1.0f;
                q[1] = 1.0f;
                q[2] = 1.0f;
                q[3] = 1.0f;
            }
            e->size = 1.0f;
            fr.s.unk44 = 0;
            fr.s.flags = 0;
            e->unk4C = -1;
            fr.s.unk4D = 0;
            fr.s.unk4E = 0;
            e->unk4F = 0xFF;
            fr.s.unk50 = 0;
            VU0_SQC2_VF0(&fr, 0x90);
            fr.s.unk70 = 0;
            fr.s.unk72 = 0;
            fr.s.unk74 = 0;
            fr.s.unk78 = 0;
            VU0_SQC2_VF0(&fr, 0x20);
            VU0_SQC2_VF0(&fr, 0xB0);
            if (*(float *)(self + 0x124) == 0.0f &&
                *(float *)(self + 0x12C) == 0.0f) {
                fr.c.x = fr.c.y = fr.c.z = 0.0f;
            } else {
                fr.c.x = fr.c.z = 0.0f;
                fr.c.y = capVu0Atan2(*(float *)(self + 0x124),
                                     *(float *)(self + 0x12C));
            }
            if ((void *)&fr.d != (void *)&fr.a) {
                fr.d.x = fr.a.x;
                fr.d.y = fr.a.y;
                fr.d.z = fr.a.z;
            }
            fr.d.y = thr + 0.65f;
            fr.s.unk20.x = fr.d.x;
            fr.s.unk20.y = fr.d.y;
            fr.s.unk20.z = fr.d.z;
            fr.s.unk10.x = fr.c.x;
            fr.s.unk10.y = fr.c.y;
            fr.s.unk10.z = fr.c.z;
            if (*(signed char *)(self + 0x2D0) != -1) {
                SetEffect(*(signed char *)(self + 0x2D0),
                          *(unsigned char *)(self + 0x2D1) + 1, 0, &fr.s, -1,
                          EFFECT_FOLLOW_OWNER);
            } else {
                fr.s.unk74 = *(unsigned char *)(self + 0x2E6);
                SetEffect(*(short *)(self + 0x23A),
                          *(unsigned short *)(self + 0x23C), 0, &fr.s, -1,
                          EFFECT_FOLLOW_OWNER);
            }
            if (*(int *)(self + 0x2D8) != 2) {
                UpdateObjByIndexedOp_2FBE50(self);
                return;
            }
        }
        if (*(int *)(self + 0x2D8) == 3) {
            UpdateObjByIndexedOp_2FBE50(self);
            return;
        }
        {
            Vec4 *pw = &fr.c;
            float x = *(float *)(self + 0x124) * *(float *)(self + 0x2C0);
            float y = *(float *)(self + 0x128) * -*(float *)(self + 0x2C4);
            float z = *(float *)(self + 0x12C) * *(float *)(self + 0x2C0);

            *(float *)(self + 0x128) = y;
            *(float *)(self + 0x124) = x;
            *(float *)(self + 0x12C) = z;
            fr.c.x = x;
            fr.c.y = y;
            fr.c.z = z;
            pw->w = 1.0f;
            t = __builtin_sqrtf(capVu0LengthSq(pw));
        }
        if (t < 0.1f) {
            *(int *)(self + 0x2DC) |= 1;
            *(float *)(self + 0x178) = *(float *)(self + 0x17C) =
                *(float *)(self + 0x180) = *(float *)(self + 0x134) =
                    *(float *)(self + 0x138) = *(float *)(self + 0x13C) =
                        *(float *)(self + 0x124) = *(float *)(self + 0x128) =
                            *(float *)(self + 0x12C) = 0.0f;
        }
    }
    cNode_setTranslationFromWorld(self, &fr.a);
}
