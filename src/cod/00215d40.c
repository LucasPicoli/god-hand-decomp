/* sn-2.95.3-136 matched TU. */

extern unsigned int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int cCoreSave_getGameLevel(void *a0);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern void func_002705D8(void *a0);
extern void func_00262AA8(void *a0);
extern char D_00569B70[];

__attribute__((section(".text.func_00215D40")))
void func_00215D40(void *a0)
{
    char *s0 = (char *)a0;

    *(int *)(s0 + 0x16D0) |= 0x400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int w;
        int r;
        *(int *)(s0 + 0x17D0) = Forward30F348_31CFE0() % 5;
        r = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x1934) + w, *(int *)(w + 0x1938) + w,
                      0.0f, 0xA, r & 0xFFFF, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        AddScaledDeltaToField_104_2A7498(s0, (int)(s0 + 0x16A0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2: {
        int w;
        int r = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x193C) + w, *(int *)(w + 0x1940) + w,
                      0.0f, 0xA, r & 0xFFFF, 0);
        *(unsigned char *)(s0 + 0x2F7) = Forward30F348_31CFE0() & 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3: {
        float d;
        AddScaledDeltaToField_104_2A7498(s0, (int)(s0 + 0x16A0),
                                         *(float *)(s0 + 0x5A8) * 0.19634954f);
        moveMotion(s0);
        if (cCoreSave_getGameLevel(D_00569B70) == 5)
            *(float *)(s0 + 0x338) = *(float *)(s0 + 0x5A8) * 0.6f;
        else
            *(float *)(s0 + 0x338) = *(float *)(s0 + 0x5A8) * 0.3f;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        d = Turn_dest(*(void **)(s0 + 0xF0), s0 + 0x1690,
                      *(float *)(s0 + 0x104), 3.14159274f);
        if (d < 0.0f)
            d = -d;
        if (*(unsigned char *)(s0 + 0x2F7)) {
            if (*(float *)(s0 + 0x618) < 25.0f)
                func_002705D8(s0);
        }
        if (1.5707964f < d || *(float *)(s0 + 0x618) < 6.25f)
            func_002705D8(s0);
        break;
    }
    case 4: {
        int w;
        int r = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x1944) + w, *(int *)(w + 0x1948) + w,
                      0.0f, 0xA, r & 0xFFFF, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5:
        if (moveMotion(s0))
            func_002705D8(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
    func_00262AA8(s0);
}
