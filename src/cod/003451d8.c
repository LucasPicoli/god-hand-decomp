/* cygnus-2.96 matched TU. */

extern void func_003B9DE0(void *a0);
extern char D_00460A00[];
extern int D_003EE330;
extern int D_003EE334;
extern int *volatile D_00766CA0;
extern int *Obj0000_Get_D_00459FA8_35F8A8(void);
extern void func_0035F8B8(void);
extern void func_0035FE60(void);
extern void func_0035FE90(void);
extern void func_0036CA50(void);
extern int SFH_IsExistStmId(void *h, unsigned char id, int *out);

__attribute__((section(".text.func_003BA4F8")))
int func_003BA4F8(char *a0, unsigned char *a1) {
    unsigned int b;
    a1 += (*(int *)(a0 + 0x28) == 1);
    b = *a1;
    if ((b >> 3) >= 9) {
        func_003B9DE0(D_00460A00);
        return -1;
    }
    *(int *)(a0 + 0x38) = b & 7;
    return 0;
}

__attribute__((section(".text.func_003509E8")))
int func_003509E8(void *a0) {
    char *h = (char *)a0;
    int lim = *(int *)(h + 0xA68);
    int e = *(int *)(h + 0x2C);
    int pos;
    if (lim == -1) {
        lim = e;
    }
    if (e < lim) {
        lim = e;
    }
    pos = func_00355508(a0);
    if (*(int *)(h + 0x58) == 2) {
        pos = pos + *(int *)(h + 0x968);
    }
    if (pos < lim) {
        return 0;
    }
    return 1;
}

__attribute__((section(".text.func_0035F838")))
void func_0035F838(void) {
    if (D_003EE330 <= 0) {
        D_00766CA0 = Obj0000_Get_D_00459FA8_35F8A8();
        func_0035F8B8();
        func_0035FE60();
        func_0035FE90();
        func_0036CA50();
        D_003EE334 = 0;
        D_003EE330 = D_003EE330 + 1;
    }
}

__attribute__((section(".text.func_003451D8")))
int func_003451D8(void *a0) {
    int x;
    int y;
    int r;
    int xv;
    r = SFH_IsExistStmId(a0, 0xE0, &x);
    if (r != 1) {
        return 0;
    }
    xv = x;
    if (xv != r) {
        return 0;
    }
    if (func_0035E520(a0, 0xE0, &y) != xv) {
        return 0;
    }
    return y == 3;
}
