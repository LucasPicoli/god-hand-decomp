/* sn-2.95.3-136 matched TU. */

extern float capVu0LengthSq(void *a0);
extern float capVu0Atan2(float y, float x);
extern float sqrtf(float x);
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern void *CopyVec16From20_B62E0(void *dst, char *self);
extern void UpdateObjByIndexedOp_2FBE50(void *self);
extern void func_002B5FC8(void *self, void *v);
extern int SetEffect();

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"










typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct S {
    float f00;            /* 0x00 */
    float f04;
    float f08;
    float f0C;
    Vec4 v10;             /* 0x10 sqc2 */
    Vec4 v20;             /* 0x20 sqc2 */
    float f30;            /* 0x30 */
    float f34;
    float f38;
    float f3C;
    float f40;            /* 0x40 */
    int i44;
    int i48;
    signed char b4C;      /* 0x4C */
    signed char b4D;
    signed char b4E;
    unsigned char b4F;
    int i50;              /* 0x50 */
    char pad54[0xC];
    char q60[0x10];       /* 0x60 sqc2 */
    short h70;            /* 0x70 */
    short h72;
    signed char b74;      /* 0x74 */
    char pad75[3];
    int i78;              /* 0x78 */
    char pad7C[4];
} S;

typedef struct Frame {
    Vec4 a;               /* 0x00 */
    Vec4 b;               /* 0x10 */
    Vec4 c;               /* 0x20 */
    S s;                  /* 0x30 */
    Vec4 d;               /* 0xB0 */
} Frame;

__attribute__((section(".text.func_002E28F0")))
void func_002E28F0(void *arg, float thr) {
    Frame fr;
    char *self = (char *)arg;
    S *e;
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
        st = *(int *)(self + 0x2C8);
        fr.a.y = thr + h;
        if (st == 1 || st == 2) {
            e = &fr.s;
            e->f00 = 1.0f;
            e->f04 = 1.0f;
            e->f08 = 1.0f;
            e->f0C = 1.0f;
            VU0_SQC2_VF0(&fr, 0x40);
            VU0_SQC2_VF0(&fr, 0x50);
            {
                float *q = &e->f30;
                q[0] = 1.0f;
                q[1] = 1.0f;
                q[2] = 1.0f;
                q[3] = 1.0f;
            }
            e->f40 = 1.0f;
            fr.s.i44 = 0;
            fr.s.i48 = 0;
            e->b4C = -1;
            fr.s.b4D = 0;
            fr.s.b4E = 0;
            e->b4F = 0xFF;
            fr.s.i50 = 0;
            VU0_SQC2_VF0(&fr, 0x90);
            fr.s.h70 = 0;
            fr.s.h72 = 0;
            fr.s.b74 = 0;
            fr.s.i78 = 0;
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
            fr.s.v20.x = fr.d.x;
            fr.s.v20.y = fr.d.y;
            fr.s.v20.z = fr.d.z;
            fr.s.v10.x = fr.c.x;
            fr.s.v10.y = fr.c.y;
            fr.s.v10.z = fr.c.z;
            if (*(signed char *)(self + 0x2C0) != -1) {
                SetEffect(*(signed char *)(self + 0x2C0),
                          *(unsigned char *)(self + 0x2C1) + 1, 0, &fr.s, -1,
                          0xFFFFFFFF);
            } else {
                fr.s.b74 = *(unsigned char *)(self + 0x2D6);
                SetEffect(*(short *)(self + 0x23A),
                          *(unsigned short *)(self + 0x23C), 0, &fr.s, -1,
                          0xFFFFFFFF);
            }
            if (*(int *)(self + 0x2C8) != 2) {
                UpdateObjByIndexedOp_2FBE50(self);
                return;
            }
        }
        if (*(int *)(self + 0x2C8) == 3) {
            UpdateObjByIndexedOp_2FBE50(self);
            return;
        }
        {
            Vec4 *pw = &fr.c;
            float x = *(float *)(self + 0x124) * *(float *)(self + 0x2B0);
            float y = *(float *)(self + 0x128) * -*(float *)(self + 0x2B4);
            float z = *(float *)(self + 0x12C) * *(float *)(self + 0x2B0);

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
            *(int *)(self + 0x2CC) |= 1;
            *(float *)(self + 0x178) = *(float *)(self + 0x17C) =
                *(float *)(self + 0x180) = *(float *)(self + 0x134) =
                    *(float *)(self + 0x138) = *(float *)(self + 0x13C) =
                        *(float *)(self + 0x124) = *(float *)(self + 0x128) =
                            *(float *)(self + 0x12C) = 0.0f;
        }
    }
    func_002B5FC8(self, &fr.a);
}
