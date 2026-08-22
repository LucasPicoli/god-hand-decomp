/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);

__attribute__((section(".text.func_00247320")))
void func_00247320(void *a0)
{
    char *s0 = (char *)a0;
    int v0;

    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x20000;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int a;
        int bb;

        {
            int id = *(int *)(s0 + 0x564);
            if (id != 0x22C) {
                if (id >= 0x22D) goto dflt;
                if (id != 0x21C) {
                dflt:
                {
                    int b = *(int *)(s0 + 0x304);
                    a = *(int *)(b + 0x36F0) + b;
                    bb = *(int *)(b + 0x36F4) + b;
                }
                } else {
                {
                    int b = *(int *)(s0 + 0x304);
                    a = *(int *)(b + 0x3708) + b;
                    bb = *(int *)(b + 0x370C) + b;
                }
                }
            } else {
                {
                    int b = *(int *)(s0 + 0x304);
                    a = *(int *)(b + 0x3710) + b;
                    bb = *(int *)(b + 0x3714) + b;
                }
            }
        }
        func_002A8578(s0, a, bb, 0.0f, 0, t0, 0);
    }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            if (*(int *)(s0 + 0x564) == 0x244) {
                *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
            } else {
                func_002705D8(s0);
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2:
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;

        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x36F8) + v0, *(int *)(v0 + 0x36FC) + v0, 0.0f, 3, t0, 0);
    }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(int *)(s0 + 0x16D0) & 0x20000000) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        if (0.0f < *(float *)(s0 + 0x16C0)) {
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        break;
    case 4:
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;

        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x3700) + v0, *(int *)(v0 + 0x3704) + v0, 0.0f, 3, t0, 0);
    }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5:
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
}
