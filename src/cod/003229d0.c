/* cygnus-2.96 matched TU. */

extern void Forward33E6A8_324880(void);
extern void Forward33E6B0_324898(void);
extern int Forward322BD8_322AD0(int a0, int a1, int a2, int a3);
extern int Forward322C18_322B60(int a0, int a1, int a2, int a3);
extern void Obj33F8_NoOp_FCA0(void);
extern void Obj33F8_NoOp_FCA8(void);
extern void Forward33B658_3389F8(void);
extern void Forward33B670_338A10(void);
extern void Forward33B568_33B658(void);
extern void Forward33B5C8_33B670(void);
extern int MPSLIB_CheckHn(void *);
extern int MPSLIB_SetErr(int, unsigned int);

__attribute__((section(".text.func_003229D0")))
int func_003229D0(int a0, int a1, int a2, int a3) {
    int r;
    Forward33E6A8_324880();
    r = func_00322A38(a0, a1, a2, a3);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_00322A68")))
int func_00322A68(int a0, int a1, int a2, int a3) {
    int r;
    Forward33E6A8_324880();
    r = Forward322BD8_322AD0(a0, a1, a2, a3);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_00322AF8")))
int func_00322AF8(int a0, int a1, int a2, int a3) {
    int r;
    Forward33E6A8_324880();
    r = Forward322C18_322B60(a0, a1, a2, a3);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_0032D340")))
int func_0032D340(int a0, int a1, int a2, int a3) {
    int r;
    Obj33F8_NoOp_FCA0();
    r = func_0032D3A8(a0, a1, a2, a3);
    Obj33F8_NoOp_FCA8();
    return r;
}

__attribute__((section(".text.func_003392F8")))
int func_003392F8(int a0, int a1, int a2, int a3) {
    int v0;
    Forward33B658_3389F8();
    v0 = sjmem_IsGetChunk(a0, a1, a2, a3);
    Forward33B670_338A10();
    return v0;
}

__attribute__((section(".text.func_00339E98")))
int func_00339E98(int a0, int a1, int a2, int a3) {
    int v0;
    Forward33B658_3389F8();
    v0 = sjrbf_IsGetChunk(a0, a1, a2, a3);
    Forward33B670_338A10();
    return v0;
}

__attribute__((section(".text.func_0033AB68")))
int func_0033AB68(int a0, int a1, int a2, int a3) {
    int v0;
    Forward33B658_3389F8();
    v0 = sjuni_IsGetChunk(a0, a1, a2, a3);
    Forward33B670_338A10();
    return v0;
}

__attribute__((section(".text.func_0033B810")))
int func_0033B810(int a0, int a1, int a2, int a3) {
    int v0;
    Forward33B568_33B658();
    v0 = svm_SetCbSvr(a0, a1, a2, a3);
    Forward33B5C8_33B670();
    return v0;
}

__attribute__((section(".text.MPS_GetPackHd")))
int MPS_GetPackHd(void *a0, void *a1) {
    if (MPSLIB_CheckHn(a0)) {
        return MPSLIB_SetErr(0, 0xFF020201);
    }
    *(long long*)((char*)a1 + 0x0) = *(long long*)((char*)a0 + 0x18);
    *(long long*)((char*)a1 + 0x8) = *(long long*)((char*)a0 + 0x20);
    return 0;
}
