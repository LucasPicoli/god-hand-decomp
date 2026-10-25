/* include/godhand/sfadxtHn.h - the ADXT audio side of a Sofdec handle (CRI libsfd, src/cod/0034a*..0034b*).
 *
 * The handle keeps the ADXT creation parameters at 0x35B0, the created
 * player pair at 0x35A8 and a six-slot callback table at 0x365C (0x2114 points
 * at it). Field names are ours, taken from the matched routines; offsets are
 * exact. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_SFADXTHN_H
#define GODHAND_SFADXTHN_H

#define SFADXT_ERR_CREATE   0xFF000C04
#define SFADXT_ERR_BUFFER   0xFF000C05

typedef struct SfAdxtCfg {
    int w0;                             /* 0x00 */
    int w4;                             /* 0x04 */
    int w8;                             /* 0x08 */
} SfAdxtCfg;

typedef struct SfAdxtPair {
    void *adxt;                         /* 0x00 the created player */
    void *buf;                          /* 0x04 its stream buffer */
} SfAdxtPair;

typedef struct SfCbTbl {
    int id;                             /* 0x00 */
    void *fn04;                         /* 0x04 */
    void *fn08;                         /* 0x08 */
    void *fn0C;                         /* 0x0C */
    void *fn10;                         /* 0x10 */
    void *fn14;                         /* 0x14 */
} SfCbTbl;

typedef struct SfAdxtHn {
    char unk0000[0x2004];
    SfAdxtPair *pair;                   /* 0x2004 */
    char unk2008[0x2114 - 0x2008];
    SfCbTbl *cb;                        /* 0x2114 */
    char unk2118[0x35A8 - 0x2118];
    SfAdxtPair pairRec;                 /* 0x35A8 */
    SfAdxtCfg cfg;                      /* 0x35B0 */
    char unk35BC[0x365C - 0x35BC];
    SfCbTbl cbTbl;                      /* 0x365C */
} SfAdxtHn;

extern void *sfadxt_CreateEx(SfAdxtCfg *cfg);
extern int func_003395A0(int a, int b, int c);
extern int func_0034ADB8(SfAdxtHn *hn, SfAdxtPair *pair);
extern int func_0034DD70(void *hn, int code);
extern void func_00329D38(void *adxt);
extern void func_0034B3E0(SfAdxtHn *hn, int mode);
extern void func_0034AFF0(SfAdxtHn *hn);
extern int GetArrayElemA0C_35A1C8(void *hn, int idx);
extern void func_00349BA8(void);
extern void func_00349BC8(void);
extern void func_00349BE8(void);
extern void func_00349C08(void);
extern void func_00349C28(void);

#endif
