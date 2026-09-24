/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f12);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f12);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void MtxInitRotY(void *a0, float angle);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern float Adjust_theta(float f12);
extern unsigned int D_00747A24;
extern unsigned short D_00747A50;
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_00569B70[];
extern char D_005FEE00[];
extern void cOmSub_setVibration(void *a0, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(void *a0);
extern char D_00585720[];
extern char D_005FEC58[];
extern int D_00747A0C;

typedef struct { int w[25]; } B100;

__attribute__((section(".text.func_002A2358")))
void func_002A2358(void *a0, char *d, char *s)
{
    *(long *)(d + 0x0) = *(long *)(s + 0x0);
    *(B100 *)(d + 0x8) = *(B100 *)(s + 0x78);
    *(B100 *)(d + 0x6C) = *(B100 *)(s + 0xDC);
    *(B100 *)(d + 0xD0) = *(B100 *)(s + 0x140);
    *(B100 *)(d + 0x134) = *(B100 *)(s + 0x1A4);
    *(B100 *)(d + 0x1FC) = *(B100 *)(s + 0x14);
    *(B100 *)(d + 0x198) = *(B100 *)(s + 0x274);

    *(int *)(d + 0x260) = 0;
    *(float *)(d + 0x264) = 255.0f;
    *(unsigned char *)(d + 0x268) = *(unsigned char *)(s + 0x26C);
    *(unsigned char *)(d + 0x269) = *(unsigned char *)(s + 0x26D);
    *(unsigned char *)(d + 0x26A) = *(unsigned char *)(s + 0x10);
    *(unsigned char *)(d + 0x26B) = 0;
    *(unsigned short *)(d + 0x26C) = *(unsigned short *)(s + 0x26E);
    *(unsigned short *)(d + 0x26E) = *(unsigned short *)(s + 0x270);
    *(unsigned short *)(d + 0x270) = *(unsigned short *)(s + 0x272);
    *(unsigned short *)(d + 0x272) = 0;
}

#include "godhand/vu0.h"

__attribute__((section(".text.func_0011ECB0")))
void func_0011ECB0(void *a0)
{
    char *s1 = (char *)a0;
    char *s3;
    int flag = 0;
    char frame[0x90] __attribute__((aligned(16)));

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x2000;
    s3 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        if (D_00747A50 == 0x203 && s3 != 0) flag = 1;
        if (D_00747A50 == 0x403 && s3 != 0) flag = 1;
        if (D_00747A50 == 0x803 && s3 != 0) flag = 1;
        if (D_00747A50 == 0x4F && s3 != 0) flag = 1;
        if (flag != 0) {
            float *d;
            char *t;

            VU0_SQC2_VF0(frame, 0x40);
            VU0_SQC2_VF0(frame, 0x50);
            *(float *)(frame + 0x50) = 0.0f;
            *(float *)(frame + 0x54) = (*(float **)(s1 + 0xF0))[1];
            *(float *)(frame + 0x58) = 0.0f;
            MtxInitRotY(frame, *(float *)(s1 + 0x104));
            d = *(float **)(s3 + 0xF0);
            if (d != (float *)(frame + 0x50)) {
                d[0] = *(float *)(frame + 0x50);
                d[1] = *(float *)(frame + 0x54);
                d[2] = *(float *)(frame + 0x58);
            }
            t = frame + 0x80;
            *(float *)(frame + 0x40) = 0.0706f;
            *(float *)(frame + 0x44) = 0.0f;
            *(float *)(frame + 0x48) = -3.9432f;
            VU0_LQC2(4, frame + 0x40, 0);
            VU0_SQC2(4, frame, 0x80);
            sceVu0ApplyMatrix(t, frame, t);
            VU0_LQC2(4, t, 0);
            VU0_SQC2(4, frame, 0x70);
            d = *(float **)(s3 + 0xF0);
            VU0_LQC2(4, frame + 0x70, 0);
            VU0_SQC2(4, frame, 0x80);
            VU0_VADD_XYZ_IP(frame, 0x80, d);
            VU0_LQC2(4, t, 0);
            VU0_SQC2(4, frame, 0x60);
            d = *(float **)(s1 + 0xF0);
            if (d != (float *)(frame + 0x60)) {
                d[0] = *(float *)(frame + 0x60);
                d[1] = *(float *)(frame + 0x64);
                d[2] = *(float *)(frame + 0x68);
            }
            *(float *)(s3 + 0x104) = *(float *)(s1 + 0x104) + 3.1415927f;
            *(float *)(s3 + 0x104) = Adjust_theta(*(float *)(s3 + 0x104));
        } else {
            float *buf = (float *)frame;
            float y;

            buf[0] = -0.0706f;
            buf[1] = 0.0f;
            buf[2] = 3.9432f;
            buf[3] = 1.0f;
            y = buf[1];
            func_001299F0(s1, s3, buf, 0, y);
        }
        cEm00_GetPlMotion(s3, 0x1B, 0.0f, 0.0f);
        *(int *)(s1 + 0x15B0) = 1;
        *(int *)(s1 + 0x15B4) = 0;
        *(short *)(s1 + 0x56E) = 0x3C;
        cCoreSave_addGameLevelPoint(D_00569B70, -0x140);
        (*(unsigned char *)(s1 + 0x2F6))++;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x54A) > 0) {
                ClearField15F4Bit1_124F60(s1, 0, 0);
                *(char *)(s1 + 0x2F4) = 1;
                *(char *)(s1 + 0x2F5) = 4;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (*(int *)(s1 + 0x15B4) > 0)
            *(int *)(s1 + 0x15B4) = *(int *)(s1 + 0x15B4) - 1;
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0
            && *(int *)(s1 + 0x15B4) <= 0) {
            *(int *)(s1 + 0x15B4) = 5;
            if (s3 != 0)
                func_0012C0F8(s1, (int)(*(float *)(s3 + 0x76C) * 12.0f));
            func_0012C348(s1, 2);
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 2) != 0
            && *(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            if (s3 != 0)
                func_0012C0F8(s1, (int)(*(float *)(s3 + 0x76C) * 12.0f));
            if (*(short *)(s1 + 0x54A) <= 0) {
                *(short *)(s1 + 0x54A) = 0;
                OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
                cCoreSave_addGameLevelPoint(D_00569B70, -0x3E8);
                *(short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
            }
            func_0012C348(s1, 2);
        }
        break;
    }
}

