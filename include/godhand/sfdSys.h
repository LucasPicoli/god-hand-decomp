/* include/godhand/sfdSys.h - the Sofdec system block at D_003EE0C0 (CRI libsfd, src/cod/0034d8.c).
 *
 * Its init routine copies a 0x190-byte default table in, then takes the
 * caller's init record (a 64-bit pair and a pointer). Field names are ours,
 * taken from that routine; offsets are exact. A field nobody has named yet
 * stays as unkNNN padding.
 */
#ifndef GODHAND_SFDSYS_H
#define GODHAND_SFDSYS_H

#define SFDSYS_DEF_LEN   0x190
#define SFDSYS_CLR_WORDS 8

typedef struct SfdSysPair { char b[8]; } SfdSysPair;    /* byte-aligned 8-byte copy */

/* What the caller hands to init. */
typedef struct SfdSysInit {
    void *tbl;                          /* 0x00 transport table */
    int arg;                            /* 0x04 */
    char unk08[0x38];
} SfdSysInit;

typedef struct SfdSys {
    char defTbl[SFDSYS_DEF_LEN];        /* 0x000 */
    SfdSysPair pair;                    /* 0x190 */
    int unk198;                         /* 0x198 */
    char sub19C[0x14];                  /* 0x19C */
    char sub1B0[0xC];                   /* 0x1B0 */
    char sub1BC[0x40];                  /* 0x1BC */
    int clr1FC[2];                      /* 0x1FC */
    int words[SFDSYS_CLR_WORDS];        /* 0x204 cleared by init */
} SfdSys;

extern SfdSys D_003EE0C0;
extern char D_00459760[];
extern char D_003EE280[];
extern void func_00366C50(void *dst, int val, int n);
extern void *func_00366960(void *dst, const void *src, int n);
extern void Obj34D8_Thunk_DD58(void *p);
extern void func_0035A298(void *p, int a);
extern void func_0034BA68(void *p);
extern void Obj34D8_ClearTwoWords_1FC(void *p);
extern int SFTRN_Init(void *dst, void *src);

#endif
