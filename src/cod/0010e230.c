/* sn-2.95.3-136 matched TU. */

/* L1 w34 parked: 216/225 EXACT, insn delta -1, needs --assembler sn (ps2eeas supplies the mtc1 nop at .L0010E2EC). Residue: flag copy daddu $a0,$v0 (R allocated $v0 here), beqzl for beqz at 0x0010E334 (follows the flag register), mov.s $f12 placement before the func_002A8578 call. Edits this wave: int one = 1 hoisted, extern int func_00124540, stores 15C4/15B0 first. */
/* func_0010E230 — 0x0010E230, 900 B — sn-2.95.3-136. */

extern float capVu0MagnitudeXZ(void *a0, void *a1);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern int func_00124540(void *a0, int a1);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, int a4, float a3, int a5, int a6);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int  moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_0010A438(void *a0);

extern int  D_00569B70;

static __inline__ long InMidRange(unsigned short k, int lo, int hi)
{
    long c;
    int t;
    c = 0;
    if (k >= lo) {
        t = (k < hi);
        c = t;
    }
    return c;
}

__attribute__((section(".text.func_0010E230")))
void func_0010E230(void *a0)
{
    char *s1 = (char *)a0;
    int one = 1;

    *(int *)(s1 + 0x15F4) |= 0x40000;
    if (*(short *)(s1 + 0x54A) <= 0)
        *(short *)(s1 + 0x54A) = one;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        char *o;
        int w;


        o = *(char **)(s1 + 0x640);
        *(int *)(s1 + 0x1588) = 0;
        if (o != 0) {
            char *vt;
            int (*fp)();
            char *p;
            float d;
            float lim;

            vt = *(char **)(o + 0x214);
            p = *(char **)(s1 + 0xF0);
            fp = *(int (**)())(vt + 0x6C);
            d = capVu0MagnitudeXZ(p, (void *)fp(o + *(short *)(vt + 0x68)));
            d = d - 1.2f;
            lim = 0.5f;
            if (*(unsigned short *)(s1 + 0x5E0) == 0
                && *(unsigned char *)(s1 + 0x61F) != 0)
                lim = 1.0f;
            if (lim < d)
                d = lim;
            if (0.0f < d)
                *(float *)(s1 + 0x1588) = d * 0.2f;
        if (*(char **)(s1 + 0x640) != 0) {
            unsigned short k = *(unsigned short *)(*(char **)(s1 + 0x640) + 0x2FE);
            if (InMidRange(k, 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(&D_00569B70, 0x14);
        }
        }
        func_00124540(s1, 0);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        if (*(char *)(s1 + 0x648) > 0)
            *(char *)(s1 + 0x648) = 0x2D;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1,
            (int)(*(float *)(s1 + 0x600) * 8.0f), 2, 0x18, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1,
            (int)(*(float *)(s1 + 0x600) * 8.0f), 2, 0x18, 0, 0xA);
        w = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(w + 0x1AC) + w, *(int *)(w + 0x1B4) + w,
                      3, 0.0f, 0, 0);
        *(float *)(s1 + 0x15C4) = 0.0f;
        *(int *)(s1 + 0x15B0) = 1;
        *(float *)(s1 + 0x15C0) = 1.0f;
        *(int *)(s1 + 0x15B8) = 1;
        *(float *)(s1 + 0x1588) = 0.0f;
        *(short *)(s1 + 0x568) = 0x32;
        *(char *)(s1 + 0x1603) = 2;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        *(int *)(s1 + 0x15B4) = 0;
    }
    /* fallthrough */
    case 1: {
        char *o;
        float acc;

        if (*(short *)(s1 + 0x568) != 0) {
            *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
            InvokeVirtualAtField214AndForward_124E68(s1, 0.19634954f);
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x10) == 0)
            *(char *)(s1 + 0x1603) = 2;
        if (*(int *)(s1 + 0x640) != 0)
            *(char *)(s1 + 0x648) = 0x14;
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        o = *(char **)(s1 + 0x640);
        if (o != 0) {
            char *vt;
            int (*fp)();
            char *p;

            vt = *(char **)(o + 0x214);
            p = *(char **)(s1 + 0xF0);
            fp = *(int (**)())(vt + 0x6C);
            if (capVu0MagnitudeSqXZ(p, (void *)fp(o + *(short *)(vt + 0x68))) < 1.21f) {
                *(int *)(s1 + 0x330) = 0;
                *(int *)(s1 + 0x338) = 0;
            }
        }
        acc = *(float *)(s1 + 0x1588);
        *(float *)(s1 + 0x338) = *(float *)(s1 + 0x338) + acc;
        *(float *)(s1 + 0x1588) = acc * 0.9f;
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    default:
        break;
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1) != 0)
        ClearField15F4Bit1_124F60(s1, 1, 0);
}
