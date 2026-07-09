/* cygnus-2.96 matched TU. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(void *a0);
extern void func_003589C0(void *a0);
extern void func_0034D098(void *a0);
extern void SFBUF_DestroySj(void *a0);
extern int D_003EE2C4[];

__attribute__((section(".text.func_003587E8")))
int func_003587E8(void *a0) {
    int i;
    int *p;
    int r;
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0)) {
        return func_0034DD70(0, 0xFF000131);
    }
    func_003589C0(a0);
    func_0034D098((char *)a0 + 0x78);
    SFBUF_DestroySj(a0);
    r = func_00358888(a0);
    p = D_003EE2C4;
    for (i = 7; i >= 0; i--) {
        if (*p == (int)a0)
            *p = 0;
        p++;
    }
    return r;
}
