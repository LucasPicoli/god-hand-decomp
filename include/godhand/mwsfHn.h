/* include/godhand/mwsfHn.h - MWSF (Sofdec middleware) play handle and SUD stream table
 * (cygnus code at 0x344F18..0x348610).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_MWSFHN_H
#define GODHAND_MWSFHN_H

typedef struct MwsfHn {
    int unk00;
    int stat;                   /* 0x04 */
    char unk08[0x3C - 0x08];
    void *sfd;                  /* 0x3C */
    char unk40[0x70 - 0x40];
    char concat;                /* 0x70 */
    char concatSave;            /* 0x71 */
    char unk72[0x1A4 - 0x72];
    int f1A4;                   /* 0x1A4 */
    char unk1A8[0x284 - 0x1A8];
    char sub284[0x2A4 - 0x284]; /* 0x284 */
    char sub2A4[0x2D8 - 0x2A4]; /* 0x2A4 */
    int f2D8;                   /* 0x2D8 */
    int f2DC;                   /* 0x2DC */
    int busy;                   /* 0x2E0 */
    unsigned int mode;          /* 0x2E4 */
    int f2E8;                   /* 0x2E8 */
    int f2EC;                   /* 0x2EC */
    int f2F0;                   /* 0x2F0 */
    int f2F4;                   /* 0x2F4 */
    int f2F8;                   /* 0x2F8 */
    int f2FC;                   /* 0x2FC */
    int count;                  /* 0x300 */
} MwsfHn;

typedef struct SudStmEnt {
    int state;
    int unk04;
    int type;
    int unk0C;
    int ccs;
} SudStmEnt;

typedef struct SudStmTbl {
    char pad00[0xC0];
    SudStmEnt ent[8];           /* 0xC0 */
} SudStmTbl;

extern int GetField0OrZero_346828(MwsfHn *mw);
extern void MWSFSVM_Error(const char *msg);
extern int MWSFLIB_SetErrCode(int err);
extern int Forward345250_344F18(MwsfHn *mw);
extern int mwPlyGetStat(MwsfHn *mw);
extern int func_003468B8(MwsfHn *mw);
extern void func_00346968(MwsfHn *mw, int *time, int *tunit);
extern void mwPlyStartFnameLp(MwsfHn *mw, int a1);
extern void mwPlyStartAfsLp(MwsfHn *mw, int a1, int a2);
extern void mwPlyStartFnameRangeLp(MwsfHn *mw, int a1, int a2, int a3);
extern void CheckReleasLpTiming(MwsfHn *mw);
extern void MWSST_SetLnkSw(void *sub, int on);
extern int Obj0000_Call_0035A128_Field_3C(MwsfHn *mw, int id, int *out);

extern int SFD_SetConcatPlay(void *sfd);
extern int SFD_GetTime(void *sfd, int *time, int *tunit);
extern int SFD_GetHnStat(void *sfd);
extern int SFD_GetFps(void *sfd, int *out);

#endif /* GODHAND_MWSFHN_H */
