/* sn-2.95.3-136 matched TU. */

extern unsigned int Forward30F348_31CFE0(void);
extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern void Obj1D00_SetState_7_2(int a0);
extern void Obj1D00_SetState_7_A_a1(int a0, int a1);
extern void Obj1D00_SetState_7_6(int a0);
extern void Obj1D00_SetState_7_4(int a0);
extern void Obj1D00_SetState_7_8(int a0);
extern void Obj1D00_SetState_7_18(int a0);
extern void Obj1D00_ClearState_7(int a0);
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void func_002744E0(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern char D_00569B70[];
extern char D_005FEE00[];

__attribute__((section(".text.func_00234368")))
void func_00234368(void *a0)
{
    char *s0 = (char *)a0;

    *(unsigned char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    if (*(unsigned char *)(s0 + 0x2F6) == 0 && (Forward30F348_31CFE0() & 3) == 0)
        *(unsigned char *)(s0 + 0x2F6) = 8;
    CheckSlotsShort2FEAndSetByte1864_262A10(s0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int t;
        int w;
        int p;
        *(unsigned char *)(s0 + 0x1864) = 0;
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x2F24) + w, *(int *)(w + 0x2F28) + w, 0.0f, 0xA, t, 0);
        p = *(int *)(s0 + 0x708);
        if (p != 0)
            Obj1D00_SetState_7_2(p);
        *(int *)(s0 + 0x5F4) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    case 2: {
        int t;
        int lo;
        int hi;
        int r;
        *(unsigned char *)(s0 + 0x1864) = 0;
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        r = Forward30F348_31CFE0() & 1;
        *(unsigned char *)(s0 + 0x2F7) = r;
        switch ((unsigned char)r) {
        default:
        case 0: {
            int w = *(int *)(s0 + 0x304);
            int p = *(int *)(s0 + 0x708);
            lo = *(int *)(w + 0x2F4C) + w;
            hi = *(int *)(w + 0x2F50) + w;
            if (p != 0)
                Obj1D00_SetState_7_6(p);
            break;
        }
        case 1: {
            int w = *(int *)(s0 + 0x304);
            lo = *(int *)(w + 0x2F54) + w;
            hi = *(int *)(w + 0x2F58) + w;
            if (cCoreSave_getGameLevel(D_00569B70) == 5) {
                int p = *(int *)(s0 + 0x708);
                int w2 = *(int *)(s0 + 0x304);
                hi = *(int *)(w2 + 0x2F5C) + w2;
                if (p != 0)
                    Obj1D00_SetState_7_A_a1(p, 1);
            } else {
                int p = *(int *)(s0 + 0x708);
                if (p != 0)
                    Obj1D00_SetState_7_A_a1(p, 0);
            }
            break;
        }
        }
        func_002A8578(s0, lo, hi, 0.0f, 3, t, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3: {
        unsigned short fl;
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0)) {
            if (36.0f < *(float *)(s0 + 0x618))
                *(unsigned char *)(s0 + 0x2F6) = 6;
            else
                *(unsigned char *)(s0 + 0x2F6) = 4;
            if (cCoreSave_getGameLevel(D_00569B70) >= 2 &&
                (Forward30F348_31CFE0() & 1))
                *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        fl = *(unsigned short *)(s0 + 0x3AC);
        if ((fl & 3) == 0)
            goto set5F4;
        if (*(int *)(s0 + 0x5F4) != 0) {
            *(int *)(s0 + 0x5F4) = 0;
            switch (*(unsigned char *)(s0 + 0x2F7)) {
            default:
            case 0:
                if ((fl & 2) != 0)
                    goto call13;
                goto call0D;
            case 1:
                goto call13;
            }
        }
        break;
    }
    case 4: {
        int t;
        int w;
        int p;
        *(unsigned char *)(s0 + 0x1864) = 0;
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x2F2C) + w, *(int *)(w + 0x2F30) + w, 0.0f, 3, t, 0);
        p = *(int *)(s0 + 0x708);
        if (p != 0)
            Obj1D00_SetState_7_4(p);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5:
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0)) {
            int p;
            AddScaledVecToField_100_14F9F0(s0, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
            func_002705D8(s0);
            p = *(int *)(s0 + 0x708);
            if (p != 0)
                Obj1D00_ClearState_7(p);
        } else {
            AddScaledVecToField_100_14F9F0(s0, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        }
        break;
    case 6: {
        int t;
        int w;
        int p;
        *(unsigned char *)(s0 + 0x1864) = 0;
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x2F9C) + w, *(int *)(w + 0x2FA0) + w, 0.0f, 3, t, 0);
        p = *(int *)(s0 + 0x708);
        if (p != 0)
            Obj1D00_SetState_7_8(p);
        *(int *)(s0 + 0x5F0) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 7:
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = 4;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 3) && *(int *)(s0 + 0x5F0) != 0) {
            *(int *)(s0 + 0x5F0) = 0;
            func_002744E0(s0);
        }
        break;
    case 8: {
        int t;
        int w;
        int p;
        *(unsigned char *)(s0 + 0x1864) = 0;
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x2F40) + w, *(int *)(w + 0x2F44) + w, 0.0f, 0xA, t, 0);
        p = *(int *)(s0 + 0x708);
        if (p != 0)
            Obj1D00_SetState_7_18(p);
        *(int *)(s0 + 0x5F4) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 9:
        AddScaledDeltaToField_104_2A7498(s0,
                                         *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0)) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 3) == 0)
            goto set5F4;
        if (*(int *)(s0 + 0x5F4) != 0) {
            *(int *)(s0 + 0x5F4) = 0;
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x25, s0, 0, 0, 0, 0);
            if (*(unsigned short *)(s0 + 0x3AC) & 2) {
            call13:
                func_0026BEF0(s0, 0x13, 0);
                func_0026BEF0(s0, 0x13, 1);
                func_0026BEF0(s0, 0x13, 2);
                func_0026BEF0(s0, 0x13, 3);
                func_0026BEF0(s0, 0x13, 4);
            } else {
            call0D:
                func_0026BEF0(s0, 0xD, 0);
            }
        }
        break;
    }
    return;
set5F4:
    *(int *)(s0 + 0x5F4) = 1;
}
