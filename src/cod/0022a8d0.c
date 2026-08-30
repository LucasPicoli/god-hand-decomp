/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00569B70[];
extern unsigned char D_005864F0[];
extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern void StoreMotionParams_2609E0(char *a0, int a1, int a2, int a3, int t0, short t1);
extern void Set_Fields_1884_1894_2609F8(char *a0, int a1, int a2, int a3, int t0, short t1);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern int Obj293_IsByteSet_53D(void *a0);
extern int Obj293_IsByteSet_53C(void *a0);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

/* sn-2.95.3-136 matched TU. */





















__attribute__((section(".text.func_0022A8D0")))
void func_0022A8D0(void *a0)
{
    char *s1 = (char *)a0;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) = *(int *)(s1 + 0x16D4) | 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(s1);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        int b;

        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x251C) + b, *(int *)(b + 0x2520) + b, 0.0f, 3, gb, 0);
        InitRenderStruct_2A8608(s1, 0xAA, 7, 0, 2, 0);
        StoreMotionParams_2609E0(s1, 0x28, 0x1C, 0x3E, -1, 0);
        Set_Fields_1884_1894_2609F8(s1, 0x3C, 0x1B, 0x3E, -1, 0);
        *(int *)(s1 + 0x5FC) = 0;
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x104);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 1: {
        void *e = *(void **)(s1 + 0xF0);
        float t;
        float th;

        *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x800000;
        t = Turn_dest(e, *(void **)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                      *(float *)(s1 + 0x600), *(float *)(s1 + 0x5A8) * 0.09817477f);
        th = *(float *)(s1 + 0x600) + t;
        *(float *)(s1 + 0x600) = th;
        *(float *)(s1 + 0x600) = Adjust_theta(th);
        th = *(float *)(s1 + 0x104) + t;
        *(float *)(s1 + 0x104) = th;
        *(float *)(s1 + 0x104) = Adjust_theta(th);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 2: {
        int gb;
        int b;

        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x2524) + b, *(int *)(b + 0x2528) + b, 0.0f, 0, gb, 1);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            *(short *)(s1 + 0x568) = 1;
            break;
        case 2:
            *(short *)(s1 + 0x568) = 2;
            break;
        case 3:
            *(short *)(s1 + 0x568) = 2;
            break;
        case 4:
            *(short *)(s1 + 0x568) = 2;
            break;
        case 5:
            *(short *)(s1 + 0x568) = 3;
            break;
        }
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 3: {
        void *e = *(void **)(s1 + 0xF0);
        float t;
        float th;
        char *g;

        *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x800000;
        t = Turn_dest(e, *(void **)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                      *(float *)(s1 + 0x600), *(float *)(s1 + 0x5A8) * 0.09817477f);
        th = *(float *)(s1 + 0x600) + t;
        *(float *)(s1 + 0x600) = th;
        *(float *)(s1 + 0x600) = Adjust_theta(th);
        th = *(float *)(s1 + 0x104) + t;
        *(float *)(s1 + 0x104) = th;
        *(float *)(s1 + 0x104) = Adjust_theta(th);
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x568) != 0) {
                *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
            } else {
                *(char *)(s1 + 0x2F6) = 4;
            }
        }
        g = (char *)&D_005864F0;
        if (Obj293_IsByteSet_53D(g) != 0) {
            *(char *)(s1 + 0x2F6) = 4;
        } else if (Obj293_IsByteSet_53C(g) != 0) {
            *(char *)(s1 + 0x2F6) = 4;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 4: {
        int gb;
        int b;

        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x252C) + b, *(int *)(b + 0x2530) + b, 0.0f, 0, gb, 0);
        InitRenderStruct_2A8608(s1, 0xAA, 8, 0, 2, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 5:
        *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x800000;
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_00260B30(s1);
    if ((*(unsigned short *)(s1 + 0x3AC) & 3) != 0) {
        *(int *)(s1 + 0x5FC) = 1;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) = *(int *)(s1 + 0x16D4) & 0xFFFFFBFFU;
    }
}
