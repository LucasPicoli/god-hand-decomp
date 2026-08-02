/* sn-2.95.3-136 matched TU. */

extern char D_00447AD0[];
extern char D_00447E68[];
extern int NoOp_279E70();
extern char D_00447F70[];
extern char D_00448028[];
extern char D_004483A8[];
extern int cCollisionSolidManage_ReleaseUnit_27E088();
extern char D_00448890[];
extern char D_00448948[];

/* clone */

__attribute__((section(".text.func_001FAA18")))
void func_001FAA18(void *a0, int a1) {
    if (!*(void **)a0)
        return;
    *(int *)((char *)*(void **)a0 + 0x6C) += a1;
    if (*(int *)((char *)*(void **)a0 + 0x6C) >= 0xA)
        *(int *)((char *)*(void **)a0 + 0x6C) = 9;
    if (*(int *)((char *)*(void **)a0 + 0x6C) < 0)
        *(int *)((char *)*(void **)a0 + 0x6C) = 0;
}

/* clone */

__attribute__((section(".text.func_0026E7A8")))
void func_0026E7A8(char *a0, float *a1) {
    float *p = (float*)(a0 + 0x1660);
    if (p == a1) return;
    *(float*)(a0 + 0x1660) = a1[0];
    p[1] = a1[1];
    p[2] = a1[2];
}

/* clone */


__attribute__((section(".text.func_002714B0")))
void func_002714B0(char *a0) {
    int v = *(int*)(a0 + 0x1860);
    if (v) {
        func_0030F5C8(v);
        *(int*)(a0 + 0x1860) = 0;
    }
}

/* clone */



__attribute__((section(".text.func_00276980")))
int func_00276980(void *a0) {
    *(char**)((char*)a0+0x214) = D_00447AD0;
    return func_002A73C8(a0);
}

/* clone */




__attribute__((section(".text.func_00279D40")))
void func_00279D40(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_00447E68;
    NoOp_279E70(a0);
    func_0028EB88(a0, a1);
}

/* clone */



__attribute__((section(".text.func_0027A2F8")))
int func_0027A2F8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00447F70;
    return func_002A73C8(a0);
}

/* clone */



__attribute__((section(".text.func_0027ADE8")))
int func_0027ADE8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00448028;
    return func_002A73C8(a0);
}

/* clone */




__attribute__((section(".text.func_0027DE18")))
void func_0027DE18(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_004483A8;
    cCollisionSolidManage_ReleaseUnit_27E088(a0);
    func_0028EB88(a0, a1);
}

/* clone */



__attribute__((section(".text.func_00283660")))
int func_00283660(void *a0) {
    *(char**)((char*)a0+0x214) = D_00448890;
    return func_002A73C8(a0);
}

/* clone */



__attribute__((section(".text.func_00284040")))
int func_00284040(void *a0) {
    *(char**)((char*)a0+0x214) = D_00448948;
    return func_002A73C8(a0);
}
