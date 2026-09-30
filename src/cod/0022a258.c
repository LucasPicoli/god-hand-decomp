/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void func_0026B240(void *a0, int a1, int a2, int a3);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void func_0028FB08(void *a0);
extern void cEmManage_ReleaseEm(void *a0, void *a1);
extern char D_005864F0[];

__attribute__((section(".text.func_0022A258")))
void func_0022A258(void *a0)
{
    char *s0 = (char *)a0;
    char *v;
    float one;
    int r, t;

    *(char *)(s0 + 0x186A) = 2;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v + 0x3914) + (int)v, *(int *)(v + 0x3918) + (int)v, 0.0f, 3, t, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(int *)(s0 + 0x5F4) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        v = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(int *)(v + 0xF0), *(float *)(s0 + 0x5A8) * 0.09817477f);
        *(int *)(s0 + 0x16D0) |= 0x800000;
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                *(int *)(s0 + 0x5F0) = 0;
                r = func_0026AA30(s0, 0x37E);
                if (r != 0) {
                    func_0026B240(s0, r, 0x37E, 0xE);
                }
            }
        } else {
            *(int *)(s0 + 0x5F0) = 1;
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(int *)(s0 + 0x5F4) != 0) {
                *(int *)(s0 + 0x5F4) = 0;
                r = func_0026AA30(s0, 0x37E);
                if (r != 0) {
                    func_0026B240(s0, r, 0x37E, 0x12);
                }
            }
        } else {
            *(int *)(s0 + 0x5F4) = 1;
        }
        break;
    }
}

__attribute__((section(".text.func_00277D38")))
void func_00277D38(void *a0)
{
    char *s0 = (char *)a0;
    char *v;
    float one;

    *(int *)(s0 + 0x1560) |= 1;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(float *)(s0 + 0x104) = 2.5918138f;
        *(float *)(*(char **)(s0 + 0xF0) + 0) = -80.327904f;
        *(float *)(*(char **)(s0 + 0xF0) + 4) = -26.400499f;
        *(float *)(*(char **)(s0 + 0xF0) + 8) = -22.3136f;
        v = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v + 0xC) + (int)v, *(int *)(v + 0x10) + (int)v, 0.0f, 0, 0, 0);
        *(short *)(s0 + 0x568) = 0x3C;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        one = 1.0f;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        if (--*(short *)(s0 + 0x568) <= 0) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 2:
        func_002A8578(s0, *(int *)(*(char **)(s0 + 0x304) + 0x6C) + *(int *)(s0 + 0x304), *(int *)(*(char **)(s0 + 0x304) + 0x70) + *(int *)(s0 + 0x304), 0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        if (moveMotion(s0) != 0) {
            func_0028FB08(s0);
            cEmManage_ReleaseEm(D_005864F0, s0);
            break;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}
