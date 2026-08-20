/* sn-2.95.3-136 matched TU. */

extern void MaxField514_292030(void *a0, int a1);
extern void Obj293_SetByte_53C_2(void *a0);
extern void MaxByte538_292EF0(void *a0, int a1);
extern void SetField548AndGlobals_292F38(void *a0, float a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00129578(void *a0);
extern void ShiftDownBytesA8_FAC00(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int cCoreSave_getCostumeNo(void *a0);
extern void func_0012BC00(void *a0, int a1, int a2);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005864F0[];
extern char D_005FEE00[];
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */























__attribute__((section(".text.func_00111DD8")))
void func_00111DD8(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(D_005864F0, 2);
    Obj293_SetByte_53C_2(D_005864F0);
    MaxByte538_292EF0(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        *(char *)(s1 + 0x1684) = 1;
        func_00129578(s1);
        ShiftDownBytesA8_FAC00(&D_00569B70);
        ShiftDownBytesA8_FAC00(&D_00569B70);
        ShiftDownBytesA8_FAC00(&D_00569B70);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x20) + t, *(int *)(t + 0x24) + t,
                      0.0f, 3, 0, 0);
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
        *(int *)(s1 + 0x15B0) = 1;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
        if (*(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            switch (cCoreSave_getCostumeNo(&D_00569B70)) {
            default:
            case 0:
            case 2:
            case 4:
            case 6:
                func_0012BC00(s1, 0x29, 0);
                break;
            case 1:
            case 3:
            case 5:
            case 7:
                func_0012BC00(s1, 0x2A, 0);
                func_0012BC00(s1, 0x2B, 0);
                break;
            }
        }
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
        char *g = D_005FEE00;
        cSnd_SeStop(g, *(int *)(s1 + 0x161C));
        *(int *)(s1 + 0x161C) = 0;
        *(int *)(g + 0xB0) &= 0xFFBFFFFF;
        *(int *)(g + 0xAC) &= 0xFFBFFFFF;
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 1, 0);
    } else {
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}