extern void cOmSub_initMove1_pos(void *a0, void *a1, int a2, int a3, void *t0,
                                 float f12, float f13);


extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5,
                              int a6, int a7);


__attribute__((section(".text.func_001AD0D0")))
void func_001AD0D0(void *a0)
{
    char *s1 = (char *)a0;
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13;
    unsigned char ok1, ok2, ok3, ok4, ok5, ok6, ok7, ok8, ok9, ok10, ok11, ok12, ok13;
    int o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13;
    int v;
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13;

    switch (*(unsigned char *)(s1 + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(s1 + 0x60D) == 1)
            break;
        *(unsigned char *)(s1 + 0x60E) = 1;
        if (*(int *)(s1 + 0x600) == 0) {
            float *q = (float *)frame;
            float z, one;

            *(int *)frame = 0;
            z = q[0];
            q[1] = *(float *)(s1 + 0x790);
            q[2] = 0.0f;
            q[3] = 1.0f;
            cOmSub_initMove1_pos(s1 + 0x630, s1, -1, 0x3C, q, 0.2f, z);
            cOmSub_setVibration(s1 + 0x630, 0, 5, z, 1.0f, 2.0f);
        } else {
            float *q = (float *)frame;
            float z, one;

            *(int *)frame = 0;
            one = 1.0f;
            z = q[0];
            q[1] = -*(float *)(s1 + 0x790);
            q[2] = 0.0f;
            q[3] = one;
            cOmSub_initMove1_pos(s1 + 0x630, s1, -1, 0x3C, q, 0.2f, z);
            cOmSub_setVibration(s1 + 0x630, 0, 5, z, one, 2.0f);
        }
        *(int *)(s1 + 0x5B8) = *(int *)(s1 + 0x5B8) & ~0x100;
        i1 = 1;
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(s1 + 0x2B4)), (i1 < b1));
        if (ok1) o1 = *(int *)(*(int *)(s1 + 0x278) + i1 * 4); else o1 = 0;
        if (o1 != 0) {
            i2 = 1;
            ok2 = ((*(int *)frame = b2 = *(unsigned char *)(s1 + 0x2B4)), (i2 < b2));
            if (ok2) o2 = *(int *)(*(int *)(s1 + 0x278) + i2 * 4); else o2 = 0;
            *(int *)(o2 + 0x104) = 0;
        }
        i3 = 2;
        ok3 = ((*(int *)frame = b3 = *(unsigned char *)(s1 + 0x2B4)), (i3 < b3));
        if (ok3) o3 = *(int *)(*(int *)(s1 + 0x278) + i3 * 4); else o3 = 0;
        if (o3 != 0) {
            i4 = 2;
            ok4 = ((*(int *)frame = b4 = *(unsigned char *)(s1 + 0x2B4)), (i4 < b4));
            if (ok4) o4 = *(int *)(*(int *)(s1 + 0x278) + i4 * 4); else o4 = 0;
            *(int *)(o4 + 0x104) = 0;
        }
        *(short *)(s1 + 0x61C) = 0x14;
        *(float *)(s1 + 0x798) = 0.03926991f;
        i5 = 1;
        ok5 = ((*(int *)frame = b5 = *(unsigned char *)(s1 + 0x2B4)), (i5 < b5));
        if (ok5) o5 = *(int *)(*(int *)(s1 + 0x278) + i5 * 4); else o5 = 0;
        if (o5 != 0) {
            i6 = 2;
            ok6 = ((*(int *)frame = b6 = *(unsigned char *)(s1 + 0x2B4)), (i6 < b6));
            if (ok6) v = *(int *)(*(int *)(s1 + 0x278) + i6 * 4); else v = 0;
            if (v != 0) {
                v = 1;
                goto set;
            }
        }
        v = 2;
    set:
        {
            volatile unsigned char *st = (volatile unsigned char *)s1;
            st[0x2F6] = 0;
            st[0x2F5] = v;
            st[0x2F7] = 0;
        }
        /* fallthrough */
    case 1:
        *(float *)(s1 + 0x798) = *(float *)(s1 + 0x798) + 0.052359879f;
        i7 = 1;
        ok7 = ((*(int *)frame = b7 = *(unsigned char *)(s1 + 0x2B4)), (i7 < b7));
        if (ok7) o7 = *(int *)(*(int *)(s1 + 0x278) + i7 * 4); else o7 = 0;
        *(float *)(o7 + 0x108) = *(float *)(o7 + 0x108) - *(float *)(s1 + 0x798);
        i8 = 2;
        ok8 = ((*(int *)frame = b8 = *(unsigned char *)(s1 + 0x2B4)), (i8 < b8));
        if (ok8) o8 = *(int *)(*(int *)(s1 + 0x278) + i8 * 4); else o8 = 0;
        *(float *)(o8 + 0x108) = *(float *)(o8 + 0x108) + *(float *)(s1 + 0x798);
        i9 = 1;
        ok9 = ((*(int *)frame = b9 = *(unsigned char *)(s1 + 0x2B4)), (i9 < b9));
        if (ok9) o9 = *(int *)(*(int *)(s1 + 0x278) + i9 * 4); else o9 = 0;
        if (*(float *)(o9 + 0x108) < -0.959931076f) {
            i10 = 1;
            ok10 = ((*(int *)frame = b10 = *(unsigned char *)(s1 + 0x2B4)), (i10 < b10));
            if (ok10) o10 = *(int *)(*(int *)(s1 + 0x278) + i10 * 4); else o10 = 0;
            *(float *)(o10 + 0x108) = -0.959931076f;
            i11 = 2;
            ok11 = ((*(int *)frame = b11 = *(unsigned char *)(s1 + 0x2B4)), (i11 < b11));
            if (ok11) o11 = *(int *)(*(int *)(s1 + 0x278) + i11 * 4); else o11 = 0;
            *(float *)(o11 + 0x108) = 0.959931076f;
            *(float *)(s1 + 0x798) = *(float *)(s1 + 0x798) * -0.5f;
        }
        if (*(short *)(s1 + 0x61C) < 0) {
            i12 = 1;
            ok12 = ((*(int *)frame = b12 = *(unsigned char *)(s1 + 0x2B4)), (i12 < b12));
            if (ok12) o12 = *(int *)(*(int *)(s1 + 0x278) + i12 * 4); else o12 = 0;
            *(float *)(o12 + 0x108) = -0.959931076f;
            i13 = 2;
            ok13 = ((*(int *)frame = b13 = *(unsigned char *)(s1 + 0x2B4)), (i13 < b13));
            if (ok13) o13 = *(int *)(*(int *)(s1 + 0x278) + i13 * 4); else o13 = 0;
            *(float *)(o13 + 0x108) = 0.959931076f;
            *(short *)(s1 + 0x61C) = 0xA;
            *(unsigned char *)(s1 + 0x2F5) = 2;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        *(short *)(s1 + 0x61C) = *(unsigned short *)(s1 + 0x61C) - 1;
        break;
    case 2:
        if (*(short *)(s1 + 0x61C) < 0) {
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 3;
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x84, s1, 0, 0, 0, 0);
        }
        *(short *)(s1 + 0x61C) = *(unsigned short *)(s1 + 0x61C) - 1;
        break;
    case 3:
        if (cOmSub_move(s1 + 0x630) != 0)
            break;
        *(unsigned char *)(s1 + 0x60D) = 1;
        *(unsigned char *)(s1 + 0x2F4) = 3;
        *(unsigned char *)(s1 + 0x60E) = 0;
        *(unsigned char *)(s1 + 0x2F5) = 0;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    }
}

