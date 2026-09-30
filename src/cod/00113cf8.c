/* sn-2.95.3-136 matched TU. */

extern void MaxField514_292030(void *a0, int a1);
extern void Obj293_SetByte_53C_2(void *a0);
extern void MaxByte538_292EF0(void *a0, int a1);
extern void func_00129BA0(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void func_00124EC0(void *a0);

extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void SetField548AndGlobals_292F38(void *a0, float a1);
extern int D_005864F0;

__attribute__((section(".text.func_00113CF8")))
void func_00113CF8(void *a0)
{
    char *s1 = (char *)a0;
    int b;
    float one;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(&D_005864F0, 2);
    Obj293_SetByte_53C_2(&D_005864F0);
    MaxByte538_292EF0(&D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        func_00129BA0(s1);
        ClearField15F4Bit1_124F60(s1, 0, 0);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        b = *(int *)(s1 + 0x304);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_002A8578(s1, *(int *)(b + 0x220) + b, *(int *)(b + 0x224) + b, 21.0f, 3, 0, 0);
        *(int *)(s1 + 0x15B0) = 0xD;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        moveMotion(s1);
        if (*(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = *(int *)(s1 + 0x15B0) - 1;
        } else {
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        SetField548AndGlobals_292F38(&D_005864F0, 0.1f);
        break;
    case 2:
        Obj0000_Clear_Fields_640_648_124E58(s1);
        b = *(int *)(s1 + 0x304);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_002A8578(s1, *(int *)(b + 0x380) + b, *(int *)(b + 0x384) + b, 0.0f, 0, 0, 0);
        *(unsigned short *)(s1 + 0x54A) = *(unsigned short *)(s1 + 0x54A) - 10;
        if (*(short *)(s1 + 0x54A) < 2) {
            *(short *)(s1 + 0x54A) = 1;
        }
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 3:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        if (func_00123938(s1, 1) != 0) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
        }
        break;
    }
}
