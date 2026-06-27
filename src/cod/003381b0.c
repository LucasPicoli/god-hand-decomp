/* cygnus-2.96 matched TU. */

extern int D_003E0710;
extern int D_003E0708;
extern void func_003402E0(int);
extern void func_00337398(int);
extern int DTX_CallUrpc(int, int *, int, int, int);
extern int SFCON_IsEndcodeSkip();
extern int D_00457308;
extern int D_00457340;
extern int GetArrayElemA0C_35A1C8(int, int);
extern int Obj35C0_GetIndexed_1F30_C338(int, int);

__attribute__((section(".text.func_003381B0")))
void func_003381B0(int a0) {
    int i;
    int local;
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            *(char *)(a0) = 0;
            return;
        }
    }
    for (i = 0; i < *(int *)(a0 + 4); i++) {
        int x = ((int *)(a0 + 0x10))[i];
        if (x) func_003402E0(x);
    }
    local = *(int *)(a0 + 0x20);
    DTX_CallUrpc(9, &local, 1, 0, 0);
    for (i = 0; i < *(int *)(a0 + 4); i++) {
        int x = ((int *)(a0 + 8))[i];
        if (x) func_00337398(x);
    }
    *(char *)(a0) = 0;
}

__attribute__((section(".text.func_00359CB8")))
void func_00359CB8(int a) {
    int *obj;
    int *q = (int *)(a + 0x36B4);
    int *r = (int *)(a + 0xDC4);
    int updated;
    obj = *(int **)(a + 0x36B0);
    if (SFCON_IsEndcodeSkip() != 0) {
        return;
    }
    updated = 0;
    if (*(int *)((char *)obj + 0xDAC) <= 0) {
        int idx = 0;
        if (q[1] != -3) {
            idx = *(int *)((char *)obj + 0xDD4);
        }
        if (idx >= 0) {
            int rr = func_00359DA8(a);
            if (rr != -1) {
                *(int *)((char *)obj + 0xDAC) = idx + rr;
                updated = 1;
            }
        }
    }
    if (*(int *)((char *)obj + 0xDB0) <= 0) {
        int t = r[9];
        if (t > 0) {
            *(int *)((char *)obj + 0xDB0) = t;
            updated = 1;
            *(int *)((char *)obj + 0xDB4) = r[10];
        }
    }
    if (updated == 0) {
        return;
    }
    func_00359DF0(a);
}

int MWSFSVM_Error(void *);
int MWSFD_GetUsePicUsr(void);
int func_003504A0(int, int, int, int);

__attribute__((section(".text.func_00343AE8")))
int func_00343AE8(int a0) {
    int a1 = *(int *)(a0 + 0x178);
    int s1, s2, s3, r;
    if (a1 == 0)
        return MWSFSVM_Error(&D_00457308);
    s2 = *(int *)(a0 + 0x18) + 4;
    s3 = *(int *)(a1 + 0x8);
    s1 = *(int *)(a1 + 0x0);
    if (*(int *)(a1 + 0x4) < s2 * s3)
        return MWSFSVM_Error(&D_00457340);
    r = MWSFD_GetUsePicUsr();
    if (r == 1)
        return func_003504A0(*(int *)(a0 + 0x3C), s1, s2, s3);
    return r;
}

__attribute__((section(".text.func_00360428")))
void func_00360428(int a0, int a1, int a2, int a3) {
    int s3 = a3 + 0x400;
    func_003A52F0(a3, 0, 0x400);
    func_00360280(a0, a1, a2, s3);
    if (*(int*)(a0 + 0x44) == 0) {
        if (*(int*)(a0 + 4) == 0x10) {
            func_00360520(a0, s3, a3);
        } else {
            func_003605B0(a0, s3, a3);
        }
    } else {
        (*(void(**)(int, int, float, float))(a0 + 0x44))(s3, a3, *(float*)(a0 + 0x3C), *(float*)(a0 + 0x40));
    }
}

__attribute__((section(".text.func_0034F930")))
void func_0034F930(int a0) {
    int s1 = *(int*)(a0 + 0x1F7C);
    if (GetArrayElemA0C_35A1C8(a0, 6) && GetArrayElemA0C_35A1C8(a0, 0x50)
        && !func_0034C7F0(a0, 2) && *(int*)(s1 + 8) == 0
        && Obj35C0_GetIndexed_1F30_C338(a0, 6)) {
        func_0035A000(a0, 6, 0);
    }
    if (GetArrayElemA0C_35A1C8(a0, 5) && GetArrayElemA0C_35A1C8(a0, 0x4F)
        && !func_0034C7F0(a0, 1) && *(int*)(s1 + 4) == 0
        && Obj35C0_GetIndexed_1F30_C338(a0, 7)) {
        func_0035A000(a0, 5, 0);
    }
}

__attribute__((section(".text.func_00353250")))
int func_00353250(int a0, int a1) {
    int p = *(int*)(a0 + 0x1FC0);
    int q = p + 0x8C;
    int p2, r;
    if (GetArrayElemA0C_35A1C8(a0, 0x2F) == 1) return 1;
    if (GetArrayElemA0C_35A1C8(a0, 0x27) == 1) return 0;
    if (*(signed char*)(q + 0x58) != 0) return *(int*)(p + 0x16C);
    p2 = *(int*)(q + 0x18);
    if (func_003534B0(a0) != 0) r = 1;
    else if (func_00353500(a0, p2) != 0) r = 1;
    else if (func_00353550(a0, p2, a1) != 0) r = 1;
    else if (func_00353348(a0, p2) != 0) r = 1;
    else r = (func_00353630(a0, p2) != 0);
    func_003533A8(a0, q, r);
    return r;
}
