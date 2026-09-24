/* sn-2.95.3-136 matched TU. */

extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f, int a4, int a5);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int  moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0010A438(void *a0);


struct VtEnt { short delta; short index; void *pfn; };

__attribute__((section(".text.func_0010DE70")))
void func_0010DE70(void *a0)
{
    char *s1 = (char *)a0;

    if (*(short *)(s1 + 0x54A) <= 0)
        *(short *)(s1 + 0x54A) = 1;
    if (func_0010B2E8(s1, 0) != 0 && *(int *)(s1 + 0x15BC) >= 3)
        *(int *)(s1 + 0x15BC) = 2;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int p, q;
        float f;

        func_00124540(s1, 1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        if (*(signed char *)(s1 + 0x648) > 0)
            *(char *)(s1 + 0x648) = 0x2D;
        switch (*(unsigned char *)(s1 + 0x2F7)) {
        default:
        case 0:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, (int)(*(float *)(s1 + 0x600) * 15.0f), 4, 0x1A, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, (int)(*(float *)(s1 + 0x600) * 15.0f), 4, 0x1A, 0, 0x77);
            {
                int t = *(int *)(s1 + 0x304);
                f = 2.0f;
                p = *(int *)(t + 0x830) + t;
                q = *(int *)(t + 0x834) + t;
            }
            break;
        case 1:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, (int)(*(float *)(s1 + 0x600) * 10.0f), 4, 0x1A, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, (int)(*(float *)(s1 + 0x600) * 10.0f), 4, 0x1A, 0, 0x77);
            {
                int t = *(int *)(s1 + 0x304);
                f = 5.0f;
                p = *(int *)(t + 0x61C) + t;
                q = *(int *)(t + 0x624) + t;
            }
            break;
        case 2:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, (int)(*(float *)(s1 + 0x600) * 10.0f), 3, 0x1B, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, (int)(*(float *)(s1 + 0x600) * 10.0f), 3, 0x1B, 0, 0x77);
            {
                int t = *(int *)(s1 + 0x304);
                f = 2.0f;
                p = *(int *)(t + 0x838) + t;
                q = *(int *)(t + 0x83C) + t;
                *(char *)(s1 + 0x1603) = 0xF;
            }
            break;
        }
        func_002A8578(s1, p, q, 3, f, 0x40, 0);
        *(float *)(s1 + 0x15C4) = 0.0f;
        *(int *)(s1 + 0x15B0) = 1;
        *(int *)(s1 + 0x15B4) = 0;
        *(float *)(s1 + 0x1588) = 0.0f;
        *(float *)(s1 + 0x15C0) = 1.0f;
        *(int *)(s1 + 0x15B8) = 1;
        *(int *)(s1 + 0x15BC) = 999;
        *(short *)(s1 + 0x568) = 10;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
    {
        char *e;

        if (*(short *)(s1 + 0x568) != 0) {
            *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
            InvokeVirtualAtField214AndForward_124E68(s1, 0.392699093f);
        }
        if (*(int *)(s1 + 0x640) != 0)
            *(char *)(s1 + 0x648) = 0x14;
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        e = *(char **)(s1 + 0x640);
        if (e != 0 && *(unsigned char *)(s1 + 0x2F7) != 0) {
            struct VtEnt *vt = *(struct VtEnt **)(e + 0x214);
            float *pos = *(float **)(s1 + 0xF0);
            void *r = ((void *(*)(void *))vt[13].pfn)(e + vt[13].delta);
            if (capVu0MagnitudeSqXZ(pos, r) < 1.95999992f) {
                *(int *)(s1 + 0x330) = 0;
                *(int *)(s1 + 0x338) = 0;
            }
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x200) != 0)
            *(float *)(s1 + 0x338) = *(float *)(s1 + 0x338) * 1.5f;
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    }
    if (*(int *)(s1 + 0x15BC) > 0) {
        *(int *)(s1 + 0x15BC) = *(int *)(s1 + 0x15BC) - 1;
        func_0010A438(s1);
    }
    if (func_00123938(s1, 1) != 0)
        ClearField15F4Bit1_124F60(s1, 1, 0);
}
