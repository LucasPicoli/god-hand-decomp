/* cygnus-2.96 matched TU. */
#include "godhand/criStm.h"
#include "godhand/globals.h"
#include "godhand/sftim.h"

extern int D_0076A790[];

__attribute__((section(".text.func_00306FC0")))
void func_00306FC0(void *unused, char *p) {
    if (*(short *)(p + 0xA) == 0) {
        *(int *)(p + 0x0) = 0;
        *(int *)(p + 0x4) = 0;
        *(char *)(p + 0x8) = 0;
        *(char *)(p + 0x9) = 0;
        *(short *)(p + 0xA) = 0;
        *(short *)(p + 0x10) = 0;
        *(int *)(p + 0xC) = 0;
        *(short *)(p + 0x12) = 0;
    }
}

/* cygnus-2.96 | drop-freorder-blocks */



__attribute__((section(".text.func_00330E70")))
void func_00330E70(int a, int b)
{
    if (a == 0) {
        D_003D8404 = 0;
        D_003D8408 = 0;
    } else {
        D_003D8404 = a;
        D_003D8408 = b;
    }
}

__attribute__((section(".text.PS2RNA_ResetSpu2CoreNo")))
void PS2RNA_ResetSpu2CoreNo(char *p) {
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return;
        }
    }
    *(unsigned char *)(p + 0x56) = *(unsigned char *)(p + 0x1);
}

__attribute__((section(".text.SJCRS_Init")))
void SJCRS_Init(void) {
    D_003E3A90++;
    if (D_003E3A90 == 1) {
        D_003E3A88 = 0;
    }
}

__attribute__((section(".text.SJCRS_Finish")))
void SJCRS_Finish(void) {
    D_003E3A90--;
    if (D_003E3A90 == 0) {
        D_003E3A88 = 0;
    }
}

__attribute__((section(".text.ADXCRS_Init")))
void ADXCRS_Init(void) {
    D_003EADB0++;
    if (D_003EADB0 == 1) {
        D_003EADA8 = 0;
    }
}

/* cygnus-2.96, c_flags_drop: ["-f=-freorder-blocks"] */





__attribute__((section(".text.mwsfcre_MallocRfb")))
int mwsfcre_MallocRfb(void *a0, char *a1, int *out)
{
    char hold[16];
    int ret;
    int cap;
    int size;

    ret = 0;
    cap = 0x840D0;
    *(int *)(hold + 4) = cap;
    size = *(int *)(a1 + 0x8) * *(int *)(a1 + 0xC) * 9 / 2 + 0x2840;
    *(int *)hold = size;
    if (D_003EC7D0 != 0) {
        if (D_003EC7D0 < 2 || D_003EC7D4 < size || D_003EC7D4 < cap) {
            out[0] = 0;
            out[1] = 0;
            ret = -1;
        } else {
            int u0 = D_00758A30[0];
            int u1 = D_00758A30[1];
            out[1] = u1;
            out[0] = u0;
        }
    } else {
        out[0] = func_00344568(a0, size);
        out[1] = func_00344568(a0, *(int *)(hold + 4));
    }
    if (out[0] == 0 || out[1] == 0) {
        ret = -1;
    }
    return ret;
}

/* cygnus-2.96 | drop-freorder-blocks */
__attribute__((section(".text.SFMPVF_EndRefFrm")))
void SFMPVF_EndRefFrm(int *p)
{
    if (p != 0) {
        if (*p == 4) {
            *p = 2;
        } else {
            *p = 0;
        }
    }
}

__attribute__((section(".text.SFSET_GetTrHn")))
void SFSET_GetTrHn(char *base, int i, int *out) {
    int *p = *(int **)(base + i * 0x44 + 0x1F38);
    if (p == 0) {
        *out = 0;
    } else {
        *out = *p;
    }
}

__attribute__((section(".text.sftim_IsTimeIncre")))
int sftim_IsTimeIncre(char *p) {
    char *q = p + 0x950;

    if (*(int *)(p + 0x48) != 4) {
        return 0;
    }
    if (*(int *)(p + 0x50) != 0) {
        return 0;
    }
    return *(int *)(q + 0x20) == 0;
}

__attribute__((section(".text.SFTIM_GetTimeOneFrmVideo")))
void SFTIM_GetTimeOneFrmVideo(char *p, int *o1, int *o2) {
    int i = *(int *)(p + 0x920);
    int v;

    if (i == 0) {
        *o1 = 0;
        *o2 = 0x7512;
        return;
    }
    v = D_00459920[i];
    *o1 = 0x3E8;
    *o2 = v;
}

/* cygnus-2.96 | drop-freorder-blocks */


__attribute__((section(".text.SdeSndIdNew")))
int SdeSndIdNew(void)
{
    int n = D_0076A790[6] + 1;

    D_0076A790[6] = n;
    if (n == 0) {
        D_0076A790[6] = 1;
    }
    return D_0076A790[6];
}
