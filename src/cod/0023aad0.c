/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A74E0(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int D_007476B0;

/* sn-2.95.3-136 */












__attribute__((section(".text.func_0023AAD0")))
void func_0023AAD0(void *a0)
{
    char *s0 = (char *)a0;
    float one;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(unsigned char *)(s0 + 0x1864) = 0;
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int b = *(int *)(s0 + 0x304);

        func_002A8578(s0, *(int *)(b + 0xC08) + b, *(int *)(b + 0xC0C) + b, 0.0f, 0xA, t0, 0);
    }
        *(int *)(s0 + 0x16D0) = (*(int *)(s0 + 0x16D0) | 0x8000) & 0xFFFFFFFD;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x400000;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
            break;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    case 2:
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int b = *(int *)(s0 + 0x304);

        func_002A8578(s0, *(int *)(b + 0xC08) + b, *(int *)(b + 0xC0C) + b, 0.0f, 0xA, t0, 0);
    }
        *(int *)(s0 + 0x5F0) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
    {
        int x = *(short *)(s0 + 0x54A);
        int lim = *(short *)(s0 + 0x548);

        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x400000;
        x = x + 1;
        if (lim < x) {
            x = lim;
        }
        if (lim <= x) {
            *(unsigned short *)(s0 + 0x54A) = *(unsigned short *)(s0 + 0x548);
        } else {
            *(short *)(s0 + 0x54A) = x;
        }
    }
        if ((D_007476B0 & 7) == (*(int *)(s0 + 0x17D0) & 7)) {
            *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) & 0xF7FFFFFF;
            func_002A74E0(s0, *(int *)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0xF0), 1);
            if (func_002A7CA0(s0, s0 + 0x16A0) != 0) {
                *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) | 0x8000000;
            }
            if (*(float *)(s0 + 0x510) < 8.0f) {
                *(int *)(s0 + 0x5F0) = 0;
                *(int *)(s0 + 0x16D0) = (*(int *)(s0 + 0x16D0) & 0xFFFF7FFF) | 2;
            }
        }
        if (*(int *)(s0 + 0x16EC) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        if (moveMotion(s0) != 0) {
            if (*(int *)(s0 + 0x5F0) == 0) {
                *(unsigned char *)(s0 + 0x2F6) = 4;
            }
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    case 4:
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int b = *(int *)(s0 + 0x304);

        func_002A8578(s0, *(int *)(b + 0xC10) + b, *(int *)(b + 0xC14) + b, 0.0f, 0xA, t0, 0);
    }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5:
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x400000;
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
            break;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}
