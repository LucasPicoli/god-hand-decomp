/* include/godhand/StmReqRing.h - the 16-entry request ring of a CRI stream reader (src/cod/00336*.c).
 *
 * Requests are queued at the tail and consumed at idx. Each 0x20-byte entry
 * ends with a state word (0 queued, 1 started, 2 running). Field names are
 * ours, taken from the matched ring routines; offsets are exact. A field
 * nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_STMREQRING_H
#define GODHAND_STMREQRING_H

#define STMREQ_NUM          16
#define STMREQ_ST_QUEUED    0
#define STMREQ_ST_STARTED   1
#define STMREQ_ST_RUNNING   2

typedef struct StmReq {
    int unk0;
    int a;                              /* 0x04 */
    int unk8;
    int b;                              /* 0x0C */
    int c;                              /* 0x10 */
    int d;                              /* 0x14 */
    int state;                          /* 0x18 */
    int unk1C;
} StmReq;                               /* 0x20 */

typedef struct StmReqRing {
    char unk0;
    signed char done;                   /* 0x01 */
    char unk2;
    signed char mode;                   /* 0x03 */
    signed char busy;                   /* 0x04 */
    char unk5[0x1B];
    int idx;                            /* 0x20 */
    int count;                          /* 0x24 */
    int active;                         /* 0x28 */
    char unk2C[0xC];
    StmReq req[STMREQ_NUM];             /* 0x38 */
} StmReqRing;

extern void func_00336048(StmReqRing *r);
extern void func_00336110(StmReqRing *r);
extern void func_00335F20(StmReqRing *r);

#endif
