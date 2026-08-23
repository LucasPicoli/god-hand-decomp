/* sn-2.95.3-136 matched TU. */

extern char D_003BFB48[];
extern char D_003BFB60[];
extern char D_003BFB78[];
extern char D_003BFB90[];
extern char D_003BFBA8[];
extern char D_003BFBF8[];
extern char D_003BFC48[];
extern char D_00585240[];
extern void func_001038E0(char *a0, char *a1, char *a2, float f12, float f13);
extern char D_003BFC98[];
extern char D_003BFCB0[];
extern char D_003BFCC8[];
extern char D_003BFCE0[];
extern char D_003BFCF8[];
extern char D_003BFD50[];
extern char D_003BFDA8[];
extern char D_00585450[];
extern char D_003C01D8[];
extern char D_003C0138[];
extern char D_003C0160[];
extern char D_003C0188[];
extern char D_003C01B0[];
extern char D_003C0200[];
extern char D_003C02A0[];
extern char D_003C0340[];
extern char D_00585720[];
extern char D_005FEE00[];
extern int cSnd_SeCall_2CB8A0(char *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern float DoubleFloatMinusHalf_31D020(void);
extern char D_00463050[];
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void Obj1D00_SetState_7_1C(int a0);
extern void cCamManager_setPartsCamera(void *cam, int mode);
extern void Obj0000_Set_Fields_360_364_368_139B68(void *parts, void *obj, int a2, int a3);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_002DC390(void *a0);

__attribute__((section(".text.func_0027A600")))
void func_0027A600(char *p)
{
    float v[4];
    volatile float *dst;

    *(int *)(p + 0x2130) = 0x14;
    *(char **)(p + 0x2134) = D_003BFB48;
    *(char **)(p + 0x2138) = D_003BFB90;
    *(int *)(p + 0x213C) = 0;
    *(int *)(p + 0x2140) = 0;
    *(int *)(p + 0x2144) = 0;
    *(char **)(p + 0x2148) = D_003BFB60;
    *(char **)(p + 0x214C) = D_003BFB78;
    *(int *)(p + 0x2150) = 0;
    *(int *)(p + 0x2154) = 0;
    *(char **)(p + 0x2158) = D_003BFBA8;
    *(char **)(p + 0x215C) = D_003BFBF8;
    *(char **)(p + 0x2160) = D_003BFC48;
    *(char **)(p + 0x2164) = D_00585240;
    *(int *)(p + 0x2168) = 0;
    *(int *)(p + 0x2188) = 0;
    *(float *)(p + 0x216C) = 0.015f;
    *(float *)(p + 0x2170) = 0.8f;
    *(int *)(p + 0x2174) = 1;
    *(float *)(p + 0x2178) = 0.0f;
    *(float *)(p + 0x217C) = 0.5f;
    *(float *)(p + 0x2180) = 0.5f;
    *(int *)(p + 0x2184) = 0;
    *(int *)(p + 0x218C) = 0x100;
    v[0] = 0.0f;
    v[1] = 0.0f;
    *(int *)&v[2] = 0;
    v[3] = 1.0f;
    dst = (volatile float *)(p + 0x2190);
    if (dst != (volatile float *)v) {
        dst[0] = v[0];
        dst[1] = v[1];
        dst[2] = *(volatile float *)&v[2];
    }
    *(float *)(p + 0x21A0) = 1.0471976f;
    func_001038E0(p, p + 0x2130, p + 0x5B0, 0.1f, 0.0f);
}

__attribute__((section(".text.func_0027B0F8")))
void func_0027B0F8(char *p)
{
    float v[4];
    volatile float *dst;

    *(int *)(p + 0x2130) = 0x16;
    *(char **)(p + 0x2134) = D_003BFC98;
    *(char **)(p + 0x2138) = D_003BFCE0;
    *(int *)(p + 0x213C) = 0;
    *(int *)(p + 0x2140) = 0;
    *(int *)(p + 0x2144) = 0;
    *(char **)(p + 0x2148) = D_003BFCB0;
    *(char **)(p + 0x214C) = D_003BFCC8;
    *(int *)(p + 0x2150) = 0;
    *(int *)(p + 0x2154) = 0;
    *(char **)(p + 0x2158) = D_003BFCF8;
    *(char **)(p + 0x215C) = D_003BFD50;
    *(char **)(p + 0x2160) = D_003BFDA8;
    *(char **)(p + 0x2164) = D_00585450;
    *(int *)(p + 0x2168) = 0;
    *(int *)(p + 0x2188) = 0;
    *(float *)(p + 0x216C) = 0.015f;
    *(float *)(p + 0x2170) = 0.8f;
    *(int *)(p + 0x2174) = 1;
    *(float *)(p + 0x2178) = 0.0f;
    *(float *)(p + 0x217C) = 0.8f;
    *(float *)(p + 0x2180) = 0.5f;
    *(int *)(p + 0x2184) = 0;
    *(int *)(p + 0x218C) = 0x100;
    v[0] = 0.0f;
    v[1] = 0.0f;
    *(int *)&v[2] = 0;
    v[3] = 1.0f;
    dst = (volatile float *)(p + 0x2190);
    if (dst != (volatile float *)v) {
        dst[0] = v[0];
        dst[1] = v[1];
        dst[2] = *(volatile float *)&v[2];
    }
    *(float *)(p + 0x21A0) = 1.0471976f;
    func_001038E0(p, p + 0x2130, p + 0x5B0, 0.1f, 0.0f);
}

__attribute__((section(".text.func_00284350")))
void func_00284350(char *p)
{
    float v[4];
    volatile float *dst;

    *(int *)(p + 0x2130) = 0x28;
    *(char **)(p + 0x2134) = D_003C0138;
    *(char **)(p + 0x2138) = D_003C01B0;
    *(char **)(p + 0x213C) = D_003C01D8;
    *(int *)(p + 0x2140) = 0;
    *(int *)(p + 0x2144) = 0;
    *(char **)(p + 0x2148) = D_003C0160;
    *(char **)(p + 0x214C) = D_003C0188;
    *(int *)(p + 0x2150) = 0;
    *(int *)(p + 0x2154) = 0;
    *(char **)(p + 0x2158) = D_003C0200;
    *(char **)(p + 0x215C) = D_003C02A0;
    *(char **)(p + 0x2160) = D_003C0340;
    *(char **)(p + 0x2164) = D_00585720;
    *(int *)(p + 0x2168) = 0;
    *(int *)(p + 0x2188) = 0;
    *(float *)(p + 0x216C) = 0.015f;
    *(float *)(p + 0x2170) = 0.8f;
    *(int *)(p + 0x2174) = 1;
    *(float *)(p + 0x2178) = 0.0f;
    *(float *)(p + 0x217C) = 0.8f;
    *(float *)(p + 0x2180) = 0.5f;
    *(int *)(p + 0x2184) = 0;
    *(int *)(p + 0x218C) = 0x100;
    v[0] = 0.0f;
    v[1] = 0.0f;
    *(int *)&v[2] = 0;
    v[3] = 1.0f;
    dst = (volatile float *)(p + 0x2190);
    if (dst != (volatile float *)v) {
        dst[0] = v[0];
        dst[1] = v[1];
        dst[2] = *(volatile float *)&v[2];
    }
    *(float *)(p + 0x21A0) = 1.0471976f;
    func_001038E0(p, p + 0x2130, p + 0x5B0, 0.1f, 0.0f);
}

__attribute__((section(".text.func_0017AEB0")))
void func_0017AEB0(char *p)
{
    unsigned char frame[0x10];
    unsigned int b;
    int o, o2;
    float x;

    if (*(short *)(p + 0x606) == 0) return;
    if (*(unsigned char *)(p + 0x2F4) == 0) {
        *(short *)(p + 0x606) = *(unsigned short *)(p + 0x606) - 1;
        cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x1E, -1, -1, 0, 0);
        if (*(short *)(p + 0x606) != 0) {
            if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (0 < b)))
                o = *(int *)(*(int *)(p + 0x278));
            else
                o = 0;
            if (o == 0) return;
            if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (0 < b)))
                o2 = *(int *)(*(int *)(p + 0x278));
            else
                o2 = 0;
            x = DoubleFloatMinusHalf_31D020();
            *(float *)(o2 + 0x100) = *(float *)(p + 0x608) + (x + x) * 0.0174532924f;
        } else {
            if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (0 < b)))
                o = *(int *)(*(int *)(p + 0x278));
            else
                o = 0;
            if (o == 0) return;
            if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (0 < b)))
                o = *(int *)(*(int *)(p + 0x278));
            else
                o = 0;
            *(float *)(o + 0x100) = *(float *)(p + 0x608);
        }
    } else {
        *(short *)(p + 0x606) = 0;
        if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (0 < b)))
            o = *(int *)(*(int *)(p + 0x278));
        else
            o = 0;
        if (o == 0) return;
        if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (0 < b)))
            o = *(int *)(*(int *)(p + 0x278));
        else
            o = 0;
        *(float *)(o + 0x100) = *(float *)(p + 0x608);
    }
}

