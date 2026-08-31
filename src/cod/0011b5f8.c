/* sn-2.95.3-136 matched TU. */

extern unsigned int Forward30F348_31CFE0(void);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_002DB770(void);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern char D_005FEE00[];
extern char D_007474A0[];

__attribute__((section(".text.func_0011B5F8")))
void func_0011B5F8(void *a0)
{
    char *s1 = (char *)a0;
    char *g;
    char *h;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int p1, p2;
        if (Forward30F348_31CFE0() & 1) {
            char *v0 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v0 + 0x148) + (int)v0;
            p2 = *(int *)(v0 + 0x14C) + (int)v0;
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xCF, s1, 0, 0, 0, 0);
        } else {
            char *v1 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v1 + 0x150) + (int)v1;
            p2 = *(int *)(v1 + 0x154) + (int)v1;
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD0, s1, 0, 0, 0, 0);
        }
        ClearField15F4Bit1_124F60(s1, 0, 0);
        func_002A8578(s1, p1, p2, 0.0f, 1, 0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x8C, s1, 0, 0, 0, 0);
        func_0012C348(s1, 0);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(short *)(s1 + 0x568) = 0xF;
        *(int *)(s1 + 0x15B0) = 0x96;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        float one;
        func_002DB770();
        g = D_007474A0;
        if (*(int *)(g + 8) & 0xF0) {
            *(int *)(s1 + 0x15B0) -= 5;
        }
        if (*(int *)(g + 8) & 0xF00000) {
            *(int *)(s1 + 0x15B0) -= 0x14;
        }
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        if (*(short *)(s1 + 0x568) != 0) {
            *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
        } else {
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    }
    case 2: {
        char *v0 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x49C) + (int)v0, *(int *)(v0 + 0x4A0) + (int)v0, 0.0f, 0xA, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        float one;
        int t;
        func_002DB770();
        moveMotion(s1);
        t = *(int *)(s1 + 0x15B0);
        h = D_007474A0;
        *(int *)(s1 + 0x15B0) = t - 1;
        if (*(int *)(h + 8) & 0xF0) {
            *(int *)(s1 + 0x15B0) = t - 6;
        }
        if (*(int *)(h + 8) & 0xF00000) {
            *(int *)(s1 + 0x15B0) -= 0x14;
        }
        if (*(int *)(s1 + 0x15B0) <= 0) {
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    }
    }
}
