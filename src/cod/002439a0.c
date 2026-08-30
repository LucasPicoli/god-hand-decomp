/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f12, int t0, int t1);
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_0026B600(void *a0);
extern void func_0026BAD8(void *a0, int a1, int a2);
extern float capVu0Sin(float f12);
extern float Adjust_theta(float f12);
extern char D_00462FC0[];

__attribute__((section(".text.func_002439A0")))
void func_002439A0(void *a0)
{
    char *s0 = (char *)a0;
    float t20;
    float th;
    int p;

    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    *(int *)(s0 + 0x16D0) |= 0x10000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x2474) + w, *(int *)(w + 0x2478) + w,
                      3, 0.0f, t, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(float *)(s0 + 0x60C) = 0.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) && *(int *)(s0 + 0x5F0) != 0) {
            *(int *)(s0 + 0x5F0) = 0;
            func_0026B600(s0);
        }
        break;
    case 2: {
        int t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x247C) + w, *(int *)(w + 0x2480) + w,
                      3, 0.0f, t, 0);
        *(float *)(s0 + 0x600) = 90.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3: {
        float d;
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        d = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        *(float *)(s0 + 0x600) = d;
        if (d <= 0.0f)
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        break;
    }
    case 4: {
        int t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x249C) + w, *(int *)(w + 0x24A0) + w,
                      3, 0.0f, t, 0);
        *(float *)(s0 + 0x600) = 0.0f;
        *(short *)(s0 + 0x568) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5:
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 3) {
            if (*(short *)(s0 + 0x568) > 0)
                goto chk;
            *(short *)(s0 + 0x568) = 8;
            *(float *)(s0 + 0x600) = 2.0f;
        }
        if (*(short *)(s0 + 0x568) == 0)
            break;
    chk:
        if (0.0f < *(float *)(s0 + 0x600)) {
            *(float *)(s0 + 0x600) = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        } else {
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
            func_0026BAD8(s0, 1, 1);
            *(float *)(s0 + 0x600) = 20.0f;
        }
        break;
    case 6: {
        int t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x247C) + w, *(int *)(w + 0x2480) + w,
                      3, 0.0f, t, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 7:
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s0 + 0x568) != 0) {
            if (0.0f < *(float *)(s0 + 0x600)) {
                *(float *)(s0 + 0x600) = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
            } else {
                *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
                func_0026BAD8(s0, 1, 1);
                *(float *)(s0 + 0x600) = 20.0f;
            }
        } else {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 8: {
        int t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x24A4) + w, *(int *)(w + 0x24A8) + w,
                      3, 0.0f, t, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 9:
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 10: {
        int t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x2464) + w, *(int *)(w + 0x2468) + w,
                      3, 0.0f, t, 0);
        *(float *)(s0 + 0x600) = 90.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 11: {
        float d;
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        d = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        *(float *)(s0 + 0x600) = d;
        if (d <= 0.0f) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x7F;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    }
    default:
        break;
    }
    t20 = capVu0Sin(*(float *)(s0 + 0x60C)) * 0.02f;
    th = *(float *)(s0 + 0x60C) + *(float *)(s0 + 0x5A8) * 0.17453292f;
    *(float *)(s0 + 0x60C) = th;
    *(float *)(s0 + 0x60C) = Adjust_theta(th);
    p = *(int *)(s0 + 0xF0);
    *(float *)(p + 4) = *(float *)(p + 4) + t20 * *(float *)(s0 + 0x5A8);
}
