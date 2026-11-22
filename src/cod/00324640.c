/* cygnus-2.96: ADXF file range lookup: sum the sector counts of the files before flid in the partition
 * table and return the partition, directory, sector offset and the file's size. */
#include "godhand/adxf.h"

extern int adxf_ChkPrmGfr(int ptid, int flid);
extern int ADXF_CALC_BYTE2SCT(int ent);
extern void func_003A5DA0(char *d, char *s, int n);

__attribute__((section(".text.adxf_GetFnameRangeEx")))
int adxf_GetFnameRangeEx(int ptid, int flid, char *fname, void **dir, int *ofst, int *fnsct, int *fsize)
{
    AdxfPtInfo *pt;
    unsigned short *tbl16;
    int *tbl32;
    int ret;
    int ofs;
    int i;

    ret = adxf_ChkPrmGfr(ptid, flid);
    if (ret < 0) {
        *dir = 0;
        *ofst = -1;
        *fnsct = -1;
        *fsize = -1;
        return ret;
    }
    pt = D_003EB308[ptid];
    if (pt->type == 1) {
        tbl32 = pt->tbl;
        ofs = ADXF_CALC_BYTE2SCT(pt->top);
        for (i = 0; i < flid; i++)
            ofs += ADXF_CALC_BYTE2SCT(tbl32[i]);
        *fnsct = ADXF_CALC_BYTE2SCT(tbl32[flid]);
        *fsize = tbl32[flid];
    } else {
        ofs = *(unsigned short *)&pt->top;
        tbl16 = (unsigned short *)&pt->top + 1;
        for (i = 0; i < flid; i++)
            ofs += tbl16[i];
        *fnsct = tbl16[flid];
        *fsize = tbl16[flid] << 11;
    }
    func_003A5DA0(fname, pt->fname, 0x100);
    *dir = pt->dir;
    *ofst = pt->ofst + ofs;
    return ret;
}
