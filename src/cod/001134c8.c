/* sn-2.95.3-136 matched TU. */

extern void MaxField514_292030(void *a0, int a1);
extern void Obj293_SetByte_53C_2(void *a0);
extern void MaxByte538_292EF0(void *a0, int a1);
extern void ShiftDownBytesA8_FAC00(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00129578(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void SetField548AndGlobals_292F38(void *a0, float a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern int Obj0000_Get_Field_1580_27A128(int a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0010A438(void *a0);
extern int D_005864F0;
extern int D_00569B70;
extern int D_0041C208;

__attribute__((section(".text.func_001134C8")))
void func_001134C8(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(&D_005864F0, 2);
    Obj293_SetByte_53C_2(&D_005864F0);
    MaxByte538_292EF0(&D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    if (*(unsigned char *)(s1 + 0x2F6) != 0) {
        if (*(unsigned char *)(s1 + 0x649) == 0) {
            if (func_0010B2E8(s1, 1) != 0) {
                *(char *)(s1 + 0x649) = 1;
                ShiftDownBytesA8_FAC00(&D_00569B70);
            }
        }
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        char *v0;
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x50, 6, 0x28, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x50, 6, 0x28, 0, 0x123);
        *(char *)(s1 + 0x1684) = 1;
        func_00129578(s1);
        v0 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x8A8) + (int)v0, *(int *)(v0 + 0x8AC) + (int)v0, 0.0f, 3, 0, 0);
        SetField548AndGlobals_292F38(&D_005864F0, 0.1f);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        float one;
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
            int t = *(int *)(s1 + 0x640);
            if (t != 0) {
                char *s0 = (char *)t;
                if (func_003A5678(&D_0041C208, *(int *)(s0 + 0x4AC)) == 0) {
                    s0 = (char *)Obj0000_Get_Field_1580_27A128(*(int *)(s1 + 0x640));
                }
                *(char *)(s0 + 0x2F4) = 1;
                *(char *)(s0 + 0x2F5) = 6;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            }
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    }
    }
    func_0010A438(s1);
    if (*(unsigned short *)(s1 + 0x3AC) & 0x100) {
        SetField548AndGlobals_292F38(&D_005864F0, 0.1f);
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 1, 0);
    } else {
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}