#define SET_ENT(e, a, b, x, y, vy)                  \
    {                                               \
        float *v;                                   \
        float *w;                                   \
                                                    \
        func_003A52F0(e, 0, 0x30);                  \
        *(unsigned char *)(e + 0x2) = a;            \
        *(unsigned char *)(e + 0x3) = b;            \
        *(float *)(e + 0x4) = x;                    \
        *(float *)(e + 0x8) = y;                    \
        v = (float *)(e + 0x10);                    \
        *(int *)(e + 0x10) = 0;                     \
        v[1] = vy;                                  \
        v[2] = 0.0f;                                \
        v[3] = 1.0f;                                \
        w = (float *)(e + 0x20);                    \
        *(int *)(e + 0x20) = 0;                     \
        w[1] = vy;                                  \
        w[2] = 0.0f;                                \
        w[3] = 1.0f;                                \
    }

__attribute__((section(".text.func_00284548")))
void func_00284548(void *a0, int a1)
{
    char *e;

    if (a1 != 0xFFFF)
        return;
    if (a0 == 0)
        return;
    e = D_00585720;
    SET_ENT(e, 0x11, 0x11, 1.0f, 0.15f, -0.2f)
    e += 0x30;
    SET_ENT(e, 0x11, 0x11, 1.0f, 0.15f, -0.3f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x12, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x13, 0.66f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x13, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x13, 0x13, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x13, 0x14, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x16, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x17, 0.66f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x17, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x17, 0x17, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x17, 0x18, 0.33f, 0.11f, 0.0f)
}

