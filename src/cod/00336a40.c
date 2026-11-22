/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void SFCON_WriteTotSmplQue(void *a0, int x, int y);
extern void func_00336330(void *, void *);

__attribute__((section(".text.sfadxt_HeadDecCallBack")))
void sfadxt_HeadDecCallBack(char *a0) {
    int *region; int id; int x; int y;
    region = (int *)(a0 + 0xD30);
    id = **(int **)(a0 + 0x2004);
    if (region[0x7D] != region[0x7E]) return;
    x = func_0032A4A8(id);
    y = func_0032A530(id);
    if (x <= 0) return;
    if (y <= 0) return;
    SFCON_WriteTotSmplQue(a0, x, y);
}

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
} P;




__attribute__((section(".text.mfCiSetSctLen")))
void mfCiSetSctLen(P *p, int n) {
    int a, u, t;
    if (p == 0) {
        func_00336330(p, &D_004551E8);
        return;
    }
    a = p->f8;
    u = p->f10;
    t = p->f4;
    p->f4 = n;
    p->fC = (a + n - 1) / n;
    p->f10 = (u * t) / n;
    p->f14 = p->f18 * n;
}

__attribute__((section(".text.SFPTS_WritePtsQue")))
int SFPTS_WritePtsQue(char *base, int idx, long long *pval, int *out) {
    int *entry;
    *out = 0;
    if (*pval < 0) return 0;
    entry = (int *)(base + idx * 116 + 0x1348);
    if (*entry == 0) return 0;
    if (func_00359480(entry, pval, out) == -1) {
        return func_0034DD70(base, 0xFF000421);
    }
    return 0;
}

__attribute__((section(".text.sfmps_ChkPrepFlg")))
int sfmps_ChkPrepFlg(void *a0) {
    int s0, r;
    r = sfmps_GetPrepDst(a0);
    if (r == 1) return r;
    s0 = *(int *)((char *)a0 + 0x1F84);
    r = SFBUF_GetPrepFlg(a0, s0);
    if (r != 1) return r;
    r = sfmps_IsPrepEnd(a0, s0);
    if (r == 0) return r;
    return sfmps_SetPrepDst(a0, 1);
}
