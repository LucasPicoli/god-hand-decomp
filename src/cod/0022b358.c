/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void AddScaledDeltaToField_104_2A7498(void *a0, void *a1, float f);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void func_0026A638(void *a0, int a1);
extern void func_0026A938(void *a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */











#define GRP                                                                    \
    case 0x21A:                                                                \
    case 0x21B:                                                                \
    case 0x21C:                                                                \
    case 0x21D:                                                                \
    case 0x21E:                                                                \
    case 0x225:                                                                \
    case 0x22C:                                                                \
    case 0x22D:                                                                \
    case 0x22E:                                                                \
    case 0x22F:                                                                \
    case 0x248:                                                                \
    case 0x249:                                                                \
    case 0x24C:                                                                \
    case 0x24D:                                                                \
    case 0x24E:                                                                \
    case 0x252:                                                                \
    case 0x25A

__attribute__((section(".text.func_0022B358")))
void func_0022B358(char *s0)
{
    int t0;
    int a1, a2;
    char *s1;
    unsigned int s2;

    *(char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    if (*(unsigned char *)(s0 + 0x2F6) == 0) {
        switch (*(int *)(s0 + 0x564)) {
        GRP:
            *(char *)(s0 + 0x2F6) = 2;
            break;
        }
    }
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        {
            int b = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(b + 0xDDC) + b, *(int *)(b + 0xDE0) + b,
                          0.0f, 3, t0, 0);
        }
        *(int *)(s0 + 0x5FC) = 0;
        *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        *(int *)(s0 + 0x16DC) = 0x64;
        *(int *)(s0 + 0x16E0) = 0x96;
        AddScaledDeltaToField_104_2A7498(s0, s0 + 0x16A0,
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0) != 0)
            *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
            if (*(unsigned char *)(s0 + 0x17C3) != 0)
                func_0026A638(s0, 1);
            else
                func_0026A638(s0, 0);
        }
        break;
    case 2:
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        switch (*(int *)(s0 + 0x564)) {
        default:
            {
                int b = *(int *)(s0 + 0x304);
                a1 = *(int *)(b + 0xDE4) + b;
                a2 = *(int *)(b + 0xDE8) + b;
            }
            break;
        GRP:
            {
                int b = *(int *)(s0 + 0x304);
                a1 = *(int *)(b + 0x152C) + b;
                a2 = *(int *)(b + 0x1530) + b;
            }
            break;
        }
        func_002A8578(s0, a1, a2, 0.0f, 3, t0, 0);
        *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        *(int *)(s0 + 0x16DC) = 0x64;
        *(int *)(s0 + 0x16E0) = 0x96;
        *(int *)(s0 + 0x16D0) |= 0x400;
        AddScaledDeltaToField_104_2A7498(s0, s0 + 0x16A0,
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(float *)(s0 + 0x618) < 2.25f)
            *(char *)(s0 + 0x2F6) = 4;
        break;
    case 4:
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        switch (*(int *)(s0 + 0x564)) {
        default:
            {
                int b = *(int *)(s0 + 0x304);
                a1 = *(int *)(b + 0xDEC) + b;
                a2 = *(int *)(b + 0xDF0) + b;
            }
            break;
        GRP:
            {
                int b = *(int *)(s0 + 0x304);
                a1 = *(int *)(b + 0x1534) + b;
                a2 = *(int *)(b + 0x1538) + b;
            }
            break;
        }
        func_002A8578(s0, a1, a2, 0.0f, 3, t0, 0);
        *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5:
        *(int *)(s0 + 0x16DC) = 0x64;
        *(int *)(s0 + 0x16E0) = 0x96;
        *(int *)(s0 + 0x16D0) |= 0x400;
        AddScaledDeltaToField_104_2A7498(s0, s0 + 0x16A0,
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (6.25f < *(float *)(s0 + 0x618))
            *(char *)(s0 + 0x2F6) = 2;
        break;
    }

    s2 = 0;
    s1 = s0 + 0x6E4;
    while (s2 < 2) {
        void *e = *(void **)s1;
        if (e != 0 && func_001B1A80(e) != 0) {
            func_0026A938(s0, 0, 1);
            func_0026A938(s0, 1, 1);
            break;
        }
        s1 += 4;
        s2++;
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 3) != 0)
        *(int *)(s0 + 0x5FC) = 1;
    if (*(int *)(s0 + 0x5FC) != 0)
        *(int *)(s0 + 0x16D4) &= 0xFFFFFBFFU;
}
