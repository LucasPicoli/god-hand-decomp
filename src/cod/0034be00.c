/* cygnus-2.96 matched TU. */

extern int MPSLIB_CheckHn(int, void *, int);
extern int MPSLIB_SetErr(int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern int Thunk_func_0033B658(void *);
extern int Thunk_func_0033B670(void *);
extern void func_0035BD88(void*, int);

__attribute__((section(".text.func_00368B18")))
int func_00368B18(int a0, void *a1, int a2) {
    if (MPSLIB_CheckHn(a0, a1, a2)) {
        return MPSLIB_SetErr(0, 0xFF020202);
    }
    memcpy(a1, (char *)((a2 << 5) + a0) + 0x48, 32);
    return 0;
}

__attribute__((section(".text.func_0034BE00")))
void func_0034BE00(int a0, int a1, int a2, int a3, int t0) {
    int *dst  = (int *)(a1 + t0 * 116);
    int *src1 = (int *)(a2 + t0 * 4);
    int *src2 = (int *)(a3 + t0 * 4);
    int *p = dst + 4;
    int va, vb, big;
    int *q;
    int k;
    func_0034BFA8((int)dst, 1, *src2 != 0);
    va = *src1;
    vb = *src2;
    big = a0 + 0x16B0;
    q = (int *)(a0 + 0x1EA8);
    p[0] = va;
    p[1] = vb;
    p[2] = 0;
    p[3] = 0;
    p[4] = big;
    for (k = 15; k >= 0; k--) {
        *q = 0;
        q = (int *)((char *)q - 0x88);
    }
}

__attribute__((section(".text.func_0034CE80")))
int func_0034CE80(int a0, int a1, int a2) {
    int buf[4];
    int *base = (int *)(a0 + 0xD30);
    int ret = 0;
    int count, last;
    Thunk_func_0033B658(buf);
    count = *(int *)((char *)base + 0x1F4);
    last  = *(int *)((char *)base + 0x1F8);
    if (count - last < 0x20) {
        *(int *)((char *)base + 0x1EC) = a2;
        ret = 1;
        *(int *)(a0 + (count % 32) * 4 + 0xF2C) = a1;
        *(int *)((char *)base + 0x1F4) += 1;
    }
    Thunk_func_0033B670(buf);
    return ret;
}

__attribute__((section(".text.func_0035BCD0")))
int func_0035BCD0(void *a0, char *a1, int **a2) {
    int *s3 = *a2;
    int *q = s3;
    char *p = a1;
    int i;
    for (i = 8; i >= 0; i--) {
        *(int *)(p + 8) = 0;
        func_0035BD88(p, *q);
        p += 0x44;
        q++;
    }
    if (func_0035BDD0(a0, s3))
        return func_0034DD70(a0, 0xFF000302);
    return 0;
}
