/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern int Forward30F348_31CFE0(void);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_00260B30(void *a0);
extern int D_00569B70;

/* sn-2.95.3-136 candidate TU. */

















__attribute__((section(".text.func_00233738")))
void func_00233738(void *a0)
{
    char *s1 = (char *)a0;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10();
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        int a1v, a2v;
        char *p;
        char *q;

        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        p = *(char **)(s1 + 0x304);
        q = *(char **)(s1 + 0x6EC);
        a1v = *(int *)(p + 0x4A4) + (int)p;
        *(int *)(s1 + 0x5F0) = 0x14;
        if (q != 0) {
            if (*(unsigned short *)(q + 0x2FE) == 0x368) {
                a1v = *(int *)(p + 0x498) + (int)p;
                a2v = *(int *)(p + 0x49C) + (int)p;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    char *v1 = *(char **)(s1 + 0x304);
                    a2v = *(int *)(v1 + 0x4A0) + (int)v1;
                }
                func_002A8578(s1, a1v, a2v, 0.0f, 3, gb, 0);
                *(int *)(s1 + 0x5F0) = 0x14;
                StoreMotionParamsBoth_2609A8(s1, 0x3C, 0x13, 0x3B, 0, 0x111);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    InitRenderStruct_2A8608(s1, 0x58, 0x7E, 0, 2, *(int *)(s1 + 0x6EC));
                } else {
                    InitRenderStruct_2A8608(s1, 0x58, 0x79, 0, 2, *(int *)(s1 + 0x6EC));
                }
            } else if ((Forward30F348_31CFE0() & 1) != 0 ||
                       *(unsigned char *)(s1 + 0x2F7) != 0) {
                char *pb = *(char **)(s1 + 0x304);
                int m, k;
                a2v = *(int *)(pb + 0x4A8) + (int)pb;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    char *v1 = *(char **)(s1 + 0x304);
                    a2v = *(int *)(v1 + 0x4A8) + (int)v1;
                }
                func_002A8578(s1, a1v, a2v, 0.0f, 3, gb, 0);
                *(int *)(s1 + 0x5F0) = 0x14;
                if (*(unsigned char *)(s1 + 0x2F7) != 0) {
                    *(int *)(s1 + 0x5F0) = 0xA;
                }
                m = *(unsigned short *)(*(char **)(s1 + 0x6EC) + 0x2FE);
                if (m == 0x368) goto bd;
                if (m < 0x369) {
                    if (m == 0x362) goto b141;
                    if (m < 0x363) goto bd;
                    k = 0x363;
                    goto bcmp;
                }
                if (m == 0x380) goto bea;
                if (m < 0x381) {
                    if (m == 0x379) goto b112;
                    goto bd;
                }
                k = 0x3B7;
            bcmp:
                if (m == k) goto b142;
                goto bd;
            b141:
                StoreMotionParamsBoth_2609A8(s1, 0x28, 0x12, 0x3A, 0, 0x141);
                goto bend;
            bd:
                StoreMotionParamsBoth_2609A8(s1, 0x28, 0x12, 0x3A, 0, 0x140);
                goto bend;
            b142:
                StoreMotionParamsBoth_2609A8(s1, 0x28, 0x12, 0x3A, 0, 0x142);
                goto bend;
            bea:
                StoreMotionParamsBoth_2609A8(s1, 0x5, 0x12, 0x3A, 0, 0xEA);
                goto bend;
            b112:
                StoreMotionParamsBoth_2609A8(s1, 0x28, 0x12, 0x38, 0, 0x112);
            bend:
                ;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    InitRenderStruct_2A8608(s1, 0x58, 0x7F, 0, 2, *(int *)(s1 + 0x6EC));
                } else {
                    InitRenderStruct_2A8608(s1, 0x58, 0x7A, 0, 2, *(int *)(s1 + 0x6EC));
                }
            } else {
                char *pc = *(char **)(s1 + 0x304);
                int m, k;
                a1v = *(int *)(pc + 0x474) + (int)pc;
                a2v = *(int *)(pc + 0x478) + (int)pc;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    char *v1 = *(char **)(s1 + 0x304);
                    a2v = *(int *)(v1 + 0x478) + (int)v1;
                }
                func_002A8578(s1, a1v, a2v, 0.0f, 3, gb, 0);
                *(int *)(s1 + 0x5F0) = 0x14;
                m = *(unsigned short *)(*(char **)(s1 + 0x6EC) + 0x2FE);
                if (m == 0x368) goto cd;
                if (m < 0x369) {
                    if (m == 0x362) goto c141;
                    if (m < 0x363) goto cd;
                    k = 0x363;
                    goto ccmp;
                }
                if (m == 0x380) goto cea;
                if (m < 0x381) {
                    if (m == 0x379) goto c112;
                    goto cd;
                }
                k = 0x3B7;
            ccmp:
                if (m == k) goto c142;
                goto cd;
            c141:
                StoreMotionParamsBoth_2609A8(s1, 0x3C, 0x12, 0x3B, 0, 0x141);
                goto cend;
            cd:
                StoreMotionParamsBoth_2609A8(s1, 0x3C, 0x12, 0x3B, 0, 0x140);
                goto cend;
            c142:
                StoreMotionParamsBoth_2609A8(s1, 0x3C, 0x12, 0x3B, 0, 0x142);
                goto cend;
            cea:
                StoreMotionParamsBoth_2609A8(s1, 0xA, 0x12, 0x3B, 0, 0xEA);
                goto cend;
            c112:
                StoreMotionParamsBoth_2609A8(s1, 0x3C, 0x12, 0x39, 0, 0x112);
            cend:
                ;
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    InitRenderStruct_2A8608(s1, 0x58, 0x80, 0, 2, *(int *)(s1 + 0x6EC));
                } else {
                    InitRenderStruct_2A8608(s1, 0x58, 0x7B, 0, 2, *(int *)(s1 + 0x6EC));
                }
            }
        }
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f); break;
        case 2: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f); break;
        case 3: case 4: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f); break;
        case 5: break;
        }
        if (*(unsigned char *)(s1 + 0x2F7) != 0) {
            *(int *)(s1 + 0x5F0) = 0xA;
        }
        *(int *)(s1 + 0x5FC) = 0;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (*(int *)(s1 + 0x5F0) != 0) {
            char *v0;
            *(int *)(s1 + 0x5F0) -= 1;
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s1, *(int *)(v0 + 0xF0),
                                             *(float *)(s1 + 0x5A8) * 0.19634955f);
        }
        if (moveMotion(s1) != 0) {
            AddScaledVecToField_100_14F9F0(s1, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
            func_002705D8(s1);
            return;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_00260B30(s1);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && func_0026F1D8(s1) == 0 &&
        (*(unsigned short *)(s1 + 0x3AC) & 0x10) != 0 &&
        *(unsigned char *)(s1 + 0x1864) == 0 && func_00262AA8(s1) != 0) {
        return;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 3) {
        *(int *)(s1 + 0x5FC) = 1;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) &= 0xFFFFFBFF;
    }
}
