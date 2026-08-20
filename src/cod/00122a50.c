/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void MaxField514_292030(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern char D_005864F0[];
extern char D_00462FC0[];

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_00122A50")))
void func_00122A50(void *a0) {
    char *s1 = (char *)a0;
    char *o;
    float *d;
    float *s;
    float one;

    *(float *)(s1 + 0x54C) = 5.0f;
    o = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    MaxField514_292030(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x80000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        if (o != 0) {
            d = *(float **)(o + 0xF0);
            s = *(float **)(s1 + 0xF0);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            *(float *)(o + 0x104) = *(float *)(s1 + 0x104);
        }
        cEm00_GetPlMotion(o, 0x54, 0.0f, 0.0f);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    case 2:
        cEm00_GetPlMotion(o, 0x55, 0.0f, 0.0f);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 3:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    case 4:
        cEm00_GetPlMotion(o, 0x56, 0.0f, 0.0f);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 5:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    case 6:
        cEm00_GetPlMotion(o, 0x57, 0.0f, 0.0f);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 7:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    }
}
