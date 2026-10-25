/* include/godhand/StmPos.h - the position tracker of the stream range block at 0xD30
 * (cygnus code at 0x35AD20). Field names are ours; offsets are exact.
 */
#ifndef GODHAND_STMPOS_H
#define GODHAND_STMPOS_H

#define STMPOS_ERR_NO_READER   (-2)     /* written to *out when no reader callback is set */
#define STMPOS_NO_POS          (-5)     /* lastPos value meaning "nothing read yet" */
#define STMPOS_RANGE_OFFSET    0xD30    /* range block inside the stream system */

/* The range block. cb reads the current (pos, tick) pair of the stream. */
typedef struct StmPosRange {
    char unk000[0x2D4];
    int (*cb)(void *arg, int *pair, int *tick); /* 0x2D4 */
    volatile int lastPos;       /* 0x2D8 */
    volatile int total;         /* 0x2DC running total of positions read */
    int lastTick;               /* 0x2E0 */
    int wrap;                   /* 0x2E4 length of one position cycle */
    void *cbArg;                /* 0x2E8 */
} StmPosRange;

typedef struct StmPosSys {
    char unk0000[STMPOS_RANGE_OFFSET];
    StmPosRange range;          /* 0xD30 */
} StmPosSys;

extern int func_0035AE18(StmPosSys *sys);
extern int func_0035A768(StmPosSys *sys);

#endif
