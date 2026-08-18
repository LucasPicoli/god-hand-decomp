/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern int Obj293_IsByteSet_53D(void *a0);
extern int Obj293_IsByteSet_53C(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_00260B30(void *a0);
extern int D_00569B70;
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */




















__attribute__((section(".text.func_002284C8")))
void func_002284C8(void *a0)
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
        func_002A8578(s1, *(int *)(v0 + 0x1E84) + (int)v0, *(int *)(v0 + 0x1E88) + (int)v0, 0.0f, 3, gb, 0);
        *(int *)(s1 + 0x5FC) = 0;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        char *v0;
        v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s1, *(int *)(v0 + 0xF0), *(float *)(s1 + 0x5A8) * 0.19634955f);
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
        int a1v, a2v;
        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(s1, 0x14, 3, 0x37, -1, 0);
        v0 = *(char **)(s1 + 0x304);
        a1v = *(int *)(v0 + 0x1E8C) + (int)v0;
        a2v = *(int *)(v0 + 0x1E90) + (int)v0;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = *(char **)(s1 + 0x304);
            a2v = *(int *)(v1 + 0x1E94) + (int)v1;
        }
        func_002A8578(s1, a1v, a2v, 0.0f, 3, gb, 0);
        *(int *)(s1 + 0x5F0) = 0xF;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f); break;
        case 2: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f); break;
        case 3: case 4: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f); break;
        case 5: break;
        }
        *(short *)(s1 + 0x568) = 1;
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x104);
        if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
            *(short *)(s1 + 0x568) = 2;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
            *(short *)(s1 + 0x568) = 2;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) >= 5) {
            *(short *)(s1 + 0x568) = 3;
        }
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        if (*(int *)(s1 + 0x5F0) != 0) {
            void *s0;
            char *v0;
            float th;
            *(int *)(s1 + 0x5F0) -= 1;
            s0 = *(void **)(s1 + 0xF0);
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            th = Turn_dest(s0, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x600), *(float *)(s1 + 0x5A8) * 0.19634955f);
            *(float *)(s1 + 0x600) += th;
            *(float *)(s1 + 0x600) = Adjust_theta(*(float *)(s1 + 0x600));
            *(float *)(s1 + 0x104) += th;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        }
        if (moveMotion(s1) != 0) {
            char *g;
            *(int *)(s1 + 0x5F0) = 0xF;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
            case 1: default: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f); break;
            case 2: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f); break;
            case 3: case 4: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f); break;
            case 5: break;
            }
            *(float *)(s1 + 0x600) = *(float *)(s1 + 0x104);
            if (*(unsigned char *)(s1 + 0x1864) != 0) {
                *(short *)(s1 + 0x568) = 0;
            }
            *(unsigned short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
            if (*(short *)(s1 + 0x568) <= 0) {
                *(unsigned char *)(s1 + 0x2F6) = 4;
            }
            g = D_005864F0;
            if (Obj293_IsByteSet_53D(g) != 0 || Obj293_IsByteSet_53C(g) != 0) {
                *(unsigned char *)(s1 + 0x2F6) = 4;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 4: {
        int gb;
        char *v0;
        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v0 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x1E98) + (int)v0, *(int *)(v0 + 0x1E9C) + (int)v0, 0.0f, 3, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
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
