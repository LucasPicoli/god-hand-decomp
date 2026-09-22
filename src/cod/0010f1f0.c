/* sn-2.95.3-136 matched TU. */

extern int cWorldLight_Set_LightData(void *a0, void *a1);
extern void MaxField514_292030(void *a0, int a1);
extern void MaxByte538_292EF0(void *a0, int a1);
extern void ShiftDownBytesA8_FAC00(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00129578(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void SetField548AndGlobals_292F38(void *a0, float a1);
extern void func_00124EC0(void *a0);
extern int  moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0010A438(void *a0);
extern void cSnd_SeStop(void *a0, int a1);
extern int  D_00569B70;
extern char D_005864F0[];
extern char D_005FEE00[];
extern void func_002E0DE8();
extern void func_00380720(void *a0, int a1, int a2, int *a3, int *t0, int *t1, int *t2);
extern char D_0045CBC0[];
extern char D_0045CBC8[];
extern char D_0045CBD8[];
extern char D_0045CBE8[];
extern char D_0045CBF8[];
extern char D_0045CC18[];
extern char D_0045CC28[];
extern char D_0045CC38[];
extern char D_0045CC50[];
extern char D_0045CC60[];
extern char D_0045CC80[];
extern char D_0045CCA0[];
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);

/* cWorldLight_Init_SatanLight — 0x002D98C0, 640 B — sn-2.95.3-136.
 * b3: pointer locals for the two vec4 fields + source order mirrors
 * retail's emitted store order. */
#include "godhand/vu0.h"

typedef struct {
    short f00;
    short f02;
    int   f04;
    int   f08;
    int   f0C;
    float v0[4];   /* 0x10 */
    float v1[4];   /* 0x20 */
    float v2[4];   /* 0x30 */
    int   f40;
    float f44;
    int   f48;
    int   f4C;
    int   f50;
    int   f54;
    int   f58;
    short f5C;
    short f5E;
    char  f60;
    char  f61;
    short f62;
    int   f64;
    int   f68;
    int   f6C;
} LightData;   /* 0x70 */



__attribute__((section(".text.cWorldLight_Init_SatanLight")))
void cWorldLight_Init_SatanLight(void *a0, int a1)
{
    LightData d __attribute__((aligned(16)));
    float *p;
    float *q;
    int c3;

    p = d.v0;
    VU0_SQC2_VF0(&d, 0x10);
    VU0_SQC2_VF0(&d, 0x20);
    q = d.v2;
    VU0_SQC2_VF0(&d, 0x30);
    c3 = 0x04040000;

    p[0] = -2.389967918395996f;
    d.f54 = a1;
    d.f00 = 1;
    d.f02 = 1;
    d.f04 = 0;
    p[1] = 1.700024962425232f;
    p[2] = 0.09997999668121338f;
    p[3] = 1.0f;
    q[0] = 0.08f;
    q[1] = 0.07f;
    q[2] = 0.08f;
    q[3] = 1.0f;
    d.f44 = 0.8f;
    d.f50 = 1;
    d.f58 = 0x05040000;
    d.f40 = 0;
    d.f48 = 0;
    d.f4C = 0;
    cWorldLight_Set_LightData(a0, &d);

    p[0] = -1.0001519918441772f;
    d.f54 = a1;
    d.f00 = 1;
    d.f02 = 2;
    d.f04 = 0;
    p[1] = -12.299838066101074f;
    p[2] = -12.899819374084473f;
    p[3] = 1.0f;
    q[0] = 0.6f;
    q[1] = 0.02f;
    q[2] = 0.02f;
    q[3] = 1.0f;
    d.f60 = 1;
    d.f44 = 0.1f;
    d.f50 = 1;
    d.f5E = 30;
    d.f5C = 0x5100;
    d.f61 = 50;
    d.f62 = 0x3667;
    d.f58 = 0x04140000;
    d.f40 = 0;
    d.f48 = 0;
    d.f4C = 0;
    cWorldLight_Set_LightData(a0, &d);

    d.f54 = a1;
    d.f02 = 2;
    p[0] = -21.199731826782227f;
    d.f00 = 1;
    d.f04 = 0;
    p[1] = -5.809957027435303f;
    p[2] = -6.899814128875732f;
    p[3] = 1.0f;
    q[0] = 0.0f;
    q[1] = 0.53f;
    d.v2[2] = 0.0f;
    q[3] = 1.0f;
    d.f44 = 0.1f;
    d.f50 = 1;
    d.f58 = c3;
    d.f40 = 0;
    d.f48 = 0;
    d.f4C = 0;
    cWorldLight_Set_LightData(a0, &d);
}

/* func_00112318 — 0x00112318, 648 B — sn-2.95.3-136.
 * +0x2F6 phase machine; template is the landed twin src/cod/00111750.c
 * (func_00111750, jaccard 0.86). */
























__attribute__((section(".text.func_00112318")))
void func_00112318(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(D_005864F0, 2);
    MaxByte538_292EF0(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    if (*(unsigned char *)(s1 + 0x2F6) != 0 &&
        *(unsigned char *)(s1 + 0x649) == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        *(char *)(s1 + 0x649) = 1;
        ShiftDownBytesA8_FAC00(&D_00569B70);
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x32, 0x16, 0x22, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x32, 0x16, 0x22, 0, 0xA);
        *(char *)(s1 + 0x1684) = 1;
        func_00129578(s1);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x218) + t, *(int *)(t + 0x21C) + t,
                      0.0f, 3, 0, 0);
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
        char *g = D_005FEE00;
        cSnd_SeStop(g, *(int *)(s1 + 0x161C));
        *(int *)(s1 + 0x161C) = 0;
        *(int *)(g + 0xB0) &= 0xFFBFFFFF;
        *(int *)(g + 0xAC) &= 0xFFBFFFFF;
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 1, 0);
    } else {
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}

