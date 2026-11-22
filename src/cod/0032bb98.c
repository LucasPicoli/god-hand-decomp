/* cygnus-2.96: func_0032BB98, ADX stream start by file id: look the file up in the AFS partition and
 * begin playback, or report the missing id and enter the error state. */
#include "godhand/globals.h"
typedef struct AdxFileHn {
    char unk00;
    char stat;                  /* 0x01 */
    char unk02;                 /* 0x02 */
    char unk03[5];
    void *sj;                   /* 0x08 */
    char unk0C[0x54];
    short unk60;                /* 0x60 */
    char unk62[0x4A];
    char unkAC;                 /* 0xAC */
    char unkAD[3];
    int dir;                    /* 0xB0 */
    int unkB4;                  /* 0xB4 */
    int ofst;                   /* 0xB8 */
    int nsct;                   /* 0xBC */
    int unkC0;                  /* 0xC0 */
} AdxFileHn;

extern void func_0033F130(char *msg);
extern void ADXT_Stop(AdxFileHn *adxt);
extern int ADXF_GetFnameRangeEx(int patid, int fid, int dir, int *ofst, int *nsct, int *c0);
extern void ADXERR_ItoA2(int a, int b, char *buf, int n);
extern void func_0033F1A8(char *msg, char *arg);
extern void ADXT_SetLnkSw(AdxFileHn *adxt, int a1);

__attribute__((section(".text.func_0032BB98")))
void func_0032BB98(AdxFileHn *adxt, int patid, int fid)
{
    char buf[0x10];
    int ofst, nsct, c0;

    if (adxt == 0) {
        func_0033F130(D_00452748);
        return;
    }
    ADXT_Stop(adxt);
    if (ADXF_GetFnameRangeEx(patid, fid, adxt->dir, &ofst, &nsct, &c0) != 0)
        return;
    if (adxt->sj == 0) {
        ADXERR_ItoA2(patid, fid, buf, 0x10);
        func_0033F1A8(D_00452778, buf);
        adxt->unk60 = -1;
        adxt->stat = 6;
        return;
    }
    adxt->unkB4 = adxt->dir;
    adxt->ofst = ofst;
    adxt->nsct = nsct;
    adxt->unkC0 = c0;
    adxt->stat = 1;
    adxt->unkAC = 1;
    adxt->unk02 = 1;
    ADXT_SetLnkSw(adxt, 0);
}
