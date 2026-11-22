/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern volatile int D_003CF9E8;
extern char D_003CF9F0;
extern void func_003A52F0(void *, int, int);
extern void ADXB_Init(void);
extern long long func_0031DE10(long long, long long);
extern long long func_003B7FE0(long long, long long);
extern void SfErrSlot_report(int);
extern int Obj35C0_GetIndexed_1F30_C338(int, int);
extern int Obj35D0_ReturnOne_D0D0(int);
extern void Obj35C0_SetIndexed_1F30_C320(int, int, int);
extern int Obj35C0_GetIndexed_1F34_C368(char *a0, int a1);
extern int sfvom_IsTerm(char *a0);
extern void Obj35C0_SetIndexed_1F34_C350(char *a0, int a1, int a2);
extern int Obj35D0_ReturnOne_D428(char *a0);
extern void Obj34D8_SetFields_0_4(char *a0, int a1, int a2);
extern int Obj34D8_SetGlobalEE0B8_IfField48(char *a0);
struct ADX_BASIC;
extern void adxb_ResetAinf(struct ADX_BASIC *self);
extern int ADXB_CheckAu(int);
extern int sfhds_CallS(int, int, void *);
extern int SFH_IsEffFtrInf(int, int, int *);
extern int SFH_AnlyElemCodecVid();
extern int SFH_AnlyElemBitRate();
extern int SFH_AnlyElemPicRate();
extern int SFH_AnlyFtrColType();
extern int SFH_AnlyFtrPicType();
extern int SFH_AnlyFtrFixFlg();
extern int SFH_AnlyFtrShcFixFlg();
extern int SFH_AnlyFtrExpand();
extern int SFH_AnlyFtrGopN();
extern int SFH_AnlyFtrGopM();

__attribute__((section(".text.ADXSJD_Finish")))
void ADXSJD_Finish(void) {
    D_003CF9E8 -= 1;
    if (D_003CF9E8 == 0) {
        func_003A52F0(&D_003CF9F0, 0, 0xAC0);
    }
}

__attribute__((section(".text.ADXSJD_Init")))
int ADXSJD_Init(void) {
    int n;
    if (D_003CF9E8 == 0) {
        ADXB_Init();
        func_003A52F0(&D_003CF9F0, 0, 0xAC0);
    }
    n = D_003CF9E8 + 1;
    D_003CF9E8 = n;
    return n;
}

__attribute__((section(".text.SFTST_GoNextFrame")))
void SFTST_GoNextFrame(char *a0, char *a1) {
    long long r, r2;
    if (*(int *)(a0 + 0xC) == 0) {
        r = func_0031DE10(*(long long *)(a0 + 0x130), *(long long *)(a1));
        r2 = func_003B7FE0(r, *(long long *)(a1 + 8));
        *(long long *)(a0 + 0x128) += r2;
    }
}

__attribute__((section(".text.func_0034DD70")))
int func_0034DD70(int a0, int a1) {
    int v0 = 0;
    int t;
    if (a1 != 0) {
        if (a0 == 0) {
            SfErrSlot_report((int)&D_003EE25C);
        } else {
            SfErrSlot_report(a0 + 0x9F8);
            t = *(int*)(a0 + 0x48);
            if (t > 0)
                *(int*)(a0 + 0x48) = -t;
        }
        v0 = a1;
    }
    return v0;
}

__attribute__((section(".text.func_0035D050")))
void func_0035D050(int a0) {
    if (Obj35C0_GetIndexed_1F30_C338(a0, 8) == 1)
        return;
    if (SFBUF_GetPrepFlg(a0, *(int*)(a0 + 0x2160)) != 1)
        return;
    if (Obj35D0_ReturnOne_D0D0(a0) == 0)
        return;
    Obj35C0_SetIndexed_1F30_C320(a0, 8, 1);
}

