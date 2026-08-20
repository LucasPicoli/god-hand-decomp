/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern char D_00569B70[];
extern char D_004365A8[];
extern char D_004365B0[];

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_00217310")))
void func_00217310(void *a0)
{
    char *s1 = (char *)a0;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        char *v0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v0 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x1D4) + (int)v0, *(int *)(v0 + 0x1D8) + (int)v0, 0.0f, 3, gb, 0);
        *(int *)(s1 + 0x5F0) = 0x1E;
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        case 1: default: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f); break;
        case 2: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f); break;
        case 3: case 4: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f); break;
        case 5: break;
        }
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x104);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (*(int *)(s1 + 0x5F0) != 0) {
            void *s0;
            char *v0;
            float th;
            *(int *)(s1 + 0x5F0) -= 1;
            s0 = *(void **)(s1 + 0xF0);
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            th = Turn_dest(s0, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x600), *(float *)(s1 + 0x5A8) * 0.39269908f);
            *(float *)(s1 + 0x600) += th;
            *(float *)(s1 + 0x600) = Adjust_theta(*(float *)(s1 + 0x600));
            *(float *)(s1 + 0x104) += th;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        }
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 1) {
        char *r;
        *(int *)(s1 + 0x16D4) &= 0xFFFFFFF7;
        r = (char *)func_0014B730(s1, D_004365A8);
        if (r != 0) {
            *(int *)(r + 0x380) &= 0xFFFFFFFE;
        }
        r = (char *)func_0014B730(s1, D_004365B0);
        if (r != 0) {
            *(int *)(r + 0x380) &= 0xFFFFFFFE;
        }
    }
}
