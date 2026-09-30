/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void func_002812A8(void *a0, int a1, int a2);
extern void func_002831C8(void *a0, int a1, int a2);
extern void func_002495E0(void *a0, float f);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern float Adjust_theta(float f12);
extern int Obj293_IsByteSet_53C(void *a0);
extern void func_0026A638(void *a0, int a1);
extern void func_0026A838(void *a0, int a1);
extern char D_005864F0[];

__attribute__((section(".text.func_0024A518")))
void func_0024A518(void *a0)
{
    char *s0 = (char *)a0;
    int t0, b;
    float one;
    float f;

    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x30400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(char *)(s0 + 0x1864) = 0;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x3D7C) + b, *(int *)(b + 0x3D80) + b, 0.0f, 10, t0, 0);
        if (*(void **)(s0 + 0x748) != 0) {
            func_002812A8(*(void **)(s0 + 0x748), 1, 0);
        }
        if (*(void **)(s0 + 0x74C) != 0) {
            func_002831C8(*(void **)(s0 + 0x74C), 1, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        one = 1.0f;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        if (*(float *)(s0 + 0x176C) <= 0.0f) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 2:
        *(char *)(s0 + 0x1864) = 0;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x3D84) + b, *(int *)(b + 0x3D88) + b, 0.0f, 10, t0, 0);
        if (*(void **)(s0 + 0x748) != 0) {
            func_002812A8(*(void **)(s0 + 0x748), 2, 0);
        }
        if (*(void **)(s0 + 0x74C) != 0) {
            func_002831C8(*(void **)(s0 + 0x74C), 2, 0);
        }
        *(float *)(s0 + 0x600) = 30.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        f = *(float *)(s0 + 0x600);
        if (0.0f < f) {
            *(float *)(s0 + 0x600) = f - *(float *)(s0 + 0x5A8);
        } else {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xFEFFFFFF;
        }
        func_002495E0(s0, 0.0f);
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
        if (moveMotion(s0) != 0) {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xFEFFFFFF;
            func_002705D8(s0);
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}

__attribute__((section(".text.func_0022AF90")))
void func_0022AF90(void *a0)
{
    char *s1 = (char *)a0;
    char *v0;
    char *s0;
    char *s2;
    int gb, b;
    float one;
    float th, d, ad, f, g;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        *(int *)(s1 + 0x16D0) = (*(int *)(s1 + 0x16D0) | 2) & 0xFFFF7FFF;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0xCF8) + b, *(int *)(b + 0xCFC) + b, 0.0f, 10, gb, 0);
        *(int *)(s1 + 0x5FC) = 0;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        s0 = *(char **)(s1 + 0xF0);
        v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        one = 1.0f;
        th = Turn_dest(s0, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x1670), 0.5235988f);
        d = Turn_dest_dir(*(float *)(s1 + 0x104), Adjust_theta(th + *(float *)(s1 + 0x1670)), *(float *)(s1 + 0x5A8) * 0.19634955f);
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + d;
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        if (*(short *)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0x54A) <= 0) {
            return;
        }
        if (Obj293_IsByteSet_53C(D_005864F0) != 0) {
            return;
        }
        f = *(float *)(s1 + 0x618);
        if (9.0f < f && f < 400.0f && *(float *)(s1 + 0x1714) <= 0.0f) {
            s2 = *(char **)(s1 + 0xF0);
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            d = Turn_dest(s2, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x104), 3.14159274f);
            if (d < 0.0f) {
                f = -d;
                ad = f;
            } else {
                ad = d;
            }
            if (ad < 0.26179940f) {
                *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
            }
        }
        if (*(float *)(s1 + 0x618) < 25.0f) {
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            d = *(float *)(*(char **)(s1 + 0xF0) + 4) - *(float *)(*(char **)(v0 + 0xF0) + 4);
            if (d < 0.0f) {
                f = -d;
                ad = f;
            } else {
                ad = d;
            }
            if (ad < 0.5f) {
                func_002705D8(s1);
            }
        }
        break;
    case 2:
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0xDBC) + b, *(int *)(b + 0xDC0) + b, 0.0f, 10, gb, 0);
        *(int *)(s1 + 0x5F0) = 0x64;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 3:
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        if (*(unsigned short *)(s1 + 0x3AC) & 1) {
            if (*(unsigned char *)(s1 + 0x17C3) != 0) {
                func_0026A638(s1, 1);
            } else {
                func_0026A638(s1, 0);
            }
        }
        if (*(unsigned short *)(s1 + 0x3AC) & 2) {
            func_0026A838(s1, 0);
            func_0026A838(s1, 1);
        }
        break;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 3) {
        *(int *)(s1 + 0x5FC) = 1;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) = *(int *)(s1 + 0x16D4) & 0xFFFFFBFF;
    }
}