__attribute__((section(".text.func_0035D2E0")))
void func_0035D2E0(char *a0)
{
    if (Obj35C0_GetIndexed_1F34_C368(a0, 6) != 1
        && SFBUF_GetTermFlg(a0, *(int *)(a0 + 0x20D8)) == 1
        && sfvom_IsTerm(a0) != 0) {
        Obj35C0_SetIndexed_1F34_C350(a0, 6, 1);
    }
}

__attribute__((section(".text.func_0035D3A8")))
void func_0035D3A8(char *a0)
{
    if (Obj35C0_GetIndexed_1F30_C338(a0, 6) != 1
        && SFBUF_GetPrepFlg(a0, *(int *)(a0 + 0x20D8)) == 1
        && Obj35D0_ReturnOne_D428(a0) != 0) {
        Obj35C0_SetIndexed_1F30_C320(a0, 6, 1);
    }
}

__attribute__((section(".text.func_0034DE20")))
int func_0034DE20(char *a0, int a1, int a2)
{
    if (a0 == 0) {
        Obj34D8_SetFields_0_4((char *)&D_003EE25C, a1, a2);
    } else if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0) {
        return func_0034DD70(0, 0xFF000101);
    } else {
        Obj34D8_SetFields_0_4(a0 + 0x9F8, a1, a2);
    }
    return 0;
}

/* Reset the AINF data, then decode the header as ADX (magic 0x8000) or as the next format whose check passes; -1 when none does. */
__attribute__((section(".text.ADXB_DecodeHeader")))
int ADXB_DecodeHeader(int a0, int a1, int a2) {
    unsigned short v;
    adxb_ResetAinf((struct ADX_BASIC *)a0);
    v = *(unsigned short *)a1;
    if ((((v >> 8) | (v << 8)) & 0xFFFF) == 0x8000)
        return func_0033C960(a0, a1, a2);
    if (func_0033DD50(a1))
        return ADXB_DecodeHeaderSpsd(a0, a1, a2);
    if (func_0033E558(a1))
        return ADXB_DecodeHeaderWav(a0, a1, a2);
    if (func_00340E90(a1))
        return ADXB_DecodeHeaderAiff(a0, a1, a2);
    if (ADXB_CheckAu(a1))
        return ADXB_DecodeHeaderAu(a0, a1, a2);
    if (ADXB_CheckAc3(a1))
        return ADXB_DecodeHeaderAc3(a0, a1, a2);
    return -1;
}

__attribute__((section(".text.sfhds_AnlyVideo")))
void sfhds_AnlyVideo(int a0, int a1, int *obj) {
    int local;
    int a1b = a1 & 0xFF;
    int r;

    obj[0] = sfhds_CallS(a0, a1, SFH_AnlyElemCodecVid);
    obj[1] = sfhds_CallS(a0, a1, SFH_AnlyElemBitRate);
    if (SFH_AnlyElemPicSz(a0, a1b, &obj[2], &obj[3]) == 0) {
        obj[2] = -1;
        obj[3] = -1;
    }
    obj[4] = sfhds_CallS(a0, a1, SFH_AnlyElemPicRate);
    r = SFH_IsEffFtrInf(a0, a1b, &local);
    if (r == 0) local = 0;
    obj[5] = (local != 0);
    if (local) {
        obj[6] = sfhds_CallS(a0, a1, SFH_AnlyFtrColType);
        obj[7] = sfhds_CallS(a0, a1, SFH_AnlyFtrPicType);
        obj[8] = sfhds_CallS(a0, a1, SFH_AnlyFtrFixFlg);
        obj[9] = sfhds_CallS(a0, a1, SFH_AnlyFtrShcFixFlg);
        obj[10] = sfhds_CallS(a0, a1, SFH_AnlyFtrExpand);
        obj[11] = sfhds_CallS(a0, a1, SFH_AnlyFtrGopN);
        obj[12] = sfhds_CallS(a0, a1, SFH_AnlyFtrGopM);
    }
}
