/* include/godhand/adxf.h - ADXF partition records (CRI libadxe, 0x322C68..0x324858).
 *
 * One AdxfPtInfo is the 0x11C-byte record of a loaded partition table. D_003EB308 holds
 * one pointer per partition id. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_ADXF_H
#define GODHAND_ADXF_H

typedef struct AdxfPtInfo {
    int unk00;                          /* 0x00 */
    int unk04;                          /* 0x04 */
    int unk08;                          /* 0x08 */
    char unk0C[3];                      /* 0x0C */
    signed char type;                   /* 0x0F 1 = packed 32-bit entries */
    char fname[0x100];                  /* 0x10 */
    void *dir;                          /* 0x110 */
    int ofst;                           /* 0x114 */
    int top;                            /* 0x118 also the 16-bit table base */
    int tbl[1];                         /* 0x11C one entry per file */
} AdxfPtInfo;

#define ADXF_PTINFO_SIZE 0x11C

extern AdxfPtInfo *D_003EB308[];

extern int adxf_ChkPrmPt(int ptid, void *ptinfo);
extern int adxf_GetFnameRangeEx(int ptid, int flid, char *fname, void **dir, int *ofst, int *fnsct, int *fsize);

#endif
