/* sn-2.95.3-136 matched TU. */

extern void *GetIndexedEntry_2CC4B8(void *a0, int a1);
extern int cSeData_IsAlive(void *p);
extern void func_002CE3E8(void *a0);
extern char D_005FEE00[];
extern unsigned int D_00747A84;
extern int D_00747A78;
extern unsigned int Forward30F348_31CFE0(void);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);

__attribute__((section(".text.func_002CDA80")))
void func_002CDA80(char *s1)
{
    char buf[0x30] __attribute__((aligned(16)));
    void *e;
    char *p;
    char *q;
    int r, a, b, t;
    unsigned long tl, tu;
    long bit;
    float f;

    if (func_002CDA38(s1) == 0) {
        return;
    }
    p = D_005FEE00;
    e = GetIndexedEntry_2CC4B8(p, *(short *)(s1 + 8));
    if (cSeData_IsAlive(e) == 0) {
        goto reset;
    }
    if (*(int *)(s1 + 0x20) > 0) {
        if (D_00747A84 & 0x8000000) {
            return;
        }
        if (*(int *)(s1 + 0xC) & 0x10) {
            if (*(unsigned int *)((char *)&D_00747A84 - 0xC) & 0x8000000) {
                return;
            }
        }
        *(int *)(s1 + 0x20) = *(int *)(s1 + 0x20) - 1;
        return;
    }
    r = func_002CF218(s1, *(short *)(s1 + 8), *(short *)(s1 + 0xA), buf);
    if (r == -1) {
        goto reset;
    }
    if (*(unsigned char *)(buf + 0x20) & 0x40) {
        *(int *)(p + 0xB0) |= 0x4000000;
        *(int *)(p + 0xAC) |= 0x4000000;
    }
    if (*(char **)(s1 + 0x38) != 0 && *(float *)(*(char **)(s1 + 0x38) + 0x5A8) < 0.5f && (*(int *)(s1 + 0x1C) & 1) != 0) {
        *(int *)(s1 + 0x18) |= 0x10000;
    } else {
        *(int *)(s1 + 0x18) &= 0xFFFEFFFF;
    }
    if ((*(unsigned char *)(s1 + 0xC) ^ 1) & 1) {
        if (func_002CE588(s1, buf) == 0) {
            goto reset;
        }
        *(int *)(s1 + 0xC) |= 1;
        goto inc;
    }
    if (*(int *)(s1 + 0x18) & 0x10) {
        a = func_002CF258(s1, buf);
        b = func_002CF298(s1);
        f = (float)((a - b) / a);
        if (f < 0.0f) {
            f = 0.0f;
        }
        if (1.0f < f) {
            f = 1.0f;
        }
        q = D_005FEE00;
        *(float *)(q + 0x9C) = f;
    }
    t = func_003750E0(*(int *)(s1 + 0x14));
    switch ((unsigned int)t) {
    case 0:
        if (*(unsigned char *)(buf + 0x22) < *(int *)(s1 + 0x24)) {
            func_002CE3E8(s1);
        }
        break;
    case 1:
        break;
    case 2:
        tl = D_00747A78;
        tu = tl >> 6;
        bit = tu & 1;
        if (bit != 0) {
            return;
        }
        if (func_002CEA00(s1, buf) == 0) {
            goto reset;
        }
        break;
    }
    goto inc;
reset:
    func_002CE3E8(s1);
    return;
inc:
    *(int *)(s1 + 0x24) = *(int *)(s1 + 0x24) + 1;
}

__attribute__((section(".text.func_0011A8F8")))
void func_0011A8F8(void *a0)
{
    char *s1 = (char *)a0;
    float one;
    float f;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int p1, p2;
        switch (Forward30F348_31CFE0() % 3) {
        case 0:
        default:
            {
            char *v0 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v0 + 0x140) + (int)v0;
            p2 = *(int *)(v0 + 0x144) + (int)v0;
            }
            break;
        case 1:
            {
            char *v1 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v1 + 0x4DC) + (int)v1;
            p2 = *(int *)(v1 + 0x4E0) + (int)v1;
            }
            break;
        case 2:
            {
            char *v2 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v2 + 0x4E4) + (int)v2;
            p2 = *(int *)(v2 + 0x4E8) + (int)v2;
            }
            break;
        }
        func_002A8578(s1, p1, p2, 0.0f, 1, 0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xCE, s1, 0, 0, 0, 0);
        func_0012C348(s1, 0);
        ClearField15F4Bit1_124F60(s1, 0, 0);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(s1) != 0) {
            if (func_00123938(s1, 1) != 0) {
                return;
            }
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        f = *(float *)(s1 + 0x54C);
        break;
    default:
        f = *(float *)(s1 + 0x54C);
        break;
    }
    if (f <= 1.0f) {
        *(unsigned short *)(s1 + 0x3AC) |= 0x40;
    }
    func_00123938(s1, 1);
}