typedef struct {
    char pad0[0x80];
    char *parts[64];
} Owner;

typedef struct {
    float f[10];
} TblEnt;

typedef struct {
    TblEnt a[5];
    float b[8];
} Tbl;



extern Tbl D_0041F250;


#define PART(bit, idv, fexpr)                                           \
    if ((*(int *)(t + 0xC) & (bit)) && n < 2) {                         \
        *(short *)(s->parts[n + 0xF] + 0x90) = (idv);                                  \
        *(short *)(s->parts[n + 0x11] + 0x90) = (idv);                                 \
        *(float *)(s->parts[n + 0xF] + 0x40) = (fexpr);                               \
        n++;                                                            \
    }

__attribute__((section(".text.func_0016BCE0")))
void func_0016BCE0(Owner *s, unsigned short a1)
{
    unsigned char n = 0;
    char *t;

    t = func_002C9008(D_005FEC58, a1);
    if (t == 0)
        return;
    PART(0x10, 0x30C7, D_0041F250.a[D_00747A0C].f[1])
    if ((*(int *)(t + 0xC) & 0x20) && n < 2) {
        *(short *)(s->parts[n + 0xF] + 0x90) = 0x30C8;
        *(short *)(s->parts[n + 0x11] + 0x90) = 0x30C8;
        *(float *)(s->parts[n + 0xF] + 0x40) = D_0041F250.a[D_00747A0C].f[2];
        *(int *)(s->parts[n + 0x29] + 0x2C) &= ~0x8000000;
        n++;
    }
    PART(0x40, 0x30C9, D_0041F250.a[D_00747A0C].f[3])
    PART(0x80, 0x30CA, D_0041F250.a[D_00747A0C].f[4])
    PART(0x100, 0x30CB, D_0041F250.b[D_00747A0C])
    PART(0x200, 0x30CC, D_0041F250.a[D_00747A0C].f[6])
    PART(0x400, 0x30CD, D_0041F250.a[D_00747A0C].f[7])
    PART(0x800, 0x30CE, D_0041F250.a[D_00747A0C].f[8])
    PART(0x1000, 0x30CF, D_0041F250.a[D_00747A0C].f[9])
    PART(0x8, 0x30C6, D_0041F250.a[D_00747A0C].f[0])
    if (n != 0)
        *(int *)(s->parts[0xF] + 0x2C) &= ~0x8000000;
    if (n >= 2)
        *(int *)(s->parts[0x10] + 0x2C) &= ~0x8000000;
}
