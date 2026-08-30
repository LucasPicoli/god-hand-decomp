/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int cCoreSave_getGameLevel(void *a0);
extern unsigned int Forward30F348_31CFE0(void);
extern int moveMotion(void *a0);
extern void func_00274FE8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_002376C0(void);
extern char D_00462FC0[];
extern char D_00569B70[];
extern char D_00568288[];
extern int D_007474A8;

extern void LookupSlotPopulateFieldsAndDispatch_1F7858(void *a0, int a1, int a2,
                                                       int a3, void *t0, void *t1,
                                                       int t2);






__attribute__((section(".text.func_002376D0")))
void func_002376D0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    *(int *)(s0 + 0x16D0) |= 0x21000;
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x20FC) + w, *(int *)(w + 0x2100) + w,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x568) = 0;
        *(short *)(s0 + 0x56E) = 0x3C;
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(short *)(s0 + 0x56A) = 0x39;
            break;
        case 2:
            *(short *)(s0 + 0x56A) = 0x3E;
            break;
        case 3:
            *(short *)(s0 + 0x56A) = 0x43;
            break;
        case 4:
            *(short *)(s0 + 0x56A) = 0x43;
            break;
        case 5:
            *(short *)(s0 + 0x56A) = 0x48;
            break;
        }
        *(short *)(s0 + 0x56C) = Forward30F348_31CFE0() & 3;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        if (moveMotion(s0)) {
            func_00274FE8(s0);
            return;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s0 + 0x56A) != 0) {
            *(short *)(s0 + 0x56A) = *(unsigned short *)(s0 + 0x56A) - 1;
        } else if (*(short *)(s1 + 0x54A) > 0 && *(short *)(s0 + 0x568) == 0) {
            switch (*(short *)(s0 + 0x56C)) {
            default:
            case 0:
                if ((D_007474A8 & 0xD0) != 0)
                    *(short *)(s0 + 0x56A) = 0;
                LookupSlotPopulateFieldsAndDispatch_1F7858(D_00568288, 0xB, 0x25,
                                                           0, func_002376C0, s0, 0);
                break;
            case 1:
                if ((D_007474A8 & 0xE0) != 0)
                    *(short *)(s0 + 0x56A) = 0;
                LookupSlotPopulateFieldsAndDispatch_1F7858(D_00568288, 0xB, 0x25,
                                                           1, func_002376C0, s0, 0);
                break;
            case 2:
                if ((D_007474A8 & 0xB0) != 0)
                    *(short *)(s0 + 0x56A) = 0;
                LookupSlotPopulateFieldsAndDispatch_1F7858(D_00568288, 0xB, 0x25,
                                                           2, func_002376C0, s0, 0);
                break;
            case 3:
                if ((D_007474A8 & 0x70) != 0)
                    *(short *)(s0 + 0x56A) = 0;
                LookupSlotPopulateFieldsAndDispatch_1F7858(D_00568288, 0xB, 0x25,
                                                           3, func_002376C0, s0, 0);
                break;
            }
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 0x10) {
            *(short *)(s0 + 0x56A) = 0x3E7;
            if (*(short *)(s0 + 0x568) == 0 || *(short *)(s1 + 0x54A) <= 0) {
                *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
                *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
            }
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            int vt = *(int *)(s0 + 0x214);
            short off = *(short *)(vt + 0xA8);
            int (*fp)() = *(int (**)())(vt + 0xAC);
            fp(s0 + off, 0x32, 0, 0, 0);
            if (*(short *)(s0 + 0x54A) <= 0)
                *(short *)(s0 + 0x54A) = 1;
        }
        break;
    case 2: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x2104) + w, *(int *)(w + 0x2108) + w,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0x3C;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(s0)) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
}
