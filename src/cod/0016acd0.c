/* sn-2.95.3-136 matched TU. */

extern int cIDBase_getIDWork(void *self, int idx);
extern void cIDBase_move(void *a0);
extern void cIDBase_trans(void *a0);
extern unsigned char D_005FEE00[];
extern unsigned char D_005864F0[];
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern int cEmManage__CreateItem(void *a0, int a1, int a2, int a3);
extern void func_0019BA08(void *a0, int a1, int a2);
extern void SetField5B0Bit2ClearBit8_1B7908(int a0);
extern float capVu0Atan2(float y, float x);
extern int SetEffect();
extern void func_001BFF68(void *a0);
extern void func_00373FA0(void *a0);
extern void func_0032BDC0(void *a0, int a1, int a2);
extern void func_0032BB48(void *a0, int a1, int a2);
extern void func_003741B0(void *a0, float f);
extern void func_00374570(void *a0);
extern void func_0032DE88(int a0, int a1);
extern void func_0032DEF8(int a0, int a1);
extern void func_0032DF70(void *a0, int a1, int a2);
extern void func_0032DA28(void *a0, int a1, int a2);
extern void func_00374958(void *a0, float f);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_0016ACD0")))
void func_0016ACD0(void *a0)
{
    char *s4 = (char *)a0;
    unsigned short i;

    if (*(char *)(s4 + 0x5A) == 3) {
        for (i = 0; i < 5; i++) {
            short *tbl = (short *)(s4 + 0x260);
            short *q = tbl + i;
            if (*q != 0) {
                int ids;
                int k;
                char *w1 = (char *)cIDBase_getIDWork(s4 + 0x210, 0);
                char *w2 = (char *)cIDBase_getIDWork(s4 + 0x210, 0);
                char *w3;
                char *w4;
                int t;
                *(float *)(w1 + 0x3C) =
                    *(float *)(*(int *)(w2 + 0x1C) + 0xC) - (float)(i * 26);
                w3 = (char *)cIDBase_getIDWork(s4 + 0x210, 0);
                *(char *)(w3 + 0x4F) = (int)((float)*q / 20.0f * 256.0f);
                w4 = (char *)cIDBase_getIDWork(s4 + 0x210, 0);
                k = i * 4;
                ids = (int)(s4 + 0x26C);
                t = *(int *)(ids + k);
                *(int *)(w4 + 0x84) = t;
                cIDBase_move(s4 + 0x210);
                cIDBase_trans(s4 + 0x210);
            }
        }
    }
    cIDBase_trans(s4 + 0xD0);
    cIDBase_trans(s4);
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"









__attribute__((section(".text.func_0019B580")))
void func_0019B580(void *a0)
{
    char *s0 = (char *)a0;
    float buf[4] __attribute__((aligned(16)));

    switch (*(unsigned char *)(s0 + 0x2F5)) {
    case 0: {
        char *vt;
        short off;
        float *(*fp)();
        float *src;
        VU0_SQC2_VF0(buf, 0);
        vt = *(char **)(s0 + 0x214);
        off = *(short *)(vt + 0x80);
        fp = *(float *(**)())(vt + 0x84);
        src = fp(s0 + off);
        if (buf != src) {
            buf[0] = src[0];
            buf[1] = src[1];
            buf[2] = src[2];
        }
        SetEffectPos(0, 0xCC, 0, buf, -1, 1.0f);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, s0, 0, 0, 0, 0);
        if (*(char *)(s0 + 0xA92) == 0) {
            func_0019BA08(s0, 0, 2);
            cEmManage__CreateItem(&D_005864F0, *(int *)(s0 + 0xF0), 0xFFFF, 0);
            *(short *)(s0 + 0x54A) = *(unsigned short *)(s0 + 0x548);
            *(unsigned char *)(s0 + 0xA92) = *(unsigned char *)(s0 + 0xA92) + 1;
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            break;
        }
        func_0019BA08(s0, 1, 3);
        SetField5B0Bit2ClearBit8_1B7908((int)s0);
        *(unsigned char *)(s0 + 0x2F5) = 1;
        *(short *)(s0 + 0xA90) = 0x1E;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
    }
    /* fallthrough */
    case 1: {
        int v = *(unsigned short *)(s0 + 0xA90) - 1;
        *(short *)(s0 + 0xA90) = v;
        if ((short)v > 0)
            break;
        *(short *)(s0 + 0xA90) = 0xF;
        *(unsigned char *)(s0 + 0x2F5) = 2;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
    case 2: {
        int v = *(unsigned short *)(s0 + 0xA90) - 1;
        short t = v;
        *(short *)(s0 + 0xA90) = v;
        *(float *)(s0 + 0x24C) = (float)t / 15.0f;
        if (t > 0)
            break;
        *(unsigned char *)(s0 + 0x2F5) = 3;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
    case 3:
        *(unsigned char *)(s0 + 0x2F4) = 3;
        *(unsigned char *)(s0 + 0x2F5) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
}

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
    S s;                  /* 0x10 */
} Frame;

__attribute__((section(".text.func_001BFD28")))
void func_001BFD28(void *a0)
{
    char *s0 = (char *)a0;
    Frame fr;
    S *e;
    float ang;

    switch (*(unsigned char *)(s0 + 0x2F5)) {
    case 0: {
        char *vt;
        short off;
        float *(*fp)();
        float *src;
        ang = capVu0Atan2(*(float *)(s0 + 0x5C0), *(float *)(s0 + 0x5C8));
        VU0_SQC2_VF0(&fr, 0x00);
        vt = *(char **)(s0 + 0x214);
        off = *(short *)(vt + 0x80);
        fp = *(float *(**)())(vt + 0x84);
        src = fp(s0 + off);
        if ((void *)&fr.a != (void *)src) {
            fr.a.x = src[0];
            fr.a.y = src[1];
            fr.a.z = src[2];
        }
        e = &fr.s;
        e->f00 = 1.0f;
        e->f04 = 1.0f;
        e->f08 = 1.0f;
        e->f0C = 1.0f;
        VU0_SQC2_VF0(&fr, 0x20);
        VU0_SQC2_VF0(&fr, 0x30);
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
        VU0_SQC2_VF0(&fr, 0x70);
        fr.s.v10.y = ang;
        fr.s.h70 = 0;
        fr.s.h72 = 0;
        fr.s.b74 = 0;
        fr.s.i78 = 0;
        if ((void *)&fr.s.v20 != (void *)&fr.a) {
            fr.s.v20.x = fr.a.x;
            fr.s.v20.y = fr.a.y;
            fr.s.v20.z = fr.a.z;
        }
        fr.s.f40 = 1.0f;
        SetEffect(0, 0x1C, 0, &fr.s, -1, 0xFFFFFFFF);
        {
            char *vt2 = *(char **)(s0 + 0x214);
            short off2 = *(short *)(vt2 + 0xA8);
            void (*fp2)() = *(void (**)())(vt2 + 0xAC);
            fp2(s0 + off2);
        }
        func_001BFF68(s0);
        SetField5B0Bit2ClearBit8_1B7908((int)s0);
        *(unsigned char *)(s0 + 0x2F5) = 1;
        *(short *)(s0 + 0x604) = 0x1E;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
    }
    /* fallthrough */
    case 1: {
        int v = *(unsigned short *)(s0 + 0x604) - 1;
        *(short *)(s0 + 0x604) = v;
        if ((short)v > 0)
            break;
        *(short *)(s0 + 0x604) = 0xF;
        *(unsigned char *)(s0 + 0x2F5) = 2;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
    case 2: {
        int v = *(unsigned short *)(s0 + 0x604) - 1;
        short t = v;
        *(short *)(s0 + 0x604) = v;
        *(float *)(s0 + 0x24C) = (float)t / 15.0f;
        if (t > 0)
            break;
        *(unsigned char *)(s0 + 0x2F5) = 3;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
    case 3:
        *(unsigned char *)(s0 + 0x2F4) = 3;
        *(unsigned char *)(s0 + 0x2F5) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
}

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_00373D90")))
int func_00373D90(void *a0, int a1, void *a2, int a3)
{
    char *o = (char *)a0;
    char *c = (char *)a2;
    int flag;
    int one;
    int nil;
    int m;

    if (*(int *)o != 0) {
        return 0;
    }
    one = 1;
    nil = 0;
    flag = nil;
    if (*(unsigned char *)(c + 0x10) != 0) {
        flag = one;
    }
    *(float *)(o + 0x20) = (float)*(unsigned char *)(c + 0xC);
    *(float *)(o + 0x24) = (float)*(unsigned short *)(c + 4);
    *(float *)(o + 0x28) = (float)*(unsigned short *)(c + 6);
    *(int *)(o + 0x18) = 0;
    *(int *)(o + 0x1C) = 0;
    *(float *)(o + 0x34) =
        (float)((int)((float)*(unsigned char *)(c + 0xD)
                    / (float)*(unsigned char *)(c + 0xC) * 100.0f) + 1) / 100.0f;
    *(int *)(o + 0xC) = *(unsigned short *)(c + 8);
    m = (*(unsigned char *)(c + 0xB) >> 2) & 3;
    *(int *)(o + 0x10) = m;
    if (m == 0) {
        *(int *)(o + 0x10) = 2;
    }
    *(float *)(o + 0x30) = *(float *)(o + 0x2C) = 1.0f;
    if (func_00373BA8(o, *(unsigned short *)(c + 8), *(unsigned char *)(c + 0xF), flag) == 0) {
        return 0;
    }
    func_00373FA0(o);
    func_0032B188(*(int *)o, 1);
    if (flag == one) {
        func_0032BDC0(*(void **)o, a3, *(unsigned short *)(c + 2));
    } else {
        func_0032BB48(*(void **)o, a1, *(unsigned short *)(c + 2));
    }
    func_003741B0(o, 2.0f);
    return 1;
}

/* sn-2.95.3-136 matched TU. */









__attribute__((section(".text.func_00374360")))
int func_00374360(void *a0, int a1, void *a2)
{
    char *o = (char *)a0;
    char *c = (char *)a2;
    char *v;
    int i;
    int m;

    if (*(int *)o != 0) {
        return 0;
    }
    if (*(unsigned char *)(c + 0xA) != 0) {
        i = 0;
        v = o + 0x24;
        do {
            float f = (float)*(unsigned char *)(c + 0xC);
            *(int *)(v - 8) = 0;
            *(int *)v = 0;
            *(float *)(v + 8) = f;
            v += 4;
        } while (++i < *(unsigned char *)(c + 0xA));
    }
    *(float *)(o + 0x34) = (float)*(unsigned short *)(c + 4);
    *(float *)(o + 0x38) = (float)*(unsigned short *)(c + 6);
    *(float *)(o + 0x44) =
        (float)((int)((float)*(unsigned char *)(c + 0xD)
                    / (float)*(unsigned char *)(c + 0xC) * 100.0f) + 1) / 100.0f;
    *(int *)(o + 0xC) = *(unsigned char *)(c + 0xA);
    m = (*(unsigned char *)(c + 0xB) >> 2) & 3;
    *(int *)(o + 0x10) = m;
    if (m == 0) {
        *(int *)(o + 0x10) = 2;
    }
    *(float *)(o + 0x40) = *(float *)(o + 0x3C) = 1.0f;
    if (func_00374210(o, *(unsigned short *)(c + 8), *(unsigned char *)(c + 0xF),
                      *(unsigned char *)(c + 0xA)) == 0) {
        return 0;
    }
    func_00374570(o);
    func_0032DE88(*(int *)o, 1);
    func_0032DEF8(*(int *)o, 1);
    func_0032DF70(*(void **)o, 1, 1);
    func_0032DA28(*(void **)o, a1, *(unsigned short *)(c + 2));
    func_00374958(o, 2.0f);
    return 1;
}
