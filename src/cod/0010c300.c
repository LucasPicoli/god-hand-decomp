/* sn-2.95.3-136 matched TU. */

extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_0012BFB8(void *a0);

extern float D_003BD478;
extern float D_003BD480;
extern float Turn_dest_dir(float f12, float f13, float f14);
extern void CopyVec3From110To120_14A2B0(void *a0);
extern void Add_nullspeedDir(void *a0, float f12);
__attribute__((section(".text.func_0010C300")))
void func_0010C300(void *a0)
{
    char *s0 = (char *)a0;
    int t0;
    int v0;
    void *q;
    int p1;
    int p2;
    float v;
    float sp;
    if (*(short *)(s0 + 0x54A) <= 0) {
        *(short *)(s0 + 0x54A) = 1;
    }
    if (*(unsigned short *)(s0 + 0x5F2) == 3) {
        *(float *)(s0 + 0x5A8) = 1.6f;
        SetField444SignedByFlag434_158288(s0, 1.6f);
    } else {
        *(float *)(s0 + 0x5A8) = 1.3f;
        SetField444SignedByFlag434_158288(s0, 1.3f);
    }
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        if (*(char *)(s0 + 0x648) >= 0xB) {
            *(char *)(s0 + 0x648) = 0xA;
        }
        t0 = *(int *)(s0 + 0x304);
        q = *(void **)(s0 + 0x6A0);
        p1 = *(int *)(t0 + 0x58) + t0;
        p2 = *(int *)(t0 + 0x5C) + t0;
        if (q != 0) {
            func_002A8578(q, *(int *)(t0 + 0x370) + t0, *(int *)(t0 + 0x38C) + t0,
                          0.0f, 0xA, 0, 0);
            v0 = *(int *)(s0 + 0x304);
            p1 = *(int *)(v0 + 0x34C) + v0;
            p2 = *(int *)(v0 + 0x350) + v0;
        }
        func_002A8578(s0, p1, p2, 0.0f, 0xA, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        *(float *)(s0 + 0x15F0) = D_003BD480;
        if (*(int *)(s0 + 0x5D8) != 4) {
            if (*(unsigned char *)(s0 + 0x61F) != 0) {
                v = *(float *)(s0 + 0x608) - 0.52359879f;
                if (v < 0.0f) {
                    v = 0.0f;
                }
                v = v * 0.400000006f;
                if (D_003BD478 < v) {
                    v = D_003BD478;
                }
                if (*(float *)(s0 + 0x604) < 0.0f) {
                    v = -v;
                }
                *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + v;
                *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
            }
            moveMotion(s0);
            AddScaledVecToField_100_14F9F0(s0, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        } else {
            v = Turn_dest_dir(*(float *)(s0 + 0x104), *(float *)(s0 + 0x15FC), 0.39269909f);
            *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + v;
            *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
            moveMotion(s0);
            CopyVec3From110To120_14A2B0(s0);
            Add_nullspeedDir(s0, *(float *)(s0 + 0x15FC));
        }
        break;
    }
    if (*(unsigned char *)(s0 + 0x61F) != 0) {
        if (*(float *)(s0 + 0x60C) < 10000.0f) {
            *(char *)(s0 + 0x1601) = 2;
        }
    }
    if (func_00123938(s0, 0) == 0) {
        func_0012BFB8(s0);
    }
}
