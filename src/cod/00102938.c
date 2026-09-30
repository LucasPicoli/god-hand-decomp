/* sn-2.95.3-136 matched TU. */

extern unsigned int func_0031ED08(float f12);
extern int setMotionInfo(void *a0, int a1, int a2, int a3, float f12, float f13, int t0);
extern int moveMotion(void *a0);
extern void func_0014E818(void *a0, float f12, void *a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_0028FB08(void *a0);
extern void cCoreSave_addKillNpcNum(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int D_00462FC0;
extern int D_00569B70;
extern char D_005FEE00[];
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern unsigned int Forward30F348_31CFE0(void);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Adjust_theta(float f12);
extern void func_001034E0(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void Obj2810_ClearState_5(void *a0);
extern void ClearBytes2F4To2F7_283170(void *a0);

__attribute__((section(".text.func_0014EB90")))
void func_0014EB90(void *a0)
{
    char *s0 = (char *)a0;
    float one;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        setMotionInfo(s0, *(int *)(s0 + 0x428), *(int *)(s0 + 0x42C),
                      func_0031ED08(*(float *)(s0 + 0x438)),
                      *(float *)(s0 + 0x440), *(float *)(s0 + 0x430),
                      *(unsigned short *)(s0 + 0x434));
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        func_0014E818(s0, *(float *)(s0 + 0x4B8), s0 + 0x4C0);
        one = 1.0f;
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    case 2:
        moveMotion(s0);
        func_0014E818(s0, *(float *)(s0 + 0x4B8), s0 + 0x4C0);
        one = 1.0f;
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00288A58")))
void func_00288A58(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    float one;

    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        func_0028FB08(s0);
        cCoreSave_addKillNpcNum(&D_00569B70);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x90) + v0, *(int *)(v0 + 0x94) + v0, 0.0f, 5, 0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5F, s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F7) = 0;
            *(unsigned char *)(s0 + 0x2F4) = 2;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 2;
        } else {
            one = 1.0f;
            AddScaledVecToField_100_14F9F0(s0, one);
            AddScaledXfmVecToField_F0_14F928(s0, one);
        }
        break;
    }
}

__attribute__((section(".text.func_0011A530")))
void func_0011A530(void *a0)
{
    char *s0 = (char *)a0;
    char *t0;
    int p1, p2;
    float one;

    *(int *)(s0 + 0x15F4) |= 0x80;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        t0 = *(char **)(s0 + 0x304);
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        p1 = *(int *)(t0 + 0x28) + (int)t0;
        p2 = *(int *)(t0 + 0x2C) + (int)t0;
        if (*(void **)(s0 + 0x6A0) != 0) {
            func_002A8578(*(void **)(s0 + 0x6A0), *(int *)(t0 + 0x36C) + (int)t0,
                          *(int *)(t0 + 0x388) + (int)t0, 0.0f, 10, 0, 0);
            {
            char *v0 = *(char **)(s0 + 0x304);
            p1 = *(int *)(v0 + 0x344) + (int)v0;
            p2 = *(int *)(v0 + 0x348) + (int)v0;
            *(unsigned char *)(s0 + 0x2F7) = 3;
            }
        }
        if (*(int *)(s0 + 0x698) != 0) {
            {
            char *v0 = *(char **)(s0 + 0x304);
            p1 = *(int *)(v0 + 0x3AC) + (int)v0;
            p2 = *(int *)(v0 + 0x3B0) + (int)v0;
            *(unsigned char *)(s0 + 0x2F7) = 3;
            }
        }
        func_002A8578(s0, p1, p2, 0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        one = 1.0f;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00102CB0")))
void func_00102CB0(void *a0)
{
    char *s0 = (char *)a0;
    float one;
    int p1, p2, t0;

    t0 = 0;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        switch (*(unsigned char *)(s0 + 0x2F7)) {
        case 0:
        default:
            {
            char *v0 = *(char **)(s0 + 0x304);
            p1 = *(int *)(v0 + 0x6C) + (int)v0;
            p2 = *(int *)(v0 + 0x70) + (int)v0;
            t0 = (Forward30F348_31CFE0() & 1) << 1;
            }
            break;
        case 1:
            {
            char *v1 = *(char **)(s0 + 0x304);
            p1 = *(int *)(v1 + 0x64) + (int)v1;
            p2 = *(int *)(v1 + 0x68) + (int)v1;
            }
            break;
        case 2:
            {
            char *v2 = *(char **)(s0 + 0x304);
            p1 = *(int *)(v2 + 0x5C) + (int)v2;
            p2 = *(int *)(v2 + 0x60) + (int)v2;
            }
            break;
        case 3:
            {
            char *v3 = *(char **)(s0 + 0x304);
            t0 = 2;
            p1 = *(int *)(v3 + 0x5C) + (int)v3;
            p2 = *(int *)(v3 + 0x60) + (int)v3;
            }
            break;
        }
        func_002A8578(s0, p1, p2, 0.0f, 5, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00102938")))
void func_00102938(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    char *v0;
    float one;
    float f;

    s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x14) + (int)v0, *(int *)(v0 + 0x18) + (int)v0, 0.0f, 10, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (*(unsigned char *)(s1 + 0x61F) != 0) {
            f = *(float *)(s1 + 0x608) - 0.5235988f;
            if (f < 0.0f) {
                f = 0.0f;
            }
            f = f * 0.4f;
            if (0.041887902f < f) {
                f = 0.041887902f;
            }
            if (*(float *)(s1 + 0x604) < 0.0f) {
                f = -f;
            }
            *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + f;
            *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
        }
        one = 1.0f;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
    func_001034E0(s0);
}

__attribute__((section(".text.func_0024AA68")))
void func_0024AA68(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    int t0;
    float one;
    float f;

    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x30400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(char *)(s0 + 0x1864) = 0;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x3D94) + v0, *(int *)(v0 + 0x3D98) + v0, 0.0f, 10, t0, 0);
        if (*(void **)(s0 + 0x748) != 0) {
            Obj2810_ClearState_5(*(void **)(s0 + 0x748));
        }
        if (*(void **)(s0 + 0x74C) != 0) {
            ClearBytes2F4To2F7_283170(*(void **)(s0 + 0x74C));
        }
        if (*(void **)(s0 + 0x750) != 0) {
            ClearBytes2F4To2F7_283170(*(void **)(s0 + 0x750));
        }
        *(float *)(s0 + 0x600) = 30.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        f = *(float *)(s0 + 0x600);
        if (0.0f < f) {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
            *(float *)(s0 + 0x600) = f - *(float *)(s0 + 0x5A8);
        }
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0xA1;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}
