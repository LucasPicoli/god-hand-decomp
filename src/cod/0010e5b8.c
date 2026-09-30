/* sn-2.95.3-136 matched TU. */

extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f, int a4, int a5);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int  moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern float capVu0MagnitudeXZ(void *a0, void *a1);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0010A438(void *a0);

extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void SetField444SignedByFlag434_158288(void *a0, float f12);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void cSnd_SeStop(void *a0, int a1);
extern void KillEffect(void *a0, int a1, int a2);
extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_007474A0;

struct VtEnt { short delta; short index; void *pfn; };

static __inline__ long inrange(unsigned short k, int lo, int hi)
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

__attribute__((section(".text.func_0010E5B8")))
void func_0010E5B8(void *a0)
{
    char *s1 = (char *)a0;
    int one = 1;

    if (*(short *)(s1 + 0x54A) <= 0)
        *(short *)(s1 + 0x54A) = one;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        char *e;
        char *e2;
        int t;

        func_00124540(s1, 0);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        if (*(signed char *)(s1 + 0x648) > 0)
            *(char *)(s1 + 0x648) = 0x2D;
        e = *(char **)(s1 + 0x640);
        if (e != 0) {
            if (inrange(*(unsigned short *)(e + 0x2FE), 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(D_00569B70, 0x14);
        }
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, (int)(*(float *)(s1 + 0x600) * 10.0f), 8, 0x13, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, (int)(*(float *)(s1 + 0x600) * 10.0f), 8, 0x13, 0, 0xA);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x18C) + t, *(int *)(t + 0x194) + t, 5, 0.0f, 0, 0);
        *(float *)(s1 + 0x15C0) = 1.0f;
        *(float *)(s1 + 0x15C4) = 0.0f;
        *(int *)(s1 + 0x15B0) = 1;
        *(int *)(s1 + 0x15B8) = 1;
        *(float *)(s1 + 0x1588) = 0.0f;
        *(int *)(s1 + 0x15B4) = 0;
        e2 = *(char **)(s1 + 0x640);
        if (e2 != 0) {
            struct VtEnt *vt = *(struct VtEnt **)(e2 + 0x214);
            float *pos = *(float **)(s1 + 0xF0);
            void *r = ((void *(*)(void *))vt[13].pfn)(e2 + vt[13].delta);
            float d = capVu0MagnitudeXZ(pos, r) - 1.20000005f;
            if (*(unsigned short *)(s1 + 0x5E0) == 0 && *(unsigned char *)(s1 + 0x61F) != 0) {
                if (1.0f < d) d = 1.0f;
            } else {
                if (0.5f < d) d = 0.5f;
            }
            if (0.0f < d)
                *(float *)(s1 + 0x1588) = d * 0.150000006f;
        }
        *(short *)(s1 + 0x5F0) = 0xA;
        *(short *)(s1 + 0x568) = 0x32;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
    {
        if (*(short *)(s1 + 0x568) != 0) {
            *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
            InvokeVirtualAtField214AndForward_124E68(s1, 0.196349546f);
        }
        if (*(int *)(s1 + 0x640) != 0)
            *(char *)(s1 + 0x648) = 0x14;
        *(float *)(s1 + 0x5A8) = 1.0f;
        *(float *)(s1 + 0x5DC) = 1.0f;
        if (*(unsigned short *)(s1 + 0x3AC) & 0x80) {
            if (*(int *)(s1 + 0x15B0) != 0) {
                if (*(float *)(s1 + 0x15C4) <= 0.0f)
                    *(float *)(s1 + 0x15C4) = 1.0f;
            }
        }
        if (*(float *)(s1 + 0x15C4) > 0.0f && *(int *)(s1 + 0x15B0) != 0) {
            if (*(int *)(s1 + 0x15B4) == 0) {
                *(int *)(s1 + 0x15B4) = 1;
                InitRenderStruct_2A8608(s1, 0, 0x31, 2, 2, 0);
            }
            if ((D_007474A0 & 0xD0) != 0) {
                float sp = 0.0250000004f;
                *(float *)(s1 + 0x5A8) = sp;
                *(float *)(s1 + 0x5DC) = sp;
                *(float *)(s1 + 0x15C4) = *(float *)(s1 + 0x15C4) - sp;
                SetField444SignedByFlag434_158288(s1, sp);
                *(float *)(s1 + 0x15C0) = *(float *)(s1 + 0x15C0) + 0.0500000007f;
                if (*(float *)(s1 + 0x15C4) <= 0.0f)
                    *(float *)(s1 + 0x15C0) = *(float *)(s1 + 0x15C0) + 1.0f;
                if (*(float *)(s1 + 0x15C0) >= 1.10000002f) {
                    if (*(int *)(s1 + 0x15B8) != 0) {
                        *(int *)(s1 + 0x15B8) = 0;
                        *(int *)(s1 + 0x1620) = cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x11B, s1, 0, 0, 0, 0);
                    }
                }
            } else {
                *(float *)(s1 + 0x15C4) = 0.0f;
                *(int *)(s1 + 0x15B0) = 0;
            }
            if (*(float *)(s1 + 0x15C4) <= 0.0f)
                *(int *)(s1 + 0x15B0) = 0;
        } else {
            if (*(unsigned short *)(s1 + 0x3AC) & 3)
                KillEffect(Obj0000_Get_D_00747A94_2DB6B0(), 2, 2);
            if (*(int *)(s1 + 0x15B4) != 0) {
                *(int *)(s1 + 0x15B4) = 0;
                if (*(float *)(s1 + 0x15C0) >= 2.5f) {
                    KillEffect(Obj0000_Get_D_00747A94_2DB6B0(), 2, 2);
                    SetEffect(0, 0x32, s1, 0, -1, 0xFFFFFFFFu);
                }
                cSnd_SeStop(D_005FEE00, *(int *)(s1 + 0x1620));
                *(int *)(s1 + 0x1620) = 0;
            }
        }
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        {
            char *e = *(char **)(s1 + 0x640);
            if (e != 0) {
                struct VtEnt *vt = *(struct VtEnt **)(e + 0x214);
                float *pos = *(float **)(s1 + 0xF0);
                void *r = ((void *(*)(void *))vt[13].pfn)(e + vt[13].delta);
                if (capVu0MagnitudeSqXZ(pos, r) < 1.21000004f) {
                    *(int *)(s1 + 0x330) = 0;
                    *(int *)(s1 + 0x338) = 0;
                }
            }
        }
        *(float *)(s1 + 0x338) = *(float *)(s1 + 0x338) + *(float *)(s1 + 0x1588);
        *(float *)(s1 + 0x1588) = *(float *)(s1 + 0x1588) * 0.899999976f;
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    }
    *(float *)(s1 + 0x1610) = *(float *)(s1 + 0x15C0);
    if (2.5f < *(float *)(s1 + 0x15C0)) {
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x10, 8, 0x14, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x10, 8, 0x14, 0, 0xA);
    }
    func_0010A438(s1);
    if (*(unsigned short *)(s1 + 0x3AC) & 0x10) {
        if (*(short *)(s1 + 0x5F0) != 0) {
            *(short *)(s1 + 0x5F0) = *(unsigned short *)(s1 + 0x5F0) - 1;
            *(int *)(s1 + 0x15F4) |= 0x20000;
        } else {
            *(short *)(s1 + 0x5E0) = 0;
            *(short *)(s1 + 0x5E2) = 0;
        }
    }
    if (func_00123938(s1, 1) != 0)
        ClearField15F4Bit1_124F60(s1, 1, 0);
}
