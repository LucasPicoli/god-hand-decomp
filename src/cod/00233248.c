/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Obj1D00_ClearState_6(void *a0);
extern void Obj1D00_ClearState_7(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern int Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(void *a0);
extern void func_00260B30(void *a0);
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */





















__attribute__((section(".text.func_00233248")))
void func_00233248(void *arg0)
{
    char *s1 = (char *)arg0;
    float fv = 0.0f;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10();
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        int a1v, a2v;
        int st;

        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        *(int *)(s1 + 0x5F4) = 0;
        *(int *)(s1 + 0x5FC) = 0;
        *(int *)(s1 + 0x5F0) = 0xF;
        *(float *)(s1 + 0x608) = 1.0f;
        StoreMotionParamsBoth_2609A8(s1, 0x14, 0, 0x37, -1, 0);
        st = *(int *)(s1 + 0x564);
        *(float *)(s1 + 0x604) = fv;
        *(float *)(s1 + 0x60C) = fv;
        if (st >= 0x250) {
            if (st < 0x252) goto lb;
            if (st == 0x260) goto lc;
        }
        {
            char *pa;
            StoreMotionParamsBoth_2609A8(s1, 0x14, 3, 0x37, -1, 0);
            pa = *(char **)(s1 + 0x304);
            a1v = *(int *)(pa + 0x390) + (int)pa;
            a2v = *(int *)(pa + 0x394) + (int)pa;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = *(char **)(s1 + 0x304);
            a2v = *(int *)(v1 + 0x398) + (int)v1;
        }
        fv = 2.0f;
        goto lmerge;
    lb:
        {
            char *pb;
            StoreMotionParamsBoth_2609A8(s1, 0x1E, 0x1B, 0x45, -1, 0);
            pb = *(char **)(s1 + 0x304);
            a1v = *(int *)(pb + 0x19E8) + (int)pb;
            a2v = *(int *)(pb + 0x19EC) + (int)pb;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = *(char **)(s1 + 0x304);
            a2v = *(int *)(v1 + 0x19F0) + (int)v1;
        }
        *(float *)(s1 + 0x604) = 20.0f;
        fv = 3.0f;
        goto lmerge;
    lc:
        {
            char *pc;
            StoreMotionParamsBoth_2609A8(s1, 0x46, 0x1B, 0x45, -1, 0);
            pc = *(char **)(s1 + 0x304);
            a1v = *(int *)(pc + 0x30D8) + (int)pc;
            a2v = *(int *)(pc + 0x30DC) + (int)pc;
        }
        *(float *)(s1 + 0x604) = 20.0f;
        fv = 3.0f;
    lmerge:
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f); break;
        case 2: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f); break;
        case 3: case 4: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f); break;
        case 5: break;
        }
        func_002A8578(s1, a1v, a2v, fv, 5, gb, 0);
        {
            void *p = *(void **)(s1 + 0x6F0);
            if (p != 0) {
                Obj1D00_ClearState_6(p);
            }
            p = *(void **)(s1 + 0x708);
            if (p != 0) {
                Obj1D00_ClearState_7(p);
            }
        }
        *(float *)(s1 + 0x54C) = 5.0f;
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x104);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (*(float *)(s1 + 0x604) > 0.0f) {
            *(int *)(s1 + 0x16D0) |= 0x800000;
            *(float *)(s1 + 0x604) -= *(float *)(s1 + 0x5A8);
        }
        if (*(int *)(s1 + 0x5F0) != 0) {
            char *tgt;
            char *o;
            float d;
            *(int *)(s1 + 0x5F0) -= 1;
            tgt = *(char **)(s1 + 0xF0);
            o = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            d = Turn_dest(tgt, *(void **)(o + 0xF0), *(float *)(s1 + 0x600),
                          *(float *)(s1 + 0x5A8) * 0.19634955f);
            *(float *)(s1 + 0x600) += d;
            *(float *)(s1 + 0x600) = Adjust_theta(*(float *)(s1 + 0x600));
            *(float *)(s1 + 0x104) += d;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        }
        if (moveMotion(s1) != 0) {
            AddScaledVecToField_100_14F9F0(s1, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
            func_002705D8(s1);
            return;
        }
        *(float *)(s1 + 0x338) = *(float *)(s1 + 0x338) * *(float *)(s1 + 0x608);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if (*(int *)(s1 + 0x564) == 0x222) {
        unsigned short fl = *(unsigned short *)(s1 + 0x3AC);
        if (fl & 2) {
            *(unsigned short *)(s1 + 0x3AC) = fl & 0xFFFD;
            *(char *)(s1 + 0x1865) = 2;
            *(float *)(s1 + 0x17D4) = 6.0f;
        }
    }
    if (*(int *)(s1 + 0x564) == 0x208) {
        void *p = *(void **)(s1 + 0x700);
        if (p != 0 && Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(p) == 0) {
            *(int *)(s1 + 0x16D0) |= 0x80000000;
        }
    }
    func_00260B30(s1);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && func_0026F1D8(s1) == 0 &&
        (*(unsigned short *)(s1 + 0x3AC) & 0x10) != 0 &&
        *(unsigned char *)(s1 + 0x1864) == 0 && func_00262AA8(s1) != 0) {
        return;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) &= 0xFFFFFBFF;
    }
}