/* func_00384590 — 0x00384590, 660 B — sn-2.95.3-136. */

















__attribute__((section(".text.func_00384590")))
void func_00384590(void *a0, unsigned char *a1)
{
    char buf[0x100];
    int  q[4];
    int  x;
    int  s6;
    int  fp;

    if ((a1[3] & 1) != 0) {
        char *s0 = (char *)a1 + 0xA4;

        fp = *(int *)((char *)a1 + 0xA4);
        s6 = *(int *)(s0 + 0x4);
        x  = *(int *)(s0 + 0x14);
        func_002E0DE8(0x20, 8, 8, D_0045CBC8, *(int *)(s0 + 0x8));
        func_002E0DE8(0x20, 9, 8, D_0045CBD8, *(int *)(s0 + 0xC));
        func_002E0DE8(0x20, 0xA, 8, D_0045CBE8, *(int *)(s0 + 0x10));
    } else {
        char *s1 = (char *)a1 + 0x34;

        x  = *(int *)(s1 + 0x10);
        s6 = *(int *)(s1 + 0x4);
        fp = *(int *)((char *)a1 + 0x34);
        func_00380720(a0, s6, *(int *)(s1 + 0x14), &q[0], &q[1], &q[2], &q[3]);
        func_002E0DE8(3, 0xB, 8, D_0045CBF8, q[0], q[1], q[2], q[3]);
        func_002E0DE8(0x20, 8, 8, D_0045CC18, *(int *)(s1 + 0x8));
        func_002E0DE8(0x20, 9, 8, D_0045CC28, *(int *)(s1 + 0xC));
        func_003A6C58(buf, D_0045CC38, *(float *)(s1 + 0x18));
        func_002E0DE8(0x20, 0xA, 8, D_0045CBC0, buf);
        func_002E0DE8(0x20, 0xB, 8, D_0045CC50, *(int *)(s1 + 0x1C));
    }
    func_00380720(a0, s6, fp, &q[0], &q[1], &q[2], &q[3]);
    func_002E0DE8(3, 9, 8, D_0045CC60, q[0], q[1], q[2], q[3]);
    func_00380720(a0, s6, x, &q[0], &q[1], &q[2], &q[3]);
    func_002E0DE8(3, 0xA, 8, D_0045CC80, q[0], q[1], q[2], q[3]);
    func_002E0DE8(0x20, 7, 8, D_0045CCA0, s6);
}

/* func_0010F1F0 — 0x0010F1F0, 708 B — sn-2.95.3-136.
 * +0x2F6 phase machine; template src/cod/00111750.c (jaccard 0.86). */
























__attribute__((section(".text.func_0010F1F0")))
void func_0010F1F0(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(D_005864F0, 2);
    MaxByte538_292EF0(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int p, q;

        func_00129578(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        if (*(unsigned char *)(s1 + 0x2F7) != 0) {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x190, 0xE, 0x1C, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x190, 0xE, 0x1C, 0, 0x123);
            ShiftDownBytesA8_FAC00(&D_00569B70);
            ShiftDownBytesA8_FAC00(&D_00569B70);
            {
                int t = *(int *)(s1 + 0x304);
                p = *(int *)(t + 0xC8) + t;
                q = *(int *)(t + 0xD0) + t;
            }
        } else {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x5A, 0xE, 0x1C, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x5A, 0xE, 0x1C, 0, 0x123);
            ShiftDownBytesA8_FAC00(&D_00569B70);
            {
                int t = *(int *)(s1 + 0x304);
                p = *(int *)(t + 0xC8) + t;
                q = *(int *)(t + 0xCC) + t;
            }
        }
        *(char *)(s1 + 0x1684) = 1;
        func_002A8578(s1, p, q, 0.0f, 3, 0, 0);
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        InvokeVirtualAtField214AndForward_124E68(s1, 0.13089969754219055f);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
            ClearField15F4Bit1_124F60(s1, 1, 0);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 1, 0);
    } else {
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
            char *g = D_005FEE00;
            cSnd_SeStop(g, *(int *)(s1 + 0x161C));
            *(int *)(s1 + 0x161C) = 0;
            *(int *)(g + 0xB0) &= 0xFFBFFFFF;
            *(int *)(g + 0xAC) &= 0xFFBFFFFF;
        }
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}
