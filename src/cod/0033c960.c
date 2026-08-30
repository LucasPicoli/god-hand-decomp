/* cygnus-2.96 matched TU. */

extern unsigned char D_00456888[];
extern unsigned char D_004568A8[];
extern int (*D_003E9D48)(int a0, void *a1);
extern void func_0033F1A8(void *a0, void *a1);
extern int ADX_DecodeInfoExVer(int a0, int a1, void *a2, void *a3);
extern void Obj33F8_StoreS16Trio_34_FA00(int a0, int a1, int a2, int a3);
extern int ADX_DecodeInfoExADPCM2(int a0, int a1, void *a2);
extern void Obj33F8_Thunk_0033E6B8_F988(int a0, int a1, int a2);
extern void Obj33F8_StorePair_28_2C_F9B0(int a0, void *a1, void *a2);
extern void func_0033EE30(int a0, int a1, void *a2, void *a3, void *t0, void *t1);

extern void func_0033EBD0(int a0, int a1, void *a2, void *a3, void *t0, void *t1,
                          void *t2, void *t3, void *s0);


__attribute__((section(".text.func_0033C960")))
short func_0033C960(void *a0, int a1, int a2)
{
    char *s0 = (char *)a0;
    int b10[4];
    int b20[4];
    short q[4];
    short h;
    unsigned char v;
    unsigned char ch;
    short w0, w1, w2;
    int *p = (int *)(s0 + 0x14);
    char *e;

    *(short *)(s0 + 0x2) = 1;
    if (func_0033E8A0(a1, a2, &h, s0 + 0xC, s0 + 0xD, s0 + 0xF, s0 + 0xE,
                      s0 + 0x14, s0 + 0x18, s0 + 0x10) < 0) {
        return 0;
    }
    if (*(char *)(s0 + 0xC) >= 5) {
        if (*(int *)(s0 + 0xB4) == 0) {
            func_0033F1A8(&D_00456888, &D_004568A8);
            return -1;
        }
        *(char *)(s0 + 0xD) = 8;
        *(char *)(s0 + 0xF) = *(char *)(s0 + 0xE) * 0xC0;
        *(int *)(s0 + 0x10) = 0x60;
        *(short *)(s0 + 0x98) = 0xA;
        *(short *)(s0 + 0x1C) = 0;
        *(short *)(s0 + 0x24) = 0;
        *(short *)(s0 + 0x26) = 0;
        *(int *)(s0 + 0x20) = 0;
        *(int *)(s0 + 0x28) = 0;
        *(int *)(s0 + 0x2C) = 0;
        *(int *)(s0 + 0x30) = 0;
        *(int *)(s0 + 0x34) = 0;
        *(int *)(s0 + 0x88) = 0;
        if (ADX_DecodeInfoExVer(a1, a2, &v, &ch) < 0) {
            return 0;
        }
        q[0] = 0;
        if (func_0033D090(s0, v, ch, *(int *)(s0 + 0x18), &q[1], &q[2], &q[3]) < 0) {
            return -1;
        }
        if (D_003E9D48 != 0) {
            D_003E9D48(*(int *)(s0 + 0xB4), q);
        }
    } else {
        if (ADX_DecodeInfoExVer(a1, a2, &v, &ch) < 0) {
            return 0;
        }
        if (func_0033D090(s0, v, ch, *(int *)(s0 + 0x18), &w0, &w1, &w2) < 0) {
            return -1;
        }
        e = s0 + 0x1C;
        Obj33F8_StoreS16Trio_34_FA00(*(int *)(s0 + 0x8), w0, w1, w2);
        if (ADX_DecodeInfoExADPCM2(a1, a2, e) < 0) {
            return 0;
        }
        if (func_0033EA98(a1, a2, b10, b20) < 0) {
            return 0;
        }
        Obj33F8_Thunk_0033E6B8_F988(*(int *)(s0 + 0x8), *p, *(short *)e);
        Obj33F8_StorePair_28_2C_F9B0(*(int *)(s0 + 0x8), b10, b20);
        func_0033EBD0(a1, a2, s0 + 0x20, s0 + 0x24, s0 + 0x26, s0 + 0x28,
                      s0 + 0x2C, s0 + 0x30, s0 + 0x34);
        func_0033EE30(a1, a2, s0 + 0xCC, s0 + 0xD0, s0 + 0xE0, s0 + 0xE2);
        *(short *)(s0 + 0x98) = 0;
    }
    *(int *)(s0 + 0x50) = *(char *)(s0 + 0xE);
    *(int *)(s0 + 0x54) = *(char *)(s0 + 0xF);
    *(int *)(s0 + 0x58) = *(int *)(s0 + 0x10);
    *(int *)(s0 + 0x5C) = *(int *)(s0 + 0x3C);
    *(int *)(s0 + 0x60) = *(int *)(s0 + 0x40);
    *(int *)(s0 + 0x64) = *(int *)(s0 + 0x44);
    *(int *)(s0 + 0x8C) = 0;
    return h;
}
