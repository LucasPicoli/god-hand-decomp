/* cygnus-2.96 matched TU. */

extern void (*D_003D90D4)(int a0, int a1, int a2);
extern int D_003D90D8;
extern void Obj3290_Tramp_0033E6A8_9070(void);
extern int Obj3290_Tramp_0033E6B0_9088(void);
extern void NoOp_33E6A8(void);
extern int NoOp_33E6B0(void);

__attribute__((section(".text.func_00332808")))
void func_00332808(int a0, int a1) {
    if (D_003D90D4 != 0) {
        D_003D90D4(D_003D90D8, a1, a0);
    }
}

__attribute__((section(".text.func_00327E18")))
int func_00327E18(int a0, int a1, int a2, int a3, int a4) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00327E88(a0, a1, a2, a3, a4);
    return Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_00327FA8")))
int func_00327FA8(int a0) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00327FD8(a0);
    return Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_003282D0")))
int func_003282D0(int a0) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00328300(a0);
    return Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_003283E8")))
int func_003283E8(int a0, int a1, int a2) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00328438(a0, a1, a2);
    return Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_003298C0")))
void func_003298C0(int a0) {
    NoOp_33E6A8();
    adxPly_destroy(a0);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_0032B188")))
void func_0032B188(int a0, int a1) {
    NoOp_33E6A8();
    func_0032B1C8(a0, a1);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_0034CA30")))
int func_0034CA30(int *a0, int a1) {
    int off;
    if (a1 == 8) return 0;
    off = a1 * 116;
    return *(int*)((char*)a0 + (off + 0x1318));
}

__attribute__((section(".text.func_0034CA98")))
int func_0034CA98(int *a0, int a1) {
    int off;
    if (a1 == 8) return 1;
    off = a1 * 116;
    return *(int*)((char*)a0 + (off + 0x131C));
}

__attribute__((section(".text.func_00366C50")))
void func_00366C50(int *a0, int a1, unsigned int a2) {
    int *p = a0 + a2;
    unsigned int rem = a2 & 0xF;
    if (rem != 0) {
        do {
            *--p = a1;
        } while (--rem != 0);
    }
    a2 >>= 4;
    if (a2 != 0) {
        do {
            *--p = a1; *--p = a1; *--p = a1; *--p = a1;
            *--p = a1; *--p = a1; *--p = a1; *--p = a1;
            *--p = a1; *--p = a1; *--p = a1; *--p = a1;
            *--p = a1; *--p = a1; *--p = a1; *--p = a1;
        } while (--a2 != 0);
    }
}

__attribute__((section(".text.func_00373A58")))
int func_00373A58(int *a0) {
    int v = *(int*)((char*)a0 + 0x4C) & 2;
    return v != 0;
}

__attribute__((section(".text.func_0037D148")))
void func_0037D148(void *a0) {
    void *p = *(void**)((char*)a0 + 0x8);
    if (p) {
        *(short*)((char*)p + 0x0) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 0x14) = 0;
        *(int*)((char*)p + 0x8) = 0;
    }
}

__attribute__((section(".text.func_0037D3B0")))
void func_0037D3B0(void *a0) {
    *(short*)((char*)a0 + 0x0) = 0;
    *(int*)((char*)a0 + 0x10) = 0;
    *(int*)((char*)a0 + 0x14) = 0;
    *(int*)((char*)a0 + 0x8) = 0;
}
