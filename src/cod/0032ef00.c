/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int GetField0OrZero_346828(void *a0);
extern void func_00345DF0(void *a0);
extern void func_00347E58(void *a0, int a1);
extern int MWSFSVM_Error(char *a0);
extern int GetArrayElemA0C_35A1C8(void *a0, int a1);
extern void func_0032AB70(int a0, int a1);
extern void func_0034D318(void *a0, int a1);
extern void SFHDS_ProcessHdr(void *a0);
extern void Obj34D8_CopyVec3_From98_To934(void *a0);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_0035B4A0(void);
extern int sfpl2_TrPause(void *a0, void *a1);
extern void func_00329EA8(int a0);

__attribute__((section(".text.func_00345EE0")))
int func_00345EE0(char *a0) {
    if (GetField0OrZero_346828(a0) != 1) {
        return MWSFSVM_Error(D_00458088);
    }
    func_00345DF0(a0);
    func_00347E58(a0, 0);
    *(int*)(a0 + 0x74) = 0;
    return func_00335950(*(int*)(a0 + 0x48));
}

__attribute__((section(".text.func_00348338")))
int func_00348338(void *a0, int a1, int a2, int a3) {
    int r = 0;
    char *p = func_00348938(a0);
    if (p != 0) {
        int (*fp)(int, int, int) = *(int (**)(int, int, int))(p + 8);
        if (fp != 0) {
            r = fp(a1, a2, a3);
        }
    }
    return r;
}

__attribute__((section(".text.func_0034ABF8")))
void func_0034ABF8(char *a0) {
    char *s1 = *(char **)(a0 + 0x2004);
    int s0 = *(int *)(s1 + 0);
    int ret = GetArrayElemA0C_35A1C8(a0, 0x1B);
    if (*(int *)(s1 + 0x44) != ret) {
        *(int *)(s1 + 0x44) = ret;
        func_0032AB70(s0, ret);
    }
}

__attribute__((section(".text.func_0034D3E8")))
void func_0034D3E8(char *a0) {
    char *s0 = a0 + 0x78;
    int r = func_0034D450(a0);
    if (r != 0) {
        func_0034D318(s0, r);
        SFHDS_ProcessHdr(s0);
        Obj34D8_CopyVec3_From98_To934(a0);
    }
}

__attribute__((section(".text.func_003565E0")))
int func_003565E0(int a0, void *a1, int a2) {
    D_00766C70 = 1;
    memcpy(D_00766C78, a1, 8);
    memcpy((void *)(*(int *)((char *)a2 + 0x1FC0) + 0x11F8), a1, 8);
    func_0034DD70((void *)a2, 0xFF000F40);
    return 1;
}

__attribute__((section(".text.func_00357068")))
int func_00357068(void *a0, void *a1) {
    unsigned int x = *(int *)((char *)a0 + 0x4C) - 3;
    if (x >= 2) {
        return 0;
    }
    func_0035B4A0();
    return sfpl2_TrPause(a0, a1);
}

__attribute__((section(".text.func_00358700")))
void func_00358700(void *a0, int a1, void *a2) {
    int *slot = (int *)((char *)a0 + 0x950);
    void (*fp)(void *, void *, void *);
    *slot = *slot + a1;
    fp = GetArrayElemA0C_35A1C8(a0, 0x24);
    if (fp != 0) {
        fp(a0, a2, slot);
    }
}

__attribute__((section(".text.func_00358768")))
void func_00358768(void *a0, int a1, void *a2) {
    int *base = (int *)((char *)a0 + 0x950);
    void (*fp)(void *, void *, void *);
    base[1] = base[1] + a1;
    fp = GetArrayElemA0C_35A1C8(a0, 0x25);
    if (fp != 0) {
        fp(a0, a2, base);
    }
}

__attribute__((section(".text.func_0032EF00")))
void func_0032EF00(char *a0) {
    int i = 0;
    if (*(signed char *)(a0 + 3) > 0) {
        int *p = (int *)(a0 + 0xC);
        do {
            func_00329EA8(*p);
            p++;
            i++;
        } while (i < *(signed char *)(a0 + 3));
    }
}
