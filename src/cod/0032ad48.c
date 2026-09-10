/* cygnus-2.96 matched TU. */

extern const char D_00452500[];
extern const char D_004523D8[];

__attribute__((section(".text.ADXT_ClearErrCode")))
void ADXT_ClearErrCode(char *adxt)
{
    if (adxt == 0) {
        func_0033F130(D_00452500);
        return;
    }
    *(short *)(adxt + 0x60) = 0;
    *(int *)(adxt + 0x64) = 0;
    *(short *)(adxt + 0x68) = 0;
    *(short *)(adxt + 0x6A) = 0;
}

typedef struct SJ SJ;
struct SJVT { char pad[0x24]; int (*f24)(SJ *, int); };
struct SJ { struct SJVT *vt; };
struct ADXT { char pad[0x14]; SJ *f14; };




__attribute__((section(".text.ADXT_GetNumSctIbuf")))
int ADXT_GetNumSctIbuf(struct ADXT *adxt)
{
    SJ *sj;
    if (adxt == 0) {
        func_0033F130(D_004523D8);
        return -1;
    }
    sj = adxt->f14;
    if (sj != 0) return sj->vt->f24(sj, 1) / 2048;
    return 0;
}
