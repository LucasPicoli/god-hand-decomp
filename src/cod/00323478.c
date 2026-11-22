/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void MWSFSVM_Error();
extern signed char D_003EAEC8[];
extern signed char D_003DED70[];
extern signed char D_003D84C0[];
extern void DTX_Destroy(void *);

typedef struct {
    char pad[0x1A4];
    int f1A4;
    int pad2[1];
    int f1AC;
    int f1B0;
    int f1B4;
    int f1B8;
} S346228;





__attribute__((section(".text.MWSFPLY_ReqStartAfs")))
void MWSFPLY_ReqStartAfs(S346228 *this, int a1, int a2) {
    int x, y, z;
    if (ADXF_GetFnameRangeEx(a1, a2, this->f1A4, &x, &y, &z) == 0) {
        this->f1B0 = x;
        this->f1B4 = y;
        this->f1B8 = z;
        this->f1AC = 1;
    } else {
        MWSFSVM_Error(D_00458168);
    }
}

__attribute__((section(".text.adxf_AllocAdxFs")))
signed char *adxf_AllocAdxFs(void) {
    signed char *r;
    int i;
    r = 0;
    for (i = 0; i < 16; i++) {
        if (D_003EAEC8[i * 0x44] == 0) {
            r = &D_003EAEC8[i * 0x44];
            break;
        }
    }
    return r;
}

__attribute__((section(".text.sfmps_ShortSupply")))
void sfmps_ShortSupply(void *a0, int *out)
{
    int *base;
    int s1v;
    int r;
    int res;

    base = (int *)((char *)a0 + 0x1F74);
    s1v = base[2];
    r = SFBUF_GetTermFlg(a0, base[4]);
    if (r == 1) {
        sfmps_SetTermDst(a0, *(int *)(s1v + 0x3C));
        res = 1;
    } else {
        res = 0;
    }
    if (out != 0)
        *out = res;
}

__attribute__((section(".text.mfci_alloc")))
signed char *mfci_alloc(void) {
    signed char *result;
    int i;
    result = 0;
    for (i = 0; i < 0x28; i++) {
        if (D_003DED70[i * 0x38] == 0) {
            result = &D_003DED70[i * 0x38];
            break;
        }
    }
    return result;
}

__attribute__((section(".text.DTX_Finish")))
void DTX_Finish(void) {
    signed char *p;
    int i;
    int one;
    if (--D_003D84BC == 0) {
        one = 1;
        p = D_003D84C0;
        i = 15;
        do {
            if (*p == one) {
                DTX_Destroy(p);
            }
            i--;
            p += 0x44;
        } while (i >= 0);
    }
}
