/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern unsigned char D_005FEE00[];
extern int D_00462FC0;

__attribute__((section(".text.func_0025A920")))
void func_0025A920(void *a0)
{
    char *s1 = (char *)a0;

    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x1084) + b, *(int *)(b + 0x1088) + b,
                      0.0f, 3, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                           (short)Obj0000_Get_Field_424_1595F0(s1),
                           s1, 0, 0, 0, 0);
        *(unsigned char *)(s1 + 0x1866) = *(unsigned char *)(s1 + 0x1866) + 1;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 1:
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 2:
    {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x107C) + b, *(int *)(b + 0x1080) + b,
                      0.0f, 3, 0, 0);
        *(float *)(s1 + 0x600) = 150.0f;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 3:
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
        if (*(float *)(s1 + 0x600) <= 0.0f) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        break;
    case 4:
    {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x1094) + b, *(int *)(b + 0x1098) + b,
                      0.0f, 3, 0, 0);
        *(float *)(s1 + 0x54C) = 5.0f;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 5:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    *(short *)(s1 + 0x3AC) = *(short *)(s1 + 0x3AC) | 0x400;
}
