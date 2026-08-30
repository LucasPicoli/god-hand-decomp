/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern int Obj293_IsByteSet_53D(void *a0);
extern int Obj293_IsByteSet_53C(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0014FA60(void *a0, float f12, float f13);
extern void func_00270C78(void *a0);
extern void func_00260B30(void *a0);
extern int D_00569B70;
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */





















__attribute__((section(".text.func_0022A3F8")))
void func_0022A3F8(void *a0)
{
    char *s1 = (char *)a0;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(s1);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        char *v0;
        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v0 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0xE0C) + (int)v0, *(int *)(v0 + 0xE10) + (int)v0, 0.0f, 0xA, gb, 0);
        StoreMotionParamsBoth_2609A8(s1, 5, 0x23, 0x3D, 0, 0xF0);
        *(int *)(s1 + 0x5FC) = 0;
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x104);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        void *s0;
        char *v0;
        float th;
        s0 = *(void **)(s1 + 0xF0);
        v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        th = Turn_dest(s0, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x600), *(float *)(s1 + 0x5A8) * 0.09817477f);
        *(float *)(s1 + 0x600) += th;
        *(float *)(s1 + 0x600) = Adjust_theta(*(float *)(s1 + 0x600));
        *(float *)(s1 + 0x104) += th;
        *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 2: {
        int gb;
        char *v0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v0 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0xE14) + (int)v0, *(int *)(v0 + 0xE18) + (int)v0, 0.0f, 0, gb, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(short *)(s1 + 0x568) = 5; break;
        case 2: *(short *)(s1 + 0x568) = 6; break;
        case 3: *(short *)(s1 + 0x568) = 7; break;
        case 4: *(short *)(s1 + 0x568) = 7; break;
        case 5: *(short *)(s1 + 0x568) = 8; break;
        }
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        char *g;
        if (*(float *)(s1 + 0x618) > 9.0f) {
            void *s0;
            char *v0;
            float th;
            s0 = *(void **)(s1 + 0xF0);
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            th = Turn_dest(s0, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x600), *(float *)(s1 + 0x5A8) * 0.09817477f);
            *(float *)(s1 + 0x600) += th;
            *(float *)(s1 + 0x600) = Adjust_theta(*(float *)(s1 + 0x600));
            *(float *)(s1 + 0x104) += th;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        }
        if (*(unsigned char *)(s1 + 0x1864) != 0) {
            if (*(short *)(s1 + 0x568) >= 2) {
                *(short *)(s1 + 0x568) = 1;
            }
        }
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x568) != 0) {
                *(unsigned short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
            } else {
                *(unsigned char *)(s1 + 0x2F6) = 4;
            }
        }
        g = D_005864F0;
        if (Obj293_IsByteSet_53D(g) != 0 || Obj293_IsByteSet_53C(g) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 4;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        *(int *)(s1 + 0x330) = 0;
        *(int *)(s1 + 0x334) = 0;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(float *)(s1 + 0x338) = 0.15f; break;
        case 2: *(float *)(s1 + 0x338) = 0.15f; break;
        case 3: *(float *)(s1 + 0x338) = 0.15f; break;
        case 4: *(float *)(s1 + 0x338) = 0.15f; break;
        case 5: *(float *)(s1 + 0x338) = 0.2f; break;
        }
        *(float *)(s1 + 0x338) = *(float *)(s1 + 0x338) * *(float *)(s1 + 0x5A8);
        func_0014FA60(s1, *(float *)(s1 + 0x600), 1.0f);
        break;
    }
    case 4: {
        int gb;
        char *v0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v0 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0xE1C) + (int)v0, *(int *)(v0 + 0xE20) + (int)v0, 0.0f, 0, gb, 0);
        *(int *)(s1 + 0x5F4) = 0;
        *(float *)(s1 + 0x5D0) = 99999.9f;
        *(float *)(s1 + 0x5D4) = 99999.9f;
        *(float *)(s1 + 0x5D8) = 99999.9f;
        *(int *)(s1 + 0x5B4) = 99999;
        func_0026F120(s1);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5:
        if (moveMotion(s1) != 0) {
            func_00270C78(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_00260B30(s1);
    if (*(unsigned short *)(s1 + 0x3AC) & 3) {
        *(int *)(s1 + 0x5FC) = 1;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) &= 0xFFFFFBFF;
    }
}
