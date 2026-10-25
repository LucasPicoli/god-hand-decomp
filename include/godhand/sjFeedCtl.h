/* include/godhand/sjFeedCtl.h - the feed state machine of a Sofdec stream joint pair (cygnus code at 0x3BA148).
 *
 * A feed reads from the `in` joint (data waiting) and writes into the `out` joint.
 * State 1 starts, 2 runs and copies one block per call, 3 means the source is
 * drained and 4 means an error stopped it. Each call at state 2 takes a 6-byte
 * header chunk from `in`, checks it, and passes one SJFEED_BLOCK block to `out`.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SJFEEDCTL_H
#define GODHAND_SJFEEDCTL_H

#include "godhand/criSj.h"

#define SJFEED_BLOCK        0x1800
#define SJFEED_HDR_LEN      6
#define SJFEED_BIG          0x7FFFFFFF

#define SJFEED_START        1
#define SJFEED_RUN          2
#define SJFEED_DRAINED      3
#define SJFEED_ERROR        4

#define SJ_LANE_FREE        0
#define SJ_LANE_FULL        1

typedef struct SjFeedCtl {
    char unk00[4];
    int state;                          /* 0x04 SJFEED_* */
    void *src;                          /* 0x08 the block the feed copies out */
    char unk0C[4];
    SjObj *in;                          /* 0x10 joint with the data waiting */
    SjObj *out;                         /* 0x14 joint the blocks go to */
    char unk18[4];
    int pos;                            /* 0x1C bytes passed so far */
    int sent;                           /* 0x20 bytes written to out */
    int final;                          /* 0x24 1: the source has ended */
    int copyMode;                       /* 0x28 1: refresh src before writing */
    char unk2C[8];
    int step;                           /* 0x34 bytes the source advances per block */
} SjFeedCtl;

#endif
