/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"
#include "godhand/sftim.h"

extern int GetField0OrZero_346828(void *a0);
extern void func_00345DF0(void *a0);
extern void func_00347E58(void *a0, int a1);
extern int MWSFSVM_Error(char *a0);
extern void ADXT_SetSvrFreq(int a0, int a1);
extern void SFHDS_ProcessHdr(void *a0);
extern void Obj34D8_CopyVec3_From98_To934(void *a0);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void SFTIM_Pause(void);
extern int sfpl2_TrPause(void *a0, void *a1);
extern void ADXT_Stop(int a0);

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

__attribute__((section(".text.MWSST_CalcWorkSize")))
int MWSST_CalcWorkSize(void *a0, int a1, int a2, int a3) {
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

__attribute__((section(".text.sfadxt_SetSvrFreq")))
void sfadxt_SetSvrFreq(char *a0) {
    char *s1 = *(char **)(a0 + 0x2004);
    int s0 = *(int *)(s1 + 0);
    int ret = GetArrayElemA0C_35A1C8(a0, 0x1B);
    if (*(int *)(s1 + 0x44) != ret) {
        *(int *)(s1 + 0x44) = ret;
        ADXT_SetSvrFreq(s0, ret);
    }
}

__attribute__((section(".text.SFHDS_ReprocessHdr")))
void SFHDS_ReprocessHdr(SftimHn *hn) {
    SfdHdInf *hdr = &hn->hdr;
    SfdHdInf *r = (SfdHdInf *)sfhds_GetHd(hn);
    if (r != 0) {
        func_0034D318(hdr, r);
        SFHDS_ProcessHdr(hdr);
        Obj34D8_CopyVec3_From98_To934(hn);
    }
}

__attribute__((section(".text.mpegError")))
int mpegError(int a0, void *a1, int a2) {
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
    SFTIM_Pause();
    return sfpl2_TrPause(a0, a1);
}

__attribute__((section(".text.SFPLY_AddDecPic")))
void SFPLY_AddDecPic(SftimHn *hn, int n, int picType) {
    SfdErr *inf = &hn->errInf;
    SfdPicCntFn fp;
    inf->nDec = inf->nDec + n;
    fp = (SfdPicCntFn)GetArrayElemA0C_35A1C8(hn, 0x24);
    if (fp != 0) {
        fp(hn, picType, inf);
    }
}

__attribute__((section(".text.SFPLY_AddSkipPic")))
void SFPLY_AddSkipPic(SftimHn *hn, int n, int picType) {
    SfdErr *inf = &hn->errInf;
    SfdPicCntFn fp;
    inf->nSkip = inf->nSkip + n;
    fp = (SfdPicCntFn)GetArrayElemA0C_35A1C8(hn, 0x25);
    if (fp != 0) {
        fp(hn, picType, inf);
    }
}

__attribute__((section(".text.func_0032EF00")))
void func_0032EF00(char *a0) {
    int i = 0;
    if (*(signed char *)(a0 + 3) > 0) {
        int *p = (int *)(a0 + 0xC);
        do {
            ADXT_Stop(*p);
            p++;
            i++;
        } while (i < *(signed char *)(a0 + 3));
    }
}
