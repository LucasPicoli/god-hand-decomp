/* sn-2.95.3-136 matched TU. */

/* func_0010EE80 — 0x0010EE80, 880 B — sn-2.95.3-136.
 * +0x2F6 phase machine; template src/cod/00111750.c. */

extern void MaxField514_292030(void *a0, int a1);
extern void MaxByte538_292EF0(void *a0, int a1);

extern void ShiftDownBytesA8_FAC00(void *a0);
extern void func_00129578(void *a0);

extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00124EC0(void *a0);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int  moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void SetField548AndGlobals_292F38(void *a0, float a1);
extern void func_0010A438(void *a0);

extern void cSnd_SeStop(void *a0, int a1);
extern int  D_00747A0C;
extern int  D_00569B70;
extern char D_005864F0[];
extern char D_005FEE00[];

__attribute__((section(".text.func_0010EE80")))
void func_0010EE80(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(D_005864F0, 2);
    MaxByte538_292EF0(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    if (*(unsigned char *)(s1 + 0x2F6) != 0 &&
        *(unsigned char *)(s1 + 0x649) == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        *(char *)(s1 + 0x649) = 1;
        ShiftDownBytesA8_FAC00(&D_00569B70);
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int p, q;

        func_00129578(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_00124540(s1, 1);
        if (*(unsigned char *)(s1 + 0x2F7) != 0) {
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0xE6, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0xE6, 0xD, 0x1D, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0xC8, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0xC8, 0xD, 0x1D, 0, 0x123);
            }
            {
                int t = *(int *)(s1 + 0x304);
                p = *(int *)(t + 0xD4) + t;
                q = *(int *)(t + 0xDC) + t;
            }
        } else {
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x64, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x64, 0xD, 0x1D, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x50, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x50, 0xD, 0x1D, 0, 0x123);
            }
            {
                int t = *(int *)(s1 + 0x304);
                p = *(int *)(t + 0xD4) + t;
                q = *(int *)(t + 0xD8) + t;
            }
        }
        *(char *)(s1 + 0x1684) = 1;
        func_002A8578(s1, p, q, 0.0f, 3, 0, 0);
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        InvokeVirtualAtField214AndForward_124E68(s1, 0.13089969754219055f);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
            ClearField15F4Bit1_124F60(s1, 1, 0);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 1, 0);
    } else {
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
            char *g = D_005FEE00;
            cSnd_SeStop(g, *(int *)(s1 + 0x161C));
            *(int *)(s1 + 0x161C) = 0;
            *(int *)(g + 0xB0) &= 0xFFBFFFFF;
            *(int *)(g + 0xAC) &= 0xFFBFFFFF;
        }
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}
