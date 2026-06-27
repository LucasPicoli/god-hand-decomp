/* cygnus-2.96 matched TU. */

extern void *getElemInfPtr();
extern int isEnableVidFtr();
extern int D_00762058;
extern int D_003EE2E8;
extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(void *);
extern int M2VERR_SetCode(int, unsigned int);
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *);
extern void func_003589C0(void *);

__attribute__((section(".text.func_00350418")))
void func_00350418(char *obj, int *arr, int count) {
    int *base;
    int s2;
    int i;
    base = *(int **)((char *)obj + 0x1FC0);
    s2 = *base;
    if (s2 == 0) return;
    for (i = 0; i < count; i++) {
        func_0036C450(s2, i, arr[i]);
    }
}

__attribute__((section(".text.func_0035E670")))
int func_0035E670(void *a0, int a1, int *out)
{
    void *p;
    unsigned char k;
    unsigned char b;

    k = a1 & 0xFF;
    *out = 0;
    p = getElemInfPtr(a0, k);
    if (p == 0)
        return 0;
    if (isEnableVidFtr(k, p) == 0)
        return 0;
    b = (*(unsigned char *)((char *)p + 0x23)) & 0x10;
    *out = b != 0;
    return 1;
}

__attribute__((section(".text.func_0034E140")))
int func_0034E140(void)
{
    int r;
    if (func_0034E1B0() != 0) {
        for (;;)
            ;
    }
    r = func_00368CE8(8, &D_00762058);
    if (r != 0)
        return func_0034DD70(0, 0xFF000D01);
    D_003EE2E8 = 0;
    return r;
}

__attribute__((section(".text.func_0036DA30")))
void func_0036DA30(void *a0)
{
    if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(a0)) {
        M2VERR_SetCode(0, 0xFF030210);
        return;
    }
    *(int *)((char *)a0 + 0x118) = 1;
}

__attribute__((section(".text.func_00359518")))
int func_00359518(char *p0, int index, unsigned int p2, long long *p3) {
    char *base;
    char *e;
    int *cb;
    int *fb;
    int chk, off1c, off18;
    unsigned int len;
    base = p0 + 0x1310;
    e = base + index * 0x74;
    *p3 = -1;
    cb = (int *)(e + 0x38);
    fb = (int *)(e + 0x10);
    chk = cb[0];
    off18 = fb[2];
    off1c = fb[3];
    if (chk == 0) {
        return 0;
    }
    len = p2 - off1c;
    if (p2 < (unsigned int)(off18 + off1c)) {
        len = p2;
    }
    func_00359590(cb, len, p3, off18);
    return 0;
}

__attribute__((section(".text.func_00358968")))
int func_00358968(void *thisp) {
    if (Obj34D8_SetGlobalEE0B8_IfField48(thisp)) {
        return func_0034DD70(0, 0xFF000133);
    }
    func_003589C0(thisp);
    *(int *)((char *)thisp + 0x44) = 1;
}
