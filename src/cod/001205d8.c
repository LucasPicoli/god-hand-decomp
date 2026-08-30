/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern unsigned char D_00569B70[];
extern unsigned char D_005FEE00[];
extern int D_00747A24;
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);

/* sn-2.95.3-136 matched TU. */






















__attribute__((section(".text.func_001205D8")))
void func_001205D8(void *a0)
{
    char *s1 = (char *)a0;
    char *s0;
    float buf[4] __attribute__((aligned(16)));
    float v;

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    s0 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(&D_005864F0);

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[0] = -0.1346f;
        buf[1] = 0.0f;
        buf[2] = 0.7623f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(s1, s0, buf, 0, v);
        cEm00_GetPlMotion(s0, 0x23, v, v);
        *(short *)(s1 + 0x56E) = 0x3C;
        *(int *)(s1 + 0x15B0) = 1;
        *(int *)(s1 + 0x15B4) = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 4;
            if (*(short *)(s1 + 0x54A) <= 0) {
                *(short *)(s1 + 0x54A) = 1;
            }
            ClearField15F4Bit1_124F60(s1, 0, 0);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0 && *(int *)(s1 + 0x15B4) != 0) {
            *(int *)(s1 + 0x15B4) = 0;
            if (s0 != 0) {
                func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 5.0f));
            }
            func_0012C348(s1, 2);
        } else {
            *(int *)(s1 + 0x15B4) = 1;
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 2) != 0 && *(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            if (s0 != 0) {
                func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 10.0f));
            }
            if (*(short *)(s1 + 0x54A) <= 0) {
                *(short *)(s1 + 0x54A) = 1;
                OrChildField98AndSelfFieldB0AC_2CA718(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                *(short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
            }
            func_0012C348(s1, 2);
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x200) != 0 && *(short *)(s1 + 0x54A) < 0xB) {
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        break;
    case 2:
        cEm00_GetPlMotion(s0, 0x25, 0.0f, 0.0f);
        *(short *)(s1 + 0x54A) = 0;
        func_0012C348(s1, 2);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        OrChildField98AndSelfFieldB0AC_2CA718(&D_005FEE00);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 3:
        *(short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            D_00747A24 = D_00747A24 | 8;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 4:
        ClearField15F4Bit1_124F60(s1, 1, 0);
        cEm00_GetPlMotion(s0, 0x24, 0.0f, 0.0f);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 5:
        if (moveMotion(s1) != 0) {
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}