__attribute__((section(".text.func_00247588")))
void func_00247588(char *p)
{
    unsigned char frame[0x10];
    void *ptr;
    int b, o1, o2, i1, i2, r;
    char *q;
    char *cam;
    char *parts;
    unsigned char st;

    ptr = Obj0000_Get_D_00747A94_2DB6B0();
    *(int *)(p + 0x16D0) |= 0x30000;
    *(float *)(p + 0x54C) = 3.0f;
    *(int *)(p + 0x250) |= 0x10000;
    st = *(unsigned char *)(p + 0x2F6);
    if (st == 0) goto blockA;
    if (st == 1) goto common;
    return;
blockA:
    {
        r = Obj0000_Get_Byte_17C3_NZ_2_276468(p);
        q = *(char **)(p + 0x304);
        func_002A8578(p, *(int *)(q + 0x2FB4) + (int)q, *(int *)(q + 0x2FB8) + (int)q,
                      0.0f, 0, r & 0xFFFF, 0);
        Obj1D00_SetState_7_1C(*(int *)(p + 0x708));
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    }
common:
    cam = D_00463050;
    cCamManager_setPartsCamera(cam, 0);
    parts = cam + 0x920;
    i1 = 0x1B;
    if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (i1 < b)))
        o1 = *(int *)(*(int *)(p + 0x278) + i1 * 4);
    else
        o1 = 0;
    i2 = 0x1C;
    if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (i2 < b)))
        o2 = *(int *)(*(int *)(p + 0x278) + i2 * 4);
    else
        o2 = 0;
    Obj0000_Set_Fields_360_364_368_139B68(parts, p, o1, o2);
    if (moveMotion(p) != 0) {
        ClearField15F4Bit1_124F60(ptr, 0, 1);
        func_002705D8(p);
    }
    AddScaledVecToField_100_14F9F0(p, 1.0f);
    AddScaledXfmVecToField_F0_14F928(p, 1.0f);
}

__attribute__((section(".text.func_00271298")))
void func_00271298(char *p)
{
    unsigned char frame[0x10];
    int b;
    int i4;
    int o;
    char *g;
    char *q;
    float z;
    float r;
    float t;
    float m;
    float dy;
    float u;

    i4 = 4;
    if (((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (i4 < b)))
        o = *(int *)(*(int *)(p + 0x278) + i4 * 4);
    else
        o = 0;
    g = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    z = 0.0f;
    if (*(float *)(g + 0x54C) > z) return;
    if (*(int *)(g + 0x6A0) != 0) return;
    if (o == 0) return;
    q = *(char **)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0xF0);
    dy = Turn_dest(q, *(char **)(o + 0xF0),
                   *(float *)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0x104),
                   3.14159274f);
    r = dy;
    if (r < z) t = -r; else t = r;
    if (t > 0.785398185f) return;
    m = *(float *)(*(int *)(g + 0xF0) + 4) - *(float *)(*(int *)(p + 0xF0) + 4);
    dy = m;
    if (dy < z) u = -dy; else u = dy;
    if (u > 0.5f) return;
    m = capVu0MagnitudeSqXZ(*(char **)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                            *(char **)(o + 0xF0));
    if (m < 9.0f) func_002DC390(p);
}
