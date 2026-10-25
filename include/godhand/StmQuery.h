/* include/godhand/StmQuery.h - the stream system words the 0x352008 query reads
 * (cygnus code). Field names are ours; offsets are exact. Same object as StmSys
 * in criStm.h, which ends before the current-stream word.
 */
#ifndef GODHAND_STMQUERY_H
#define GODHAND_STMQUERY_H

/* The tail block of the stream system (0x1FB8). */
typedef struct StmQueryCtl {
    char unk00[8];
    char *mgr;                  /* 0x08 stream manager */
    int unk0C;                  /* 0x0C */
    int cur;                    /* 0x10 current stream number */
} StmQueryCtl;

typedef struct StmQuerySys {
    char unk0000[0xD30];
    char range[0x1FB8 - 0xD30]; /* 0xD30 the StmRange block */
    StmQueryCtl ctl;            /* 0x1FB8 */
} StmQuerySys;

#define STMQUERY_MGR_NAME   0x118   /* offset in the manager the lookup is keyed by */
#define STMQUERY_NONE       (-1)    /* "no result" written to both outputs */

extern int func_00359518(StmQuerySys *sys, int cur, unsigned int flag, long long *out);
extern long long func_003520D8(void *range, void *key, int no, long long *pos, void *outB, void *outA);

#endif
