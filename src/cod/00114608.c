/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005FEE00[];
extern unsigned char D_005864F0[];
extern unsigned char D_00569B70[];
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00124EC0(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f12);
extern void func_0012CC70(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void SetField548AndGlobals_292F38(void *a0, float f12);
extern void SetField444SignedByFlag434_158288(void *a0, float f12);
extern int cCoreSave_getCostumeNo(void *a0);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned int t1);
extern void func_00126770(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void FreeFieldObject_1267F8(void *a0);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

__attribute__((section(".text.func_00114608")))
void func_00114608(void *a0)
{
    char *s1 = (char *)a0;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int s2;
        char *e;
        int p1;
        int p2;
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        func_00124540(s1, 3);
        if (*(int *)(s1 + 0x640) != 0)
            func_00124EC0(s1);
        e = *(char **)(s1 + 0x640);
        s2 = 0;
        if (e != 0) {
            char *vt = *(char **)(e + 0x214);
            char *p = *(char **)(s1 + 0xF0);
            int off = *(short *)(vt + 0x68);
            int (*fp)() = *(int (**)())(vt + 0x6C);
            int r = fp(e + off);
            if (64.0f < capVu0MagnitudeSqXZ(p, (void *)r))
                s2 = 1;
        }
        if (s2 != 0) {
            int w1 = *(int *)(s1 + 0x304);
            p1 = *(int *)(w1 + 0x228) + w1;
            p2 = *(int *)(w1 + 0x22C) + w1;
        } else {
            int w2 = *(int *)(s1 + 0x304);
            p1 = *(int *)(w2 + 0x220) + w2;
            p2 = *(int *)(w2 + 0x224) + w2;
        }
        func_002A8578(s1, p1, p2, 0.0f, 3, 0, 0);
        *(int *)(s1 + 0x15B0) = 0x66;
        *(int *)(s1 + 0x15BC) = *(int *)(s1 + 0x15B4) = 1;
        *(short *)(s1 + 0x568) = 5;
        *(int *)(s1 + 0x15B8) = 0;
        *(int *)(s1 + 0x165C) = 0;
        *(int *)(s1 + 0x161C) = 0;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        InvokeVirtualAtField214AndForward_124E68(s1, 0.19634954f);
        if (*(int *)(s1 + 0x640) != 0) {
            *(unsigned char *)(s1 + 0x648) = 0x14;
            func_0012CC70(s1);
            *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x800000;
        }
        if (*(unsigned short *)(s1 + 0x3AC) & 0x100) {
            if (*(int *)(s1 + 0x15B4) != 0) {
                if (*(int *)(s1 + 0x165C) == 0)
                    *(int *)(s1 + 0x165C) = func_00125048(s1);
                if (*(int *)(s1 + 0x15B0) != 0) {
                    *(int *)(s1 + 0x15B0) = *(int *)(s1 + 0x15B0) - 1;
                    if (*(int *)(s1 + 0x161C) == 0)
                        *(int *)(s1 + 0x161C) =
                            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 4, s1, 0, 0, 0, 0);
                    SetField548AndGlobals_292F38(&D_005864F0, 0.03f);
                    *(float *)(s1 + 0x5A8) = 0.03f;
                    SetField444SignedByFlag434_158288(s1, 0.03f);
                    {
                        char *g = (char *)&D_005FEE00;
                        *(int *)(g + 0xB0) = *(int *)(g + 0xB0) | 0x400000;
                        *(int *)(g + 0xAC) = *(int *)(g + 0xAC) | 0x400000;
                    }
                    if (*(int *)(s1 + 0x15BC) != 0) {
                        *(int *)(s1 + 0x15BC) = 0;
                        if (*(int *)(s1 + 0x15F4) & 0x20) {
                            switch (cCoreSave_getCostumeNo(&D_00569B70)) {
                            default:
                            case 0:
                            case 2:
                            case 4:
                            case 6:
                                SetEffect(0, 0xE, s1, 0, -1, 0xFFFFFFFFU);
                                break;
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                                break;
                            }
                        }
                    }
                }
            }
            if (*(unsigned short *)(s1 + 0x3AC) & 0x100) {
                if (*(short *)(s1 + 0x568) != 0) {
                    *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
                } else if (*(signed char *)(s1 + 0x626) != 0 &&
                           *(int *)(s1 + 0x15B8) == 0) {
                    *(unsigned char *)(s1 + 0x626) = 0;
                    *(unsigned char *)(s1 + 0x621) = 0;
                    *(unsigned char *)(s1 + 0x622) = 0;
                    *(unsigned char *)(s1 + 0x623) = 0;
                    *(int *)(s1 + 0x15B8) = 1;
                    func_00126770(s1);
                    ClearField15F4Bit1_124F60(s1, 1, 0);
                    *(unsigned char *)(s1 + 0x2F6) = 2;
                }
            }
        }
        if (*(int *)(s1 + 0x15B0) == 0 && *(int *)(s1 + 0x15B8) == 0)
            FreeFieldObject_1267F8(s1);
        if (moveMotion(s1)) {
            ClearField15F4Bit1_124F60(s1, 1, 0);
            func_00126770(s1);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (*(unsigned short *)(s1 + 0x3AC) & 0x100) {
            *(short *)(s1 + 0x3AC) = *(unsigned short *)(s1 + 0x3AC) | 0x800;
            *(float *)(s1 + 0x674) = 0.05f;
        }
        break;
    case 2: {
        int w = *(int *)(s1 + 0x304);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_002A8578(s1, *(int *)(w + 0x220) + w, *(int *)(w + 0x224) + w,
                      21.0f, 0xA, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(s1)) {
            func_00126770(s1);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    default:
        break;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 0x10)
        *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x400000;
    if (func_00123938(s1, 1)) {
        func_00126770(s1);
        ClearField15F4Bit1_124F60(s1, 1, 0);
    }
}
